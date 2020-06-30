#pragma once

#include<iostream>
using namespace std;


typedef int  Elemdate;

#define MAX_SIZE 128
#define ROW 6
#define COL 6




typedef struct _SqStack{
	Elemdate *top;
	Elemdate *base;	

}SqStack;
bool initStack(SqStack &stack);
bool isFully(SqStack &stack);
bool pushStack(SqStack &stack,Elemdate date);
bool isEmpty(SqStack &stack);
bool popStack(SqStack &stack,Elemdate &date);
Elemdate* getfrontStack(SqStack &stack);
int countStack(SqStack &stack);
void destoyedStack(SqStack &stack);
