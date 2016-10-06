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

int N, A, B, Pori[100010], P[100010];
int Apair[100010], Bpair[100010], ans[100010];
bool visited[100010];
vector<int> startA, startB;

int main()
{
	scanf("%d %d %d", &N, &A, &B);
	for(int i = 0; i < N; i++) 
	{
		scanf("%d", &Pori[i]);
		P[i] = Pori[i];
	}
	sort(P, P + N);
	
	bool valid = true;
	memset(Apair, -1, sizeof(Apair));
	memset(Bpair, -1, sizeof(Bpair));
	
	for(int i = 0; i < N; i++)
	{
		if(Apair[i] == -1)
		{
			int temp = A - P[i];
			int idx = lower_bound(P, P + N, temp) - P;
			
			if(idx >= 0 && idx < N && P[idx] == temp)
			{
				Apair[i] = idx;
				Apair[idx] = i;
			}
		}
		
		if(Bpair[i] == -1)
		{
			int temp = B - P[i];
			int idx = lower_bound(P, P + N, temp) - P;
			
			if(idx >= 0 && idx < N && P[idx] == temp)
			{
				Bpair[i] = idx;
				Bpair[idx] = i;
			}
		}
	}
	
	if(A != B)
	{
		for(int i = 0; i < N && valid; i++)
			if(Apair[i] != -1 && Bpair[i] == -1) startA.pb(i); else
				if(Apair[i] == -1 && Bpair[i] != -1) startB.pb(i); else
					if(Apair[i] == -1 && Bpair[i] == -1) valid = false;
		
		memset(ans, -1, sizeof(ans));
		for(int i = 0; i < startA.size() && valid; i++)
		{
			int now = startA[i];
			if(ans[now] != -1) continue;
			
			int passed = 0;
			vector<int> node;
			node.pb(now);
			
			while(true)
			{
				int next = (passed % 2 == 0) ? Apair[now] : Bpair[now];
				if(next == -1) break;
				
				passed++;
				now = next;
				node.pb(now);
			}
			
			if(passed % 2 == 0) valid = false; else
				for(int j = 0; j < node.size(); j++) ans[node[j]] = 0;
		}
		
		for(int i = 0; i < startB.size() && valid; i++)
		{
			int now = startB[i];
			if(ans[now] != -1) continue;
			
			int passed = 0;
			vector<int> node;
			node.pb(now);
			
			while(true)
			{
				int next = (passed % 2 == 0) ? Bpair[now] : Apair[now];
				if(next == -1) break;
				
				passed++;
				now = next;
				node.pb(now);
			}
			
			if(passed % 2 == 0) valid = false; else
				for(int j = 0; j < node.size(); j++) ans[node[j]] = 1;
		}
	} else
	{
		for(int i = 0; i < N && valid; i++) 
			if(Apair[i] == -1) valid = false; else ans[i] = 0;
	}
	
	for(int i = 0; i < N && valid; i++) if(ans[i] == -1) valid = false;
	
	if(!valid) printf("NO\n"); else
	{
		printf("YES\n");
		for(int i = 0; i < N; i++)
		{
			int idx = lower_bound(P, P + N, Pori[i]) - P;
			if(i) printf(" ");
			printf("%d", ans[idx]);
		}
		printf("\n");
	}
	return 0;
}

