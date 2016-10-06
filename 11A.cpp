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

int N,D,x,y,z,move;
int arr[2010];

int main()
{
	scanf("%d %d",&N,&D);
	for(x=1;x<=N;x++) scanf("%d",&arr[x]);
	move=0;
	for(x=2;x<=N;x++) if(arr[x]<=arr[x-1])
	{
		z=((arr[x-1]-arr[x])/D)+1;
		move+=z;
		arr[x]+=z*D;
	}
	printf("%d\n",move);
	return 0;
}

