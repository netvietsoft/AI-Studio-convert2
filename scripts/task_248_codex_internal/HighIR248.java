// TASK_248 R1: extract bounded register-style HighFunction IR, not C or source recovery.
// @category Extraction
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.pcode.PcodeOpAST;
import ghidra.program.model.pcode.HighFunction;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.HashSet;
import java.util.Iterator;

public class HighIR248 extends GhidraScript {
    private static final long ELF_VA = 0xa8b08L;
    private static final int SIZE = 27524;
    private static final String SOURCE_HASH =
        "7c65b7edc58d97da61177d6c07fe5579bf950074592f79dc0bb6d4499e904fb5";

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
        if (args.length != 1 || !"libPVGCodec.so".equals(currentProgram.getName()))
            throw new IllegalArgumentException("pinned program/output required");
        Path out = Paths.get(args[0]);
        long base = currentProgram.getImageBase().getOffset();
        Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + ELF_VA);
        Function fn = currentProgram.getFunctionManager().getFunctionAt(start);
        if (fn == null || fn.getBody().getNumAddresses() != 25916 ||
            fn.getBody().getMinAddress().getOffset() != start.getOffset() ||
            fn.getBody().getMaxAddress().getOffset() != start.getOffset() + SIZE - 1)
            throw new IllegalStateException("exact function body differs");
        byte[] bytes = new byte[SIZE];
        if (currentProgram.getMemory().getBytes(start, bytes) != SIZE || !SOURCE_HASH.equals(sha(bytes)))
            throw new IllegalStateException("original memory mismatch");
        DecompInterface d = new DecompInterface();
        d.setOptions(new DecompileOptions());
        d.toggleCCode(false);
        d.setSimplificationStyle("register");
        if (!d.openProgram(currentProgram)) throw new IllegalStateException("decompiler open failed");
        long begin = System.nanoTime();
        DecompileResults result;
        try {
            result = d.decompileFunction(fn, 15, monitor);
        } finally {
            d.dispose();
        }
        long elapsed = (System.nanoTime() - begin) / 1000000;
        HighFunction high = result == null ? null : result.getHighFunction();
        StringBuilder ops = new StringBuilder();
        int count = 0;
        HashSet<Long> instructionVAs = new HashSet<>();
        if (high != null) {
            Iterator<PcodeOpAST> it = high.getPcodeOps();
            while (it.hasNext()) {
                PcodeOpAST op = it.next();
                long dbVa = op.getSeqnum().getTarget().getOffset();
                long elfVa = dbVa - base;
                if (elfVa >= ELF_VA && elfVa < ELF_VA + SIZE && (elfVa - ELF_VA) % 4 == 0)
                    instructionVAs.add(elfVa);
                if (count > 0) ops.append(",\n");
                ops.append("    {\"database_va\": ").append(quote("0x" + Long.toHexString(dbVa)))
                    .append(", \"elf_va\": ").append(quote("0x" + Long.toHexString(elfVa)))
                    .append(", \"opcode\": ").append(quote(op.getMnemonic()))
                    .append(", \"ir\": ").append(quote(op.toString())).append("}");
                count++;
            }
        }
        byte[] after = new byte[SIZE];
        currentProgram.getMemory().getBytes(start, after);
        if (!SOURCE_HASH.equals(sha(after))) throw new IllegalStateException("memory changed");
        String json = "{\n" +
            "  \"task_id\": \"TASK_248\", \"revision\": 1,\n" +
            "  \"generated_at\": " + quote(Instant.now().toString()) + ",\n" +
            "  \"mode\": \"register_high_ir_no_c\",\n" +
            "  \"elf_va\": \"0xa8b08\", \"size_bytes\": 27524,\n" +
            "  \"source_memory_sha256\": " + quote(SOURCE_HASH) + ",\n" +
            "  \"decompile_completed\": " + (result != null && result.decompileCompleted()) + ",\n" +
            "  \"error\": " + quote(result == null ? "null result" : result.getErrorMessage()) + ",\n" +
            "  \"elapsed_ms\": " + elapsed + ",\n" +
            "  \"high_function_present\": " + (high != null) + ",\n" +
            "  \"high_ir_ops\": " + count + ",\n" +
            "  \"unique_source_instruction_vas\": " + instructionVAs.size() + ",\n" +
            "  \"ops\": [\n" + ops + "\n  ]\n}\n";
        Files.write(out, json.getBytes(StandardCharsets.UTF_8));
        println("[TASK_248] register high IR ops=" + count + " source_vas=" +
            instructionVAs.size() + " completed=" + (result != null && result.decompileCompleted()));
    }
}
