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

int a[2],stone,now,take;

int main()
{
	scanf("%d %d %d",&a[0],&a[1],&stone);
	now=0;
	while(1)
	{
		take = __gcd(stone,a[now]);
		if(take > stone) break;
		stone-=take;
		now=1-now;
	}
	
	printf("%d\n",1-now);
	return 0;
}

