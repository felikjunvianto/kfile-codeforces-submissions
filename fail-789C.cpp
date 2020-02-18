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

int N;
LL a[100010], prefix[100010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%I64d", &a[i]);

	prefix[0] = 0LL;
	LL minus  = 1LL;
	for(int i = 1; i + 1 <= N; i++) {
		LL elem = abs(a[i] - a[i + 1]) * minus;
		prefix[i] = prefix[i - 1] + elem;

		minus *= -1LL;
	}

	LL ans = prefix[1];
	for(int L = 1; L < N; L++)
		for(int R = L; R < N; R++) {
			LL now = prefix[R] - prefix[L - 1];
			if((L - 1) & 1) now *= -1LL;

			// cout << L << " " << R << " " << now << endl;

			ans = max(ans, now); 
		}

	printf("%I64d\n", ans);

	return 0;
}

