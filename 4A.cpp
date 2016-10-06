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

int N,x;
bool ans;

int main()
{
	scanf("%d",&N);
	ans=false;
	for(x=2;2*x<=N;x+=2) if(!((N-x)&1)) ans=true;
	printf("%s\n",ans?"YES":"NO");
	return 0;
}

