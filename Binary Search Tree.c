#include<stdio.h>
#include<stdlib.h>
struct node{
  struct node*left;
  int data;
  struct node*right;
};
struct node *root=NULL;
void insert();
void delet(int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void search();
int main(){
  int ch,x;
   while(ch!=7){
    printf("Enter choice\n1.Insert\n2.Delete\n3.Inorder\n4.PreOrder\n5.Post Order\n6.Search\n7.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      insert();
      break;
      case 2:
      printf("Enter the number want to delete");
      scanf("%d",&x);
      delet(x);
      break;
      case 3:
      inorder(root);
      break;
      case 4:
      preorder(root);
      break;
      case 5:
      postorder(root);
      break;
      case 6:
      search();
      break;
  

    }
  }

}
void insert(){
  struct node *ptr,*ne,*ptr1;
  int x;
  ne=(struct node*)malloc(sizeof(struct node));
  if(ne==NULL){
    printf("\nInsufficient Memory");
    return;
  }printf("Enter the number u want to insert");
  scanf("%d",&x);
  ne->right=ne->left=NULL;
  ne->data=x;
  if(root==NULL){
    root=ne;
    return;
  }ptr=root;
  while(ptr!=NULL){
    if(x==ptr->data){
      printf("Item is present\n");
      break;
    }if(x>ptr->data){
      ptr1=ptr;
      ptr=ptr->right;
    }else{
      ptr1=ptr;
      ptr=ptr->left;
    }
  }if(ptr==NULL){
    if(x>ptr1->data){
      ptr1->right=ne;
    }else{
      ptr1->left=ne;
    }
  }
}
void search(){
  struct node *ptr=root;
  int x;
  printf("Enter the number u want to serach");
  scanf("%d",&x);
  while(ptr!=NULL){
    if(ptr->data==x){
      printf("The Element is present");
      break;
    }if(x>ptr->data){
      ptr=ptr->right;
    }else{
      ptr=ptr->left;
    }
  }if(ptr==NULL){
    printf("Data not present");
  }
}
void inorder(struct node *p){
  if(p!=NULL){
    inorder(p->left);
    printf("%d\t",p->data);
    inorder(p->right);
  }
}
void preorder(struct node *p){
  if(p!=NULL){
    printf("%d\t",p->data);
    preorder(p->left);
    preorder(p->right);

  }
}
void postorder(struct node *p){
  if(p!=NULL){
    postorder(p->left);
    postorder(p->right);
    printf("%d\t",p->data);
  }
}
void delet(int x){
  struct node *parent,*ptr,*p;
  int dat;
  if(root==NULL){
    printf("\n Tree is empty\n");
    return;
  }parent=NULL;
  ptr=root;
  while(ptr!=NULL){
    if(ptr->data==x){
      break;
    }parent=ptr;
    if(x>ptr->data){
      ptr=ptr->right;
    }else{
      ptr=ptr->left;
    }
  }if(ptr==NULL){
    printf("Item not presnt");
    return;

  }if(ptr->right==NULL&&ptr->left==NULL){
    if(parent==NULL){
      root=NULL;
    }else if(parent->right==ptr){
      parent->right=NULL;
    }else{
      parent->left=NULL;
      printf("Element Deleted");
    }free(ptr);
    return;
  }if(ptr->right!=NULL&&ptr->left!=NULL){
    p=ptr->right;
    while(ptr->left!=NULL){
      p=ptr->left;
    }dat=p->data;
    delet(p->data);
    ptr->data=dat;
    return;
  }if(parent==NULL){
    if(ptr->right==NULL){
      root=ptr->left;
    }else{
      root=ptr->right;
    }
  }else{
    if(parent->right==ptr){
      if(ptr->right==NULL){
        parent->right=ptr->left;

      }else{
        parent->right=ptr->right;
      }
    }else{
      if(ptr->left==NULL){
        parent->left=ptr->right;
      }else{
        parent->left=ptr->left;
      }
    }
  }
  printf("Element Deleted");
  free(ptr);
}