// TASK_160 R1: direct, bounded Ghidra extraction of one pinned SO export set.
// @category Extraction

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

public class ExportChunk160 extends GhidraScript {

    private static class Target {
        int index;
        long elfVa;
        int size;
        String expectedSha;
        String symbol;

        Target(String line) {
            String[] fields = line.split("\t", 5);
            if (fields.length != 5) throw new IllegalArgumentException("invalid target TSV row");
            index = Integer.parseInt(fields[0]);
            elfVa = Long.decode(fields[1]);
            size = Integer.parseInt(fields[2]);
            expectedSha = fields[3];
            symbol = fields[4];
            if (index < 1 || size < 1 || size > 65536 || expectedSha.length() != 64) {
                throw new IllegalArgumentException("invalid target bounds");
            }
        }
    }

    private static String escape(String text) {
        if (text == null) return "";
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);
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

    private static String hash(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder out = new StringBuilder();
        for (byte value : digest) out.append(String.format("%02x", value & 0xff));
        return out.toString();
    }

    private String extract(Target target, long imageBase, DecompInterface decomp) {
        StringBuilder row = new StringBuilder();
        long databaseVa = imageBase + target.elfVa;
        boolean bytesMatch = false;
        boolean decompileSuccess = false;
        int instructionCount = 0;
        String actualSha = "";
        String pseudocode = "";
        String error = "";
        List<String> instructions = new ArrayList<>();
        List<String> calls = new ArrayList<>();
        long started = System.nanoTime();

        try {
            Address address = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(databaseVa);
            byte[] raw = new byte[target.size];
            currentProgram.getMemory().getBytes(address, raw);
            actualSha = hash(raw);
            bytesMatch = actualSha.equalsIgnoreCase(target.expectedSha);
            if (!bytesMatch) throw new IllegalStateException("Ghidra bytes differ from source PT_LOAD bytes");

            if (getInstructionAt(address) == null) disassemble(address);
            Function function = getFunctionAt(address);
            if (function == null) {
                createFunction(address, target.symbol);
                function = getFunctionAt(address);
            }
            if (function == null) throw new IllegalStateException("no Ghidra function at exported VA");

            InstructionIterator iterator = currentProgram.getListing().getInstructions(address, true);
            while (iterator.hasNext()) {
                Instruction instruction = iterator.next();
                long current = instruction.getAddress().getOffset();
                if (current < databaseVa || current >= databaseVa + target.size) break;
                instructions.add(instruction.getAddress() + ": " + instruction);
                instructionCount++;
                if (instruction.getFlowType().isCall()) {
                    Address[] flows = instruction.getFlows();
                    if (flows.length > 0) {
                        Function callee = getFunctionAt(flows[0]);
                        calls.add(instruction.getAddress() + " -> " + flows[0] +
                            (callee == null ? "" : " [" + callee.getName() + "]"));
                    } else {
                        calls.add(instruction.getAddress() + " -> INDIRECT");
                    }
                }
            }
            DecompileResults result = decomp.decompileFunction(function, 15, monitor);
            if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                pseudocode = result.getDecompiledFunction().getC();
                decompileSuccess = true;
            } else {
                error = result == null ? "null DecompileResults" : result.getErrorMessage();
            }
        } catch (Exception exception) {
            error = exception.getClass().getSimpleName() + ": " + exception.getMessage();
        }

        row.append("    {\n");
        row.append("      \"index\": ").append(target.index).append(",\n");
        row.append("      \"symbol\": \"").append(escape(target.symbol)).append("\",\n");
        row.append("      \"elf_va\": \"0x").append(Long.toHexString(target.elfVa)).append("\",\n");
        row.append("      \"database_va\": \"0x").append(Long.toHexString(databaseVa)).append("\",\n");
        row.append("      \"size_bytes\": ").append(target.size).append(",\n");
        row.append("      \"expected_source_sha256\": \"").append(target.expectedSha).append("\",\n");
        row.append("      \"ghidra_memory_sha256\": \"").append(actualSha).append("\",\n");
        row.append("      \"source_bytes_match\": ").append(bytesMatch).append(",\n");
        row.append("      \"instruction_count_observed\": ").append(instructionCount).append(",\n");
        row.append("      \"decompile_success\": ").append(decompileSuccess).append(",\n");
        row.append("      \"elapsed_ms\": ").append((System.nanoTime() - started) / 1000000.0).append(",\n");
        row.append("      \"error\": \"").append(escape(error)).append("\",\n");
        row.append("      \"pseudocode\": \"").append(escape(pseudocode)).append("\",\n");
        row.append("      \"instructions\": [");
        for (int i = 0; i < instructions.size(); i++) {
            if (i != 0) row.append(", ");
            row.append("\"").append(escape(instructions.get(i))).append("\"");
        }
        row.append("],\n");
        row.append("      \"calls\": [");
        for (int i = 0; i < calls.size(); i++) {
            if (i != 0) row.append(", ");
            row.append("\"").append(escape(calls.get(i))).append("\"");
        }
        row.append("]\n    }");
        return row.toString();
    }

    @Override
    public void run() throws Exception {
        String[] arguments = getScriptArgs();
        if (arguments.length != 2) throw new IllegalArgumentException("expected targets TSV and output JSON path");
        Path targetsPath = Paths.get(arguments[0]);
        Path outputPath = Paths.get(arguments[1]);
        List<Target> targets = new ArrayList<>();
        for (String line : Files.readAllLines(targetsPath, StandardCharsets.UTF_8)) {
            if (!line.isEmpty()) targets.add(new Target(line));
        }
        if (targets.isEmpty() || targets.size() > 256) throw new IllegalStateException("expected 1-256 exported addresses");
        long imageBase = currentProgram.getImageBase().getOffset();
        println("[TASK_160] source=" + currentProgram.getName() + " image_base=0x" +
            Long.toHexString(imageBase) + " targets=" + targets.size());

        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        if (!decomp.openProgram(currentProgram)) throw new IllegalStateException("decompiler initialization failed");
        StringBuilder json = new StringBuilder();
        json.append("{\n  \"schema_version\": \"2.1.2\",\n");
        json.append("  \"task_id\": \"TASK_160\",\n  \"revision\": 1,\n");
        json.append("  \"program_name\": \"").append(escape(currentProgram.getName())).append("\",\n");
        json.append("  \"image_base\": \"0x").append(Long.toHexString(imageBase)).append("\",\n");
        json.append("  \"generated_at\": \"").append(Instant.now()).append("\",\n");
        json.append("  \"targets\": [\n");
        for (int i = 0; i < targets.size(); i++) {
            json.append(extract(targets.get(i), imageBase, decomp));
            if (i + 1 < targets.size()) json.append(",\n");
            else json.append("\n");
            if ((i + 1) % 10 == 0 || i + 1 == targets.size()) {
                println("[TASK_160] processed " + (i + 1) + "/" + targets.size());
            }
        }
        json.append("  ]\n}\n");
        Files.createDirectories(outputPath.getParent());
        Files.write(outputPath, json.toString().getBytes(StandardCharsets.UTF_8));
        decomp.dispose();
        println("[TASK_160] wrote " + outputPath + " bytes=" + Files.size(outputPath));
    }
}
