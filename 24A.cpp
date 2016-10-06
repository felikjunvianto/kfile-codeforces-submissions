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

vector<int> adjlist[111];
int cost[111][111];
bool visited[111];
int N,x,y,a,b,c,now,tot,ans;

int main()
{
	scanf("%d",&N);
	memset(cost,0,sizeof(cost));
	for(x=0;x<N;x++)
	{
		scanf("%d %d %d",&a,&b,&c);
		adjlist[a].pb(b);
		adjlist[b].pb(a);cost[b][a]=c;
		tot+=c;
	}
	
	now=1;ans=0;
	memset(visited,false,sizeof(visited));
	visited[1]=true;
	for(x=1;x<=N;x++) 
	{
		if(x==N) visited[1]=false;
		for(y=0;y<adjlist[now].size();y++) if(!visited[adjlist[now][y]])
		{
				visited[adjlist[now][y]]=true;
				ans+=cost[now][adjlist[now][y]];
				now=adjlist[now][y];
				break;
		}
	}
	
	printf("%d\n",min(ans,tot-ans));
	return 0;
}

