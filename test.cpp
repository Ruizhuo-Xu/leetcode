#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
	if (a[0] == b[0]) return a[1] < b[1];
	return a[0] < b[0];
}

int main() {
	
	// string s = "-11";
	// cout << stoi(s) << endl;
	// int x = 123;
	// cout << to_string(x).substr(1, 2) << endl;

	// vector<string> strs = {"abc", "bcd", "abe", "aba", "egh"};
	// map<string, int> mp;
	// for (string s : strs) {
	// 	mp[s]++;
	// }
	// for (pair<const string, int>& s : mp) {
	// 	// 要用引用必须要在键前面加上const
	// 	// cout << s.first << ' ' << s.second << endl;
	// 	s.second++;
	// }

	// for (auto s : mp) {
	// 	// auto 返回的是副本
	// 	// cout << s.first << ' ' << s.second << endl;
	// 	s.second++;
	// }

	// for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		// 使用迭代器返回的是指针
	// 	it->second++;
	// }
	// for (pair<string, int> s : mp) {
	// 	cout << s.first << ' ' << s.second << endl;
	// 	// s.second++;
	// }

	// vector<vector<int>> x = {{1, 2}, {1, 1}, {2, 2}, {0, 3}};
	// sort(x.begin(), x.end(), cmp);
	// reverse(x.begin(), x.end());
	// for (auto it : x) {
	// 	for (int i : it) {
	// 		cout << i << ' ';
	// 	}
	// 	cout << endl;
	// }
	// int a = 1, b = 2;
	// swap(a, b);
	// cout << a << ' ' << b <<endl;
	cout << (0 - 1) % 2 << endl;
	return 0;
}