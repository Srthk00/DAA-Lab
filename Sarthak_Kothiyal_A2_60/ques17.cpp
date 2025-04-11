#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> colour(n,-1);
    for(int i=0;i<n;i++){  
        if(colour[i]==-1){
            queue<int> que;
            que.push(i);
            colour[i]=0; 
            while(!que.empty()){
                int node=que.front();
                que.pop();
                for(int it:graph[node]){
                    if(colour[it]==-1){  
                        colour[it]=!colour[node];
                        que.push(it);
                    } 
                    else if(colour[it]==colour[node]){  
                        return false; 
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    int v,e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for(int i=0;i<e;i++){
        int m,n;
        cin >> m >> n;
        graph[m].push_back(n);
        graph[n].push_back(m);
    }
    if(isBipartite(graph)){
        cout << "The Graph is Bipartite..." << endl; 
    }
    else{
        cout << "The Graph is Not Bipartite..." << endl; 
    }
    return 0;
}