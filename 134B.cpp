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

int count(int a,int b)
{
	if((a==0)||(b==0)) return(INF);
	if(a==1) return(b-1);
	if(b==1) return(a-1);
	
	return(count(b,a%b)+a/b);
}

int n,ans,x;

int main()
{
	scanf("%d",&n);
	ans=INF;
	for(x=1;x<=n;x++) ans=min(ans,count(n,x));
	printf("%d\n",ans);
	return 0;
}

