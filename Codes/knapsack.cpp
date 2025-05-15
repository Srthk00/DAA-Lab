#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> &wt,vector<int> &val,int W,int n){
    if(W==0 || n==0){return 0;}
    if(wt[n-1]>W){return knapsack(wt,val,W,n-1);}
    return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
}

int main(){
    int n,value;
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
    cin >> W;
    cout << "Total Value: " << knapsack(wt,val,W,n);  
    return 0;
}