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
	
string ans[]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
int N,dua,x;

int main()
{
	scanf("%d",&N);
	dua=1;
	while(N>0)
	{
		for(x=0;x<5;x++) 
		{
			N-=dua;
			if(N<1)
			{
				printf("%s\n",ans[x].c_str());
				break;
			}
		}
		dua*=2;
	}
	return 0;
}

