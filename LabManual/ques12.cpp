#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> arr,int k){
    if(k>arr.size())
        return INT_MIN;
    int min=*min_element(arr.begin(),arr.end());
    int max=*max_element(arr.begin(),arr.end());
    int size=max-min+1;
    int *freq=(int*)calloc(size,sizeof(int));
    for(int i=0;i<arr.size();i++){
        freq[arr[i]-min]++;
    }
    for(int i=1;i<size;i++){
        freq[i]=freq[i-1]+freq[i];
    }
    int *temp=(int*)malloc(size*sizeof(int));
    for(int i=arr.size()-1;i>=0;i--){
        int index=--freq[arr[i]-min];
        temp[index]=arr[i];
    }
    return temp[k-1];
}

int main(){
    int testcases;
    cout << "Enter number of testcase: ";
    cin >> testcases;
    while(testcases>0){
        int n,val,k;
        cout << "Enter size of array: ";
        cin >> n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin >> val;
            arr.push_back(val);
        }
        cout << "Enter value of 'k' to search the kth smallest element: ";
        cin >> k;
        int result=find(arr,k);
        cout << "'kth' smallest element is: " << result << endl;
        testcases--;
    }
    return 0;
}