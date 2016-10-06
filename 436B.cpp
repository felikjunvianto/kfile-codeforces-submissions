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
char grid[2010][2010];

int main()
{
	scanf("%d %d %d", &R, &C, &K);
	for(int r = 0; r < R; r++) scanf("%s", grid[r]);
	
	for(int c = 0; c < C; c++)
	{
		int lihat = 0;
		
		for(int t = 0; t < R; t++)
		{
			if(2 * t < R && grid[2 * t][c] == 'U') lihat++;
			if(c + t < C && grid[t][c + t] == 'L') lihat++;
			if(c - t >= 0 && grid[t][c - t] == 'R') lihat++;
		}
		
		printf("%d%c", lihat, c + 1 == C ? '\n' : ' ');
	}
	return 0;
}

