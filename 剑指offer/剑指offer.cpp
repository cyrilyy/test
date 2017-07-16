//// 剑指offer.cpp : 定义控制台应用程序的入口点。
////
//
#include "stdafx.h"
//
//
//////矩阵中的路径
//#include <iostream>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//	bool hasPath(char* matrix, int rows, int cols, char* str)
//	{
//		row = rows;
//		col = cols;
//		used.resize(row * col);
//		int i = 0;
//		while (str[i] != '\0')
//			++i;
//		len = i;
//		bool re = false;
//		for (int i = 0; i < row; ++i)
//		{
//			for (int j = 0; j < col; ++j)
//			{
//				if (matrix[i*col + j] != str[0])
//					continue;
//				used[i*col + j] = 1;
//				solver(matrix, str, i, j, 1, re);
//				used[i*col + j] = 0;
//				if (re)
//					return true;
//			}
//		}
//		return false;
//	}
//private:
//	pair<int, int> op[5] = { {0,0}, { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
//	vector<int> used;
//	int row;
//	int col;
//	int len;
//	void solver(const char* matrix,const char* str, int x, int y,int pos,bool& re)
//	{
//		if (re)
//			return;
//		if (pos == len)
//		{
//			re = true;
//			return;
//		}
//		for (int i = 1; i < 5; ++i)
//		{
//			int tmpx = x + op[i].first;
//			int tmpy = y + op[i].second;
//			if (tmpx < row && tmpx >= 0 && tmpy < col && tmpy >= 0 && used[tmpx*col + tmpy] == 0 && matrix[tmpx*col+tmpy] == str[pos])
//			{
//				used[tmpx*col + tmpy] = 1;
//				++pos;
//				solver(matrix, str, tmpx, tmpy, pos, re);
//				used[tmpx*col + tmpy] = 0;
//				--pos;
//			}
//		}
//	}
//};
//int main()
//{
//	char* matrix = "AAAAAAAAAAAA";
//	char* str1 = "AAAAAAAAAAAA";
//	char* str2 = "AB";
//	Solution s;
//	cout << s.hasPath(matrix,3,4,str1) << endl;
//	cout << s.hasPath(matrix, 3, 4, str2) << endl;
//	return 0;
//}
//
//
//
////青蛙跳台阶
//#include <iostream>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//	int jumpFloor(int number) {
//		if (number == 1)
//			return 1;
//		if (number == 2)
//			return 2;
//		record.resize(number+1);
//		record[1] = 1;
//		record[2] = 2;
//		for (int i = 3; i <= number; ++i)
//			record[i] = record[i - 1] + record[i - 2];
//		return record[number];
//	}
//private:
//	vector<int> record;
//};
//int main()
//{
//	int n;
//	Solution s;
//	while (cin >> n)
//		cout << s.jumpFloor(n) << endl;
//	return 0;
//}
//
//
////变态青蛙跳
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//
//class Solution {
//public:
//	int jumpFloorII(int number) {
//		if (number == 1)
//			return 1;
//		if (number == 2)
//			return 2;
//		times.resize(number + 1);
//		times[1] = 1;
//		times[2] = 2;
//		for (int i = 3; i <= number; ++i)
//		{
//			times[i] = 1;
//			for (int j = 1; j < i; ++j)
//				times[i] += times[i - j];
//		}
//		return times[number];
//	}
//private:
//	vector<int> times;
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	Solution s;
//	cout << s.jumpFloorII(n) << endl;
//	return 0;
//}
//
////最小的k个数
////二分法,思想类似快排
//#include <iostream>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		int pivot = input[0];
//		int len = input.size();
//		if (k < 1 || len < 1 || len < k)
//			return vector<int>();
//		int left = 0, right = len;
//		while (left < right)
//		{
//			do
//			{
//				++left;
//			} while (left < len && input[left] < pivot);
//			do 
//			{
//				--right;
//			} while (right >= 0 && input[right] > pivot);
//			if (left < right)
//			{
//				swap(input[left], input[right]);
//			}
//		}
//		swap(input[0], input[right]);
//		vector<int> fhalf(input.begin(), input.begin() + right + 1);
//		vector<int> bhalf(input.begin() + right + 1, input.end());
//		if (fhalf.size() == k)
//			return fhalf;
//		else if (fhalf.size() > k)
//			return GetLeastNumbers_Solution(fhalf, k);
//		else
//		{
//			vector<int> tmp = GetLeastNumbers_Solution(bhalf, k-fhalf.size());
//			for (auto i : tmp)
//				fhalf.push_back(i);
//			return fhalf;
//		}
//	}
//};
//int main()
//{
//	vector<int> nums = {0, 5, 1, 6, 2, 7, 3, 8};
//	Solution s;
//	vector<int> re = s.GetLeastNumbers_Solution(nums, 0);
//	for (auto i : re)
//		cout << i << " ";
//	cout << endl;
//	return 0;
//}
//
//
//////根据前序和中序重建二叉树
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//
// struct TreeNode {
//     int val;
//     TreeNode *left;
//	 TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
//class Solution {
//public:
//	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
//	{
//		int len = pre.size();
//		if (len < 1)
//			return NULL;
//		int root = pre[0];
//		TreeNode* ptr = new TreeNode(root);
//		vector<int>::iterator iter = find(vin.begin(), vin.end(), root);
//		int left_len = iter - vin.begin();
//		vector<int>pre_left, pre_right, vin_left, vin_right;
//		int i = 0;
//		for (; i < left_len; ++i)
//		{
//			vin_left.push_back(vin[i]);
//			pre_left.push_back(pre[i + 1]);
//		}
//		for (++i; i < len; ++i)
//		{
//			vin_right.push_back(vin[i]);
//			pre_right.push_back(pre[i]);
//		}
//		ptr->left = reConstructBinaryTree(pre_left, vin_left);
//		ptr->right = reConstructBinaryTree(pre_right, vin_right);
//		return ptr;
//	}
//	void preorder(TreeNode* root)
//	{
//		if (!root)
//			return;
//		cout << root->val << " ";
//		preorder(root->left);
//		preorder(root->right);
//	}
//};
//int main()
//{
//	vector<int> pre = { 1,2,4,7,3,5,6,8 };
//	vector<int> vin = { 4,7,2,1,5,3,8,6 };
//	Solution s;
//	TreeNode* root = s.reConstructBinaryTree(pre, vin);
//	s.preorder(root);
//	return 0;
//}
//
//
////2个stack实现队列
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//
//
//class Solution
//{
//public:
//	void push(int node) 
//	{
//		stack1.push(node);
//	}
//
//	int pop() 
//	{
//		if (stack2.empty())
//		{
//			while(!stack1.empty())
//			{
//				stack2.push(stack1.top());
//				stack1.pop();
//			}
//		}
//		int top = stack2.top();
//		stack2.pop();
//		return top;
//	}
//
//private:
//	stack<int> stack1;
//	stack<int> stack2;
//};
//int main()
//{
//
//	return 0;
//}
//
//
////旋转数组的最小数字
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//
//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray)
//	{
//		int len = rotateArray.size();
//		if (len < 1)
//			return 0;
//		int left = 0, right = len - 1;
//		while (rotateArray[left] >= rotateArray[right])
//		{
//			if (left + 1 == right)
//			{
//				++left;
//				break;
//			}
//			int mid = left + (right - left) / 2;
//			if (rotateArray[mid] >= rotateArray[left])
//			{
//					left = mid;
//			} 
//			else if(rotateArray[mid] <= rotateArray[right])
//			{
//				right = mid;
//			}
//		}
//		return rotateArray[left];
//	}
//};
//
//int main()
//{
//	vector<int> nums{5,1,2,3,4};
//	Solution s;
//	cout << s.minNumberInRotateArray(nums) << endl;
//	return 0;
//}
//
//
////矩形覆盖
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//
//class Solution {
//public:
//	int rectCover(int number) {
//		if (number == 1)
//			return 1;
//		if (number == 2)
//			return 2;
//		times.resize(number+1);
//		times[1] = 1;
//		times[2] = 2;
//		for (int i = 3; i <= number; ++i)
//			times[i] = times[i - 1] + times[i - 2];
//		return times[number];
//	}
//	vector<int> times;
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	Solution s;
//	cout << s.rectCover(n) << endl;
//	return 0;
//}
//
//
//////判断B是不是A的子树
//////思路：寻找到和B根节点相等的A树节点，然后判断是否结构相同
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct TreeNode 
//{
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//	val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
//	{
//		bool result = false;
//		if (pRoot1 && pRoot2)
//		{
//			if (pRoot1->val == pRoot2->val)
//				result = isSame(pRoot1, pRoot2);
//			if (!result)
//				result = HasSubtree(pRoot1->left, pRoot2);
//			if (!result)
//				result = HasSubtree(pRoot1->right, pRoot2);
//		}
//		return result;
//	}
//private:
//	bool isSame(TreeNode* root1, TreeNode* root2)
//	{
//		if (root2 == NULL)
//			return true;
//		if (root1 == NULL)
//			return false;
//		if (root1->val != root2->val)
//			return false;
//		return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);		
//	}
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	Solution s;
//	return 0;
//}
//
//////栈的压入弹出序列
//////思路：复现压栈出栈操作
//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		stack<int> st;
//		size_t len = pushV.size();
//		size_t i = 0,j = 0;
//		for (; i < len; ++i)
//		{
//			if (!st.empty() && st.top() == popV[i])
//				st.pop();
//			while (j < len && pushV[j] != popV[i])
//			{
//				st.push(pushV[j]);
//				++j;
//			}
//			++j;
//		}
//		if (st.empty())
//			return true;
//		else
//			return false;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> pushV{ 1,2,3,4,5 };
//	vector<int> popV{ 4,3,5,1,2 };
//	cout << s.IsPopOrder(pushV, popV) << endl;;
//	return 0;
//}
//
//
//////Ugly Number
//////思路：复现压栈出栈操作
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//	int GetUglyNumber_Solution(int index) 
//	{
//		if (index <= 0)
//			return 0;
//		vector<int> vec(index,1);
//		int pos_2 = 0, pos_3 = 0, pos_5 = 0;
//		int re_2, re_3, re_5;
//		for (int i = 1; i < index; ++i)
//		{
//			re_2 = vec[pos_2] * 2;
//			re_3 = vec[pos_3] * 3;
//			re_5 = vec[pos_5] * 5;
//			vec[i] = min(min(re_2,re_3),re_5);
//			while(vec[pos_2] * 2 <= vec[i])
//				++pos_2;
//			while (vec[pos_3] * 3 <= vec[i])
//				++pos_3;
//			while (vec[pos_5] * 5 <= vec[i])
//				++pos_5;
//		}
//		return vec[index - 1];
//	}
//};
//
//int main()
//{
//	Solution s;
//	int n;
//	cin >> n;
//	cout << s.GetUglyNumber_Solution(n) << endl;;
//	return 0;
//}
//
//
//
//
////二进制数中1的个数
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//	int  NumberOf1(int n) {
//		int count = 0;
//		while (n)
//		{
//			++count;
//			n &= (n - 1);
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	Solution s;
//	int n;
//	cin >> n;
//	cout << s.NumberOf1(n) << endl;;
//	return 0;
//}
//
//
//
//
//////数的次方
////
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//	double Power(double base, int exponent) {
//		int flag = 1;
//		if (abs(base) <= 0.000001)
//			return 0;
//		if (base < 0)
//		{
//			flag = -1;
//			base *= -1;
//		}
//		if (exponent == 0)
//			return 1;
//		if (exponent < 0)
//		{
//			base = 1 / base;
//			exponent *= -1;
//		}
//		double re = 1;
//		for (int i = 0; i < exponent; ++i)
//			re *= base;
//		if (flag == -1 && exponent % 2 == 1)
//			return -re;
//		else
//			return re;
//
//	}
//};
//
//int main()
//{
//	Solution s;
//	int n;
//	cin >> n;
//	return 0;
//}
//
//
//////两个链表的第一个公共结点
////
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//struct ListNode
//{
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//	val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//		if (pHead1 == NULL || pHead2 == NULL)
//			return NULL;
//		ListNode* ptr1 = pHead1, *ptr2 = pHead2;
//		while (ptr1 != ptr2)
//		{
//			ptr1 = ptr1 ? ptr1->next : pHead2;
//			ptr2 = ptr2 ? ptr2->next : pHead1;
//		}
//		return ptr1;
//	}
//};
//
//int main()
//{
//	Solution s;
//	int n;
//	cin >> n;
//	return 0;
//}
//
//
//
//
//
//////奇数位于偶数前
////
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		int pos_ji = 0, pos_ou = 0;
//		int len = array.size();
//		while (pos_ji < len)
//		{
//			while (pos_ji < len && array[pos_ji] % 2 == 0)
//				++pos_ji;
//			while (pos_ou < len && array[pos_ou] % 2 == 1)
//				++pos_ou;
//			if (pos_ji >= len)
//				break;
//			if (pos_ji > pos_ou)
//			{
//				for (int i = pos_ji; i > pos_ou; --i)
//					swap(array[i], array[i - 1]);
//				++pos_ji;
//				++pos_ou;
//			}
//			else
//				++pos_ji;
//		}
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> vec{ 1,3,5,7,2,4,6 };
//	s.reOrderArray(vec);
//	for (auto i : vec)
//		cout << i << " ";
//	cout << endl;
//	return 0;
//}
//
//
//
//
//
////链表的倒数第k个节点
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) :
//val(x), next(NULL) {
//}
//};
//class Solution {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		if (pListHead == NULL || k < 1)
//			return NULL;
//		ListNode* slow = pListHead, *fast = pListHead;
//		for (unsigned int i = 1; i < k && fast != NULL; ++i)
//			fast = fast->next;
//		if (fast == NULL)
//			return NULL;
//		while (fast->next)
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	return 0;
//}
//
//
////二叉树镜像
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//
//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};
//
//class Solution {
//public:
//	void Mirror(TreeNode *pRoot) {
//		if (pRoot == NULL || pRoot->left == NULL && pRoot->right == NULL)
//			return;
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//		TreeNode* tmp = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = tmp;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	return 0;
//}
//
//
//
////顺时针打印矩阵
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//
//class Solution {
//public:
//	vector<int> printMatrix(vector<vector<int> > matrix) {
//		vector<int> re;
//		int row = matrix.size();
//		if (row < 1)
//			return re;
//		int col = matrix[0].size();
//		int up = 0;
//		int down = row - 1;
//		int left = 0;
//		int right = col - 1;
//		while (up <= down && left <= right)
//		{
//			for (int i = left; i <= right; ++i)
//				re.push_back(matrix[up][i]);
//			for (int i = up + 1; i <= down; ++i)
//				re.push_back(matrix[i][right]);
//			if (up < down)
//			{
//				for (int i = right - 1; i >= left; --i)
//					re.push_back(matrix[down][i]);
//			}
//			if (left < right)
//			{
//				for (int i = down - 1; i > up; --i)
//					re.push_back(matrix[i][left]);
//			}
//			++up;
//			++left;
//			--down;
//			--right;
//		}
//		return re;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<vector<int>> vec{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
//	vector<int> re = s.printMatrix(vec);
//	for (auto i : re)
//		cout << i << " ";
//	cout << endl;
//	return 0;
//}
//
//
//////包含min函数的栈
//////思路：一个栈正常操作，另一个栈维护最小值，当push的元素比最小栈栈顶元素小或等，则入栈；pop时，当pop元素等于栈顶元素，则最小栈pop栈顶元素；
//#include <iostream>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
//
//
//
//class Solution {
//public:
//	void push(int value) {
//		nums.push(value);
//		if (min_nums.empty() || value <= min())
//			min_nums.push(value);
//	}
//	void pop() {
//		if (!nums.empty())
//		{
//			if (nums.top() == min_nums.top())
//				min_nums.pop();
//			nums.pop();
//		}
//	}
//	int top() {
//		if (nums.empty())
//			return 0;
//		return nums.top();
//	}
//	int min() {
//		if (min_nums.empty())
//			return 0;
//		return min_nums.top();
//	}
//private:
//	stack<int> nums;
//	stack<int> min_nums;
//};
//
//
//int main()
//{
//	Solution s;
//	return 0;
//}
//
//
//
////包含min函数的栈
////思路：一个栈正常操作，另一个栈维护最小值，当push的元素比最小栈栈顶元素小或等，则入栈；pop时，当pop元素等于栈顶元素，则最小栈pop栈顶元素；
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;



class Solution {
public:
	template<typename T>
	void push(T value) {
		nums.push(value);
		if (min_nums.empty() || value <= min())
			min_nums.push(value);
	}
	template<typename T>
	void pop() {
		if (!nums.empty())
		{
			if (nums.top() == min_nums.top())
				min_nums.pop();
			nums.pop();
		}
	}
	template<typename T>
	T top() {
		if (nums.empty())
			return 0;
		return nums.top();
	}
	template<typename T>
	T min() {
		if (min_nums.empty())
			return 0;
		return min_nums.top();
	}
private:
	template<typename T>
	stack<T> nums;
	template<typename T>
	stack<T> min_nums;
};


int main()
{
	Solution s;
	return 0;
}