#include <bits/stdc++.h>
using namespace std;
vector <int> node[101];
#define pb push_back
int L[100];
int T[100];
int P[101][22];
void dfs(int from, int u, int dep)
{
    T[u] = from;
    //printf(" T[%d]= %d\n",u,T[u]);
    L[u] = dep;
   //  printf(" L[%d]= %d\n",u,L[u]);

    for(int i = 0; i < node[u].size(); i++)
    {
        int v = node[u][i];
      //   printf("v= %d\n",v);
        if(v == from)
            continue;
        dfs(u, v, dep + 1);
    }
}
int lca_query (int N, int p, int q)  // N= Number of vertex
{
    int tmp, log,i;
    if(L[p] < L[q])
    {
        tmp = p;
        p = q;
        q =tmp;
    }
    printf("P=%d  q= %d\n",p,q);
    log = 1;
    while(1)
    {
        int next = log + 1;
        if((1<<next)>L[p])
            break;
        log++;
    }
    printf("log = %d \n",log);
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])//for same level, go to 2^ith parent
            {
                p = P[p][i];
               // printf("...P=%d \n",P[p][i]);
            }

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
           {

            p = P[p][i], q = P[q][i];  //taking both p anq till the parent is same
          // printf("p =%d &&& q =%d \n",p,q);
           }
    return T[p];
}
void lca_init(int N)
  {
      memset (P,-1,sizeof(P));
      int i, j;
       for (i = 0; i < N; i++)
          {
              P[i][0] = T[i];
          //printf("..P[%d][0]= %d\n",i,P[i][0]);
          }

for (j = 1; 1 << j < N; j++)  //2^j এর মান যদি N এর ছোট না হয় তাহলে নতুন কোনো প্যারেন্ট পাবার সম্ভাবনা নেই, তাই লুপ চলবে (1<<j) বা 2^j যতক্ষণ N এর ছোট হবে।
    for (i = 0; i < N; i++)
        if (P[i][j - 1] != -1)
        {

        P[i][j] = P[P[i][j - 1]][j - 1];//P[i][j]=P[P[i][j – 1]][j – 1] যেখানে P[i][j – 1] হলো j-1 তম প্যারেন্ট।
   // printf("%d\n",P[P[i][j - 1]][j - 1]);
    //printf("P[%d][%d]= %d\n",i,j,P[i][j]);
    }
 }
int main()
{

  node[0].pb(1);

	node[0].pb(2);
	node[2].pb(3);
	node[2].pb(4);
	node[1].pb(5);
	node[1].pb(6);
	node[6].pb(7);
	dfs(0, 0, 0);
	lca_init(8);
	printf( "%d\n", lca_query(8,5,4));
	return 0;
}
