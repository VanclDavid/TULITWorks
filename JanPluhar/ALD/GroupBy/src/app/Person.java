package app;
public class Person{
    private String name;
    private String surname;
    private String group;
    private char sex;
    private int year;
    private String programmingLanguage;
    public Person(String name, String surname, String group, String sex, int year, String programmingLanguage) {
        this.name = name;
        this.surname = surname;
        this.group = group;
        this.sex = sex.toUpperCase().charAt(0);
        this.year = year;
        this.programmingLanguage = programmingLanguage;
    }
    public String getAll(){
        return "-- "+surname+" "+name+" ("+sex+", "+year+". @ "+group.substring(0,2)+"): "+programmingLanguage;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public String getGroup() {
        return group;
    }

    public char getSex() {
        return sex;
    }

    public int getYear() {
        return year;
    }

    public String getProgrammingLanguage() {
        return programmingLanguage;
    }
}