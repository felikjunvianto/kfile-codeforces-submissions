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

int T, N, grain;
int a, b, c, d;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d %d", &N, &a, &b, &c, &d);
		int minGW = N * (a - b), maxGW = N * (a + b);
		int minTW = c - d, maxTW = c + d;
		// cout << minGW << " " << maxGW << " " << minTW << " " << maxTW << endl;
		bool cons = (minTW <= maxGW) && (minGW <= maxTW);

		printf("%s\n", cons ? "Yes" : "No");
	}
	return 0;
}
