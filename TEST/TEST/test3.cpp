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
#include<unordered_map>
#include<unordered_set>
using namespace std;

unsigned long long fib(int n)
{
	int result, pre_result, next_older_result;
	result = pre_result = 1;
	while (n > 2)
	{
		n -= 1;
		next_older_result = pre_result;
		pre_result = result;
		result = pre_result + next_older_result;
	}
	if (n == 0)
	{
		return 0;
	}
	return result;
}
int main()
{
	int from, to;
	while (cin >> from >> to)
	{
		unsigned long long sum = fib(from);
		while (from != to)
		{
			from++;
			sum += fib(from);
		}
		cout << sum << endl;
	}
	return 0;
}

#if 0
//剪花布条
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		auto it = s.begin();
		int count = 0, flag = 0;
		while (it != s.end())
		{
			auto it2 = t.begin();
			flag = 0;
			while (*it == *it2)
			{
				flag = 1;
				it++;
				it2++;
				if (it2 == t.end())
				{
					count++;
					break;
				}

			}
			if (flag == 0)
			{
				it++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

//因数分解
int main()
{
	int n = 0;
	while (cin >> n)
	{
		printf("%d = ", n);
		int i = 0;
		for (i = 2; i <= sqrt(n); i++)
		{
			while (n != i)
			{
				if (n % i == 0)
				{
					printf("%d * ", i);
					n = n / i;
				}
				else 
					break;
			}
		}
		printf("%d\n", n); 
	}
	return 0;
}

//美国日期
int getDay(int year,int month, int day)
{
	if (month < 3)
	{
		year -= 1;
		month += 12;
	}
	int c = int(year / 100), y = year - 100 * c;
	int w = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (month + 1) / 10) + day - 1;
	w = (w % 7 + 7) % 7;
	return w;
}
int main()
{
	int year = 0;
	while (cin >> year)
	{
		if (year < 2000 && year > 9999)
		{
			continue;
		}
		cout << year << "-01-01" << endl;

		//1月的第三个星期一
		for (size_t i = 1;; i++)
		{
			if (getDay(year, 1, i) == 1)
			{
				cout << year << "-01-" << i + 14 << endl;
				break;
			}
		}
		//2月的第三个星期一
		for (size_t i = 1;; i++)
		{
			if (getDay(year, 2, i) == 1)
			{
				cout << year << "-02-" << i + 14 << endl;
				break;
			}
		}

		//5月的最后一个星期一
		for (size_t i = 31;; i--)
		{
			if (getDay(year, 5, i) == 1)
			{
				cout << year << "-05-" << i << endl;
				break;
			}
		}

		cout << year << "-07-04" << endl;

		//9月的第一个星期一
		for (size_t i = 1;; i++)
		{
			if (getDay(year, 9, i) == 1)
			{
				cout << year << "-09-0" << i << endl;
				break;
			}
		}

		//11月的第四个星期四
		for (size_t i = 1;; i++)
		{
			if (getDay(year, 11, i) == 4)
			{
				cout << year << "-11-" << i + 21 << endl;
				break;
			}
		}

		cout << year << "-12-25" << endl;
		cout << endl;
	}
	return 0;
}

//删除公共字符
int main()
{
	string strs, d;
	while (getline(cin, strs))
	{
		cin >> d;
		unordered_set<char> del;
		for (const auto& e : d)
		{
			del.insert(e);
		}
		auto it = strs.begin();
		while (it != strs.end())
		{
			while (it != strs.end() && del.find(*it) != del.end())
			{
				strs.erase(it);
				//it = strs.begin();
			}
			it++;
		}
		cout << strs;
	}
	return 0;
}

//连续最大和
int main()
{
	int a = 0, cur = 0, max = INT32_MIN;
	cin >> a;
	vector<int> nums;
	nums.resize(a);
	for (int i = 0; i < a; i++)
	{
		cin >> nums[i];
		cur += nums[i];
		if (max < cur)
		{
			max = cur;
		}
		if (cur < 0)
		{
			cur = 0;
		}
	}
	cout << max;
	return 0;
}



//给定两个数组,编写一个函数来计算它们的交集。
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_set<int> ump1;
	unordered_set<int> ump2;
	for (const auto& a : nums1)
	{
		ump1.insert(a);
	}
	for (const auto& b : nums2)
	{
		ump2.insert(b);
	}
	vector<int> res;
	for (const auto& e : ump1)
	{
		if (ump2.count(e))
		{
			res.push_back(e);
		}
	}
	return res;
}
int main()
{
	vector<int> nums1 = { 1,2,2,1 };
	vector<int> nums2 = { 2,2 };
	intersection(nums1, nums2);
	return 0;
}

//在大小为 2N 的数组 A 中有 N + 1 个不同的元素,其中有一个元素重复了 N 次。
//返回重复了 N 次的那个元素。
int repeatedNTimes(vector<int>& A)
{
	unordered_map<int, int> um;
	int res = 0;
	for (const auto e : A)
	{
		++um[e];
	}
	for (const auto i : um)
	{
		if (i.second == A.size() / 2)
		{
			res = i.first;
		}
	}
	return res;
}
int main()
{
	vector<int> A = { 1,2,3,3 };
	repeatedNTimes(A);
	return 0;
}

//给一非空的单词列表,返回前 k 个出现次数最多的单词。
//返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率,按字母顺序排序。
vector<string> topKFrequent(vector<string>& words, int k)
{
	map<string, int> mp;
	for (const auto i : words)
	{
		++mp[i];
	}
	multimap<int, string, greater<int>> mtp;
	for (const auto e : mp)
	{
		mtp.insert(make_pair(e.second, e.first));
	}
	vector<string> res;
	for (const auto a : mtp)
	{
		res.push_back(a.second);
		if (--k == 0)
		{
			break;
		}
	}
	return res;
}
int main()
{
	vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
	topKFrequent(words, 4);
	return 0;
}

//给定一棵二叉树,想象自己站在它的右侧,按照从顶部到底部的顺序,返回从右侧所能看到的节点值。
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = 0) :
		val(x), left(NULL), right(NULL) {}
};
void Find(TreeNode* root, vector<int>& res, int k)
{
	if (root != NULL)
	{
		if (k >= res.size())
		{
			res.push_back(root->val);
		}
		Find(root->right, res, k + 1);
		Find(root->left, res, k + 1);
	}
}
vector<int> rightSideView(TreeNode* root) 
{
	vector<int> res;
	Find(root, res, 0);
	return res;
}
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	//root->right->right = new TreeNode(4);
	rightSideView(root);
	return 0;
}

//给定一组不含重复元素的整数数组 nums,返回该数组所有可能的子集（幂集)。
//说明：解集不能包含重复的子集。
void helper(vector<vector<int> >& res, vector<int> tmp, vector<int>& nums, int level)
{
	if (tmp.size() <= nums.size())
	{
		res.push_back(tmp);
	}
	for (int i = level; i < nums.size(); i++) {
		tmp.push_back(nums[i]);
		helper(res, tmp, nums, i + 1);
		tmp.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums) 
{
	vector<vector<int>> res;
	vector<int> tmp;
	helper(res, tmp, nums, 0);
	return res;
}
int main()
{
	vector<int> num = { 1, 2, 3 };
	subsets(num);
	return 0;
}

//根据逆波兰表示法,求表达式的值。
//有效的运算符包括 + , -, *, / 。每个运算对象可以是整数,也可以是另一个逆波兰表达式。
int evalRPN(vector<string>& tokens)
{
	for (size_t i = 0; i < tokens.size(); i++)
	{
		if (tokens[i] == "+")
		{
			int num = stoi(tokens[i - 2]) + stoi(tokens[i - 1]);
			tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
			tokens.insert(tokens.begin() + (i - 2), to_string(num));
			i -= 2;
			continue;
		}
		if (tokens[i] == "-")
		{
			int num = stoi(tokens[i - 2]) - stoi(tokens[i - 1]);
			tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
			tokens.insert(tokens.begin() + (i - 2), to_string(num));
			i -= 2;
			continue;
		}
		if (tokens[i] == "*")
		{
			int num = stoi(tokens[i - 2]) * stoi(tokens[i - 1]);
			tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
			tokens.insert(tokens.begin() + (i - 2), to_string(num));
			i -= 2;
			continue;
		}
		if (tokens[i] == "/")
		{
			int num = stoi(tokens[i - 2]) / stoi(tokens[i - 1]);
			tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
			tokens.insert(tokens.begin() + (i - 2), to_string(num));
			i -= 2;
			continue;
		}
	}
	return stoi(tokens[0]);
}
int main()
{
	vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	evalRPN(tokens);
	return 0;
}

//给定一个整数数组,你需要寻找一个连续的子数组,如果对这个子数组进行升序排序,那么整个数组都会变为升序排序。
//你找到的子数组应是最短的,请输出它的长度。
int findUnsortedSubarray(vector<int>& nums)
{
	vector<int> tmp = nums;
	sort(nums.begin(), nums.end());
	size_t i = 0, j = nums.size() - 1;
	for (; i < nums.size() - 1; i++)
	{
		if (nums[i] != tmp[i])
		{
			break;
		}
	}
	for (; j > i; j--)
	{
		if (nums[j] != tmp[j])
		{
			break;
		}
	}
	if (i == j)
	{
		return 0;
	}
	return j - i + 1;
}
int main()
{
	vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
	findUnsortedSubarray(nums);
	return 0;
}

int compress(vector<char>& chars)
{
	for (size_t i = 0; i < chars.size() - 1; i++)
	{
		char ch = chars[i];
		int j = 1;
		while (i + 1 != chars.size() && ch == chars[i + 1])
		{
			j++;
			chars.erase(chars.begin() + i + 1);
		}
		if (j > 1)
		{
			while (j != 0)
			{
				int t = j % 10;
				j /= 10;
				chars.insert(chars.begin() + i + 1, '0' + t);
			}
			i++;
		}

	}
	return chars.size();
}
int main()
{
	vector<char> chars = { 'a','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b' };
	compress(chars);
	return 0;
}

//给定一个字符串,验证它是否是回文串,只考虑字母和数字字符,可以忽略字母的大小写。
bool isPalindrome(string s)
{
	auto it = s.begin();
	auto rit = s.rbegin();
	while (it != s.end() && rit != s.rend())
	{
		if (*it >= 'a' && *it <= 'z' || *it >= 'A' && *it <= 'Z' || *it >= '0'  && *it <= '9')
		{
			if (*it >= 'A' && *it <= 'Z')
			{
				*it += ' ';
			}
			if (*rit >= 'a' && *rit <= 'z' || *rit >= 'A' && *rit <= 'Z' || *rit >= '0' && *rit <= '9')
			{
				if (*it == *rit || *it == *rit + ' ')
				{
					s.erase(it);
					it = s.begin();
					if (s.size() == 1 || s.size() == 0)
					{
						return true;
					}
					s.pop_back();
					rit = s.rbegin();
				}
				else
				{
					return false;
				}
			}
			else
			{
				s.pop_back();
				rit = s.rbegin();
			}
		}
		else
		{
			s.erase(it);
			it = s.begin();
			rit = s.rbegin();
		}
	}
	return true;
}
int main()
{
	string s = "!D2mH2?.0:xe`7zkU:Ky`2r'CA.!w'ZI' ARhID9\"J!\"k1Kk`;!l7 \"sF2 3 'B`!efSlJ'0,4,zgy:2L ..PbTCSG,5m:!!:! \"YZ6:X'. XUIg :'`Mo SxGfSW!HAKE0Kh?!k\";2W0! h837y?Y?6k. 9:K\"!?!?!\"K:9 .k6?Y?y738h !0W2;\"k!?hK0EKAH!WSfGxS oM`': gIUX .'X:6ZY\" !:!!:m5,GSCTbP.. L2:ygz,4,0'JlSfe!`B' 3 2Fs\" 7l!;`kK1k\"!J\"9DIhRA 'IZ'w!.AC'r2`yK:Ukz7`ex:0.?2Hm2D!";
	isPalindrome(s);
	return 0;
}

//给定一个按照升序排列的整数数组 nums,和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//你的算法时间复杂度必须是 O(log n) 级别。
vector<int> searchRange(vector<int>& nums, int target)
{
	int right = nums.size() - 1, left = 0, mid = (right + left) / 2;
	int flag = 1;
	vector<int> ret = { -1,-1 };
	if (nums.size() < 2)
	{
		if (nums.size() == 0)
		{
			return ret;
		}
		else
		{
			if (nums[mid] == target)
			{
				ret = { mid,mid };
				return ret;
			}
			return ret;
		}
	}
	while (left < right)
	{
		if (nums[mid] == target)
		{
			int l = mid, r = mid;
			while (l >= 0 && nums[l] == target)
			{
				l--;
			}
			while (r <= nums.size() - 1 && nums[r] == target)
			{
				r++;
			}
			ret = { l + 1,r - 1 };
			return ret;
		}
		else if(nums[mid] > target)
		{
			right = mid;
			mid = (right + left) / 2;
		}
		else
		{
			left = mid;
			mid = (right + left) / 2;
		}
		if (mid == left || mid == right)
		{
			if (flag == 0)
			{
				break;
			}
			if (nums[left] == target)
			{
				mid = left;
			}
			if (nums[right] == target)
			{
				mid = right;
			}
			flag = 0;
		}
	}
	return ret;
}
int main()
{
	vector<int> nums = { 1,1,1,1,4 };
	int target = 4;
	searchRange(nums, target);
	return 0;
}

//实现一个 atoi 函数,使其能将字符串转换成整数。
int myAtoi(string str)
{
	auto it = str.begin();
	vector<int> num;
	int flag = 0;	
	while (it != str.end())
	{
		if (*it == ' ')
		{
			it++;
			continue;
		}
		else if (*it >= '0' && *it <= '9')
		{
			while (it != str.end() && *it >= '0' && *it <= '9')
			{
				num.push_back(*it - '0');
				it++;
			}
			break;
		}
		else if (*it == '+' || *it == '-')
		{
			if (*(it + 1) < '0' || *(it + 1) > '9')
			{
				return 0;
			}
			if (*it == '-')
			{
				flag = 1;
			}
		}
		else
		{
			break;
		}
		it++;
	}
	if (num.size() == 0)
	{
		return 0;
	}
	else
	{
		int ret = 0;
		int size = num.size() - 1;
		for (int i = 0; i <= size; i++)
		{
			ret += pow(10, size - i) * num[i];
			if (ret >= INT32_MAX || ret <= INT32_MIN)
			{
				if (flag == 1)
				{
					if (ret == INT32_MAX)
					{
						return -INT32_MAX;
					}
					return INT32_MIN;
				}
				return INT32_MAX;
			}
		}
		if (flag == 1)
		{
			return -ret;
		}
		return ret;
	}
}
int main()
{
	string str = "-91283472332";
	myAtoi(str);
	return 0;
}

struct HAR
{
	int x,y; 
	struct HAR* p; 
}
h[2];
void main()
{
	h[0].x = 1; h[0].y = 2;
	h[1].x = 3; h[1].y = 4;
	h[0].p = &h[1]; h[1].p = h;
	printf("%d,%d \n", (h[0].p)->x, (h[1].p)->y);
}

//给定两个二进制字符串,返回他们的和（用二进制表示)。输入为非空字符串且只包含数字 1 和 0
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

//给定一个整数数组 nums 和一个目标值 target,请你在该数组中找出和为目标值的那两个整数,并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是,你不能重复利用这个数组中同样的元素。
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

//给定一个非空数组,返回此数组中第三大的数。如果不存在,则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
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

//给定一个由整数组成的非空数组所表示的非负整数,在该数的基础上加一。
//最高位数字存放在数组的首位, 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外,这个整数不会以零开头。
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

//给定一个整数类型的数组 nums,请编写一个能够返回数组“中心索引”的方法。
//我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
//如果数组不存在中心索引,那么我们应该返回 - 1。如果数组有多个中心索引,那么我们应该返回最靠近左边的那一个。
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

//给定一个非负整数数组 A,返回一个数组,在该数组中, A 的所有偶数元素之后跟着所有奇数元素。
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

//给定一个字符串 S,返回 “反转后的” 字符串,其中不是字母的字符都保留在原地,而所有字母的位置发生反转。
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

//给定一个按非递减顺序排序的整数数组 A,返回每个数字的平方组成的新数组,要求也按非递减顺序排序。
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

//给定一个整数数组,判断是否存在重复元素。
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

//给定两个有序整数数组 nums1 和 nums2,将 nums2 合并到 nums1 中,使得 num1 成为一个有序数组。
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

//给定一个仅包含大小写字母和空格 ' ' 的字符串,返回其最后一个单词的长度。如果不存在最后一个单词,请返回 0 。
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

//判断一个整数是否是回文数。回文数是指正序（从左向右)和倒序（从右向左)读都是一样的整数。
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