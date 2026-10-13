import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

/** CEO read-only independent list of AArch64 FDE words omitted from a function body. */
public class ReviewOmittedWords184 extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("targets and output required");
        List<String> lines = Files.readAllLines(Paths.get(args[0]), StandardCharsets.UTF_8);
        if (lines.size() != 141) throw new IllegalArgumentException("141 targets required");
        Path output = Paths.get(args[1]);
        if (Files.exists(output)) throw new IllegalArgumentException("output already exists");
        long base = currentProgram.getImageBase().getOffset();
        try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
            for (String line : lines) {
                String[] f = line.split("\\t");
                int index = Integer.parseInt(f[0]);
                long va = Long.decode(f[1]);
                int size = Integer.parseInt(f[2]);
                Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + va);
                Function function = getFunctionAt(start);
                AddressSetView body = function == null ? null : function.getBody();
                StringBuilder missing = new StringBuilder("[");
                int n = 0;
                for (int i = 0; i < size; i += 4) {
                    Address wordStart = start.add(i);
                    if (body != null && body.contains(wordStart, wordStart.add(3))) continue;
                    if (n++ > 0) missing.append(',');
                    missing.append("\"0x").append(Long.toHexString(va + i)).append("\"");
                }
                missing.append(']');
                writer.write("{\"index\":" + index + ",\"elf_va\":\"0x" + Long.toHexString(va)
                    + "\",\"fde_size_bytes\":" + size + ",\"missing_instruction_slots\":" + n
                    + ",\"missing_word_vas\":" + missing + "}");
                writer.newLine();
            }
        }
        println("[CEO_OMITTED_WORDS] rows=" + lines.size() + " output=" + output);
    }
}
