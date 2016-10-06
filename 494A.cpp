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

char msk[100010];
int len;
stack<int> S;

int main()
{
	scanf("%s", msk); len = strlen(msk);
	
	vector<int> hPos, ans;
	for(int i = 0; i < len; i++)
	{
		if(msk[i] == '#') 
		{
			hPos.pb(i); 
			ans.pb(0);
		}
		
		else if(msk[i] == '(')
		{
			S.push(i); 
		}
		
		else if(msk[i] == ')')
		{
			if(S.empty())
			{
				printf("-1\n");
				return 0;
			}
			
			S.pop();
		}
	}
	
	while(!S.empty())
	{
		int now = S.top(); S.pop();
		int idx = lower_bound(hPos.begin(), hPos.end(), now) - hPos.begin();
		
		if(idx == hPos.size())
		{
			printf("-1\n");
			return 0;
		}
		
		ans[idx]++;
	}
	
	stack<int> kosong;
	for(int i = ans.size() - 1; i >= 0; i--) if(!ans[i]) kosong.push(i); else
	{
		while(ans[i] > 1 && !kosong.empty())
		{
			int now = kosong.top(); kosong.pop();
			ans[now]++;
			ans[i]--;
		}
	}
	
	if(!kosong.empty())
	{
		printf("-1\n");
		return 0;
	}
	
	for(int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
	return 0;
}

