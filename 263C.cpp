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

int N, i, j, k;
vector<int> adjlist[100010];
int path[100010], deg[100010];
bool found, visited[100010];

void backtrack(int now)
{
	if(now == N) 
	{
		found = true;
		for(int i = 0; i < N; i++) printf("%d%c",path[i],i+1==N?'\n':' ');
		return;
	}
	
	for(int i = 0; i < adjlist[path[now-1]].size(); i++)
	{
		int next = adjlist[path[now-1]][i];
		if(visited[next]) continue;
		
		bool valid = true;
		if(now > 1) 
		{
			valid = false;
			for(int j = 0; j < adjlist[next].size(); j++)
				if(adjlist[next][j] == path[now-2])
				{
					valid = true;
					break;
				} if(!valid) continue;
				
			if(now + 2 >= N) 
			{
				valid = false;
				for(int j = 0; j < adjlist[next].size(); j++)
				if(adjlist[next][j] == path[(now+2)%N])
				{
					valid = true;
					break;
				} if(!valid) continue;
			}
			
			if(now + 1 == N)
			{
				valid = false;
				for(int j = 0; j < adjlist[next].size(); j++)
				if(adjlist[next][j] == path[0])
				{
					valid = true;
					break;
				} if(!valid) continue;
			}
		}
		
		if(valid) 
		{
			visited[next] = true;
			path[now] = next;
			backtrack(now+1);
			
			if(found) return;
			visited[next] = false;
		}
	}
}

int main()
{
	scanf("%d",&N);
	for(k=0;k<2*N;k++)
	{
		scanf("%d %d",&i, &j);
		
		if(deg[i] == 4 || deg[j] == 4) 
		{
			printf("-1\n");
			return 0;
		}
		
		deg[i]++;deg[j]++;
		adjlist[i].pb(j);
		adjlist[j].pb(i);
	}
	
	for(k=1;k<=N;k++) if(deg[k]!=4) 
	{
		printf("-1\n");
		return 0;
	}
	
	memset(visited,false,sizeof(visited));
	found = false;
	visited[1] = true; path[0] = 1;
	backtrack(1);
	
	if(!found) printf("-1");
	return 0;
}