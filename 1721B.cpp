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

int T, R, C, lr, lc, d;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d %d", &R, &C, &lr, &lc, &d);

		bool blockS = false, blockF = false, blockLR = false, blockTD = false;
		if((lr - d <= 1) && (lc - d <= 1)) blockS = true;
		if((lr + d >= R) && (lc + d >= C)) blockF = true;
		if((lr - d <= 1) && (lr + d >= R)) blockLR = true;
		if((lc - d <= 1) && (lc + d >= C)) blockTD = true;

		printf("%d\n", (blockS || blockF || blockLR || blockTD) ? -1 : R + C - 2);
	}
	return 0;
}

