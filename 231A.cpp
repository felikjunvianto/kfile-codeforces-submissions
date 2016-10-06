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

int N, problem[1010], total;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		problem[i] = 0;
		for(int j = 0; j < 3; j++)
		{
			int k;
			scanf("%d", &k);
			problem[i] += k;
		}
		
		if(problem[i] >= 2) total++;
	}
	
	printf("%d\n", total);
	return 0;
}

