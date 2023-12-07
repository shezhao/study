#include "bird.h"

//功能：人工智能模式
void AIPlayer(void){
    double Q_table[30][50][2]={0};
    int count = 0;
    int bestScore = 0;
    while(1){
        BIRD bird={{17,10},0};
        COORD wall[3]={{30,4},{55,13},{80,8}};
        int action = 0; //行为 1:玩家输入空格 0:不输入,自动下降
        //状态
        COORD state={0,0};
        //行为后
        COORD newState={bird.pos.X-wall[0].X,bird.pos.Y-wall[0].Y};
        //自动学习
        do{
            //初始状态与上一次末状态一致
            state =newState;
            Begin(&bird);
            printf("\ncount=% 4d\nbest=% 4d",count,bestScore);
            CheckWall(wall);
            action  = ChooseAction(Q_table,state);

            if(action)  bird.pos.Y-=1;
            else        bird.pos.Y+=1;
            for (int  i = 0; i < 3; i++)
            {
                wall[i].X--;
            }
            //执行新状态
            newState.X = bird.pos.X-wall[0].X;
            newState.Y = bird.pos.Y-wall[0].Y;
            PrtBird(&bird);
            Sleep(20);
            }while(Learning(Q_table,state,newState,action,&bird));
            if(bird.score>bestScore) bestScore=bird.score;

            count ++;
    }
}

//功能:动作选择
int ChooseAction(double Q[30][50][2],COORD state){
    double eGreedy = 0.9;/// 贪婪率
    double action = Q[state.X+X_SUPPORT][state.Y+Y_SUPPORT][1]-Q[state.X+X_SUPPORT][state.Y+Y_SUPPORT][0];

    if((double)rand()/RAND_MAX>eGreedy||action==0)
    {
        return rand()%2;
    }
    return action > 0;
}
//功能:强化学习
int  Learning(double Q[30][50][2],COORD state ,COORD newState,int action,BIRD*bird)
{
    double learningRate = 0.3;//学习率
    double rewardDecay =0.4;//奖励折扣
    double averNewState =0;
    int reward =1;
    if(bird->pos.Y<1||bird->pos.Y>25||(newState.X>=0&&(newState.Y<=0||newState.Y>=BLAN)))
    {reward = -100;}
    bird->score+=1;
    //更新状态
    averNewState = (Q[state.X+X_SUPPORT][state.Y+Y_SUPPORT][1]+Q[state.X+X_SUPPORT][state.Y+Y_SUPPORT][0])/2;
    //学习->更新记忆表
    Q[state.X+X_SUPPORT][state.Y+Y_SUPPORT][action]+=
                        learningRate * ((reward+rewardDecay * averNewState)
                        -Q[state.X+X_SUPPORT][state.Y+Y_SUPPORT][action]);
    return reward==1;//受惩罚返回0
}
//功能:显示墙体 display wall
void CheckWall(COORD wall[])
{
    int i;
    HideCursor();
    COORD temp = {wall[2].X+DIS,rand()%13+5};
    if(wall[0].X<10)
    {
        wall[0]=wall[1];
        wall[1]=wall[2];
        wall[2]=temp;
    }
    for (int i = 0; i < 3; i++)
    {
        //显示上部分
        temp.X=wall[i].X+1;
        SetConsoleColor(0x0C);
        for (temp.Y=2;temp.Y< wall[i].Y; temp.Y++)
        {
            Gotoxy(temp.X,temp.Y);
            printf("########");
        }
        temp.X--;
        Gotoxy(temp.X,temp.Y);
        printf("#########");

        //显示下半部分
        temp.Y+=BLAN;
        Gotoxy(temp.X,temp.Y);
        printf("#########");
        temp.X++;
        temp.Y++;
        for ( ; (temp.Y) < 26; temp.Y++)
        {
            Gotoxy(temp.X,temp.Y);
            printf("########");
        } 
    }
} 
//功能:显示小鸟 display bird
void PrtBird(BIRD *bird)
{
    SetConsoleColor(0x0E);
    Gotoxy(bird->pos.X,bird->pos.Y);
    printf("00->");
  
}
//功能:检测小鸟位置是否正确 check the bird's location is legal
int  CheckWin(COORD *wall,BIRD *bird)
{
    if(bird->pos.X>=wall->X)
    {
        if(bird->pos.Y<=wall->Y||bird->pos.Y>=wall->Y+BLAN)
        {
            return 0;
        }
    }
    if(bird->pos.Y<1||bird->pos.Y>26)
    {
        return 0;
    }
    (bird->score)++;
    return 1;

}
//功能:显示上下边界和分数 display bound and score
void Begin(BIRD *bird)
{
    system("cls");
    Gotoxy(0,26);
    printf("==============================================================================================");
    Gotoxy(0,1);
    printf("==============================================================================================");
    printf("\nscore=% 4d",bird->score);
}
//功能:设置颜色 choose color
BOOL SetConsoleColor(unsigned int wAttributes)
{
    HANDLE hOutput =GetStdHandle(STD_OUTPUT_HANDLE);
    if(hOutput == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }
    return SetConsoleTextAttribute(hOutput,wAttributes);

}
//功能:定位光标  cursor's location
void Gotoxy (int x,int y)
{
    COORD pos = {x,y};
    HANDLE hOutput =GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
}
//功能:隐藏光标 
void HideCursor()
{
    HANDLE handle =  GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle,&CursorInfo);
    CursorInfo.bVisible=0;
    SetConsoleCursorInfo(handle,&CursorInfo);
}
//人类模式
void PersonPlayer(void)
{
    BIRD bird={{22,10},0};
    COORD wall[3]={{40,10},{60,6},{80,8}};
    int i;
    char ch;
    while(CheckWin(wall,&bird))
    {
        Begin(&bird);
        CheckWall(wall);
        PrtBird(&bird);
        Sleep(200);
        if((kbhit()))
        {
            ch=getch();
            if(ch==' ')
            {
                bird.pos.Y-=1;
            }
        }
        else
        {
            bird.pos.Y+=1;
        }
        for ( i = 0; i < 3; i++)
        {
            wall[i].X--;
        }
    } 
   
}