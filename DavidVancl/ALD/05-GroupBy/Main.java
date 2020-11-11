package com.mine;

import java.time.Instant;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    private static final Scanner scanner = new Scanner(System.in);

    private static ArrayList<DataObject> data = new ArrayList<>();
    private static ArrayList<String> nameGroup = new ArrayList<>();
    private static ArrayList<String> surnameGroup = new ArrayList<>();
    private static ArrayList<String> groupGroup = new ArrayList<>();
    private static ArrayList<String> genderGroup = new ArrayList<>();
    private static ArrayList<String> studyGroup = new ArrayList<>();
    private static ArrayList<String> programmingLanguagesGroup = new ArrayList<>();

    public static class DataObject {
        public final String name;
        public final String surname;
        public final String group;
        public final String gender;
        public final int studyLength;
        public final String programmingLanguage;

        public DataObject(String name, String surname, String group, String gender, int studyLength, String programmingLanguage) {
            this.name = name;
            this.surname = surname;
            this.group = group;
            this.gender = gender;
            this.studyLength = studyLength;
            this.programmingLanguage = programmingLanguage;
        }
    }

    private static String getVariable(int i,String type){
        switch (type){
            case "pohlavi":
                return data.get(i).gender;
            case "programovaci-jazyk":
                return data.get(i).programmingLanguage;
            case "skupina":
                return data.get(i).group;
            case "rok-studia":
                return Integer.toString(data.get(i).studyLength);
        }
        return "";
    }

    private static void printRow(String type,ArrayList<String> dataGroup){
        for (String ac: dataGroup) {
            System.out.format("-skupina %s:\n", (type.equals("pohlavi")) ? ac.substring(0,1) : ac);
            for (int i = 0; i < data.size(); i++) {
                if (getVariable(i, type).equals(ac)) {
                    System.out.format("-- %s %s (%c, %d. @ %s): %s\n",
                            data.get(i).surname.toUpperCase(),
                            data.get(i).name,
                            data.get(i).gender.charAt(0),
                            data.get(i).studyLength,
                            data.get(i).group.substring(0, 2),
                            data.get(i).programmingLanguage);
                }
            }
        }
    }

    public static void main(String[] args) {
        String command = "";
        while (!(command = scanner.next()).equals("---")){
            boolean isNumber = true;
            int number = 0;
            try {
                number = (int)Double.parseDouble(command);
            } catch (NumberFormatException e) {
                isNumber = false;
            }

            if(isNumber) {
                for (int i = 0; i < number;i++){
                    String name = scanner.next();
                    String surname = scanner.next();
                    String group = scanner.next();
                    String gender = scanner.next();
                    int studyLength = scanner.nextInt();
                    String programmingLanguage = scanner.next();

                    if (!nameGroup.contains(name)) nameGroup.add(name);
                    if (!surnameGroup.contains(surname)) surnameGroup.add(surname);
                    if (!groupGroup.contains(group)) groupGroup.add(group);
                    if (!genderGroup.contains(gender)) genderGroup.add(gender);
                    if (!studyGroup.contains(Integer.toString(studyLength))) studyGroup.add(Integer.toString(studyLength));
                    if (!programmingLanguagesGroup.contains(programmingLanguage)) programmingLanguagesGroup.add(programmingLanguage);

                    data.add(new DataObject(name,surname,group,gender,studyLength,programmingLanguage));
                }
            } else {
                System.out.format("Trideni dle %s\n",command.toUpperCase().replace('-','_'));
                switch (command){
                    case "pohlavi":
                        printRow(command,genderGroup);
                        break;
                    case "programovaci-jazyk":
                        printRow(command,programmingLanguagesGroup);
                        break;
                    case "skupina":
                        printRow(command,groupGroup);
                        break;
                    case "rok-studia":
                        printRow(command,studyGroup);
                        break;

                }
            }
        }
    }
}