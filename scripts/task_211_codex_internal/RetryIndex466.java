// TASK_211: one bounded retry of zero-based FDE index 465 / R1 row 466.
// @category Extraction
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;

public class RetryIndex466 extends GhidraScript {
    private static final long ELF_VA = 0x1ebdd8L;
    private static final int SIZE = 2780;
    private static final String SOURCE_HASH =
        "2ee0e7f90483583800b9d2f7e93ff3f73456d991585e00cc7d211af010db3cca";

    private static String quote(String s) {
        if (s == null) s = "";
        StringBuilder b = new StringBuilder("\"");
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '\\') b.append("\\\\");
            else if (c == '"') b.append("\\\"");
            else if (c == '\n') b.append("\\n");
            else if (c == '\r') b.append("\\r");
            else if (c == '\t') b.append("\\t");
            else if (c < 32) b.append(String.format("\\u%04x", (int)c));
            else b.append(c);
        }
        return b.append('"').toString();
    }

    private static String sha256(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder b = new StringBuilder();
        for (byte x : digest) b.append(String.format("%02x", x & 255));
        return b.toString();
    }

    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2 || !"libPVGImageCodec.so".equals(currentProgram.getName()))
            throw new IllegalArgumentException("pinned program, output path and mode required");
        Path out = Paths.get(args[0]);
        String mode = args[1];
        if (!mode.equals("retry") && !mode.equals("fresh_verify"))
            throw new IllegalArgumentException("mode must be retry or fresh_verify");
        long base = currentProgram.getImageBase().getOffset();
        Address start = currentProgram.getAddressFactory().getDefaultAddressSpace()
            .getAddress(base + ELF_VA);
        Function fn = currentProgram.getFunctionManager().getFunctionAt(start);
        if (fn == null || fn.getBody().getNumAddresses() != SIZE ||
            fn.getBody().getMinAddress().getOffset() != start.getOffset() ||
            fn.getBody().getMaxAddress().getOffset() != start.getOffset() + SIZE - 1)
            throw new IllegalStateException("existing exact Ghidra function differs");
        byte[] bytes = new byte[SIZE];
        if (currentProgram.getMemory().getBytes(start, bytes) != SIZE ||
            !SOURCE_HASH.equals(sha256(bytes)))
            throw new IllegalStateException("Ghidra memory differs from pinned original range");
        int instructions = 0;
        for (int off = 0; off < SIZE; off += 4) {
            if (currentProgram.getListing().getInstructionAt(start.add(off)) == null)
                throw new IllegalStateException("missing analyzed instruction at offset " + off);
            instructions++;
        }
        boolean complete = false;
        String cText = "";
        String error = "";
        long elapsed = 0;
        if (mode.equals("retry")) {
            DecompInterface d = new DecompInterface();
            d.setOptions(new DecompileOptions());
            d.toggleCCode(true);
            d.setSimplificationStyle("decompile");
            if (!d.openProgram(currentProgram)) throw new IllegalStateException("decompiler open failed");
            try {
                long begin = System.nanoTime();
                DecompileResults result = d.decompileFunction(fn, 15, monitor);
                elapsed = (System.nanoTime() - begin) / 1000000;
                if (result != null && result.decompileCompleted() &&
                    result.getDecompiledFunction() != null) {
                    cText = result.getDecompiledFunction().getC();
                    complete = cText != null && !cText.trim().isEmpty();
                } else error = result == null ? "null result" : result.getErrorMessage();
            } finally { d.dispose(); }
        }
        byte[] after = new byte[SIZE];
        currentProgram.getMemory().getBytes(start, after);
        if (!SOURCE_HASH.equals(sha256(after)))
            throw new IllegalStateException("Ghidra memory changed");
        String json = "{\n" +
            "  \"task_id\": \"TASK_211\", \"revision\": 1,\n" +
            "  \"generated_at\": " + quote(Instant.now().toString()) + ",\n" +
            "  \"mode\": " + quote(mode) + ",\n" +
            "  \"global_zero_based_fde_index\": 465, \"r1_raw_one_based_row\": 466,\n" +
            "  \"elf_va\": \"0x1ebdd8\", \"database_va\": " +
                quote("0x" + Long.toHexString(start.getOffset())) + ",\n" +
            "  \"size_bytes\": " + SIZE + ", \"instruction_slots\": " + instructions + ",\n" +
            "  \"original_memory_sha256\": " + quote(SOURCE_HASH) + ",\n" +
            "  \"function_name\": " + quote(fn.getName()) + ",\n" +
            "  \"function_body_bytes\": " + fn.getBody().getNumAddresses() + ",\n" +
            "  \"c_like_nonempty\": " + complete + ", \"elapsed_ms\": " + elapsed + ",\n" +
            "  \"decompile_error\": " + quote(error) + ",\n" +
            "  \"c_like_text\": " + quote(cText) + "\n}\n";
        Files.write(out, json.getBytes(StandardCharsets.UTF_8));
        println("[TASK_211] " + mode + " row466 c_like=" + complete +
                " original_bytes=" + SIZE + " instructions=" + instructions +
                " elapsed_ms=" + elapsed + " error=" + error);
    }
}
