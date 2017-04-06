import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int arr[][] = new int[6][6];
        for(int arr_i=0; arr_i < 6; arr_i++){
            for(int arr_j=0; arr_j < 6; arr_j++){
                arr[arr_i][arr_j] = in.nextInt();
            }
        }
      
        final int ROWS = 6;
        final int COLS = 6;
        final int HG = 3;
      
        int max_sum = -99999;
        int sum = 0;
      
        for (int i=0; i<=(ROWS-HG); i++){
          for (int j=0; j<=(COLS-HG); j++){
            //printHg(arr, i, j);
              
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            //System.out.print ("max_sum, sum: " +max_sum + ", " + sum);
            if (max_sum < sum){
              max_sum = sum;
            }
            //System.out.println ("; " + max_sum + "," + sum);
          }
        }
      
        System.out.println(max_sum);
    }
  
  private static void printHg(int[][] arr, int i, int j){
    System.out.println("----------------------");
    System.out.println("Hourglass ["+ i + "] ["+ j + "] :");
    System.out.println(arr[i][j] + " " + arr[i][j+1]  + " " +  arr[i][j+2]);
    System.out.println("  " + arr[i+1][j+1]);
    System.out.println(arr[i+2][j]  + " " + arr[i+2][j+1]  + " " +  arr[i+2][j+2]);
  }
}
