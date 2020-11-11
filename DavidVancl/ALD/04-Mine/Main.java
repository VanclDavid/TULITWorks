package com.mine;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static final Scanner scanner = new Scanner(System.in);

    public static class Item{
        private char type;

        public Item (char type) {
            this.type = type;
        }

        public boolean isBomb(){
            return this.type == '*';
        }

        public void setType(char type){
            this.type = type;
        }
    }

    public static void fillDeclaredArray(int rowCount, int columnCount){
        gameDesk = new Item[rowCount][columnCount];
        assignment = new Item[rowCount][columnCount];

        for(int i = 0; i < rowCount; i++){
            for(int j = 0; j < columnCount; j++){
                gameDesk[i][j] = new Item('?');
                assignment[i][j] = new Item('?');
            }
        }
    }

    public static void printArray(Item[][] array){
        for(int i = 0; i < array.length; i++){
            for(int j = 0; j < array[0].length; j++){
                System.out.print(array[i][j].type + " ");
            }
            System.out.println();
        }
    }

    public static Item[][] gameDesk;
    public static Item[][] assignment;
    public static ArrayList<Item> used = new ArrayList<>();

    public static int revealItem(int actX, int actY){
        if(actX < 0 || actX >= gameDesk.length || actY < 0 || actY >= gameDesk[0].length ||
                gameDesk[actX][actY].isBomb() || used.contains(gameDesk[actX][actY])) return 1;

        if(
                ((actY + 1) < gameDesk[0].length && gameDesk[actX][actY + 1].isBomb()) ||
                ((actY - 1) >= 0 && gameDesk[actX][actY - 1].isBomb()) ||
                ((actX + 1) < gameDesk.length && gameDesk[actX + 1][actY].isBomb()) ||
                ((actX - 1) >= 0 && gameDesk[actX - 1][actY].isBomb()) ||
                ((actY - 1) >= 0 && (actX - 1) >= 0 && gameDesk[actX - 1][actY - 1].isBomb()) ||
                ((actX + 1) < gameDesk.length && (actY - 1) >= 0 && gameDesk[actX + 1][actY - 1].isBomb()) ||
                ((actY + 1) < gameDesk[0].length && (actX + 1) < gameDesk.length && gameDesk[actX + 1][actY + 1].isBomb()) ||
                ((actX - 1) >= 0 && (actY + 1) < gameDesk[0].length && gameDesk[actX - 1][actY + 1].isBomb())
        ) return 1;

        gameDesk[actX][actY].setType('.');
        used.add(gameDesk[actX][actY]);

        revealItem(actX,actY + 1); //bottom
        revealItem(actX,actY - 1); //up
        revealItem(actX + 1,actY); //right
        revealItem(actX - 1,actY); //left
        revealItem(actX - 1,actY - 1); //up-left
        revealItem(actX + 1,actY - 1); //up-right
        revealItem(actX + 1,actY + 1); //bottom-right
        revealItem(actX - 1,actY + 1); //bottom-lef

        return 0;
    }

    public static void main(String[] args) {
        int rowCount = scanner.nextInt(), columnCount = scanner.nextInt();
        fillDeclaredArray(rowCount,columnCount);

        int mineCount = scanner.nextInt();
        for(int i = 0; i < mineCount; i++){
            int x = scanner.nextInt(), y = scanner.nextInt();
            gameDesk[x][y] = new Item('*');
            assignment[x][y] = new Item('*');
        }

        int clickCount = scanner.nextInt();
        for(int i = 0; i < clickCount; i++){
            int x = scanner.nextInt(), y = scanner.nextInt();
            revealItem(x,y);
            assignment[x][y] = new Item('o');
        }

        for(int i = 0; i < rowCount; i++){
            for(int j = 0; j < columnCount; j++){
                if(gameDesk[i][j].type == '*'){
                    gameDesk[i][j].setType('?');
                }
            }
        }

        printArray(assignment);
        System.out.println();
        printArray(gameDesk);
    }
}