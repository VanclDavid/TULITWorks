package com.dbs;

import java.util.Scanner;

public class Main {
    private final static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        DBSConnector dbsConnector = new DBSConnector(scanner);
        CustomConnector customConnector = new CustomConnector(scanner);

	    UI.printMenu();
	    int actualAction = 0;
	    while ((actualAction = scanner.nextInt()) != -1){
	        switch (actualAction){
                case 1:
                    dbsConnector.insertInto(UI.loadTableName(scanner));
                    break;
                case 2:
                    dbsConnector.selectFrom(UI.loadTableName(scanner),UI.loadIDs(scanner),UI.loadLimit(scanner));
                    break;
                case 3:
                    UI.printSubMenu();
                    int command;
                    while ((command = scanner.nextInt()) != -1){
                        switch (command){
                            case 1:
                                customConnector.getMedicamentAVGStock();
                                break;
                            case 2:
                                customConnector.getPharmaciesStockMoreThan200();
                                break;
                            case 3:
                                customConnector.getUselessDoctors();
                                break;
                            case 4:
                                customConnector.getDoctorsPeopleCount();
                                break;
                            case 5:
                                customConnector.getPacients();
                                break;
                            case 6:
                                customConnector.getStockPharmacy();
                                break;
                        }
                        UI.printSubMenu();
                    }
                    break;
                case 4:
                    dbsConnector.truncateTable(UI.loadTableName(scanner),UI.loadIDs(scanner));
                    break;
                case 5:
                    dbsConnector.editRow(UI.loadTableName(scanner),UI.loadID(scanner));
                    break;
            }
            UI.printMenu();
        }
    }
}