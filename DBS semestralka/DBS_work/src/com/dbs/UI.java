package com.dbs;

import java.util.ArrayList;
import java.util.Scanner;

public class UI {
    public static void printMenu(){
        System.out.println(
                "1. INSERT VALUE\n" +
                "2. SELECT\n" +
                "3. PRELOADED SELECTS\n" +
                "4. TRUNCATE TABLE\n" +
                "5. EDIT ROW\n" +
                "-1. Exit app\n" +
                "Select operation: "
        );
    }

    public static void printSubMenu(){
        System.out.println(
                "1. SELECT v SELECT\n" +
                "2. SELECT ve FROM\n" +
                "3. SELECT ve WHERE\n" +
                "4. GROUP BY\n" +
                "5. množinovou operaci\n" +
                "6. LEFT JOIN\n" +
                "-1. Leave submenu\n" +
                "Select operation: "
        );
    }

    public static int loadLimit(Scanner scanner){
        System.out.println("Set limit (0 - no limit):");
        return scanner.nextInt();
    }

    public static String loadTableName(Scanner scanner){
        System.out.println("Table name:");
        return scanner.next();
    }

    public static int loadID(Scanner scanner){
        System.out.println("ID:");
        return scanner.nextInt();
    }

    public static ArrayList<Integer> loadIDs(Scanner scanner){
        ArrayList<Integer> ids = new ArrayList<>();
        int acID;
        System.out.println("ID (1): [-1 => stop]");
        while ((acID = scanner.nextInt()) != -1){
            ids.add(acID);
            System.out.println("ID ("+(ids.size() + 1)+"):");
        }
        return ids;
    }
}
