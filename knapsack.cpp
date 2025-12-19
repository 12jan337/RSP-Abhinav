#include <iostream>
#include <vector>

using namespace std;

int knapsackRec(vector<int> val, vector<int> wt, int W, int n){ // O(2^n)

    if (n == 0 || W == 0){
        return 0;
    }
    int itemwt = wt[n - 1];
    int itemVal = val[n - 1];

    if (itemwt <= W){
         // valid-wt
        // include
        int ans1 = knapsackRec(val, wt, W - itemwt, n - 1) + itemVal;
        // exclude
        int ans2 = knapsackRec(val, wt, W, n - 1);
        return max(ans1, ans2);
        }else {
        // exclude
        return knapsackRec(val, wt, W, n - 1);
    }
}

int knapsackMem(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>> &dp) {
    if (n == 0 || W == 0){
        return 0;
    }
    if(dp[n][W] != -1) {
        return dp [n] [W];
    }
    int itemwt = wt[n-1];
    int itemVal = val[n-1];

    if (itemwt <= W) { //valid wt

    //include
    int ans1 = knapsackMem(val, wt, W-itemwt, n-1, dp) + itemVal;
    //exclude
    int ans2 = knapsackMem (val, wt, W, n-1, dp);
    dp[n][W] = max (ans1, ans2);
    } else {
    //exclude
    dp[n][W] = knapsackMem(val, wt, W, n-1, dp);
    }

    return dp[n][W] ;
}

int knapsackTab (vector<int> val, vector<int> wt, int W, int n) { //O(n*W)
 vector<vector<int>> dp(n+1, vector<int> (W+1, 0));

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < W + 1; j++){
            int itemwt = wt [i-1];
            int itemVal = val[i-1];
            if (itemwt <= j) {
                dp[i][j] = max(itemVal + dp [i-1] [j-itemwt], dp [i-1] [j]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

class Solution{ 
    public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0)) ;
        for(int i=0; i<n+1; i++) {
            dp[i][0] = 1;
        }
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<amount+1; j++) {
                if (coins [i-1] < j) { //valid
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                } else { //invalid
                dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};


int main() {
vector<int> val = {15, 14, 10, 45, 30};
vector<int> wt = {2, 5, 1, 3, 4};
int W = 7;
int n = 5;
cout << knapsackTab(val, wt, W, n)<< endl;
return 0;
}

