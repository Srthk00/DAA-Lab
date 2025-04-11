#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void count(vector<int> &nums){
    int m=*max_element(nums.begin(),nums.end());
    vector<int> freq(m+1,0);
    for(int i:nums){
        freq[i]++;
    }
    for(int i=1;i<freq.size();i++){
        freq[i]=freq[i]+freq[i-1];
    }
    vector<int> temp(nums.size());
    for(int i=nums.size()-1;i>=0;i--){
        temp[freq[nums[i]]-1]=nums[i];
        freq[nums[i]]--;
    }
    nums=temp;
}

int main(){
    int n, val;
    vector<int> nums;
    cout << "Enter the size of an array:";
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> val;
        nums.push_back(val);
    }
    for (int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    count(nums);
    cout << endl;
    for (int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    return 0;
}