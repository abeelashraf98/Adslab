#include<stdio.h>
void merge(int[],int,int[],int,int[]);
void main(){
    int a[15],b[15],c[15],m,n,i;
    printf("Enter how many number u wanr to enter in 1st array");
    scanf("%d",&m);
    printf("enter the elements");
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }printf("\nEnter how many values u want to enter in 2nd array\n");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&b[i]);
    }merge(a,m,b,n,c);
    
}
void merge(int a[],int m,int b[],int n,int c[]){
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
    printf("\nMerged value \n");
    for(i=0;i<m+n;i++){
        printf("%d,",c[i]);
    }
}