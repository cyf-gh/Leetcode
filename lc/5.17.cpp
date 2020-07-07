#include <iostream>
using namespace std;

int GetLength(int x) {
	int len = 0;
	while (x) {
		x /= 10;
		len++;
	}
	return len;
}

int GetSameBit(int x) {
	int len = 1;
	x /= 10;
	while (x) {
		x /= 10;
		len *= 10;
	}
	return len;
}

int GetInverse( int x ) {
	int inver = 0;
	int cur = x;
	while (cur > 0)
	{
		int end = cur - cur / 10 * 10;

		if ((long)inver * 10 + end > INT_MAX) return false; // int都超过最大值肯定不是回文

		inver = (inver * 10 + end);
		cur /= 10;
	}
	return inver;
}

bool isPalindrome(int x) {
	if (x < 0) return false;

	int inver = 0;
	int cur = x;
	while ( cur > 0 )
	{
		int end = cur - cur / 10 * 10;
		
		if ( (long)inver * 10 + end > INT_MAX ) return false; // int都超过最大值肯定不是回文

		inver = (inver * 10 + end);
		cur /= 10;
	}
	return inver == x;
}

int main() {

	// cout<<isPalindrome(11)<<" TRUE";
	cout << isPalindrome(12345678) << " FALSE";
	getchar();
	return 0;
}