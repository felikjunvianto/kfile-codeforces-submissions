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

int P,t,A,B,Da,Db;
bool oke;

int main()
{
	scanf("%d %d %d %d %d %d",&P,&t,&A,&B,&Da,&Db);
	
	if(!P) oke = true; else oke = false;
	
	for(int i=0;i<t && !oke;i++)
	{
		if( A - i*Da == P) oke = true;
		if( B - i*Db == P) oke = true;
	}
	
	for(int i=0;i<t && !oke;i++)
		for(int j =0;j<t && !oke;j++)
			if( A + B - i*Da - j*Db == P) oke = true;
	
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

