#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int adj[10000][10000],v[1000000],n,m;
void dfs( int s ,int h )
{
    v[s]=h;
    for (int i =0 ;i<n;i++ )
        if( adj[s][i] == 1 && !v[i] )
            dfs(i,h);
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i =0 ;i<m;i++ )
    {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u-1][v-1] = 1; 
        adj[v-1][u-1] = 1;
    }
    int h= 1,ans1 = 0,ans2 = 0;
    for( int i =0 ;i< n; i++ )
    {
        if( !v[i] )
        {
            dfs(i,h);
            int o = 0;
            for( int j =0 ;j<n;j++)
                if( v[j] == h )
                    o++;
            if( o > ans1 )
            {
                ans1 = o ;
                ans2 = h;
            }
            h++;
        }
    }
    if(ans1==n)
    {
        printf("-1");
    }
    else
    {
    printf("%d\n",n-ans1);
    for (int i =0 ;i<n;i++ )
        if(v[i] != ans2)
            printf("%d ",i+1);
    }
}
