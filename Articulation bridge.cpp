#include <bits/stdc++.h>
using namespace std;
int dis[1000];int low[1000];bool visit[1000];int parent[10000];
vector <int> node[1000];vector<int> ap;
int timer;
void dfs(int u){
    dis[u] = low[u] = ++timer;
    printf("DIS[%d]= %d   LOW[%d]=%d\n",u,timer,u,timer);
    visit[u] = true;
    int v;
    for(int i = 0; i < node[u].size(); i++){
        v = node[u][i];
        printf("v=%d\n",v);
        if(!visit[v]){

            parent[v] = u;
             printf("..PARENT[%d]..= %d\n",v,u);
            dfs(v);
            /// if backedge is found
   low[u] = min(low[u], low[v]);
printf("!!!!!!!LOW[%d] = %d  v=%d\n",u,low[u],v);
            /// special condition , if u is root  and u has many child , then u is AP

            /// if root has not many child
   if(low[v] > dis[u])
        {
            cout<<".......apapapapa......."<<u<<"............"<<v<<endl;

        ap.push_back(u);
        } }
        else if(v != parent[u])
            low[u] = min(low[u], dis[v]);
            printf("...LOW[%d]... = %d\n",u,low[u]);
    }
}
int main()
{
    memset(parent, -1, sizeof parent);
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }


    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == false)
            dfs(i);
    }
int cnt=0;

    for(int i = 0; i < ap.size(); i++)
        cout<< ap[i] << " ";


     //   cout<<cnt<<endl;

    cout<< endl;
}
/*
8 9
1 2
1 3
2 3
3 4
4 5
5 6
5 7
6 7
6 8

4 3
1 2
2 3
3 4

5 5
1 2
1 3
2 3
1 4
4 5
*/
