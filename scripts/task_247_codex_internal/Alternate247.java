// TASK_247 R1: bounded alternate simplification diagnostics for exact FDE465.
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

public class Alternate247 extends GhidraScript {
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

    private static String sha(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder b = new StringBuilder();
        for (byte x : digest) b.append(String.format("%02x", x & 255));
        return b.toString();
    }

    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1 || !"libPVGImageCodec.so".equals(currentProgram.getName()))
            throw new IllegalArgumentException("pinned program/output required");
        Path out = Paths.get(args[0]);
        long base = currentProgram.getImageBase().getOffset();
        Address start = currentProgram.getAddressFactory().getDefaultAddressSpace()
            .getAddress(base + ELF_VA);
        Function fn = currentProgram.getFunctionManager().getFunctionAt(start);
        if (fn == null || fn.getBody().getNumAddresses() != SIZE ||
            fn.getBody().getMinAddress().getOffset() != start.getOffset() ||
            fn.getBody().getMaxAddress().getOffset() != start.getOffset() + SIZE - 1)
            throw new IllegalStateException("exact existing function body differs");
        byte[] bytes = new byte[SIZE];
        if (currentProgram.getMemory().getBytes(start, bytes) != SIZE ||
            !SOURCE_HASH.equals(sha(bytes)))
            throw new IllegalStateException("original memory mismatch");
        int slots = 0;
        int pcodeOps = 0;
        for (int off = 0; off < SIZE; off += 4) {
            var instruction = currentProgram.getListing().getInstructionAt(start.add(off));
            if (instruction == null) throw new IllegalStateException("missing instruction at " + off);
            slots++;
            pcodeOps += instruction.getPcode().length;
        }
        String[] styles = {"firstpass", "register", "normalize"};
        StringBuilder attempts = new StringBuilder();
        for (int i = 0; i < styles.length; i++) {
            String style = styles[i];
            String cText = "";
            String error = "";
            boolean completed = false;
            long elapsed = 0;
            DecompInterface d = new DecompInterface();
            try {
                d.setOptions(new DecompileOptions());
                d.toggleCCode(true);
                d.setSimplificationStyle(style);
                if (!d.openProgram(currentProgram)) throw new IllegalStateException("open failed");
                long begin = System.nanoTime();
                DecompileResults result = d.decompileFunction(fn, 15, monitor);
                elapsed = (System.nanoTime() - begin) / 1000000;
                if (result != null) {
                    completed = result.decompileCompleted();
                    if (result.getDecompiledFunction() != null)
                        cText = result.getDecompiledFunction().getC();
                    error = result.getErrorMessage();
                } else error = "null decompiler result";
            } catch (Throwable ex) {
                error = ex.toString();
            } finally {
                d.dispose();
            }
            if (cText == null) cText = "";
            if (i > 0) attempts.append(",\n");
            attempts.append("    {\"style\": ").append(quote(style))
                .append(", \"decompile_completed\": ").append(completed)
                .append(", \"elapsed_ms\": ").append(elapsed)
                .append(", \"c_like_nonempty\": ").append(!cText.trim().isEmpty())
                .append(", \"error\": ").append(quote(error))
                .append(", \"c_like_sha256\": ")
                .append(quote(sha(cText.getBytes(StandardCharsets.UTF_8))))
                .append(", \"c_like_text\": ").append(quote(cText)).append("}");
            println("[TASK_247] " + style + " completed=" + completed +
                " c_like=" + !cText.trim().isEmpty() + " elapsed_ms=" + elapsed +
                " error=" + error);
            byte[] after = new byte[SIZE];
            currentProgram.getMemory().getBytes(start, after);
            if (!SOURCE_HASH.equals(sha(after)))
                throw new IllegalStateException("memory changed after " + style);
        }
        String json = "{\n" +
            "  \"task_id\": \"TASK_247\", \"revision\": 1,\n" +
            "  \"generated_at\": " + quote(Instant.now().toString()) + ",\n" +
            "  \"global_zero_based_fde_index\": 465, \"elf_va\": \"0x1ebdd8\",\n" +
            "  \"database_va\": " + quote("0x" + Long.toHexString(start.getOffset())) + ",\n" +
            "  \"size_bytes\": " + SIZE + ", \"instruction_slots\": " + slots +
            ", \"pcode_ops\": " + pcodeOps + ",\n" +
            "  \"source_memory_sha256\": " + quote(SOURCE_HASH) + ",\n" +
            "  \"function_body_bytes\": " + fn.getBody().getNumAddresses() + ",\n" +
            "  \"styles\": [\n" + attempts + "\n  ]\n}\n";
        Files.write(out, json.getBytes(StandardCharsets.UTF_8));
    }
}
