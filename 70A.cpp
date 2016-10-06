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

int bts=1000003;
int N,x,ans[1111];

int main()
{
	scanf("%d",&N);
	ans[0]=ans[1]=1;
	for(x=2;x<=N;x++) ans[x]=(ans[x-1]*3)%bts;
	printf("%d\n",ans[N]);
	return 0;
}

