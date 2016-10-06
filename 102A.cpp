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

int N,M,price[111],x,y,z,ans;
bool match[111][111];

int main()
{
	scanf("%d %d",&N,&M);
	for(x=1;x<=N;x++) scanf("%d",&price[x]);
	memset(match,false,sizeof(match));
	while(M--)
	{
		scanf("%d %d",&x,&y);
		match[x][y]=match[y][x]=true;
	}
	
	ans=INF;
	for(x=1;x<=N;x++)
		for(y=x+1;y<=N;y++)
			for(z=y+1;z<=N;z++) 
				if((match[x][y])&&(match[y][z])&&(match[x][z]))
					ans=min(ans,price[x]+price[y]+price[z]);
					
	printf("%d\n",ans==INF?-1:ans);
	return 0;
}

