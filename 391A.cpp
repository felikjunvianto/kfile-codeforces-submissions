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

char msk[222];
int len;

int main()
{
	scanf("%s", msk); len = strlen(msk);
	
	int ans = 0, x = 0;
	do
	{
		int y = x;
		while(y < len && msk[y] == msk[x]) y++;
		if((y - x) % 2 == 0) ans++;
		x = y;
	} while(x < len);
	
	printf("%d\n", ans);
	return 0;
}

