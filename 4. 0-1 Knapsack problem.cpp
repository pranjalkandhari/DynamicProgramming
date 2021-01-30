
/*
    0/1 Knapsack problem

    (Self attempt after watching the video of "Back to Back SWE", link: https://www.youtube.com/watch?v=xCbYmUPvc2Q)
*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(int item_count, int max_capacity, int *weight, int *value)
{
    // Items on the row header and max weight as the column header
    int dp[item_count + 1][max_capacity + 1];

    for (int i = 0; i < item_count + 1; i++)
    {
        for (int j = 0; j < max_capacity + 1; j++)
        {
            // If we choose no item, then our maximum value will be 0. 
            // Hence for all cases of max_capacity, the value will be zero if we do not choose any item.
            // i.e if i == 0, dp[i][j] = 0 for all values of j.
            // Similarly, if j == 0, i.e. max weight is 0, then nothing can be put into the sack, so dp[i][j] = 0
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            // else we have two choices, either we "choose" or "not choose" the current item.
            else
            {
                // if our knapsack is not big enough for the weight of current item, we do "not choose" the item.
                // note: here for ith item we've used (i-1)th element because our matrix size is +1 to both the dimensions.
                if (j - weight[i-1] < 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max( /*choose*/ value[i-1] + dp[i-1][j - weight[i-1]], /*not choose*/ dp[i-1][j]);
            }
        }
    }

    return dp[item_count][max_capacity];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    /*
        Given N items and a sack of maximum capacity M.
        N items have a value and some weight.
        Find the maximum possible value that can be put into the sack.

        Input:
        Item_count max_capacity
        weight[0] ... weight[end]
        value[0]  ... value[end]
    */

    int item_count, max_capacity;
    cin >> item_count >> max_capacity;

    int weight[item_count], value[item_count];

    for (int i = 0; i < item_count; i++)
        cin >> weight[i];

    for (int i = 0; i < item_count; i++)
        cin >> value[i];

    cout << knapsack(item_count, max_capacity, weight, value) << '\n';

    return 0;
}


/*
Sample test case 1:

Input:
3 50
10 20 30
60 100 120    

Output:
220


Sample test case 2:

Input:
4 5
5 3 4 2
60 50 70 30

Output:
80
*/