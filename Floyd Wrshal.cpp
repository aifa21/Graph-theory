#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,mat[100][100];
   cin>>n;
   for(int k=0;k<n;k++){
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(mat[i][j]>mat[i][k]+mat[k][j])
           {
               mat[i][j]=mat[i][k]+mat[k][j];
           }
       }
   }
   }
   //cout<<mat[i][j]<<endl;
    return 0;
}
