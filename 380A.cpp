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

int M, N, c, x, y;
LL cumIdx[100010];
PII oper[100010];

int main()
{
	scanf("%d", &M);
	
	cumIdx[0] = 0LL;
	for(int i = 1; i <= M; i++)
	{
		scanf("%d", &c);
		if(c == 1)
		{
			scanf("%d", &x);
			cumIdx[i] = 1LL + cumIdx[i - 1];
			oper[i] = mp(x, -1);
		} else
		{
			scanf("%d %d", &x, &y);
			cumIdx[i] = (LL) (x * y) + cumIdx[i - 1];
			oper[i] = mp(x, y);
		}
	}
	
	bool awal = true;
	scanf("%d", &N);
	while(N--)
	{
		LL msk;
		scanf("%I64d", &msk);
		if(!awal) printf(" ");
		awal = false;
		
		int i = lower_bound(cumIdx + 1, cumIdx + M + 1, msk) - cumIdx;
		while(oper[i].se != -1)
		{
			msk -= cumIdx[i-1];
			msk = ((msk - 1LL) % (LL)oper[i].fi) + 1LL;
			i = lower_bound(cumIdx + 1, cumIdx + M + 1, msk) - cumIdx;
			//cout << i << " " << msk << endl;
		}
		printf("%d", oper[i].fi);
	}
	printf("\n");
	return 0;
}

