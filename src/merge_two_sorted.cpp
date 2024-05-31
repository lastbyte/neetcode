#include "definitions.h"
#include <__config>
#include <iostream>
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);

void testCase(ListNode *list1, ListNode *list2);

int main() {

  ListNode *list1 = new ListNode(1);
  list1->next = new ListNode(2);
  list1->next->next = new ListNode(3);

  ListNode *list2 = new ListNode(4);
  list2->next = new ListNode(5);
  list2->next->next = new ListNode(6);

  testCase(list1, list2);

  list1 = new ListNode(1);
  list1->next = new ListNode(5);
  list1->next->next = new ListNode(6);

  list2 = new ListNode(2);
  list2->next = new ListNode(3);
  list2->next->next = new ListNode(4);

  testCase(list1, list2);

  return 0;
}

void testCase(ListNode *list1, ListNode *list2) {
  std::cout << "List 1 : ";
  printList(list1);

  std::cout << "List 2 : ";
  printList(list2);

  ListNode *merged = mergeTwoLists(list1, list2);

  std::cout << "Merged list : ";
  printList(merged);
}

/*
 * @param list1 pointer to list 1
 * @param list2 pointer to list 2
 *
 * @return pointer to the merged list
 * */
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

  if (list1 == nullptr)
    return list2;
  if (list2 == nullptr)
    return list1;

  ListNode *head = nullptr, *itr = nullptr, *itr1 = list1, *itr2 = list2;

  if (itr1->val < itr2->val) {
    head = itr1;
    itr1 = itr1->next;
  } else {
    head = itr2;
    itr2 = itr2->next;
  }

  itr = head;

  while (itr1 != nullptr && itr2 != nullptr) {
    if (itr1->val < itr2->val) {
      itr->next = itr1;
      itr1 = itr1->next;
    } else {
      itr->next = itr2;
      itr2 = itr2->next;
    }
    itr = itr->next;
  }

  if (itr1 != nullptr) {
    itr->next = itr1;
  }

  if (itr2 != nullptr) {
    itr->next = itr2;
  }

  return head;
}
