#include <iostream>
#include <vector>

using namespace std;

int knapsackmemo(vector<vector<int>> &dp,vector<int> &wt,vector<int> &val,int W,int n){
    if(W==0 || n==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(wt[n-1]>W){
        return dp[n][W]=knapsackmemo(dp,wt,val,W,n-1);
    }
    return dp[n][W]=max(val[n-1]+knapsackmemo(dp,wt,val,W-wt[n-1],n-1),knapsackmemo(dp,wt,val,W,n-1));
}

int main(){
    int n,value;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> wt;
    vector<int> val;
    cout << "Enter weight array: ";
    for(int i=0;i<n;i++){
        cin >> value;
        wt.push_back(value);
    }
    cout << "Enter value array: ";
    for(int i=0;i<n;i++){
        cin >> value;
        val.push_back(value);
    }
    int W;
    cout << "Enter maximum capacity: ";
    cin >> W;
    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
    cout << "Total Value: " << knapsackmemo(dp,wt,val,W,n);
    return 0;
}