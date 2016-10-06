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

int N,x,y,z,arr[111];

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++) scanf("%d",&arr[x]);
	for(x=1;x<=N;x++)
		for(y=1;y<=N;y++) if(y!=x)
			for(z=1;z<=N;z++) if((z!=x)&&(z!=y))
				if(arr[x]==arr[y]+arr[z])
				{
					printf("%d %d %d\n",x,y,z);
					return 0;
				}
	printf("-1\n");
	return 0;
}

