#include <cstddef>
struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
{
  ListNode* res;
  int pos = 1;

  while (list1->next) {
    list1 = list1->next;
    pos++;

    if (pos <= a || pos >= b) {
      res = list1;
      res->next = list1->next;
    }

    if (pos == a) {
      while (list2->next) {
        res = list2;
        res->next = list2->next;
        list2 = list2->next;
      }
    }
  }

  return res;
}


