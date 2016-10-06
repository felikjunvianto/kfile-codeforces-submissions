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

int N,a,x;
LL ans;

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++)
	{
		scanf("%d",&a);
		ans+=(LL)a+(LL)(x-1)*(LL)(a-1);
	}
	
	printf("%I64d\n",ans);
	return 0;
}

