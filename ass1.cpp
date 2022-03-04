#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

pair<vector<vector<int>>,vector<int>> create_unweighted_undirected_graph(){
    int size;
    cout<<"\nEnter the number of node in graph:";
    cin>>size;
    vector<int>node;
    vector<vector<int>>graph(size,vector<int>(size,0));
    int temp;
    bool has=false;
    for(int i=0;i<size;i++){
        cout<<"\nEnter the value of the node "<<i<<':';
        cin>>temp;
        node.push_back(temp);
        temp=0;
        cout<<"\nEnter the node to which it is connected ,for termination enter -1\n";
        while(true){
            cin>>temp;
            if(temp==-1)
                break;
            else if(temp<size && temp>=0){
                graph[i][temp]=1;
                graph[temp][i]=1;
            }
            else if(temp>size || temp<-1){
                cout<<"invalid entry";
                continue;
            }
            for(auto i:graph[i]){
                if(i==0){
                    has=true;
                    break;
                }
            }
            if(has){
                has=false;
                continue;
            }
        }
    }
    return {graph,node};
}

bool dfs(vector<vector<int>>&adj,vector<int>&node,int val){
    stack<int>st;
    vector<bool>visited(adj.size(),false);
    st.push(0);
    visited[0]=true;
    // cout<<'0'<<endl;
    while(!st.empty()){
        cout<<st.top()<<endl;
        if(node[st.top()]==val)
            return true;
        else{
            int temp=st.top();
            st.pop();
            for(int i=adj.size()-1;i>=0;i--){
                if(adj[temp][i]==1 && !visited[i]){
                    st.push(i);
                    visited[i]=true;
                    // cout<<i;
                }
            }
            // cout<<endl;
        }
    }
    return false;   
}

bool bfs(vector<vector<int>>&adj,vector<int>&node,int val){
    queue<int>st;
    vector<bool>visited(adj.size(),false);
    st.push(0);
    visited[0]=true;
    // cout<<'0'<<endl;
    while(!st.empty()){
        cout<<st.front()<<endl;
        if(node[st.front()]==val)
            return true;
        else{
            int temp=st.front();
            st.pop();
            for(int i=0;i<adj.size();i++){
                if(adj[temp][i]==1 && !visited[i]){
                    st.push(i);
                    visited[i]=true;
                    // cout<<i;
                }
            }
            // cout<<endl;
        }
    }
    return false; 
}

bool dls(vector<vector<int>>&adj,vector<int>&node,int val,int depth_limit){
    stack<pair<int,int>>st;
    vector<bool>visited(adj.size(),false);
    st.push({0,0});
    visited[0]=true;
    // cout<<'0'<<endl;
    while(!st.empty()&& depth_limit){
        if(st.top().second>depth_limit)
            break;
        cout<<st.top().first<<st.top().second<<endl;
        if(node[st.top().first]==val)
            return true;
        else{
            pair<int,int> temp=st.top();
            st.pop();
            for(int i=adj.size()-1;i>=0;i--){
                if(adj[temp.first][i]==1 && !visited[i]){
                    st.push({i,temp.second+1});
                    visited[i]=true;
                    // cout<<i;
                }
            }
            // cout<<endl;
        }
    }
    return false; 
}

bool ids(vector<vector<int>>&adj,vector<int>&node,int val,int depth_limit){
    for(int i=0;i<depth_limit;i++){
        if(dls(adj,node,val,i))
            return true;
        cout<<endl<<"iteration no:"<<i<<endl;
    }
    return false;
}
int main(){
    // pair<vector<vector<int>>,vector<int>> graph=create_unweighted_undirected_graph();

    vector<vector<int>>temp={{0,1,1,1,0},{1,0,0,0,0},{1,0,0,0,1},{1,0,0,0,0},{0,0,1,0,0}};
    vector<int>l={2,3,5,6,8};

    if(ids(temp,l,8,3))
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl;

    // if(dls(temp,l,8,2))
    //     cout<<"found"<<endl;
    // else
    //     cout<<"not found"<<endl;
    // return 0;
}