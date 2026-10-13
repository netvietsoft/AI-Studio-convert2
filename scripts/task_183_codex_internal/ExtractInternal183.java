// TASK_183: 51 exact FDE candidate ranges from a copied analyzed project.
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
import java.util.List;

public class ExtractInternal183 extends GhidraScript {

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
        if (args.length != 2) throw new IllegalArgumentException("exact target TSV and output directory required");
        if (!"libMTGif.so".equals(currentProgram.getName())) throw new IllegalStateException("wrong analyzed program");
        Path input = Paths.get(args[0]);
        Path output = Paths.get(args[1]);
        List<String> targets = Files.readAllLines(input, StandardCharsets.US_ASCII);
        if (targets.size() != 51) throw new IllegalStateException("expected exact 51 target rows");
        Files.createDirectories(output);
        long base = currentProgram.getImageBase().getOffset();
        FunctionManager manager = currentProgram.getFunctionManager();
        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.toggleCCode(true);
        decomp.setSimplificationStyle("decompile");
        if (!decomp.openProgram(currentProgram)) throw new IllegalStateException("decompiler program open failed");
        try {
            int expectedIndex = 1;
            for (String line : targets) {
                if (monitor.isCancelled()) break;
                String[] cols = line.split("\\t");
                if (cols.length != 4) throw new IllegalArgumentException("invalid target TSV");
                int index = Integer.parseInt(cols[0]);
                long elfVa = Long.decode(cols[1]);
                int size = Integer.parseInt(cols[2]);
                String expectedSha = cols[3];
                if (index != expectedIndex++ || index > 51 || size < 4 || size > 4096 || size % 4 != 0 ||
                    elfVa % 4 != 0 || expectedSha.length() != 64) throw new IllegalArgumentException("target row outside exact batch");
                Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + elfVa);
                Address end = start.add(size - 4);
                byte[] bytes = new byte[size];
                int actual = currentProgram.getMemory().getBytes(start, bytes);
                String memorySha = hash(bytes);
                if (actual != size || !expectedSha.equalsIgnoreCase(memorySha))
                    throw new IllegalStateException("copied Ghidra memory differs at index " + index);
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
                    List<String> pcode = new ArrayList<>();
                    for (PcodeOp op : ins.getPcode()) {
                        pcode.add(q(op.toString()));
                        pcodeCount++;
                    }
                    instructionRows.add("    {\"database_va\": " + q("0x" + Long.toHexString(pc.getOffset())) +
                                        ", \"assembly\": " + q(ins.toString()) +
                                        ", \"pcode_ops\": [" + String.join(", ", pcode) + "]}");
                }
                Function function = manager.getFunctionAt(start);
                Function containing = manager.getFunctionContaining(start);
                String boundary;
                boolean temporaryCreated = false;
                String functionName = "";
                String functionStart = "";
                String functionBodyMin = "";
                String functionBodyMax = "";
                boolean cLike = false;
                String cText = "";
                String error = "";
                long elapsed = 0;
                int transaction = -1;
                try {
                    if (function != null) {
                        boundary = "EXACT_GHIDRA_FUNCTION_START_FDE_RANGE_UNPROVEN";
                    } else if (containing != null) {
                        boundary = "FDE_START_INSIDE_EXISTING_GHIDRA_FUNCTION_BOUNDARY_AMBIGUOUS";
                        error = "cannot create overlapping temporary function";
                    } else if (missing > 0) {
                        boundary = "FDE_START_NO_FUNCTION_AND_MISSING_ANALYZED_INSTRUCTIONS";
                        error = "temporary metadata requires fully analyzed instruction range";
                    } else {
                        boundary = "FDE_RANGE_TEMPORARY_FUNCTION_ASSUMPTION";
                        transaction = currentProgram.startTransaction("TASK183 transient FDE function " + index);
                        AddressSet body = new AddressSet(start, end);
                        function = manager.createFunction("task183_fde_candidate_" + index,
                                                          start, body, SourceType.USER_DEFINED);
                        temporaryCreated = function != null;
                        if (!temporaryCreated) error = "temporary function creation returned null";
                    }
                    if (function != null) {
                        functionName = function.getName();
                        functionStart = "0x" + Long.toHexString(function.getEntryPoint().getOffset());
                        functionBodyMin = "0x" + Long.toHexString(function.getBody().getMinAddress().getOffset());
                        functionBodyMax = "0x" + Long.toHexString(function.getBody().getMaxAddress().getOffset());
                        long began = System.nanoTime();
                        DecompileResults result = decomp.decompileFunction(function, 10, monitor);
                        elapsed = (System.nanoTime() - began) / 1000000;
                        if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                            cText = result.getDecompiledFunction().getC();
                            cLike = cText != null && !cText.trim().isEmpty();
                        } else {
                            error = result == null ? "null DecompileResults" : result.getErrorMessage();
                        }
                    }
                } catch (Exception failure) {
                    boundary = "FUNCTION_METADATA_OR_DECOMPILATION_FAILURE";
                    error = failure.getClass().getSimpleName() + ": " + failure.getMessage();
                } finally {
                    if (transaction != -1) currentProgram.endTransaction(transaction, false);
                }
                byte[] after = new byte[size];
                currentProgram.getMemory().getBytes(start, after);
                if (!hash(after).equalsIgnoreCase(expectedSha))
                    throw new IllegalStateException("memory changed after transient metadata rollback index " + index);
                String json = "{\n  \"task_id\": \"TASK_183\", \"revision\": 1,\n" +
                    "  \"generated_at\": " + q(Instant.now().toString()) + ",\n" +
                    "  \"index\": " + index + ", \"elf_va\": " + q(cols[1]) +
                    ", \"database_va\": " + q("0x" + Long.toHexString(base + elfVa)) + ",\n" +
                    "  \"size_bytes\": " + size + ", \"ghidra_memory_sha256\": " + q(memorySha) + ",\n" +
                    "  \"instruction_slots\": " + (size / 4) +
                    ", \"ghidra_instruction_count\": " + instructionCount +
                    ", \"missing_analyzed_instruction_count\": " + missing +
                    ", \"ghidra_pcode_ops\": " + pcodeCount + ",\n" +
                    "  \"boundary_classification\": " + q(boundary) +
                    ", \"temporary_function_created_and_rolled_back\": " + temporaryCreated + ",\n" +
                    "  \"function_name\": " + q(functionName) +
                    ", \"function_start\": " + q(functionStart) +
                    ", \"function_body_min\": " + q(functionBodyMin) +
                    ", \"function_body_max\": " + q(functionBodyMax) + ",\n" +
                    "  \"decompile_elapsed_ms\": " + elapsed +
                    ", \"c_like_nonempty\": " + cLike +
                    ", \"decompile_error\": " + q(error) +
                    ", \"c_like_text\": " + q(cText) + ",\n" +
                    "  \"instruction_pcode\": [\n" + String.join(",\n", instructionRows) + "\n  ]\n}\n";
                Path rowFile = output.resolve(String.format("%02d_%x.json", index, elfVa));
                Files.write(rowFile, json.getBytes(StandardCharsets.UTF_8));
                println("[TASK_183] index=" + index + " va=0x" + Long.toHexString(elfVa) +
                        " instr=" + instructionCount + "/" + (size / 4) +
                        " pcode=" + pcodeCount + " c=" + cLike +
                        " boundary=" + boundary + " ms=" + elapsed);
            }
        } finally {
            decomp.dispose();
        }
    }
}
