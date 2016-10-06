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

int N, T;
char antri[100];
bool moved[100];

int main()
{
	scanf("%d %d",&N, &T);
	scanf("%s", antri);
	
	while(T--)
	{
		memset(moved, false, sizeof(moved));
		for(int i = 0; i + 1 < N; i++) if(antri[i] == 'B' && antri[i+1] == 'G' && !moved[i] && !moved[i+1])
		{
			swap(antri[i], antri[i+1]);
			moved[i] = moved[i+1] = true;
		}
	}
	
	printf("%s\n",antri);
	return 0;
}

