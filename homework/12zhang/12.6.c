#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define INT 1
#define FLT 2
#define N 20

typedef struct node{
    int type;
    union{
        int ival;
        double dval;
    }dat;
}NodeType;
typedef struct stack{
    NodeType data[N];
    int top;
}STACK;
void Push(STACK * stack,NodeType data);
NodeType Pop(STACK *stack);
NodeType OpFloat(double d1,double d2,int op);
NodeType OpInt(int d1,int d2,int op);
NodeType OpData(NodeType *d1,NodeType *d2,int op);
int main (){
    char word[N];
    STACK stack;
    NodeType d1,d2,d3;
    stack.top=0;
    while(scanf("%s",word)==1&&word[0] !='#'){
        if(isdigit(word[0])){
            if(strchr(word,'.')==NULL){
                d1.type=INT;
                d1.dat.ival =atoi(word);
            }
            else {
                d1.type=FLT;
                d1.dat.dval=atof(word);
            }
            Push(&stack,d1);
            continue;
        }
        d2=Pop(&stack);
        d1=Pop(&stack);
        d3=OpData(&d1,&d2,word[0]);
        Push (&stack,d3);
    }
    d1=Pop(&stack);
    if(d1.type==INT){
        printf("%d\n",d1.dat.ival);
    }
    else{
        printf("%.2f\n",d1.dat.dval);
    }
    return 0;
}
//入堆
void Push(STACK*stack,NodeType data){
    memcpy(&stack->data[stack->top],&data,sizeof(NodeType));
    stack->top=stack->top+1;
}
//出堆
NodeType Pop(STACK*stack){
    stack->top=stack->top-1;
    return stack->data[stack->top];
}
//计算
NodeType OpInt(int d1,int d2,int op)
{
    NodeType res;
    switch(op)
    {
        case'+':
        res.dat.ival=d1+d2;
        break;
        case'-':
        res.dat.ival=d1-d2;
        break;
        case'*':
        res.dat.ival=d1*d2;
        break;
        case'/':
        res.dat.ival=d1/d2;
        break;
    }
    res.type=INT;
    return res;
}
NodeType OpFloat(double d1,double d2,int op)
{
    NodeType res;
    switch(op)
    {
        case'+':
        res.dat.dval=d1+d2;
        break;
        case'-':
        res.dat.dval=d1-d2;
        break;
        case'*':
        res.dat.dval=d1*d2;
        break;
        case'/':
        res.dat.dval=d1/d2;
        break;
    }
    res.type=FLT;
    return res;
}
NodeType OpData(NodeType*d1,NodeType*d2,int op)
{
    double dv1,dv2;
    NodeType res;
    if(d1->type==d2->type){
        if(d1->type==INT){
            res =OpInt(d1->dat.ival,d2->dat.ival,op);
        }
        else{
            res =OpFloat(d1->dat.dval,d2->dat.dval,op);
        }
    }
    else{
        dv1=(d1->type==INT)?d1->dat.ival:d1->dat.dval;
        dv2=(d2->type==INT)?d2->dat.ival:d2->dat.dval;
        res =OpFloat(dv1,dv2,op);
    }
    return res;
}