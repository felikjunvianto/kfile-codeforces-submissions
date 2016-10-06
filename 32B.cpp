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

string num,code[]={".","-.","--"};
char msk[300];
int x;

int main()
{
	scanf("%s",msk);num=msk;
	while(num.size()) 
		for(x=0;x<3;x++) if(num.find(code[x])==0)
		{
			printf("%d",x);
			num.erase(0,(int)code[x].size());
			break;
		}
	printf("\n");
	return 0;
}

