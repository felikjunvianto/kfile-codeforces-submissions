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

char stone[100], com[100];
int pos, t;

int main()
{
	scanf("%s",stone);
	scanf("%s",com);
	
	pos = 0;
	int len = strlen(com);
	for(t=0;t < len; t++) if(stone[pos] == com[t]) pos++;
	printf("%d\n",pos + 1);
	return 0;
}

