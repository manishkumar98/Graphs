#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int adj[10000][10000],v[1000000],n,m;
void dfs( int s)
{
    v[s]=1;
    for (int i =0 ;i<n;i++ )
        if( adj[s][i] == 1 && !v[i] )
            dfs(i);
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i =0 ;i<m;i++ )
    {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u-1][v-1] = 1; 
    }
    int h= 1;
    for( int i =0 ;i< n; i++ )
    {
        memset(v,0,sizeof(v));
        dfs(i);
        for( int j =0 ;j<n;j++ )
        {
            if( !v[j])
            {
                h= 0 ;
                break;
            }
        }
        if(h == 1)
            printf("%d ",i+1);
        h=1;
    }

}
