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

int N, terbesar;
PII num[300030];
vector<int> sisa, unik;

bool cf(PII i, PII j)
{
	return i.se < j.se;
}

int main()
{
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &num[i].fi);
		num[i].se = i;
	}
	
	sort(num, num + N);
	for(int i = 0; i < N; i++)
		if(!i || num[i].fi != num[i-1].fi) unik.pb(num[i].fi);
	terbesar = unik.back();
	
	int x = 0;
	while(x + 1 < N)
	{
		int y = x + 1;
		while(y < N && num[x].fi == num[y].fi) y++;
		y--;
		
		int patok = lower_bound(unik.begin(), unik.end(), num[x].fi) - unik.begin();
		if(patok + 1 < unik.size())
		{
			int kosong = unik[patok + 1] - unik[patok] - 1;	
			int jalan = x + 1;
			int next = unik[patok] + 1;
			while(kosong > 0 && jalan <= y)
			{
				num[jalan++].fi = next++;
				kosong--;
			}
			
			while(kosong > 0 && sisa.size() > 0)
			{
				int idx = sisa.back(); sisa.pop_back();
				num[idx].fi = next++;
				kosong--;
			}
			
			while(jalan <= y) sisa.pb(jalan++);
		} else
		
		{
			int next = unik[patok] + 1;
			for(int i = x + 1; i <= y; i++) 
			{
				num[i].fi = next++;
				terbesar = max(terbesar, num[i].fi);
			}
			
			while(sisa.size() > 0)
			{
				int idx = sisa.back(); sisa.pop_back();
				num[idx].fi = next++;
				terbesar = max(terbesar, num[idx].fi);
			}
		}
		
		x = y + 1;
	}
	
	++terbesar;
	while(sisa.size() > 0)
	{
		int idx = sisa.back(); sisa.pop_back();
		num[idx].fi = terbesar++;
	}
	
	
	sort(num, num + N, cf);
	for(int i = 0; i < N; i++)
		printf("%d%c", num[i].fi, i+1==N?'\n':' ');
	return 0;
}

