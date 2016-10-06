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

int R, C, K;
vector<int> fac_C, fac_R, blkg;

LL max_smallest(int r, int c, vector<int> &fac_r)
{
	LL ans = 0LL;
	for(int i = 0; i < fac_r.size(); i++)
	{
		int rem = K - fac_r[i] + 1;
		if(rem >= c) continue;
		
		ans = max(ans, (LL) floor(r / fac_r[i]) *  (rem + 1 <= 0 ? (LL) c : (LL) floor(c / (rem + 1))));
	}
	
	return ans;
}

void find_factor(int N, vector<int> &fac_N)
{
	blkg.clear();
	
	for(int i = 1; i * i <= N; i++) if(N % i == 0)
	{
		fac_N.pb(i);
		if(i * i != N) blkg.pb(N / i);
	}
	
	for(int i = blkg.size() - 1; i >= 0; i--) fac_N.pb(blkg[i]);
}

int main()
{
	scanf("%d %d %d", &R, &C, &K);
	if(R + C - 2 < K)
	{
		printf("-1\n");
		return 0;
	}
	
	find_factor(R, fac_R);
	find_factor(C, fac_C);
	
	printf("%I64d\n", max(max_smallest(R, C, fac_R), max_smallest(C, R, fac_C)));
	return 0;
}

