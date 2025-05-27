#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long matrixmultiplication(vector<int> &mat,int i,int j,vector<vector<int>> &dp){
    if(i>=j){return 0;}
    long long final=INT_MAX;
    for(int k=i;k<j;k++){
        long long temp=matrixmultiplication(mat,i,k,dp)+matrixmultiplication(mat,k+1,j,dp)+(mat[i]*mat[k]*mat[j]);
        if(temp<final){
            final=temp;
        }
    }
    return final;
}

int main(){
    int n,val;
    cout << "Enter number of Matrix: ";
    cin >> n;
    vector<int> mat;
    cout << "Enter matrix Data: ";
    for(int i=0;i<n;i++){
        cin >> val;
        mat.push_back(val);
    }
    vector<vector<int>> dp;
    long long result=matrixmultiplication(mat,0,mat.size(),dp);
    cout << result;
    return 0;
}