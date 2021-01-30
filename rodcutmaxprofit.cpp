#include<iostream>
using namespace std;

int memo[100];
int maxProfit(int arr[],int totalLen){
    if(totalLen==0) return 0;

    if(memo[totalLen]!=-1){
        return memo[totalLen];
    }
    int best=0;
    for(int len=1;len<=totalLen;++len){
        //ek piece ki cost mei nikaluga baki ki tum nikal ke aao
        //selling every piece at a time and calling recursion for
        //the rest of the rod
        int netProfit = arr[len] + maxProfit(arr,totalLen-len);
        best=max(best,netProfit);
    }
    memo[totalLen]=best;
    return best;
}

int max_profit_bu(int arr[],int totalLen){
    int dp[100]={};

    for(int len=1;len<=totalLen;++len){
        int best=0;
        for(int cut=1;cut<=len;++cut){
            best=max(best,arr[cut]+dp[len-cut]);
        }
        dp[len]=best;
    }
    return dp[totalLen];
}

int main(){
    int priceOfEachLength[100];

    int totalLen;
    cin>>totalLen;

    for(int eachPiece=1;eachPiece<=totalLen;++eachPiece){
        cin>>priceOfEachLength[eachPiece];
    }

    //reset memopad
    for(int i=0;i<=totalLen;++i){
        memo[i]=-1;
    }

    int ans = maxProfit(priceOfEachLength,totalLen);
    cout<<max_profit_bu(priceOfEachLength,totalLen);
    cout<<endl<<ans;


    return 0;

}
