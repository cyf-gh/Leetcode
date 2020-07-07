#include "inc.h"

void SplitZero(vector<int>& nums, vector<vector<int>>& res, bool& hasZero, int& negCount) {
	vector<int> t;

	for (auto n : nums) {
		if (n < 0)
		{
			negCount++;
		}
		if (n == 0)
		{
			hasZero = true;
			if (t.size() != 0)
			{
				res.push_back(vector<int>(t));
				t.clear();
			}
			continue;
		}
		t.push_back(n);
	}
	if (!t.empty())
	{
		res.push_back(t);
	}
}

int GetSum(vector<int>& vn, int start, int end) {
	int sum = 1;
	for (int i = start; i < end; ++i)
	{
		sum *= vn[i];
	}
	return sum;
}

int Process(vector<int>& vn) {
	int firstNegIndex = -1;
	int lastNegIndex = -1;
	int negCount = 0;

	if (vn.size() == 1)
	{
		return vn[0];
	}

	// ��ȡ��һ�������һ��������λ��
	for (int i = 0; i < vn.size(); i++)
	{
		if (vn[i] < 0)
		{
			firstNegIndex = firstNegIndex == -1 ? i : firstNegIndex; // ��ȡ��һ��λ��
			lastNegIndex = vn[i] < 0 ? i : lastNegIndex; // ���ϸ������һ��λ��
			negCount++;
		}
	}

	if (negCount % 2 == 0)
	{
		return GetSum(vn, 0, vn.size());
	}
	else {
		return max(GetSum(vn, firstNegIndex + 1, vn.size()), GetSum(vn, 0, lastNegIndex));
	}
}



int maxProduct(vector<int>& nums) {
	if (nums.size() == 1)
	{
		return nums[0];
	}

	vector<vector<int>> splited;
	bool hasZero = false;
	int negCount = 0;
	int nMAx = Process(nums);
	SplitZero(nums, splited, hasZero, negCount);
	if (!hasZero && negCount % 2 == 0) // ��0��ż��������
	{
		return GetSum(nums, 0, nums.size());
	}
	else {
		for (auto s : splited)
		{
			nMAx = max(Process(s), nMAx);
		}
	}
	return nMAx;
}

int main() {
	vector<int> input = { 0, -2, 0 };
	maxProduct(input);
	return 0;
}