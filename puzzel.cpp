#include<bits/stdc++.h>
using namespace std;

int main(){
cout<<"hello";
vector<vector<int>>v{{0,-1},{0,1},{1,0},{-1,0}};
vector<vector<vector<int>>>states;
queue<vector<vector<vector<int>>>>q;
vector<vector<int>>initial{{2,3,4},{1,8,7},{6,5,0}};
vector<vector<int>>goal{{1,2,3},{4,5,6},{7,8,0}};
vector<vector<vector<int>>>temp;
temp.push_back(initial);
q.push(temp);
while(!q.empty()){
    cout<<"hello";
    temp=q.front();
    if(temp[temp.size()-1]==goal){
        int count=1;
        for(auto i:temp){
            cout<<"state "<<count++<<':'<<'\n';
            for(auto j:i){
                for(auto k:j){
                    cout<<k<<'\t';
                }
                cout<<'\n';
            }
            cout<<'\n';
        }
        break;
    }
    bool present=false;
    for(auto i:states){
        if(i==temp[temp.size()-1])
            present=true;
    }
    if(!present){
        states.push_back(temp[temp.size()-1]);
        vector<vector<int>>state=temp[temp.size()-1];
        for(int i=0;i<state.size();i++){
            for(int j=0;j<state.size();j++){
                if(state[i][j]==0){
                    for(auto k:v){
                        if(i+k[0]>=0 && j+k[1]<3){
                            state[i][j]=state[i+k[0]][j+k[1]];
                            state[i+k[0]][j+k[1]]=0;
                            temp.push_back(state);
                            q.push(temp);
                            temp.pop_back();
                        }
                    }
                }
            }
        }
    }
}
return 0;
}