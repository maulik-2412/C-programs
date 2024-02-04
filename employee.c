#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee{
    int id,salary;
    char name[15],designation[10];
};

void add(struct employee *emp,int *n);
void Delete(struct employee *emp,int *n);
void modify(struct employee *emp,int *n);
void display(struct employee *emp,int n);

int main() {
    printf("Enter no. of employees:");
    int n;
    scanf("%d",&n);
    struct employee *emp=(struct employee*)(malloc(n*sizeof(struct employee)));
    
    for(int i=0;i<n;i++){
        printf("Enter id");
        scanf("%d",&emp[i].id);
        printf("Enter name");
        scanf("%s",&emp[i].name);
        printf("Enter salary");
        scanf("%d",&emp[i].salary);
        printf("Enter designation");
        scanf("%s",&emp[i].designation);
    }
    
    int j=0;
    while(j!=4){
        printf("Menu\n----\n1.ADD\n2.DELETE\n3.modify\n4.exit");
        printf("Enter choice");
        scanf("%d",&j);
        switch(j){
            case 1: add(emp,&n);
                    display(emp,n);
                    break;
            case 2: Delete(emp,&n);
                    display(emp,n);
                    break;
            case 3: modify(emp,&n);
                    display(emp,n);
                    break;
            case 4: break;
            
            default: printf("invalid choice:");
            
        }
    }
    

    return 0;
}

void add(struct employee *emp,int *n){
    *n=*n+1;
    struct employee *emp1=realloc(emp,(*n)*sizeof(struct employee));
    emp=emp1;
    printf("Enter id");
    scanf("%d",&emp[*n-1].id);
    printf("Enter name");
    scanf("%s",emp[*n-1].name);
    printf("Enter salary");
    scanf("%d",&emp[*n-1].salary);
    printf("Enter designation");
    scanf("%s",emp[*n-1].designation);
    
}

void Delete(struct employee *emp,int *n){
    printf("Enter id");
    int k,i=0;
    int flag=0;
    
    scanf("%d",&k);
    for(i=0;i<*n;i++){
        if(emp[i].id==k){
            flag=1;
            break;
        }
    }
    if(flag==1){
        for(;i<*n-1;i++){
            emp[i]=emp[i+1];
        }
        (*n)--;
        emp = realloc(emp, (*n) * sizeof(struct employee));
    }
    
}

void modify(struct employee *emp,int *n){
    int m,i=0;
    printf("enter index to modify:");
    scanf("%d",&m);
    
    for(i=0;i<*n;i++){
        if(emp[i].id==m){
            break;
        }
    }
    printf("%d\t%s\t%d\t%s\t\n",emp[i].id,emp[i].name,emp[i].salary,emp[i].designation);
    printf("Enter id");
    scanf("%d",&emp[i].id);
    printf("Enter name");
    scanf("%s",emp[i].name);
    printf("Enter salary");
    scanf("%d",&emp[i].salary);
    printf("Enter designation");
    scanf("%s",emp[i].designation);
}

void display(struct employee *emp,int n){
   printf("The structure contains\n");
    for(int i=0;i<n;i++){
        
        printf("%d\t%s\t%d\t%s\t\n",emp[i].id,emp[i].name,emp[i].salary,emp[i].designation);
    }
}