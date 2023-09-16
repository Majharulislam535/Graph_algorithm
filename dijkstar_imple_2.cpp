#include <bits/stdc++.h>
using namespace std;



const int N=1e5+5;
const long long INF= 1e18;

vector<pair<int,int>> adj[N];

bool visited[N];

long long int d[N];

int n,m;

void dijkstra(int s){

    for(int i=1;i<=m;i++){
        d[i]=INF;
    }

    d[s] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({d[s],s});

    while(!pq.empty()){

        pair<int,int> f = pq.top();

        pq.pop();

        int selectedNode = f.second;

        if(visited[selectedNode])
        continue;
        visited[selectedNode]=true;


        for(auto pii:adj[selectedNode]){
             int edc = pii.first;
             int v = pii.second;

              if(d[selectedNode]+edc < d[v]){

                  d[v]=d[selectedNode]+edc;
                   pq.push({d[v],v});
              }

        }





    }



}


int main()
{

     cin>>n>>m;

     for(int i=0;i<m;i++){
         int u,v,w;
         cin>>u>>v>>w;

         adj[u].push_back({w,v});
         adj[v].push_back({w,u});
     }

     dijkstra(1);

     for(int i=1;i<=n;i++){
         cout<<i<< " " << d[i]<<endl;
     }




    return 0;
}
