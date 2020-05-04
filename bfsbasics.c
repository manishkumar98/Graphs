#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
	for (i = 1; i <= n; i++) {
		if (a[v][i] && !visited[i])
			q[++r] = i;
		if (f <= r) {
			visited[q[f]] = 1;
			bfs(q[f++]);
		}

	}


}

int main() {
	int v;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		q[i] = 0;
		visited[i] = 0;

	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d", &v);
	bfs(v);
	for (i = 1; i <= n; i++) {
		if (visited[i]) {
			printf("%d", i);
		}
		else {
			printf("BFS NOT POSSIBLE \n");
			break;
		}
	}
}