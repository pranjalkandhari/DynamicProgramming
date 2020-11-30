#include<iostream>
#define ull long long
using namespace std;

//This approach is recrsion with memoization.
ull maxXor(ull *arr , ull n , ull k , ull save[1001][1024])
{
    if(n == 1) 
    {
        ull op1 = (arr[0]^k);
        ull op2 = k;
        return max(op1 , op2);
    }
    if(save[n][k] != -1) return save[n][k];
    ull op1 = maxXor(arr+1 , n-1 , k , save);
    ull op2 = maxXor(arr+1 , n-1 , (arr[0]^k) , save);

    save[n][k] = max(op1,op2);

    return max(op1,op2);
}

int main()
{
    ull T;
    cin>>T;
    while(T--)
    {
        ull n,k;
        cin>>n>>k;
        ull *arr = new ull[n];
        for(ull i = 0 ; i<n ; i++) cin>>arr[i];

        ull save[1001][1024]; //Max number = n  and max value of k = 1023 (As 1<=Ai<=1000)
        for(ull i = 0 ; i<=n ; i++)
        {
            for(ull j = 0 ; j<=1023 ; j++)
            {
                save[i][j] = -1;
            }
        }

        cout<<maxXor(arr , n , k , save)<<endl;

    }
}