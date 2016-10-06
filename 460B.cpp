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

int a, b, c;
vector<int> ans;

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	
	for(int i = 1; i <= 81; i++)
	{
		LL temp = 1;
		for(int j = 0; j < a; j++) temp *= (LL) i;
		temp = temp * (LL) b + (LL) c;
		
		if(temp > 0LL && temp < 1000000000LL) 
		{
			int beneran = (int) temp, tot = 0;
			
			while(beneran)
			{
				tot += beneran % 10;
				beneran /= 10;
			}
			
			if(tot == i) ans.pb((int) temp);
		}
	}
	
	printf("%d\n", (int) ans.size());
	for(int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], i + 1 == (int) ans.size() ? '\n' : ' ');
	return 0;
}

