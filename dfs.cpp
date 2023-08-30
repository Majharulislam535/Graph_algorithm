#include<bits/stdc++.h>

using namespace std;

 const int N= 1e3+5;
 vector<int> adj[N];
 bool visited[N];

  void dfs(int u){

     visited[u]=true;
     cout<<"visited Node : "<< u<<endl;

     for(int v:adj[u]){
              if(visited[v] != true)
                dfs(v);
          }
   }

int main()
{

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }

    dfs(1);




    return 0;
}


