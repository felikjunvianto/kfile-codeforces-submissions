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

int N, last, x, y, z;
bool used[10], bisa;

int main()
{
	scanf("%d",&N);
	scanf("%d",&last); last = 7 - last;
	scanf("%d %d",&x, &y);
	
	bisa = true; N--;
	while(N--)
	{
		memset(used,false,sizeof(used));
		scanf("%d %d",&x, &y);
		used[x] = used[7-x] = used[y] = used[7-y] = true;
		if(used[7 - last]) 
		{
			bisa = false;
			break;
		}
		last;
	}
	
	printf("%s\n",bisa?"YES":"NO");
	return 0;
}

