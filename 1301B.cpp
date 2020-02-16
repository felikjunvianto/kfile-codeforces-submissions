#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double> 
#define LL long long
#define INF 1000000000

using namespace std;

int T, N, a[100005], k, vmin, vmax, m;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int n = 0; n < N; n++) scanf("%d", &a[n]);

		vmin = vmax = -1;
		for(int n = 0; n < N; n++) {
			if(a[n] != -1 && ((n > 0 && a[n-1] == -1) || (n + 1 < N && a[n+1] == -1))) {
				if(vmin == -1 || vmin > a[n]) vmin = a[n];
				if(vmax == -1 || vmax < a[n]) vmax = a[n];
			}
		}
		
		k = (vmin + vmax) / 2;
		if(k == -1) k = 0;
		for(int n = 0; n < N; n++) if (a[n] == -1) a[n] = k;

		m = 0;
		for(int n = 1; n < N; n++) m = max(m, abs(a[n-1] - a[n]));

		printf("%d %d\n", m, k);
	}

	return 0;
}

