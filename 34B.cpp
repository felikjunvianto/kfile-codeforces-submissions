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

int N,M,x,y,z,ans;
int tv[110];

int main()
{
	scanf("%d %d",&N,&M);
	for(x=0;x<N;x++) scanf("%d",&tv[x]);
	sort(tv,tv+N);
	
	ans=0;
	x=-1;
	while(1)
	{
		x++;
		if((x==M)||(tv[x]>0)) break;
		ans-=tv[x];
	}
	printf("%d\n",ans);
	return 0;
}

