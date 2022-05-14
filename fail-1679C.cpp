#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1e9

using namespace std;

const int MAX = 200020;

int Q, N;
vector<int> segRowTree, segColTree;

int update(vector<int> &tree, int now, int L, int R, int &idx, int val) {
	if(idx < L || R < idx) return tree[now];

	if(L == R) {
		if(L == idx) tree[now] += val;
		return min(1, tree[now]);
	}

	int mid = (L + R) / 2;
	int leftChild = now * 2 + 1;
	int leftL = L, leftR = mid;
	int left = update(tree, leftChild, leftL, leftR, idx, val);

	int rightChild = now * 2 + 2;
	int rightL = mid + 1, rightR = R;
	int right = update(tree, rightChild, rightL, rightR, idx, val);

	tree[now] = left + right;
	// if(tree == segRowTree) cout << "update " << now << " " << tree[now] << " " << left << " " << right << endl;
	return tree[now];
}

void print(vector<int> &tree, int now, int L, int R) {
	cout << "now = " << now << " range = " << L << ", " << R << " value = " << tree[now] << endl;
	if(L == R) return;

	int mid = (L + R) / 2;
	int leftChild = now * 2 + 1;
	int leftL = L, leftR = mid;
	print(tree, leftChild, leftL, leftR);

	int rightChild = now * 2 + 2;
	int rightL = mid + 1, rightR = R;
	print(tree, rightChild, rightL, rightR);
}

int query(vector<int> &tree, int now, int nowL, int nowR, int &l, int &r) {
	if(r < nowL || nowR < l) return 0;
	if(l <= nowL && nowR <= r) {
		// cout << "now = " << now << " is inside range (" << l << ", " << r << ")!";
		// if(nowL == nowR) cout << " value = " << min(1, tree[now]) << endl;
		// 	else cout << " value = " << tree[now] << endl;
		if(nowL == nowR) return min(1, tree[now]);
		return tree[now];
	}

	int mid = (nowL + nowR) / 2;
	int leftChild = now * 2 + 1;
	int leftL = nowL, leftR = mid;
	int left = query(tree, leftChild, leftL, leftR, l, r);

	int rightChild = now * 2 + 2;
	int rightL = mid + 1, rightR = nowR;
	int right = query(tree, rightChild, rightL, rightR, l, r);

	// cout << "query " << now << " " << nowL << " " << nowR << " " << l << " " << r << " = " << left + right << endl;
	return left + right;
}

int main()
{
	scanf("%d %d", &N, &Q);
	segRowTree = vector<int>(4 * MAX, 0);
	segColTree = vector<int>(4 * MAX, 0);

	while(Q--) {
		int type; scanf("%d", &type);

		int r, c, r1, c1, r2, c2;
		switch(type) {
			case 1:
				scanf("%d %d", &r, &c);
				update(segRowTree, 0, 1, N, r, 1);
				update(segColTree, 0, 1, N, c, 1);
				// print(segRowTree, 0, 1, N);
				break;
			case 2:
				scanf("%d %d", &r, &c);
				update(segRowTree, 0, 1, N, r, -1);
				update(segColTree, 0, 1, N, c, -1);
				break;
			case 3:
				scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
				
				int rowQuery = query(segRowTree, 0, 1, N, r1, r2);
				int colQuery = query(segColTree, 0, 1, N, c1, c2);

				bool rowOk = rowQuery == r2 - r1 + 1;
				bool colOk = colQuery == c2 - c1 + 1;
				
				printf("%s\n", rowOk || colOk ? "Yes" : "No");	
				break;
		}
	}

	return 0;
}

