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

int n,a,b,x,ans;

int main()
{
	scanf("%d %d %d",&n,&a,&b);
	ans=0;
	for(x=0;x<n;x++) if((x>=a)&&(n-x-1<=b)) ans++;
	printf("%d\n",ans);
	return 0;
}

