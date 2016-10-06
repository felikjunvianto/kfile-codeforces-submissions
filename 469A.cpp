#include <cstdio>
#include <cstdlib>
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
#include <set>

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

int N, P, Q, x;
bool cleared[111];

int main()
{
	scanf("%d", &N);
	memset(cleared, false, sizeof(cleared));
	
	scanf("%d", &P);
	while(P--)
	{
		scanf("%d", &x);
		cleared[x] = true;
	}
	
	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d", &x);
		cleared[x] = true;
	}
	
	bool oke = true;
	for(int i = 1; i <= N && oke; i++) oke = cleared[i];
	
	printf("%s\n", oke ? "I become the guy." : "Oh, my keyboard!");
	return 0;
}

