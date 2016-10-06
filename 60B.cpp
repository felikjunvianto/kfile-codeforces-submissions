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

int dx[]={-1, 1, 0, 0, 0, 0};
int dy[]={ 0, 0,-1, 1, 0, 0};
int dz[]={ 0, 0, 0, 0,-1, 1};

int bawah,samping,dalam;
int x,y,z,a,b,ans;
char mat[15][15][15],msk[15];

void ff(int x,int y,int z)
{
	for(int i=0;i<6;i++)
	{
		int sx=x+dx[i],sy=y+dy[i],sz=z+dz[i];
		if((sx)&&(sx<=samping)&&(sy)&&(sy<=bawah)&&(sz)&&(sz<=dalam))
			if(mat[sx][sy][sz]=='.')
			{
				mat[sx][sy][sz]='*';
				ans++;
				ff(sx,sy,sz);
			}
	}
}

int main()
{
	scanf("%d %d %d",&dalam,&bawah,&samping);
	for(z=1;z<=dalam;z++)
		for(y=1;y<=bawah;y++)
		{
			scanf("%s",msk);
			for(x=1;x<=samping;x++) mat[x][y][z]=msk[x-1];
		}
	
	scanf("%d %d",&a,&b);
	
	ans=1;
	mat[b][a][1]='*';
	ff(b,a,1);
	printf("%d\n",ans);
	return 0;
}

