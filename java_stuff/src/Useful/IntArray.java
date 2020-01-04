/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Useful;

import java.text.DecimalFormat;

/**
 *
 * @author Alexzander
 */
public class IntArray {

    private int[] array;
    private OldFunctions funct = new OldFunctions();

    private IntArray(final int[] array) {
        this.array = array;
    }

    public void Find_subArray(final int[] vector) {
        int dim = 0;
        int index = 0;
        for (int _index = 0; _index < array.length; _index++) {
            if (array[_index] == vector[index]) {
                dim++;
                if (index < vector.length - 1) {
                    index++;
                }
            } else {
                dim = 0;
                index = 0;
            }
            if (dim == vector.length) {
                break;
            }
        }
        if (dim == vector.length) {
            System.out.println("SubArray found.");
        } else {
            System.out.println("SubArray not found.");
        }
    }

    public void Insert_array_on_index(final int[] vector, int pos) {
        int positon = pos;
        int[] new_array = new int[array.length + vector.length];
        for (int _index = 0; _index < pos; _index++) {
            new_array[_index] = array[_index];
        }
        for (int _index = 0; _index < vector.length; _index++) {
            new_array[pos++] = vector[_index];
        }
        for (int _index = pos; _index < new_array.length; _index++) {
            new_array[_index] = array[positon++];
        }
        Print_array(new_array);
    }

    public void Delete_element(int start, final int stop) {
        int[] array_copy = new int[array.length - ((start + stop) / 2)];
        for (int _index = 0; _index < array.length; _index++) {
            if (_index == start) {
                break;
            }
            array_copy[_index] = array[_index];
        }
        for (int _index = stop + 1; _index < array.length; _index++) {

            array_copy[start++] = array[_index];
        }
        Print_array(array_copy);
    }

    public void Delete_element(final int element) {
        int[] array_copy = new int[array.length - 1];
        int pos = 0;
        for (int _index = 0; _index < array.length; _index++) {
            if (element == array[_index]) {
                pos = _index;
                break;
            }
            array_copy[_index] = array[_index];
        }
        for (int _index = pos; _index < array.length - 1; _index++) {
            array_copy[_index] = array[_index + 1];
        }
        Print_array(array_copy);
    }

    public void Insert_on_index(final int element, final int pos) {
        int[] new_array = new int[array.length + 1];
        int index = 0;
        for (; index < pos; index++) {
            new_array[index] = array[index];
        }
        new_array[pos] = element;
        for (int _index = pos; _index < array.length; _index++) {
            new_array[_index + 1] = array[_index];
        }
        Print_array(new_array);
    }

    public void Push_back(final int element) {
        int[] new_array = new int[array.length + 1];
        int index = 0;
        for (; index < array.length; index++) {
            new_array[index] = array[index];
        }
        new_array[index] = element;
        Print_array(new_array);
    }

    public static void Print_array(final int[] vector) {
        for (int index = 0; index < vector.length; index++) {
            System.out.print(vector[index] + " ");
        }
        System.out.print("\n");
    }

    private static int Generate_length_random(final int range1, final int range2) {
        return (int) ((Math.random() * range2) + range1);
    }

    private void Array_random_population_bet_rg1_rg2(int[] vector, final int range1, final int range2) {
        for (int _index = 0; _index < vector.length; _index++) {
            vector[_index] = Generate_length_random(range1, range2);
        }
    }

    private void Print_array_average(IntArray obj) {
        DecimalFormat df = new DecimalFormat("#.##");
        int sum = 0;
        for (int _index = 0; _index < obj.array.length; _index++) {
            sum += obj.array[_index];
        }
        System.out.println("Average: " + df.format(sum / (double) obj.array.length));
    }

    private void Prime_numbers_and_indexs(IntArray obj) {
        for (int _index = 0; _index < obj.array.length; _index++) {
            if (funct.Prime_number(obj.array[_index])) {
                System.out.print("[" + _index + "]:" + obj.array[_index] + " ");
            }
        }
        System.out.print("\n");
    }

    public static void main(String[] args) {
        IntArray array = new IntArray(new int[]{1, 2, 3, 4, 5, 6, 7});
        Print_array(array.array);
        array.Push_back(1);
        array.Insert_on_index(7, 2);
        array.Delete_element(1);
        array.Delete_element(2, 4);
        array.Insert_array_on_index(new int[]{1, 2, 3, 4, 5}, 3);
        array.Find_subArray(new int[]{3, 4, 5});
        IntArray vector = new IntArray(new int[Generate_length_random(50, 50)]);
        vector.Array_random_population_bet_rg1_rg2(vector.array, 1, 1000);
        Print_array(vector.array);
        vector.Print_array_average(vector);
        vector.Prime_numbers_and_indexs(vector);
    }
}
