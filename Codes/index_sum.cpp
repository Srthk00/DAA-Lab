#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void print_index(vector<int> arr){
    int n=arr.size();
    int i,j;
    for(int k=n-1;k>=2;k--){
        int sum=arr[k];
        i=0;
        j=k-1;
        while(i<j){
            if(arr[i]+arr[j]==sum){
                cout << i+1 << "," << j+1 << "," << k+1;
                return;
            }
            else if(arr[i]+arr[j]>sum)
                i++;
            else
                j--;
        }
    }
}

int main(){
    int n,val;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin >> val;
        arr.push_back(val);
    }
    print_index(arr);
    return 0;
}