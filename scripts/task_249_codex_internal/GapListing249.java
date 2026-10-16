import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

public class GapListing249 extends GhidraScript {
  static final long START = 0xaf040L;
  static final long END = 0xaf688L;
  static String q(String s) {
    if (s == null) s = "";
    return "\"" + s.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n").replace("\r", "\\r") + "\"";
  }
  public void run() throws Exception {
    String[] a = getScriptArgs();
    if (a.length != 1 || !"libPVGCodec.so".equals(currentProgram.getName()))
      throw new IllegalArgumentException("expected pinned libPVGCodec.so and one output path");
    long base = currentProgram.getImageBase().getOffset();
    Address lo = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + START);
    Address hi = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + END - 1);
    Address cLo = lo.subtract(16), cHi = hi.add(16);
    StringBuilder sb = new StringBuilder();
    sb.append("{\n  \"program\": ").append(q(currentProgram.getName())).append(",\n")
      .append("  \"generated_at\": ").append(q(Instant.now().toString())).append(",\n")
      .append("  \"image_base\": ").append(q("0x" + Long.toHexString(base))).append(",\n")
      .append("  \"gap\": [\"0xaf040\",\"0xaf688\"],\n  \"word_membership\": [\n");
    int bodyWords=0, instWords=0, bodyAndInst=0;
    for (long va=START; va<END; va+=4) {
      Address x = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + va);
      Function f = currentProgram.getFunctionManager().getFunctionContaining(x);
      Instruction ins = currentProgram.getListing().getInstructionAt(x);
      boolean inBody = f != null && f.getBody().contains(x);
      if (inBody) bodyWords++;
      if (ins != null) instWords++;
      if (inBody && ins != null) bodyAndInst++;
      if (va != START) sb.append(",\n");
      sb.append("    {\"va\": ").append(q("0x"+Long.toHexString(va)))
        .append(", \"function_body_member\": ").append(inBody)
        .append(", \"function_entry\": ").append(q(f == null ? "" : "0x"+Long.toHexString(f.getEntryPoint().getOffset()-base)))
        .append(", \"function_name\": ").append(q(f == null ? "" : f.getName()))
        .append(", \"instruction_defined\": ").append(ins != null)
        .append(", \"mnemonic\": ").append(q(ins == null ? "" : ins.getMnemonicString()))
        .append(", \"instruction\": ").append(q(ins == null ? "" : ins.toString()))
        .append(", \"bytes\": ").append(q(ins == null ? "" : ins.getBytes().length + " bytes"))
        .append("}");
    }
    sb.append("\n  ],\n  \"context_instructions\": [\n");
    AddressSet context = new AddressSet(cLo,cHi);
    Instruction it = currentProgram.getListing().getInstructionAt(cLo);
    // Start at the first instruction at/after context start if there is no exact instruction.
    if (it == null) it = currentProgram.getListing().getInstructionAfter(cLo);
    boolean first=true;
    while (it != null && it.getAddress().compareTo(cHi) <= 0) {
      Address x=it.getAddress();
      long va=x.getOffset()-base;
      Function f=currentProgram.getFunctionManager().getFunctionContaining(x);
      if (!first) sb.append(",\n"); first=false;
      byte[] bytes=it.getBytes(); StringBuilder hx=new StringBuilder();
      for(byte b:bytes) hx.append(String.format("%02x", b & 255));
      sb.append("    {\"va\": ").append(q("0x"+Long.toHexString(va)))
        .append(", \"bytes\": ").append(q(hx.toString()))
        .append(", \"instruction\": ").append(q(it.toString()))
        .append(", \"function_entry\": ").append(q(f==null?"":"0x"+Long.toHexString(f.getEntryPoint().getOffset()-base)))
        .append(", \"function_name\": ").append(q(f==null?"":f.getName()))
        .append(", \"function_body_member\": ").append(f!=null && f.getBody().contains(x)).append("}");
      it=currentProgram.getListing().getInstructionAfter(x);
    }
    sb.append("\n  ],\n  \"external_flow_references\": [\n");
    boolean firstRef=true; int externalFlowRefs=0;
    for (long va=START; va<END; va+=4) {
      Address target=currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base+va);
      ReferenceIterator refs=currentProgram.getReferenceManager().getReferencesTo(target);
      while (refs.hasNext()) {
        Reference ref=refs.next();
        Address from=ref.getFromAddress();
        if (from.compareTo(lo)>=0 && from.compareTo(hi)<=0) continue;
        if (!ref.getReferenceType().isFlow()) continue;
        Function sourceFn=currentProgram.getFunctionManager().getFunctionContaining(from);
        Instruction sourceIns=currentProgram.getListing().getInstructionAt(from);
        if (!firstRef) sb.append(",\n"); firstRef=false; externalFlowRefs++;
        sb.append("    {\"from_va\": ").append(q("0x"+Long.toHexString(from.getOffset()-base)))
          .append(", \"to_va\": ").append(q("0x"+Long.toHexString(va)))
          .append(", \"reference_type\": ").append(q(ref.getReferenceType().getName()))
          .append(", \"source_instruction\": ").append(q(sourceIns==null?"":sourceIns.toString()))
          .append(", \"source_function\": ").append(q(sourceFn==null?"":sourceFn.getName())).append("}");
      }
    }
    sb.append("\n  ],\n  \"summary\": {\"gap_words\": 402, \"external_flow_references\": ").append(externalFlowRefs)
      .append(", \"function_body_member_words\": ").append(bodyWords)
      .append(", \"instruction_defined_words\": ").append(instWords)
      .append(", \"both\": ").append(bodyAndInst).append("}\n}\n");
    Path p=Paths.get(a[0]); Files.write(p, sb.toString().getBytes(StandardCharsets.UTF_8));
    println("[TASK_249] gap words=402 body="+bodyWords+" instructions="+instWords+" both="+bodyAndInst);
  }
}


