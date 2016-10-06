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

int N, P[111], Q[111], ans;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d %d", &P[i], &Q[i]);
	
	ans = 0;
	for(int i = 0; i < N; i++) if(P[i] + 2 <= Q[i]) ans++;
	printf("%d\n", ans);
	return 0;
}

