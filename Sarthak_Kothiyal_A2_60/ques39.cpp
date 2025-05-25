#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void find(vector<int>& arr){
    int n=arr.size();
    unordered_map<int,pair<int,int>> map;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int prod=arr[i]*arr[j];
            if(map.find(prod)==map.end()){
                map[prod]={i,j};
            }
            else{
                pair<int,int> prev=map[prod];
                if(prev.first!=i && prev.second!=i && prev.first!=j && prev.second!=j){
                    cout << "Pairs with same product found: ";
                    cout << "(" << arr[prev.first] << "," << arr[prev.second] << ") and (" << arr[i] << "," << arr[j] << ")";
                    return;
                }
            }
        }
    }
    cout << "No such pairs exist\n";
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    find(arr);
    return 0;
}