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

struct garis
{
	int x, y, l;
};

garis l_ver[1010], l_hor[1010];
int ans, ver, hor;

int main()
{
	scanf("%d %d", &ver, &hor);
	
	int a, b, c;
	for(int i = 0; i < ver; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		l_ver[i] = (garis) {a, b, c};
	}
	
	for(int i = 0; i < hor; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		l_hor[i] = (garis) {a, b, c};
	}
	
	ans = 0;
	for(int i = 0; i < ver; i++)
		for(int j = 0; j < hor; j++)
			if(l_hor[j].x <= l_ver[i].x && l_ver[i].x <= l_hor[j].x + l_hor[j].l &&
			   l_ver[i].y <= l_hor[j].y && l_hor[j].y <= l_ver[i].y + l_ver[i].l)
			{
				int xp = l_ver[i].x, yp = l_hor[j].y;
				int shortest = min(min(xp - l_hor[j].x, l_hor[j].x + l_hor[j].l - xp),
								   min(yp - l_ver[i].y, l_ver[i].y + l_ver[i].l - yp));
			
				ans = max(ans, shortest);
			}
		
	printf("%d\n", ans);
	return 0;
}

