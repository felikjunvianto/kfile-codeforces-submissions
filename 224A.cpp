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

int areaA, areaB, areaC;
int A, B, C, tot;

int main()
{
	scanf("%d %d %d",&areaA, &areaB, &areaC);
	for(A = 1; A <= areaA; A++) if(areaA % A == 0)
	{
		B = areaA / A;
		if(areaB % B == 0)
		{
			C = areaB / B;
			if(A * C == areaC)
			{
				tot = 4*(A + B + C);
				break;
			}
		}
	}
	
	printf("%d\n",tot);
	return 0;
}

