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

int T, N;
LL K, a[200010], prefsum[200010];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %I64d", &N, &K);
		for(int i = 0; i < N; i++) scanf("%I64d", &a[i]);
		sort(a, a + N);

		memset(prefsum, 0, sizeof(prefsum));
		prefsum[0] = a[0];
		for(int i = 1; i < N; i++) prefsum[i] = prefsum[i-1] + a[i];

		LL ans = 9e18;
		for(int convNum = 0; convNum < N; convNum++) {
			LL sum = prefsum[N - convNum - 1] + a[0] * convNum;
			LL curr = (LL) convNum;
			
			if(sum > K) {
				LL diff = sum - K;
				curr += (diff + convNum) / (convNum + 1);
			}

			// cout << "convNum = " << convNum << " K = " << K << " Kleft = " << Kleft << " prefsum = " << prefsum[endIdx] - prefsum[0] << " KperConv = " << KperConv << " a[0] = " << a[0] << " decNum = " << decNum << " move = " << decNum + convNum - 1 << endl;
			ans = min(ans, curr);
		}

		printf("%I64d\n", ans);
		// cout << "----------------\n";
	}
	return 0;
}

