// TASK_183 targeted transient metadata for candidate #10 only; rollback after extraction.
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

public class RepairBoundary183 extends GhidraScript {
    private static final long VA = 0xe724L;
    private static final int SIZE = 80;
    private static final String SHA = "f629ed5510c08e0a84ba8de78c755467f3a12e61f3de620dae26771549583088";

    private static String q(String value) {
        if (value == null) value = "";
        StringBuilder out = new StringBuilder("\"");
        for (int i = 0; i < value.length(); i++) {
            char ch = value.charAt(i);
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
        return out.append('"').toString();
    }

    private static String hash(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder out = new StringBuilder();
        for (byte b : digest) out.append(String.format("%02x", b & 0xff));
        return out.toString();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1 || !"libMTGif.so".equals(currentProgram.getName()))
            throw new IllegalArgumentException("pinned MTGif program and one output path required");
        Path output = Paths.get(args[0]);
        long base = currentProgram.getImageBase().getOffset();
        Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + VA);
        Address end = start.add(SIZE - 1);
        byte[] before = new byte[SIZE];
        if (currentProgram.getMemory().getBytes(start, before) != SIZE || !SHA.equals(hash(before)))
            throw new IllegalStateException("copied project original FDE body hash differs");
        FunctionManager manager = currentProgram.getFunctionManager();
        Function original = manager.getFunctionAt(start);
        if (original == null) throw new IllegalStateException("expected pre-existing Ghidra function absent");
        String oldBodyEnd = "0x" + Long.toHexString(original.getBody().getMaxAddress().getOffset());
        int originalSlots = 0;
        for (int off = 0; off < SIZE; off += 4)
            if (currentProgram.getListing().getInstructionAt(start.add(off)) != null) originalSlots++;
        if (originalSlots != 15 || original.getBody().getMaxAddress().getOffset() != base + VA + 59)
            throw new IllegalStateException("pre-existing 15-of-20 boundary gap changed");
        int transaction = currentProgram.startTransaction("TASK183 transient full FDE #10 metadata");
        boolean removed = false;
        boolean created = false;
        int decoded = 0;
        int pcodeOps = 0;
        boolean cLike = false;
        String cText = "";
        String error = "";
        long elapsed = 0;
        List<String> instructions = new ArrayList<>();
        try {
            removed = manager.removeFunction(start);
            if (!removed) throw new IllegalStateException("cannot remove truncated function in temporary copy");
            for (int off = 0; off < SIZE; off += 4) {
                Address pc = start.add(off);
                if (currentProgram.getListing().getInstructionAt(pc) == null) disassemble(pc);
            }
            for (int off = 0; off < SIZE; off += 4) {
                Address pc = start.add(off);
                Instruction ins = currentProgram.getListing().getInstructionAt(pc);
                if (ins == null || ins.getLength() != 4) {
                    instructions.add("    {\"database_va\": " + q("0x" + Long.toHexString(pc.getOffset())) +
                                     ", \"missing_instruction\": true}");
                    continue;
                }
                decoded++;
                List<String> ops = new ArrayList<>();
                for (PcodeOp op : ins.getPcode()) {
                    ops.add(q(op.toString()));
                    pcodeOps++;
                }
                instructions.add("    {\"database_va\": " + q("0x" + Long.toHexString(pc.getOffset())) +
                                 ", \"assembly\": " + q(ins.toString()) +
                                 ", \"pcode_ops\": [" + String.join(", ", ops) + "]}");
            }
            if (decoded == 20) {
                Function full = manager.createFunction("task183_full_fde_candidate_10", start,
                                                       new AddressSet(start, end), SourceType.USER_DEFINED);
                created = full != null;
                if (created) {
                    DecompInterface decomp = new DecompInterface();
                    try {
                        decomp.setOptions(new DecompileOptions());
                        decomp.toggleCCode(true);
                        decomp.setSimplificationStyle("decompile");
                        if (!decomp.openProgram(currentProgram)) throw new IllegalStateException("decompiler open failed");
                        long began = System.nanoTime();
                        DecompileResults result = decomp.decompileFunction(full, 10, monitor);
                        elapsed = (System.nanoTime() - began) / 1000000;
                        if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                            cText = result.getDecompiledFunction().getC();
                            cLike = cText != null && !cText.trim().isEmpty();
                        } else error = result == null ? "null DecompileResults" : result.getErrorMessage();
                    } finally {
                        decomp.dispose();
                    }
                } else error = "temporary full-FDE function creation returned null";
            } else error = "Ghidra could not decode all 20 source instructions";
        } catch (Exception failure) {
            error = failure.getClass().getSimpleName() + ": " + failure.getMessage();
        } finally {
            currentProgram.endTransaction(transaction, false);
        }
        byte[] after = new byte[SIZE];
        currentProgram.getMemory().getBytes(start, after);
        if (!SHA.equals(hash(after))) throw new IllegalStateException("source body changed after rollback");
        String json = "{\n  \"task_id\": \"TASK_183\", \"revision\": 1, \"index\": 10,\n" +
            "  \"generated_at\": " + q(Instant.now().toString()) + ",\n" +
            "  \"elf_va\": \"0xe724\", \"size_bytes\": 80,\n" +
            "  \"memory_sha256\": " + q(SHA) + ", \"memory_unchanged_after_rollback\": true,\n" +
            "  \"old_function_body_end\": " + q(oldBodyEnd) +
            ", \"old_analyzed_instruction_slots\": " + originalSlots + ",\n" +
            "  \"temporary_old_function_removed\": " + removed +
            ", \"temporary_full_fde_function_created\": " + created + ",\n" +
            "  \"full_fde_instruction_count\": " + decoded +
            ", \"full_fde_pcode_ops\": " + pcodeOps + ",\n" +
            "  \"decompile_elapsed_ms\": " + elapsed +
            ", \"c_like_nonempty\": " + cLike +
            ", \"error\": " + q(error) +
            ", \"c_like_text\": " + q(cText) + ",\n" +
            "  \"instruction_pcode\": [\n" + String.join(",\n", instructions) + "\n  ]\n}\n";
        Files.createDirectories(output.getParent());
        Files.write(output, json.getBytes(StandardCharsets.UTF_8));
        println("[TASK_183_CORRECTION] candidate=10 full_FDE_instructions=" + decoded +
                "/20 pcode=" + pcodeOps + " c=" + cLike + " elapsed_ms=" + elapsed +
                " error=" + error);
    }
}
