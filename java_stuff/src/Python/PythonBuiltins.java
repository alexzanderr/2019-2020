package Python;


import java.util.Arrays;
import java.util.*;

/**
 * @author Alexzander
 * @version 1.0
 */
public class PythonBuiltins {

    public void print() {
        System.out.println();
    }

    public <T> void print(final T arg) {
        System.out.println(arg);
    }

    public <T1, T2> void print(final T1 arg1, final T2 arg2) {
        System.out.print(arg1);
        System.out.print(" ");
        System.out.println(arg2);
    }

    public <T1, T2, T3> void print(final T1 arg1, final T2 arg2, final T3 arg3) {
        System.out.print(arg1);
        System.out.print(" ");
        System.out.print(arg2);
        System.out.print(" ");
        System.out.println(arg3);
    }

    public <T1, T2, T3, T4> void print(final T1 arg1, final T2 arg2, final T3 arg3, final T4 arg4) {
        System.out.print(arg1);
        System.out.print(" ");
        System.out.print(arg2);
        System.out.print(" ");
        System.out.print(arg3);
        System.out.print(" ");
        System.out.println(arg4);
    }

    public void print(final int[] arr) {
        System.out.print("[");
        for (int iter = 0; iter < arr.length; iter++) {
            System.out.print(arr[iter]);
            System.out.print(", ");
        }
        System.out.print(arr[arr.length - 1]);
        System.out.println("]");
    }

    /**
     * @param arr char array
     */
    public void print(final char[] arr) {
        System.out.print("[");
        for (int iter = 0; iter < arr.length; iter++) {
            System.out.print(arr[iter]);
            System.out.print(", ");
        }
        System.out.print(arr[arr.length - 1]);
        System.out.println("]");
    }

    /**
     * @param arr Integer array
     */
    public void print(final Integer[] arr) {
        System.out.print("[");
        for (int iter = 0; iter < arr.length; iter++) {
            System.out.print(arr[iter]);
            System.out.print(", ");
        }
        System.out.print(arr[arr.length - 1]);
        System.out.println("]");
    }

    public String type(Object arg) {
        String result = "<class '%s'>";
        if (arg.getClass() == Integer.class) {
            result = String.format(result, "Integer");
        }
        else if (arg.getClass() == String.class) {
            result = String.format(result, "String");
        }
        else if (arg.getClass() == Float.class) {
            result = String.format(result, "Float");
        }
        else if (arg.getClass() == Double.class) {
            result = String.format(result, "Double");
        }
        else if (arg.getClass() == PythonBuiltins.class) {
            result = String.format(result, "PythonBuiltins");
        }
        else {
            result = String.format(result, "None");
        }
        return result;
    }

    public int[] copy(final Integer[] arr) {
        int[] result = new int[arr.length];
        for (int iter = 0; iter < arr.length; iter++) {
            result[iter] = arr[iter];
        }
        return result;
    }

    public Integer[] copy(final int[] arr) {
        Integer[] result = new Integer[arr.length];
        for (int iter = 0; iter < arr.length; iter++) {
            result[iter] = arr[iter];
        }
        return result;
    }

    public void QuickSort(int[] array) {
        QuickSort(array, 0, array.length - 1);
    }

    public void QuickSort(int[] array, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = array[(left + right) / 2];
        int index = Partition(array, left, right, pivot);
        QuickSort(array, left, index - 1);
        QuickSort(array, index, right);
    }

    public int Partition(int[] array, int left, int right, int pivot) {
        while (left <= right) {
            while (array[left] < pivot) {
                left++;
            }
            while (array[right] > pivot) {
                right--;
            }
            if (left <= right) {
                int aux = array[left];
                array[left] = array[right];
                array[right] = aux;
                left++;
                right--;
            }
        }
        return left;
    }

    public int[] sorted(Integer[] arr) {
        Arrays.sort(arr);
        print(arr);
        int[] result = copy(arr);
        return result;
    }

    public int[] sorted(Integer[] arr, final boolean reversed) {
        if (reversed) {
            Arrays.sort(arr, Collections.reverseOrder());
        }
        else {
            Arrays.sort(arr);
        }
        int[] result = copy(arr);
        return result;
    }

    public Integer[] sorted(int[] arr) {
        Integer[] result = copy(arr);
        Arrays.sort(result);
        return result;
    }

    public Integer[] sorted(int[] arr, final boolean reversed) {
        Integer[] result = copy(arr);
        if (reversed) {
            Arrays.sort(result, Collections.reverseOrder());
        }
        else {
            Arrays.sort(result);
        }
        return result;
    }

}