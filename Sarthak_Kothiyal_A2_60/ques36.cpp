#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutation(string str,int low,int high,vector<string> &result){
    if(low==high){
        result.push_back(str);
        return;
    }
    for(int i=low;i<=high;i++){
        swap(str[low],str[i]);
        permutation(str,low+1,high,result);
        swap(str[low],str[i]);
    }
    sort(result.begin(),result.end());
}

int main(){
    string str;
    cout << "Enter a String: ";
    cin >> str;
    vector<string> result;
    permutation(str,0,str.size()-1,result);
    cout << "All permutaion of " << str << ": " << endl;
    for(string s:result){
        cout << s << ", ";
    }
    return 0;
}