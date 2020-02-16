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

struct cust {
	int waktu, tempLow, tempHigh;
};

int T, N, t, templ, temph;
vector<cust> req;

bool isIntersect(int l1, int h1, int l2, int h2) {
	int ll = max(l1, l2);
	int hh = min(h1, h2);
	return hh >= ll;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		req.clear();

		scanf("%d %d", &N, &t);
		int posLow = t, posHigh = t, nowT = 0;

		for(int i = 0; i < N; i++) {
			scanf("%d %d %d", &t, &templ, &temph);
			req.pb((cust) {t, templ, temph});
		}

		bool bisa = true;
		for(int i = 0; i < req.size() && bisa; i++) {
			cust next = req[i];
			int dur = next.waktu- nowT;
			int movLow = min(dur, abs(posLow - next.tempLow));
			int movHigh = min(dur, abs(posHigh - next.tempHigh));

			int nextPosLow  = posLow <= next.tempLow   ? posLow + movLow   : posLow - movLow;
			int nextPosHigh = posHigh <= next.tempHigh ? posHigh + movHigh : posHigh - movHigh;

			bisa = isIntersect(nextPosLow, nextPosHigh, next.tempLow, next.tempHigh);
			posLow = max(nextPosLow, next.tempLow);
			posHigh = min(nextPosHigh, next.tempHigh);
			nowT = next.waktu;
		}

		printf("%s\n", bisa ? "YES" : "NO");
	}
	return 0;
}

