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

int prefsum[100005], N, M, C, T, V;

int main()
{
	scanf("%d %d", &N, &M);
	
	prefsum[0] = 0;
	for(int i = 1; i <= N; i++) 
	{
		scanf("%d %d", &C, &T);
		prefsum[i] = C * T + prefsum[i - 1];
	}
	
	while(M--)
	{
		scanf("%d", &V);
		printf("%d\n", lower_bound(prefsum + 1, prefsum + N + 1, V) - prefsum);
	}
	return 0;
}

