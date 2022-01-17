#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "Deque.h"
using namespace std;
Deque::Deque()
{
	head = nullptr;
	tail = nullptr;
}
Deque::Deque(const Deque& d) {
	head = tail = nullptr;
	// Голова списка, из которого копируем:
	node* temp = d.head;
	// Пока не конец списка:
	while (temp != nullptr)
	{   // Передираем данные:
		insTail(temp->item);
		temp = temp->next;
	}
}
Deque::~Deque()
{
	node* temp = new node;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
}
void Deque::insHead(int n) {
	node* temp = new node;
	temp->prev = nullptr;
	temp->item = n;
	temp->next = head;
	if (head)
		head->prev = temp;
	else tail = temp;
	head = temp;
}
void Deque::insTail(int n) {
	node* tmp = new node;
	tmp->item = n;
	tmp->next = nullptr;
	tmp->prev = tail;
	if (tail)
		tail->next = tmp;
	else head = tmp;
	tail = tmp;
}
int Deque::delHead() {
	if (head) {
		int res = head->item;
		node* temp = head;
		if (head->next)
			head->next->prev = nullptr;
		else tail = nullptr;
		head = head->next;
		delete temp;
		return res;
	}
	else return -2000000000;
}
void Deque::cet() {
	struct node* pnt = head;
	struct node* prev = head;
	struct node* temp = nullptr;
	while (pnt) {
		if (num(abs(pnt->item)) && pnt == head) {
			temp = pnt;
			//pnt = pnt->next;
			head = pnt;
			prev = head;
		//delete temp;
			insHead(rb(abs(pnt->item)));
			pnt = pnt->next;
		}
		else if (num(abs(pnt->item)) && pnt->next == nullptr) {
			temp = pnt;
			insTail(rb(abs(pnt->item)));
			//prev->next = nullptr;
			//delete temp;
			break;
		}
		else if (num(abs(pnt->item))) {
			temp = pnt;
			//prev->next = pnt;
			insert(rb(abs(pnt->item)), find(pnt->item)+0);
			pnt = pnt->next->next;
		}
		else {
			prev = pnt;
			pnt = pnt->next;
		}
	}
}
bool Deque::num(int n) {
	if (n % 2 == 0)
		return true;
	return false;
}
int Deque::rb(int a) {
	int k=0;
	int n = a;
	while (n > 0) {
		n /=10;
		k++;
	}
	int* arr = new int[k];
	for (int i = 0; i < k; i++) {
		if (a > 0) {
			arr[i] = a % 10;
			a /= 10;
		}
	}
	sort(arr, arr + k);
	int z=0;
	for (int i = 0; i < k; i++) {
		if ((i + 1) != k) {
			z += arr[i];
			z *= 10;
		}
		else z += arr[i];
	}
	return z;
}
int Deque::find(int dataItem) 
{node* ptr; 
	ptr = head;
	int k = 0;
	do
{
		if (dataItem == ptr->item)
			return k;
		else {
			ptr = ptr->next;
			k++;
		}
	} while (ptr != head);
}
void Deque::insert(int data, int pos)
{
	node* tmp = new node;
	tmp->item = data;
	node* ptmp = head;
	if (ptmp == 0) {
		tmp->next = nullptr;
		tmp->prev = nullptr;
		head = tmp;
		tail = tmp;
		return;
	}
	int i = 0;
	while ((i < pos) && (ptmp->next)) {
		ptmp = ptmp->next;
		i++;
	}
	if (ptmp->next == 0) {
		ptmp->next = tmp;
		tmp->prev = ptmp;
		tmp->next = 0;
		tail = tmp;
		return;
	}
	ptmp->next->prev = tmp;
	tmp->next = ptmp->next;
	ptmp->next = tmp;
	tmp->prev = ptmp;
}
int Deque::delTail() {
	if (tail) {
		int res = tail->item;
		node* temp = tail;
		if (tail->prev)
			tail->prev->next = nullptr;
		else head = nullptr;
		tail = tail->prev;
		delete temp;
		return res;
	}
	else return -2000000000;
}
bool Deque::isEmpty() {
	if (head == nullptr)
		return true;
	return false;
}
void Deque::print()
{
	node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->item << " ";
		temp = temp->next;
	}
	cout << endl;
}
int Deque ::  min() {
	int k = 0;
	node* temp=head;
	while (temp != 0) {
		temp = temp->next;
		k++;
	}
	node* trm = head;
	int* arr = new int[k];
	for (int i = 0; i < k; i++) {
		if (trm != 0) {
			arr[i] = trm->item;
			trm=trm->next;
		}
	}
	sort(arr, arr + k);
	return arr[0];
}
void Deque::rec() {
	int a = min();
	int b = find(a);
	node* temp = head;
	int k = 0;
	while (temp != 0) {
		k++;
		temp = temp->next;
	}
	if (b == 0) {
		return;
	}
	else if (b == k-1) {
		insHead(a);
		delTail();
	}
	else {
		int c = remove(b);
		insHead(c);
	}
}
int Deque::remove(int pos)
{
	node* tmp = head;
	for (int i = 0; i < pos; i++) {
		if (tmp == 0) return 0;
		tmp = tmp->next;
	}
	tmp->next->prev = tmp->prev;
	if (tmp->prev != 0)
		tmp->prev->next = tmp->next;
	int res = tmp->item;
	delete tmp;
	return res;
}
