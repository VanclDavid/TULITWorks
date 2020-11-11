package app;

public class GameBoard {
    private char[][] board;
    public GameBoard(int rows, int columns){
        board=new char[rows][columns];
        fillBoard();
    }
    private void fillBoard(){
        for (int i = 0; i < getRows(); i++) {
            for (int j = 0; j < getColumns(); j++) {
                board[i][j]='?';
            }
        }
    }
    public void addMine(int row,int column){
        board[row][column]='*';
    }
    public void addClick(int row,int column){
        board[row][column]='o';
    }
    public void printBoard(boolean hideMines){
        for (int i = 0; i < getRows(); i++) {
            for (int j = 0; j < getColumns(); j++) {
                if (hideMines && board[i][j]=='*'){
                    System.out.print("? ");
                } else {
                    System.out.print(board[i][j]+" ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
    public void discoverClicks(){
        for (int i = 0; i < getRows(); i++) {
            for (int j = 0; j < getColumns(); j++) {
                if (board[i][j]=='o'){
                    recursiveSearch(i,j);
                }
            }
        }
    }
    public int getRows(){
        return board.length;
    }
    public int getColumns(){return board[0].length;}
    private void recursiveSearch(int row, int column){
        if(row >= 0 && row<getRows() && column>=0 && column<getColumns() && board[row][column]!='.') {
            boolean isValid = true;
            if (row - 1 < 0 || board[row - 1][column] != '*') {
            } else {
                isValid = false;
            }
            if (row - 1 < 0 || column - 1 < 0 || board[row - 1][column - 1] != '*') {
            } else {
                isValid = false;
            }
            if (row - 1 < 0 || column + 1 >= getColumns() || board[row - 1][column + 1] != '*') {
            } else {
                isValid = false;
            }

            if (column - 1 < 0 || board[row][column - 1] != '*') {
            } else {
                isValid = false;
            }
            if (column + 1 >= getColumns() || board[row][column + 1] != '*') {
            } else {
                isValid = false;
            }

            if (row + 1 >= getRows() || board[row+1][column] != '*') {
            } else {
                isValid = false;
            }
            if (row + 1 >= getRows() || column - 1 < 0 || board[row + 1][column - 1] != '*') {
            } else {
                isValid = false;
            }
            if (row + 1 >= getRows() || column + 1 >= getColumns() || board[row + 1][column + 1] != '*') {
            } else {
                isValid = false;
            }

            if (isValid) {
                board[row][column] = '.';
                recursiveSearch(row - 1, column);
                recursiveSearch(row - 1, column - 1);
                recursiveSearch(row - 1, column + 1);

                recursiveSearch(row, column - 1);
                recursiveSearch(row, column + 1);

                recursiveSearch(row + 1, column);
                recursiveSearch(row + 1, column - 1);
                recursiveSearch(row + 1, column + 1);
            } else {
                board[row][column] = '?';
            }

        }
    }

}
