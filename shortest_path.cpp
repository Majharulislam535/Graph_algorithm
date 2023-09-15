#include<bits/stdc++.h>

using namespace std;

const int N= 1e5+5;
vector<int> adj[N];
bool visited[N];
int level[N];
int pare[N];


void bfs(int s){
     queue<int>q;
     q.push(s);
     visited[s]=true;
     level[s]=0;
     pare[s]=-1;

     while(!q.empty()){
          int u=q.front();
          q.pop();

          for(int v:adj[u]){
             if(visited[v])continue;
             q.push(v);
             visited[v]=true;
             level[v]=level[u]+1;
             pare[v]=u;
          }
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

      int s,d;
      cin>>s>>d;
      bfs(s);


      vector<int> path;

      int current = d;

      while(current != -1){
          path.push_back(current);
          current=pare[current];
      }

      reverse(path.begin(),path.end());

      for(int i:path){
         cout<<i<<" ";
      }



    return 0;
}



