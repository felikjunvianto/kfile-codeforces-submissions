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

int cnt[11];
int x;

int main()
{
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < 6; i++) 
	{
		scanf("%d", &x);
		cnt[x]++;
	}
	
	int kaki = -1;
	for(int i = 0; i < 10 && kaki == -1; i++) if(cnt[i] >= 4) kaki = i;
	if(kaki != -1) cnt[kaki] -= 4;
	
	// apakah gajah?
	bool gajah = false;
	for(int i = 0; i < 10 && kaki != -1 && !gajah; i++) if(cnt[i] == 2) gajah = true;
	
	// apakah beruang?
	bool bear = false;
	int tempcnt = 0;
	for(int i = 0; i < 10 && kaki != -1 && !bear; i++) if(cnt[i] == 1) 
	{
		tempcnt++;
		if(tempcnt == 2) bear = true;
	}
	
	if(gajah) printf("Elephant\n"); else
		if(bear) printf("Bear\n"); else
			printf("Alien\n");
	return 0;
}

