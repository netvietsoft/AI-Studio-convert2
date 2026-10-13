// TASK_182: one vector-only synthetic-metadata probe in a byte-verified copied project.
// This does not edit the original SO/project and cannot establish whole-function C.
// @category Extraction

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.SourceType;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;

public class VectorProbe182 extends GhidraScript {
    private static final long ORIGINAL = 0x328dcL;
    private static final long VECTOR_START = 0x3294cL;
    private static final long VECTOR_END_INCLUSIVE = 0x32ab0L;
    private static final int SIZE = 624;
    private static final String BODY_SHA =
        "fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404";

    private static String hash(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder out = new StringBuilder();
        for (byte value : digest) out.append(String.format("%02x", value & 0xff));
        return out.toString();
    }

    private static String escape(String value) {
        if (value == null) return "";
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < value.length(); i++) {
            char ch = value.charAt(i);
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
        if (args.length != 1) throw new IllegalArgumentException("one output JSON path required");
        if (!"libglide-webp.so".equals(currentProgram.getName())) {
            throw new IllegalStateException("wrong analyzed source program");
        }
        Path output = Paths.get(args[0]);
        long image = currentProgram.getImageBase().getOffset();
        Address original = toAddr(image + ORIGINAL);
        Address vectorStart = toAddr(image + VECTOR_START);
        Address vectorEnd = toAddr(image + VECTOR_END_INCLUSIVE);
        byte[] body = new byte[SIZE];
        currentProgram.getMemory().getBytes(original, body);
        String memorySha = hash(body);
        if (!BODY_SHA.equals(memorySha)) throw new IllegalStateException("source-memory hash mismatch");
        FunctionManager functions = currentProgram.getFunctionManager();
        Function originalFunction = functions.getFunctionAt(original);
        if (originalFunction == null || !"WebPConvertRGBA32ToUV_C".equals(originalFunction.getName())) {
            throw new IllegalStateException("original analyzed function absent");
        }
        Listing listing = currentProgram.getListing();
        int instructions = 0;
        int pcodeOps = 0;
        for (long va = VECTOR_START; va <= VECTOR_END_INCLUSIVE; va += 4) {
            Instruction ins = listing.getInstructionAt(toAddr(image + va));
            if (ins == null || ins.getLength() != 4) throw new IllegalStateException("missing vector instruction at " + Long.toHexString(va));
            instructions++;
            pcodeOps += ins.getPcode().length;
        }
        if (!functions.removeFunction(original)) throw new IllegalStateException("cannot isolate vector metadata");
        Function vector = listing.createFunction("TASK_182_vector_probe", vectorStart,
            new AddressSet(vectorStart, vectorEnd), SourceType.USER_DEFINED);
        if (vector == null) throw new IllegalStateException("cannot create vector probe function");
        DecompInterface decompiler = new DecompInterface();
        decompiler.setOptions(new DecompileOptions());
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        boolean style = decompiler.setSimplificationStyle("decompile");
        if (!style || !decompiler.openProgram(currentProgram)) throw new IllegalStateException("decompiler unavailable");
        long started = System.nanoTime();
        DecompileResults result = decompiler.decompileFunction(vector, 90, monitor);
        double elapsedMs = (System.nanoTime() - started) / 1000000.0;
        boolean completed = result != null && result.decompileCompleted();
        String c = completed && result.getDecompiledFunction() != null ? result.getDecompiledFunction().getC() : "";
        String error = result == null ? "null result" : result.getErrorMessage();
        decompiler.dispose();
        StringBuilder json = new StringBuilder();
        json.append("{\n  \"schema_version\": \"2.1.2\",\n  \"task_id\": \"TASK_182\",\n");
        json.append("  \"revision\": 1,\n  \"program_name\": \"libglide-webp.so\",\n");
        json.append("  \"original_elf_va\": \"0x328dc\",\n  \"vector_start_elf_va\": \"0x3294c\",\n");
        json.append("  \"vector_end_exclusive_elf_va\": \"0x32ab4\",\n");
        json.append("  \"copied_project_memory_sha256\": \"").append(memorySha).append("\",\n");
        json.append("  \"synthetic_metadata_only\": true,\n  \"whole_original_function_decompiled\": false,\n");
        json.append("  \"entry_register_state_proven\": false,\n");
        json.append("  \"vector_instruction_count\": ").append(instructions).append(",\n");
        json.append("  \"vector_pcode_ops\": ").append(pcodeOps).append(",\n");
        json.append("  \"decompile_style\": \"decompile\",\n  \"decompile_elapsed_ms\": ").append(elapsedMs).append(",\n");
        json.append("  \"decompile_completed\": ").append(completed).append(",\n");
        json.append("  \"vector_fragment_c_like_nonempty\": ").append(!c.trim().isEmpty()).append(",\n");
        json.append("  \"vector_fragment_c_like\": \"").append(escape(c)).append("\",\n");
        json.append("  \"error\": \"").append(escape(error)).append("\",\n");
        json.append("  \"generated_at\": \"").append(Instant.now()).append("\"\n}\n");
        Files.createDirectories(output.getParent());
        Files.write(output, json.toString().getBytes(StandardCharsets.UTF_8));
        println("[TASK_182] vector-only completed=" + completed + " c_like=" + !c.trim().isEmpty() +
            " instructions=" + instructions + " pcode=" + pcodeOps + " elapsed_ms=" + elapsedMs);
    }
}
