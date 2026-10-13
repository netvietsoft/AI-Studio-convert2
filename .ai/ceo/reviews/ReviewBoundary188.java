// CEO independent, read-only replay of TASK_188 original Ghidra body boundaries.
// @category Extraction

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class ReviewBoundary188 extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2 || !"libMTLReportTool.so".equals(currentProgram.getName()))
            throw new IllegalArgumentException("pinned MTLReportTool program, target TSV and output NDJSON required");
        Path input = Paths.get(args[0]);
        Path output = Paths.get(args[1]);
        List<String> lines = Files.readAllLines(input, StandardCharsets.US_ASCII);
        if (lines.size() != 117) throw new IllegalArgumentException("expected 117 candidate rows");
        long base = currentProgram.getImageBase().getOffset();
        FunctionManager manager = currentProgram.getFunctionManager();
        int exact = 0;
        Files.createDirectories(output.getParent());
        try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
            for (String line : lines) {
                String[] cols = line.split("\\t");
                if (cols.length != 4) throw new IllegalArgumentException("invalid pinned candidate row");
                int index = Integer.parseInt(cols[0]);
                long elfVa = Long.decode(cols[1]);
                int size = Integer.parseInt(cols[2]);
                if (size < 4 || size > 4096 || size % 4 != 0 || elfVa % 4 != 0)
                    throw new IllegalArgumentException("invalid pinned FDE range");
                Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + elfVa);
                Function function = manager.getFunctionAt(start);
                StringBuilder bits = new StringBuilder(size);
                int other = 0;
                for (int offset = 0; offset < size; offset++) {
                    Address address = start.add(offset);
                    bits.append(function != null && function.getBody().contains(address) ? '1' : '0');
                    Function owner = manager.getFunctionContaining(address);
                    if (owner != null && !owner.getEntryPoint().equals(start)) other++;
                }
                int memberCount = (int) bits.chars().filter(c -> c == '1').count();
                if (memberCount == size) exact++;
                long bodyCount = function == null ? -1 : function.getBody().getNumAddresses();
                writer.write("{\"index\":" + index + ",\"elf_va\":\"0x" + Long.toHexString(elfVa)
                    + "\",\"size_bytes\":" + size + ",\"function_at_start\":" + (function != null)
                    + ",\"fde_byte_membership_bits\":\"" + bits + "\",\"fde_byte_membership_count\":"
                    + memberCount + ",\"function_body_total_address_count\":" + bodyCount
                    + ",\"other_function_byte_count\":" + other + "}");
                writer.newLine();
            }
        }
        println("[CEO_TASK188_BOUNDARY] rows=" + lines.size() + " original_exact=" + exact);
    }
}
