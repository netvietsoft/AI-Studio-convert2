// TASK_175 R1: one isolated normalize-style decompilation of a historical gap.
// @category Extraction

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.pcode.PcodeOp;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

public class AttemptGlideMissing175 extends GhidraScript {
    private static final long ELF_VA = 0x328dcL;
    private static final int SIZE = 624;
    private static final String SYMBOL = "WebPConvertRGBA32ToUV_C";
    private static final String SOURCE_SHA =
        "2f7f38acc0d294a3333069aa8a3c07e69d4bc0a64f162215578bd55dbe1a4486";
    private static final String BODY_SHA =
        "fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404";

    private static String escape(String text) {
        if (text == null) return "";
        StringBuilder out = new StringBuilder();
        for (int index = 0; index < text.length(); index++) {
            char ch = text.charAt(index);
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

    private static void array(StringBuilder out, String key, List<String> values) {
        out.append("  \"").append(key).append("\": [");
        for (int index = 0; index < values.size(); index++) {
            if (index != 0) out.append(",");
            out.append("\n    \"").append(escape(values.get(index))).append("\"");
        }
        if (!values.isEmpty()) out.append("\n  ");
        out.append("],\n");
    }

    @Override
    public void run() throws Exception {
        String[] arguments = getScriptArgs();
        if (arguments.length != 1) throw new IllegalArgumentException("expected output JSON path");
        if (!"libglide-webp.so".equals(currentProgram.getName())) {
            throw new IllegalStateException("wrong analyzed project program");
        }
        Path output = Paths.get(arguments[0]);
        long imageBase = currentProgram.getImageBase().getOffset();
        long databaseVa = imageBase + ELF_VA;
        Address address = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(databaseVa);
        byte[] body = new byte[SIZE];
        currentProgram.getMemory().getBytes(address, body);
        String memorySha = hash(body);
        if (!BODY_SHA.equals(memorySha)) {
            throw new IllegalStateException("copied Ghidra project body differs from original ELF PT_LOAD");
        }
        Function function = getFunctionAt(address);
        if (function == null) {
            throw new IllegalStateException("expected analyzed function is absent");
        }
        List<String> instructions = new ArrayList<>();
        List<String> pcode = new ArrayList<>();
        InstructionIterator iterator = currentProgram.getListing().getInstructions(address, true);
        while (iterator.hasNext()) {
            Instruction instruction = iterator.next();
            long offset = instruction.getAddress().getOffset();
            if (offset < databaseVa || offset >= databaseVa + SIZE) break;
            instructions.add(instruction.getAddress() + ": " + instruction);
            for (PcodeOp operation : instruction.getPcode()) {
                pcode.add(instruction.getAddress() + ": " + operation);
            }
        }
        if (instructions.size() != 156) {
            throw new IllegalStateException("copied project no longer lists all 156 original instructions");
        }
        DecompInterface decompiler = new DecompInterface();
        decompiler.setOptions(new DecompileOptions());
        long started = System.nanoTime();
        DecompileResults result = null;
        String error = "";
        boolean styleSupported = decompiler.setSimplificationStyle("normalize");
        try {
            if (!styleSupported) {
                error = "normalize analysis style not supported";
            } else {
                decompiler.toggleCCode(true);
                decompiler.toggleSyntaxTree(true);
                if (!decompiler.openProgram(currentProgram)) {
                    error = "could not open copied project in Ghidra decompiler";
                } else {
                    result = decompiler.decompileFunction(function, 15, monitor);
                }
            }
        } catch (Exception exception) {
            error = exception.getClass().getSimpleName() + ": " + exception.getMessage();
        }
        double elapsedMs = (System.nanoTime() - started) / 1000000.0;
        boolean completed = result != null && result.decompileCompleted();
        String cLike = completed && result.getDecompiledFunction() != null ?
            result.getDecompiledFunction().getC() : "";
        if (result != null && result.getErrorMessage() != null && !result.getErrorMessage().isEmpty()) {
            error = result.getErrorMessage();
        }
        decompiler.dispose();
        StringBuilder json = new StringBuilder();
        json.append("{\n  \"schema_version\": \"2.1.2\",\n");
        json.append("  \"task_id\": \"TASK_175\",\n  \"revision\": 1,\n");
        json.append("  \"historical_task_id\": \"TASK_155\",\n");
        json.append("  \"program_name\": \"libglide-webp.so\",\n");
        json.append("  \"source_sha256\": \"").append(SOURCE_SHA).append("\",\n");
        json.append("  \"symbol\": \"").append(SYMBOL).append("\",\n");
        json.append("  \"ghidra_function_name\": \"").append(escape(function.getName())).append("\",\n");
        json.append("  \"elf_va\": \"0x328dc\",\n");
        json.append("  \"database_va\": \"0x").append(Long.toHexString(databaseVa)).append("\",\n");
        json.append("  \"image_base\": \"0x").append(Long.toHexString(imageBase)).append("\",\n");
        json.append("  \"size_bytes\": 624,\n");
        json.append("  \"original_source_body_sha256\": \"").append(BODY_SHA).append("\",\n");
        json.append("  \"copied_ghidra_memory_sha256\": \"").append(memorySha).append("\",\n");
        json.append("  \"analysis_style\": \"normalize\",\n");
        json.append("  \"analysis_style_supported\": ").append(styleSupported).append(",\n");
        json.append("  \"decompile_elapsed_ms\": ").append(elapsedMs).append(",\n");
        json.append("  \"decompile_completed\": ").append(completed).append(",\n");
        json.append("  \"c_like_nonempty\": ").append(!cLike.trim().isEmpty()).append(",\n");
        json.append("  \"c_like\": \"").append(escape(cLike)).append("\",\n");
        json.append("  \"error\": \"").append(escape(error)).append("\",\n");
        json.append("  \"instruction_count\": ").append(instructions.size()).append(",\n");
        array(json, "instructions", instructions);
        array(json, "pcode", pcode);
        json.append("  \"generated_at\": \"").append(Instant.now()).append("\"\n}\n");
        Files.createDirectories(output.getParent());
        Files.write(output, json.toString().getBytes(StandardCharsets.UTF_8));
        println("[TASK_175] isolated normalize attempt completed=" + completed +
            " c_like_nonempty=" + !cLike.trim().isEmpty() + " instructions=" + instructions.size() +
            " pcode=" + pcode.size() + " output=" + output);
    }
}
