#include <iostream>
#include <vector>

using namespace std;

int countWaysToMakeSum(vector<int> &coins, int target){
    int n=coins.size();
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=target;j++){
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[target];
}

int main() {
    int n,target;
    cout << "Enter number of coin types: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter types of coin: " << endl;
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    cout << "Enter target sum: ";
    cin >> target;
    int result=countWaysToMakeSum(coins,target);
    cout << "Number of ways to make sum " << target << ": " << result << endl;
    return 0;
}