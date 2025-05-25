#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int minCost=INT_MAX;

void kedges(vector<vector<pair<int,int>>> &graph,int k,int s,int d,int sum){
    if(k<0)
        return;
    if(s==d && k==0){
        minCost=min(minCost,sum);
        return;
    }
    for(auto &it:graph[s]){
        int next=it.first;
        int weight=it.second;
        kedges(graph,k-1,next,d,sum+weight);
    }
}

int main(){
    int v,e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    vector<vector<pair<int,int>>> graph(v);
    for(int i=0;i<e;i++){
        int m,n,w;
        cout << "Enter source, destination, and weight: ";
        cin >> m >> n >> w;
        graph[m].push_back({n,w});
    }
    int source,dest,k;
    cout << "Enter source node, destination node, and k: ";
    cin >> source >> dest >> k;
    kedges(graph,k,source,dest,0);
    if (minCost == INT_MAX)
        cout << "No path exists from " << source << " to " << dest << " with exactly " << k << " edges." << endl;
    else
        cout << "Shortest path cost from " << source << " to " << dest << " with exactly " << k << " edges: " << minCost << endl;
    return 0;
}