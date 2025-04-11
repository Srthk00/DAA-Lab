#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void mergee(vector<int> &nums,int low,int mid,int high){
    vector<int> temp;
    int left=low,right=mid+1;
    while(left<=mid && right<=high){
        if(nums[left]<nums[right]){
            temp.push_back(nums[left++]);
        }
        else{
            temp.push_back(nums[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(nums[left++]);
    }
    while(right<=high){
        temp.push_back(nums[right++]);
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
}

void mergesort(vector<int> &nums,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        mergee(nums,low,mid,high);
    }
}

int main(){
    vector<int> nums;
    int n,val;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> val;
        nums.push_back(val);
    }
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    mergesort(nums,0,nums.size()-1);
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    return 0;
}