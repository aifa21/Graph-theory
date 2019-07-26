#include<bits/stdc++.h>
using namespace std;
int sss=0;
int adj[100][100],dis[100],d[100],f[100];


void initialization()
{
    int k,j;
    for(k=0; k<100; k++)
    {
        for(j=0; j<100; j++)
        {
            adj[k][j]=0;
        }
    }

}
void dfs(int u,int n)
{
    int v;
    dis[u] = 1;
   sss=sss+1;
    d[u]=sss;


    for(int i = 1; i <=n ; i++)
    {
        if(adj[u][i]==1){

        if(dis[i] == -1)
        {
            dfs(i,n);
        }
        }
    }

   sss=sss+1;
   f[u]=sss;
 //printf("f[%d] = %d\n",u,sss);

}

int main()
{
//initialization();
int n,m;
  while(cin >> n >> m)
  {
      initialization();
      memset(dis, -1 ,sizeof dis);
      for(int i = 0; i < m ;i++)
      {
          int a, b;

          cin >> a >> b;

          adj[a][b]=1;

      }


      for(int i = 1; i <= n; i++)
      {
          if(dis[i] == -1)
          {
              dfs(i,n);

          }
      }
      for(int i=1; i<=n; i++)
    {
        cout<<"For Node "<<i<<":"<<endl;
        cout<<" Start time and Finishing time = "<<d[i]<<"/"<<f[i]<<" \n";
    }

  }

    return 0;
}
