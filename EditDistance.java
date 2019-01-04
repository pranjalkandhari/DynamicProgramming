/*
Problem:
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. 
Edit Distance of two strings is minimum number of steps required to make one string equal to other. 
In order to do so you can perform following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character

The below function is the solution to the above problem
*/


public class Solution {
    
  //USING RECURSION
	  public static int editDistance(String s1, String s2){	

            // BASE CASE
            if(s1 == s2) return 0; 
            if(s1.length() == 0) return s2.length();
            if(s2.length() == 0) return s1.length();

            if(s1.charAt(0) == s2.charAt(0)) return editDistance(s1.substring(1) , s2.substring(1) );

            else{ 

                // 1.Insert an element. 
                int op1 =  1 + editDistance(s1 , s2.substring(1));

                // 2.Delete an element.
                int op2 =  1 + editDistance(s1.substring(1) , s2);

                // 3.substitute
                int op3 =  1 + editDistance(s1.substring(1) , s2.substring(1)) ;

                return Math.min(op1 , Math.min(op2 , op3));

            }

	}
  
  //USING DP
   public static int editDistance(String s1 , String s2){
        int m = s1.length();
        int n = s2.length();

        int storage[][] = new int[m+1][n+1];

        for(int i = 0 ; i <= m ; i++) storage[i][0] = i;
        for(int i = 0 ; i <= n ; i++) storage[0][i] = i;

        for(int i = 1 ; i<=m ; i++){
            for(int j = 1 ; j<=n ; j++){
                if(s1.charAt(m-i) == s2.charAt(n-j)) storage[i][j] = storage[i-1][j-1];

                else{
                    int op1 = storage[i-1][j];
                    int op2 = storage[i][j-1];
                    int op3 = storage[i-1][j-1];

                    storage[i][j] =1 + Math.min(op1 , Math.min(op2 , op3));
                }
            }
        } 

        return storage[m][n];
    }
  
}
