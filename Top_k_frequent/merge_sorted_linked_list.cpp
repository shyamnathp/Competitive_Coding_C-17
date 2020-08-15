#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class FunctorSort
{
	bool operator()(const ListNode& node1, const ListNode& node2) const
	{
		if (node1.val > node2.val)
		{
			ListNode* temp = NULL;
		}

		return node1.val < node2.val;
	}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode* p;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		if (p1->val > p2->val)
			p = p2;
		else
			p = p1;

		while (p1!=NULL and p2!=NULL)
		{
			if (p1->val > p2->val)
			{
				p->next = p2;
				p2 = p2->next;
			}
			else
			{
				p->next = p1;
				p1 = p1->next;
			}
			p = p->next;
		}

		p->next = p1 ? p1 : p2;

		return p;		
	}
};