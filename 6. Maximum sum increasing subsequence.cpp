
/*
    Maximum sum increasing subsequence

    Problem link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
*/

#include <bits/stdc++.h>
using namespace std;

#define ull long long

void print(ull *a, ull n)
{
    for (ull i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

ull solve(ull *a, ull n)
{
    ull dp[n] = {};

    for (ull i = 0; i < n; i++)
        dp[i] = a[i];

    for (ull i = 0; i < n; i++)
    {
        ull ans = dp[i];
        for (ull j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                ans = max(ans, dp[i] + dp[j]);
        }
        dp[i] = ans;
    }
    return *max_element(dp, dp + n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ull t; cin >> t;
    while(t--)
    {
        ull n; cin >> n;
        ull a[n];
        for (ull i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(a, n) << '\n';
    }
    return 0;
}
