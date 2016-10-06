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

int x,N,ans[20];

int main()
{
	for(x=12;x<16;x++) ans[x]=0;
	for(x=1;x<12;x++) ans[x]=4;
	ans[10]=15;
	
	scanf("%d",&N);
	printf("%d\n",N<11?0:ans[N-10]);
	return 0;
}

