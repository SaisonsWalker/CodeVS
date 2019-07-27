#include <bits/stdc++.h>
using namespace std;
long long d[60][60] = {0};
int main() {
	int m, n, sx, sy, dx, dy;
	scanf("%d %d %d %d %d %d", &m, &n, &sx, &sy, &dx, &dy);
	d[sx][sy] = 1;
	for (int i = sx + 1; i < dx; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = d[i-2][j-1] + d[i-2][j+1] + d[i-1][j+2];
			if (j > 1) {
				d[i][j] += d[i-1][j-2];
			}
		}
	}
	d[dx][dy] = d[dx-2][dy-1] + d[dx-2][dy+1] + d[dx-1][dy+2];
	if (dy > 1) {
		d[dx][dy] += d[dx-1][dy-2];
	}
	printf("%lld\n", d[dx][dy]);
	return 0;
}
