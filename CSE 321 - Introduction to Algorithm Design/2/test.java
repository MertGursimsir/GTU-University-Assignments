// Java program for the above approach
import java.io.*;
import java.util.*;
 
class test{
    // Driver Code
    public static void main(String[] args)
    {
        int[] arr = { -40, -5, -20 };
        int size = arr.length;
        int n = -60;
        boolean flag = false;

        int max = arr[0];
        for (int i = 1; i < arr.length; ++i){
            if (arr[i] > max) max = arr[i];
        }

        int[] newarr = new int[max+1];

        for (int i = 0; i < newarr.length; ++i){
            newarr[i] = 0;
        }
        for (int i = 0; i < arr.length; ++i){
            newarr[arr[i]]++;

            if (n == 0 && newarr[i] > 1){
                System.out.println("Pair Found: (" + arr[i] + ", " + arr[i] + ")");
                flag = true;
            }
        }
        if (n == 0 && !flag) System.out.println("no pair found");

        for (int i = 0; i < arr.length; ++i){
            if ((n+arr[i]) < newarr.length && newarr[n+arr[i]] != 0) System.out.println("Pair Found: (" + arr[i] + ", " + (n+arr[i]) + ")");
        }


    }
}
 
// This code is contributed by code_hunt.