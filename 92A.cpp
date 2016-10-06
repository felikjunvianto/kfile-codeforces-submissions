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

int N,M,now;

int main()
{
	scanf("%d %d",&N,&M);
	now=0;
	while(1)
	{
		now++;
		if(now==N+1) now=1;
		if(M<now) break; else M-=now;
	}
	printf("%d\n",M);
	return 0;
}

