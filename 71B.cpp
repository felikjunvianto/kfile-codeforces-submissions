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

int bar[110];
int N,K,T,x,tot;

int main()
{
	scanf("%d %d %d",&N,&K,&T);
	tot=N*K*T/100;
	memset(bar,0,sizeof(bar));
	for(x=1;x*K<=tot;x++) bar[x]=K;
	bar[(tot/K)+1]=tot%K;
	for(x=1;x<=N;x++) printf("%d%c",bar[x],x==N?'\n':' ');
	return 0;
}

