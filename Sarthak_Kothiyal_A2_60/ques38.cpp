#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &nums,int k){
    int m=*max_element(nums.begin(),nums.end());
    vector<int> freq(m+1,0);
    int n=nums.size();
    for(int i=0;i<k;i++){
        freq[nums[i]]++;
        if(freq[nums[i]]>1){return true;}
    }
    for(int i=k;i<n;i++){
        freq[nums[i]]++;
        freq[nums[i-k]]--;
        if(freq[nums[i]]>1){return true;}
    }
    return false;
}

int main(){
    int n,k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements in the array: ";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << "Enter window Size: ";
    cin >> k;
    if(check(nums,k)){
        cout << "Duplicates present in window of size " << k;
    }
    else{        
        cout << "Duplicates are NOT present in window of size " << k;
    }
    return 0;
}