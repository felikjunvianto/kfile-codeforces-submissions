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

string month[]={"January","February","March","April", 
                "May","June","July","August", 
				"September","October","November","December"};
				
int N,x;
char msk[30];

int main()
{
	scanf("%s",msk);
	scanf("%d",&N);
	for(x=0;x<12;x++) if(!strcmp(msk,month[x].c_str())) break;
	N=(N+x)%12;
	printf("%s\n",month[N].c_str());
	return 0;
}

