#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<memory>
#include<map>
#include<set>
using namespace std;

string addBinary(string a, string b)
{
	string big = b, small = a;
	if (a.size() > b.size())
	{
		big = a;
		small = b;
	}
	auto it = small.rbegin();
	auto it2 = big.rbegin();
	while (it != small.rend())
	{
		*it2 += *it - '0';
		it2++;
		it++;
	}
	it2 = big.rbegin();
	int flag = 0;
	while (it2 != big.rend())
	{
		while (*it2 > '1')
		{
			*it2 -= 2;
			if (it2 + 1 != big.rend())
			{
				(*(it2 + 1))++;
			}
			else
			{
				flag = 1;
			}
		}
		it2++;
	}
	if (flag == 1)
	{
		big.insert(big.begin(), '1');
	}
	return big;
}
int main()
{
	string a = "111", b = "111";
	addBinary(a, b);
	return 0;
}

#if 0
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> num;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if(nums[i] + nums[j] == target)
			{
				num = { i,j };
				break;
			}
		}
		if (num.empty() == 0)
		{
			break;
		}
	}
	return num;
}
int main()
{
	vector<int> nums = { 11,2,15,7 };
	int target = 9;
	twoSum(nums, target);
	return 0;
}

//给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
int thirdMax(vector<int>& nums)
{
	vector<long long> max = { INT64_MIN,INT64_MIN,INT64_MIN };
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] > max[2])
		{
			if (nums[i] > max[1])
			{
				if (nums[i] > max[0])
				{
					max.insert(max.begin(), nums[i]);
				}
				else if(nums[i] == max[0])
				{
					continue;
				}
				else
				{
					max.insert(max.begin() + 1, nums[i]);
				}
			}
			else if (nums[i] == max[1])
			{
				continue;
			}
			else
			{
				max.insert(max.begin() + 2, nums[i]);
			}
		}
	}
	if (max[2] == INT64_MIN)
	{
		return max[0];
	}
	else
	{
		return max[2];
	}
}
int main()
{
	vector<int> nums = { 1,2 };
	thirdMax(nums);
	return 0;
}

//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。
vector<int> plusOne(vector<int>& digits)
{
	int flag = 0;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (++(digits[i]) < 10)
		{
			flag = 0;
			break;
		}
		flag = 1;
		digits[i] = 0;
	}
	if (flag == 1)
	{
		digits.insert(digits.begin(), 1);
	}
	return digits;
}
int main()
{
	vector<int> digits = { 9,9 };
	plusOne(digits);
	return 0;
}

//给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
//我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
//如果数组不存在中心索引，那么我们应该返回 - 1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
int pivotIndex(vector<int>& nums)
{
	if (nums.size() <= 2)
	{
		return -1;
	}
	int len = nums.size() - 1;
	for (int i = 0; i <= len; i++)
	{
		int left = i - 1, right = i + 1;
		int sum1 = 0, sum2 = 0;
		while (left >= 0)
		{
			sum1 += nums[left];
			left--;
		}
		while (right <= len)
		{
			sum2 += nums[right];
			right++;
		}
		if (sum1 == sum2)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	vector<int> nums = { -1, -1, -1, 0, 1, 1 };
	pivotIndex(nums);
	return 0;
}

//给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
vector<int> sortArrayByParity(vector<int>& A)
{
	vector<int> B;
	for (size_t i = 0; i < A.size(); i++)
	{
		if (A[i] % 2 == 0)
		{
			B.insert(B.begin(), A[i]);
		}
		else
		{
			B.insert(B.end(), A[i]);
		}
	}
	return B;
}
int main()
{
	vector<int> A = { 1,3,2,4 };
	sortArrayByParity(A);
	return 0;
}

//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
void Swaq(char& a, char& b)
{
	char t = a;
	a = b;
	b = t;
}
string reverseOnlyLetters(string S)
{
	size_t size = S.size();
	if (size == 0)
	{
		return S;
	}
	for (size_t i = 0, j = size - 1; i < j; i++, j--)
	{
		if (S[i] >= 'A' && S[i] <= 'Z' || S[i] >= 'a' && S[i] <= 'z')
		{
			if (S[j] >= 'A' && S[j] <= 'Z' || S[j] >= 'a' && S[j] <= 'z')
			{
				Swaq(S[i], S[j]);
			}
			else
			{
				while (i < j && j < size && S[j] < 'A' || S[j] > 'Z' && S[j] < 'a' || S[j] > 'z')
				{
					j--;
				}
				if (i >= j || j >= size)
				{
					return S;
				}
				Swaq(S[i], S[j]);
			}
		}
		else
		{
			while (i < j && i < size - 1 && S[i] < 'A' || S[i] > 'Z' && S[i] < 'a' || S[i] > 'z')
			{
				i++;
			}
			if (i >= j || i >= size - 1)
			{
				return S;
			}
			if (S[j] >= 'A' && S[j] <= 'Z' || S[j] >= 'a' && S[j] <= 'z')
			{
				Swaq(S[i], S[j]);
			}
			else
			{
				while (i < j && j < size && S[j] < 'A' || S[j] > 'Z' && S[j] < 'a' || S[j] > 'z')
				{
					j--;
				}
				if (i >= j || j >= size)
				{
					return S;
				}
				Swaq(S[i], S[j]);
			}
		}
	}
	return S;
}

int main()
{
	string S = "-S2,_";
	reverseOnlyLetters(S);
	return 0;
}

//给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
vector<int> sortedSquares(vector<int>& A)
{
	for (size_t i = 0; i < A.size(); i++)
	{
		A[i] = A[i] * A[i];
	}
	sort(A.begin(), A.end());
	return A;
}
int main()
{
	vector<int> A = { -4, -1, 0, 3, 10 };
	A = sortedSquares(A);
	return 0;
}

bool isLongPressedName(string name, string typed) 
{
	if (name == typed)
	{
		return true;
	}
	else if (name.length() > typed.length())
	{
		return false;
	}
	else
	{
		bool flag = true;
		string name2 = name;
		for (int i = 0, j = 0; j < typed.length();)
		{
			if (name[i] == typed[j])
			{
				name2[i] = '#';
				i++;
				j++;
			}
			else 
			{
				if (name[i - 1] == typed[j])
				{
					j++;
				}
				else
				{
					i++;
				}
			}
		}
		for (int i = 0; i < name2.length(); i++)
		{
			if (name2[i] != '#')
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
}
int main()
{
	string name = "alex";
	string typed = "aaleex";
	isLongPressedName(name, typed);
	return 0;
}

//给定一个整数数组，判断是否存在重复元素。
bool containsDuplicate(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	auto it = nums.begin();
	while (it + 1 != nums.end() && it != nums.end())
	{
		if (*it == *(it + 1))
		{
			return true;
		}
		it++;
	}
	return false;
}
int main()
{
	vector<int> nums = { 1,9,5,7,6 };
	containsDuplicate(nums);
	return 0;
}

//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	nums1.resize(m);
	auto it1 = nums1.begin();
	auto it2 = nums2.begin();
	while (it2 != nums2.end())
	{
		while (it1 != nums1.end())
		{
			if (*it2 <= *it1)
			{
				nums1.insert(it1, *it2);
				it1 = nums1.begin();
				break;
			}
			else
			{
				it1++;
			}
		}
		if (it1 == nums1.end())
		{
			nums1.push_back(*it2);
			it1 = nums1.end();
		}
		it2++;
	}
}
int main()
{
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	int m = 3;
	vector<int> nums2 = { 2, 5, 6 };
	int n = 3;
	merge(nums1, m, nums2, n);
	return 0;
}

//给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
int lengthOfLastWord(string s)
{
	auto rit = s.rbegin();
	int count = 0;
	while (*rit == ' ')
	{
		s.pop_back();
		rit = s.rbegin();
	}
	while (rit != s.rend() && *rit != ' ')
	{
		count++;
		rit++;
	}
	return count;
}

int main()
{
	string s = "b   a    ";
	cout << lengthOfLastWord(s) << endl;
	return 0;
}

//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}
	string num = to_string(x);
	auto rit = num.rbegin();
	auto it = num.begin();
	while (it != num.end() && rit != num.rend())
	{
		if (*it != *rit)
		{
			return false;
		}
		it++;
		rit++;
	}
	return true;
}
int main()
{
	int x = 12321;
	isPalindrome(x);
	return 0;
}


//赎金信
bool canConstruct()
{
	string ransomNote = "aa";
	string magazine = "ab";
	auto it1 = ransomNote.begin();
	while (it1 != ransomNote.end())
	{
		auto it2 = magazine.begin();
		int flag = 0;
		while (it2 != magazine.end())
		{
			if (*it1 == *it2)
			{
				magazine.erase(it2);
				flag = 1;
				break;
			}
			it2++;
		}
		if (flag == 0)
		{
			return false;
		}
		it1++;
	}
	return true;
}

int main()
{
	canConstruct();
	return 0;
}

int main()
{
	vector<int> nums = { 1,3,5,6 };
	int target = 7;

	size_t n = 0;
	if (target <= nums[n])
	{
		return 0;
	}
	while (nums.size() != 1 && n <= nums.size() - 1)
	{
		n++;
		if (target <= nums[n])
		{
			return n;
		}
		if (n == nums.size() - 1)
		{
			break;
		}
	}
	return nums.size();
}

int main()
{
	vector<int> nums = { 3,2,2,3 };
	int val = 3;
	auto it = nums.begin();
	while (it != nums.end())
	{
		while (*it == val)
		{
			nums.erase(it);
			if (nums.size() == 0)
			{
				return 0;
			}
			it = nums.begin();
		}
		it++;
	}
	return nums.size();
}

int main()
{
	int x = 10;
	int y = 10;
	x = y = ++y;
	printf("%d %d", x, y);
	return 0;
}

//向右移动K个单位
int main()
{
	vector<int> nums = { 1,2,3,4,5,6 };
	int k = 3;
	while (k--)
	{
		nums.insert(nums.begin(), nums[nums.size() - 1]);
		nums.pop_back();
	}
	return 0;
}


//将所有大写字母转化成小写字母
int main()
{
	string str = "Hello";
	auto it = str.begin();
	while (it != str.end())
	{
		if (*it >= 'A' && *it <= 'Z')
		{
			*it = *it - 'A' + 'a';
		}
		it++;
	}
	cout << str << endl;
	return 0;
}

void test()
{
	map<int, int> mp;
	vector<pair<int, int>> vec;
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		vec.push_back(make_pair(i, i));
	}
	map<int, int> mp2(vec.begin(), vec.end());
	map<int, int> mp3(mp2.begin(), mp2.end());
	map<int, int> cp(mp3);

	for (const auto& e : mp2)
	{
		cout << e.first << ", " << e.second << endl;
	}  
}
int main()
{
	test();
	system("pause");
	return 0;
}

class A
{
public:
	int a = 10;
	int b = 20;
	int c = 30;
};

int main()
{
	shared_ptr<A> sp(new A());
	shared_ptr<A> cp(sp);
	shared_ptr<A> sp3(new A());
	sp3 = sp;
	return 0;
}

//int main()
//{
//	unique_ptr<a> up(new a());
//	up->a = 20;
//	unique_ptr<a> copy(up);
//	unique_ptr<a> up3(new a());
//	up3 = up;
//	return 0;
//}


//因子个数
int main() {
	int n, k, i;
	while (cin >> n) {
		k = 0;
		for (i = 2; i <= sqrt(n); i++)
			if (n % i == 0) {
				while (n % i == 0)n = n / i;
				k++;
			}
		if (n != 1)k++;
		cout << k << endl;
	}
	return 0;
}

//最难的问题
int main()
{
	string str;
	while (getline(cin, str))
	{
		auto it = str.begin();
		while (it != str.end())
		{
			if (*it == ' ')
			{
				it++;
			}
			else if (*it <= 'E')
			{
				*it += 21;
				it++;
			}
			else
			{
				*it -= 5;
				it++;
			}
		}
		cout << str << endl;
	}
	return 0;
}

//有假币
int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 1;
		if (num == 1)
		{
			count = 0;
		}
		while (num > 4)
		{
			num /= 2;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}

//求正数数组的最小不可组成和
int getFirstUnFormedNum(vector<int> arr, int len) 
{
	int sum = 0, min = arr[0];
	for (int i = 0; i < len; ++i)
	{
		sum += arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	vector<int> dp(sum + 1, 0);
	for (int i = 0; i < len; ++i)
	{
		for (int j = sum; j >= arr[i]; --j)
		{
			if (dp[j - arr[i]] + arr[i] > dp[j])
			{
				dp[j] = dp[j - arr[i]] + arr[i];
			}
		}
	}

	for (int i = min; i <= sum; ++i)
	{
		if (i != dp[i])
			return i;
	}
	return sum + 1;
}

int main()
{
	vector<int> arr = { 3,2,4 };
	int len = arr.size();
	int ret = getFirstUnFormedNum(arr, len);
	return 0;
}

int main()
{
	
	return 0;
}

int main()
{
	size_t n;
	while (cin >> n)
	{
		size_t x = pow(5, n) - 4;
		size_t y = pow(4, n) + n - 4;
		if (n == 0)
			break;
		else
		{
			cout << x << " " << y << endl;
		}
	}
	return 0;
}

void oddInOddEvenInEven(vector<int>& arr, int len)
{
	int i = 0, j = 1;
	while (i < len && j < len)
	{
		if (arr[i] % 2 != 0 && arr[j] % 2 == 0)
		{
			swap(arr[i], arr[j]);
			i += 2;
			j += 2;
			continue;
		}
		if (arr[i] % 2 == 0)
		{
			i += 2;
		}
		if (arr[j] % 2 != 0)
		{
			j += 2;
		}
	}
}

int main()
{
	vector<int> arr = { 7,7,9,5,1,6,7,9,3,2,6 };
	int len = arr.size();
	oddInOddEvenInEven(arr, len);
	return 0;
}

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}

int main()
{
	float n, r;
	while (cin >> n >> r)
	{
		if (n <= 2 * 3.14 * r)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}

int Jump(int num)
{
	if (num == 1)
	{
		return 1;
	}
	if (num == 2)
	{
		return 2;
	}
	int count = 1;
	for (int i = 1; i < num; i++)
	{
		count += Jump(num - i);
	}
	return count;
}

int jumpFloorII(int number)
{
	if (number == 1)
	{
		return 1;
	}
	if (number == 2)
	{
		return 2;
	}
	int count = 1;
	for (int i = 1; i < number; i++)
	{
		count += Jump(number - i);
	}
	cout << count << endl;
	return 0;
}

int main()
{
	int num = 3;
	cout << jumpFloorII(4) << endl;
	return 0;
}

int main()
{
	string num;
	while (cin >> num)
	{
		int cur = 0;
		while (num.size() > 1)
		{
			cur = 0;
			for (const auto& e : num)
			{
				cur += e - '0';
			}
			num = to_string(cur);
		}
		cout << cur << endl;
	}
	return 0;
}

void square(vector<vector<size_t>>& num)
{
	vector<vector<size_t>> num2 = { {1,1},{1,0} };
	size_t a = num[0][0] * num2[0][0] + num[1][0] * num2[0][1],
		b = num[0][0] * num2[0][1] + num[0][1] * num2[1][1],
		c = num[1][0] * num2[0][0] + num[1][1] * num2[1][0],
		d = num[1][0] * num2[0][1] + num[1][1] * num2[1][1];
	num[0][0] = a;
	num[0][1] = b;
	num[1][0] = c;
	num[1][1] = d;
}

int main()
{
	size_t num;
	while (cin >> num)
	{
		vector<size_t> count;
		for (size_t i = 0; i < num; i++)
		{
			size_t n = 0;
			cin >> n;
			count.push_back(n);
		}
		for (size_t i = 0; i < num; i++)
		{
			vector<vector<size_t>> number = { {1,1},{1,0} };
			for (size_t j = 1; j < count[i]; j++)
			{
				square(number);
			}
			vector<int> ret;
			ret.resize(5);
			int x = 0;
			while (number[0][0] != 0)
			{
				if (x == 4)
				{
					break;
				}
				ret[x] = number[0][0] % 10;
				number[0][0] /= 10;

				x++;
			}
			for (int i = 3; i >= 0; i--)
			{
				cout << ret[i];
			}
		}
		cout << endl;
	}
	return 0;
}

string ret;
string Down(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command);
string Up(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command);
string Left(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command);
string Right(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	command += 'R';
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;
	}
	if (Kratos_ways[i][j + 1] == 0)
	{
		string tmp = command;
		Right(Kratos_ways, i, j + 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i + 1][j] == 0)
	{
		string tmp = command;
		Down(Kratos_ways, i + 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i - 1][j] == 0)
	{
		string tmp = command;
		Up(Kratos_ways, i - 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	return ret;
}
string Left(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	command += 'L';
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;
	}
	if (Kratos_ways[i][j - 1] == 0)
	{
		string tmp = command;
		Left(Kratos_ways, i, j - 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i + 1][j] == 0)
	{
		string tmp = command;
		Down(Kratos_ways, i + 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i - 1][j] == 0)
	{
		string tmp = command;
		Up(Kratos_ways, i - 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	return ret;
}
string Down(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	command += 'D';
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;	
	}
	if (Kratos_ways[i][j + 1] == 0)
	{
		string tmp = command;
		Right(Kratos_ways, i, j + 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i][j - 1] == 0)
	{
		string tmp = command;
		Left(Kratos_ways, i, j - 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i + 1][j] == 0)
	{
		string tmp = command;
		Down(Kratos_ways, i + 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	return ret;
}
string Up(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	command += 'U';
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;
	}
	if (Kratos_ways[i][j + 1] == 0)
	{
		string tmp = command;
		Right(Kratos_ways, i, j + 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i][j - 1] == 0)
	{
		string tmp = command;
		Left(Kratos_ways, i, j - 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i - 1][j] == 0)
	{
		string tmp = command;
		Up(Kratos_ways, i - 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	return ret;
}
string Find(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;
	}
	if (Kratos_ways[i][j + 1] == 0)
	{
		Right(Kratos_ways, i, j + 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = "";
	}
	if (Kratos_ways[i][j - 1] == 0)
	{
		Left(Kratos_ways, i, j - 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = "";
	}
	if (Kratos_ways[i + 1][j] == 0)
	{
		Down(Kratos_ways, i + 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = "";
	}
	if (Kratos_ways[i - 1][j] == 0)
	{
		Up(Kratos_ways, i - 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = "";
	}
	return ret;
}
int main()
{
	size_t n, m;
	while (cin >> n >> m)
	{
		vector<vector<int>> Kratos_ways;
		Kratos_ways.resize(n + 2);
		for (size_t i = 0; i < n + 2; i++)
		{
			Kratos_ways[i].resize(m + 2, 1);
			for (size_t j = 1; i > 0 && i < n + 1 && j <= m; j++)
			{
				cin >> Kratos_ways[i][j];
			}
		}
		ret = Find(Kratos_ways, 1, 1, "");
		cout << "(0,0)" << endl;
		int i = 0, j = 0;
		for (const auto& e : ret)
		{
			if (e == 'R')
			{
				j++;
				cout << "(" << i << "," << j << ")" << endl;
			}
			if (e == 'L')
			{
				j--;
				cout << "(" << i << "," << j << ")" << endl;
			}
			if (e == 'U')
			{
				i--;
				cout << "(" << i << "," << j << ")" << endl;
			}
			if (e == 'D')
			{
				i++;
				cout << "(" << i << "," << j << ")" << endl;
			}
		}
		ret = "";
	}
	return 0;
}

void Down(vector<vector<int> > board, size_t i, size_t j, int sum, int& max);
void Right(vector<vector<int> > board, size_t i, size_t j, int sum,int& max)
{
	j++;
	sum += board[i][j];
	if (i == board.size() - 1 && j == board[i].size() - 1)
	{
		if (max < sum)
		{
			max = sum;
		}
	}
	if (j != board[i].size() - 1)
	{
		Right(board, i, j, sum, max);
	}
	if (i != board.size() - 1)
	{
		Down(board, i, j, sum, max);
	}
}
void Down(vector<vector<int> > board, size_t i, size_t j, int sum,int& max)
{
	i++;
	sum += board[i][j];
	if (i == board.size() - 1 && j == board[i].size() - 1)
	{
		if (max < sum)
		{
			max = sum;
		}
	}
	if (j != board[i].size() - 1)
	{
		Right(board, i, j, sum, max);
	}
	if (i != board.size() - 1)
	{
		Down(board, i, j, sum, max);
	}	
}
int getMost(vector<vector<int> > board)
{
	int sum = board[0][0];
	int max = 0;
	size_t i = 0, j = 0;
	Right(board, i, j, sum, max);
	Down(board, i, j, sum, max);
	return max;
}
int main()
{
	vector<vector<int> > board;
	board.resize(6, { 1,2,3,4,5,6 });
	getMost(board);
	return 0;
}


int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int count = 0;
		auto it1 = s1.begin();
		auto it2 = s2.begin();
		while (it1 != s1.end() && it2 != s2.end())
		{
			while (*it1 == *it2)
			{
				it1++;
				it2++;
			}
			auto tmp1 = it1;
			auto tmp2 = it2;

		}
		while (it1 != s1.end())
		{
			count++;
			it1++;
		}
		cout << count << endl;
	}
	return 0;
}


int getValue(vector<int> gifts, int n)
{
	int max = INT32_MIN;
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = i + 1; j < n; j++)
		{
			while (j < n && gifts[i] == gifts[j])
			{
				count++;
				j++;
			}
		}
		if (count > n / 2)
		{
			if (max < gifts[i])
			{
				max = gifts[i];
			}
		}
	}
	if (max > 0)
	{
		return max;
	}
	return 0;
}

int main()
{
	vector<int> gifts = { 1,2,3,2,2 };
	int n = 5;
	int ret = getValue(gifts, n);
	return 0;
}

int main()
{
	string str;
	while (cin >> str)
	{
		auto it = str.begin();
		while (it != str.end())
		{
			int flag = 0;
			auto nit = it + 1;
			while (nit != str.end())
			{
				while (nit != str.end() && *it == *nit)
				{
					flag = 1;
					str.erase(nit);
				}
				if (nit != str.end())
				{
					*nit++;
				}
			}
			if (flag == 1)
			{
				str.erase(it);
			}
			else
			{
				it++;
			}
		}
		if (str.empty())
		{
			cout << -1 << endl;
		}
		else
		{
			cout << str[0] << endl;
		}

	}
	return 0;
}


int FindYs(int s, int b)
{
	int sum = 1;
	for (int i = 1; i <= s; i++)
	{
		if (s % i == 0 && b % i == 0)
		{
			sum = i;
		}
	}
	return sum;
}
int main()
{
	int count, level;
	while (cin >> count >> level)
	{
		for (int i = 0; i < count; i++)
		{
			int beast = 0;
			cin >> beast;
			if (level >= beast)
			{
				level += beast;
			}
			else
			{
				level += FindYs(level, beast);
			}
		}
		cout << level << endl;
	}
	return 0;
}


//找两个数的最大公约数
int FindYs(int s, int b)
{
	int sum = 1;
	for (int i = 1; i <= s; i++)
	{
		if (s % i == 0 && b % i == 0)
		{
			sum = i;
		}
	}
	return sum;
}
int main()
{
	int s = 0, b = 0;
	while (cin >> s >> b)
	{
		if (s > b)
		{
			swap(s, b);
		}
		cout << FindYs(s, b) << endl;
	}
	return 0;
}

template <class A>
A Add(A a, A b)
{
	return a + b;
}

int main()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	double e = 1.2, f = 2.2;
	//swap(a, b);
	//swap(c, d);
	//swap(e, f);
	Add(a, b);
	system("pause");
	return 0;
}
#endif