// TASK_192: fresh read-only session check after transient metadata rollback.
// @category Extraction

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.util.List;

public class CheckOriginalMembership192 extends GhidraScript {
    private static String hash(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder out = new StringBuilder();
        for (byte b : digest) out.append(String.format("%02x", b & 0xff));
        return out.toString();
    }

    private static String q(String value) {
        if (value == null) value = "";
        return "\"" + value.replace("\\", "\\\\").replace("\"", "\\\"") + "\"";
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2 || !"libPVGImageCodec.so".equals(currentProgram.getName()))
            throw new IllegalArgumentException("pinned program, 4-row TSV/output required");
        Path input = Paths.get(args[0]);
        Path output = Paths.get(args[1]);
        List<String> targets = Files.readAllLines(input, StandardCharsets.US_ASCII);
        if (targets.size() != 4) throw new IllegalStateException("expected 4 rows");
        Files.createDirectories(output);
        long base = currentProgram.getImageBase().getOffset();
        FunctionManager manager = currentProgram.getFunctionManager();
        int prior = 0;
        for (String line : targets) {
            String[] cols = line.split("\\t");
            if (cols.length != 4) throw new IllegalArgumentException("bad TSV row");
            int index = Integer.parseInt(cols[0]);
            long va = Long.decode(cols[1]);
            int size = Integer.parseInt(cols[2]);
            if (index <= prior || index < 1 || index > 64 || size < 4 || size > 4096 || size % 4 != 0)
                throw new IllegalArgumentException("out-of-scope row");
            prior = index;
            Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + va);
            byte[] bytes = new byte[size];
            if (currentProgram.getMemory().getBytes(start, bytes) != size ||
                !hash(bytes).equalsIgnoreCase(cols[3]))
                throw new IllegalStateException("memory/body mismatch index " + index);
            Function function = manager.getFunctionAt(start);
            if (function == null) throw new IllegalStateException("original function absent index " + index);
            StringBuilder bits = new StringBuilder(size);
            int otherBytes = 0;
            for (int off = 0; off < size; off++) {
                Address pc = start.add(off);
                bits.append(function.getBody().contains(pc) ? '1' : '0');
                Function owner = manager.getFunctionContaining(pc);
                if (owner != null && !owner.getEntryPoint().equals(start)) otherBytes++;
            }
            String data = "{\"task_id\":\"TASK_192\",\"revision\":1," +
                "\"index\":" + index + ",\"elf_va\":" + q(cols[1]) +
                ",\"size_bytes\":" + size + ",\"memory_sha256\":" + q(hash(bytes)) +
                ",\"function_name\":" + q(function.getName()) +
                ",\"function_start\":" + q("0x" + Long.toHexString(function.getEntryPoint().getOffset())) +
                ",\"body_bits\":" + q(bits.toString()) +
                ",\"other_function_byte_count\":" + otherBytes + "}\n";
            Files.write(output.resolve(String.format("%03d_%x.json", index, va)),
                        data.getBytes(StandardCharsets.UTF_8));
            println("[TASK_192_POSTROLLBACK] index=" + index + " membership=" +
                    bits.chars().filter(c -> c == '1').count() + "/" + size +
                    " other_owner=" + otherBytes);
        }
    }
}
