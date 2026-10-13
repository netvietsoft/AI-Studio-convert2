// TASK_187: one transient full-FDE metadata/disassembly pass for six exact gaps.
// @category Extraction

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
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
import java.util.Arrays;
import java.util.List;

public class RepairMembership187 extends GhidraScript {
    private static final List<Integer> INDICES = Arrays.asList(18, 23, 30, 43, 85, 128);

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

    private static String bits(Function function, Address start, int size) throws Exception {
        StringBuilder out = new StringBuilder(size);
        for (int off = 0; off < size; off++)
            out.append(function != null && function.getBody().contains(start.add(off)) ? '1' : '0');
        return out.toString();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2 || !"libMTFilterKernel.so".equals(currentProgram.getName()))
            throw new IllegalArgumentException("pinned MTFilterKernel program, six-row TSV/output required");
        Path input = Paths.get(args[0]);
        Path output = Paths.get(args[1]);
        List<String> targets = Files.readAllLines(input, StandardCharsets.US_ASCII);
        if (targets.size() != INDICES.size()) throw new IllegalStateException("expected exact six anomaly rows");
        Files.createDirectories(output);
        long base = currentProgram.getImageBase().getOffset();
        FunctionManager manager = currentProgram.getFunctionManager();
        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.toggleCCode(true);
        decomp.setSimplificationStyle("decompile");
        if (!decomp.openProgram(currentProgram)) throw new IllegalStateException("decompiler open failed");
        try {
            for (int ordinal = 0; ordinal < targets.size(); ordinal++) {
                String[] cols = targets.get(ordinal).split("\\t");
                if (cols.length != 4) throw new IllegalArgumentException("invalid exact anomaly TSV");
                int index = Integer.parseInt(cols[0]);
                long elfVa = Long.decode(cols[1]);
                int size = Integer.parseInt(cols[2]);
                String expectedSha = cols[3];
                if (index != INDICES.get(ordinal) || size < 4 || size > 4096 || size % 4 != 0 ||
                    elfVa % 4 != 0 || expectedSha.length() != 64)
                    throw new IllegalArgumentException("anomaly outside exact six targets");
                Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + elfVa);
                Address end = start.add(size - 1);
                byte[] before = new byte[size];
                if (currentProgram.getMemory().getBytes(start, before) != size ||
                    !hash(before).equalsIgnoreCase(expectedSha))
                    throw new IllegalStateException("copied source memory differs index " + index);
                Function original = manager.getFunctionAt(start);
                if (original == null) throw new IllegalStateException("pre-existing exact function absent index " + index);
                String originalMembership = bits(original, start, size);
                int oldCount = (int) originalMembership.chars().filter(c -> c == '1').count();
                if (oldCount >= size) throw new IllegalStateException("expected pre-existing body gap absent index " + index);
                int otherFunctionBytes = 0;
                for (int off = 0; off < size; off++) {
                    Function owner = manager.getFunctionContaining(start.add(off));
                    if (owner != null && !owner.getEntryPoint().equals(start)) otherFunctionBytes++;
                }
                if (otherFunctionBytes > 0) throw new IllegalStateException("other function overlaps FDE index " + index);
                boolean removed = false;
                boolean created = false;
                int decoded = 0;
                int pcodeOps = 0;
                int correctedMembership = 0;
                long correctedBodyAddressCount = 0;
                String correctedBits = "";
                boolean cLike = false;
                String cText = "";
                String error = "";
                long elapsed = 0;
                List<String> instructionRows = new ArrayList<>();
                int tx = currentProgram.startTransaction("TASK187 transient full FDE metadata " + index);
                try {
                    removed = manager.removeFunction(start);
                    if (!removed) throw new IllegalStateException("cannot remove pre-existing truncated function");
                    for (int off = 0; off < size; off += 4) {
                        Address pc = start.add(off);
                        if (currentProgram.getListing().getInstructionAt(pc) == null) disassemble(pc);
                    }
                    for (int off = 0; off < size; off += 4) {
                        Address pc = start.add(off);
                        Instruction ins = currentProgram.getListing().getInstructionAt(pc);
                        if (ins == null || ins.getLength() != 4) {
                            instructionRows.add("    {\"database_va\": " + q("0x" + Long.toHexString(pc.getOffset())) +
                                                ", \"missing_instruction\": true}");
                            continue;
                        }
                        decoded++;
                        List<String> ops = new ArrayList<>();
                        for (PcodeOp op : ins.getPcode()) {
                            ops.add(q(op.toString()));
                            pcodeOps++;
                        }
                        instructionRows.add("    {\"database_va\": " + q("0x" + Long.toHexString(pc.getOffset())) +
                                            ", \"assembly\": " + q(ins.toString()) +
                                            ", \"pcode_ops\": [" + String.join(", ", ops) + "]}");
                    }
                    if (decoded == size / 4) {
                        Function full = manager.createFunction("task187_full_fde_candidate_" + index,
                            start, new AddressSet(start, end), SourceType.USER_DEFINED);
                        created = full != null;
                        if (created) {
                            correctedBits = bits(full, start, size);
                            correctedMembership = (int) correctedBits.chars().filter(c -> c == '1').count();
                            correctedBodyAddressCount = full.getBody().getNumAddresses();
                            long began = System.nanoTime();
                            DecompileResults result = decomp.decompileFunction(full, 10, monitor);
                            elapsed = (System.nanoTime() - began) / 1000000;
                            if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                                cText = result.getDecompiledFunction().getC();
                                cLike = cText != null && !cText.trim().isEmpty();
                            } else error = result == null ? "null DecompileResults" : result.getErrorMessage();
                        } else error = "temporary full FDE function creation returned null";
                    } else error = "some original instruction positions could not be analyzed";
                } catch (Exception failure) {
                    error = failure.getClass().getSimpleName() + ": " + failure.getMessage();
                } finally {
                    currentProgram.endTransaction(tx, false);
                }
                byte[] after = new byte[size];
                currentProgram.getMemory().getBytes(start, after);
                if (!hash(after).equalsIgnoreCase(expectedSha))
                    throw new IllegalStateException("copied source memory changed after rollback index " + index);
                String json = "{\n  \"task_id\": \"TASK_187\", \"revision\": 1,\n" +
                    "  \"generated_at\": " + q(Instant.now().toString()) + ",\n" +
                    "  \"index\": " + index + ", \"elf_va\": " + q(cols[1]) +
                    ", \"database_va\": " + q("0x" + Long.toHexString(base + elfVa)) + ",\n" +
                    "  \"size_bytes\": " + size + ", \"memory_sha256\": " + q(expectedSha) +
                    ", \"memory_unchanged_after_rollback\": true,\n" +
                    "  \"original_function_fde_membership_count\": " + oldCount +
                    ", \"original_function_fde_membership_bits\": " + q(originalMembership) +
                    ", \"other_function_byte_count\": " + otherFunctionBytes + ",\n" +
                    "  \"temporary_old_function_removed\": " + removed +
                    ", \"temporary_full_fde_function_created\": " + created +
                    ", \"corrected_function_fde_membership_count\": " + correctedMembership +
                    ", \"corrected_function_fde_membership_bits\": " + q(correctedBits) +
                    ", \"corrected_function_body_total_address_count\": " + correctedBodyAddressCount + ",\n" +
                    "  \"full_fde_instruction_count\": " + decoded +
                    ", \"full_fde_pcode_ops\": " + pcodeOps + ",\n" +
                    "  \"decompile_elapsed_ms\": " + elapsed +
                    ", \"c_like_nonempty\": " + cLike +
                    ", \"error\": " + q(error) +
                    ", \"c_like_text\": " + q(cText) + ",\n" +
                    "  \"instruction_pcode\": [\n" + String.join(",\n", instructionRows) + "\n  ]\n}\n";
                Path file = output.resolve(String.format("%03d_%x.json", index, elfVa));
                Files.write(file, json.getBytes(StandardCharsets.UTF_8));
                println("[TASK_187_CORRECTION] index=" + index + " old_membership=" + oldCount +
                        "/" + size + " new_membership=" + correctedMembership +
                        "/" + size + " decoded=" + decoded + "/" + (size / 4) +
                        " pcode=" + pcodeOps + " c=" + cLike + " error=" + error);
            }
        } finally {
            decomp.dispose();
        }
    }
}
