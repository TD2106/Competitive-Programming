import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader( new InputStreamReader(System.in)); // fast input
        StringTokenizer st = new StringTokenizer(bufferedReader.readLine()); // fast input

        BigInteger a = new BigInteger(st.nextToken()); // init
        BigInteger b = new BigInteger(st.nextToken()); // init
        BigInteger result;
        result = a.add(b); // add
        result = a.multiply(b); // mul
        result = a.abs(); // abs
        result = b.divide(a); // result is like b/a (long long)
        result = a.gcd(b);//gcd
        result = a.max(b); // max
        result = a.min(b); // min
        int c = a.compareTo(b); // 0  = , 1 > ,-1 <;
        result = a.mod(new BigInteger("8")); // mod
        result = a.modPow(new BigInteger("100"),new BigInteger("1000000007"));
        result = a.negate(); // -a;
        result = a.nextProbablePrime(); // next possible prime > a;
        result = a.subtract(b); // a-b
        result = a.pow(10);
      //  FileInputStream newIn = new FileInputStream("TEST.INP");
      //  System.setIn(newIn);
      //  PrintStream printStream = new PrintStream("TEST.OUT");
        BigDecimal d = new BigDecimal(0);
        d=d.add(new BigDecimal(0.1));
        System.out.format("%.2f",d.doubleValue());
        d = d.multiply(new BigDecimal(2));
    }
}