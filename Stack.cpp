#pragma once
#include"Stack.h"




//1、栈的初始化
bool initStack(SqStack &stack){
	
	stack.base=new Elemdate[MAX_SIZE];

	if(!stack.base)return false;

	stack.top=stack.base;
	return true;

}

//2、判断元素是由已满
bool isFully(SqStack &stack){
	if(!stack.base)return false;

	if(stack.top-stack.base==MAX_SIZE)return true;

	return false;

}


//3、栈插入元素
bool pushStack(SqStack &stack,Elemdate date){

	if(!stack.base||isFully(stack))return false;
	//if(isFully(stack))return false;

	*(stack.top++)=date;
	return true;

}

//4、判断栈是否为空
bool isEmpty(SqStack &stack){
	//if(!stack.base)return false;
	if(stack.base==stack.top)return true;
	return false;
}

//5、出列元素
bool popStack(SqStack &stack,Elemdate &date){
	
	//if(!stack.base||isEmpty(stack))return false;
	if(isEmpty(stack))return false;
	date=*(--stack.top);
	return true;

}

//6、获取栈顶元素
Elemdate* getfrontStack(SqStack &stack){
	if(!stack.base||isEmpty(stack))return NULL;
	//if(isEmpty(stack))return NULL;

	return (stack.top-1);

}

//7、获取元素的个数
int countStack(SqStack &stack){
	
	return stack.top-stack.base;

}

//8、销毁栈
void destoyedStack(SqStack &stack){
	
	if(!stack.base)return ;

	free(stack.base);

	stack.base=NULL;
	stack.top=NULL;


}








