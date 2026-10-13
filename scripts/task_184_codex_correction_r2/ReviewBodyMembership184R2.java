// TASK_184 R2: verify full Ghidra function body membership, not only min/max endpoints.
// @category Extraction

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.List;

public class ReviewBodyMembership184R2 extends GhidraScript {
    private static String sha(byte[] data) throws Exception {
        StringBuilder out = new StringBuilder();
        for (byte b : MessageDigest.getInstance("SHA-256").digest(data)) {
            out.append(String.format("%02x", b & 0xff));
        }
        return out.toString();
    }

    private static String hex(byte[] data) {
        StringBuilder out = new StringBuilder();
        for (byte b : data) out.append(String.format("%02x", b & 0xff));
        return out.toString();
    }

    private static String escape(String input) {
        if (input == null) return "";
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            if (ch == '\\') out.append("\\\\");
            else if (ch == '"') out.append("\\\"");
            else if (ch == '\n') out.append("\\n");
            else if (ch == '\r') out.append("\\r");
            else if (ch == '\t') out.append("\\t");
            else if (ch < 0x20) out.append(String.format("\\u%04x", (int) ch));
            else out.append(ch);
        }
        return out.toString();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("targets TSV and output NDJSON required");
        if (!"libVERenderer.so".equals(currentProgram.getName())) {
            throw new IllegalStateException("wrong analyzed program: " + currentProgram.getName());
        }
        Path input = Paths.get(args[0]);
        Path output = Paths.get(args[1]);
        List<String> lines = Files.readAllLines(input, StandardCharsets.UTF_8);
        if (lines.size() != 141) throw new IllegalStateException("expected 141 pinned targets");
        if (Files.exists(output)) throw new IllegalStateException("duplicate R2 body-membership output");
        Files.createDirectories(output.getParent());
        long base = currentProgram.getImageBase().getOffset();
        int exact = 0;
        int nonexact = 0;
        println("[TASK_184_R2] start " + Instant.now() + " image_base=0x" + Long.toHexString(base));
        try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
            for (String line : lines) {
                String[] f = line.split("\t", -1);
                if (f.length != 5) throw new IllegalArgumentException("invalid target row");
                int index = Integer.parseInt(f[0]);
                long va = Long.decode(f[1]);
                int size = Integer.parseInt(f[2]);
                long fileOffset = Long.decode(f[3]);
                String expected = f[4].toLowerCase();
                if (index < 1 || index > 141 || size < 4 || size > 4096 || size % 4 != 0 || expected.length() != 64) {
                    throw new IllegalArgumentException("target bounds invalid at index " + index);
                }
                Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + va);
                Address end = start.add(size - 1);
                byte[] bytes = new byte[size];
                currentProgram.getMemory().getBytes(start, bytes);
                String actual = sha(bytes);
                if (!actual.equals(expected)) throw new IllegalStateException("Ghidra memory differs from pinned original body at " + index);
                Function function = getFunctionAt(start);
                AddressSetView body = function == null ? null : function.getBody();
                long bodyBytes = body == null ? -1 : body.getNumAddresses();
                boolean containsFull = body != null && body.contains(start, end);
                long membershipBytes = 0;
                if (body != null) {
                    for (int i = 0; i < size; i++) {
                        if (body.contains(start.add(i))) membershipBytes++;
                    }
                }
                long missingBytes = size - membershipBytes;
                boolean exactBody = containsFull && bodyBytes == size;
                if (exactBody) exact++; else nonexact++;
                StringBuilder omissions = new StringBuilder("[");
                int omittedSlots = 0;
                for (int i = 0; i < size; i += 4) {
                    Address slot = start.add(i);
                    if (body != null && body.contains(slot, slot.add(3))) continue;
                    if (omittedSlots > 0) omissions.append(",");
                    byte[] word = new byte[] {bytes[i], bytes[i + 1], bytes[i + 2], bytes[i + 3]};
                    Instruction instruction = getInstructionAt(slot);
                    omissions.append("{\"elf_va\":\"0x").append(Long.toHexString(va + i))
                        .append("\",\"database_va\":\"0x").append(Long.toHexString(base + va + i))
                        .append("\",\"original_file_offset\":\"0x").append(Long.toHexString(fileOffset + i))
                        .append("\",\"word_le\":\"").append(hex(word))
                        .append("\",\"word_sha256\":\"").append(sha(word))
                        .append("\",\"ghidra_listing\":\"")
                        .append(escape(instruction == null ? "<none>" : instruction.toString()))
                        .append("\"}");
                    omittedSlots++;
                }
                omissions.append("]");
                String min = body == null ? "" : body.getMinAddress().toString();
                String max = body == null ? "" : body.getMaxAddress().toString();
                String name = function == null ? "" : function.getName();
                writer.write("{\"index\":" + index + ",\"elf_va\":\"0x" + Long.toHexString(va)
                    + "\",\"fde_size_bytes\":" + size + ",\"original_file_offset\":\"0x"
                    + Long.toHexString(fileOffset) + "\",\"expected_original_body_sha256\":\"" + expected
                    + "\",\"owned_project_memory_sha256\":\"" + actual
                    + "\",\"function_at_start\":" + (function != null)
                    + ",\"function_name\":\"" + escape(name)
                    + "\",\"body_num_addresses\":" + bodyBytes
                    + ",\"body_contains_fde\":" + containsFull
                    + ",\"body_member_bytes_within_fde\":" + membershipBytes
                    + ",\"body_missing_bytes_within_fde\":" + missingBytes
                    + ",\"body_extra_bytes_outside_fde\":" + (body == null ? -1 : bodyBytes - membershipBytes)
                    + ",\"body_equals_fde\":" + exactBody
                    + ",\"body_min\":\"" + min + "\",\"body_max\":\"" + max
                    + "\",\"missing_instruction_slots\":" + omittedSlots
                    + ",\"missing_instructions\":" + omissions + "}");
                writer.newLine();
                if (index % 20 == 0 || index == 141) {
                    println("[TASK_184_R2] checked " + index + "/141 exact=" + exact + " nonexact=" + nonexact);
                }
            }
        }
        println("[TASK_184_R2] finished " + Instant.now() + " exact=" + exact + " nonexact=" + nonexact + " output=" + output);
    }
}
