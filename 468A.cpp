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

int N;

int main()
{
	scanf("%d", &N);
	if(N < 4) printf("NO\n"); else
	{
		printf("YES\n");
		switch(N)
		{
			case(4): printf("2 * 3 = 6\n");
					 printf("1 * 6 = 6\n");
					 printf("4 * 6 = 24\n");
					 break;
					 
			case(5): printf("5 - 2 = 3\n");
					 printf("3 - 1 = 2\n");
					 printf("3 * 2 = 6\n");
					 printf("4 * 6 = 24\n");
					 break;
					 
			default: printf("%d - 1 = %d\n", N, N - 1);
					 printf("%d - %d = 0\n", N - 1, N - 1);
					 for(int i = N - 2; i > 4; i --) printf("%d * 0 = 0\n", i);
					 printf("3 * 2 = 6\n");
					 printf("6 + 0 = 6\n");
					 printf("6 * 4 = 24\n");
					 break;
		}
	}
	return 0;
}

