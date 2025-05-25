#include <iostream> 
#include <queue> 
#include <vector> 
using namespace std; 
 
int minCostCombineFile(vector<int> &files,int n){ 
    priority_queue<int, vector<int>, greater<int>> pq; 
    for(int i=0; i<files.size(); i++){
        pq.push(files[i]);
    } 
    int cost=0; 
    while(pq.size()!=1){ 
        int m1=pq.top();
        pq.pop(); 
        int m2=pq.top();
        pq.pop(); 
        cost+=m1+m2; 
        pq.push(m1+m2); 
    } 
    return cost; 
} 
 
int main() { 
    int n;  
    cout << "Enter the number of files: "; 
    cin >> n; 
    vector<int> files(n); 
    cout << "Enter the sizes of files: "; 
    for(int i=0; i<n; i++){
        cin >> files[i]; 
    }
    cout << "Minimum cost to combine: " << minCostCombineFile(files,n); 
    return 0; 
}