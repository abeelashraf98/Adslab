#include<stdio.h>
#include<math.h>
#include<string.h>
void assign(char *, int *);
void display(int,int);
int main(){
  int s1,s2,s3,i,l;
  char set1[15],set2[15];
  s1=s2=s3=0;
  printf("Enter Set1\n");
  scanf("%s",set1);
  printf("Enter Set 2\n");
  scanf("%s",set2);
  l=strlen(set1);
  if(l!=strlen(set2)){
    printf("Not able to perform operation");
  }else{
    assign(set1,&s1);
    assign(set2,&s2);
    printf("\nSet 1\n");
    display(s1,l);
    printf("\nSet2\n");
    display(s2,l);
    s3=s1&s2;
    printf("\nIntersection\n");
    display(s3,l);
    s3=s1|s2;
    printf("\nUnion\n");
    display(s3,l);
    s2=~s2;
    s3=s1&s2;
    printf("\nDifference\n");
    display(s3,l);
  }
}
void assign(char *set1,int *p){
  int i,x,j;
  for(i=strlen(set1)-1,j=0;i>=0;i--,j++){
    if(set1[i]=='1'){
      x=1;
    }else{
      x=0;
    }*p=*p+x*((int)pow(2,j));
  }
}
void display(int s3,int l){
  int i;
  for(i=l-1;i>=0;i--){
    printf("%d",(s3&(int)pow(2,i))>>i);
  }

}