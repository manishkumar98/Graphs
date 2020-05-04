
/*
Given a tree T, your task is print the nodes belonging to the K th level from the root, i.e. at
a distance K from the root node. It is given that the root node is always numbered 0 and
considered as level 0. Assume that every non-root node is reachable from the root.
Input
The first line of input contains a single integer N (1 ≤ N ≤ 10 3 ) denoting the number of vertices
in the given tree T, which are labeled from 0 to N − 1, with 0 being the label of the root. The
next line contains a sequence of N-1 space-separated integers P i (1 ≤ i ≤ N − 1) denoting that
the parent of i th vertex is P i . The third and last line contains a single integer K (1 ≤ K ≤ 10 3 ),
denoting the level at which the nodes have to be found.
Output
In the first line print the number of nodes present in the K th level and in the second line, print
the nodes themselves in ascending order. If no nodes are present in the K th level, i.e. all nodes
are at a distance less than K from the root, just print -1.
input
17
0 14 0 0 0 1 4 5 5 9 5 3 6 12 4 0
2
output
7
6 7 8 9 11 12 15
input
15
0 1 1 0 4 4 2 2 3 3 5 5 6 6
4
output
-1


*/

#include <stdio.h>
#include <stdlib.h>
int queue[100000],a1[1000000],v[1000000],p[100000],k,n,front =0,rear = -1;
int pop()
{
    return queue[front++];
}
void push(int v)
{
    queue[++rear]= v;
}
int notempty()
{
    if( rear<front)
        return 0;
    return 1;
}
int comp(const void * a , const void * b )
{
    return (*(int *)a) > (*(int * )b);
}
void bfs()
{
    push(0);
    push(-1);
    while ( notempty() )
    {
        int a = pop();
        if( a== -1 && !notempty())
            break;
        if( a == -1)
        {
            push(-1);
            k--;
            if( k== 0 )
            {
                int j= 0;
                for( int i = front;i<=rear-1;i++)
                    p[j++]=queue[i];
                qsort(p,j,sizeof(int),comp);
                for( int i = 0;i<j;i++ )
                    printf("%d ",p[i]);
                return ;
            }
            continue;
        } 
        for( int i = 0 ;i<n-1;i++)
        {
            if( a1[i] == a && !v[i])
            {

                v[i] = 1;
                push(i+1);
            }
        }
        for( int i =0 ;i<30 ;i++ )
            printf("%d ",queue[i]);
        printf("\n");
    }
    printf("-1");
}
int main()
{
    scanf("%d",&n);
    for( int i =0 ;i<n-1;i++)
        scanf("%d",&a1[i]);
    scanf("%d",&k);
    bfs();
}
