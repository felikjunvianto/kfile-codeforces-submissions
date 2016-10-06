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

LL last,now,mod = 1000000007LL;
int N,x;


int main()
{
	scanf("%d",&N);
	last=0LL;
	for(x=2;x<=N;x++)
	{
		LL add;
		if(x%2) add=-1LL; else add=1LL;
		now=((last+add)*3LL)%mod;
		last=now;
	}
	printf("%I64d\n",last);
	return 0;
}

