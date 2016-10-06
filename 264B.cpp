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

int N, good;
bool prime[100010];
vector<int> fact, num, lis;

int main()
{
	memset(prime,true,sizeof(prime));
	for(int i = 2; i*i<=100000;i++) if(prime[i])
		for(int j = 2; i*j<=100000;j++) prime[i*j] = false;
	for(int i = 2; i <= 100000; i++) if(prime[i]) 
	{
		num.pb(i);
		lis.pb(0);
	}
	
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&good);
		int temp = good;
		fact.clear();
		
		int longest = 0;
		for(int i = 0; i < num.size() && num[i]*num[i]<=good; i++) if(good%num[i]==0)
		{
			fact.pb(i);
			longest = max(longest, lis[i] + 1);
			while(temp%num[i]==0) temp/=num[i];
		} 
		
		if(temp>1) 
		{
			int i = lower_bound(num.begin(),num.end(),temp)-num.begin();
			fact.pb(i);
			longest = max(longest, lis[i] + 1);
		}
		
		for(int i = 0; i < fact.size(); i++) lis[fact[i]] = max(lis[fact[i]], longest);
	}
	
	int ans = 1;
	for(int i = 0; i < num.size(); i++) ans = max(ans, lis[i]);
	printf("%d\n",ans);
	return 0;
}

