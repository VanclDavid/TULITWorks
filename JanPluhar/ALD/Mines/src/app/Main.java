package app;

import java.util.Scanner;

public class Main {

    public static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        GameBoard gm=new GameBoard(sc.nextInt(),sc.nextInt());
        int mineCount=sc.nextInt();
        for (int i = 0; i < mineCount; i++) {
            gm.addMine(sc.nextInt(),sc.nextInt());
        }
        int clickCount=sc.nextInt();
        for (int i = 0; i < clickCount; i++) {
            gm.addClick(sc.nextInt(),sc.nextInt());
        }
        gm.printBoard(false);
        gm.discoverClicks();
        gm.printBoard(true);
    }
}

