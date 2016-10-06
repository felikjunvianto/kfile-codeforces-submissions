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

int R, C, minW, maxW, i, j;
char grid[1010][1010];
int isBlack[1010];
int dp[1010][2];

int solve(int now, int state)
{
	if(now==C+1) return 0;
	if(now>C) return INF;
	if(dp[now][state]!=-1) return dp[now][state];
	
	int &ret = dp[now][state] = INF;
	for(int k = minW; k <= maxW; k++)
	{
		int next = now + k - 1;
		int move = (isBlack[next] - isBlack[now-1]);
		if(state==0) move = (next - now + 1)*R - move;

		ret = min(ret, solve(next+1,1 - state) + move);
	}
	
	return ret;
}

int main()
{
	scanf("%d %d %d %d",&R, &C, &minW, &maxW);
	for(i=1;i<=R;i++) scanf("%s",grid[i]+1);
	
	memset(isBlack,0,sizeof(isBlack));
	for(i=1;i<=R;i++)
		for(j=1;j<=C;j++) 
			if(grid[i][j]=='#') isBlack[j]++;
	
	for(j=1;j<=C;j++) isBlack[j]+=isBlack[j-1];
	memset(dp,-1,sizeof(dp));
	printf("%d\n",min(solve(1,0),solve(1,1)));
	return 0;
}

