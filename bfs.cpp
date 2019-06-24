#include <bits/stdc++.h>
using namespace std;
#define  unvisited -1
#define  visited 1
vector <int> node[100005];
int dis[100005];
void bfs (int src)
{
    queue <int> q;
    dis[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
       cout<<"u  >"<<u<<endl;
     //  cout<<endl;
        q.pop();
        for(int i = 0; i < node[u].size(); i++)
        {
            int v = node[u][i];
         //   cout<<"v "<<v<<endl;
        //    cout<<endl;

            if(dis[v] == unvisited)
            {
                dis[v] = dis[u] + 1;
                //cout<<"dis["<<v<<"]  "<<dis[v]<<endl;
               // cout<<endl;
                q.push(v);
            }
        }
    }
}
int main()
{
    int tes;
    cin >> tes;
    while(tes--)
    {


        memset(dis, unvisited , sizeof dis);
        int n, e;
        //cout<<"Node and edge" << endl;
        cin >> n >> e;
        for(int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            node[u].push_back(v);
            node[v].push_back(u);
        }
        int src;
      cin>>src;
        bfs(src);
        for(int i = 0; i <n; i++)
        {
            cout<<i<<" "<< dis[i] << endl;;
        }

        for(int i = 0; i < n; i++)
           {

           node[i].clear();
           }
            if(tes)
                cout<<endl;

    }
    return 0;
}
/*
2
5 5
1 2
1 3
2 3
2 4
3 4
*/
/*
4
4 3
0 1
2 1
1 3
*/
