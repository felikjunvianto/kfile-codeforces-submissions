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

const int LIM = 10000000;

int a, b, c, d, num[LIM + 10];

int main() {
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	memset(num, 0, sizeof(num));
	for(int k = 0; a * k + b <= LIM; k++) num[a * k + b]++;
	for(int k = 0; c * k + d <= LIM; k++) num[c * k + d]++;

	int ans = -1;
	for(int i = 0; i <= LIM && ans == -1; i++) if(num[i] == 2) ans = i;

	printf("%d\n", ans);
	return 0;
}

