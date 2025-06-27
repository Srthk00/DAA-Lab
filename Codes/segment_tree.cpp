#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void build_max(int i,vector<int> &nums,vector<int> &segtree,int L,int R){
    if(L==R){
        segtree[i]=nums[L];
    }
    else{
        int mid=(L+R)/2;
        build_max(2*i+1,nums,segtree,L,mid);
        build_max(2*i+2,nums,segtree,mid+1,R);
        segtree[i]=max(segtree[2*i+1],segtree[2*i+2]);
    }
}

// L and R represent bounds of current node (i), initially root, so 0 to n-1 and shrinks as calls go on
// a and b represent our query (search space for max element), remain unchanged
int find_max(int i,int a,int b,vector<int> &segtree,int L,int R){
    if(a>R || b<L){
        return INT_MIN;
    }   
    if(a<=L && b>=R){
        return segtree[i];
    }
    int mid=(L+R)/2;
    int fromleft=find_max(2*i+1,a,b,segtree,L,mid);
    int fromright=find_max(2*i+1+2,a,b,segtree,mid+1,R);
    return max(fromleft,fromright);
}

void update_max(int i,int L,int R,int idx,int val,vector<int> &segtree){
    if(L==R){
        segtree[i]+=val;
    }
    else{
        int mid=(L+R)/2;
        if(idx<=mid){
            update_max(2*i+1,L,mid,idx,val,segtree);
        }
        else{
            update_max(2*i+2,mid+1,R,idx,val,segtree);
        }
        segtree[i]=max(segtree[2*i+1],segtree[2*i+2]);
    }
}

void build_sum(int i,vector<int> &nums,vector<int> &segtree,int L,int R){
    if(L==R){
        segtree[i]=nums[L];
    }
    else{
        int mid=(L+R)/2;
        build_sum(2*i+1,nums,segtree,L,mid);
        build_sum(2*i+2,nums,segtree,mid+1,R);
        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
    }
}

int find_sum(int i,int a,int b,vector<int> &segtree,int L,int R){
    if(a>R || b<L){
        return 0;
    }
    if(a<=L && b>=R){
        return segtree[i];
    }
    int mid=(L+R)/2;
    int fromleft=find_sum(2*i+1,a,b,segtree,L,mid);
    int fromright=find_sum(2*i+1+2,a,b,segtree,mid+1,R);
    return fromleft+fromright;
}

void update_sum(int i,int L,int R,int idx,int val,vector<int> &segtree){
    if(L==R){
        segtree[i]+=val;
    }
    else{
        int mid=(L+R)/2;
        if(idx<=mid){
            update_sum(2*i+1,L,mid,idx,val,segtree);
        }
        else{
            update_sum(2*i+2,mid+1,R,idx,val,segtree);
        }
        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
    }
}

int main(){
    int n,val;
    cout << "Enter number of Elements: ";
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin >> val;
        nums.push_back(val);
    }
    int a,b;
    int idx,v;
    vector<int> segtree(4*n);

    build_max(0,nums,segtree,0,n-1); // starting node(0), main array, segment tree array, starting and ending range of array

    cout << "Enter starting and ending point of serach for max element: "; // input for query (indexes)
    cin >> a >> b;
    cout << "Max element in range: " << a << "-" << b << ": " << find_max(0,a,b,segtree,0,n-1);

    cout << "Enter index where changes are to be made: ";
    cin >> idx;
    cout << "Enter increment: ";
    cin >> v;
    update_max(0,0,n-1,idx,v,segtree); // current node index, lower and upper bounds, index to make changes at, change to increment, segtree

    build_sum(0,nums,segtree,0,n-1);

    cout << "Enter starting and ending point to find sum of elements in that range: "; // input for query (indexes)
    cin >> a >> b;
    cout << "Sum of elements in range: " << a << "-" << b << ": " << find_sum(0,a,b,segtree,0,n-1);

    cout << "Enter index where changes are to be made: ";
    cin >> idx;
    cout << "Enter increment: ";
    cin >> v;
    update_sum(0,0,n-1,idx,v,segtree);
    
    return 0;
}