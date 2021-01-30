#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *head=NULL;
void insertfirst();
void insertlast();
void insertpos();
void display();
void search();
void deletefirst();
void deletelast();
void deletepos();
int main(){
  int ch=0;
  while(ch!=9){
    printf("Enter choice\n1.Insert first\n2.Insert last\n3.Insert at pos\n4.Delete first\n5.Delete last\n6.Delete at pos\n7.Search\n8.Display\n9.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      insertfirst();
      break;
      case 2:
      insertlast();
      break;
      case 3:
      insertpos();
      break;
      case 4:
      deletefirst();
      break;
      case 5:
      deletelast();
      break;
      case 6:
      deletepos();
      break;
      case 7:
      search();
      break;
      case 8:
      display();
      break;
  

    }
  }
}
void insertfirst(){
  int x;
  struct node *ne=(struct node*)malloc(sizeof(struct node));
  if(ne==NULL){
    printf("Insufficent memory\n");
    return;
  }else{
    printf("enter the value to insert");
    scanf("%d",&x);
    ne->left=NULL;
    ne->right=NULL;
    ne->data=x;
  }
  if(ne==NULL){
    return;
  }if(head==NULL){
    head=ne;
    return;
  }else{
    head->left=ne;
    ne->right=head;
    head=ne;
  }

}
void insertlast(){
  struct node *ptr;
  int x;
  struct node *ne=(struct node*)malloc(sizeof(struct node));
  if(ne==NULL){
    printf("Insufficent memory\n");
    return;
  }else{
    printf("enter the value to insert");
    scanf("%d",&x);
    ne->left=NULL;
    ne->right=NULL;
    ne->data=x;
  }if(ne==NULL){
    return;
  }
  if(head==NULL){
    head=ne;
    return;
  }else{
    ptr=head;
    while(ptr->right!=NULL){
      ptr=ptr->right;
    }ptr->right=ne;
    ne->left=ptr;

  }
}
void insertpos(){
  struct node *ptr,*ptr1;
  int x,a;
  struct node *ne=(struct node*)malloc(sizeof(struct node));
  if(ne==NULL){
    printf("Insufficent memory");
    return;
  }else{
    printf("enter the value to insert");
    scanf("%d",&x);
    ne->left=NULL;
    ne->right=NULL;
    ne->data=x;
  }
  if(ne==NULL){
    return;
  }if(head==NULL){
    head=ne;
  }ptr=head;
  printf("Enter the key value of node to be inserted");
  scanf("%d",&a);
  while(ptr->right!=NULL&&ptr->data!=a){
    ptr=ptr->right;
  }if(ptr->right==NULL){
    ptr->right=ne;
    ne->left=ptr;
  }else{
    ptr1=ptr->right;
    ne->right=ptr1;
    ne->left=ptr;
    ptr->right=ne;
    ptr1->left=ne;
  }
}
void display(){
  struct node *ptr=head;
  if(head==NULL){
    printf("List is empty\n");
    return;
  }
  while(ptr!=NULL){
    printf("%d\t",ptr->data);
    ptr=ptr->right;
  }
}
void search(){
  struct node *ptr;
  int x;
  if(head==NULL){
    printf("Linked list is empty");
    return;
  }ptr=head;
  printf("Enter the number u want to serach");
  scanf("%d",&x);
  while(ptr!=NULL){
    if(ptr->data==x){
      printf("Element is present");
      return;
    }ptr=ptr->right;
  }
}
void deletefirst(){
  struct node*ptr;
  if(head==NULL){
    printf("List is empty\n");
    return;
  }ptr=head;
  if(head->right!=NULL){
    head=head->right;
    head->left=NULL;
    free(ptr);
  }else{
     free(head); head=NULL;
  }display();

}
void deletelast(){
  struct node *ptr,*prev;
  if(head==NULL){
    printf("list is empty");
    return;
  }if(head->right==NULL){
    free(head);
    head=NULL;
    return;
  }ptr=head;
  while(ptr->right!=NULL){
    ptr=ptr->right;
  }prev=ptr->left;
  prev->right=NULL;
  free(ptr);
  display();
}
void deletepos(){
  struct node*ptr,*prev,*next;
  int x;
  if(head==NULL){
    printf("\n List is empty\n");
    return;
  }printf("Enter the number u want to delete");
  scanf("%d",&x);
  if(head->data==x){
    ptr=head;
    head=ptr->right;
    if(head!=NULL){
      head->left=NULL;
      free(ptr);
      return;
    }
  }ptr=head;
  while(ptr->data!=x&&ptr->right!=NULL){
    ptr=ptr->right;
  }if(ptr->data==x){
    next=ptr->right;
    prev=ptr->left;
    prev->right=ptr->right;
    if(next!=NULL){
      next->left=ptr->left;
      free(ptr);
    }

  }printf("Element is not found");
}
