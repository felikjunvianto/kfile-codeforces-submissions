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

int N, M, W, A[100010], kecil, gede;
int kons[200010];

bool solve(int height)
{
	memset(kons, 0, sizeof(kons));
	
	int tambah = 0, sisa = M;

	for(int i = 1; i <= N; i++)
	{
		if(A[i] + tambah < height)
		{
			int kurang = height - (A[i] + tambah);
			if(kurang > sisa) return false;
			
			sisa -= kurang;
			kons[i + W - 1] += kurang;
			tambah += kurang;
		}
		
		tambah -= kons[i];
	}
	
	return true;
}

int binser(int L, int R)
{
	while(L <= R)
	{
		int mid = (L + R) >> 1;
		bool oke_mid = solve(mid), oke_next = solve(mid + 1);
		
		// cout << L << " " << R << " " << mid << " " << oke_mid << " " << oke_next << endl;
		
		if(oke_mid && !oke_next) return mid; else
			if(oke_mid && oke_next) L = mid + 1; else
				if(!oke_mid) R = mid - 1;
	}
	return R;
}

int main()
{
	scanf("%d %d %d", &N, &M, &W);
	kecil = INF, gede = -INF;
	for(int i = 1; i <= N; i++) 
	{
		scanf("%d", &A[i]);
		kecil = min(kecil, A[i]); gede = max(gede, A[i]);
	}
	
	printf("%d\n", binser(kecil, gede + M));
	return 0;
}

