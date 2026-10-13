import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

import java.lang.reflect.Method;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.List;

/** Read-only identity probe of an unreviewed technical-cache Program. */
public class VerifyLayerFlow206 extends GhidraScript {
    private static String esc(String input) {
        if (input == null) return "";
        return input.replace("\\", "\\\\").replace("\"", "\\\"")
            .replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t");
    }

    private static String sha(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder out = new StringBuilder();
        for (byte b : digest) out.append(String.format("%02x", b & 0xff));
        return out.toString();
    }

    private String optionalProgramString(String name) {
        try {
            Method method = currentProgram.getClass().getMethod(name);
            Object value = method.invoke(currentProgram);
            return value == null ? "" : value.toString();
        } catch (Exception ignored) {
            return "";
        }
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 5) throw new IllegalArgumentException("expected target TSV, output JSON, .text VA, size and SHA");
        Path targetsPath = Paths.get(args[0]);
        Path outputPath = Paths.get(args[1]);
        long textVa = Long.decode(args[2]);
        int textSize = Integer.parseInt(args[3]);
        String expectedTextSha = args[4].toLowerCase();
        if (textSize < 1 || textSize > 10000000 || expectedTextSha.length() != 64)
            throw new IllegalArgumentException("invalid .text bounds/hash");
        List<String> lines = Files.readAllLines(targetsPath, StandardCharsets.UTF_8);
        if (lines.size() != 128) throw new IllegalStateException("expected 128 exact targets");
        long imageBase = currentProgram.getImageBase().getOffset();
        StringBuilder rows = new StringBuilder();
        int matches = 0;
        for (String line : lines) {
            String[] fields = line.split("\t", 4);
            if (fields.length != 4) throw new IllegalArgumentException("malformed target TSV");
            int index = Integer.parseInt(fields[0]);
            long va = Long.decode(fields[1]);
            int size = Integer.parseInt(fields[2]);
            String originalSha = fields[3].toLowerCase();
            if (index < 1 || index > 128 || size < 4 || size > 4096 || size % 4 != 0 ||
                    originalSha.length() != 64) throw new IllegalArgumentException("invalid target");
            Address address = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(imageBase + va);
            byte[] memory = new byte[size];
            int read = currentProgram.getMemory().getBytes(address, memory);
            if (read != size) throw new IllegalStateException("short Ghidra memory read at " + fields[1]);
            String memorySha = sha(memory);
            boolean equals = memorySha.equals(originalSha);
            if (equals) matches++;
            if (rows.length() > 0) rows.append(',');
            rows.append("{\"index\":").append(index)
                .append(",\"elf_va\":\"").append(esc(fields[1]))
                .append("\",\"size_bytes\":").append(size)
                .append(",\"source_body_sha256\":\"").append(originalSha)
                .append("\",\"program_memory_body_sha256\":\"").append(memorySha)
                .append("\",\"body_bytes_match\":").append(equals).append('}');
        }
        String programName = currentProgram.getName();
        String language = currentProgram.getLanguage().getLanguageID().toString();
        String endian = currentProgram.getLanguage().isBigEndian() ? "BIG" : "LITTLE";
        String executablePath = optionalProgramString("getExecutablePath");
        String executableSha = optionalProgramString("getExecutableSHA256");
        String executableMd5 = optionalProgramString("getExecutableMD5");
        byte[] textBytes = new byte[textSize];
        Address textAddress = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(imageBase + textVa);
        int textRead = currentProgram.getMemory().getBytes(textAddress, textBytes);
        if (textRead != textSize) throw new IllegalStateException("short .text memory read");
        String programTextSha = sha(textBytes);
        StringBuilder out = new StringBuilder();
        out.append("{\"task_id\":\"TASK_206\",\"revision\":1,")
            .append("\"generated_at\":\"").append(Instant.now()).append("\",")
            .append("\"program_name\":\"").append(esc(programName)).append("\",")
            .append("\"image_base\":\"0x").append(Long.toHexString(imageBase)).append("\",")
            .append("\"language_id\":\"").append(esc(language)).append("\",")
            .append("\"endian\":\"").append(endian).append("\",")
            .append("\"executable_path_metadata\":\"").append(esc(executablePath)).append("\",")
            .append("\"executable_sha256_metadata\":\"").append(esc(executableSha)).append("\",")
            .append("\"executable_md5_metadata\":\"").append(esc(executableMd5)).append("\",")
            .append("\"source_text_elf_va\":\"0x").append(Long.toHexString(textVa)).append("\",")
            .append("\"source_text_size_bytes\":").append(textSize).append(',')
            .append("\"source_text_sha256\":\"").append(expectedTextSha).append("\",")
            .append("\"program_text_memory_sha256\":\"").append(programTextSha).append("\",")
            .append("\"full_text_bytes_match\":").append(programTextSha.equals(expectedTextSha)).append(',')
            .append("\"target_count\":128,\"memory_body_sha256_matches\":").append(matches)
            .append(",\"targets\":[").append(rows).append("]}\n");
        Files.createDirectories(outputPath.getParent());
        Files.writeString(outputPath, out.toString(), StandardCharsets.UTF_8);
        println("[TASK_206_IDENTITY] program=" + programName + " language=" + language +
                " body_matches=" + matches + "/128 output=" + outputPath);
    }
}
