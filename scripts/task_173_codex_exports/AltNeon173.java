// TASK_173 R1: one alternative normalized decompilation of one original NEON export.
// @category Extraction

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.PcodeOpAST;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class AltNeon173 extends GhidraScript {

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
                    if (ch < 0x20) out.append(String.format("\\u%04x", (int) ch));
                    else out.append(ch);
            }
        }
        return out.toString();
    }

    private static String sha256(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder out = new StringBuilder();
        for (byte value : digest) out.append(String.format("%02x", value & 0xff));
        return out.toString();
    }

    private static void stringField(StringBuilder json, String name, String value, boolean comma) {
        json.append("  \"").append(name).append("\": \"").append(escape(value)).append("\"");
        json.append(comma ? ",\n" : "\n");
    }

    private static void stringList(StringBuilder json, String name, List<String> values, boolean comma) {
        json.append("  \"").append(name).append("\": [");
        for (int i = 0; i < values.size(); i++) {
            if (i != 0) json.append(", ");
            json.append("\"").append(escape(values.get(i))).append("\"");
        }
        json.append(comma ? "],\n" : "]\n");
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("expected one target TSV and output JSON");
        Path targetPath = Paths.get(args[0]);
        Path resultPath = Paths.get(args[1]);
        List<String> lines = Files.readAllLines(targetPath, StandardCharsets.UTF_8);
        if (lines.size() != 1) throw new IllegalArgumentException("exactly one target required");
        String[] fields = lines.get(0).split("\t", 5);
        if (fields.length != 5) throw new IllegalArgumentException("invalid target TSV");
        int index = Integer.parseInt(fields[0]);
        long elfVa = Long.decode(fields[1]);
        int size = Integer.parseInt(fields[2]);
        String expectedSha = fields[3];
        String symbol = fields[4];
        if (size < 1 || size > 65536 || expectedSha.length() != 64 ||
            !(index == 2283 && elfVa == 0x658fe8L || index == 2330 && elfVa == 0x65aea8L)) {
            throw new IllegalArgumentException("target outside TASK_173 scope");
        }
        if (!"libffmpeg.so".equals(currentProgram.getName())) {
            throw new IllegalStateException("wrong analyzed Ghidra program");
        }
        long imageBase = currentProgram.getImageBase().getOffset();
        long databaseVa = imageBase + elfVa;
        Address address = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(databaseVa);
        byte[] body = new byte[size];
        currentProgram.getMemory().getBytes(address, body);
        String actualSha = sha256(body);
        if (!actualSha.equalsIgnoreCase(expectedSha)) {
            throw new IllegalStateException("copied Ghidra memory differs from original PT_LOAD body");
        }
        Function function = getFunctionAt(address);
        if (function == null) throw new IllegalStateException("analyzed function absent at target VA");
        List<String> instructions = new ArrayList<>();
        List<String> rawPcode = new ArrayList<>();
        InstructionIterator iterator = currentProgram.getListing().getInstructions(address, true);
        while (iterator.hasNext()) {
            Instruction instruction = iterator.next();
            long pc = instruction.getAddress().getOffset();
            if (pc < databaseVa || pc >= databaseVa + size) break;
            instructions.add(instruction.getAddress() + ": " + instruction.toString());
            for (PcodeOp op : instruction.getPcode()) {
                rawPcode.add(instruction.getAddress() + ": " + op.toString());
            }
        }
        println("[TASK_173] target=" + index + " source_bytes_match=true instructions=" + instructions.size());

        boolean completed = false;
        String cLike = "";
        String error = "";
        List<String> highPcode = new ArrayList<>();
        long started = System.nanoTime();
        DecompInterface decomp = new DecompInterface();
        try {
            decomp.setOptions(new DecompileOptions());
            if (!decomp.openProgram(currentProgram)) {
                throw new IllegalStateException("decompiler initialization failed: " + decomp.getLastMessage());
            }
            // A distinct style from TASK_170's default C decompilation; exactly one call below.
            decomp.setSimplificationStyle("normalize");
            DecompileResults result = decomp.decompileFunction(function, 180, monitor);
            if (result != null) {
                completed = result.decompileCompleted();
                error = result.getErrorMessage();
                if (result.getDecompiledFunction() != null) {
                    String candidate = result.getDecompiledFunction().getC();
                    if (candidate != null) cLike = candidate;
                }
                HighFunction high = result.getHighFunction();
                if (high != null) {
                    Iterator<PcodeOpAST> ops = high.getPcodeOps();
                    while (ops.hasNext()) {
                        PcodeOpAST op = ops.next();
                        highPcode.add(op.getSeqnum().getTarget() + ": " + op.toString());
                    }
                }
            } else {
                error = "null DecompileResults";
            }
        } catch (Exception failure) {
            error = failure.getClass().getSimpleName() + ": " + failure.getMessage();
        } finally {
            decomp.dispose();
        }
        double elapsedSeconds = (System.nanoTime() - started) / 1000000000.0;
        StringBuilder json = new StringBuilder();
        json.append("{\n  \"task_id\": \"TASK_173\",\n  \"revision\": 1,\n");
        json.append("  \"target_index\": ").append(index).append(",\n");
        stringField(json, "program_name", currentProgram.getName(), true);
        stringField(json, "symbol", symbol, true);
        stringField(json, "elf_va", "0x" + Long.toHexString(elfVa), true);
        stringField(json, "database_va", "0x" + Long.toHexString(databaseVa), true);
        json.append("  \"size_bytes\": ").append(size).append(",\n");
        stringField(json, "expected_source_sha256", expectedSha, true);
        stringField(json, "ghidra_memory_sha256", actualSha, true);
        json.append("  \"source_bytes_match\": true,\n");
        stringField(json, "alternative_style", "normalize", true);
        json.append("  \"decompile_completed\": ").append(completed).append(",\n");
        json.append("  \"alternative_decompile_seconds\": ").append(elapsedSeconds).append(",\n");
        stringField(json, "decompile_error", error, true);
        stringField(json, "c_like", cLike, true);
        stringList(json, "instructions", instructions, true);
        stringList(json, "raw_pcode", rawPcode, true);
        stringList(json, "normalized_high_pcode", highPcode, false);
        json.append("}\n");
        Files.createDirectories(resultPath.getParent());
        Files.write(resultPath, json.toString().getBytes(StandardCharsets.UTF_8));
        println("[TASK_173] wrote result index=" + index + " bytes=" + Files.size(resultPath) +
                " completed=" + completed + " c_like=" + (!cLike.isBlank()));
    }
}
