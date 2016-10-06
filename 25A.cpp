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

int N,gen,gan,odd,even,x,temp;

int main()
{
	scanf("%d",&N);
	odd=even=0;
	for(x=1;x<=N;x++)
	{
		scanf("%d",&temp);
		if(temp&1)
		{
			odd++;
			gan=x;
		} else
		{
			even++;
			gen=x;
		}
	}
	
	printf("%d\n",odd==1?gan:gen);
	return 0;
}

