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

int N,cnt[5],x;

int main()
{
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	sort(cnt+1,cnt+4);
	
	printf("%d\n",cnt[1]+cnt[2]);
	return 0;
}

