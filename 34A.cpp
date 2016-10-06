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

using namespace std;

int N,x,y,z,arr[110],now;
PII ans;

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++) scanf("%d",&arr[x]);
	now=abs(arr[N]-arr[1]);
	ans=mp(N,1);
	for(x=1;x<N;x++) if(now>abs(arr[x]-arr[x+1]))
	{
		now=abs(arr[x]-arr[x+1]);
		ans=mp(x,x+1);
	}
	printf("%d %d\n",ans.fi,ans.se);
	return 0;
}

