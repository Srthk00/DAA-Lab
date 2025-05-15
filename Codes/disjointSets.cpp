#include <iostream>
#include <vector>

using namespace std;

int find(int x,vector<int> &parent){
    if(x!=parent[x]){
        parent[x]=find(parent[x],parent);
    }
    return parent[x];
}

void UNION(int a,int b,vector<int> &rank,vector<int> &parent){
    int x=find(a,parent);
    int y=find(b,parent);
    if(x==y){
        cout << "Both nodes belong to same set..." << endl;
        return;
    }
    if(rank[x]>rank[y]){
        parent[y]=x;
    }
    else if(rank[x]<rank[y]){
        parent[x]=y;
    }
    else{
        parent[x]=y;
        rank[y]++;
    }
}

int main(){
    vector<int> parent(1000);
    vector<int> rank(1000,0);
    int v;
    cout << "Enter number of Vertices: ";
    cin >> v;
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    while(true){
        cout << "------MENU------" << endl;
        cout << "1. Find" << endl;
        cout << "2. Union" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch(choice){
            case 1:{
                int node;
                cout << "Enter the node to find its Representative: ";
                cin >> node;
                cout << "Representative of ",node," is: ",find(node,parent);
                break;
            }
            case 2:{
                int n1,n2;
                cout << "Enter two sets to merge: ";
                cin >> n1 >> n2;
                UNION(n1,n2,rank,parent);
                break;
            }
            case 3:{
                cout << "Program Ended..." << endl;
                break;
            }
            default:{
                cout << "Enter a valid option..." << endl;
            }
        }
    }
    return 0;
}