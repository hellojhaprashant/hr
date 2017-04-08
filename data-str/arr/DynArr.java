package hr.ds.arr.darr;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {
  private static int                 N, Q, lastAns;
  private static List<List<Integer>> sequences = new ArrayList<List<Integer>>();
  private static int[][]             queries;                                   // query

  // data

  public static void main(String[] args) {
    /*
     * Enter your code here. Read input from STDIN. Print output to STDOUT. Your
     * class should be named Solution.
     */
    init();
    doQueries();
  }

  private static void doQueries() {
    for (int i = 0; i < Q; i++) {
      int x = queries[i][1];
      int y = queries[i][2];

      switch (queries[i][0]) {
      case 1:
        doQuery1(x, y);
        break;
      case 2:
        doQuery2(x, y);
        break;
      default:
        System.out.println("ERROR: reached default in switch-case");
        break;
      }
    }
    //
  }

  /**
   * when query type = 1, get x and y get the sequence at index = (x ^ lastAns)
   * mod N append y to the sequence
   */
  private static void doQuery1(final int x, final int y) {
    int index = (x ^ lastAns) % N;
    // System.out.printf("index = %d %n", index);

    List<Integer> seq = null;
    if (index < sequences.size()) {
      // sequence exists
      seq = sequences.get(index);
    }

    if (seq == null) {
      // System.out.println("empty seq, will create new");
      seq = new ArrayList<Integer>();
      sequences.add(seq);
    }
    seq.add(y);
    // System.out.println("seq:" + seq);
  }

  /**
   * when query type = 2, Find the sequence, , at index (x ^ lastAns) % N) in
   * sequences. Find the value of element y % size(seq) and assign it to
   * lastAns. Print the new value of lastAns on a new line
   */
  private static void doQuery2(int x, int y) {
    // System.out.printf("entered doQuery2() x=%d, y=%d %n", x, y);
    int index = (x ^ lastAns) % N;
    // System.out.printf("index=%d %n", index);
    List<Integer> seq = sequences.get(index);
    int size = seq.size();
    int value = seq.get(y % size);
    lastAns = value;
    // System.out.println("==================");
    System.out.println(lastAns);
  }

  /**
   * read the input data get N, Q. Init the queries
   */
  private static void init() {
    // Scanner s = new Scanner(System.in);
    try {
      Scanner s = new Scanner(new File("hr.ds.arr.darr.input.txt"));
      N = s.nextInt();
      Q = s.nextInt();

      queries = new int[Q][3]; // the data for queries

      for (int i = 0; i < Q; i++) {
        // String line = s.nextLine();
        queries[i][0] = s.nextInt();
        queries[i][1] = s.nextInt();
        queries[i][2] = s.nextInt();
        // System.out.printf("queryType=%d, x=%d, y=%d", XY[i][0], XY[i][1],
        // XY[i][2]);
      }

      s.close();
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }

    // logInputs();
  }

  private static void logInputs() {
    System.out.println("N=" + N + ", Q=" + Q);

    for (int i = 0; i < Q; i++) {
      System.out.printf("queryType=%d, x=%d, y=%d %n", queries[i][0],
          queries[i][1], queries[i][2]);
    }
  }
}

/**
 * Create a list, , of empty sequences, where each sequence is indexed from to .
 * The elements within each of the sequences also use -indexing. Create an
 * integer, , and initialize it to . The types of queries that can be performed
 * on your list of sequences () are described below: Query: 1 x y Find the
 * sequence, , at index in . Append integer to sequence . Query: 2 x y Find the
 * sequence, , at index in . Find the value of element in (where is the size of
 * ) and assign it to . Print the new value of on a new line Task Given , , and
 * queries, execute each query.
 * 
 * Note: is the bitwise XOR operation, which corresponds to the ^ operator in
 * most languages. Learn more about it on Wikipedia.
 * 
 * Input Format
 * 
 * The first line contains two space-separated integers, (the number of
 * sequences) and (the number of queries), respectively. Each of the subsequent
 * lines contains a query in the format defined above.
 * 
 * Constraints
 * 
 * It is guaranteed that query type will never query an empty sequence or index.
 * Output Format
 * 
 * For each type query, print the updated value of on a new line.
 * 
 * Sample Input
 * 
 * 2 5 1 0 5 1 1 7 1 0 3 2 1 0 2 1 1 Sample Output
 * 
 * 7 3 Explanation
 * 
 * Initial Values:
 * 
 * 
 * 
 * 
 * Query 0: Append to sequence .
 * 
 * 
 * 
 * Query 1: Append to sequence .
 * 
 * 
 * Query 2: Append to sequence .
 * 
 * 
 * 
 * Query 3: Assign the value at index of sequence to , print .
 * 
 * 
 * 7 Query 4: Assign the value at index of sequence to , print .
 * 
 * 
 * 3
 */
