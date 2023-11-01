#include<stdio.h>
#include<stdlib.h>
struct student 
{
    int id;
    struct student  *next;
};
struct student  *append(struct student  *head){
    struct student  *p=NULL,*pr=head;
    int data;
    p=(struct student *)malloc(sizeof(struct student));
    if(p==NULL){
        printf("no enough !!\n");
        exit(0);
    }
    if(head==NULL){
        head=p;
    }
    else {
        while(pr->next!=NULL){
            pr=pr->next;
        }
        pr->next=p;
    }
    printf("input a number:");
    scanf("%d",&data);
    p->id=data;
    p->next=NULL;
    return head;
}
void display(struct student *head){
    struct student  *p=head;
    if(head==NULL){
        printf("\nthis link is empty!\n");
    }
    else{
        printf("node flowing>>\n");
        int j=0;
        while (p!=NULL)
        {
            j++;
            printf("node%d=%d\n",j,p->id);
            p=p->next;

        }
    }
}
void Delete(struct student  *head){
    struct student *p=head,*pr=NULL;
    while (p!=NULL)
    {
        pr=p;
        p=p->next;
        free(pr);       
    }
    
}
struct student *DeleteNode(struct student*head,int nodeData){
    struct student *p=head,*pr=head;
    if(head==NULL){
        printf("all node is empty!");
        return head;
    }
    while(nodeData!=p->id&&p->next!=NULL){
        pr=p;
        p=p->next;
    }
    if(nodeData==p->id){
        if(p==head){
            head=head->next;

        }
        else{
            pr->next=p->next;//跳过删除节点，空间内存还在
        }
        free(p);//要释放内存
    }
    else {
        printf("all node is not find!\n");
    }
    return head;

}
struct student*insert (struct student*head,int nodeData){
    struct student*pr=head,*p=head,*temp =NULL;
    p=(struct student* )malloc(sizeof(struct student));
    if(p==NULL){
        printf("no enough!!");
        exit(0);
    }
    p->next=NULL;
    p->id=nodeData;
    if (head==NULL)

    {
        head==p;
    }
    else {
        while(pr->id<nodeData&&pr->next!=NULL){
            temp=pr;
            pr=pr->next;
        }
        if(pr->id>=nodeData){
            if(pr==head){
                p->next=head;
                head=p;
            }
            else {
                pr=temp;
                p->next=pr->next;
                pr->next=p;
            }
        }
        else {
            pr->next=p;
        }
    }
    return head;
}
void menu(){
    printf("----------------------------------\n");
    printf("--------1.在链表后添加节点----------\n");
    printf("--------2.在链表中删除节点----------\n");
    printf("--------3.在链表中插入节点----------\n");
    printf("--------0.退出---------------------\n");
}   



int main (){
    struct student  *head=NULL;
    int c;
    menu();
    int op=0;
    do{
    printf("请输入：");
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        printf("please append a new node(1/0)?");
        scanf("%d",&c);
        while(c==1){
        head=append(head);
        display(head);
        printf("please append a new node(1/0)?");
        scanf("%d",&c);
    }
        break;
    case 2:
        display(head);
        printf("please input what you want delete:");
        int node;
        scanf("%d",&node);
        head=DeleteNode(head,node);
        display(head);
        break;
    case 3:
        display(head);
        printf("please input what you want insert:");
        int node1;
        scanf("%d",&node1);
        head=insert(head,node1);
        display(head);
        break;
    case 0:
        goto FLAG;
        break;
    default:
        break;
    }
    menu();
}while(op!=0);
    FLAG:Delete(head); 
    return 0;
}
