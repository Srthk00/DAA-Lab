#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool checkpath(vector<vector<int>>& graph, int source, int destination,int n) {
    vector<int> visited(n+1,0);
    stack<int> st;
    st.push(source);
    visited[source]=1;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(node==destination)
            return true;
        for(int i=n-1;i>=0;i--){
            if(graph[node][i] && visited[i]!=1){
                st.push(i);
                visited[i]=1;
            }
        }
    }
    return false;
}

int main(){
    int v,e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    vector<vector<int>> graph(v,vector<int>(v,0));
    for(int i=0;i<e;i++){
        int m,n;
        cin >> m >> n;
        graph[m][n]++;
        graph[n][m]++;
    }
    int s,d;
    cout << "Provide Source and Destination: ";
    cin >> s >> d;
    if(checkpath(graph,s,d,v)){
        cout << "Path Exist..." << endl; 
    }
    else{
        cout << "Path Do Not Exist..." << endl;
    }
    return 0;
}