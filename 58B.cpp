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

int dp[1000010];
int path[1000010];
int N,x,y,z;

int solve(int now)
{
	if(dp[now]!=-1) return(dp[now]);
	int i,&ret = dp[now] = 0;
	for(i=1;i*i<=now;i++) if(now%i==0)
	{
		if(solve(now/i)+1>ret)
		{
			ret=solve(now/i)+1;
			path[now]=now/i;
		}
		
		if(solve(i)+1>ret)
		{
			ret=solve(i)+1;
			path[now]=i;
		}
	}
	return(ret);
}

int main()
{
	scanf("%d",&N);
	memset(dp,-1,sizeof(dp));
	dp[1]=path[1]=1;
	z=solve(N);
	
	while(N!=path[N])
	{
		printf("%d ",N);
		N=path[N];
	}
	printf("1\n");
	return 0;
}

