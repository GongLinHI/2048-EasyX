
#include"move.h"
#include"putnums.h"
#include"img.h"

#include<stdio.h>
#include<conio.h>
#include<Windows.h>

/// <summary>
/// 输出当前矩阵信息
/// </summary>
/// <param name="map">数字方阵</param>
void _print(int map[4][4])
{
    system("cls");
    for (int j = 0; j < 4; j++)
        printf("------");
    printf("-");
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("|");
            if (map[i][j]) //有数字就打印，没有就打印空格
                printf("%5d", map[i][j]);
            else
                printf("     ");

        }
        printf("|\n");
        for (int j = 0; j < 4; j++)
            printf("------");
        printf("-");
        printf("\n");
    }
    for (int j = 0; j < 4; j++)
        printf("*********");
    printf("\n");
    printf("使用方向键进行操作，连续两次Esc退出。\n");
    for (int j = 0; j < 4; j++)
       printf("*********");
    printf("\n");
}


/// <summary>
/// 读取方向键信息
/// </summary>
/// <returns>方向简称或者其他控制信息</returns>
char command()
{
    char c;
    c = _getch();
    c = _getch();
    if (c == 75)
        return 'L';
    else if (c == 77)
        return 'R';
    else if (c == 72)
        return 'U';
    else if (c == 80)
        return 'D';
    else if (c == 27)
        return 'E';
    else
        return '\0';
}

/// <summary>
/// 游戏流程
/// </summary>
/// <returns></returns>
int Setup()
{
    int m[4][4] = { 0 };
    print(m,true);
    PutRandNum(m);
    PutRandNum(m);
    print(m);

    while (!IsGameOver(m)) //0
    {
        int a[MATRIX_SIZE][MATRIX_SIZE] = { 0 };
        CopyMatrix(a, m);
        char cmd;
        while ((cmd = command()) == '\0');
        if (cmd == 'E')
            break;
        else if (cmd == 'U')
            MoveUp(m);
        else if (cmd == 'D')
            MoveDown(m);
        else if (cmd == 'L')
            MoveLeft(m);
        else if (cmd == 'R')
            MoveRight(m);
        Sleep(3);
        if (IsHaveSpace(m))
            PutRandNum(m);
        else if (!Isdifferent(a, m))
        {
            YouLose();
            break;
        }
        print(m);
        //todo： 没有空格时移动方向不对 lose

    }
    if (IsGameOver(m) == 2)
        YouWin();
    else//==1
        YouLose();
    char c = getchar();
    return 0;
}