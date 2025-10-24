#include <iostream>
#include <cstdlib>

#define MAXSIZE 100               //多项式可能达到的最大长度
#define LIST_INIT_SIZE 100       //线性表存储空间的初始分配量

//定义顺序表类型
typedef struct
{
	int* elem; //int elem[MAXSIZE]静态内存分配（数组）
	int length;
}SqList;

//多项式系数
typedef struct
{
	float p;
	int e;
}Polynomial;


//定义函数返回状态
typedef int Status;
#define OK 1
#define ERROR 0

//表初始化
Status InitList_Sq(SqList&L)
{
	L.elem =new int(MAXSIZE);//分配内存
	if (!L.elem) { exit(ERROR); }
	L.length = 0;
	return OK;
}

//销毁线性表
void DestroyList(SqList& L)
{
	if (L.elem)
	{
		delete L.elem;   //释放存储空间
	}
}

//清空线性表
void ClearList(SqList& L)
{
	L.length = 0;//将线性表长度置为0
}

//获取线性表长度
int GetLength(SqList& L)
{
	return(L.length);
}

//判断线性表是否为空
int IsEmpty(SqList& L)
{
	if (L.elem == 0)  return 1; 
	else return 0;
}

//线性表取值
int GetElem(SqList L, int i, int& e)
{
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}

//顺序表的查找，返回元素数据的位置
int LocateElem(SqList L, int e)
{
	int i;
	for (i = 0; i<L.length; i++)
	{
		if (L.elem[i] == e) return i + 1;
		return 0;
	}
}

//顺序表的插入
Status ListInsert_Sq(SqList& L, int i, int e)
{
	int j;
	if ((i<1) || (i>L.length + 1)) return ERROR;        //i值不合法
	if (L.length == MAXSIZE) return ERROR;        //当前存储空间已满
	for (j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length += 1;
	return OK;
}
//顺序表的删除
Status ListDelete_Sq(SqList& L,int i)
{
	int j;
	if ((i<1) || (i>L.length + 1)) return ERROR;
	for (j=i;j<L.length-1;j++)
	{
		L.elem[j - 1] = L.elem[j];//被删除的元素后的所有元素前移动
	}
	L.length--;
	return OK;
}

int main()
{
	SqList L;  //定义变量
	if (InitList_Sq(L) == OK)
	{
		std::cout << "初始化成功" << std::endl;
	}
	if (InitList_Sq(L) == ERROR)
	{
		std::cout << "初始化失败" << std::endl;
	}

	return 0;
}
