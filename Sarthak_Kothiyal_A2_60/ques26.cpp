#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double ksnap(vector<double> &val,vector<double> &wt,int n,int W){
    vector<pair<double,pair<int,int>>> frac;
    for(int i=0;i<n;i++){
        frac.push_back({val[i]/wt[i],{wt[i],val[i]}});
    }
    sort(frac.rbegin(),frac.rend());
    double maxVal=0;
    for(int i=0;i<n && W>0;i++){
        if(W>=frac[i].second.first){
            maxVal+=frac[i].second.second;
            W-=frac[i].second.first;
        }
        else{
            maxVal+=frac[i].first*W;
            W=0;
        }
    }
    return maxVal;
}

int main(){
    int n,W;
    cout << "Enter Size of array: ";
    cin >> n;
    vector<double> wt(n),val(n);
    cout << "Enter weight array: ";
    for(int i=0;i<n;i++)
        cin >> wt[i];
    cout << "Enter value array: ";
    for(int i=0;i<n;i++)
        cin >> val[i];
    cin >> W;
    cout << "Total Value: " << ksnap(val,wt,n,W);
    return 0;
}
