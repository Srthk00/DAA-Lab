#include <iostream>
#include <vector>

using namespace std;

int main(){
    int v,e;
    cout << "Enter number of Vertices and Edges: ";
    cin >> v >> e;
    vector<vector<pair<int,int>>> graph(v);
    for(int i=0;i<e;i++){
        int m,n,w;
        cout << "Enter Source, Destination, and Weigth: ";
        cin >> m >> n >> w;
        graph[m].push_back({n,w});
    }
    
    return 0;
}