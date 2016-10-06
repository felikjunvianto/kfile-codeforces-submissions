#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define LL long long
#define INF 1000000000
#define mp make_pair
#define pb push_back
#define PII pair<int,int> 

using namespace std;

int N, K, rem;

int main()
{
	scanf("%d %d",&N, &K);
	if(3*N <= K) printf("0\n"); else
	{
		rem = K - 2*N;
		printf("%d\n",N - rem);
	}
	return 0;
}

