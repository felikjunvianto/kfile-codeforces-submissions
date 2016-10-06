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

int a1, a2, a3, a4;
int b1, b2, b3, b4;

int main()
{
	scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
	
	if(b1 == b2) // case 1 : -
	{
		int d = abs(a2 - a1);
		a3 = a1, b3 = b1 + d;
		a4 = a2, b4 = b2 + d;
		printf("%d %d %d %d\n", a3, b3, a4, b4);
	} else if(a1 == a2) // case 2 : |
	{
		int d = abs(b2 - b1);
		a3 = a1 + d, b3 = b1;
		a4 = a2 + d, b4 = b2;
		printf("%d %d %d %d\n", a3, b3, a4, b4);
	} else if(abs(a2 - a1) == abs(b2 - b1)) // case 3 : \ or /
	{
		a3 = a1, b3 = b2;
		a4 = a2, b4 = b1;
		printf("%d %d %d %d\n", a3, b3, a4, b4);
	} else
	{
		printf("-1\n");
	}
	return 0;
}

