#include "inc.h"


int lengthOfLongestSubstring1(string s) {
	unordered_map<char, int>m;
	size_t curMax = 0;

	for (size_t i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (1 == m.count(c)) {
			curMax = max(m.size(), curMax);
			i = m[c];
			m.clear();
		} else {
			m[c] = i;
		}
	}
	return max(m.size(), curMax);
}

bool checkNextIsDigit( int i, string str) {
	return i + 1 < str.length() ? (str[i + 1] >= 48 && str[i + 1] <= 59) : false;
}

int myAtoi(string str) {
	double res = 0;
	bool isNeg = false;
	bool start = false;
	for ( int i = 0; i < str.length(); ++i )
	{
		char c = str[i];
		if ( ( c == ' ' ) && res == 0 && !start ) // 剔除前面的空格和0
			continue;

		if ( res == 0 && !start ) {
			if (c == '-')
			{
				isNeg = true;
				if (!checkNextIsDigit(i, str))
				{
					return 0;
				}
				continue;
			} 
			if ( c == '+')
			{
				isNeg = false;
				if (!checkNextIsDigit(i, str))
				{
					return 0;
				}
				continue;
			}
		}
		start = true;

		if ( c == '0' && res == 0 )
		{
			continue;
		}
		if (!(c >= 48 && c <= 59))
			goto END;

		else
			res = res * 10  + ( c - 48 ) ;
	}
	END:
	int r = 0;
	if ( isNeg )
		r = -res < INT_MIN ? INT_MIN : -res;
	else
		r = res > INT_MAX ? INT_MAX : res;
	return r;
}
int main() {
	string input;
	// cout << lengthOfLongestSubstring(input) << endl;
	// cout << lengthOfLongestSubstring(" ") << endl;
	cout << endl << myAtoi("0-1");
	return 0;
}

string longestCommonPrefix(vector<string>& strs) {
	string res = "";
	if (strs.size() == 0)
		return res;
	if (strs.size() == 1 )
		return strs[0];


	for (size_t j = 0; j < strs[0].length(); j++)
	{
		char c = strs[0][j];
		for ( size_t i = 1; i < strs.size(); ++i )
		{
			auto curStr = strs[i];
			if ( j == curStr.length() )
			{
				return res;
			}

			if ( curStr[j] != c )
			{
				return res;
			}
		}
		res += c;
	}
	return res;
}