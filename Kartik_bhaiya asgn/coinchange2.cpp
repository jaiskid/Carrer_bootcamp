#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007
int change(int amount, vector<int>& coins) {
	int n = coins.size();
	int t[n + 1][amount + 1];
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < amount + 1; j++) {
			if (i == 0)
				t[i][j] = 0;
			if (j == 0)
				t[i][j] = 1;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < amount + 1; j++) {
			if (coins[i - 1] <= j) {
				t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
			}
			else if (coins[i - 1] > j) {
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][amount];
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>coins;
	coins.resize(n);
	F(coins, n);
	P(coins, n);
	int amount;
	cin >> amount;
	cout << change(amount, coins);

}