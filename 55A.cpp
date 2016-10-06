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

bool vis[1010][1010],kena[1010],oke;
int x,N,move,now,next;

int main()
{
	scanf("%d",&N);
	memset(vis,false,sizeof(vis));
	memset(kena,false,sizeof(kena));
	kena[1]=true;
	now=move=1,next=2;
	while(!vis[now][next])
	{
		vis[now][next]=true;
		now=next;
		kena[now]=true;
		move=(move+1)%N;
		for(x=1;x<=move;x++) if(next==N) next=1; else next++;
	}
	
	oke=true;
	for(x=1;x<=N;x++) if(!kena[x]) oke=false;
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

