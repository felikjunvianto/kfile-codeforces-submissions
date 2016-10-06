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

int N, a[100050], basis;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &a[i]);
	
	basis = -1;
	bool bisa = true;
	for(int i = 0; i < N && bisa; i++)
	{
		while(a[i] % 2 == 0) a[i] /= 2;
		while(a[i] % 3 == 0) a[i] /= 3;
		
		if(basis == -1) basis = a[i]; else
			if(basis != a[i]) bisa = false;
	}
	
	printf("%s\n", bisa ? "Yes" : "No");
	return 0;
}

