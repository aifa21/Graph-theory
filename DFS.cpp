#include <bits/stdc++.h>

using namespace std;
int dis[10001];
vector <int> node[1001];

int p;
void dfs(int u)
{
    p++;
    //cout<<p<<endl;
    int v;
    dis[u] = 1;
    for(int i = 0; i < node[u].size(); i++)
    {
        v = node[u][i];
        if(dis[v] == -1)
        {
            dfs(v);
        }

    }


}
int main()
{
  int n , m,t,pp;
  cin>>t;
  while(t--)
  {

      memset(dis, -1 ,sizeof dis);
      cin>>n>>m;
      for(int i = 0; i < m ;i++)
      {
          int a, b;
          cin >> a >> b;
          node[a].push_back(b);
          node[b].push_back(a);
      }
      //how many components
     /* int c = 0;
      for(int i = 1; i <= n; i++)
      {
          if(dis[i] == -1)
          {
              dfs(i);
              c++;
          }
      }
      cout<<c<< endl;*/

  //components are connect or not
     /* int src;
      cin>>src;
      dfs(src);
      pp=0;
      for(int i = 1; i <= n; i++)
      {
          if(dis[i] == true)
          {
              pp++;
             // cout<<"DIS["<<i<<"] "<<"CONNECT"<<endl;
          }
         // else{
           // cout<<"DIS["<<i<<"] "<<"NOT CONNECT"<<endl;
          //}
          //cout<<pp+1;
      }
      cout<<pp+1;*/
      //maximum node
    int mx=0;
      for(int i = 1; i <= n; i++)
      {
          if(dis[i] == -1)
          {
              p=0;
              dfs(i);
              mx=max(mx,p);
          }

      }
       cout<<mx<<endl;

  }
return 0;
}
/*
6 4
1 2
1 3
3 4
5 6
1
*/
/*
10 4
2 3
4 5
4 8
5 8
1
*/
