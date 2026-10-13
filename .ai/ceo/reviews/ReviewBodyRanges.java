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

/** CEO read-only check that a Ghidra function body includes every pinned FDE byte. */
public class ReviewBodyRanges extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("targets TSV and output NDJSON required");
        Path input = Paths.get(args[0]);
        Path output = Paths.get(args[1]);
        List<String> lines = Files.readAllLines(input, StandardCharsets.UTF_8);
        long base = currentProgram.getImageBase().getOffset();
        int count = 0;
        int exact = 0;
        Files.createDirectories(output.getParent());
        try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
            for (String line : lines) {
                if (line.isBlank()) continue;
                String[] f = line.split("\\t");
                if (f.length < 3) throw new IllegalArgumentException("malformed TSV row");
                int index = Integer.parseInt(f[0]);
                long va = Long.decode(f[1]);
                int size = Integer.parseInt(f[2]);
                Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + va);
                Address end = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + va + size - 1);
                Function function = getFunctionAt(start);
                long bodyBytes = -1;
                boolean contains = false;
                String min = "";
                String max = "";
                String name = "";
                if (function != null) {
                    AddressSetView body = function.getBody();
                    bodyBytes = body.getNumAddresses();
                    contains = body.contains(start, end);
                    min = body.getMinAddress().toString();
                    max = body.getMaxAddress().toString();
                    name = function.getName();
                }
                boolean equal = contains && bodyBytes == size;
                if (equal) exact++;
                writer.write("{\"index\":" + index + ",\"elf_va\":\"0x" + Long.toHexString(va)
                    + "\",\"fde_size_bytes\":" + size + ",\"function_at_start\":" + (function != null)
                    + ",\"body_num_addresses\":" + bodyBytes + ",\"body_contains_fde\":" + contains
                    + ",\"body_equals_fde\":" + equal + ",\"body_min\":\"" + min
                    + "\",\"body_max\":\"" + max + "\",\"function_name\":\"" + name + "\"}");
                writer.newLine();
                count++;
            }
        }
        println("[CEO_BODY_RANGE] rows=" + count + " exact=" + exact + " output=" + output);
    }
}
