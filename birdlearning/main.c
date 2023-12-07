#include "bird.h"

int main()//int argc, char const *argv[]
{
    int argc=0;
    scanf("%d",&argc);
    srand((unsigned int)time(NULL));
    if(argc>1)
        AIPlayer();
    else
        PersonPlayer();
    return 0;
}
