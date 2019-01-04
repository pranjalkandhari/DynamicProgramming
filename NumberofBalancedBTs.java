/*
  Problem:
  Given an integer h, find the possible number of balanced binary trees of height h. 
  You just need to return the count of possible binary trees which are balanced.
  
  The below function is the solution to the above problem
*/

public class Solution {

  //USING RECURSION
	public static int balancedTreesOfHeightH(int height){
		/* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
	 	 * Taking input and printing output is handled automatically.
		*/
        // BASE CASE 
        if(height == 1 || height == 0) return 1;

        int h1 = balancedTreesOfHeightH(height-1);
        int h2 = balancedTreesOfHeightH(height-2);
        int m = (int)Math.pow(10,9) + 7;
        long res1 = ((long)h1*h1);
        long res2 = ((long)h1*h2*2);

        int val1 = (int)(res1%m);
        int val2 = (int)(res2%m);

        return (val1 + val2)%m;
	}
  
  //NOW USING DP:
  public static int balancedTreesOfHeightHDP(int n){
		// Write your code here
      
      int storage[] = new int[n+1];

      storage[0] = 1;
      storage[1] = 1;

      for(int i = 2 ; i <= n ; i++){
          int h1 = storage[i-1];
          int h2 = storage[i-2];

          int m = (int)Math.pow(10,9) + 7;
        long res1 = ((long)h1*h1);
        long res2 = ((long)h1*h2*2);

        int val1 = (int)(res1%m);
        int val2 = (int)(res2%m);

        storage[i] = (val1 + val2)%m;
      }
        return storage[n];
	}
  
}
