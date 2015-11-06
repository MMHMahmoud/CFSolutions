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

struct classcomp {
	bool operator() (const vector<int>& lhs, const vector<int>& rhs) const
	{
		return lhs[0]>rhs[0];
	}
};

//int A[200000];
int A[1010][1010];
int B[1010];
void __main() {
	int n;
	cin >> n;
	n = n * 2;
	fill(B, B + n, -1);
	set< vector<int>, classcomp > s;
	REP(i, n) REP(j, n) A[i][j] = -1;
	
	REPs(i,1, n){
		REP(j, i) {
			cin >> A[i][j];
			vector<int> myvec;
			myvec.push_back(A[i][j]); myvec.push_back(i); myvec.push_back(j);
			s.insert(myvec);
		}
	}
	int done = 0;
	//while (true)
	for (auto it = s.begin(); it != s.end(); it++)
	{
		auto cure = *it;
		int curmax = cure[0], curi = cure[1], curj = cure[2];
		if (B[curi]==-1 && B[curj]==-1){
			B[curi] = curj, B[curj] = curi;
			done += 2;
		}
		if (done == n) break;
	}
	REP(i, n)cout << B[i] + 1 << " ";

}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "2\n6\n1 2\n3 4 5\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("2 1 4 3\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "3\n487060\n3831 161856\n845957 794650 976977\n83847 50566 691206 498447\n698377 156232 59015 382455 626960\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("6 5 4 3 2 1\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
