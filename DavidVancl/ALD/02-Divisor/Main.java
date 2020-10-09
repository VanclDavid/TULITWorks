package com.divisor;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scanner.nextInt();
	    for(int i = 1; i <= n; i++){
            System.out.print(i + ": ");
            ArrayList<Integer> divisors = getDivisor(i);
            for (int j = divisors.size() - 1; j >= 0;j--) {
                if(j == 0){
                    System.out.print(divisors.get(j));
                } else {
                    System.out.print(divisors.get(j) + ", ");
                }
            }
            System.out.println();
        }
    }

    public static ArrayList<Integer> getDivisor(int number){
        ArrayList<Integer> divisors = new ArrayList<Integer>();
        for(int i = number; i > 0;i--){
            if (number % i == 0){
                divisors.add(i);
            }
        }
        return divisors;
    }
}