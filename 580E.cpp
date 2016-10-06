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

struct node
{
	int l, r, toChange;
	string value;
};

const LL MOD1 = 1000000007LL;
const LL MOD2 = 1000000009LL;
const LL MOD3 = 1000000021LL;

int N, M, K;
char awal[100010];
node segtree[400040];

void initialize_tree(int idx, int l, int r)
{
	if(l == r)
	{
		segtree[idx].l = segtree[idx].r = l;
		segtree[idx].value = awal[l];
		segtree[idx].toChange = -1;
	} else
	{
		int mid = (l + r) >> 1;
		int leftIdx = 2 * idx + 1, rightIdx = leftIdx + 1;
		
		initialize_tree(leftIdx, l, mid);
		initialize_tree(rightIdx, mid + 1, r);
		
		segtree[idx].l = l;
		segtree[idx].r = r;
		segtree[idx].value = segtree[leftIdx].value;
		segtree[idx].value += segtree[rightIdx].value;
		segtree[idx].toChange = -1;
	}	
}

void refresh_value(int idx)
{
	if(segtree[idx].toChange == -1) return;
	
	segtree[idx].value = "";
	string unit(1, (char)(segtree[idx].toChange + '0'));
	for(int i = 0, bts = segtree[idx].r - segtree[idx].l + 1; i < bts; i++)
		segtree[idx].value += unit;
}

void propagate(int idx)
{
	if(segtree[idx].toChange == -1) return;

	refresh_value(idx);
	
	if(segtree[idx].l < segtree[idx].r)
	{
		int leftIdx = 2 * idx + 1, rightIdx = leftIdx + 1;
		segtree[leftIdx].toChange = segtree[rightIdx].toChange = segtree[idx].toChange;
	}
	
	segtree[idx].toChange = -1;
}

string fetch_data(int idx, int L, int R)
{
	if(segtree[idx].r < L || segtree[idx].l > R) return "";
	if(L <= segtree[idx].l && segtree[idx].r <= R)
	{
		refresh_value(idx);
		return segtree[idx].value;
	}
	
	propagate(idx);
	int leftIdx = 2 * idx + 1, rightIdx = leftIdx + 1;
	return fetch_data(leftIdx, L, R) + fetch_data(rightIdx, L, R);
}

void update(int idx, int L, int R, int newDigit)
{
	if(segtree[idx].r < L || segtree[idx].l > R) return;
	if(L <= segtree[idx].l && segtree[idx].r <= R) 
	{
		segtree[idx].toChange = newDigit;
		refresh_value(idx);
		return;
	}
	
	propagate(idx);
	int leftIdx = 2 * idx + 1, rightIdx = leftIdx + 1;
	
	update(leftIdx, L, R, newDigit);
	update(rightIdx, L, R, newDigit);
	
	segtree[idx].value = segtree[leftIdx].value;
	segtree[idx].value += segtree[rightIdx].value;
}

void print_tree(int idx)
{
	printf("%d -> (%d, %d, %d, %s)\n", idx, segtree[idx].l, segtree[idx].r, segtree[idx].toChange, segtree[idx].value.c_str());
	if(segtree[idx].l != segtree[idx].r)
	{
		int leftIdx = 2 * idx + 1, rightIdx = leftIdx + 1;
		print_tree(leftIdx);
		print_tree(rightIdx);
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	scanf("%s", awal + 1);
	
	initialize_tree(0, 1, N);
	
	int type, L, R, arg, total = M + K;
	while(total--)
	{
		scanf("%d %d %d %d", &type, &L, &R, &arg);
		if(type == 1) update(0, L, R, arg); else
		{
			string lToR = fetch_data(0, L, R);
			LL init1 = 0LL, init2 = 0LL, init3 = 0LL;
			
			for(int i = 0; i < arg; i++) 
			{
				init1 = ((init1 * 10LL) % MOD1 + (LL)(lToR[i] - '0')) % MOD1;
				init2 = ((init2 * 10LL) % MOD2 + (LL)(lToR[i] - '0')) % MOD2;
				init2 = ((init2 * 10LL) % MOD3 + (LL)(lToR[i] - '0')) % MOD3;
			}
				
			bool oke = true;
			LL temp1 = 0LL, temp2 = 0LL, temp3 = 0LL;
			
			//cout << lToR << " " << arg << " " << init << endl;
			for(int i = arg; i < lToR.size() && oke; i++)
			{
				temp1 = ((temp1 * 10LL) % MOD1 + (LL)(lToR[i] - '0')) % MOD1;
				temp2 = ((temp2 * 10LL) % MOD2 + (LL)(lToR[i] - '0')) % MOD2;
				temp2 = ((temp2 * 10LL) % MOD3 + (LL)(lToR[i] - '0')) % MOD3;
				if((i + 1) % arg == 0)
				{
					//cout << i << " " << temp << endl;
					oke = (temp1 == init1) && (temp2 == init2) && (temp3 == init3);
					temp1 = temp2 = temp3 = 0LL;
				}
			}
			
			printf("%s\n", oke ? "YES" : "NO");
		}
	}
	return 0;
}

