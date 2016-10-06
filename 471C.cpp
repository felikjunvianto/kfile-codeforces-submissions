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

LL N;

bool check(int k, int adder)
{
	if(k == 0) return true;
	
	int num = 3 * (k - 1) + adder;
	LL temp = (N + (LL) num) / 3LL;
	temp = 8LL * temp + 1LL;
	
	int maksimum = (int) sqrt((double) temp);
	maksimum = (maksimum - 1) / 2;
	
	return maksimum >= num;
}

int binser(int adder)
{
	int kiri = 0, kanan = 2000000;
	while(kiri <= kanan)
	{
		int mid = (kiri + kanan) >> 1;
		bool okemid = check(mid, adder), okenext = check(mid + 1, adder);
		
		if(okemid && !okenext) return mid; else
			if(okemid && okenext) kiri = mid + 1; else
				if(!okemid) kanan = mid - 1;
	}
	
	return kanan;
}

int main()
{
	scanf("%I64d",&N);
	
	int sisa = 3 - (int)(N % 3LL);
	printf("%d\n", binser(sisa));
	return 0;
}

