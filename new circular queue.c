#include<stdio.h>
#include<stdlib.h>
void insert(int[],int);
void deletion(int[]);
void search(int[]);
void display(int[]);
int front=-1;
int rear=-1;
int main(){
    int a[4],n,ch,j;
    while(1){
    printf("1.Insert\n2.Delete\n3.Search\n4.display\n5.Exit");
    printf("\nEnter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      printf("Enter your number");
      scanf("%d",&n);
      insert(a,n);
      break;
      case 2:
      deletion(a);
      break;
      case 3:
      search(a);
      break;
      case 4:
      display(a);
      break;
      case 5:
      exit(1);
      break;
    }
    }
}
void insert(int a[],int n){
    if (front==(rear+1)%4){
        printf("Queue is full\n");
        return;
    }if(front==-1)
        front=0;
        rear=(rear+1)%4;
        a[rear]=n;
        return;
    
    
}
void deletion(int a[]){
  {
  if(front==-1){
    printf("Queue is empty\n");
    return;
  }printf("deleted %d  ",a[front]);
   if(front==rear)
    front=rear=-1;
  else{
    front=(front+1)%4;
 }

}
}
void search(int a[]){
  int f,pos,j;
    if (front==-1){
    printf("Queuue is empty");
    return;
  }f=front;
  pos=1;
  printf("Enter the value to search");
  scanf("%d",&j);
  while(1){
    if(a[f]==j){
      printf("The element %d in %d th postion",j,pos);
      break;
    }if (f==rear){
      printf("The element not found");
      break;
    }
  f=(f+1)%4;
  pos=pos+1;
  }
  
}
void display(int a[]){
  int f;
  if(front==-1){
    printf("Queue is empty");
    return;
  }f=front;
  while (1){
    printf("%d",a[f]);
    if(f==rear){
      break;
    }
  f=(f+1)%4;
  }
  
}