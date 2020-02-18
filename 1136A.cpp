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

int N, K;
PII ch[111];

int main() {
	scanf("%d", &N);
	for(int n = 1; n <= N; n++) scanf("%d %d", &ch[n].fi, &ch[n].se);
	scanf("%d", &K);

	int ans = 1;
	while(ch[ans].se < K) ans++;
	printf("%d\n", N - ans + 1);

	return 0;
}

