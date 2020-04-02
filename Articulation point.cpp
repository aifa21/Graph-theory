#include <bits/stdc++.h>
using namespace std;
int dis[1000];int low[1000];bool visit[1000];int parent[10000];
vector <int> node[1000];vector<int> ap;
int timer;
void dfs(int u){
    dis[u] = low[u] = ++timer;
    printf("DIS[%d]= %d   LOW[%d]=%d\n",u,timer,u,timer);
    visit[u] = true;
    int v;  int children = 0;
    for(int i = 0; i < node[u].size(); i++){
        v = node[u][i];
        printf("v=%d\n",v);
        if(!visit[v]){
            children++;
            printf("..CHILDREN = %d \n",children);
            parent[v] = u;
             printf("..PARENT[%d]..= %d\n",v,u);
            dfs(v);
            /// if backedge is found
   low[u] = min(low[u], low[v]);
printf("!!!!!!!LOW[%d] = %d\n",u,low[u]);
            /// special condition , if u is root  and u has many child , then u is AP
        if(parent[u] == -1 && children > 1)
        {
          cout<<"  apapapapa  = "<<u<<endl;

        ap.push_back(u);
        }
            /// if root has not many child
   if(parent[u] != -1 && low[v] >= dis[u])
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


/*
#include <bits/stdc++.h>

#define pii             pair <int,int>
#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define MP              make_pair
#define db              double
#define ll              long long
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define VI              vector <int>
#define DBG             pf("Hi\n")
#define MOD             100007
#define MAX             100007
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long


using namespace std;

vector<int>graph[MAX];
int n,m,cnt;
bool visited[MAX],artpoint[MAX];
int back_edge[MAX],dis[MAX],degroot,dfsnum,root;

void Find_Art(int u)
{
    visited[u]=1;
    dfsnum++;
    back_edge[u]=dis[u]=dfsnum;
    for(i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!visited[v])
        {
            Find_Art(v);
            if(u==root)
            {
                degroot++;
                if(degroot>=2)
                {
                    artpoint[root]=1;
                }
            }

            back_edge[u]=min(back_edge[u],back_edge[v]); // if backedge is found

            if(back_edge[v]>=dis[u] && u!=root)
            {
                artpoint[u]=1;
            }

        }
        else
            back_edge[u]=min(back_edge[u],dis[v]);//there is a backedge
    }
}

void allclear()
{
    for(i=0;i<n+5;i++)
    {
        graph[i].clear();
        visited[i]=0;
        artpoint[i]=0;
        back_edge[i]=0;
        dis[i]=0;
    }
    cnt=dfsnum=degroot=0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        allclear();
        int a,b;
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        root=1;
        Find_Art(1);

        for(i=1;i<n+1;i++)
        if(artpoint[i])
        {
            //cout<<"i="<<i<<endl;
            cnt++;}

        cout<<cnt<<endl;
    }
    return 0;
}
*/
