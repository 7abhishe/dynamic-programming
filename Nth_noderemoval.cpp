#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    if (fast == NULL) {
        // If fast pointer has reached the end, remove the head node
        ListNode* temp = head->next;
        delete head;
        return temp;
    }
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    // Remove the nth node from the end
    ListNode* temp = slow->next;
    slow->next = temp->next;
    delete temp;
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    head = removeNthFromEnd(head, n);
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}
