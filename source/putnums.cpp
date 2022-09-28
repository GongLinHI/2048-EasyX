#include<stdio.h>
#include "putnums.h"
#include<Windows.h>
#include<assert.h>
/// <summary>
/// 判断是否有空间
/// </summary>
/// <param name="map">数字矩阵</param>
bool IsHaveSpace(int(*map)[4])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            if (map[i][j] == 0)
                return 1;
    return 0;
}

/// <summary>
/// 生成随机数字并放置到随机位置
/// </summary>
/// <param name="map">数字矩阵</param>
void PutRandNum(int(*map)[4])
{
    if (!IsHaveSpace(map))
        return;
    int x=0, y=0,num=0;
    int count = 0;//计算还有几个空位置
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            if (map[i][j] == 0)
            {
                x = i, y = j;//最后一个为空的xy坐标
                count++;
            }
    SYSTEMTIME t = { 0 };
    while (count>3)//如果空格数量过少，则不采用随机位置，直接指定为最后一个空位置放入对应的值
    {
        GetSystemTime(&t);
        srand((unsigned int)t.wMilliseconds);
        x = rand() % MATRIX_SIZE;
        Sleep(t.wDay);
        GetSystemTime(&t);
        srand((unsigned int)t.wMilliseconds);
        y = rand() % MATRIX_SIZE;

        if (map[x][y] == 0)
            break;
    }

    //确定是生成2还是4
    Sleep(t.wHour);
    GetSystemTime(&t);
    if (t.wMilliseconds <= 500)
        num = 2;
    else
        num = 4;
    map[x][y] = num;
    //printf("%d %d\n", x, y);
}

/// <summary>
/// 判断是否游戏结束
/// </summary>
/// <param name="map">数字矩阵</param>
/// <returns>
/// 0-未结束
/// 1-Lose
/// 2-Win
/// </returns>
int IsGameOver(int(*map)[4])
{
    bool L = true, R = true, U = true, D = true;
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            if (map[i][j] == 2048)
            {
                return 2;//Win
            }
    if (IsHaveSpace(map))
        return 0;//没结束
    else
    {
        for (int i = 0; i < MATRIX_SIZE; i++)
            for (int j = 0; j < MATRIX_SIZE; j++)
            {
                L = true, R = true, U = true, D = true;
                int cur = map[i][j];
                if (i - 1 >= 0 && map[i - 1][j] != cur)
                    U = false;
                if (i + 1 >= 0 && map[i + 1][j] != cur)
                    D = false;
                if (j - 1 >= 0 && map[i][j - 1] != cur)
                    L = false;
                if (j + 1 >= 0 && map[i][j + 1] != cur)
                    R = false;
                if (L || R || U || D)//至少有一个方向可以移动
                    return 0;//没结束
            }
        assert(!U && !D && !L && !R);
        if (!U && !D && !L && !R)
            return 1;
    }
    return -1;
}