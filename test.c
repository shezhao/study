#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 10
typedef struct student{
    int income;
    int outgoing;
    char name[MAX];
    char id[MAX];
}STUDENT ;
STUDENT *Input(int n){
    STUDENT *stu;
    stu=(STUDENT*)malloc(sizeof(STUDENT)*(n+1));
    if(stu==NULL){
        printf("no enough memory!!!\n");
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        printf("please input the %d people data:\n",i+1);
        printf("name>>");
        scanf("%s",stu[i].name);
        printf("id>>");
        scanf("%s",stu[i].id);
        printf("income>>");
        scanf("%d",&stu[i].income);
        getchar();
        printf("outgoing>>");
        scanf("%d",&stu[i].outgoing);
        getchar();
    }
    return stu;
}
STUDENT* Change(STUDENT *stu,int n){
    STUDENT temp;
    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n-1; i++)
        {
            if(strcmp(stu[i].name,stu[i+1].name)<0)
            {
                temp=stu[i];
                stu[i]=stu[i+1];
                stu[i+1]=temp; 
            }
        }
    }
    return stu;
}
void Display(STUDENT*stu,int n){
    printf("name\tid\tincome\toutgoing\t\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%s\t%d\t%d\t\n",stu[i].name,stu[i].id,stu[i].income,stu[i].outgoing);
    }
}
double AverIn(STUDENT*stu,int n){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=stu[i].income;
    }
    return(double)(sum*1.0/n);
    
}
double AverOut(STUDENT*stu,int n){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=stu[i].outgoing;
    }
    return(double)(sum*1.0/n);
}
void MaxIncome(STUDENT*stu,int n,double averIncome){
    printf("under averIn :\n");
    printf("name\tid\tincome\toutgoing\t\n");
    for (int i = 0; i < n; i++)
    {
        if((double)(stu[i].income)>=averIncome)
        {
            printf("%s\t%s\t%d\t%d\t\n",stu[i].name,stu[i].id,stu[i].income,stu[i].outgoing);
        }
    }
    
}
void MaxOut(STUDENT*stu,int n,double averOut){
    printf("under averOut :\n");
    printf("name\tid\tincome\toutgoing\t\n");
    for (int i = 0; i < n; i++)
    {
        if((double)(stu[i].outgoing)>=averOut)
        {
            printf("%s\t%s\t%d\t%d\t\n",stu[i].name,stu[i].id,stu[i].income,stu[i].outgoing);
        }
    }
    
}
void Menu(){
    printf("\n1. Input record\n");
    printf("2. Sort and list records in reverse order by user name\n");
    printf("3. Search records by user name\n");
    printf("4. Calculate and list per capita income and expenses\n");
    printf("5. List records which have more expenses than per capita expenses\n");
    printf("6. List all records\n");
    printf("0. Exit\n\t\tPlease enter your choice:");
}
void Find(STUDENT *stu,int n,char *name){
    int ans=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(stu[i].name); j++)
        {
            if(name[j]!=stu[i].name[j]) ans=0;
        }
        if(ans){
            printf("name\tid\tincome\toutgoing\t\n");
            printf("%s\t%s\t%d\t%d\t\n",stu[i].name,stu[i].id,stu[i].income,stu[i].outgoing);
        }
    }
}

int main (){
    static int n=0;
    int op;
    double in,out;
    int ans=0;
    STUDENT *stu=NULL;
    FLAG:do{
        if(ans>0){printf("\t\tplease input right number!!!\n");}
        ans++;
        Menu();
        scanf("%d",&op);
        getchar();
    }while(op!=0&&op!=1&&op!=2&&op!=3&&op!=4&&op!=5&&op!=6);
        ans=0;
        switch (op)
        {
            case 1:
                printf("please input how many people>>");
                scanf("%d",&n);
                    getchar();
                    stu=Input(n);
                    Display(stu,n);
                    goto FLAG;
            case 2:
                if(stu==NULL){printf("no people!!!\n");goto FLAG;}
                stu=Change(stu,n);
                Display(stu,n);
                goto FLAG;
            case 3:
                if(stu==NULL){printf("no people!!!\n");goto FLAG;}
                printf("please input people's name>>");
                char name[MAX];
                scanf("%s",name);
                Find(stu,n,name);
                goto FLAG;
            case 4:
                if(stu==NULL){printf("no people!!!\n");goto FLAG;}
                in =AverIn(stu,n);
                out=AverOut(stu,n);
                printf("AverIncome\tAverOut\t\n");
                printf("%0.2f\t\t%0.2f\t\n",in,out);
                goto FLAG;
            case 5:
                if(stu==NULL){printf("no people!!!\n");goto FLAG;}
                in =AverIn(stu,n);
                out=AverOut(stu,n);
                printf("AverIncome\tAverOut\t\n");
                printf("%0.2f\t\t%0.2f\t\n",in,out);
                MaxIncome(stu,n,in);
                MaxOut(stu,n,out);
                goto FLAG;
            case 6:
                if(stu==NULL){printf("no people!!!\n");goto FLAG;}
                Display(stu,n);
                goto FLAG;
            case 0:
                printf("exit system\n");
                exit(0);
                break;
        }
    return 0;
}