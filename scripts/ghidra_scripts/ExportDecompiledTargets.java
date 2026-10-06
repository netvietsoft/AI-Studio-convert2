// Ghidra decompiler export script for TASK_061
// @category Analysis
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

public class ExportDecompiledTargets extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = "F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reconstruction/evidence/TASK_061/ghidra_decompiled";
        if (args != null && args.length > 0) {
            outDir = args[0];
        }
        File outFolder = new File(outDir);
        outFolder.mkdirs();

        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        String progName = currentProgram.getName();
        File outFile = new File(outFolder, progName + "_decompiled.txt");
        PrintWriter writer = new PrintWriter(new FileWriter(outFile));

        println("Exporting decompiled functions for " + progName + " to " + outFile.getAbsolutePath());

        FunctionIterator funcs = currentProgram.getFunctionManager().getFunctions(true);
        int count = 0;
        while (funcs.hasNext()) {
            Function f = funcs.next();
            String name = f.getName();
            // Filter targets
            boolean match = false;
            String lower = name.toLowerCase();
            if (lower.contains("hair") || lower.contains("mask") || lower.contains("soft") || 
                lower.contains("blend") || lower.contains("filter") || lower.contains("color") ||
                lower.contains("guided") || lower.contains("segment") || lower.contains("matte") ||
                lower.contains("dye") || lower.contains("clean") || lower.contains("whiten") ||
                lower.contains("lut") || lower.contains("vldp")) {
                match = true;
            }
            if (!match) continue;

            DecompileResults res = decomp.decompileFunction(f, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                String cCode = res.getDecompiledFunction().getC();
                writer.println("================================================================================");
                writer.println("FUNCTION: " + name);
                writer.println("ADDRESS:  0x" + f.getEntryPoint().toString());
                writer.println("SIZE:     " + f.getBody().getNumAddresses() + " bytes");
                writer.println("SIGNATURE: " + f.getPrototypeString(true, true));
                writer.println("XREFS:");
                ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(f.getEntryPoint());
                while (refs.hasNext()) {
                    Reference r = refs.next();
                    writer.println("  from 0x" + r.getFromAddress() + " (" + r.getReferenceType() + ")");
                }
                writer.println("DECOMPILED C BODY:");
                writer.println(cCode);
                writer.println();
                writer.flush();
                count++;
            }
        }
        writer.close();
        decomp.dispose();
        println("Exported " + count + " target functions successfully.");
    }
}
