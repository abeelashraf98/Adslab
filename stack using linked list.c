#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};
struct node *top=NULL;
void push();
void pop();
void search();
void display();
int main(){
  int ch;
  while(1){
    printf("1.Push\n2.pop\n3.Search\n4.display\n5.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      push();
      break;
      case 2:
      pop();
      break;
      case 3:
      search();
      break;
      case 4:
      display();
      break;
      case 5:
      exit(1);



    }
  }

}
void push(){
  int a;
  struct node *ne=(struct node*)malloc(sizeof(struct node));
  if(ne==NULL){
    printf("Out of memory\n");
    return;
  }printf("Enter the number u want to insert");
  scanf("%d",&a);
  ne->data=a;
  ne->link=top;
  top=ne;
}
void pop()
{
  struct node *ptr;
  if(top==NULL){
    printf("Stack empty\n");
    return;
  }ptr=top;
  top=top->link;
  ptr=NULL;
}
void search(){
  struct node *ptr;
  int x;
  if(top==NULL){
    printf("Stack is empty\n");
    return;
  }ptr=top;
  printf("Enter the number u want to search");
  scanf("%d",&x);
  while (ptr!=NULL){
    if(ptr->data==x){
      printf("\nElement is found\n");
      return;
    }ptr=ptr->link;
  }if(ptr==NULL){
    printf("\nElement not found");
  }
}
void display(){
  struct node *ptr;
  if(top==NULL){
    printf("Stack is empty\n");
    return;
  }ptr=top;
  while (ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->link;
  }
}
