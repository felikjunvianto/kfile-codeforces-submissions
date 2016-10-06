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

int N,atas,bawah,x,temp;

int main()
{
	scanf("%d",&N);bawah=N-2;
	atas=0;
	for(x=2;x<=N-1;x++)
	{
		temp=N;
		while(temp)
		{
			atas+=temp%x;
			temp/=x;
		}
	}
	
	x=__gcd(atas,bawah);
	printf("%d/%d\n",atas/x,bawah/x);
	return 0;
}

