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

int x, y, temp;

int main()
{
	for(x = 1; x <= 5; x++)
	{
		for(y = 1; y <= 5; y++)
		{
			scanf("%d",&temp);
			if(temp == 1) break;
		}
		if(temp == 1) break;
	}
	
	printf("%d\n",abs(3 - x) + abs(3 - y));
	return 0;
}

