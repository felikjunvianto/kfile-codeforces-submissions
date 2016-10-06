#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000000
#define EPS 1e-9
#define PI 2*acos(0.0)
#define PII pair<int,int> 
#define LL long long

using namespace std;

int N, par[2222], level[2222];
int i, j, k;
vector<int> adjlist[2222];
queue<int> q;

int main()
{
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&par[i]);
		if(par[i]!=-1) adjlist[par[i]].pb(i);
	}
	
	memset(level,-1,sizeof(level));
	for(i=1;i<=N;i++) if(par[i]==-1) 
	{
		level[i]=1;
		q.push(i);
	}
	
	while(!q.empty())
	{
		int now = q.front();q.pop();
		for(i=0;i<adjlist[now].size();i++)
		{
			j = adjlist[now][i];
			if(level[j]==-1)
			{
				level[j] = level[now]+1;
				q.push(j);
			}
		}
	}
	
	int ans = 0;
	for(i=1;i<=N;i++) ans = max(ans, level[i]);
	printf("%d\n",ans);
	return 0;
}

