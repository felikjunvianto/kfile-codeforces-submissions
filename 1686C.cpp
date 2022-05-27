#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1e9

using namespace std;

int T, N, a[100010], ans[100010];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &a[i]);

		if(N % 2 == 1) {
			printf("NO\n");
			continue;
		}

		sort(a, a + N);

		int mid = N / 2, ptr = 0;
		for(int i = 0; i * 2 < N; i++) {
			ans[ptr++] = a[i];
			ans[ptr++] = a[i + mid]; 
		}

		bool oke = true;
		for(int i = 0; i < N && oke; i++) {
			int prev = ans[(i - 1 + N) % N], next = ans[(i + 1) % N];

			if(!((prev < ans[i]) && (ans[i] > next) || (prev > ans[i]) && (ans[i] < next))) oke = false;
		}

		printf("%s\n", oke ? "YES" : "NO");
		if(oke) for(int i = 0; i < N; i++) printf("%d%c", ans[i], i + 1 == N ? '\n' : ' ');
	}

	return 0;
}
