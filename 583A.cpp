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
bool beres_ver[60], beres_hor[60];

int main()
{
	memset(beres_ver, false, sizeof(beres_ver));
	memset(beres_hor, false, sizeof(beres_hor));
	
	scanf("%d", &N);
	for(int i = 1, total = N * N; i <= total; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		
		if(!beres_ver[a] && !beres_hor[b])
		{
			beres_ver[a] = beres_hor[b] = true;
			printf("%d\n", i);
		}
	}
	
	return 0;
}

