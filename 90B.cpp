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

int dx[]={-1, 0, 0, 1};
int dy[]={ 0, 1,-1, 0};

int bawah,samping,x,y,z;
bool oke[110][110];
char grid[110][110];

int main()
{
	scanf("%d %d",&bawah,&samping);getchar();
	for(y=1;y<=bawah;y++)
		for(x=1;x<=samping;x++)
		{
			scanf("%c",&grid[x][y]);
			if(x==samping) getchar();
		}
	
	memset(oke,true,sizeof(grid));
	for(x=1;x<=samping;x++)
		for(y=1;y<=bawah;y++) if(oke[x][y])
			for(z=0;z<4;z++)
			{
				int move=0;
				while(1)
				{
					move++;
					int sx=x+dx[z]*move,sy=y+dy[z]*move;
					if((sx<1)||(sx>samping)||(sy<1)|(sy>bawah)) break;
					if(grid[sx][sy]==grid[x][y]) oke[x][y]=oke[sx][sy]=false;
				}
			}
			
	for(y=1;y<=bawah;y++)
		for(x=1;x<=samping;x++) if(oke[x][y]) printf("%c",grid[x][y]);
	printf("\n");
	return 0;
}

