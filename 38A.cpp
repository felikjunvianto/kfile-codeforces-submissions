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

int N,d[110],a,b,ans;

int main()
{
	scanf("%d",&N);
	for(a=1;a<N;a++) scanf("%d",&d[a]);
	scanf("%d %d",&a,&b);
	ans=0;
	while(a!=b)
	{
		ans+=d[a];
		a++;
	}
	printf("%d\n",ans);
	return 0;
}

