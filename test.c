#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
typedef struct student{
    int income;
    int outgoing;
    char name[MAX];
    char id[MAX];
}STUDENT ;

STUDENT *Input(int n){
    int k=1;
    int ans=0;
    STUDENT *stu=NULL;
    do{

        if(k==0||ans>0) printf("the income or expenses must is number!!!\n");
        k=1;ans=0;
        stu=(STUDENT*)malloc(sizeof(STUDENT)*(n+1));
        if(stu==NULL){
            printf("no enough memory!!!\n");
            exit(0);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%s",stu[i].id);scanf("%s",stu[i].name); k=(scanf("%d %d",&stu[i].income,&stu[i].outgoing));

            char ch;
            while((ch=getchar())!=EOF&&ch!='\n'){
                ans++;
            }
        }
    }while(k==0||ans>0);
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
    printf("ID\tUserName\tIncome\tExpenses\t\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%s\t\t%d\t%d\t\n",stu[i].id,stu[i].name,stu[i].income,stu[i].outgoing);
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
void MaxOut(STUDENT*stu,int n,double averOut){
    printf("under averOut :\n");
    printf("ID\tUserName\tIncome\tExpenses\t\n");
    for (int i = 0; i < n; i++)
    {
        if((double)(stu[i].outgoing)>=averOut)
        {
            printf("%s\t%s\t\t%d\t%d\t\n",stu[i].id,stu[i].name,stu[i].income,stu[i].outgoing);
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
    printf("0. Exit\n");
}
int Find(STUDENT *stu,int n,char *name){
    int ans=1;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        ans=1;
        for (int j = 0; j < strlen(stu[i].name); j++)
        {
            if(name[j]!=stu[i].name[j]) ans=0;
        }
        if(ans){
            printf("ID\tUserName\tIncome\tExpenses\t\n");
            printf("%s\t%s\t\t%d\t%d\t\n",stu[i].id,stu[i].name,stu[i].income,stu[i].outgoing);
            count =1;
        }

    }
    return count;
}

int main (){
    static int n=1;
    int op=-1;
    double in,out;
    int ans=0;
    STUDENT *stu=NULL;
    do{
        if(ans>0){printf("\t\tplease input right number!!!\n");}
        ans=0;
        char ch;
        Menu();
        FLAG:op=-1;
        printf("\t\tPlease enter your choice:");
        scanf("%d",&op);
        while((ch=getchar())!=EOF&&ch!='\n'){
             ans++;
        }
    }while(ans>0);
        ans=0;
        int cont=0;
        char cha;
        switch (op)
        {
            case 1:

                do{
                    if(cont>0||(n>10||n<=0)){printf("\t\tplease input right number!!!(1-10)\n");}
                    cont=0;
                    printf("please input how many people>>");
                    scanf("%d",&n);
                    while((cha=getchar())!=EOF&&cha!='\n')
                        {
                        cont++;
                        }
                   }while(cont>0||(n>10||n<=0));
                    stu=Input(n);
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
                if((Find(stu,n,name))==0){
                    printf("no find the people!!!\n");
                }
                goto FLAG;
            case 4:
                if(stu==NULL){printf("no people!!!\n");goto FLAG;}
                in =AverIn(stu,n);
                out=AverOut(stu,n);
                printf("per capita income :\t%0.2f\nper capita expenses:\t%0.2f\t\n",in,out);
                goto FLAG;
            case 5:
                if(stu==NULL){printf("no people!!!\n");goto FLAG;}
                in =AverIn(stu,n);
                out=AverOut(stu,n);
                MaxOut(stu,n,out);
                goto FLAG;
            case 6:
                if(stu==NULL){printf("no people!!!\n");goto FLAG;}
                Display(stu,n);
                goto FLAG;
            case 0:
                printf("exit system\n");
                free(stu);
                exit(0);
                break;
        }
    return 0;
}
