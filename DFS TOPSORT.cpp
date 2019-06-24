#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int dis[10005];
vector <int> node[10005];
vector <int> vc;
int n;
void dfs_sort(int u) {
  dis[u] = 1;
    for(int i = 0; i < node[u].size(); i++){
        int v = node[u][i];
      //  cout<<"V= "<<v<<endl;
        if(dis[v] == 0){
            dfs_sort(v);
            }}
          //  cout<<"...U= "<<u<<endl;
    vc.push_back(u);//8 2 6 1 3 9 5 4 7 10
}
void dfs(int u){
    dis[u] = 1;
    for(int i = 0; i < node[u].size(); i++){
        int q=node[u][i];
        cout<<"Q="<<q<<endl;
        if(dis[q] == 0){
            dfs(q);}}}
int main(){
    int o=0,t;
    cin>>t;
  while(t--)  {  o++;
     int n,m;
     cin>>n>>m;
      for(int i = 0; i < m ;i++){
          int a, b;
          cin >> a >> b;
          node[a].pb(b);  }
      memset(dis, 0 ,sizeof dis);
    for(int i = 1; i <= n; i++) {
          if(dis[i] == 0) {
              dfs_sort(i);
              }
              }
      reverse(vc.begin(),vc.end());
      for(int i=0;i<vc.size();i++)
      {
          cout<<vc[i]<<" ";
      }
      cout<<endl;
       /*memset(dis, 0 ,sizeof dis);
       int c=0;
       for(int i = 0; i < vc.size(); i++){
           if(dis[vc[i]] == 0){
               c++;
               dfs(vc[i]);}}
cout<<"Case "<<o<<": "<<c<<endl;*/
      for(int i=1;i<=n;i++){node[i].clear();}
      vc.clear();}
    return 0;}
/*
4
5 4
1 2
1 3
3 4
5 3
4 4
1 2
1 3
4 2
4 3
*/
/*
3
10 13
1 2
1 6
2 8
4 3
4 5
4 8
4 9
5 9
7 1
7 2
7 3
9 3
10 5

2
6 6
5 2
5 0
4 0
4 1
2 3
3 1
*/
