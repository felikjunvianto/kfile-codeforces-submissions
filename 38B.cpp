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

int dx[]={ 1, 2, 2, 1,-1,-2,-2,-1};
int dy[]={ 2, 1,-1,-2,-2,-1, 1, 2};

char pos[5],grid[10][10];
int N,x,y,z,ans;


int main()
{
	memset(grid,'.',sizeof(grid));
	scanf("%s",pos);
	x=pos[0]-'a'+1,y=pos[1]-'0';
	for(z=1;z<=8;z++) grid[x][z]=grid[z][y]='#';
	grid[x][y]='X';
	
	scanf("%s",pos);
	x=pos[0]-'a'+1,y=pos[1]-'0';
	for(z=0;z<8;z++)
	{
		int sx=x+dx[z],sy=y+dy[z];
		if((sx)&&(sx<=8)&&(sy)&&(sy<=8)&&(grid[sx][sy]!='X')) grid[sx][sy]='#';
	} grid[x][y]='X';
	
	ans=0;
	for(x=1;x<=8;x++)
		for(y=1;y<=8;y++) if(grid[x][y]=='.')
		{
			bool oke=true;
			for(z=0;(z<8)&&oke;z++)
			{
				int sx=x+dx[z],sy=y+dy[z];
				if((sx)&&(sx<=8)&&(sy)&&(sy<=8))
					if(grid[sx][sy]=='X') oke=false;
			}
			
			if(oke) ans++;
		}
	
	printf("%d\n",ans);
	return 0;
}

