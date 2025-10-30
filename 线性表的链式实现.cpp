#include <iostream>

using namespace std;

#define OK 1;
#define ERROR 0;

struct Lnode
{
	int data;
	Lnode *next;
};

using LinkList = Lnode*;//等价typedef Lnode* LinkList,LinkList 是一个类型别名，代表 “指向 Lnode 类型的指针

//创建一个头节点
int InitList(LinkList& L)
{
	L = new Lnode;
	L->next = NULL;
	return OK;
}

//判断链表是否为空
int ListEmpty(LinkList L)
{
	if (L->next)
	{
		return 0;
	}
	else
		return 1;
}

//销毁链表
int DestroyList(LinkList& L)
{
	Lnode* p;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}


//清空链表
int ClearList(LinkList& L)
{
	Lnode* p, * q;
	p = L->next;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
}

//求单链表表长
int ListLength_L(LinkList L)
{
	LinkList p;
	p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//单链表取第i个元素,通过变量e返回
int GetElem_L(LinkList L, int i, int& e)
{
	Lnode* p;
	int j = 1;
	p = L->next;
	while (p && j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}

//查找链表中的元素,返回元素e的地址，加一个j可以返回位置序号
Lnode *LocateElem_L(LinkList L, int e)
{
	Lnode* p;
	p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	return p;
}

//在L的第i个元素前插入e
int ListInsert_L(LinkList& L, int i, int e)
{
	Lnode* p,*s;
	int j = 0;
	p = L;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;
	s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//在L中删除第i个结点,保存删除节点的数据域到e
int ListDelete_L(LinkList& L, int i, int &e)
{
	Lnode* p,*q;
	int j = 0;
	p = L;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;
}

//头插法
void CreateList_H(LinkList& L, int n)
{
	L = new Lnode;
	L->next = NULL;
	for (int i = n; i > 0; --i)
	{
		Lnode* p = new Lnode;
		cout << "请输入:";
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

//尾插法
void CreateList_L(LinkList& L, int n)
{
	L = new Lnode;
	L->next = NULL;
	Lnode* r = L;
	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

int main()
{
	LinkList L;
	CreateList_H(L, 3);
	return 0;
}
