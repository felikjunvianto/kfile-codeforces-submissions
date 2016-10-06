#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000000
#define EPS 1e-9
#define PI 2*acos(0.0)
#define PII pair<int,int> 
#define LL long long

using namespace std;
 
int R, C, r, c;
int totWeed[155], maks;
char grid[155][155];
int dp[155][155];

int solve(int r, int c)
{
	if(r==R+1) return 0;
	if(dp[r][c]!=-1) return dp[r][c];
	int &ret = dp[r][c] = INF;
	
	int now = 0, dir = (r%2)?1:-1;
	for(int x=0;;x++)
	{
		if(c + x*dir < 1 || c + x*dir > C) break;
		if(grid[r][c+x*dir]=='W') now++;
		
		if(now == totWeed[r] - totWeed[r-1]) 
		{
			int turun = 0;
			if(totWeed[r] != maks) turun++;
			ret = min(ret, solve(r+1,c+x*dir) + x + turun);
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d",&R, &C);
	memset(totWeed,0,sizeof(totWeed));
	maks = 0;
	
	for(r=1;r<=R;r++) 
	{
		scanf("%s",grid[r]+1);
		for(c=1;c<=C;c++) if(grid[r][c] == 'W') totWeed[r]++;
		maks += totWeed[r];
	} for(r=1;r<=R;r++) totWeed[r] += totWeed[r-1];
	
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(1,1));
	
	//for(r=1;r<=10;r++)
	//	for(c=1;c<=10;c++)
	//		printf("%d%c",dp[r][c],c==10?'\n':' ');
	return 0;
}

