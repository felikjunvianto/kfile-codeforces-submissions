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

typedef struct
{
	int x,y,gerak;
	string m;
} cell;

int dx[]={ 1, 1, 0,-1,-1,-1, 0, 1};
int dy[]={ 0,-1,-1,-1, 0, 1, 1, 1};
string move[]={"R","RD","D","LD","L","LU","U","RU"};    

queue<cell> q;
PII awal,akhir;
int x,y,z,ans;
bool vis[10][10];
string jwb;
char msk[5];

int main()
{
	scanf("%s",msk);awal=mp(msk[0]-'a'+1,msk[1]-'0');
	scanf("%s",msk);akhir=mp(msk[0]-'a'+1,msk[1]-'0');
	memset(vis,false,sizeof(vis));
	vis[awal.fi][awal.se]=true;
	q.push((cell){awal.fi,awal.se,0,""});
	
	while(!q.empty())
	{
		cell now=q.front();q.pop();
		if(mp(now.x,now.y)==akhir)
		{
			ans=now.gerak;
			jwb=now.m;
			break;
		}
		
		for(z=0;z<8;z++)
		{
			x=now.x+dx[z],y=now.y+dy[z];
			if((x)&&(x<=8)&&(y)&&(y<=8))
				if(!vis[x][y])
				{
					vis[x][y]=true;
					q.push((cell){x,y,now.gerak+1,now.m+(char)(z+'0')});
				}
		}
	}
	
	printf("%d\n",ans);
	for(x=0;x<jwb.size();x++) printf("%s\n",move[jwb[x]-'0'].c_str());
	return 0;
}

