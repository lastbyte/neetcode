#include "definitions.h"
#include <__config>
#include <iostream>
#include <vector>

ListNode *reverseList(ListNode *head);
void testcase(ListNode *list);

int main() {

  ListNode *list = new ListNode(1);
  list->next = new ListNode(2);
  list->next->next = new ListNode(3);
  list->next->next->next = new ListNode(4);

  testcase(list);

  list = new ListNode(1);

  testcase(list);

  list = new ListNode(1);
  list->next = new ListNode(2);

  testcase(list);

  list = nullptr;
  testcase(list);

  return 0;
}

ListNode *reverseList(ListNode *head) {

  if (head == nullptr)
    return head;

  ListNode *prev = nullptr;
  ListNode *curr = head;

  while (curr != nullptr) {
    ListNode *tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }

  return prev;
}

void testcase(ListNode *list) {
  std::cout << "Current list : ";
  printList(list);
  ListNode *rev = reverseList(list);
  std::cout << "Reversed list : ";
  printList(rev);
}

void printList(ListNode *head) {
  ListNode *itr = head;
  std::cout << "[ ";
  while (itr != nullptr) {
    std::cout << itr->val << " ";
    itr = itr->next;
  }
  std::cout << "]\n";
}
