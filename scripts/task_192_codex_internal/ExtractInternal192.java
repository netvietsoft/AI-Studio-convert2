// TASK_192: 64 exact nonexport FDE candidate ranges on a copied PVGImageCodec project.
// @category Extraction

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressRangeIterator;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.symbol.SourceType;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

public class ExtractInternal192 extends GhidraScript {
    private static String q(String value) {
        if (value == null) value = "";
        StringBuilder out = new StringBuilder("\"");
        for (int i = 0; i < value.length(); i++) {
            char ch = value.charAt(i);
            switch (ch) {
                case '\\': out.append("\\\\"); break;
                case '"': out.append("\\\""); break;
                case '\n': out.append("\\n"); break;
                case '\r': out.append("\\r"); break;
                case '\t': out.append("\\t"); break;
                default:
                    if (ch < 0x20) out.append(String.format("\\u%04x", (int) ch));
                    else out.append(ch);
            }
        }
        return out.append('"').toString();
    }

    private static String hash(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder out = new StringBuilder();
        for (byte b : digest) out.append(String.format("%02x", b & 0xff));
        return out.toString();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2 || !"libPVGImageCodec.so".equals(currentProgram.getName()))
            throw new IllegalArgumentException("pinned PVGImageCodec program, TSV and output path required");
        Path input = Paths.get(args[0]);
        Path output = Paths.get(args[1]);
        List<String> targets = Files.readAllLines(input, StandardCharsets.US_ASCII);
        if (targets.size() != 32) throw new IllegalStateException("expected exact 32 target rows per batch");
        Files.createDirectories(output);
        long base = currentProgram.getImageBase().getOffset();
        FunctionManager manager = currentProgram.getFunctionManager();
        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.toggleCCode(true);
        decomp.setSimplificationStyle("decompile");
        if (!decomp.openProgram(currentProgram)) throw new IllegalStateException("decompiler program open failed");
        try {
            int previousIndex = 0;
            for (String line : targets) {
                if (monitor.isCancelled()) break;
                String[] cols = line.split("\\t");
                if (cols.length != 4) throw new IllegalArgumentException("invalid exact target TSV");
                int index = Integer.parseInt(cols[0]);
                long elfVa = Long.decode(cols[1]);
                int size = Integer.parseInt(cols[2]);
                String expectedSha = cols[3];
                if (index < 1 || index > 64 || index <= previousIndex || size < 4 || size > 4096 ||
                    size % 4 != 0 || elfVa % 4 != 0 || expectedSha.length() != 64)
                    throw new IllegalArgumentException("target row outside exact batch");
                previousIndex = index;
                Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + elfVa);
                Address end = start.add(size - 1);
                byte[] bytes = new byte[size];
                int actual = currentProgram.getMemory().getBytes(start, bytes);
                String memorySha = hash(bytes);
                if (actual != size || !expectedSha.equalsIgnoreCase(memorySha))
                    throw new IllegalStateException("copied Ghidra memory differs at index " + index);
                Function function = manager.getFunctionAt(start);
                Function containing = manager.getFunctionContaining(start);
                boolean exactStart = function != null;
                boolean containsNonstart = function == null && containing != null;
                boolean transientCreated = false;
                String error = "";
                int transaction = -1;
                if (function == null && containing != null) function = containing;
                try {
                    if (function == null) {
                        transaction = currentProgram.startTransaction("TASK192 transient FDE candidate " + index);
                        for (int off = 0; off < size; off += 4) {
                            Address pc = start.add(off);
                            if (currentProgram.getListing().getInstructionAt(pc) == null) disassemble(pc);
                        }
                        function = manager.createFunction("task192_fde_candidate_" + index, start,
                                                          new AddressSet(start, end), SourceType.USER_DEFINED);
                        transientCreated = function != null;
                        if (!transientCreated) error = "temporary FDE function creation returned null";
                    }
                } catch (Exception failure) {
                    error = failure.getClass().getSimpleName() + ": " + failure.getMessage();
                }
                List<String> instructionRows = new ArrayList<>();
                int instructionCount = 0;
                int pcodeCount = 0;
                int missing = 0;
                for (int off = 0; off < size; off += 4) {
                    Address pc = start.add(off);
                    Instruction ins = currentProgram.getListing().getInstructionAt(pc);
                    if (ins == null || ins.getLength() != 4) {
                        missing++;
                        instructionRows.add("    {\"database_va\": " + q("0x" + Long.toHexString(pc.getOffset())) +
                                            ", \"missing_analyzed_instruction\": true}");
                        continue;
                    }
                    instructionCount++;
                    List<String> ops = new ArrayList<>();
                    for (PcodeOp op : ins.getPcode()) {
                        ops.add(q(op.toString()));
                        pcodeCount++;
                    }
                    instructionRows.add("    {\"database_va\": " + q("0x" + Long.toHexString(pc.getOffset())) +
                                        ", \"assembly\": " + q(ins.toString()) +
                                        ", \"pcode_ops\": [" + String.join(", ", ops) + "]}");
                }
                StringBuilder membership = new StringBuilder(size);
                long selectedBodyAddresses = function == null ? 0 : function.getBody().getNumAddresses();
                int selectedBytes = 0;
                int otherFunctionBytes = 0;
                List<String> gaps = new ArrayList<>();
                int gapStart = -1;
                int membershipTransitions = 0;
                char prior = 'x';
                for (int off = 0; off < size; off++) {
                    Address pc = start.add(off);
                    boolean selected = function != null && function.getBody().contains(pc);
                    char bit = selected ? '1' : '0';
                    membership.append(bit);
                    if (selected) selectedBytes++;
                    if (prior != 'x' && prior != bit) membershipTransitions++;
                    prior = bit;
                    if (!selected && gapStart == -1) gapStart = off;
                    if (selected && gapStart != -1) {
                        gaps.add("{\"start_offset\": " + gapStart + ", \"end_exclusive\": " + off + "}");
                        gapStart = -1;
                    }
                    Function owner = manager.getFunctionContaining(pc);
                    if (owner != null && (function == null || !owner.getEntryPoint().equals(function.getEntryPoint())))
                        otherFunctionBytes++;
                }
                if (gapStart != -1) gaps.add("{\"start_offset\": " + gapStart +
                                             ", \"end_exclusive\": " + size + "}");
                String functionName = function == null ? "" : function.getName();
                String functionStart = function == null ? "" :
                    "0x" + Long.toHexString(function.getEntryPoint().getOffset());
                String functionBodyMin = function == null ? "" :
                    "0x" + Long.toHexString(function.getBody().getMinAddress().getOffset());
                String functionBodyMax = function == null ? "" :
                    "0x" + Long.toHexString(function.getBody().getMaxAddress().getOffset());
                List<String> extraBodyRanges = new ArrayList<>();
                long extraBodyBytes = 0;
                if (function != null) {
                    AddressRangeIterator ranges = function.getBody().getAddressRanges(true);
                    while (ranges.hasNext()) {
                        AddressRange range = ranges.next();
                        long lo = range.getMinAddress().getOffset();
                        long hiExclusive = range.getMaxAddress().getOffset() + 1;
                        long selectedLo = start.getOffset();
                        long selectedHi = end.getOffset() + 1;
                        if (lo < selectedLo) {
                            long stop = Math.min(hiExclusive, selectedLo);
                            if (lo < stop) {
                                extraBodyBytes += stop - lo;
                                extraBodyRanges.add("{\"start\": " + q("0x" + Long.toHexString(lo)) +
                                    ", \"end_exclusive\": " + q("0x" + Long.toHexString(stop)) + "}");
                            }
                        }
                        if (hiExclusive > selectedHi) {
                            long begin = Math.max(lo, selectedHi);
                            if (begin < hiExclusive) {
                                extraBodyBytes += hiExclusive - begin;
                                extraBodyRanges.add("{\"start\": " + q("0x" + Long.toHexString(begin)) +
                                    ", \"end_exclusive\": " + q("0x" + Long.toHexString(hiExclusive)) + "}");
                            }
                        }
                    }
                }
                String boundary;
                if (function == null) boundary = "NO_FUNCTION_METADATA";
                else if (containsNonstart) boundary = "FDE_START_INSIDE_EXISTING_FUNCTION_BOUNDARY_AMBIGUOUS";
                else if (transientCreated) boundary = "TRANSIENT_FDE_FUNCTION_ASSUMPTION";
                else if (exactStart) boundary = "EXACT_GHIDRA_FUNCTION_START_FDE_BOUNDARY_UNPROVEN";
                else boundary = "UNKNOWN_FUNCTION_METADATA";
                if (selectedBytes != size) boundary += "_PARTIAL_OR_DISCONTIGUOUS_BODY";
                if (otherFunctionBytes > 0) boundary += "_OTHER_FUNCTION_OVERLAP";
                boolean cLike = false;
                String cText = "";
                long elapsed = 0;
                try {
                    if (function != null) {
                        long began = System.nanoTime();
                        DecompileResults result = decomp.decompileFunction(function, 10, monitor);
                        elapsed = (System.nanoTime() - began) / 1000000;
                        if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                            cText = result.getDecompiledFunction().getC();
                            cLike = cText != null && !cText.trim().isEmpty();
                        } else {
                            String msg = result == null ? "null DecompileResults" : result.getErrorMessage();
                            error = error.isEmpty() ? msg : error + "; " + msg;
                        }
                    } else if (error.isEmpty()) error = "no candidate function to decompile";
                } catch (Exception failure) {
                    String msg = failure.getClass().getSimpleName() + ": " + failure.getMessage();
                    error = error.isEmpty() ? msg : error + "; " + msg;
                } finally {
                    if (transaction != -1) currentProgram.endTransaction(transaction, false);
                }
                byte[] after = new byte[size];
                currentProgram.getMemory().getBytes(start, after);
                if (!hash(after).equalsIgnoreCase(expectedSha))
                    throw new IllegalStateException("memory changed after transient rollback index " + index);
                String json = "{\n  \"task_id\": \"TASK_192\", \"revision\": 1,\n" +
                    "  \"generated_at\": " + q(Instant.now().toString()) + ",\n" +
                    "  \"index\": " + index + ", \"elf_va\": " + q(cols[1]) +
                    ", \"database_va\": " + q("0x" + Long.toHexString(base + elfVa)) + ",\n" +
                    "  \"size_bytes\": " + size + ", \"ghidra_memory_sha256\": " + q(memorySha) + ",\n" +
                    "  \"instruction_slots\": " + (size / 4) +
                    ", \"ghidra_instruction_count\": " + instructionCount +
                    ", \"missing_analyzed_instruction_count\": " + missing +
                    ", \"ghidra_pcode_ops\": " + pcodeCount + ",\n" +
                    "  \"boundary_classification\": " + q(boundary) +
                    ", \"existing_exact_function_start\": " + exactStart +
                    ", \"existing_function_contains_nonstart\": " + containsNonstart +
                    ", \"temporary_function_created_and_rolled_back\": " + transientCreated + ",\n" +
                    "  \"function_name\": " + q(functionName) +
                    ", \"function_start\": " + q(functionStart) +
                    ", \"function_body_min\": " + q(functionBodyMin) +
                    ", \"function_body_max\": " + q(functionBodyMax) +
                    ", \"function_body_total_address_count\": " + selectedBodyAddresses + ",\n" +
                    "  \"extra_body_address_count\": " + extraBodyBytes +
                    ", \"extra_body_ranges\": [" + String.join(", ", extraBodyRanges) + "],\n" +
                    "  \"fde_byte_membership_count\": " + selectedBytes +
                    ", \"fde_byte_membership_bits\": " + q(membership.toString()) +
                    ", \"fde_byte_membership_transitions\": " + membershipTransitions +
                    ", \"fde_missing_body_ranges\": [" + String.join(", ", gaps) + "]" +
                    ", \"other_function_byte_count\": " + otherFunctionBytes + ",\n" +
                    "  \"decompile_elapsed_ms\": " + elapsed +
                    ", \"c_like_nonempty\": " + cLike +
                    ", \"decompile_error\": " + q(error) +
                    ", \"c_like_text\": " + q(cText) + ",\n" +
                    "  \"instruction_pcode\": [\n" + String.join(",\n", instructionRows) + "\n  ]\n}\n";
                Path rowFile = output.resolve(String.format("%03d_%x.json", index, elfVa));
                Files.write(rowFile, json.getBytes(StandardCharsets.UTF_8));
                println("[TASK_192] index=" + index + " va=0x" + Long.toHexString(elfVa) +
                        " instr=" + instructionCount + "/" + (size / 4) +
                        " pcode=" + pcodeCount + " body_bytes=" + selectedBytes + "/" + size +
                        " other_function_bytes=" + otherFunctionBytes + " c=" + cLike +
                        " boundary=" + boundary + " ms=" + elapsed);
            }
        } finally {
            decomp.dispose();
        }
    }
}
