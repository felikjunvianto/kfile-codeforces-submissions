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

int tambah, kurang, num;
int N, M, L, R;

int main()
{
	scanf("%d %d", &N, &M);
	
	tambah = kurang = 0;
	for(int i = 1; i <= N; i++) 
	{
		scanf("%d", &num);
		if(num == 1) tambah++; else kurang++;
	}
	
	while(M--)
	{
		scanf("%d %d", &L, &R);
		int tengah = R - L + 1;
		if(tengah & 1) printf("0\n");
			else if(tengah <= 2 * tambah && tengah <= 2 * kurang) printf("1\n");
				else printf("0\n");
	}
	return 0;
}

