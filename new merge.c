#include<stdio.h>
void array(int*,int);
int merge(int*,int,int*,int,int *);
void result(int*,int);
int main(){
    int a[10],b[10],c[10],m,n,k;
    printf("Enter how many elements u want to enter in 1st array: ");
    scanf("%d",&m);
    array(a,m);
    printf("Enterhow many elements u want to enter in 2nd array ");
    scanf("%d",&n);
    array(b,n);
    k=merge(a,m,b,n,c);
    result(c,k);
    
    
}
void array(int*p,int a){
    int i;
    for(i=0;i<a;i++){
      scanf("%d",&p[i]);
    } 
}
int merge(int a[],int m,int b[],int n,int c[]){
    int i=0,k=0,j=0;
    while(i<m&&j<n){
        if (a[i]<b[j]){
            c[k]=a[i];
            i++;
        }else if (b[j]<a[i]){
            c[k]=b[j];
            j++;
        }else{
            c[k]=a[i];
            j++;
            i++;
        }
    k++;
    }while(i<m){
        c[k]=a[i];
        i++;
        k++;
    }while(j<n){
        c[k]=b[j];
        j++;
        k++;
    }
  return k;
}
 

void result(int*c,int k ){
  int i;
  printf("\nMerged value \n");
    for(i=0;i<k;i++){
        printf("%d,",c[i]);
    }

}