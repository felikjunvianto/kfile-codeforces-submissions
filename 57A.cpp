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

int N,xa,ya,xb,yb;

int main()
{
	scanf("%d %d %d %d %d",&N,&xa,&ya,&xb,&yb);
	if(xa+xb==N) printf("%d\n",min(ya+yb+N,3*N-(ya+yb))); else
	if(ya+yb==N) printf("%d\n",min(xa+xb+N,3*N-(xa+xb))); else
	printf("%d\n",abs(xa-xb)+abs(ya-yb));
	return 0;
}

