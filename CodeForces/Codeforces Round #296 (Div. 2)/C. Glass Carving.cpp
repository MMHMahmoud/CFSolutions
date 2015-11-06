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


#ifndef _WIN64
	#define UNLINE_JUDGE
#endif

const int MAXN = 200000 + 7;

bool X[MAXN], Y[MAXN];

void __main() {
	int w, h, n;
	cin >> w >> h>>n;
	fill(Y, Y + h, 0);
	fill(X, X+w, 0);
	queue<int> q;
	
	ll minx = 0, maxx = w,
		miny = 0, maxy = h, 
		ans;
	map<int, int>  lbsx, lbsy;
	int curx = 0, cury=0;
	//vector<int> sumx, sumy;
	lbsx[0]= w;
	lbsy[0]= h;
	REP(i, n){
		char ch; 
		int pos;
		cin >> ch >> pos;
		if (ch == 'V') {
			auto elem = lbsx.lower_bound(pos);
			int cursum = elem->second;
			if (pos != elem->first)lbsx[elem->first] =  pos - elem->first;
			lbsx[pos] = cursum - (pos - elem->first);
		}
		if (ch == 'H')  {
			
		}
	}
}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "4 3 4\nH 2\nV 2\nV 3\nV 1\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("8\n4\n4\n2\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "7 6 5\nH 4\nV 3\nV 5\nH 2\nV 1\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("28\n16\n12\n6\n4\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
