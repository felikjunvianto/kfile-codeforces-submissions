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

int T, N, D;
int hay[111];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &D);
		for(int i = 0; i < N; i++) scanf("%d", &hay[i]);

		for(int i = 1; i < N && D; i++) {
			if(!hay[i]) continue;

			int pindah = min(D / i, hay[i]);
			hay[0] += pindah;
			D -= pindah * i;
		}

		printf("%d\n", hay[0]);
	}
	return 0;
}
