#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

typedef struct node{
    char ch;
    int freq;
    node *left,*right;
}node;

node *getnode(char ch,int freq,node *left,node *right){
    node *nde=new node();
    nde->ch=ch;
    nde->freq=freq;
    nde->left=left;
    nde->right=right;
    return nde;
}

typedef struct MinHeap{
    node* heap[1000];
    int size;

    MinHeap(){size=0;}

    void heapify(int i){  
        int smallest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=size && heap[left]->freq < heap[smallest]->freq){
            smallest=left;
        }
        if(right<=size && heap[right]->freq < heap[smallest]->freq){
            smallest=right;
        }
        if(smallest!=i){
            swap(heap[i],heap[smallest]);
            heapify(smallest);
        }
    }
    void insert(node *nde){
        size++;
        int i=size;
        heap[i]=nde;
        while(i>1 && heap[i]->freq<heap[i/2]->freq){
            swap(heap[i],heap[i/2]);
            i=i/2;
        }
    }
    node *extractmin(){
        node *minnode=heap[1];
        heap[1]=heap[size];
        size--;
        heapify(1);
        return minnode;
    }
}MinHeap;

void encode(node* root,string str,unordered_map<char,string> &huffmanCode){ 
    if(!root)
        return; 
    if(!root->left && !root->right) 
        huffmanCode[root->ch]=str; 
    encode(root->left,str+"0",huffmanCode); 
    encode(root->right,str+"1",huffmanCode); 
} 

void decode(node *root,int &index,string str){ 
    if(!root)
        return; 
    if(!root->left && !root->right){ 
        cout << root->ch;
        return; 
    } 
    index++; 
    if(str[index]=='0') 
        decode(root->left,index,str); 
    else 
        decode(root->right,index,str); 
} 

void buildtree(string str){
    unordered_map<char,int> mp;
    for(char ch:str){
        mp[ch]++;
    }
    
}

int main(){
    string str;
    cout << "Enter a String: ";
    getline(cin,str);
    buildtree(str);
    return 0;
}