/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Useful;

/**
 *
 * @author Andrew
 */
public class OldFunctions {
    
    public void Print_array(final char[] array) {
        Print_array(array, array.length);
    }
    
    public void Print_array(final char[] array, final int length) {
        for (int index = 0; index < length; index++) {
            System.out.print(array[index] + " ");
        }
        System.out.print("\n");
    }
    
    public void Print_array(final int[] array) {
        Print_array(array, array.length);
    }
    
    public void Print_array(final int[] array, final int length) {
        for (int index = 0; index < length; index++) {
            System.out.print(array[index] + " ");
        }
        System.out.print("\n");
    }
    
    public int Max_value_int(final int value1, final int value2) {
        if (value1 > value2) {
            return value1;
        }
        return value2;
    }
    
    public int Min_value_int(final int value1, final int value2) {
        if (value1 < value2) {
            return value1;
        }
        return value2;
    }

    public boolean Binary_search_int_returnBool(final int[] array, final int element) {
        int start_index = 0;
        int stop_index = array.length - 1;
        while (start_index <= stop_index) {
            int middle_index = (start_index + stop_index) / 2;
            if (array[middle_index] == element) {
                return true;
            } else if (array[middle_index] < element) {
                start_index = middle_index + 1;
            } else {
                stop_index = middle_index - 1;
            }
        }
        return false;
    }
    
    public boolean Prime_number(final int number) {
        if (number < 2) {
            return false;
        }
        if ((number % 2 == 0) && (number > 2)) {
            return false;
        }
        for (int divisor = 3; (divisor * divisor) <= number; divisor += 2) {
            if (number % divisor == 0) {
                return false;
            }
        }
        return true;
    }
    
    public int Power(final int X, final int Y) {
        int power = 1;
        for(int index = 0; index < Y; index++) {
            power *= X;
        }
        return power;
    }
}