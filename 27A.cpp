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

bool cnt[3010];
int N,x;

int main()
{
	scanf("%d",&N);
	memset(cnt,false,sizeof(cnt));
	while(N--)
	{
		scanf("%d",&x);
		cnt[x]=true;
	}
	
	for(x=1;x<=3000;x++) if(!cnt[x]) break;
	printf("%d\n",x);
	return 0;
}

