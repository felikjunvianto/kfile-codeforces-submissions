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

char grid[10][10];
int r,c,x,y,z,ans,A,B;

int main()
{
	for(r=0;r<8;r++) scanf("%s",grid[r]);
	ans=0;
	for(r=0;r<8;r++)
		for(c=0;c<8;c++) if(grid[r][c]=='B')
		{
			ans++;
			A=B=0;//hor
			for(x=0;x<8;x++) if(grid[r][x]=='B') B++; else if(grid[r][x]=='A') A++;
			if(A+B==8)
			{
				for(x=0;x<8;x++) grid[r][x]='A';
				continue;
			}
			
			A=B=0;//ver
			for(x=0;x<8;x++) if(grid[x][c]=='B') B++; else if(grid[x][c]=='A') A++;
			if(A+B==8)
			{
				for(x=0;x<8;x++) grid[x][c]='A';
				continue;
			}
		}
	printf("%d\n",ans);
	return 0;
}

