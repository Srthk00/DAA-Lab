#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void redixSort(vector<int>& arr,int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }
    int exp=1;
    while(max/exp>0){
        int *output=(int*)malloc(sizeof(n));
        int count[10]={0};
        for(int i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;i--){
            output[count[(arr[i]/exp)%10]-1]=arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for(int i=0;i<n;i++){
            arr[i]=output[i];
            exp*=10;
        }
    }
}

int main(){
    int n, val;
    vector<int> arr;
    cout << "enter the size of an array:";
    cin >> n;
    cout << "enter the element of array:";
    for(int i=0;i<n;i++){
        cin >> val;
        arr.push_back(val);
    }
    redixSort(arr,n);
    for (int i = 0; i < n; i++)
    cout << arr[i] << ",";
    cout << endl;
    return 0;
}