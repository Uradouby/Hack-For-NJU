#include "List.h"
#include <cstdio>
#include <iostream>

List init() {
	List head = new Node;
	head->next = NULL;
	return head;
}

bool erase(List &head, int i) {
	if (head == NULL)
		return false;
	Node *pre = head, *p = head->next;
	for (int j = 0; j < i; j++) {
		if (p == NULL) {
			return false;
		}
		pre = pre->next;
		p = p->next;
	}
	if (p == NULL)
		return false;
	pre->next = p->next;
	delete p;
	return true;
}

bool insert(List &head, int i, int val) {
	if (head == NULL)
		return false;
	Node *p = head;
	bool ok = true;
	for (int j = 0; j < i; j++) {
		if (p == NULL) {
			return false;
		}
		p = p->next;
	}
	Node *newnode = new Node;
	newnode->val = val;
	newnode->next = p->next;
	p->next = newnode;
	return true;
}
void clear(List &head) {
	if (head == NULL)
		return;
	Node *p = head->next;
	while (p != NULL) {
		Node *pre = p;
		p = p->next;
		delete pre;
	}
	delete head;
	head = NULL;
}
void show(List &head) {
	if (head == NULL)
		return;
	Node *p = head->next;
	while (p != NULL) {
		std::cout << p->val << " ";
		p = p->next;
	}
	std::cout << std::endl;
}