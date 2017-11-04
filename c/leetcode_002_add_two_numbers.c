/* You are given two non-empty linked lists representing two non-negative integers. */
/*  The digits are stored in reverse order and each of their nodes contain a single */
/*  digit. Add the two numbers and return it as a linked list. */
/* You may assume the two numbers do not contain any leading zero, except */
/*  the number 0 itself. */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

/*beats 95.83%*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;

  int digitSum;
  bool carryOver = false;
  struct ListNode *res = malloc(sizeof(*res));
  struct ListNode *resp = res;
  struct ListNode *elem1 = l1;
  struct ListNode *elem2 = l2;
  struct ListNode *nullElem = malloc(sizeof(*nullElem));
  nullElem->val = 0; nullElem->next = NULL;

   while (1) {
    digitSum = elem1->val + elem2->val;
    if (carryOver) digitSum++;
    carryOver = (digitSum > 9);
    resp->val = carryOver ? digitSum - 10 : digitSum;
    if (elem1->next == NULL && elem2->next == NULL) break;
    resp->next = malloc(sizeof(*res));
    resp = resp->next;
    elem1 = (NULL == elem1->next) ? nullElem : elem1->next;
    elem2 = (NULL == elem2->next) ? nullElem : elem2->next;
  }

  if (carryOver) {
    resp->next = calloc(1, sizeof(*res));
    resp = resp->next;
    resp->val=1;
  }

  resp->next=NULL;
  return res;
}

int main() {
    struct ListNode *l1 = malloc(3*sizeof(struct ListNode));
    struct ListNode *p1 = l1;
    p1->val = 2;
    p1->next = p1 + 1;
    p1++;

    p1->val = 4;
    p1->next = p1 + 1;
    p1++;

    p1->val = 3;
    p1->next = NULL;

    struct ListNode *l2 = malloc(5*sizeof(struct ListNode));
    struct ListNode *p2 = l2;
    p2->val = 5;
    p2->next = p2 + 1;
    p2++;

    p2->val = 6;
    p2->next = p2 + 1;
    p2++;

    p2->val = 4;
    p2->next = NULL;

    struct ListNode *p = addTwoNumbers(l1, l2);

    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
