#pragma once
class Deque		/* дек Ц двусторонн€ очередь */
{
	struct node			/* элемент дека */
	{
		int  item;	/* данные */
		struct  node* next;  /* указатель на следующий элемент */
		struct  node* prev;  /* указатель на предыдущий элемент */
	};
	/* указатели на первый и последний элементы в списке */
	struct node* head, * tail;
public:
	Deque();			// конструктор
	Deque(const Deque& d);	// конструктор копировани€
	~Deque();		/* деструктор */
	void insHead(int n);	/* включить элемент в голову дека */
	void insTail(int n);	/* включить элемент в хвост дека */
	int delHead();	      /* исключить элемент из головы дека */
	int delTail();	      /* исключить элемент из хвоста дека */
	bool isEmpty();		/* пустой дек? */
	void print();
	bool num(int n);
	void insert(int data, int pos);
	int rb(int a);
	void cet();
	int find(int n);
	int min();
	int remove(int pos);
	void rec();
};