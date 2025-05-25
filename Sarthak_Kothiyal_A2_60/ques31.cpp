#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matrixchainmultiplication(vector<pair<int,int>> &mat){  
    int n=mat.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=2;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int k=j+i-1;
            dp[j][k]=INT_MAX;
            for(int m=j;m<k;m++){
                int cost=dp[j][m]+dp[m+1][k]+mat[j].first*mat[m].second*mat[k].second;
                dp[j][k]=min(dp[j][k],cost);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<pair<int,int>> mat(n);
    cout << "Enter dimensions of matrices:" << endl;
    for(int i=0;i<n;i++){
        cin >> mat[i].first >> mat[i].second;
    }
    int result=matrixchainmultiplication(mat);
    cout << "Result: " << result;
    return 0;
}