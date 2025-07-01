#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class moalgorithm{
    private:
        vector<int> nums;
        vector<pair<int,int>> queries;
    
    public:
        moalgorithm(vector<int> &nums,vector<pair<int,int>> &queries){
            this->nums=nums;
            this->queries=queries;
        }

        vector<int> sumquery(){
            int currL=0,currR=-1;
            vector<int> result;
            int sum=0;
            for(auto &[L,R]:queries){
                while(currL<L){
                    sum-=nums[currL];
                    currL++;
                }
                while(currL>L){
                    currL--;
                    sum+=nums[currL];
                }
                while(currR>R){
                    sum-=nums[currR];
                    currR--;
                }
                while(currR<R){
                    currR++;
                    sum+=nums[currR];
                }
                result.push_back(sum);
            }
            return result;
        }

        vector<int> maxinrangequery(){
            int currL=0,currR=-1;
            vector<int> result;
            multiset<int> mset;
            for(auto &[L,R]:queries){
                while(currL<L){
                    mset.erase(mset.find(nums[currL]));
                    currL++;
                }
                while(currL>L){
                    currL--;
                    mset.insert(nums[currL]);
                }
                while(currR>R){
                    mset.erase(mset.find(nums[currR]));
                    currR--;
                }
                while(currR<R){
                    currR++;
                    mset.insert(nums[currR]);
                }
                result.push_back(*mset.rbegin());
            }
            return result;
        }

        vector<int> distinctinrangequery(){
            int currL=0,currR=-1;
            vector<int> result;
            unordered_map<int,int> map;
            int count=0;
            for(auto &[L,R]:queries){
                while(currL<L){
                    map[nums[currL]]--;
                    if(map[nums[currL]]==0){
                        count--;
                    }
                    currL++;
                }
                while(currL>L){
                    currL--;
                    map[nums[currL]]++;
                    if(map[nums[currL]]==1){
                        count++;
                    }
                }
                while(currR>R){
                    map[nums[currR]]--;
                    if(map[nums[currR]]==0){
                        count--;
                    }
                    currR--;
                }
                while(currR<R){
                    currR++;
                    map[nums[currR]]++;
                    if(map[nums[currR]]==1){
                        count++;
                    }
                }
                result.push_back(count);
            }
            return result;
        }

        // vector<pair<int,int>> maxfreqinrangequery(){
        //     int currL=0,currR=-1;
        //     vector<int> result;
        //     unordered_map<int,int> map;
        //     int maxfreq=0;
        //     for(auto &[L,R]:queries){
        //         while(currL<L){
        //             map[nums[currL]]--;
        //             if(map[nums[currL]]<maxfreq){
        //                 count--;
        //             }
        //             currL++;
        //         }
        //         while(currL>L){
        //             currL--;
        //             map[nums[currL]]--;
        //             if(map[nums[currL]]==1){
        //                 count++;
        //             }
        //         }
        //         while(currR>R){
        //             map[nums[currR]]--;
        //             if(map[nums[currR]]==0){
        //                 count--;
        //             }
        //             currR--;
        //         }
        //         while(currR<R){
        //             currR++;
        //             map[nums[currR]]++;
        //             if(map[nums[currR]]==1){
        //                 count++;
        //             }
        //         }
        //         result.push_back(count);
        //     }
        //     return result;
        // }
};

int main(){
    int n;
    cout << "Enter number of Elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: " << endl;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    vector<pair<int,int>> queries;
    cout << "Enter queries: " << endl;
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        queries.push_back({a,b});
    }
    int block=sqrt(n);
    sort(queries.begin(),queries.end(),[block](pair<int,int> &a,pair<int,int> &b){
        if(a.first/block==b.first/block){
            return a.second>b.second;
        }
        return a.first<b.first;
    });
    moalgorithm *obj=new moalgorithm(nums,queries);

    while(true){
        int choice;
        cout << endl << "1. Sum of Range" << endl;
        cout << "2. Max in Range" << endl;
        cout << "3. Distinct in Range" << endl;
        // cout << "4. Max Frequency in Range" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:{
                vector<int> result=obj->sumquery();
                for(int i=0;i<q;i++){
                    cout << "Sum in range: [" << queries[i].first << "-" << queries[i].second << "] is: " << result[i] << endl;
                }
                break;
            }
            case 2:{
                vector<int> result=obj->maxinrangequery();
                for(int i=0;i<q;i++){
                    cout << "Max in range: [" << queries[i].first << "-" << queries[i].second << "] is: " << result[i] << endl;
                }
                break;
            }
            case 3:{
                vector<int> result=obj->distinctinrangequery();
                for(int i=0;i<q;i++){
                    cout << "Distinct elements in range: [" << queries[i].first << "-" << queries[i].second << "] is: " << result[i] << endl;
                }
                break;
            }
            // case 4:{
            //     vector<pair<int,int>> result=obj->maxfreqinrangequery();
            //     for(int i=0;i<q;i++){
            //         cout << "Distinct elements in range: [" << queries[i].first << "-" << queries[i].second << "] is: " << result[i].first << "-->" << result[i].second << endl;
            //     }
            //     break;
            // }
            case 5:{
                cout << "Ending the Program..." << endl;
                exit(0);
            }
            default:{
                break;
            }
        }
    }
    return 0;
}