#include<iostream>
using namespace std;

#define MaxSize 50
typedef int ElemType;
typedef struct//声明顺序栈的类型
{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack*& s)//初始化栈
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestroyStack(SqStack*& s)//销毁栈
{
	free(s);
}
bool StackEmpty(SqStack* s)//判断栈是否为空
{
	return(s->top == -1);
}

bool Push(SqStack*& s, ElemType e)//进栈
{
	if (s->top == MaxSize - 1) return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack*& s, ElemType& e)//出栈
{
	if (s->top == -1) return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack* s, ElemType& e)//取栈顶元素
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}


int main()
{
	int a[8] = { 1,5,3,6,4,7,0,9 };
	int e;
	SqStack* s;
	InitStack(s);

	for (int i = 0; i < 8; i++)
		Push(s, a[i]);//进栈
	if (StackEmpty(s))//判断栈是否为空
		cout << "栈顶为空" << endl;
	else cout << "栈顶不为空" << endl;


	GetTop(s, e);
		cout << e << endl;
	if (StackEmpty(s))//判断栈是否为空
		cout << "栈顶为空" << endl;
	else cout << "栈顶不为空" << endl;


	while(Pop(s,e))
		cout << e << endl;
	if (StackEmpty(s))//判断栈是否为空
		cout << "栈顶为空" << endl;
	else cout << "栈顶不为空" << endl;

	DestroyStack(s);


}
