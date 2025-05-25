#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair<int, string> longestCommonSubsequence(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string lcs="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            lcs+=s1[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    return {dp[n][m],lcs};
}

int main() {
    string s1, s2;
    cout << "Enter first sequence: ";
    cin >> s1;
    cout << "Enter second sequence: ";
    cin >> s2;
    pair<int,string> result=longestCommonSubsequence(s1,s2);
    cout << "Length of Longest Common Subsequence: " << result.first << endl;
    cout << "Longest Common Subsequence: " << result.second << endl;
    return 0;
}