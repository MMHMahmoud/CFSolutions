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
	bool operator() (const int& lhs, const int& rhs) const
	{
		return lhs > rhs;
	}
};

map<int, int, classcomp> bm, ssm;
map<int, int> sm;

void __main() {
	int n, s;
	cin >> n >> s;
	REP(i, n){
		char ch;
		int p, q;
		cin >> ch >> p >> q;
		if (ch == 'B'){
			if (bm.find(p) == bm.end()) bm[p] = q;
			else bm[p] += q;
		}
		else{
			if (sm.find(p) == sm.end()) sm[p] = q;
			else sm[p] += q;
		}
	}
	int cnt = 0;
	for (auto it = sm.begin(); it != sm.end(); it++)
	{
		if (cnt >= s) break;
		ssm[it->first] = it->second;
		cnt++;
	}
	for (auto it = ssm.begin(); it != ssm.end(); it++)
		cout << "S " << it->first << " " << it->second << endl;
	
	cnt = 0;
	for (auto it = bm.begin(); it != bm.end(); it++)
	{
		if (cnt >= s) break;
		cout << "B " << it->first << " " << it->second << endl;
		cnt++;
	}
}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "6 2\nB 10 3\nS 50 2\nS 40 1\nS 50 6\nB 20 4\nB 25 10\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("S 50 8\nS 40 1\nB 25 10\nB 20 4\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
