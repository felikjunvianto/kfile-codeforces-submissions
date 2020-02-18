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

int N, M;
bool cancel, positif[10005], negatif[10005];

int main() {
	scanf("%d %d", &N, &M);
	cancel = false;

	while(M--) {
		int k, who;
		memset(positif, false, sizeof(positif));
		memset(negatif, false, sizeof(negatif));

		scanf("%d", &k);
		while(k--) {
			scanf("%d", &who);
			if(who < 0) negatif[-who] = true; else positif[who] = true;
		}

		bool aman = false;
		for(int i = 1; i <= N && !aman; i++)
			if(positif[i] && negatif[i]) aman = true;

		if(!aman) {
			cancel = true;
			break;
		}
	}

	printf("%s\n", cancel ? "YES" : "NO");
	return 0;
}

