import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressRangeIterator;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.pcode.PcodeOp;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

/** Research-only, exact FDE-candidate extraction in an owned copy of the analyzed Ghidra project. */
public class ExportInternal196 extends GhidraScript {

    private static final class Target {
        final int index;
        final long va;
        final int size;
        final String sha;

        Target(String line) {
            String[] f = line.split("\t", 4);
            if (f.length != 4) throw new IllegalArgumentException("malformed target TSV");
            index = Integer.parseInt(f[0]);
            va = Long.decode(f[1]);
            size = Integer.parseInt(f[2]);
            sha = f[3].toLowerCase();
            if (index < 1 || size < 4 || size > 262144 || size % 4 != 0 || sha.length() != 64) {
                throw new IllegalArgumentException("invalid target bounds");
            }
        }
    }

    private static String esc(String input) {
        if (input == null) return "";
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            switch (c) {
                case '\\': out.append("\\\\"); break;
                case '"': out.append("\\\""); break;
                case '\n': out.append("\\n"); break;
                case '\r': out.append("\\r"); break;
                case '\t': out.append("\\t"); break;
                default:
                    if (c < 0x20) out.append(String.format("\\u%04x", (int)c));
                    else out.append(c);
            }
        }
        return out.toString();
    }

    private static String sha(byte[] bytes) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(bytes);
        StringBuilder out = new StringBuilder();
        for (byte b : digest) out.append(String.format("%02x", b & 0xff));
        return out.toString();
    }

    private static String word(byte[] raw, int offset) {
        StringBuilder out = new StringBuilder();
        for (int k = 0; k < 4; k++) out.append(String.format("%02x", raw[offset + k] & 0xff));
        return out.toString();
    }

    private String extract(Target t, long imageBase, DecompInterface decomp) {
        long started = System.nanoTime();
        long dbVa = imageBase + t.va;
        String copySha = "";
        String failure = "";
        String cText = "";
        String cHash = "";
        String fName = "";
        String fEntry = "";
        String fMin = "";
        String fMax = "";
        String boundary = "UNDETERMINED";
        long functionBodyAddressCount = 0;
        long fdeMemberBytes = 0;
        long fdeMissingBytes = 0;
        long extraBodyBytes = 0;
        int instructionCount = 0;
        int pcodeInstructionCount = 0;
        int pcodeOpCount = 0;
        boolean createdMetadata = false;
        boolean startWithinOtherFunction = false;
        boolean cLike = false;
        boolean bytesMatch = false;
        List<String> instructions = new ArrayList<>();
        List<String> instructionPcode = new ArrayList<>();
        List<String> calls = new ArrayList<>();
        List<String> missingRanges = new ArrayList<>();
        List<String> bodyRanges = new ArrayList<>();
        List<String> extraRanges = new ArrayList<>();
        String membershipBits = "";
        try {
            Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(dbVa);
            Address end = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(dbVa + t.size - 1);
            byte[] raw = new byte[t.size];
            currentProgram.getMemory().getBytes(start, raw);
            copySha = sha(raw);
            bytesMatch = copySha.equals(t.sha);
            if (!bytesMatch) throw new IllegalStateException("private-copy memory body hash differs from original ELF");

            for (int j = 0; j < t.size; j += 4) {
                Address at = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(dbVa + j);
                Instruction ins = getInstructionAt(at);
                if (ins == null || ins.getLength() != 4) {
                    instructionPcode.add("{\"database_va\":\"" + at + "\",\"word_le\":\"" +
                        word(raw, j) + "\",\"missing_instruction\":true,\"assembly\":\"\",\"pcode_ops\":[]}");
                    continue;
                }
                instructionCount++;
                instructions.add(at + ": " + ins.toString());
                PcodeOp[] pcode = ins.getPcode();
                int ops = pcode.length;
                if (ops > 0) pcodeInstructionCount++;
                pcodeOpCount += ops;
                StringBuilder row = new StringBuilder("{\"database_va\":\"" + at +
                    "\",\"word_le\":\"" + word(raw, j) + "\",\"missing_instruction\":false," +
                    "\"assembly\":\"" + esc(ins.toString()) + "\",\"pcode_ops\":[");
                for (int k = 0; k < pcode.length; k++) {
                    if (k > 0) row.append(',');
                    row.append('"').append(esc(pcode[k].toString())).append('"');
                }
                row.append("]}");
                instructionPcode.add(row.toString());
                if (ins.getFlowType().isCall()) {
                    Address[] flows = ins.getFlows();
                    if (flows.length > 0) {
                        Function callee = getFunctionAt(flows[0]);
                        calls.add(at + " -> " + flows[0] + (callee == null ? "" : " [" + callee.getName() + "]"));
                    } else calls.add(at + " -> INDIRECT");
                }
            }

            Function function = getFunctionAt(start);
            if (function == null) {
                Function containing = getFunctionContaining(start);
                if (containing != null) {
                    startWithinOtherFunction = true;
                    function = containing;
                    fName = containing.getName();
                    fEntry = containing.getEntryPoint().toString();
                } else {
                    boundary = "GHIDRA_FUNCTION_ABSENT";
                    failure = "No existing function at FDE start; metadata of other functions was preserved";
                }
            }
            if (function != null) {
                fName = function.getName();
                fEntry = function.getEntryPoint().toString();
                AddressSetView body = function.getBody();
                fMin = body.getMinAddress().toString();
                fMax = body.getMaxAddress().toString();
                functionBodyAddressCount = body.getNumAddresses();
                boolean[] members = new boolean[t.size];
                StringBuilder bits = new StringBuilder(t.size);
                int missingStart = -1;
                int lastMember = -1;
                for (int j = 0; j < t.size; j++) {
                    Address at = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(dbVa + j);
                    boolean member = body.contains(at);
                    members[j] = member;
                    bits.append(member ? '1' : '0');
                    if (member) {
                        fdeMemberBytes++;
                        lastMember = j;
                        if (missingStart >= 0) {
                            missingRanges.add("0x" + Long.toHexString(t.va + missingStart) +
                                "..0x" + Long.toHexString(t.va + j - 1));
                            missingStart = -1;
                        }
                    } else if (missingStart < 0) {
                        missingStart = j;
                    }
                }
                membershipBits = bits.toString();
                long fdeLast = t.va + t.size - 1;
                AddressRangeIterator ranges = body.getAddressRanges();
                while (ranges.hasNext()) {
                    AddressRange range = ranges.next();
                    long first = range.getMinAddress().getOffset() - imageBase;
                    long last = range.getMaxAddress().getOffset() - imageBase;
                    bodyRanges.add("0x" + Long.toHexString(first) + "..0x" + Long.toHexString(last));
                    if (first < t.va) extraRanges.add("0x" + Long.toHexString(first) +
                        "..0x" + Long.toHexString(Math.min(last, t.va - 1)));
                    if (last > fdeLast) extraRanges.add("0x" + Long.toHexString(Math.max(first, fdeLast + 1)) +
                        "..0x" + Long.toHexString(last));
                }
                if (missingStart >= 0) {
                    missingRanges.add("0x" + Long.toHexString(t.va + missingStart) +
                        "..0x" + Long.toHexString(t.va + t.size - 1));
                }
                fdeMissingBytes = t.size - fdeMemberBytes;
                extraBodyBytes = functionBodyAddressCount - fdeMemberBytes;
                boolean internalGap = false;
                for (int j = 0; j < lastMember; j++) {
                    if (!members[j]) {
                        internalGap = true;
                        break;
                    }
                }
                if (fdeMissingBytes == 0 && extraBodyBytes == 0) {
                    boundary = "GHIDRA_BODY_EQUALS_FDE_RANGE";
                } else if (fdeMissingBytes == 0) {
                    boundary = "GHIDRA_BODY_CONTAINS_FDE_WITH_EXTRA_BYTES";
                } else if (internalGap) {
                    boundary = "FDE_HAS_INTERNAL_GAPS_IN_GHIDRA_BODY";
                } else if (fdeMemberBytes > 0) {
                    boundary = "GHIDRA_BODY_PREFIX_OF_FDE_RANGE";
                } else {
                    boundary = "GHIDRA_BODY_MISSES_ENTIRE_FDE_RANGE";
                }
                if (startWithinOtherFunction) boundary = "FDE_START_INSIDE_EXISTING_GHIDRA_FUNCTION";
                DecompileResults result = decomp.decompileFunction(function, 10, monitor);
                if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                    cText = result.getDecompiledFunction().getC();
                    if (cText != null && !cText.isEmpty() && cText.length() <= 4000000) {
                        cHash = sha(cText.getBytes(StandardCharsets.UTF_8));
                        cLike = true;
                    } else {
                        cText = "";
                        failure = "C text missing or above 4,000,000 character per-candidate cap";
                    }
                } else failure = result == null ? "null DecompileResults" : result.getErrorMessage();
            } else if (failure.isEmpty()) failure = boundary;
        } catch (Exception e) {
            failure = e.getClass().getSimpleName() + ": " + e.getMessage();
        }
        StringBuilder out = new StringBuilder();
        out.append("{\"task_id\":\"TASK_196\",\"revision\":1,");
        out.append("\"index\":").append(t.index).append(",\"elf_va\":\"0x").append(Long.toHexString(t.va));
        out.append("\",\"database_va\":\"0x").append(Long.toHexString(dbVa));
        out.append("\",\"fde_size_bytes\":").append(t.size);
        out.append(",\"original_body_sha256\":\"").append(t.sha);
        out.append("\",\"copy_memory_body_sha256\":\"").append(copySha);
        out.append("\",\"body_bytes_match\":").append(bytesMatch);
        out.append(",\"instruction_slots\":").append(t.size / 4);
        out.append(",\"instruction_count_observed\":").append(instructionCount);
        out.append(",\"pcode_instruction_count\":").append(pcodeInstructionCount);
        out.append(",\"pcode_op_count\":").append(pcodeOpCount);
        out.append(",\"function_metadata_created_in_owned_copy\":").append(createdMetadata);
        out.append(",\"fde_start_inside_other_ghidra_function\":").append(startWithinOtherFunction);
        out.append(",\"function_name\":\"").append(esc(fName));
        out.append("\",\"function_entry\":\"").append(esc(fEntry));
        out.append("\",\"function_min\":\"").append(esc(fMin));
        out.append("\",\"function_max\":\"").append(esc(fMax));
        out.append("\",\"function_body_address_count\":").append(functionBodyAddressCount);
        out.append(",\"fde_member_bytes\":").append(fdeMemberBytes);
        out.append(",\"fde_missing_bytes\":").append(fdeMissingBytes);
        out.append(",\"extra_body_bytes\":").append(extraBodyBytes);
        out.append(",\"fde_membership_bits\":\"").append(membershipBits).append('"');
        out.append(",\"boundary_classification\":\"").append(esc(boundary));
        out.append("\",\"fde_missing_ranges\":[");
        for (int k = 0; k < missingRanges.size(); k++) {
            if (k > 0) out.append(',');
            out.append('"').append(esc(missingRanges.get(k))).append('"');
        }
        out.append("]");
        out.append(",\"function_body_ranges\":[");
        for (int k = 0; k < bodyRanges.size(); k++) {
            if (k > 0) out.append(',');
            out.append('"').append(esc(bodyRanges.get(k))).append('"');
        }
        out.append("]");
        out.append(",\"extra_body_ranges\":[");
        for (int k = 0; k < extraRanges.size(); k++) {
            if (k > 0) out.append(',');
            out.append('"').append(esc(extraRanges.get(k))).append('"');
        }
        out.append("]");
        out.append(",\"c_like_present\":").append(cLike);
        out.append(",\"c_like_sha256\":\"").append(cHash);
        out.append("\",\"c_like_text\":\"").append(esc(cText));
        out.append("\",\"failure\":\"").append(esc(failure));
        out.append("\",\"elapsed_ms\":").append((System.nanoTime() - started) / 1000000.0);
        out.append(",\"instructions\":[");
        for (int k = 0; k < instructions.size(); k++) {
            if (k > 0) out.append(',');
            out.append('"').append(esc(instructions.get(k))).append('"');
        }
        out.append("],\"calls\":[");
        for (int k = 0; k < calls.size(); k++) {
            if (k > 0) out.append(',');
            out.append('"').append(esc(calls.get(k))).append('"');
        }
        out.append("],\"instruction_pcode\":[");
        for (int k = 0; k < instructionPcode.size(); k++) {
            if (k > 0) out.append(',');
            out.append(instructionPcode.get(k));
        }
        out.append("]}");
        return out.toString();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("expected targets TSV and output NDJSON");
        Path targetPath = Paths.get(args[0]);
        Path outputPath = Paths.get(args[1]);
        List<Target> targets = new ArrayList<>();
        for (String line : Files.readAllLines(targetPath, StandardCharsets.UTF_8)) {
            if (!line.isBlank()) targets.add(new Target(line));
        }
        if (targets.size() < 1 || targets.size() > 32) throw new IllegalStateException("expected 1..32 candidates");
        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        if (!decomp.openProgram(currentProgram)) throw new IllegalStateException("decompiler initialization failed");
        Files.createDirectories(outputPath.getParent());
        long imageBase = currentProgram.getImageBase().getOffset();
        println("[TASK_196] program=" + currentProgram.getName() + " image_base=0x" +
            Long.toHexString(imageBase) + " targets=" + targets.size() + " at=" + Instant.now());
        try (BufferedWriter writer = Files.newBufferedWriter(outputPath, StandardCharsets.UTF_8)) {
            for (Target t : targets) {
                writer.write(extract(t, imageBase, decomp));
                writer.newLine();
                writer.flush();
                println("[TASK_196] processed index=" + t.index + " elf_va=0x" + Long.toHexString(t.va));
            }
        } finally {
            decomp.dispose();
        }
        println("[TASK_196] wrote " + outputPath + " bytes=" + Files.size(outputPath));
    }
}
