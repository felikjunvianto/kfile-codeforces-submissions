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

using namespace std;

int bawah,samping,x,y,ans;
bool papan[20][20];

int main()
{
	scanf("%d %d",&bawah,&samping);
	memset(papan,false,sizeof(papan));
	ans=0;
	for(x=1;x+1<=samping;x++)
		for(y=1;y+1<=bawah;y++) if(!papan[x][y])
		{
			ans+=2;
			papan[x][y]=papan[x+1][y]=papan[x][y+1]=papan[x+1][y+1]=true;
		}
		
	for(x=1;x+1<=samping;x++) if(!papan[x][bawah])
	{
		ans++;
		papan[x][bawah]=papan[x+1][bawah]=true;
	}
	
	for(y=1;y+1<=bawah;y++) if(!papan[samping][y])
	{
		ans++;
		papan[samping][y]=papan[samping][y+1]=true;
	}
	
	printf("%d\n",ans);
	return 0;
}

