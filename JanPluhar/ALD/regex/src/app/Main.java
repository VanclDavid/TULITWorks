package app;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String input;
        ArrayList<String> upperCases=new ArrayList<>();
        ArrayList<String> iLoveWords=new ArrayList<>();
        ArrayList<String> sentences=new ArrayList<>();
        while (sc.hasNextLine()) {
            input = sc.nextLine();
            upperCases.addAll(findMatches(input, "[A-Z][a-zA-Z-]*",true));
            iLoveWords.addAll(findMatches(input, "I love",false));
            sentences.addAll(findMatches(input, "[A-Z][a-zA-Z- ]*[.]",true));
        }
        print("Uppercases", upperCases);
        print("I love", iLoveWords);
        print("Sentences", sentences);
    }

    public static ArrayList<String> findMatches(String input, String regex, boolean isCaseSensitive) {
        ArrayList<String> allMatches = new ArrayList<>();
        Pattern pattern;
        if (isCaseSensitive) {
            pattern = Pattern.compile(regex);
        } else {
            pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        }
        Matcher m = pattern.matcher(input);
        while (m.find()) {
            allMatches.add(m.group());
        }
        return allMatches;
    }

    public static void print(String title, ArrayList<String> data) {
        if (data.size()!=0){
            System.out.println(title + " " + data.size() + "x:");
            for (int i = 0; i < data.size(); i++) {
                System.out.println(i + 1 + ") '" + data.get(i) + "'");
            }
            System.out.println();
        }
    }
}

