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
#include <set>

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

int T, N, total;
int step[100010];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &total);
		for(int i = 0; i < N; i++) scanf("%d", &step[i]);
		sort(step, step + N);

		int ans = 2*INF;
		for(int i = 0; i < N; i++) {
			int langkah = total / step[i];
			int sisa = total % step[i];

			if(sisa) {
				int idx = lower_bound(step, step + i, sisa) - step;
				langkah += (step[idx] == sisa) ? 1 : 2;
			}

			ans = min(ans, langkah);
		}
		printf("%d\n", ans);
	}
	return 0;
}

