package com.company;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        int cost[] = new int[]{6,2,5,5,4,5,6,3,7,6};
        BigInteger dp[] = new BigInteger[2005];
        BigInteger Ti = BigInteger.ZERO;
        n=scanner.nextInt();
        Arrays.fill(dp,BigInteger.ZERO);
        dp[0]=BigInteger.ONE;
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
        System.out.println(Ti);
		scanner.close();
    }
}
