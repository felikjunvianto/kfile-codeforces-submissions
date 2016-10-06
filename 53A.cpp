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

char msk[200];
vector<string> dict;
string cari;
int N,x;

int main()
{
	scanf("%s",msk);cari=msk;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",msk);
		dict.pb(msk);
	}
	
	sort(dict.begin(),dict.end());
	for(x=0;x<dict.size();x++) if(dict[x].find(cari)==0)
	{
		printf("%s\n",dict[x].c_str());
		break;
	}
	if(x==(int)dict.size()) printf("%s\n",cari.c_str());
	return 0;
}

