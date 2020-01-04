/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Useful;

import Python.PythonBuiltins;

/**
 *
 * @author Alexzander
 */
public class SetsAndMatrix {

    private PythonBuiltins python = new PythonBuiltins();
    private OldFunctions funct = new OldFunctions();

    private int Return_digits(final int number) {
        return (int) (Math.log10(number) + 1);
    }

    private char Convert_Int_to_Character_digit_only(final int value) {
        switch (value) {
            case 0:
                return '0';
            case 1:
                return '1';
            case 2:
                return '2';
            case 3:
                return '3';
            case 4:
                return '4';
            case 5:
                return '5';
            case 6:
                return '6';
            case 7:
                return '7';
            case 8:
                return '8';
            case 9:
                return '9';
            default:
                return '\0';
        }
    }

    private void Converter(final int number) {
        int copy = number;
        int digits = Return_digits(number);
        char[] str = new char[digits];
        int index = str.length - 1;
        while (copy > 0) {
            int value = copy % 10;
            str[index--] = Convert_Int_to_Character_digit_only(value);
            copy /= 10;
        }
        python.print(str);
        if(str.length % 2 == 0) {
            boolean valid = true;
            int iter = str.length - 1;
            for (int _index = 0; _index < (str.length / 2) - 1; _index++) {
                if(str[_index] != str[iter--]) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                System.out.println("Simetrical array.");
            }
        } else {
            boolean valid = true;
            int iter = str.length - 1;
            for (int _index = 0; _index < str.length / 2; _index++) {
                if(str[_index] != str[iter--]) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                System.out.println("Simetrical array.");
            }
        }
    }

    public void Crowds_operations(int[] array1, int[] array2) {
        System.out.print("A: ");
        python.print(array1);
        System.out.print("B: ");
        python.print(array2);
        final int size1 = array1.length;
        final int size2 = array2.length;
        int[] reunion = new int[size1 + size2];
        int min_size = size1 < size2 ? size1 : size2;
        int[] intersect = new int[min_size];
        int limit = 0;
        for (int i = 0; i < size1; i++) {
            reunion[i] = array1[i];
            limit++;
        }
        for (int i = 0; i < size2; i++) {
            reunion[limit++] = array2[i];
        }
        python.QuickSort(reunion);
        int jiterator = 0;
        final int size = reunion.length - 1;
        for (int index = 0; index < size; index++) {
            if (reunion[index] != reunion[index + 1]) {
                reunion[jiterator] = reunion[index];
                jiterator++;
            }
        }
        reunion[jiterator] = reunion[size];
        System.out.print("Reunion: ");
        funct.Print_array(reunion, jiterator + 1);

        //=========================================================================
        int found = 0;
        for (int index = 0; index < size1; index++) {
            if (funct.Binary_search_int_returnBool(array2, array1[index])) {
                intersect[index] = array1[index];
                found++;
            }
        }

        int[] intersection = new int[found];
        for (int index = 0; index < found; index++) {
            intersection[index] = intersect[index];
        }
        python.QuickSort(intersection);
        System.out.print("Intersection: ");
        funct.Print_array(intersection);

        //=========================================================================
        int[] dif1 = new int[size1];
        int[] dif2 = new int[size2];
        int found1 = 0;
        int found2 = 0;
        int not_found1 = 0;
        int not_found2 = 0;
        for (int index = 0; index < size1; index++) {
            if (!funct.Binary_search_int_returnBool(array2, array1[index])) {
                dif1[index] = array1[index];
                found1++;
            } else {
                not_found1++;
            }

        }
        if (not_found1 == size1) {
            System.out.println("There is no diference between crowds.");
        } else {
            int[] diference1 = new int[found1];
            int dim = 0;
            for (int index = 0; index < size1; index++) {
                if (dif1[index] != 0) {
                    diference1[dim++] = dif1[index];
                }
            }
            python.QuickSort(diference1);
            System.out.print("A \\ B: ");
            funct.Print_array(diference1);
        }

        for (int index = 0; index < size2; index++) {
            if (!funct.Binary_search_int_returnBool(array1, array2[index])) {
                dif2[index] = array2[index];
                found2++;
            } else {
                not_found2++;
            }

        }
        if (not_found2 == size2) {
            System.out.println("There is no diference between sets.");
        } else {
            int[] diference2 = new int[found2];
            int dim = 0;
            for (int index = 0; index < size2; index++) {
                if (dif2[index] != 0) {
                    diference2[dim++] = dif2[index];
                }
            }
            python.QuickSort(diference2);
            System.out.print("B \\ A: ");
            funct.Print_array(diference2);
        }
    }

    public void Matrix_operations(int[][] matrix1, int[][] matrix2) {  //matrix1.l == matrix2.l
        
        final int dim = matrix1.length;
        int[][] matrix_sum = new int[matrix1.length][matrix1[0].length];
        int[][] matrix_multiplication = new int[matrix2.length][matrix2[0].length];
        System.out.println("Matrix sum: \n");
        for (int i = 0; i < matrix1.length; i++) {
            for (int j = 0; j < matrix1[i].length; j++) {
                matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j];
                System.out.print(matrix_sum[i][j] + " ");
            }
            System.out.print("\n");
        }
        System.out.print("\n");
        for (int index = 0; index < dim; index++) {
            int additon = 0;
            for (int i = 0; i < matrix1.length; i++) {
                for (int j = 0; j < matrix1[i].length; j++) {
                    additon += matrix1[index][j] * matrix2[j][i];
                }
                matrix_multiplication[index][i] = additon;
            }
        }
        System.out.println("Matrix multiplication: \n");
        for (int i = 0; i < matrix_multiplication.length; i++) {
            for (int j = 0; j < matrix_multiplication[i].length; j++) {
                System.out.print(matrix_multiplication[i][j] + " ");
            }
            System.out.print("\n");
        }
        System.out.print("\n");
        for (int i = 0; i < matrix1.length; i++) {
            for (int j = i + 1; j < matrix1[i].length; j++) {
                int aux = matrix1[i][j];
                matrix1[i][j] = matrix1[j][i];
                matrix1[j][i] = aux;
            }
        }
        System.out.println("Matrix1 transposed: \n");
        for (int i = 0; i < matrix1.length; i++) {
            for (int j = 0; j < matrix1[i].length; j++) {
                System.out.print(matrix1[i][j] + " ");
            }
            System.out.print("\n");
        }
        System.out.print("\n");
        for (int i = 0; i < matrix2.length; i++) {
            for (int j = i + 1; j < matrix2[i].length; j++) {
                int aux = matrix2[i][j];
                matrix2[i][j] = matrix2[j][i];
                matrix2[j][i] = aux;
            }
        }
        System.out.println("Matrix2 transposed: \n");
        for (int i = 0; i < matrix2.length; i++) {
            for (int j = 0; j < matrix2[i].length; j++) {
                System.out.print(matrix2[i][j] + " ");
            }
            System.out.print("\n");
        }
    }

    public void Array_find_element(int[] array, final int element) {
        
        int[] list_pos = new int[array.length];
        int showing = 0;
        int first_pos = 0;
        int last_pos = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] == element) {
                showing++;
                last_pos = list_pos[i] = i;
            }
        }
        for (int i = 0; i < array.length; i++) {
            if (array[i] == element) {
                first_pos = i;
                break;
            }
        }
        System.out.println("Showing: " + showing);
        System.out.println("First pos: " + first_pos + "\nLast pos: " + last_pos);
        for (int i = 0; i < list_pos.length; i++) {
            if (list_pos[i] != 0) {
                System.out.print(list_pos[i] + " ");
            }
        }
        System.out.println("\n");
    }

    public void Array_of_char_merge(char[] chr1, char[] chr2) {
        int limit = 0;
        char[] chr3 = new char[chr1.length + chr2.length];
        for (int i = 0; i < chr1.length; i++) {
            chr3[i] = chr1[i];
            limit++;
        }
        for (int i = 0; i < chr2.length; i++) {
            chr3[limit++] = chr2[i];
        }
        System.out.println(chr3);
    }


    // testing area
    public static void main(String[] args) {
        SetsAndMatrix operations = new SetsAndMatrix();
        operations.Array_of_char_merge(new char[]{'1','2','3','4'}, new char[]{'2', '4', '5', '6', '7'});
        operations.Array_find_element(new int[]{1, 4, 2, 4, 3, 2, 3, 233, 4, 5}, 4);
        operations.Matrix_operations(
                new int[][]{
                        {1, 2, 3, 6},
                        {4, 5, 6, 4},
                        {7, 8, 9, 3},
                        {2, 3, 4, 5}
                }, new int[][]{
                        {9, 8, 7, 4},
                        {6, 5, 4, 6},
                        {3, 2, 1, 6},
                        {2, 7, 5, 9}
                }
        );
        operations.Crowds_operations(
                new int[]{4, 5, 6, 7, 8, 9, 20, 19, 18, 32, 42, 36},
                new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
        );
        operations.Converter(12321);
        char c = (char) operations.Convert_Int_to_Character_digit_only(0);
        System.out.println(c);
    }
}