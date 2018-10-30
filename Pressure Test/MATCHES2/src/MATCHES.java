import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class MATCHES {

    public static void main(String[] args) {
        File file;
        FileWriter fw;
        FileReader fr;
        BufferedWriter bw;
        BufferedReader br;
        int n;
        int cost[] = new int[]{6,2,5,5,4,5,6,3,7,6};
        BigInteger dp[] = new BigInteger[2005];
        BigInteger Ti = BigInteger.ZERO;
        Arrays.fill(dp,BigInteger.ZERO);
        dp[0]=BigInteger.ONE;
        try {
            file = new File("MATCHES.OUT");
            fr = new FileReader(file);
            br = new BufferedReader(fr);
            n = Integer.parseInt(br.readLine());
            for(int i=0;i<=n;i++){
                for(int j=0;j<10;j++){
                    if(i==0&&j==0) continue;
                    if(i+cost[j]<=n){
                        dp[i+cost[j]]=dp[i+cost[j]].add(dp[i]);
                    }
                }
            }
            for(int i=1;i<=n;i++) Ti=Ti.add(dp[i]);
            if(n>=6) Ti=Ti.add(BigInteger.ONE);
            br.close();
            fr.close();
        }
        catch (Exception e){
            System.out.println("Error");
        }
        //System.out.println(Ti.toString());
        try {
            file = new File("MATCHES.OUT");
            fw = new FileWriter(file);
            bw = new BufferedWriter(fw);
            bw.write(Ti.toString());
            bw.close();
            fw.close();
        }
        catch (Exception e){
            System.out.println("Error");
        }
    }
}
