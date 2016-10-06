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

int N, a[333], pos, len; 
char ans[1000010];

void gerak(int src, int dest)
{
	if(src == dest) return;
	while(src < dest) 
	{
		ans[len++] = 'R';
		src++;
	}
	
	while(src > dest)
	{
		ans[len++] = 'L';
		src--;
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	pos = 1;
	len = 0;
	
	for(int isi = 1; isi <= N; isi++)
	{
		while(a[isi] > 0)
		{
			gerak(pos, isi); pos = isi;
			ans[len++] = 'P'; a[isi]--;
			if(a[isi] == 0) break;
			
			if(isi == 1) 
			{
				ans[len++] = 'R';
				pos++;
			} else
			{
				ans[len++] = 'L';
				pos--;
			}
		}
	}
	
	ans[len] = '\0';
	printf("%s\n", ans);
	return 0;
}

