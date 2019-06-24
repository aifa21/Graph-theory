
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u, v, w;
    node(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator < (const node& p) const
    {
        return w < p.w;
    }
};
vector <node> edge;
int par[10005];
int find (int u)
{
    if(u != par[u])
        par[u] = find(par[u]);

    return par[u];
}
int krush_kal (int n)
{
    sort(edge.begin(), edge.end());
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    int cnt = 0;
    int cost = 0;
    for(int i = 0; i < (int)edge.size(); i++)
    {
        int u , v;
        u = find(edge[i].u);
        v = find(edge[i].v);

        if(u != v)
        {
            cnt++;
            par[u]=v;
            cost += edge[i].w;
            if(cnt == n - 1)
                break;
        }
    }
    return cost;
}
int main()
{
     int n, m;
    printf("Enter the node & edge:\n");
     while(cin >> n >> m)
     {
         for(int i = 0; i < m; i++)
         {
             int u, v, w;
             cin >> u >> v >> w;
             edge.push_back(node(u, v, w));
         }

         printf("The weight of the spanning tree: ");
        cout<< krush_kal(n) << endl;
        edge.clear();
     }

}

/*
   #include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}*/
/*
9 14
0 1 4
0 7 8
1 7 11
1 2 8
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
