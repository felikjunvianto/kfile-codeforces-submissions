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

const int dr[] = { 0, 1, 1, 1, 0,-1,-1,-1};
const int dc[] = { 1, 1, 0,-1,-1,-1, 0, 1};

char grid[6][6];

bool bisa_ujung(int row, int col, int dir)
{
	for(int k = 1; k <= 2; k++)
	{
		int sr = row + dr[dir] * k;
		int sc = col + dc[dir] * k;

		if(grid[sr][sc] != 'x') return false;
	}

	return true;
}

bool bisa_tengah(int row, int col, int dir)
{
	for(int k = -1; k <= 1; k++)
	{
		if(k == 0) continue;

		int sr = row + dr[dir] * k;
		int sc = col + dc[dir] * k;

		if(grid[sr][sc] != 'x') return false;
	}

	return true;
}

int main()
{
	for(int i = 0; i < 4; i++) scanf("%s", grid[i]);

	bool menang = false;
	for(int r = 0; r < 4 && !menang; r++)
		for(int c = 0; c < 4 && !menang; c++)
			if(grid[r][c] == '.')
			{
				for(int i = 0; i < 8 && !menang; i++)
				{
					menang = bisa_ujung(r, c, i);
					// printf("UJUNG %d %d %d %s\n", r, c, i, menang ? "YES" : "NO");
				}

				for(int i = 0; i < 4 && !menang; i++)
				{
					menang = bisa_tengah(r, c, i);
					// printf("TENGAH %d %d %d %s\n", r, c, i, menang ? "YES" : "NO");
				}
			}
	
	printf("%s\n", menang ? "YES" : "NO");
	return 0;
}

