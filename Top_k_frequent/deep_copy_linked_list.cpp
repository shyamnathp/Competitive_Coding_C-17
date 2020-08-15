#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL)
			return nullptr;

		Node* newHead= new Node(head->val);

		auto p = newHead;
		auto p1 = head->next;
		while (p1 != NULL)
		{
			p->next = new Node(p1->val);
			p1 = p1->next;
			p = p->next;
		}

		p = newHead;
		p1 = head;
		for (auto p = newHead; p != NULL; p=p->next)
		{
			p->random = p1;
			Node* temp = p1->next;
			p1->next = p;
			p1 = temp;
		}

		p1 = head;
		for (auto p = newHead; p != NULL; p = p->next, p1 = p1->next)
		{
			if (p->random->random != NULL)
			{
				auto test = p->random;
				auto test1 = p->random->random;
				auto test2 = p->random->random->next;
				p->random = p->random->random->next;
			}
			else
				p->random = NULL;

			if (p->next != NULL)
				p1->next = p->next->random;
			else
				p1->next = NULL;
		}

		return newHead;

	}
};

int main()
{
	vector<int> k = { 7, 13, 11, 10, 1 };
	vector<Node*> nodes = vector<Node*>(5);
	for (int i = 0; i < 5; ++i)
		nodes[i] = new Node(k[i]);

	for (int i=0;i<5;++i)
	{
		if (i != 4)
			nodes[i]->next = nodes[i + 1];
		else
			nodes[i]->next = NULL;
	}
	nodes[0]->random = NULL;
	nodes[1]->random = nodes[0];
	nodes[2]->random = nodes[4];
	nodes[3]->random = nodes[2];
	nodes[4]->random = nodes[0];
	Solution s;
	auto newHead = s.copyRandomList(nodes[0]);
}


//right solution
//
// Here's how the 2nd algorithm goes.
// Consider l1 as a node on the 1st list and l2 as the corresponding node on 2nd list.
// Step 1:
// Build the 2nd list by creating a new node for each node in 1st list. 
// While doing so, set the next pointer of the new node to the random pointer 
// of the corresponding node in the 1st list.  And set the random pointer of the 
// 1st list's node to the newly created node.
// Step 2:
// The new head is the node pointed to by the random pointer of the 1st list.
// Step 3:
// Fix the random pointers in the 2nd list: (Remember that l1->random is l2)
// l2->random will be the node in 2nd list that corresponds to the node in the 
// 1st list that is pointed to by l2->next, 
// Step 4:
// Restore the random pointers of the 1st list and fix the next pointers of the 
// 2nd list. random pointer of the node in 1st list is the next pointer of the 
// corresponding node in the 2nd list.  This is what we had done in the 
// 1st step and now we are reverting back. next pointer of the node in 
// 2nd list is the random pointer of the node in 1st list that is pointed to 
// by the next pointer of the corresponding node in the 1st list.
// Return the new head that we saved in step 2.
//

RandomListNode *copyRandomList(RandomListNode *head) {
	RandomListNode *newHead, *l1, *l2;
	if (head == NULL) return NULL;

	for (l1 = head; l1 != NULL; l1 = l1->next) {
		l2 = new RandomListNode(l1->label);
		l2->next = l1->random;
		l1->random = l2;
	}

	newHead = head->random;
	for (l1 = head; l1 != NULL; l1 = l1->next) {
		l2 = l1->random;
		l2->random = l2->next ? l2->next->random : NULL;
	}

	for (l1 = head; l1 != NULL; l1 = l1->next) {
		l2 = l1->random;
		l1->random = l2->next;
		l2->next = l1->next ? l1->next->random : NULL;
	}

	return newHead;
}

//another solution
public RandomListNode copyRandomList(RandomListNode head) {
	if (head == null) return null;

	Map<RandomListNode, RandomListNode> map = new HashMap<RandomListNode, RandomListNode>();

	// loop 1. copy all the nodes
	RandomListNode node = head;
	while (node != null) {
		map.put(node, new RandomListNode(node.label));
		node = node.next;
	}

	// loop 2. assign next and random pointers
	node = head;
	while (node != null) {
		map.get(node).next = map.get(node.next);
		map.get(node).random = map.get(node.random);
		node = node.next;
	}

	return map.get(head);
}
