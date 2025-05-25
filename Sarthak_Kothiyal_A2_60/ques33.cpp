#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int> &arr){
    int n=arr.size();
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
    if(totalSum%2!=0){
        return false;
    }
    int target=totalSum/2;
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of the set:" << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];  
    }
    bool result=canPartition(arr);
    if(result){
        cout << "Yes..." << endl;
    }
    else{
        cout << "No..." << endl;
    }
    return 0;
}
