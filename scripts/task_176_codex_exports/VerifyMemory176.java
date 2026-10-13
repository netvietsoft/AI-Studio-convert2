// TASK_176 R1: read-only hash verification of historical analyzed Ghidra memory.
// No import, analysis, or decompilation occurs in this script.
// @category Extraction

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
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

public class VerifyMemory176 extends GhidraScript {

    private static String escape(String value) {
        if (value == null) return "";
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < value.length(); i++) {
            char ch = value.charAt(i);
            switch (ch) {
                case '\\': result.append("\\\\"); break;
                case '"': result.append("\\\""); break;
                case '\n': result.append("\\n"); break;
                case '\r': result.append("\\r"); break;
                case '\t': result.append("\\t"); break;
                default:
                    if (ch < 0x20) result.append(String.format("\\u%04x", (int) ch));
                    else result.append(ch);
            }
        }
        return result.toString();
    }

    private static String sha256(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder result = new StringBuilder();
        for (byte value : digest) result.append(String.format("%02x", value & 0xff));
        return result.toString();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 3) throw new IllegalArgumentException("expected library, TSV, output JSON");
        String name = args[0];
        if (!("libbmpKit.so".equals(name) || "libfftw3.so".equals(name)) ||
            !name.equals(currentProgram.getName())) {
            throw new IllegalStateException("program outside TASK_176 pinned lane");
        }
        Path input = Paths.get(args[1]);
        Path output = Paths.get(args[2]);
        List<String> lines = Files.readAllLines(input, StandardCharsets.UTF_8);
        int expectedCount = "libbmpKit.so".equals(name) ? 316 : 367;
        if (lines.size() != expectedCount) throw new IllegalArgumentException("export count changed");
        long imageBase = currentProgram.getImageBase().getOffset();
        List<String> rows = new ArrayList<>();
        long bodyBytes = 0;
        int expectedIndex = 1;
        for (String line : lines) {
            String[] fields = line.split("\\t", 5);
            if (fields.length != 5) throw new IllegalArgumentException("invalid target TSV row");
            int index = Integer.parseInt(fields[0]);
            long va = Long.decode(fields[1]);
            int size = Integer.parseInt(fields[2]);
            String expectedSha = fields[3];
            String symbol = fields[4];
            if (index != expectedIndex++ || va <= 0 || size <= 0 || size > 65536 ||
                expectedSha.length() != 64) throw new IllegalArgumentException("invalid pinned target");
            long databaseVa = imageBase + va;
            Address address = currentProgram.getAddressFactory().getDefaultAddressSpace()
                                            .getAddress(databaseVa);
            byte[] body = new byte[size];
            int read = currentProgram.getMemory().getBytes(address, body);
            if (read != size) throw new IllegalStateException("short Ghidra memory read at " + index);
            String actualSha = sha256(body);
            if (!actualSha.equalsIgnoreCase(expectedSha)) {
                throw new IllegalStateException("Ghidra/original body mismatch at " + index);
            }
            int instructionStarts = 0;
            InstructionIterator instructions = currentProgram.getListing().getInstructions(address, true);
            while (instructions.hasNext()) {
                Instruction instruction = instructions.next();
                long pc = instruction.getAddress().getOffset();
                if (pc < databaseVa || pc >= databaseVa + size) break;
                instructionStarts++;
            }
            boolean functionPresent = currentProgram.getFunctionManager().getFunctionAt(address) != null;
            rows.add("    {\"index\": " + index + ", \"symbol\": \"" + escape(symbol) +
                     "\", \"elf_va\": \"0x" + Long.toHexString(va) +
                     "\", \"database_va\": \"0x" + Long.toHexString(databaseVa) +
                     "\", \"size_bytes\": " + size +
                     ", \"ghidra_memory_sha256\": \"" + actualSha +
                     "\", \"source_bytes_match\": true" +
                     ", \"instruction_starts\": " + instructionStarts +
                     ", \"function_present\": " + functionPresent + "}");
            bodyBytes += size;
        }
        String json = "{\n  \"schema_version\": \"2.1.2\",\n" +
                      "  \"task_id\": \"TASK_176\",\n  \"revision\": 1,\n" +
                      "  \"program_name\": \"" + escape(name) + "\",\n" +
                      "  \"image_base\": \"0x" + Long.toHexString(imageBase) + "\",\n" +
                      "  \"generated_at\": \"" + Instant.now().toString() + "\",\n" +
                      "  \"read_only_memory_check\": true,\n" +
                      "  \"fresh_imports\": 0,\n  \"fresh_decompilations\": 0,\n" +
                      "  \"target_count\": " + rows.size() + ",\n" +
                      "  \"body_bytes_hashed\": " + bodyBytes + ",\n" +
                      "  \"targets\": [\n" + String.join(",\n", rows) + "\n  ]\n}\n";
        Files.createDirectories(output.getParent());
        Files.write(output, json.getBytes(StandardCharsets.UTF_8));
        println("[TASK_176] " + name + " memory-matched=" + rows.size() +
                " body-bytes=" + bodyBytes + " fresh-decompile=0");
    }
}
