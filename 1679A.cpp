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

int T;
LL N;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%I64d", &N);
		
		if(N % 2LL != 0 || N < 4LL) {
			printf("-1\n");
			continue;
		}

		LL pairs = N / 2LL;
		LL smallest = pairs / 3LL;
		if(pairs % 3LL != 0) smallest++;

		LL biggest = pairs / 2LL;
		printf("%I64d %I64d\n", smallest, biggest);
	}
	return 0;
}

