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

int dx[]={-1, 0, 1, 0};
int dy[]={ 0, 1, 0,-1};

typedef struct{int x,y,t;} cell;

PII finish;
char grid[500][500],msk[111];
int len,x,y,z,ans;
queue<cell> q;

int main()
{
	memset(grid,'#',sizeof(grid));
	x=y=250;
	
	scanf("%s",msk);len=strlen(msk);
	for(z=0;z<len;z++)
	{
		switch(msk[z])
		{
			case('L') : x--;break;
			case('U') : y--;break;
			case('R') : x++;break;
			case('D') : y++;break;
		}
		grid[x][y]='.';
	}
	
	ans=INF;
	finish=mp(x,y);
	q.push((cell){250,250,0});
	grid[250][250]='@';
	
	while(!q.empty())
	{
		cell now=q.front();q.pop();
		if(mp(now.x,now.y)==finish) ans=min(ans,now.t); else
			for(z=0;z<4;z++)
			{
				int sx=now.x+dx[z],sy=now.y+dy[z];
				if(grid[sx][sy]=='.')
				{
					grid[sx][sy]='@';
					q.push((cell){sx,sy,now.t+1});
				}
			}
	}
	
	printf("%s\n",ans==len?"OK":"BUG");
	return 0;
}

