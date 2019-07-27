#include <bits/stdc++.h>
using namespace std;
int a[55][55], m, n;
int d[111][55][55];
int D(int s, int ma, int mb) {
	if (d[s][ma][mb] == 0) {
		if (ma > 1) {
			if (mb > 1) {
				d[s][ma][mb] = max(d[s][ma][mb], D(s-1, ma-1, mb-1));
			}
			if (ma != mb + 1) {
				d[s][ma][mb] = max(d[s][ma][mb], D(s-1, ma-1, mb));
			}
		}
		if (ma < s - 1) {
			if (mb > 1) {
				d[s][ma][mb] = max(d[s][ma][mb], D(s-1, ma, mb-1));
			}
			d[s][ma][mb] = max(d[s][ma][mb], D(s-1, ma, mb));
		}
		d[s][ma][mb] += a[ma][s-ma] + a[mb][s-mb];
	}
	return d[s][ma][mb];
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			for (int k = 1; k < j; k++) {
				d[i+j][i][i+k] = 0;
			}
		}
	}
	printf("%d", D(m + n - 1, m, m - 1));
	return 0;
}
