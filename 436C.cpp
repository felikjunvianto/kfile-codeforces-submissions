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

struct edge
{
	int a, b, c;
};

int R, C, K, W, par[1005];
char grid[1005][15][15];
vector<edge> e;
vector<int> adjlist[1005];
bool visited[1005];

bool cf(edge i, edge j) 
{ 
	if(i.c != j.c) return i.c < j.c; 
	if(i.a != j.a) return i.a < j.a;
	return i.b < j.b;
}

int find(int i)
{
	if(par[i] == -1) par[i] = i; else
	{
		int ci = i;
		while(par[ci] != ci) ci = par[ci];
		par[i] = ci;
	}
	return par[i];
}

bool union_find(int i, int j)
{
	if(find(i) != find(j))
	{
		par[par[i]] = par[j];
		return true;
	}
	
	return false;
}

int kruskal()
{
	sort(e.begin(), e.end(), cf);
	for(int i = 0; i <= K; i++) adjlist[i].clear();
	memset(par, -1, sizeof(par));
	int con = 0, ret = 0;
	
	for(int i = 0; i < e.size(); i++) if(union_find(e[i].a, e[i].b))
	{
		adjlist[e[i].a].pb(e[i].b);
		adjlist[e[i].b].pb(e[i].a);
		ret += e[i].c;
		con++;
		
		if(con == K) break;
	}
	
	return ret;
}

void traverse(int root)
{
	for(int i = 0; i < adjlist[root].size(); i++)
	{
		int next = adjlist[root][i];
		if(!visited[next])
		{
			visited[next] = true;
			printf("%d %d\n", next, root);
			traverse(next);
			
			visited[next] = false;
		}
	}
}

int main()
{
	scanf("%d %d %d %d", &R, &C, &K, &W);
	for(int k = 1; k <= K; k++)
		for(int r = 0; r < R; r++)
			scanf("%s", grid[k][r]);
			
	for(int i = 0; i <= K; i++)
		for(int j = i + 1; j <= K; j++)
			if(!i) e.pb((edge){i, j, R*C}); else
			{
				int beda = 0;
				for(int r = 0; r < R; r++)
					for(int c = 0; c < C; c++)
						beda += (grid[i][r][c] == grid[j][r][c] ? 0 : 1);
						
				e.pb((edge){i, j, beda * W});
			}
			
	printf("%d\n", kruskal());
	
	memset(visited, false, sizeof(visited));
	visited[0] = true;
	traverse(0);
	return 0;
}

