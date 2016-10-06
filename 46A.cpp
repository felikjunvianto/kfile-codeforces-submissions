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

int N,x,y,now;

int main()
{
	scanf("%d",&N);
	now=0;
	for(x=1;x<N;x++)
	{
		for(y=1;y<=x;y++) now=(now+1)%N;
		printf("%d%c",now+1,x+1==N?'\n':' ');
	}
	return 0;
}

