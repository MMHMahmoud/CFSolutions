#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
//#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
#define REP(i,n) for(int i=0; i<n; i++)
#define REPs(i,x,n) for(int i=x; i<n; i++)
#define SZ(x) x.size()
#define VVII vector< vector< pair<int, int> > > 
#define mem(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define epsil 1e-9
#define infinit  1e8
#define ll long long
#define PI pair<int, int>
#define X first
#define Y second

#ifndef _WIN64
	#define UNLINE_JUDGE
#endif

const int MAXN = 100000 + 7;

ll K[MAXN], B[MAXN],
x1e[MAXN], x2e[MAXN];
pair<ll, ll> xe[MAXN];
ll nxt[MAXN];

bool comp(pair<ll, ll> a, pair<ll, ll> b){
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

void __main() {
	int n;
	int x1, x2;
	cin >> n >> x1 >> x2;
	REP(i, n){
		cin >> K[i] >> B[i];
		xe[i].first = x1*K[i] + B[i];
		xe[i].second = x2*K[i] + B[i];
	}
	sort(xe, xe + n, comp);
	fill(nxt, nxt + n, -1);
	/*int lstval = -1;
	REPs(i,1, n){
		if (xe[i].first != xe[i - 1].first)nxt[i - 1] = i, lstval = i;
	}
	int curval = lstval;
	for (int i = n - 1; i >= 0; i--){
		if (nxt[i]==lstval) 
	}*/
	REP(i, n-1){
		pair<ll, ll> cura, curb;
		//ll ib = i + 1;
		cura = xe[i], curb = xe[i+1];
		//while (cura.first == curb.first) curb = xe[++ib];
		if ((cura.first<curb.first && cura.second>curb.second) ||
			(cura.first>curb.first && cura.second<curb.second))
		{
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "4\n1 2\n1 2\n1 0\n0 1\n0 2\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("NO");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "2\n1 3\n1 0\n-1 3\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("YES");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "2\n1 3\n1 0\n0 2\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #3 ...\n\tExpected: ");
	printf("YES");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "2\n1 3\n1 0\n0 3\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #4 ...\n\tExpected: ");
	printf("NO");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
