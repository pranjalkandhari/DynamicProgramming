/*
Problem:
Given an integer matrix of size m*n.
You need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.

The below function is the solution to the above problem.
*/

public class Solution {
    
	public static int minCostPath(int input[][]) {
		/* Your class should be named Solution
		* Don't write main().
		* Don't read input, it is passed as function argument.
		* Return output and don't print it.
		* Taking input and printing output is handled automatically.
		*/
      int m = input.length;
      int n = input[0].length;
      
      // For Edegs
      for(int i = 1; i<n ; i++) input[0][i] += input[0][i-1];
      for(int i = 1; i<m ; i++) input[i][0] += input[i-1][0];

     for(int i = 1 ; i<m ; i++){
         for(int j = 1 ; j<n ; j++){
             input[i][j] += Math.min( input[i-1][j-1] , Math.min( input[i][j-1] , input[i-1][j] ) );
         }
     }
	return input[m-1][n-1];
	}
}
