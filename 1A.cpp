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

int n,m,a;
LL ba,sa;

int main()
{
	scanf("%d %d %d",&n,&m,&a);
	sa=(LL)n/a;if(n%a) sa++;
	ba=(LL)m/a;if(m%a) ba++;
	printf("%I64d\n",sa*ba);
	return 0;
}

