#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int pivot(vector<int>& arr,int low,int high,int &swp,int &comp){
    int ran=low+rand()%(high-low+1);
    swap(arr[ran],arr[high]);
    swp++;
    int pi=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        comp++;
        if(arr[j]<pi){
            i++;
            swap(arr[i],arr[j]);
            swp++;
        }
    }
    swap(arr[i+1],arr[high]);
    swp++;
    return i+1;
}

void quick(vector<int>& arr,int low,int high,int &swp,int &comp){
    if(low<high){
        int p=pivot(arr,low,high,swp,comp);
        quick(arr,low,p-1,swp,comp);
        quick(arr,p+1,high,swp,comp);
    }
}

int main(){
    srand(time(0));
    int n, val,testcase;
    cout << "Enter number of testcases: ";
    cin >> testcase;
    while(testcase>0){
        int swp=0,comp=0;
        vector<int> arr;
        cout << "enter the size of an array:";
        cin >> n;
        cout << "enter the element of array:";
        for(int i=0;i<n;i++){
            cin >> val;
            arr.push_back(val);
        }
        cout << "Elements before sorting: [";
        for(int i:arr){
            cout << i << ",";
        }
        cout << "]" << endl;
        quick(arr,0,n-1,swp,comp);
        cout << "Elements after sorting: [";
        for(int i:arr){
            cout << i << ",";
        }
        cout << "]" << endl;
        cout << "Number of Swaps: " << swp << endl;
        cout << "Number of Comparisons: " << comp << endl;
        testcase--;
    }
    return 0;
}