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

int N, h[100010], i, pos;
LL ans;

int main()
{
	scanf("%d",&N);
	for(i = 0 ; i < N; i++) scanf("%d", &h[i]);
	
	pos = ans = 0;
	for(i = 0; i < N; i++)
	{
		ans += (LL)(h[i] - pos + 1);
		pos = h[i];
		
		if(i < N - 1 && h[i] > h[i + 1])
		{
			ans += (LL)(pos - h[i + 1]);
			pos = h[i + 1];
		}
		
		if(i < N - 1) ans++;
	}
	
	printf("%I64d\n",ans);
	return 0;
}

