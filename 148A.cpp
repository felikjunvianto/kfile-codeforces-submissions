#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

int num[5], N, ans;
bool drag[100005];
int i, j;

int main()
{
	for(i=0;i<4;i++) scanf("%d",&num[i]);
	scanf("%d",&N);

	memset(drag,sizeof(drag),false);
	for(i=0;i<4;i++)
		for(j=1;num[i]*j<=N;j++)
			drag[j*num[i]] = true;
	
	ans = 0;
	for(i=1;i<=N;i++) if(drag[i]) ans++;
	printf("%d\n",ans);
	return 0;
}
