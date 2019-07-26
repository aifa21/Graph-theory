

#include<bits/stdc++.h>
using namespace std;
int sss=0;
int adj[100][100],dis[1000],d[100],f[100];
vector <int> node[1001];

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
    //printf("D[%d]=%d\n",u,sss);

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
          //node[a].push_back(b);
         // node[b].push_back(a);
          adj[a][b]=1;
         // adj[b][a]=1;
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
        cout<<"For Node "<<i<<"Start time = "<<d[i]<<"and Finishing time = "<<f[i]<<" \n";
    }

  }

    return 0;
}

/*
2
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
1 2
2 1

6 12
1 2
2 1
2 4
4 2
1 3
3 1
3 4
4 3
3 5
5 3
5 6
6 5

*/

