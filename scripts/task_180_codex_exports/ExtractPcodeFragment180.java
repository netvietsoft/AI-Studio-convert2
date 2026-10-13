// TASK_180: source-hash-guarded original p-code and one synthetic scalar fragment.
// The synthetic function is transient and the transaction is rolled back.
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

public class ExtractPcodeFragment180 extends GhidraScript {

    private static String quote(String value) {
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

    private static String sha256(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder result = new StringBuilder();
        for (byte value : digest) result.append(String.format("%02x", value & 0xff));
        return result.toString();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 7) throw new IllegalArgumentException("index, ELF VA, size, body SHA, fragment start/end, JSON path required");
        if (!"libMTGif.so".equals(currentProgram.getName())) throw new IllegalStateException("wrong analyzed program");
        int index = Integer.parseInt(args[0]);
        long elfVa = Long.decode(args[1]);
        int size = Integer.parseInt(args[2]);
        String expectedSha = args[3];
        long fragmentElfStart = Long.decode(args[4]);
        long fragmentElfEnd = Long.decode(args[5]);
        Path output = Paths.get(args[6]);
        if ((index != 1 && index != 2) || size < 1 || size > 4096 ||
            expectedSha.length() != 64 || fragmentElfStart < elfVa ||
            fragmentElfEnd >= elfVa + size || fragmentElfEnd < fragmentElfStart) {
            throw new IllegalArgumentException("outside two pinned original/fragment bounds");
        }
        long base = currentProgram.getImageBase().getOffset();
        Address originalAddress = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + elfVa);
        Address fragmentAddress = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + fragmentElfStart);
        Address fragmentEnd = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + fragmentElfEnd);
        byte[] body = new byte[size];
        int read = currentProgram.getMemory().getBytes(originalAddress, body);
        String memorySha = sha256(body);
        if (read != size || !memorySha.equalsIgnoreCase(expectedSha)) {
            throw new IllegalStateException("original PT_LOAD and copied Ghidra memory differ");
        }
        Function original = getFunctionAt(originalAddress);
        if (original == null) throw new IllegalStateException("original analyzed function absent");
        List<String> rows = new ArrayList<>();
        int instructions = 0;
        int pcodeOps = 0;
        InstructionIterator iterator = currentProgram.getListing().getInstructions(originalAddress, true);
        while (iterator.hasNext()) {
            Instruction instruction = iterator.next();
            long pc = instruction.getAddress().getOffset();
            if (pc < base + elfVa || pc >= base + elfVa + size) break;
            List<String> ops = new ArrayList<>();
            for (PcodeOp op : instruction.getPcode()) {
                ops.add(quote(op.toString()));
                pcodeOps++;
            }
            rows.add("    {\"database_va\": \"0x" + Long.toHexString(pc) + "\", \"assembly\": " +
                     quote(instruction.toString()) + ", \"pcode_ops\": [" +
                     String.join(", ", ops) + "]}");
            instructions++;
        }
        if (instructions == 0 || pcodeOps == 0) throw new IllegalStateException("original p-code absent");

        boolean syntheticCreated = false;
        boolean fragmentC = false;
        String fragmentText = "";
        String fragmentError = "";
        long elapsedMillis = 0;
        int tx = currentProgram.startTransaction("TASK180 transient scalar fragment");
        try {
            FunctionManager manager = currentProgram.getFunctionManager();
            if (!manager.removeFunction(originalAddress)) throw new IllegalStateException("cannot isolate original analyzed function");
            AddressSet region = new AddressSet(fragmentAddress, fragmentEnd);
            Function fragment = manager.createFunction("task180_scalar_fragment_" + index,
                                                      fragmentAddress, region, SourceType.USER_DEFINED);
            if (fragment == null) throw new IllegalStateException("synthetic scalar region function not created");
            syntheticCreated = true;
            DecompInterface decomp = new DecompInterface();
            try {
                decomp.setOptions(new DecompileOptions());
                decomp.toggleCCode(true);
                decomp.setSimplificationStyle("decompile");
                if (!decomp.openProgram(currentProgram)) throw new IllegalStateException("fragment decompiler open failed");
                long began = System.nanoTime();
                DecompileResults result = decomp.decompileFunction(fragment, 15, monitor);
                elapsedMillis = (System.nanoTime() - began) / 1000000;
                if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                    fragmentText = result.getDecompiledFunction().getC();
                    fragmentC = fragmentText != null && !fragmentText.trim().isEmpty();
                } else {
                    fragmentError = result == null ? "null DecompileResults" : result.getErrorMessage();
                }
            } finally {
                decomp.dispose();
            }
        } catch (Exception failure) {
            fragmentError = failure.getClass().getSimpleName() + ": " + failure.getMessage();
        } finally {
            currentProgram.endTransaction(tx, false);
        }

        byte[] after = new byte[size];
        currentProgram.getMemory().getBytes(originalAddress, after);
        if (!sha256(after).equalsIgnoreCase(expectedSha)) throw new IllegalStateException("source-aligned memory changed after rollback");
        String json = "{\n  \"schema_version\": \"2.1.2\",\n" +
            "  \"task_id\": \"TASK_180\", \"revision\": 1,\n" +
            "  \"program_name\": \"libMTGif.so\",\n" +
            "  \"generated_at\": " + quote(Instant.now().toString()) + ",\n" +
            "  \"target_index\": " + index + ", \"elf_va\": \"0x" + Long.toHexString(elfVa) + "\",\n" +
            "  \"database_va\": \"0x" + Long.toHexString(base + elfVa) + "\",\n" +
            "  \"size_bytes\": " + size + ",\n" +
            "  \"ghidra_original_memory_sha256\": \"" + memorySha + "\",\n" +
            "  \"memory_unchanged_after_rollback\": true,\n" +
            "  \"original_instruction_count\": " + instructions + ",\n" +
            "  \"original_pcode_operation_count\": " + pcodeOps + ",\n" +
            "  \"synthetic_fragment\": {\"elf_start\": \"0x" + Long.toHexString(fragmentElfStart) +
            "\", \"elf_end_inclusive\": \"0x" + Long.toHexString(fragmentElfEnd) +
            "\", \"function_created\": " + syntheticCreated +
            ", \"decompile_success\": " + fragmentC +
            ", \"elapsed_ms\": " + elapsedMillis +
            ", \"error\": " + quote(fragmentError) +
            ", \"c_like_fragment_only\": " + quote(fragmentText) + "},\n" +
            "  \"original_instruction_pcode\": [\n" + String.join(",\n", rows) + "\n  ]\n}\n";
        Files.createDirectories(output.getParent());
        Files.write(output, json.getBytes(StandardCharsets.UTF_8));
        println("[TASK_180] target=" + index + " original_instructions=" + instructions +
                " pcode_ops=" + pcodeOps + " fragment_c=" + fragmentC +
                " fragment_elapsed_ms=" + elapsedMillis + " saved=" + output);
    }
}
