#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include"Stack.h"
//12+3*6/3+4*5
using namespace std;

//�Ƚ�lhs�����ȼ��Ƿ����rhs,rhs��ʾջ����Ԫ��
bool isLarger(const int &lhs,const int &rhs){
	
	if((rhs=='+'||rhs=='-'||rhs=='('||rhs==')')&&(lhs=='/'||lhs=='*')){
	
		return true;
	}else{
		return false;
	}

}

//���������ֵ
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
	SqStack date_stack;//����=����ջ
	SqStack opt_stack;//�������ջ
	int ldate=0,rdate=0;
	int status=0;//0-����������� 1-���ܲ��������"+-*/" 2-�����Ҳ�����

	//��ʼ��ջ�������
	initStack(date_stack);
	initStack(opt_stack);

	for(int i=0;i<input.length();i++){
	if(isspace(input[i]))continue;

	switch(status){
		//�ո������	

	case 0:
		if(isdigit(input[i])){
			ldate*=10;
			ldate+=input[i]-'0';
		
		}else{
			cout<<"�õ��������"<<ldate<<endl;
			pushStack(date_stack,ldate);//��߲�������ջ
			i--;
			status=1;
		}
	break;
	case 1:
		//�жϷ���
		if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
		
			if(isEmpty(opt_stack)){//��һ������ֱ���ƽ�ȥ
			cout<<"�������Ϊ��"<<endl;
	
			pushStack(opt_stack,input[i]);
			cout<<"����"<<(char)input[i]<<"��ջ"<<endl;
			status = 2;

			}else{//�����һ�����Ų�Ϊ�գ��жϵ�ǰ��������ķ��ŵ����ȼ����Ѵ��ڷ��ŵ����ȼ��Ǹ�����
				if(isLarger(input[i],*getfrontStack(opt_stack))){//���ȼ���������ջ
				cout<<"��ջ"<<(char)input[i]<<endl;
				pushStack(opt_stack,input[i]);
				status = 2;
				rdate =0;
				}else{//����߲������ȼ��ͣ���ô����ֵ
					int left=0,right=0,opt;
					//����
					cout<<"false"<<endl;
					do{
					//��ջ��ֵ
					popStack(date_stack,right);
					//��ջ��ֵ
					popStack(date_stack,left);
					//��ջ�����
					popStack(opt_stack,opt);
					
			
					cout<<"�����"<<(char)opt<<"��ջ"<<endl;
					int result=operate(left,right,opt);
					pushStack(date_stack,result);
					
					
					}while(!isEmpty(opt_stack)&&!isLarger(input[i],*getfrontStack(opt_stack)));
					cout<<"����Ԫ��"<<(char)input[i]<<"��ջ"<<endl;
					pushStack(opt_stack,input[i]);
					status=2;
					rdate=0;
				
				}
			
			
			}
		
		}else if(input[i]=='='){
		//������
			int opt;
			int result;
			do{
					//��ջ��ֵ
					popStack(date_stack,rdate);
					//��ջ��ֵ
					popStack(date_stack,ldate);
					//��ջ�����
					popStack(opt_stack,opt);
			
					cout<<"�����"<<(char)opt<<"��ջ"<<endl;
					result=operate(ldate,rdate,opt);

					pushStack(date_stack,result);
	
					
					}while(!isEmpty(opt_stack));
			return result;
		
		}else{
			cerr<<"�������������"<<endl;
			
		}
		break;
	case 2:
	if(isdigit(input[i])){
			rdate*=10;
			rdate+=input[i]-'0';
		
		}else{
			cout<<"�õ��������"<<rdate<<endl;
			pushStack(date_stack,rdate);//��߲�������ջ
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