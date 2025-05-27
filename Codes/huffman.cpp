#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct node{
    char ch;
    int freq;
    node *left,*right;
};

struct Compare{
    bool operator()(node *a,node *b){
        return a->freq>b->freq;
    }
};

void generateCode(node* root,string str,unordered_map<char,string> &huffmanCode){ // pre-order traversal
    if(!root)
        return; 
    if(!root->left && !root->right) 
        huffmanCode[root->ch]=str; 
    generateCode(root->left,str+"0",huffmanCode); 
    generateCode(root->right,str+"1",huffmanCode); 
} 

unordered_map<char,string> huffman(string str){
    unordered_map<char,int> map;
    for(char ch:str){
        map[ch]++;
    }   
    priority_queue<node*,vector<node*>,Compare> pq;
    for(auto &it:map){
        node *temp=new node{it.first,it.second,nullptr,nullptr};
        pq.push(temp);
    }
    while(pq.size()>1){
        node *n1=pq.top();
        pq.pop();
        node *n2=pq.top();
        pq.pop();
        node *newNode=new node{'\0',n1->freq+n2->freq,n1,n2};
        pq.push(newNode);
    }
    node *root=pq.top();
    unordered_map<char,string> huffmanCoding;
    generateCode(root,"",huffmanCoding);
    return huffmanCoding;
}

string encode(string txt,unordered_map<char,string> &huffmanCoding){
    string result="";
    for(char ch:txt){
        result+=huffmanCoding[ch];
    }
    return result;
}

string decode(string encoded,unordered_map<char,string> &huffmanCoding){
    unordered_map<string,char> rev;
    for(auto &it:huffmanCoding){
        rev[it.second]=it.first;
    }
    string decoded="";
    string currcode="";
    for(char ch:encoded){
        currcode+=ch;
        if(rev.find(currcode)!=rev.end()){
            decoded+=rev[currcode];
            currcode="";
        }
    }
    return decoded;
}

int main(){
    string str;
    cout << "Enter a String: ";
    getline(cin,str);
    unordered_map<char,string> huffmanCoding=huffman(str);
    string temp=encode(str,huffmanCoding);
    cout << "Encoded Message: " << temp << endl;
    cout << "Decoded Message: " << decode(temp,huffmanCoding);
    return 0;
}