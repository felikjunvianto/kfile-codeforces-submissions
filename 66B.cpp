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

using namespace std;

int N,x,y,z,ans;
int h[1010],kiri[1010],kanan[1010];

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++) scanf("%d",&h[x]);
	kiri[1]=kanan[N]=1;
	for(x=2;x<=N;x++) if(h[x]>=h[x-1]) kiri[x]=kiri[x-1]+1; else kiri[x]=1;
	for(x=N-1;x;x--) if(h[x]>=h[x+1]) kanan[x]=kanan[x+1]+1; else kanan[x]=1;
	ans=0;
	for(x=1;x<=N;x++) ans=max(ans,kiri[x]+kanan[x]-1);
	printf("%d\n",ans);
	return 0;
}

