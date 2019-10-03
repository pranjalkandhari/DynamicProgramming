/*
Problem:
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
Output will be 1, as 1 is the minimum count of numbers required.

The below function is the solution to the above problem:
*/


public class Solution {
	
public static int minCount(int n) {
		if(n<=3) 
		return n;
        int count[] = new int[n+1];
        count[1] = 1;
        count[2] = 2;
        count[3] = 3;

        for(int i = 4 ; i<=n ; i++)
        {
            int ans = i;
            for(int j = 1 ; j<= i/2 ; j++){
                int k = i - (j*j);
                if(k>=0)
                ans = Math.min(ans , count[k] + 1 );
            }
            count[i] = ans;
        }

        return count[n];
    }
	
}
