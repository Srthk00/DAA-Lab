#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    vector<char> chars(n);
    vector<int> freq(26,0);
    cout << "Enter characters: ";
    for(int i=0;i<n;i++){
        cin >> chars[i];
    }
    for(int i:chars){
        freq[i-'a']++;
    }
    for(int i=0;i<26;i++){
        if(freq[i]){
            cout << (char)(i+'a') << ": " << freq[i] << endl;
        }
    }
    return 0;
}