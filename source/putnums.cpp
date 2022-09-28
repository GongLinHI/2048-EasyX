#include<stdio.h>
#include "putnums.h"
#include<Windows.h>
#include<assert.h>
/// <summary>
/// �ж��Ƿ��пռ�
/// </summary>
/// <param name="map">���־���</param>
bool IsHaveSpace(int(*map)[4])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            if (map[i][j] == 0)
                return 1;
    return 0;
}

/// <summary>
/// ����������ֲ����õ����λ��
/// </summary>
/// <param name="map">���־���</param>
void PutRandNum(int(*map)[4])
{
    if (!IsHaveSpace(map))
        return;
    int x=0, y=0,num=0;
    int count = 0;//���㻹�м�����λ��
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            if (map[i][j] == 0)
            {
                x = i, y = j;//���һ��Ϊ�յ�xy����
                count++;
            }
    SYSTEMTIME t = { 0 };
    while (count>3)//����ո��������٣��򲻲������λ�ã�ֱ��ָ��Ϊ���һ����λ�÷����Ӧ��ֵ
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

    //ȷ��������2����4
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
/// �ж��Ƿ���Ϸ����
/// </summary>
/// <param name="map">���־���</param>
/// <returns>
/// 0-δ����
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
        return 0;//û����
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
                if (L || R || U || D)//������һ����������ƶ�
                    return 0;//û����
            }
        assert(!U && !D && !L && !R);
        if (!U && !D && !L && !R)
            return 1;
    }
    return -1;
}