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

using namespace std;

int N,len;
char msk[200];

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",msk);
		len=strlen(msk);
		if(len<11) printf("%s\n",msk); else printf("%c%d%c\n",msk[0],len-2,msk[len-1]);
	}
	return 0;
}

