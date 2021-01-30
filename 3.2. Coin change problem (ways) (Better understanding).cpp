
/*
    Coin change problem (ways) revisited (with complete understanding)
*/

/*
    YouTube reference: Back to Back SWE (https://www.youtube.com/watch?v=DJ4a7cmjZY0)
*/

#include <bits/stdc++.h>
using namespace std;

int count_ways(int sum, int *coins, int m)
{
    /*    
        creating a dp table (very similar to the knapsack table)
        At rows we have the coins and at the column we have the amount (or the sum) to be made
        
        A cell in the table represents the number of ways in which we can me a sum (the column header)
        using first i coins (the row header).
    
        Since we must consider the case that what if we have no coins at all (base case) and the case
        that when the sum we have to make is itself 0. 

        The approach we will use is very similar to the knapsack problem. 
        At every point (block) we have an option to "choose" or "not choose" the current coin (row header).
        If our sum is less than the coin value, then we have no choice but to "not choose" the coin hence we 
        then go to our subproblem where we don't really have that coin and we have to make the sum.
        And if the sum is greater than or equal to the current coin's value then we choose it and check the
        answer to the subproblem after removing the value of the current coin (just like the knapsack problem) and then
        do not choose it and add both the possibilities.

        Hence solution, 
        ways = choose the coin[m] + do not choose the coin[m]

        Though, I've tried to explain at my very best but PLEASE GO AND WATCH THE VIDEO TO UNDERSTAND BETTER.
    */

    int dp[m + 1][sum + 1];


    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                // if we do not have any coins then there will be no way to make up the change, hence 0 for no coins
                if (i == 0) 
                    dp[i][j] = 0;

                // if the sum to be made is 0 then there's only 1 way, i.e. by using no coin change at all
                if (j == 0)
                    dp[i][j] = 1;
            }

            else
            {
                // now using the knapsack like concept: we check both possibilites of "choosing" and "not choosing"
                // here we choose the (i-1)th coin bcz we have m-1 coins from 0 index. So i at m will give out of bound error.
                int choose_max_coin = (j >= coins[i-1] ? dp[i][ j - coins[i-1] ] : 0);
                int not_choose_max_coin = dp[i - 1][j];

                // adding both the possibilities to get the total number of ways
                dp[i][j] = choose_max_coin + not_choose_max_coin;
            }
        }
    }

    // uncomment to print the dp table

    // for (int  i = 0; i < m + 1; i++)
    // {
    //     for (int j = 0; j < sum + 1; j++)
    //         cout << dp[i][j] << '\t';
    //     cout << '\n';
    // }
    return dp[m][sum];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum, m;
    cin >> sum >> m;

    int coins[m];
    for (int i = 0; i < m; i++)
        cin >> coins[i];

    cout << count_ways(sum, coins, m) << '\n';

    return 0;
}

/*
Sample test cases:

Input:
10 4
2 5 3 6

Output:
5


Input:
4 3
1 2 3

Output:
4


Input:
5 3
1 2 5

Output:
4

*/