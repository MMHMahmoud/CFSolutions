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
#define epsil 1e-5
#define infinit  1e8
#define ll long long
#define PI pair<int, int>
#define X first
#define Y second

#ifndef _WIN64
	#define UNLINE_JUDGE
#endif


const int MAXN = 1e5 + 7;
int A[MAXN];
//double P[128][128];

//struct classcomp {
//	bool operator() (const double& lhs, const double& rhs) const
//	{
//		return (abs(lhs - rhs) < 1e-9);
//	}
//};

vector<double> poss;
void __main() {
	int n;
	cin >> n;
	REP(i, n)cin >> A[i];
	for (int i = -63; i <= 63; i++){
		for (int j = -63; j <= 63; j++){			
			double val = double(pow(2, i)) * pow(3, j);
			//poss.insert(val);
			poss.PB(val);
		}
	}
	REPs(i, 1, n){
		int a = A[0], b = A[i];
		if (a<b) swap(a, b);
		double val = (a / double(b));
		bool found = false;
		REP(j, SZ(poss)){
			if (abs(poss[j] - val) < 1e-13){
				found = 1;
				break;
			}
		}
		if (!found)
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	return;

}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "5\
		1000000000 999999999 999999998 999999997 999999996\
		");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("Yes\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "3\n100 150 250\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("No\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
