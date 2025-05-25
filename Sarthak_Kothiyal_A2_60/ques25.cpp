#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

void floydWarshall(vector<vector<int>> &dist,int v){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    cout<<"All-pairs shortest path matrix:\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dist[i][j]==INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int v;
    cout<<"Enter number of vertices: ";
    cin>>v;
    vector<vector<int>> dist(v,vector<int>(v));
    cout<<"Enter date in the matrix:\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            string val;
            cin>>val;
            if(val=="INF")
                dist[i][j]=INT_MAX;
            else
                dist[i][j]=stoi(val);
        }
    }
    floydWarshall(dist,v);
    return 0;
}