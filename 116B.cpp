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

int dr[] = {-1, 0, 1, 0};
int dc[] = { 0, 1, 0,-1};

int R, C, r, c, i, ans;
char grid[20][20];

int main()
{
	scanf("%d %d",&R, &C);
	for(r=0;r<R;r++) scanf("%s",grid[r]);
	
	ans = 0;
	for(r=0;r<R;r++)
		for(c=0;c<C;c++) if(grid[r][c] == 'P')
			for(i=0;i<4;i++)
			{
				int sr = r+dr[i], sc = c+dc[i];
				if(sr>=0 && sc>=0 && sr<R && sc<C && grid[sr][sc]=='W')
				{
					grid[sr][sc]='.';
					ans++;
					break;
				}
			}
			
	printf("%d\n",ans);
	return 0;
}

