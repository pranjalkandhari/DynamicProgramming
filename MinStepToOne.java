
/* 
    This is a functions which solve the problem minimum steps to one. 
    Problem:
    Given a number n , we have to reach 1 by keep performing 3 operations starting with n
    3 operation:
    n = n-1
    n = n/2
    n = n/3
*/
public class Solution {
	
	//USING RECURSION
	public static int countStepsTo1(int n){
		
	/* Your class should be named Solution.
	 * Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Return output and don't print it.
	 * Taking input and printing output is handled automatically.
	 */
      //BASE CASE 
      if( n == 1 ) return 0;
      
      int a1 = countStepsTo1( n-1 );
      int a2 = Integer.MAX_VALUE;
      int a3 = Integer.MAX_VALUE;
      
      if( n%2 == 0 ) a2 = countStepsTo1( n/2 );
        
      if( n%3 == 0 ) a3 = countStepsTo1( n/3 );
        
      return 1 + Math.min( a1 , Math.min( a2 , a3 ) ) ;
      
	}
	
	//NOW USING DP
	public static int countStepsTo1DP(int n){
        int storage[] = new int[n+1];
        for(int i = 2 ; i <= n ; i++ ){
            int min = storage[i-1];
            if( i%3 == 0 && min > storage[i/3] ) min = storage[i/3];
            if( i%2 == 0 && min > storage[i/2] ) min = storage[i/2];
            storage[i] = min + 1;
        }
        return storage[n];
	}
	
}
