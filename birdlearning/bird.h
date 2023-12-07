#ifndef __BIRD_H__
#define __BIRD_H__

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define DIS 22
#define BLAN 9    //柱子子间的空隙
#define X_SUPPORT 16
#define Y_SUPPORT 16

typedef struct bird{
    COORD pos;  //windows API control char's location

    int score; 
}BIRD;

void PersonPlayer(void); //人类模式
void AIPlayer(void);     //ai MOD
int  ChooseAction(double Q[30][50][2],COORD state);                                  //动作选择 action choose
int  Learning(double Q[30][50][2],COORD state ,COORD newState,int action,BIRD*bird); //强化学习 learning
void CheckWall(COORD wall[]); //显示墙体 display wall
void PrtBird(BIRD *bird);     //显示小鸟 display bird
int  CheckWin(COORD *wall,BIRD *bird);//检测小鸟位置是否正确 check the bird's location is legal
void Begin(BIRD *bird);//显示上下边界和分数 display bound and score
BOOL SetConsoleColor(unsigned int wAttributes);//设置颜色 choose color
void Gotoxy (int x,int y);//定位光标  cursor's location
void HideCursor();//隐藏光标 


#endif