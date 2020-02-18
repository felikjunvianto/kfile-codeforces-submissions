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
#include <set>
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

set<LL> badNum;
LL B, Q, L;
int M;

int main() {
	scanf("%I64d %I64d %I64d %d", &B, &Q, &L, &M);

	badNum.clear();
	for(int i = 0; i < M; i++) {
		LL bad;
		scanf("%I64d", &bad);
		badNum.insert(bad);
	}
	
	// case 1: B = 0, you will write 0 only
	if(B == 0LL) {
		bool isBad0 = badNum.count(0LL) != 0;
		printf("%s\n", isBad0 ? "0" : "inf");
		return 0;
	}

	// case 2: Q = 0, you will write B, 0, 0, 0, ....
	if(Q == 0LL) {
		bool isBad0 = badNum.count(0LL) != 0;
		bool isBadB = badNum.count(B) != 0;

		if(isBad0 && isBadB) printf("0\n"); else
			if(isBad0 && !isBadB) printf("%d\n", abs(B) <= L ? 1 : 0); else
				printf("%s\n", abs(B) <= L ? "inf" : "0");

		return 0;
	}

	// case 3: Q = 1, you will write B only
	if(Q == 1LL) {
		bool isBadB = badNum.count(B) != 0;

		if(isBadB) printf("0\n"); else
			printf("%s\n", abs(B) <= L ? "inf" : "0");

		return 0;
	}

	// case 4: Q = -1, you will write B and -B alternately
	if(Q == -1LL) {
		bool isBadB    = badNum.count(B) != 0;
		bool isBadMinB = badNum.count(-B) != 0;

		if(isBadB && isBadMinB) printf("0\n"); else
			printf("%s\n", abs(B) <= L ? "inf" : "0");

		return 0;
	}

	// case 5: else, you will reach convergence
	int ans = 0;
	LL now = B;
	while(abs(now) <= L) {
		if(badNum.count(now) == 0) ans++;
		now *= Q;
	}

	printf("%d\n", ans);

	return 0;
}
