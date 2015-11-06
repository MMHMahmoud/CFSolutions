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


const int MAXV = 4000;
int A[MAXV + 7][MAXV + 7];
int B[MAXV + 7];
set<int> S[MAXV + 7];

void __main() {
	int n, m;
	cin >> n >> m;
	REP(i, n) REP(j, n) A[i][j] = 0;
	REP(i, n) S[i].clear();
	fill(B, B + n, 0);
	REP(i, m){
		int x, y;
		cin >> x >> y;
		x--, y--;
		A[x][y] = 1;
		A[y][x] = 1;
		S[x].insert(y);
		S[y].insert(x);
	}
	int ans = 1e8;
	vector<int> q1[MAXV+7];
	REP(i, n){
		
		REP(j, n){
			if (i == j) continue;
			if (A[i][j]){
				B[i]++;
				q1[i].PB(j);
			}
		}
	}
	REP(i, n){
		if (B[i] >= 2){
			REP(j, SZ(q1[i]) - 1){
				if (i == j) continue;
				int curitem = q1[i][j];
				for (int k = j + 1; k < SZ(q1[i]); k++){
					int curitem2 = q1[i][k];
					if (S[curitem].find(curitem2) != S[curitem].end())
					{
						ans = min(ans, max(B[i] - 2, 0) + max(B[curitem] - 2, 0) + max(B[curitem2] - 2, 0));
					}
				}
			}
		}
	}
	cout << (ans==1e8?-1:ans) << endl;
}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "3 3\
		3 1\
		3 2\
		2 1\
		");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("2\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "7 4\n2 1\n3 6\n5 1\n1 7\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("-1\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
