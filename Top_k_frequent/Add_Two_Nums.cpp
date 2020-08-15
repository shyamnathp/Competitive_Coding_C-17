#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//int findReverseSum(ListNode* node, int i)
//{
//	static int sum = 0;
//
//	if (node->next == nullptr)
//	{
//		return (node->val)*pow(10, i);
//	}
//
//	return (node->val)*pow(10, i) + findReverseSum(node->next, i+1);
//}
//
//int main()
//{
//	ListNode* l1 = new ListNode(2);
//	l1->next = new ListNode(4);
//	l1->next->next = new ListNode(3);
//
//	ListNode* l2 = new ListNode(5);
//	l2->next = new ListNode(6);
//	l2->next->next = new ListNode(4);
//
//	int sum = findReverseSum(l1, 0) + findReverseSum(l2, 0);
//
//	int digit = sum % 10;
//	sum /= 10;
//	ListNode* root = new ListNode(digit);
//	ListNode* current = root;
//
//	while (sum > 0)
//	{
//		digit = sum % 10;
//		sum /= 10;
//		current->next = new ListNode(digit);
//		current = current->next;
//	}
//
//	return root;
//
//}

int main()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	int sum = 0, extra = 0;
	ListNode* root = new ListNode(0);
	ListNode* current = root;

	while (l1 || l2 || extra)
	{
		int l1Val = (l1 ? l1->val : 0);
		int l2Val = (l2 ? l2->val : 0);
		int sum = l1Val + l2Val + extra;
		extra = sum / 10;
		current->next = new ListNode(sum % 10);
		current = current->next;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}
	return root->next;
}