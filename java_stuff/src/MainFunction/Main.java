
package MainFunction;

import Python.PythonBuiltins;
import Useful.RandomObjects;
import Useful.DateTimeInterval;
import Useful.InstantiationException;
import java.time.LocalDateTime;

/**
 *
 * @author Alexzander
 */
public class Main {

    public static void main(String[] args) {
        PythonBuiltins python = new PythonBuiltins();
        python.print(python.type(123));

        int[] array = new int[]{134343, 123123, 123124, 46, 22441, 334, 434, 5, 54, 5};
        python.print(array);
        python.print(python.sorted(array));

        RandomObjects rand = new RandomObjects();
        python.print(rand.ReturnRandom16CodeDigitCode());
        rand.DisplayRandom16DigitCode();
        python.print(rand.RandomChar());
        python.print(rand.RandomChar());
        python.print(rand.RandomChar());
        python.print(rand.RandomChar());
        python.print(rand.RandomChar());
        python.print(rand.RandomWord(10));


        LocalDateTime today = LocalDateTime.now();
        LocalDateTime today_plus_10_days = today.plusDays(10);
        try {
            DateTimeInterval dti = DateTimeInterval.Instantiate(today, today_plus_10_days);
            python.print(dti);
        }
        catch (InstantiationException e) {
            //python.print(e);
        }
        finally {
            python.print("<Perfect execution>");
        }

    }
}