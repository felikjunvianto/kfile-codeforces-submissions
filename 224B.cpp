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
#include <set>

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

int N, K, L, R, x;
int arr[100010];
int cnt[100010];
set<int> now;
bool ketemu;

int main()
{
	scanf("%d %d",&N,&K);
	for(x=1;x<=N;x++) scanf("%d",&arr[x]);
	memset(cnt,0,sizeof(cnt));
	
	L = 1;
	R = L;
	while(R <= N && (int)now.size() < K) 
	{
		cnt[arr[R]]++;
		if(now.find(arr[R])==now.end()) now.insert(arr[R]);
		R++;
	} R--;
	
	if((int)now.size() < K)
	{
		printf("-1 -1\n");
		return 0;
	}
	
	while(L < N && (int) now.size() == K)
	{
		if(cnt[arr[L]]==1) break; else cnt[arr[L]]--;
		L++;
	}
		
	printf("%d %d\n",L, R);
	return 0;
}

