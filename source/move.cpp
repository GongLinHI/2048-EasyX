
#include "move.h"

/// <summary>
/// 实现数据由src向dest的复制
/// </summary>
/// <param name="dest">目标数组</param>
/// <param name="src">源数组</param>
void CopyMatrix(int(*dest)[MATRIX_SIZE], int(*src)[4])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            dest[i][j] = src[i][j];
}


/// <summary>
/// 判断两个数组的内容是否有区别
/// </summary>
/// <param name="a">数组1</param>
/// <param name="b">数组2</param>
/// <returns>true-有差别  false-一致</returns>
bool Isdifferent(int(*a)[MATRIX_SIZE], int(*b)[MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            if (a[i][j] != b[i][j])
                return true;
    return false;
}

/// <summary>
/// 实现向上移动，不进行数字合并
/// </summary>
/// <param name="map">数字方阵</param>
/// <param name="j">列索引</param>
void _MoveUp_(int(*map)[4],int j)
{
    int count = 0;
    int i = 0;//行号
    for (int k = 0; k < MATRIX_SIZE; k++)
        if (map[k][j] != 0)
            count++;//计算每列的元素个数  

    while (i < count)
    {
        while (map[i][j] == 0)
        {//向上移动1
            for (int k = i; k < MATRIX_SIZE - 1; k++)
                map[k][j] = map[k + 1][j];
            map[MATRIX_SIZE - 1][j] = 0;
        }
        i++;
    }
}

/// <summary>
/// 实现向上移动，含相等且相邻的数字合并
/// </summary>
/// <param name="map">数字方阵</param>
void MoveUp(int(*map)[4])
{
    for (int j = 0; j < MATRIX_SIZE; j++)//按照列处理
    {
        _MoveUp_(map,j);
        for(int k=0;k<MATRIX_SIZE-1;k++)
            if (map[k][j] == map[k + 1][j] && map[k][j] != 0)
            {
                map[k][j] *=2;
                map[k + 1][j] = 0;
                break;
            }
        _MoveUp_(map,j);
    }
}

/// <summary>
/// 实现向下移动，不进行数字合并
/// </summary>
/// <param name="map">数字方阵</param>
/// <param name="j">列索引</param>
void _MoveDown_(int(*map)[4], int j)
{
    int count = 0;
    int i = MATRIX_SIZE-1;//行号
    for (int k = 0; k < MATRIX_SIZE; k++)
        if (map[k][j] != 0)
            count++;//计算每列的元素个数  

    while (i >= MATRIX_SIZE - count)
    {
        while (map[i][j] == 0)
        {//向下移动1
            for (int k = i; k >0; k--)
                map[k][j] = map[k - 1][j];
            map[0][j] = 0;
        }
        i--;
    }
}

/// <summary>
/// 实现向下移动，含相等且相邻的数字合并
/// </summary>
/// <param name="map">数字方阵</param>
void MoveDown(int(*map)[4])
{
    for (int j = 0; j < MATRIX_SIZE; j++)//按照列处理
    {
        _MoveDown_(map, j);
        for (int k = MATRIX_SIZE-1; k >=0; k--)
            if (map[k][j] == map[k - 1][j] && map[k][j] != 0)
            {
                map[k][j] *= 2;
                map[k - 1][j] = 0;
                break;
            }
        _MoveDown_(map, j);
    }
}

/// <summary>
/// 实现向右移动，不进行数字合并
/// </summary>
/// <param name="map">数字方阵</param>
/// <param name="i">行索引</param>
void _MoveRight_(int(*map)[4], int i)
{
    int count = 0;
    int j = MATRIX_SIZE-1;//列号
    for (int k = 0; k < MATRIX_SIZE; k++)
        if (map[i][k] != 0)
            count++;//计算每行的元素个数  

    while (j >= MATRIX_SIZE- count)
    {
        while (map[i][j] == 0)
        {//向右移动1
            for (int k = j; k >0 ;k--)
                map[i][k] = map[i][k-1];
            map[i][0] = 0;
        }
        j--;
    }
}

/// <summary>
/// 实现向右移动，含相等且相邻的数字合并
/// </summary>
/// <param name="map">数字方阵</param>
void MoveRight(int(*map)[4])
{
    for (int i = 0; i < MATRIX_SIZE; i++)//按照行处理
    {
        _MoveRight_(map, i);
        for (int k = MATRIX_SIZE-1; k >=0;k--)
            if (map[i][k] == map[i][k-1] && map[i][k] != 0)
            {
                map[i][k] *= 2;
                map[i][k - 1] = 0;
                break;
            }
        _MoveRight_(map, i);
    }
}

/// <summary>
/// 实现向左移动，不进行数字合并
/// </summary>
/// <param name="map">数字方阵</param>
/// <param name="i">行索引</param>
void _MoveLeft_(int(*map)[4], int i)
{
    int count = 0;
    int j = 0;//列号
    for (int k = 0; k < MATRIX_SIZE; k++)
        if (map[i][k] != 0)
            count++;//计算每行的元素个数  

    while (j < count)
    {
        while (map[i][j] == 0)
        {//向左移动1
            for (int k = j; k<MATRIX_SIZE-1; k++)
                map[i][k] = map[i][k + 1];
            map[i][MATRIX_SIZE-1] = 0;
        }
        j++;
    }
}

/// <summary>
/// 实现向左移动，含相等且相邻的数字合并
/// </summary>
/// <param name="map">数字方阵</param>
void MoveLeft(int(*map)[4])
{
    for (int i = 0; i < MATRIX_SIZE; i++)//按照行处理
    {
        _MoveLeft_(map, i);
        for (int k = 0; k < MATRIX_SIZE - 1; k++)
            if (map[i][k] == map[i][k + 1] && map[i][k] != 0)
            {
                map[i][k] *= 2;
                map[i][k + 1] = 0;
                break;
            }
        _MoveLeft_(map, i);
    }
}