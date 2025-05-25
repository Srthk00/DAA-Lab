#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack01(vector<int> & wt,vector<int>& val,int ind,int W,vector<vector<int>>& dp){
    if(ind==0){
        if(wt[0]<=W)
            return val[0];
        return 0;
    }
    if(dp[ind][W]!=-1)
        return dp[ind][W];

    int taken=INT_MIN;
    int notTaken= 0 + knapsack01(wt,val,ind-1,W,dp);

    if(wt[ind]<=W)
        taken= val[ind]+knapsack01(wt,val,ind-1,W-wt[ind],dp);

    return dp[ind][W]=max(notTaken,taken);
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> wt(n), val(n);
    cout << "Enter weights of items:\n";
    for(int i=0; i<n; ++i) cin >> wt[i];
    cout << "Enter values of items:\n";
    for(int i=0; i<n; ++i) cin >> val[i];
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << "Maximum value in knapsack: " << knapsack01(wt, val, n - 1, W, dp) << endl;
    return 0;
}
