#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();
        ListNode *p = l1, *q = l2, *curr = ans;
        int carry = 0;
        while (p != NULL || q != NULL)
        {
            int sum = 0;
            if (p != NULL)
            {
                sum += p->val;
            }
            if (q != NULL)
            {
                sum += q->val;
            }
            sum += carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != NULL)
                p = p->next;
            if (q != NULL)
                q = q->next;
        }
        if (carry > 0)
        {
            curr->next = new ListNode(carry);
        }
        return ans->next;
    }
};

void printList(ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val;
        node = node->next;
        if (node != nullptr)
            cout << " -> ";
    }
    cout << endl;
}

int main()
{
    // Create first list: 2 -> 4 -> 3
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(9);

    // Create second list: 5 -> 6 -> 4
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(9);

    Solution sol;
    ListNode *result = sol.addTwoNumbers(l1, l2);

    // Print the result
    printList(result);

    // Clean up memory (optional, but good practice)
    while (result != nullptr)
    {
        ListNode *temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
