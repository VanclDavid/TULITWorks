package app;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        ArrayList<Person> persons = new ArrayList<>();
        ArrayList<String> inputGroupBy = new ArrayList<>();
        int personCount = sc.nextInt();
        for (int i = 0; i < personCount; i++) {
            persons.add(new Person(sc.next(), sc.next().toUpperCase(), sc.next(), sc.next(), sc.nextInt(), sc.next()));
        }
        String nextString;
        while (!(nextString = sc.next()).equals("---")) {
            inputGroupBy.add(nextString);
        }
        for (String group : inputGroupBy){
            ArrayList<String> uniqueValues = getUniqueValues(group,persons);
            System.out.println("Trideni dle "+group.toUpperCase().replace('-','_'));
            for (String value : uniqueValues) {
                ArrayList<Person> selectedPersons = getMatchedPersons(group,value,persons);
                System.out.println("-skupina "+value+":");
                printAllPersons(selectedPersons);
            }
        }
    }
    public static ArrayList<Person> getMatchedPersons(String group, String value, ArrayList<Person> persons){
        ArrayList<Person> newArray=new ArrayList();
        for (Person person:persons) {
            if (getAttribute(person,group).equals(value)){
                newArray.add(person);
            }
        }
        return newArray;
    }
    public static ArrayList<String> getUniqueValues(String attribute, ArrayList<Person> persons) {
        ArrayList<String> categories = new ArrayList<>();
        persons.forEach(person -> {
            String value=getAttribute(person, attribute);
            if (!alreadyExists(value,categories)){
                categories.add(value);
            }
        });
        return categories;
    }
    public static void printAllPersons(ArrayList<Person> array){
        for (Person person:array) {
            System.out.println(person.getAll());
        }
    }
    public static boolean alreadyExists(String value, ArrayList<String> categories) {
        boolean exist=false;
        for (String category : categories) {
            if (category.equals(value)) {
                return true;
            }
        }
        return false;
    }

    public static String getAttribute(Person person, String name) {
        switch (name) {
            case "jmeno":
                return person.getName();
            case "prijmeni":
                return person.getSurname();
            case "skupina":
                return person.getGroup();
            case "pohlavi":
                return Character.toString(person.getSex());
            case "rok-studia":
                return Integer.toString(person.getYear());
            case "programovaci-jazyk":
                return person.getProgrammingLanguage();
            default:
                return null;
        }
    }
}
