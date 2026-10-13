// TASK_179: one bounded alternative pass on a synthetic scalar-tail function.
// The full original function is not changed on disk; only metadata in a read-only copied project is altered.
// @category Extraction

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.SourceType;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;

public class ScalarTailProbe179 extends GhidraScript {
    private static final long START_VA = 0x328dcL;
    private static final long TAIL_VA = 0x32ab8L;
    private static final long END_VA = 0x32b48L;
    private static final int SIZE = 624;
    private static final String BODY_SHA =
        "fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404";

    private static String hash(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder out = new StringBuilder();
        for (byte value : digest) out.append(String.format("%02x", value & 0xff));
        return out.toString();
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
                    if (ch < 0x20) out.append(String.format("\\u%04x", (int)ch));
                    else out.append(ch);
            }
        }
        return out.toString();
    }

    @Override
    public void run() throws Exception {
        String[] arguments = getScriptArgs();
        if (arguments.length != 1) throw new IllegalArgumentException("one task-report output path required");
        if (!"libglide-webp.so".equals(currentProgram.getName())) {
            throw new IllegalStateException("wrong analyzed source program");
        }
        Path output = Paths.get(arguments[0]);
        long imageBase = currentProgram.getImageBase().getOffset();
        Address start = toAddr(imageBase + START_VA);
        Address tailStart = toAddr(imageBase + TAIL_VA);
        Address tailEnd = toAddr(imageBase + END_VA);
        byte[] bytes = new byte[SIZE];
        currentProgram.getMemory().getBytes(start, bytes);
        String memorySha = hash(bytes);
        if (!BODY_SHA.equals(memorySha)) {
            throw new IllegalStateException("copied project memory differs from original source bytes");
        }
        FunctionManager functions = currentProgram.getFunctionManager();
        Function original = functions.getFunctionAt(start);
        if (original == null || !"WebPConvertRGBA32ToUV_C".equals(original.getName())) {
            throw new IllegalStateException("expected original analyzed function not found");
        }
        if (!functions.removeFunction(start)) {
            throw new IllegalStateException("could not remove overlapping function metadata in copy");
        }
        Listing listing = currentProgram.getListing();
        Function tail = listing.createFunction("TASK_179_scalar_tail_probe", tailStart,
            new AddressSet(tailStart, tailEnd), SourceType.USER_DEFINED);
        if (tail == null) throw new IllegalStateException("could not create isolated scalar-tail probe");
        DecompInterface decompiler = new DecompInterface();
        decompiler.setOptions(new DecompileOptions());
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        boolean styleSupported = decompiler.setSimplificationStyle("decompile");
        if (!styleSupported || !decompiler.openProgram(currentProgram)) {
            throw new IllegalStateException("normal decompiler mode unavailable for scalar-tail probe");
        }
        long started = System.nanoTime();
        DecompileResults result = decompiler.decompileFunction(tail, 120, monitor);
        double elapsedMs = (System.nanoTime() - started) / 1000000.0;
        boolean completed = result != null && result.decompileCompleted();
        String c = completed && result.getDecompiledFunction() != null ?
            result.getDecompiledFunction().getC() : "";
        String error = result != null && result.getErrorMessage() != null ? result.getErrorMessage() : "";
        decompiler.dispose();
        StringBuilder json = new StringBuilder();
        json.append("{\n  \"schema_version\": \"2.1.2\",\n");
        json.append("  \"task_id\": \"TASK_179\",\n  \"revision\": 1,\n");
        json.append("  \"program_name\": \"libglide-webp.so\",\n");
        json.append("  \"source_body_sha256\": \"").append(BODY_SHA).append("\",\n");
        json.append("  \"copied_project_memory_sha256\": \"").append(memorySha).append("\",\n");
        json.append("  \"original_elf_va\": \"0x328dc\",\n");
        json.append("  \"synthetic_tail_elf_va\": \"0x32ab8\",\n");
        json.append("  \"synthetic_tail_end_elf_va\": \"0x32b48\",\n");
        json.append("  \"whole_original_function_decompiled\": false,\n");
        json.append("  \"decompile_style\": \"decompile\",\n");
        json.append("  \"decompile_elapsed_ms\": ").append(elapsedMs).append(",\n");
        json.append("  \"decompile_completed\": ").append(completed).append(",\n");
        json.append("  \"scalar_tail_c_like_nonempty\": ").append(!c.trim().isEmpty()).append(",\n");
        json.append("  \"scalar_tail_c_like\": \"").append(escape(c)).append("\",\n");
        json.append("  \"error\": \"").append(escape(error)).append("\",\n");
        json.append("  \"generated_at\": \"").append(Instant.now()).append("\"\n}\n");
        Files.createDirectories(output.getParent());
        Files.write(output, json.toString().getBytes(StandardCharsets.UTF_8));
        println("[TASK_179] scalar-tail-only probe completed=" + completed +
            " c_like_nonempty=" + !c.trim().isEmpty() + " elapsed_ms=" + elapsedMs +
            " output=" + output);
    }
}
