#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
 
struct node
{
	char data;
	struct node* next;
};
 

bool is_empty(struct node* st)
{
	if(st==NULL){
		return true;
	}
	return false;
}
 

struct node* create_node(char x){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
 

void push(struct node** st,char x){
	struct node* temp=create_node(x); 
	temp->next=*st;
	*st=temp;
}
 

void pop(struct node** st){
	struct node* temp=*st;
	*st=temp->next;
}

char top_ele(struct node* st){
	return st->data;
}
 

int precedence(char ch){
	if(ch=='^')
		return 3;
	else if(ch=='/' || ch=='*')
		return 2;
	else if(ch=='+'|| ch=='-')
		return 1;
	else 
		return 0;
}
 

void infix_to_postfix(char* str,char* new_str,int len){
	int j=0;
	struct node* st=NULL;
 
	for(int i=0;i<len;i++){
		if((str[i]>='0' && str[i]<='9')||(str[i]>='a' && str[i]<='z')){
			new_str[j++]=str[i];
 
		}
		else if(str[i]=='('){
			push(&st,str[i]);
		}
		else if(str[i]==')'){
			
			while(!is_empty(st) && top_ele(st)!='('){
				new_str[j++]=top_ele(st);
				pop(&st);
			}
			pop(&st);
		}
		else{
			
			while(!is_empty(st) && precedence(top_ele(st))>=precedence(str[i])){
				new_str[j++]=top_ele(st);	
				pop(&st);
			}
			push(&st,str[i]);
		}
	}
	
	while(!is_empty(st)){
		new_str[j++]=top_ele(st);
		pop(&st);
	}
	new_str[j]='\n';
}
 
int main(){
	int len;
	printf("Enter the length : ");
	scanf("%d",&len);
	printf("Enter the infix one : ");
	char str[len],new_str[len];
	scanf("%s",str);
	infix_to_postfix(str,new_str,len);
	printf("Postfix : ");
	printf("%s",new_str);
	return 0;
}
