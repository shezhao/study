#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LINK{
    char elem[100];
    int num;
    struct LINK*next;
}LINK;
LINK*add(LINK*head){
    LINK *p=NULL;
    p=(LINK*)malloc(sizeof(LINK));
    if(p==NULL){
        printf("the memory is not enough\n");
        exit(0);
    }
    printf("please input a string\n");
    scanf(" %s",p->elem);
    printf("please input a number\n");
    scanf("%d",&p->num);
    if(head==NULL){
        head=p;
        p->next=NULL;
    }
    else{
        LINK *pr=head;
        while (pr->next!=NULL)
        {
            pr=pr->next;  
        }
        pr->next=p;
        p->next=NULL;
    }
    return head;
}
void display(LINK*head){
    LINK*p=head;
    int i=0;
    if(p==NULL){
        printf("the link is empty\n");
    }
    while(p!=NULL){
        i++;
        printf("%d>>string=%s number=%d\n",i,p->elem,p->num);
        p=p->next;
    }

}
void fr(LINK*head){
    LINK*p=head;
    while(p!=NULL){
        free(p);
        p=p->next;
    }
}
int check(char *str,char *st){
    if(strlen(str)!=strlen(st)){return 0;}
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i]!=st[i]){return 0;}
    }
    return 1;
    
}
LINK*Delete(LINK*head,char*str,int number){
    LINK*p=head;
    LINK*pr=head;
    if(head==NULL){
        printf("the link is empty\n");
    }
    else{
        if(p->num==number){
                    head=head->next;
        }
        else{
            while(p->next!=NULL){ 
                p=pr->next;
                if(p->num==number){
                    pr->next=p->next;
                    p=p->next;
                }
                else{
                    pr=pr->next;
                }
            }
        }
        
    }
    return head;

    
}
int main (){
    LINK*head=NULL;
    for (int i = 0; i <5; i++)
    {
        head=add(head);
        
    }
    display(head);
    int a=0;
    char str[20];
    printf("please input a string that you want to delete\n");
    scanf("%s",str);
    printf("please input a number that you want to delete\n");
    scanf("%d",&a);
    head=Delete(head,str,a);
    display(head);
    return 0;
}