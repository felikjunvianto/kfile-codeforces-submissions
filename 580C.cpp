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

struct state {
	int pos, lewat;
};

int N, M;
vector<int> adjlist[100010];
bool visited[100010], kucing[100010];
queue<state> Q;

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &kucing[i]);
	
	for(int i = 1; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}
	
	memset(visited, false, sizeof(visited));
	visited[1] = true;
	Q.push((state) {1, kucing[1]});
	
	int num_res = 0;
	while(!Q.empty())
	{
		state now = Q.front(); Q.pop();
		if(adjlist[now.pos].size() == 1 && visited[adjlist[now.pos][0]]) num_res++; else
			for(int i = 0, SIZE = adjlist[now.pos].size(); i < SIZE; i++)
			{
				int next = adjlist[now.pos][i];
				int cons = kucing[next] ? now.lewat + kucing[next] : 0;
				if(!visited[next] && cons <= M)
				{
					visited[next] = true;
					Q.push((state){next, cons});
				}		
			}
	}
	
	printf("%d\n", num_res);
	return 0;
}

