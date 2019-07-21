#include <bits/stdc++.h>
using namespace std;
#define V 7
int graph[V][V];
int parent[V];
int rGraph[V][V];
bool bfs(int s, int t)
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        printf("u =%d\n",u);
        q.pop();

        for (int v=1; v<=V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                printf("parent[%d] =%d\n",v,u);
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

int fordFulkerson(int s, int t)
{
    int u, v;
    for (u = 1; u <= V; u++){
        for (v = 1; v <= V; v++)
            {

             rGraph[u][v] = graph[u][v];
             printf("rGraph[%d][%d] =%d\n",u,v,rGraph[u][v]);
            }}



    int max_flow = 0;
    while (bfs(s,t))
    {

        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            printf("..u=%d..\n",u);
            path_flow = min(path_flow, rGraph[u][v]);
            printf("path_flow = %d..\n",path_flow);
        }


        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            printf("..rGraph[%d][%d]...=%d\n",u,v,rGraph[u][v]);
            rGraph[v][u] += path_flow;
            printf("!!!rGraph[%d][%d]!!! =%d\n",v,u,rGraph[v][u]);
        }

        max_flow += path_flow;
        printf("max_flow =%d\n",max_flow);
    }

    return max_flow;
}

int main()
{
   int n, m, s, t;
   int tes;

   cin >> n >> s >> t >> m;
   memset(graph, 0, sizeof graph);
   for(int i = 0; i < m; i++)
   {
       int a, b, w;
       cin >> a >> b >> w;
       graph[a][b] += w;
       //graph[b][a] += w;

   }

   cout<<fordFulkerson(s,t)<< endl;

}
/*
#include <bits/stdc++.h>
using namespace std;
vector < pair < int, int > > gg[103];
int arr[103][103];
int n, src, sink;
int par[105];
bool bfs ()
{
    bool visit[103];
    memset(visit, false, sizeof visit);

    stack <int> q;

    q.push(src);

    int ff;
    visit[src] = true;
    while(!q.empty())
    {
        ff = q.top();
        q.pop();

        for(int i = 0; i < gg[ff].size(); i++)
        {
            int xx = gg[ff][i].first;

            if(visit[xx] == false && arr[ff][xx] > 0)
            {
                visit[xx] = true;
                par[xx] = ff;
                q.push(xx);
            }
        }
    }

    return visit[sink] == 1;

}
int main()
{
    int m;
    int tes;

    memset(arr, 0, sizeof arr);
    cin >> n >> src >> sink >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        arr[a][b] += cost;
        arr[b][a] += cost;
        gg[a].push_back(make_pair(b, cost));
        gg[b].push_back(make_pair(a, cost));
    }

    int res = 0, flow;
    while(bfs())
    {
        cout<<"Yes" << endl;
        int p,k = sink;
        flow = 999999999;
        while(k != src)
        {
            p = par[k];
            flow = min(flow,arr[k][p]);
            k =par[k];
        }
        k = sink;
        while(k != src)
        {
            p = par[k];
            arr[k][p] -= flow;
            arr[p][k] -= flow;
            k = par[k];
        }

        res += flow;
    }
    cout<< res << endl;
}
*/
/**
6 1 6 7
1 2 2
1 3 5
2 5 1
5 6 4
3 4 3
2 4 3
4 6 4
**/
/*
6 1 6 10
1 2 16
1 3 13
2 3 10
3 2 4
2 4 12
3 5 14
4 3 9
4 6 20
5 4 7
5 6 4
*/
