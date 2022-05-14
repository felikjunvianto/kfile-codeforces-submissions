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

struct node {
	int val, idx;
	bool operator>(const node &other) const {
		if(val != other.val) return val > other.val;
		return idx > other.idx;
	}

	bool operator<(const node &other) const {
		if(val != other.val) return val < other.val;
		return idx < other.idx;
	}
};


int T, N, rating[200010];
char like[200010];
priority_queue<node> max_hate_heap;
priority_queue<node, vector<node>, greater<node> > min_like_heap; 

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &rating[i]);
		scanf("%s", like);

		max_hate_heap = priority_queue<node>();
		min_like_heap = priority_queue<node, vector<node>, greater<node> >();
		for(int i = 0; i < N; i++) {
			node song = (node){rating[i], i};
			if(like[i] == '0') max_hate_heap.push(song);
				else min_like_heap.push(song);
		}

		if(!min_like_heap.empty() && !max_hate_heap.empty()) {
			while(min_like_heap.top() < max_hate_heap.top()) {
				node top_hate_song = max_hate_heap.top(); max_hate_heap.pop();
				node bottom_like_song = min_like_heap.top(); min_like_heap.pop();

				// cout << "swapping " << top_hate_song.val << " with " << bottom_like_song.val << endl;
				swap(rating[top_hate_song.idx], rating[bottom_like_song.idx]);

				max_hate_heap.push(bottom_like_song);
				min_like_heap.push(top_hate_song);
			}
		}

		for(int i = 0; i < N; i++) printf("%d%c", rating[i], i + 1 == N ? '\n' : ' ');
	}	
	return 0;
}

