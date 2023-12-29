#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int main() {
	// string s = "-11";
	// cout << stoi(s) << endl;
	// cout << pow(2, 3) << endl;
	// cout << max(1, 2) << endl;
	// cout << (2 << 1) << endl;
	// vector<string> strs = {"abc", "bcd", "abe", "aba", "egh"};
	// map<string, int> mp;
	// for (string s : strs) {
	// 	mp[s]++;
	// }
	// for (pair<const string, int>& s : mp) {
		// 要用引用必须要在键前面加上const
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
	cout << pow(2, 30) << endl;

	return 0;
}