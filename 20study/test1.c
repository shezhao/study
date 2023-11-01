// #include<stdio.h>
// #include<stdlib.h>
// struct link{
//         int data;
//         char c;
//         struct link*next ;
//     };
//     typedef struct link LINK;
// void display(LINK*head){
//     LINK*p=head;
//     if(head==NULL){
//         printf("the link is empty!!!\n");
//     }
//     while(p!=NULL){
//         printf("number=%d\n",p->data);
//         printf("char=%d\n",p->c);
//         p=p->next;
//     }
// }
// void del(LINK*head){
//     LINK*p=head,*pr=NULL;
//     while(p!=NULL){
//         pr=p;
//         p=p->next;
//         free(pr);
//     }
// }

// int main (){
//     int is;
//     LINK *p=NULL,*head=NULL,*tail=NULL;
//     printf("do you want add a node(1/0)");
//     scanf("%d",&is);
//     LINK*pr=head;
//     p=(LINK*)malloc(sizeof(LINK));
//     if(p==NULL){
//         printf("insufficient storage space!!!");
//         exit(0);
//     }
//     if(head==NULL){
//         head=p;
//     }
//     else {
//         while(pr->next!=NULL){
//             pr=pr->next;
//         }
//         pr->next=p;

//         printf("please input a number:");
//         scanf("%d",&p->data);
//         printf("please input a char:");
//         scanf(" %c",&p->c);
//     }
// }
//     display(head);
//     del(head);
//     return 0;
// }