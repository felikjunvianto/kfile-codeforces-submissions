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

int N,x,y,z,ans,mah[1010][5];
bool visited[1010];
char dummy[5];

int main()
{
	scanf("%d",&N);
	for(x=0;x<N;x++)
	{
		scanf("%s",dummy);mah[x][1]=dummy[0]-'0';mah[x][2]=dummy[1]-'0';
		scanf("%s",dummy);mah[x][4]=dummy[0]-'0';mah[x][3]=dummy[1]-'0';
		if(x+1<N) scanf("%s",dummy);
	}
	
	memset(visited,false,sizeof(visited));
	ans=0;
	for(x=0;x<N;x++) if(!visited[x])
	{
		ans++;
		visited[x]=true;
		for(y=0;y<N;y++) if(!visited[y])
		{
			z=0;
			do
			{
				z++;
				bool sama=true;
				for(int i=1;i<5;i++) if(mah[x][i]!=mah[y][i]) sama=false;
				if(sama)
				{
					visited[y]=true;
					break;
				}
				
				for(int i=0;i<5;i++) mah[y][i]=mah[y][(i+1)%5];
			}while(z<4);
		}
	}
	printf("%d\n",ans);
	return 0;
}

