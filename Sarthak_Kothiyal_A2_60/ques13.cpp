#include <iostream>

using namespace std;

int find(string str){
    char *arr=(char*)calloc(26,sizeof(char));
    for(char ch:str){
        arr[ch-'a']++;
    }
    int min=1;
    int index=-1;
    for(int i=0;i<26;i++){
        if(arr[i]>min){
            min=arr[i];
            index=i;
        }
    }
    return index;
}

int main(){
    int testcases;
    cout << "Enter number of testcase: ";
    cin >> testcases;
    while(testcases>0){
        string str;
        cout << "Enter a sequence of charactes: ";
        cin >> str;
        int result=find(str);
        if(result==-1)
            cout << "No duplicates...";
        else
            cout << "Element with Maximun Occurence: " << (char)(result+'a') << endl;
        testcases--;
    }
    return 0;
}