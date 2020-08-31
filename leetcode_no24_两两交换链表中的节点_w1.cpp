/*--------------------------------------------------------------------------------------|
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。								|
																						|
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。							|
																						|
 																						|
																						|
示例:																					|
																						|
给定 1->2->3->4, 你应该返回 2->1->4->3.													|
																						|
来源：力扣（LeetCode）																	|
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs								|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。					|
---------------------------------------------------------------------------------------*/

/*	
* 
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.6 MB, 在所有 C++ 提交中击败了15.42%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 ListNode* exchangeNode(ListNode *l1, ListNode *l2)
 {
	 l1->next = l2->next;
	 l2->next = l1;
	 return l2;
 }

ListNode* swapPairs(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* ans = new ListNode(0);
	ListNode* result = new ListNode(0);
	result = ans;

	while (head && head->next)
	{
		ans->next = exchangeNode(head, head->next);
		head = head->next;
		ans = ans->next->next;
	}
	return result->next;
}

int main()
{
	ListNode* Head = new ListNode(0);
	ListNode* head = Head;
	Head->next = new ListNode(1);
	Head = Head->next;
	Head->next = new ListNode(2);
	Head = Head->next;
	Head->next = new ListNode(3);
	//Head = Head->next;
	//Head->next = new ListNode(4);

	head = head->next;

	swapPairs(head);
}