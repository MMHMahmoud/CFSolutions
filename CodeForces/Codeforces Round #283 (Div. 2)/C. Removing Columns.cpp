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


string A[101];
bool goodr[101];

void __main() {
	int n, m;
	cin >> n >> m;
	REP(i, n) cin >> A[i];
	fill(goodr, goodr + n, 0);
	goodr[0] = 1;
	int lastgood = -1;
	int ans = 0;
	for (int j = 0; j < m; j++)
	{
		bool good = 1;
		vector<int> goodrv;
		for (int i = 1; i < n; i++)
		{
			if (!goodr[i] && A[i][j] < A[i - 1][j])
			{
				good = 0;
				ans++;
				break;
			}
			else if (A[i][j] > A[i - 1][j])
				goodrv.push_back(i);
		}
		if (good){
			REP(i, SZ(goodrv))
				goodr[goodrv[i]] = 1;
		}
	}
	cout << ans << endl;
}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "1 10\ncodeforces\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("0\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "4 4\ncase\ncare\ntest\ncode\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("2\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "5 4\ncode\nforc\nesco\ndefo\nrces\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #3 ...\n\tExpected: ");
	printf("4\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
