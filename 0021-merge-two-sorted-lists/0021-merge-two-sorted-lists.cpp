/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                temp->next = new ListNode(l2->val);
                temp = temp->next;
                l2 = l2->next;
            } else {
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                l1 = l1->next;
            }
            
            
        }
        while (l1 != nullptr) {

            temp->next = new ListNode(l1->val);
            temp = temp->next;

            l1 = l1->next;
        }
        while (l2 != nullptr) {

            temp->next = new ListNode(l2->val);
            temp = temp->next;

            l2 = l2->next;
        }
        return ans->next;
    }
};