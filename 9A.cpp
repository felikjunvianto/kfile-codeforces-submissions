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

int gede,x,atas,bawah;

int main()
{
	scanf("%d",&gede);
	scanf("%d",&x);
	gede=max(gede,x);
	atas=7-gede;
	bawah=6;
	x=__gcd(atas,bawah);
	printf("%d/%d\n",atas/x,bawah/x);
	return 0;
}

