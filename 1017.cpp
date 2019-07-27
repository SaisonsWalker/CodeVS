#include <bits/stdc++.h>
using namespace std;
long long d[40][50][7];
int n, a[50];
long long D(int l, int r, int k) {
	long long ret, tmp;
	if (k == 0) {
		ret = 0;
		for (int i = l; i <= r; i++) {
			ret = ret * 10 + a[i];
		}
	}
	else {
		ret = 0;
		tmp = 0;
		for (int i = l; i <= r - k; i++) {
			tmp = tmp * 10 + a[i];
			ret = max(ret, tmp * D(i + 1, r, k - 1));
		}
	}
	return ret;
}
int main() {
	int k;
	string S;
	scanf("%d %d", &n, &k);
	cin>>S;
	for (int i = 0; i < S.size(); i++) {
		a[i] = S[i] - '0';
	}
	printf("%lld", D(0, n-1, k));
	return 0;
}
