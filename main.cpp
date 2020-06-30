#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include"Stack.h"
//12+3*6/3+4*5
using namespace std;

//比较lhs的优先级是否高于rhs,rhs表示栈顶的元素
bool isLarger(const int &lhs,const int &rhs){
	
	if((rhs=='+'||rhs=='-'||rhs=='('||rhs==')')&&(lhs=='/'||lhs=='*')){
	
		return true;
	}else{
		return false;
	}

}

//对运算符求值
int operate(int left,int right,int op){
	int result = 0;
	cout<<"left:"<<left<<"right:"<<right<<(char)op<<endl;

	switch(op){
	case '+':
		result = left+right;
		break;
	case '-':
	result = left-right;
		break;
		case '*':
	result = left*right;
		break;
	case '/':
		result = left/right;
		break;
	default :
		break;
	
	}
	cout<<"result:"<<result<<endl;

	return result;
}

int caculate(string input){
	SqStack date_stack;//操作=数堆栈
	SqStack opt_stack;//运算符堆栈
	int ldate=0,rdate=0;
	int status=0;//0-接受左操作数 1-接受操作运算符"+-*/" 2-接受右操作数

	//初始化栈和运算符
	initStack(date_stack);
	initStack(opt_stack);

	for(int i=0;i<input.length();i++){
	if(isspace(input[i]))continue;

	switch(status){
		//空格键忽略	

	case 0:
		if(isdigit(input[i])){
			ldate*=10;
			ldate+=input[i]-'0';
		
		}else{
			cout<<"得到左操作数"<<ldate<<endl;
			pushStack(date_stack,ldate);//左边操作数入栈
			i--;
			status=1;
		}
	break;
	case 1:
		//判断符号
		if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
		
			if(isEmpty(opt_stack)){//第一个符号直接推进去
			cout<<"推入符号为空"<<endl;
	
			pushStack(opt_stack,input[i]);
			cout<<"符号"<<(char)input[i]<<"入栈"<<endl;
			status = 2;

			}else{//如果第一个符号不为空，判断当前即将进入的符号的优先级和已存在符号的优先级那个更高
				if(isLarger(input[i],*getfrontStack(opt_stack))){//优先级高先推入栈
				cout<<"入栈"<<(char)input[i]<<endl;
				pushStack(opt_stack,input[i]);
				status = 2;
				rdate =0;
				}else{//如后者插入优先级低，那么计算值
					int left=0,right=0,opt;
					//计算
					cout<<"false"<<endl;
					do{
					//出栈右值
					popStack(date_stack,right);
					//出栈左值
					popStack(date_stack,left);
					//出栈运算符
					popStack(opt_stack,opt);
					
			
					cout<<"最顶符号"<<(char)opt<<"出栈"<<endl;
					int result=operate(left,right,opt);
					pushStack(date_stack,result);
					
					
					}while(!isEmpty(opt_stack)&&!isLarger(input[i],*getfrontStack(opt_stack)));
					cout<<"符号元素"<<(char)input[i]<<"入栈"<<endl;
					pushStack(opt_stack,input[i]);
					status=2;
					rdate=0;
				
				}
			
			
			}
		
		}else if(input[i]=='='){
		//计算结果
			int opt;
			int result;
			do{
					//出栈右值
					popStack(date_stack,rdate);
					//出栈左值
					popStack(date_stack,ldate);
					//出栈运算符
					popStack(opt_stack,opt);
			
					cout<<"最顶符号"<<(char)opt<<"出栈"<<endl;
					result=operate(ldate,rdate,opt);

					pushStack(date_stack,result);
	
					
					}while(!isEmpty(opt_stack));
			return result;
		
		}else{
			cerr<<"输入运算符有误"<<endl;
			
		}
		break;
	case 2:
	if(isdigit(input[i])){
			rdate*=10;
			rdate+=input[i]-'0';
		
		}else{
			cout<<"得到左操作数"<<rdate<<endl;
			pushStack(date_stack,rdate);//左边操作数入栈
			i--;
			status=1;
		}
	break;


	
		}
	}

	return -1;
}

int main(int argc, char const *argv[]){
	string str=" 12+3*6/3+4*5+100=";

	cout<<"12+3*6/3+4*5="<<caculate(str)<<endl;

	system("pause");
	return 0;
	}