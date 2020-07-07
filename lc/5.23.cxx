/*
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "inc.h"
#include "5.23.h"

struct p {
	char ch;
	vector<int> is;
	p(char c) : ch(c) {}
};
vector<p*> ps;

bool contains( vector<int> p, int num ) {
	for (size_t i = 0; i < p.size(); i++)
	{
		if (p[i] == num) {
			return true;
		}
	}
	return false;
}

int GetMinMax(vector<int> *p, int& min, int& max) {
	for ( auto n : *p )
	{
		min = std::min(n, min);
		max = std::max(n, max);
	}
	return max - min + 1;
}

int GetLength(vector<int> p) {
	int min = 999999;
	int max = -1;
	for (auto n : p)
	{
		min = std::min(n, min);
		max = std::max(n, max);
	}
	int res = max - min + 1;
	return res < 0 ? 999999 : res;
}

vector<vector<int>> res;

void GetMin(int& min, int& max) {
	vector<int>* mm = &res[0];
	for ( int i = 0; i< res.size(); ++i )
	{
		mm = GetLength(res[i]) < GetLength(*mm) ? &res[i] : mm;
	}
	GetMinMax(mm, min, max);
}

void findMinNext( int i, int resI ) {
	if (i >= ps.size())
	{
		return;
	}
	res[resI].push_back(999999);
	for ( auto cur : ps[i]->is )
	{
		int curNearest = res[resI][i];
		int firstIndex = res[resI][0];
		if ( contains( res[resI], cur ) ) { // 重复字符串不能出现两遍
			continue;
		}
		res[resI][i] = curNearest;
		int lastNearest = GetLength(res[resI]);
		res[resI][i] = cur;
		int curLen = GetLength(res[resI]);

		// 使字符串保持最短
		res[resI][i] = curLen < lastNearest ? cur : curNearest;
	}
	++i;
	findMinNext(i, resI);
}
void getMinSub() {

	for ( int i = 0; i < ps[0]->is.size(); ++i )
	{
		vector<int> tmp;
		res.push_back(tmp);
		res[i].push_back(ps[0]->is[i]);//放入第一个
		findMinNext(1, i);
	}
}

bool isSub(string s, string t) {
	int sum = 0;
	int len = t.length();
	for (size_t i = 0; i < t.length(); i++)
	{
		for (size_t j = 0; j < s.length(); j++)
		{
			if ( t[i] == s[j] )
			{
				s[j] = '*';
				sum++;
				break;
			}
		}
	}
	return sum == len;
}

string minWindow(string s, string t) {
	if (t.length() > s.length())
	{
		return "";
	}
	if (t == s)
	{
		return s;
	}

	for ( auto tc : t ) {
		bool has = false;
		p * pp = new p( tc );
		for (size_t i = 0; i < s.length(); i++) {
			if ( s[i] == tc ) {
				pp->is.push_back(i);
				has = true;
			}
		}
		if (!has) return "";
		ps.push_back(pp); // 得到所有字符串的位置
	}
	if ( ps.size() == 0 || !isSub(s,t))
	{
		return "";
	}

	getMinSub();
	int min = 999999;
	int max = -1;
	GetMin(min, max);
	string res = s.substr(min, max - min + 1);
	return (res.length() < t.length()) ? "" : res;
}

int main() {
	string res = minWindow("abc",
		"ab");
	return 0;
}