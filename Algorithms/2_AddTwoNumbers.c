// task: https://leetcode.com/problems/add-two-numbers
// (time) complexity: O(length(l1)+length(l2))
// test 2 patch

void append(struct ListNode *l, int n) {
	l->val = n;
	l->next = NULL;
}

void insert(struct ListNode *l, int n) {
	// l != NULL
	while (l->next != NULL) {
		l = l->next;
	}
	l->next = (struct ListNode *) malloc(sizeof(struct ListNode));
	l->next->val = n;
	l->next->next = NULL;
}

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {

	struct ListNode *curr1 = l1; // temporary iterator through a list, for counting total number of elements
	int n1 = 0; // n1 = len(l1)
	while (curr1 != NULL) {
		curr1 = curr1->next;
		n1++;
	}

	struct ListNode *curr2 = l2;
	int n2 = 0; // n2 = len(l2)
	while (curr2 != NULL) {
		curr2 = curr2->next;
		n2++;
	}

	// if n1 contains less digits than n2, we are adding leading zeros to make number of digits equal
	while (n1 < n2) {
		insert(l1, 0);
		n1++;
	}
	while (n2 < n1) {
		insert(l2, 0);
		n2++;
	}
	free(curr2);
	free(curr1);

	int rest = 0;
	int n = (n1 > n2) ? (n1 + 1) : (n2 + 1);
	struct ListNode *resultList = (struct ListNode*) malloc(sizeof(struct ListNode));
	append(resultList, (l1->val + l2->val) % 10);
	rest = (l1->val + l2->val) / 10;
	l1 = l1->next;
	l2 = l2->next;
	while (l1 != NULL && l2 != NULL) {
		insert(resultList, (l1->val + l2->val + rest) % 10);
		rest = (l1->val + l2->val + rest) / 10;
		l1 = l1->next;
		l2 = l2->next;
	}
	if (rest != 0 && l1 == NULL && l2 == NULL) {
		insert(resultList, rest);
	}

	return resultList;
}