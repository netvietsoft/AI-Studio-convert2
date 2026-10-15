// TASK_243 R1: bounded, per-candidate read-only extraction from an owned Ghidra project copy.
// @category Extraction

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.pcode.PcodeOp;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

public class ExtractInternal243 extends GhidraScript {
    private static class Target {
        int index;
        long elfVa;
        int size;
        String expectedSha;
        long fileOffset;

        Target(String line) {
            String[] fields = line.split("\t", -1);
            if (fields.length != 5) throw new IllegalArgumentException("invalid target TSV row");
            index = Integer.parseInt(fields[0]);
            elfVa = Long.decode(fields[1]);
            size = Integer.parseInt(fields[2]);
            expectedSha = fields[3].toLowerCase();
            fileOffset = Long.decode(fields[4]);
            if (index < 1 || index > 512 || size < 4 || size > 4096 || size % 4 != 0 ||
                expectedSha.length() != 64 || fileOffset < 0) {
                throw new IllegalArgumentException("invalid target bounds");
            }
        }
    }

    private static String escape(String value) {
        if (value == null) return "";
        StringBuilder out = new StringBuilder();
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
        return out.toString();
    }

    private static String sha(byte[] raw) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(raw);
        StringBuilder out = new StringBuilder();
        for (byte b : digest) out.append(String.format("%02x", b & 0xff));
        return out.toString();
    }

    private static String arr(List<String> items) {
        StringBuilder out = new StringBuilder("[");
        for (int i = 0; i < items.size(); i++) {
            if (i > 0) out.append(",");
            out.append("\"").append(escape(items.get(i))).append("\"");
        }
        return out.append("]").toString();
    }

    private String extract(Target t, long imageBase, DecompInterface decomp) {
        long started = System.nanoTime();
        long databaseVa = imageBase + t.elfVa;
        String actualSha = "";
        String error = "";
        String decompError = "";
        String pseudocode = "";
        String functionOrigin = "NONE";
        String functionEntry = "";
        String functionMin = "";
        String functionMax = "";
        String ambiguity = "";
        int instructionCount = 0;
        int pcodeOps = 0;
        int pcodeInstructionSlots = 0;
        int missingSlots = 0;
        long bodyMemberBytes = -1;
        long bodyExtraBytes = -1;
        boolean bytesMatch = false;
        boolean decompSuccess = false;
        List<String> instructions = new ArrayList<>();
        List<String> calls = new ArrayList<>();
        try {
            Address entry = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(databaseVa);
            byte[] memoryBytes = new byte[t.size];
            currentProgram.getMemory().getBytes(entry, memoryBytes);
            actualSha = sha(memoryBytes);
            bytesMatch = actualSha.equals(t.expectedSha);
            if (!bytesMatch) throw new IllegalStateException("owned Ghidra memory differs from original PT_LOAD bytes");

            for (int offset = 0; offset < t.size; offset += 4) {
                Address slot = entry.add(offset);
                Instruction ins = getInstructionAt(slot);
                if (ins == null) {
                    disassemble(slot);
                    ins = getInstructionAt(slot);
                }
                if (ins == null || ins.getLength() != 4) {
                    missingSlots++;
                    continue;
                }
                instructionCount++;
                instructions.add(slot + ": " + ins);
                PcodeOp[] ops = ins.getPcode();
                if (ops != null && ops.length > 0) {
                    pcodeInstructionSlots++;
                    pcodeOps += ops.length;
                }
                if (ins.getFlowType().isCall()) {
                    Address[] flows = ins.getFlows();
                    calls.add(slot + " -> " + (flows.length == 0 ? "INDIRECT" : flows[0].toString()));
                }
            }

            Function function = getFunctionAt(entry);
            if (function != null) {
                functionOrigin = "EXISTING_ENTRY";
            } else {
                Function containing = getFunctionContaining(entry);
                if (containing != null) {
                    ambiguity = "FDE_START_WITHIN_EXISTING_GHIDRA_FUNCTION";
                    functionOrigin = "CONTAINED_IN_EXISTING";
                    functionEntry = containing.getEntryPoint().toString();
                    functionMin = containing.getBody().getMinAddress().toString();
                    functionMax = containing.getBody().getMaxAddress().toString();
                } else {
                    createFunction(entry, String.format("internal_fde_%03d", t.index));
                    function = getFunctionAt(entry);
                    functionOrigin = function == null ? "CREATE_FAILED" : "CREATED_IN_OWNED_COPY";
                }
            }
            if (function != null) {
                functionEntry = function.getEntryPoint().toString();
                functionMin = function.getBody().getMinAddress().toString();
                functionMax = function.getBody().getMaxAddress().toString();
                long min = function.getBody().getMinAddress().getOffset();
                long max = function.getBody().getMaxAddress().getOffset();
                bodyMemberBytes = 0;
                for (int offset = 0; offset < t.size; offset++) {
                    if (function.getBody().contains(entry.add(offset))) bodyMemberBytes++;
                }
                bodyExtraBytes = function.getBody().getNumAddresses() - bodyMemberBytes;
                if (min != databaseVa || max != databaseVa + t.size - 1 || !function.getBody().contains(entry, entry.add(t.size - 1)) || function.getBody().getNumAddresses() != t.size) {
                    ambiguity = "GHIDRA_FUNCTION_BODY_DIFFERS_FROM_FDE_RANGE";
                }
                DecompileResults result = decomp.decompileFunction(function, 15, monitor);
                if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                    pseudocode = result.getDecompiledFunction().getC();
                    decompSuccess = !pseudocode.trim().isEmpty();
                } else {
                    decompError = result == null ? "null DecompileResults" : result.getErrorMessage();
                }
            } else if (decompError.isEmpty()) {
                decompError = "No function at pinned FDE start; candidate boundary unresolved";
            }
        } catch (Throwable exception) {
            error = exception.getClass().getSimpleName() + ": " + exception.getMessage();
        }
        StringBuilder row = new StringBuilder();
        row.append("{\n");
        row.append("\"schema\":\"task237-ghidra-candidate-v1\",\n");
        row.append("\"index\":").append(t.index).append(",\n");
        row.append("\"elf_va\":\"0x").append(Long.toHexString(t.elfVa)).append("\",\n");
        row.append("\"database_va\":\"0x").append(Long.toHexString(databaseVa)).append("\",\n");
        row.append("\"size_bytes\":").append(t.size).append(",\n");
        row.append("\"original_file_offset\":\"0x").append(Long.toHexString(t.fileOffset)).append("\",\n");
        row.append("\"expected_original_body_sha256\":\"").append(t.expectedSha).append("\",\n");
        row.append("\"owned_project_memory_sha256\":\"").append(actualSha).append("\",\n");
        row.append("\"source_bytes_match\":").append(bytesMatch).append(",\n");
        row.append("\"instruction_count\":").append(instructionCount).append(",\n");
        row.append("\"missing_instruction_slots\":").append(missingSlots).append(",\n");
        row.append("\"body_member_bytes_within_fde\":").append(bodyMemberBytes).append(",\n");
        row.append("\"body_extra_bytes_outside_fde\":").append(bodyExtraBytes).append(",\n");
        row.append("\"pcode_instruction_slots\":").append(pcodeInstructionSlots).append(",\n");
        row.append("\"pcode_op_count\":").append(pcodeOps).append(",\n");
        row.append("\"function_origin\":\"").append(escape(functionOrigin)).append("\",\n");
        row.append("\"function_entry\":\"").append(escape(functionEntry)).append("\",\n");
        row.append("\"function_body_min\":\"").append(escape(functionMin)).append("\",\n");
        row.append("\"function_body_max\":\"").append(escape(functionMax)).append("\",\n");
        row.append("\"boundary_ambiguity\":\"").append(escape(ambiguity)).append("\",\n");
        row.append("\"decompile_success\":").append(decompSuccess).append(",\n");
        row.append("\"decompile_error\":\"").append(escape(decompError)).append("\",\n");
        row.append("\"error\":\"").append(escape(error)).append("\",\n");
        row.append("\"pseudocode_sha256\":\"");
        try { row.append(pseudocode.isEmpty() ? "" : sha(pseudocode.getBytes(StandardCharsets.UTF_8))); }
        catch (Exception ignored) { row.append(""); }
        row.append("\",\n");
        row.append("\"pseudocode\":\"").append(escape(pseudocode)).append("\",\n");
        row.append("\"instructions\":").append(arr(instructions)).append(",\n");
        row.append("\"calls\":").append(arr(calls)).append(",\n");
        row.append("\"elapsed_ms\":").append((System.nanoTime() - started) / 1000000.0).append("\n}");
        return row.toString();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("expected targets TSV and output directory");
        Path targetFile = Paths.get(args[0]);
        Path outputDir = Paths.get(args[1]);
        List<Target> targets = new ArrayList<>();
        for (String line : Files.readAllLines(targetFile, StandardCharsets.UTF_8)) {
            if (!line.isEmpty()) targets.add(new Target(line));
        }
        if (targets.size() != 512) throw new IllegalStateException("expected exact 512-row bounded chunk");
        if (!currentProgram.getName().equals("libPVGImageCodec.so")) {
            throw new IllegalStateException("wrong analyzed program: " + currentProgram.getName());
        }
        Files.createDirectories(outputDir);
        long base = currentProgram.getImageBase().getOffset();
        println("[TASK_243] started " + Instant.now() + " program=" + currentProgram.getName() +
                " image_base=0x" + Long.toHexString(base) + " rows=" + targets.size());
        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        if (!decomp.openProgram(currentProgram)) throw new IllegalStateException("decompiler open failed");
        for (Target target : targets) {
            Path output = outputDir.resolve(String.format("candidate_%03d.json", target.index));
            if (Files.exists(output)) throw new IllegalStateException("duplicate candidate output: " + output);
            String row = extract(target, base, decomp);
            Files.write(output, (row + "\n").getBytes(StandardCharsets.UTF_8));
            if (target.index % 10 == 0 || target.index == targets.get(targets.size() - 1).index) {
                println("[TASK_243] processed candidate " + target.index + "/512");
            }
        }
        decomp.dispose();
        println("[TASK_243] finished " + Instant.now() + " count=" + targets.size());
    }
}

