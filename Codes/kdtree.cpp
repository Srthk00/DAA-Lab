#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class kdtree{
    private:
        int k;
        struct node{
            vector<int> points;
            node *left,*right;
            node(vector<int> points){
                this->points=points;
                left=right=nullptr;
            }
        };

        node *root=nullptr;

        node *insertnode(node *root,vector<int> &points,int depth){
            if(root==nullptr){
                return new node(points);
            }
            int currdepth=depth%k;
            if(root->points[currdepth]>points[currdepth]){
                root->left=insertnode(root->left,points,depth+1);
            }
            else{
                root->right=insertnode(root->right,points,depth+1);
            }
            return root;
        }

        bool issame(vector<int> &p1,vector<int> &p2){
            for(int i=0;i<p1.size();i++){
                if(p1[i]!=p2[i]){return false;}
            }
            return true;
        }

        bool searchnode(node *root,vector<int> &points,int depth){
            if(root==nullptr){
                return false;
            }
            if(issame(points,root->points)){
                return true;
            }
            int currdepth=depth%k;
            if(root->points[currdepth]>points[currdepth]){
                return searchnode(root->left,points,depth+1);
            }
            else{
                return searchnode(root->right,points,depth+1);
            }
        }

    public:
        void set_dimension(int x){
            k=x;
        }

        void insert(vector<int> &points){
            root=insertnode(root,points,0);
        }

        bool search(vector<int> &points){
            return searchnode(root,points,0);
        }

        void printlevelorder(){
            if(root==nullptr){
                cout << "The Tree is Empty..." << endl;
            }
            queue<node*> que;
            que.push(root);
            while(!que.empty()){
                int s=que.size();
                while(s-->0){
                    node *temp=que.front();
                    que.pop();
                    cout << "[";
                    for(int i=0;i<k;i++){
                        cout << temp->points[i] << ",";
                    }
                    cout << "]";
                    if(temp->left){
                        que.push(temp->left);
                    }
                    if(temp->right){
                        que.push(temp->right);
                    }
                }
                cout << endl;
            }
        }
};

int main(){
    int k;
    cout << "Enter Dimension of Tree: ";
    cin >> k;
    kdtree *obj=new kdtree();
    obj->set_dimension(k);
    int choice;
    while(true){
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print Tree" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:{
                vector<int> points(k);
                cout << "Enter point to insert: " << endl;
                for(int i=0;i<k;i++){
                    cin >> points[i];
                }
                obj->insert(points);
                cout << "Point Inserted..." << endl;
                break;
            }
            case 2:{
                vector<int> points(k);
                cout << "Enter point to Search: " << endl;
                for(int i=0;i<k;i++){
                    cin >> points[i];
                }
                if(obj->search(points)){
                    cout << "Point is Present..." << endl;
                }
                else{
                    cout << "Point is Not Present..." << endl;
                }    
                break;
            }
            case 3:{
                obj->printlevelorder();
                break;
            }
            case 4:{
                cout << "Ending Program..." << endl;
                exit(0);
            }
            default:{
                cout << "Invalid Option..." << endl;
                break;
            }
        }
    }
    return 0;
}