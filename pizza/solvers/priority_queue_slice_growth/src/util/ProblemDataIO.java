package util;
import java.io.*;
// [experiment patch] the repository does not include this class: read stdin, write stdout
public class ProblemDataIO {
    private final InputData in; private final OutputData out;
    public ProblemDataIO(InputData in, OutputData out, String folder, String file) { this.in = in; this.out = out; }
    public InputData readData() { try (BufferedReader r = new BufferedReader(new InputStreamReader(System.in))) { in.setParams(r.readLine().trim().split(" ")); String l; while ((l = r.readLine()) != null) { if (!l.isEmpty()) in.fillData(l); } } catch (IOException e) { throw new RuntimeException(e); } return in; }
    public void writeData(Object o) { System.out.println(out.getOutput(o)); }
}
