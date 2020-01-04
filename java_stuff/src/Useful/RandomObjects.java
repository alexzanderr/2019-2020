package Useful;

import Python.PythonBuiltins;

public class RandomObjects {

    private String sixteencode;
    private boolean available;
    private PythonBuiltins python = new PythonBuiltins();
    private final String alpha = "abcdefghijklmnopqrstuvxyz" + "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private final String digits = "0123456789";

    public RandomObjects() {
        this.available = false;
        this.sixteencode = null;
    }

    public int RandomDigit() {
        return (int) ((Math.random() * 9) + 1);
    }

    public char RandomChar() {
        return alpha.charAt((int) (Math.random() * this.alpha.length()));
    }

    public String RandomWord(final int length) {
        String result = "";
        for (int iter = 0; iter < length; iter++) {
            result += RandomChar();
        }
        return result;
    }

    public void DisplayRandom16DigitCode() {
        String code = "";
        for (int _index = 1; _index <= 16; _index++) {
            code += Integer.toString(RandomDigit());
            if (_index % 4 == 0) {
                code += " ";
            }
        }
        python.print(code);
        this.sixteencode = code;
        this.available = true;
    }

    public String ReturnRandom16CodeDigitCode() {
        String aux = "";
        for (int _index = 1; _index <= 16; _index++) {
            aux += Integer.toString(RandomDigit());
            if (_index % 4 == 0) {
                aux += " ";
            }
        }
        this.sixteencode = aux;
        this.available = true;
        return aux;
    }

    public String GetCode() {
        if (!this.available) {
            return "There is no available code";
        }
        return sixteencode;
    }

    public boolean GetStatus() {
        return this.available;
    }

    @Override
    public String toString() {
        if (!this.available) {
            return "There is no available code";
        }
        return "Random 16 code is: " + sixteencode;
    }
}
