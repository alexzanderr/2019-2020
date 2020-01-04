
package Useful;

import java.util.Objects;
import Useful.InstantiationException;

/**
 * This class contains general data about persons. This is made by Andrew.
 *
 * @author Andrew
 */
public class Person implements Comparable<Object> {

    private final String firstName;
    private final String secondName; // family name
    private final int age;
    private final int day;
    private final int month;
    private final int year;
    private final int height;
    private final int weight;
    private final String gender;
    private final boolean married;
    private final boolean dead;
    private final int d_day;
    private final int d_month;
    private final int d_year;

    /**
     * This is general private constructor.
     *
     * @params final String firstName, final String secondName, final int
     * day, final int month, final int year, final int height, final int weight,
     * final String gender, final boolean married, final int age
     *
     */
    private Person(
            final String firstName,
            final String secondName,
            final int age,
            final int day,
            final int month,
            final int year,
            final int height,
            final int weight,
            final String gender,
            final boolean married,
            final boolean dead,
            final int d_day,
            final int d_month,
            final int d_year) {
        this.firstName = firstName;
        this.secondName = secondName;
        this.age = age;
        this.day = day;
        this.month = month;
        this.year = year;
        this.height = height;
        this.weight = weight;
        this.gender = gender;
        this.married = married;
        this.dead = dead;
        this.d_day = d_day;
        this.d_month = d_month;
        this.d_year = d_year;
    }
    /**
     * This is used only for name.
     *
     * @param name
     * @return
     */
    public static Person Instantiation(final String name) throws InstantiationException{
        if (!NameValidation(name)) {
            throw new InstantiationException("Invalid arguments");
        } else {
            final String[] nameArray = name.split(" ");
            return new Person(
                    UpperFirstLetter(nameArray[1]),
                    UpperFirstLetter(nameArray[0]),
                    0, 0, 0, 0, 0, 0, null, false, false, 0, 0, 0);
        }
    }

    /**
     * This is used only for name and age processing with data and streams.
     *
     * @param name
     * @param age
     * @return
     */
    public static Person Instantiation(final String name, final int age) throws InstantiationException {
        if (!NameValidation(name) || !AgeValidation(age)) {
            throw new InstantiationException("Invalid arguments");
        } else {
            final String[] nameArray = name.split(" ");
            return new Person(
                    UpperFirstLetter(nameArray[1]),
                    UpperFirstLetter(nameArray[0]),
                    age, 0, 0, 0, 0, 0, null, false, false, 0, 0, 0);
        }
    }

    /**
     * This method is used to create instance if the data is valid.
     *
     * @param name
     * @param birthDate
     * @param age
     * @param height
     * @param weight
     * @param gender
     * @param married
     * @param dead
     * @param deathDate
     * @return Person data type
     */
    public static Person Instantation(
            final String name,
            final String birthDate,
            final int age,
            final int height,
            final int weight,
            final String gender,
            final boolean married,
            final boolean dead,
            final String deathDate) throws InstantiationException {
        if (!NameValidation(name)
                || !BirthDateValidation(birthDate)
                || !HeightValidation(height)
                || !WeightValidation(weight)
                || !GenderValidation(gender)) {
            throw new InstantiationException("Invalid arguments");
        } else {
            final String[] nameArray = name.split(" ");
            final int[] dateArray = Transform(birthDate);
            if (deathDate.equals("N/A")) {
                return new Person(
                        UpperFirstLetter(nameArray[1]),
                        UpperFirstLetter(nameArray[0]),
                        age,
                        dateArray[0],
                        dateArray[1],
                        dateArray[2],
                        height,
                        weight,
                        UpperFirstLetter(gender),
                        married,
                        dead,
                        0, 0, 0
                );
            } else {
                if (!DeathDateValidation(deathDate)) {
                    throw new InstantiationException("Invalid arguments");
                }
                final int[] death_dateArray = Transform(deathDate);
                if (death_dateArray[2] < dateArray[2]) {
                    throw new InstantiationException("Death year is smaller than birth year, it makes no sense.");
                }
                if (death_dateArray[2] == dateArray[2]) {
                    throw new InstantiationException("Death year equals birth year, it makes no sense.");
                }
                return new Person(
                        UpperFirstLetter(nameArray[1]),
                        UpperFirstLetter(nameArray[0]),
                        age,
                        dateArray[0],
                        dateArray[1],
                        dateArray[2],
                        height,
                        weight,
                        UpperFirstLetter(gender),
                        married,
                        dead,
                        death_dateArray[0],
                        death_dateArray[1],
                        death_dateArray[2]
                );
            }
        }
    }

    private static String UpperFirstLetter(final String name) {
        char primulCaracter = Character.toUpperCase(name.charAt(0));
        String restul = name.substring(1).toLowerCase();
        return primulCaracter + restul;
    }

    private static int[] Transform(final String birthDate) {
        String[] date = birthDate.split("-");
        final int day = Integer.parseInt(date[0]);
        final int month = Integer.parseInt(date[1]);
        final int year = Integer.parseInt(date[2]);
        return new int[]{day, month, year};
    }

    private static boolean NameValidation(final String name) {
        if (name == null || name.isEmpty()) {
            return false;
        }
        if (!name.matches("[a-zA-Z ]+")) {
            return false;
        }
        return name.indexOf(" ") == name.lastIndexOf(" ");
    }

    private static boolean AgeValidation(final int age) {
        return !(age < 0 || age > 123);
    }

    private static boolean BirthDateValidation(final String birthDate) {
        if (birthDate == null || birthDate.isEmpty()) {
            return false;
        }
        if (!birthDate.matches("[1234567890-]+")) {
            return false;
        }
        if (birthDate.length() != 10 || birthDate.indexOf("-") != 2 || birthDate.lastIndexOf("-") != 5) {
            return false;
        }
        final int[] date = Transform(birthDate);
        if (date.length != 3) {
            return false;
        }
        return (date[0] >= 1 && date[0] <= 31 && date[1] >= 1 && date[1] <= 12);
    }

    private static boolean DeathDateValidation(final String deathDate) {
        if (deathDate == null || deathDate.isEmpty()) {
            return false;
        }
        if (!deathDate.matches("[1234567890-]+")) {
            return false;
        }
        if (deathDate.length() != 10 || deathDate.indexOf("-") != 2 || deathDate.lastIndexOf("-") != 5) {
            return false;
        }
        final int[] d_date = Transform(deathDate);
        if (d_date.length != 3) {
            return false;
        }
        return (d_date[0] >= 1 && d_date[0] <= 31 && d_date[1] >= 1 && d_date[1] <= 12);
    }

    private static boolean HeightValidation(final int height) {
        return !(height < 30 || height > 250);
    }

    private static boolean WeightValidation(final int weight) {
        return !(weight < 3 || weight > 500);
    }

    private static boolean GenderValidation(final String gender) {
        return "Male".equals(UpperFirstLetter(gender)) || "Female".equals(UpperFirstLetter(gender));
    }

    @Override
    public String toString() {
        return this.firstName
                + " "
                + this.secondName
                + ", "
                + this.age 
                + " years old, "
                + ReturnBirthDate()
                + ", "
                + this.height
                + "cm, "
                + this.weight
                + "kg, "
                + this.gender
                + ", "
                + ((this.married) ? "married, " : "not married, ")
                + ((this.dead) ? "dead... at " + ReturnDeathDate() : "!dead :)")
                + ".";
    }

    private String ReturnBirthDate() {
        return ((this.day < 10) ? ("0" + Integer.toString(this.day)) : (Integer.toString(this.day)))
                + "-"
                + ((this.month < 10) ? ("0" + Integer.toString(this.month)) : (Integer.toString(this.month)))
                + "-"
                + this.year;
    }
    
    private String ReturnDeathDate() {
        return ((this.d_day < 10) ? ("0" + Integer.toString(this.d_day)) : (Integer.toString(this.d_day)))
                + "-"
                + ((this.d_month < 10) ? ("0" + Integer.toString(this.d_month)) : (Integer.toString(this.d_month)))
                + "-"
                + this.d_year;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getSecondName() {
        return secondName;
    }

    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }

    public int getHeight() {
        return height;
    }

    public int getWeight() {
        return weight;
    }

    public String getGender() {
        return gender;
    }

    public boolean isMarried() {
        return married;
    }

    public int getAge() {
        return age;
    }

    public int getD_day() {
        return d_day;
    }

    public int getD_month() {
        return d_month;
    }

    public int getD_year() {
        return d_year;
    }

    public boolean isDead() {
        return dead;
    }

    @Override
    public int compareTo(final Object obj) {
        Person person = (Person) obj;
        final String person_name = person.secondName + " " + person.firstName;
        final String this_name = this.secondName + " " + this.firstName;
        return this_name.compareTo(person_name);
    }
}