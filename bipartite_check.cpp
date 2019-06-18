
#include <bits/stdc++.h>
using namespace std;
vector <int> node[10001];



int dis[10001];
bool  biparte_chek(int src)
{

    dis[src] = 0;
    queue <int> q;
    q.push(src);
    int c= 0 , v , u;
    bool f = true;

    while(!q.empty() && f)
    {
        u = q.front();
       // cout<<"U "<<u<<endl;
        q.pop();

        for(int i = 0; i < node[u].size(); i++)
        {
             v = node[u][i];
             //cout<<"V "<<v<<endl;

            if(dis[v] == -1)
            {


                dis[v] = dis[u] + 1;
                //

                q.push(v);
            }
            if(dis[u] == dis[v]){

            f = false;
            break;
         }

        }

    }
    return f;
}
int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {

        if(n == 0)
            break;
        memset(dis ,-1 , sizeof dis);
        int a , b;
        while(scanf("%d %d", &a ,&b))
        {
            if(a == 0 && b == 0) break;
            node[a].push_back(b);
            node[b].push_back(a);
        }
        bool k=  biparte_chek(1);
        if(k)
            printf("YES\n");
        else

            printf("NO\n");
       for(int i = 1; i <= n; i++)
        node[i].clear();
}
return 0;
}
