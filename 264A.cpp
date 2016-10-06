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

char stone[1000010];
int len;

void solve(int now)
{
	if(now == len) return;
	if(stone[now] == 'l') 
	{
		solve(now + 1);
		printf("%d\n", now + 1);
	} else 
	{
		printf("%d\n", now + 1);
		solve(now + 1);
	}
}

int main()
{
	scanf("%s",stone); len = strlen(stone);
	solve(0);
	return 0;
}

