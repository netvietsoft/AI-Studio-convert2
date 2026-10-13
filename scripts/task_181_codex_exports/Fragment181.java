// TASK_181: one isolated original-byte fragment decompile per pinned FFmpeg export.
// The original SO and historical Ghidra project are read-only; this operates on a copy.
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
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.symbol.SourceType;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

public class Fragment181 extends GhidraScript {
    private static String sha(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder value = new StringBuilder();
        for (byte one : digest) value.append(String.format("%02x", one & 0xff));
        return value.toString();
    }
    private static String esc(String text) {
        if (text == null) return "";
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (c == '\\') result.append("\\\\");
            else if (c == '"') result.append("\\\"");
            else if (c == '\n') result.append("\\n");
            else if (c == '\r') result.append("\\r");
            else if (c == '\t') result.append("\\t");
            else if (c < 32) result.append(String.format("\\u%04x", (int)c));
            else result.append(c);
        }
        return result.toString();
    }
    private static void field(StringBuilder j, String key, String value) {
        j.append("  \"").append(key).append("\": \"").append(esc(value)).append("\",\n");
    }
    private static void lines(StringBuilder j, String key, List<String> values) {
        j.append("  \"").append(key).append("\": [");
        for (int i = 0; i < values.size(); i++) {
            if (i > 0) j.append(", ");
            j.append('"').append(esc(values.get(i))).append('"');
        }
        j.append("],\n");
    }
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("target index and output path required");
        int index = Integer.parseInt(args[0]);
        long originalVa, fragmentVa, fragmentEndVa;
        int originalSize;
        String bodySha, symbol;
        if (index == 2283) {
            originalVa = 0x658fe8L; originalSize = 736;
            bodySha = "94017dc1deb91f10d8a4fd18f131f5d7741d0512c73c533de6d9845fbe095cee";
            symbol = "x264_8_deblock_h_luma_intra_neon";
            fragmentVa = 0x659200L; fragmentEndVa = 0x6592c4L;
        } else if (index == 2330) {
            originalVa = 0x65aea8L; originalSize = 232;
            bodySha = "0b7e289d57ad0368923c5a802869b755b47eb70e43ff290fcd1096388ca46439";
            symbol = "x264_8_frame_init_lowres_core_neon";
            fragmentVa = 0x65af24L; fragmentEndVa = 0x65af8cL;
        } else throw new IllegalArgumentException("index outside TASK_181");
        if (!"libffmpeg.so".equals(currentProgram.getName()))
            throw new IllegalStateException("wrong Ghidra program");
        long base = currentProgram.getImageBase().getOffset();
        Address original = toAddr(base + originalVa);
        Address fragment = toAddr(base + fragmentVa);
        Address end = toAddr(base + fragmentEndVa);
        byte[] body = new byte[originalSize];
        currentProgram.getMemory().getBytes(original, body);
        String memorySha = sha(body);
        if (!bodySha.equals(memorySha)) throw new IllegalStateException("original SO bytes differ in copied project");
        FunctionManager manager = currentProgram.getFunctionManager();
        Function old = manager.getFunctionAt(original);
        if (old == null || !symbol.equals(old.getName()))
            throw new IllegalStateException("historical analyzed function absent/mismatched");
        List<String> originalInstructions = new ArrayList<>();
        InstructionIterator all = currentProgram.getListing().getInstructions(original, true);
        while (all.hasNext()) {
            Instruction instruction = all.next();
            long pc = instruction.getAddress().getOffset();
            if (pc < base + originalVa || pc >= base + originalVa + originalSize) break;
            originalInstructions.add(instruction.getAddress().toString() + ": " + instruction);
        }
        if (originalInstructions.size() != originalSize / 4)
            throw new IllegalStateException("original instruction coverage mismatch");
        int fragmentSize = (int)(fragmentEndVa - fragmentVa + 4);
        byte[] fragmentBytes = new byte[fragmentSize];
        currentProgram.getMemory().getBytes(fragment, fragmentBytes);
        String fragmentSha = sha(fragmentBytes);
        List<String> fragmentInstructions = new ArrayList<>();
        List<String> fragmentPcode = new ArrayList<>();
        InstructionIterator it = currentProgram.getListing().getInstructions(fragment, true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            long pc = ins.getAddress().getOffset();
            if (pc > base + fragmentEndVa) break;
            fragmentInstructions.add(ins.getAddress().toString() + ": " + ins);
            for (PcodeOp op : ins.getPcode())
                fragmentPcode.add(ins.getAddress().toString() + ": " + op);
        }
        if (fragmentInstructions.size() != fragmentSize / 4)
            throw new IllegalStateException("fragment instruction coverage mismatch");
        if (!manager.removeFunction(original))
            throw new IllegalStateException("cannot isolate function metadata in copied project");
        Listing listing = currentProgram.getListing();
        Function isolated = listing.createFunction("TASK_181_fragment_" + index, fragment,
            new AddressSet(fragment, end), SourceType.USER_DEFINED);
        if (isolated == null) throw new IllegalStateException("cannot create isolated fragment");
        DecompInterface d = new DecompInterface();
        d.setOptions(new DecompileOptions());
        d.toggleCCode(true);
        d.toggleSyntaxTree(true);
        if (!d.setSimplificationStyle("decompile") || !d.openProgram(currentProgram))
            throw new IllegalStateException("normal decompiler mode unavailable");
        long started = System.nanoTime();
        DecompileResults result = d.decompileFunction(isolated, 180, monitor);
        double duration = (System.nanoTime() - started) / 1.0e9;
        boolean completed = result != null && result.decompileCompleted();
        String c = result != null && result.getDecompiledFunction() != null ? result.getDecompiledFunction().getC() : "";
        String error = result != null ? result.getErrorMessage() : "null DecompileResults";
        d.dispose();
        StringBuilder j = new StringBuilder("{\n");
        field(j, "schema_version", "2.1.2");
        field(j, "task_id", "TASK_181");
        j.append("  \"revision\": 1,\n  \"target_index\": ").append(index).append(",\n");
        field(j, "program_name", currentProgram.getName());
        field(j, "symbol", symbol);
        field(j, "original_elf_va", "0x" + Long.toHexString(originalVa));
        field(j, "original_body_sha256", bodySha);
        field(j, "copied_memory_body_sha256", memorySha);
        j.append("  \"original_instruction_count\": ").append(originalInstructions.size()).append(",\n");
        field(j, "fragment_elf_va", "0x" + Long.toHexString(fragmentVa));
        field(j, "fragment_end_elf_va", "0x" + Long.toHexString(fragmentEndVa));
        field(j, "fragment_sha256", fragmentSha);
        j.append("  \"fragment_size_bytes\": ").append(fragmentSize).append(",\n");
        j.append("  \"fragment_instruction_count\": ").append(fragmentInstructions.size()).append(",\n");
        field(j, "decompile_style", "decompile");
        j.append("  \"decompile_elapsed_seconds\": ").append(duration).append(",\n");
        j.append("  \"decompile_completed\": ").append(completed).append(",\n");
        j.append("  \"whole_original_function_decompiled\": false,\n");
        field(j, "error", error);
        field(j, "fragment_c_like", c);
        lines(j, "fragment_instructions", fragmentInstructions);
        lines(j, "fragment_raw_pcode", fragmentPcode);
        j.append("  \"generated_at\": \"").append(Instant.now()).append("\"\n}\n");
        Path output = Paths.get(args[1]);
        Files.createDirectories(output.getParent());
        Files.write(output, j.toString().getBytes(StandardCharsets.UTF_8));
        println("[TASK_181] index=" + index + " original=" + memorySha +
            " fragment=" + fragmentSha + " completed=" + completed +
            " c_like=" + !c.trim().isEmpty() + " duration=" + duration);
    }
}
