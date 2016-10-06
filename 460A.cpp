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

int N, M, ans;

int main()
{
	scanf("%d %d", &N, &M);
	ans = 0;
	
	while(N > 0)
	{
		N--;
		ans++;
		
		if(ans % M == 0) N++;
	}
	
	printf("%d\n", ans);
	return 0;
}

