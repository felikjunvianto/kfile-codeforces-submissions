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

int N,x,y,z; 
LL cnt[10],poin[55],tot,prize[10];

int main()
{
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&N);
	for(x=0;x<N;x++) scanf("%I64d",&poin[x]);
	for(x=0;x<5;x++) scanf("%I64d",&prize[x]);
	
	tot=0LL;
	for(x=0;x<N;x++)
	{
		tot+=poin[x];
		for(y=4;y>=0;y--) if(prize[y]<=tot)
		{
			LL exchange = tot/prize[y];
			cnt[y]+=exchange;
			tot%=prize[y];
		}
	}

	for(x=0;x<5;x++) printf("%I64d%c",cnt[x],x==4?'\n':' ');
	printf("%I64d\n",tot);
	return 0;
}

