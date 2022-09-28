
#include "move.h"

/// <summary>
/// ʵ��������src��dest�ĸ���
/// </summary>
/// <param name="dest">Ŀ������</param>
/// <param name="src">Դ����</param>
void CopyMatrix(int(*dest)[MATRIX_SIZE], int(*src)[4])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            dest[i][j] = src[i][j];
}


/// <summary>
/// �ж���������������Ƿ�������
/// </summary>
/// <param name="a">����1</param>
/// <param name="b">����2</param>
/// <returns>true-�в��  false-һ��</returns>
bool Isdifferent(int(*a)[MATRIX_SIZE], int(*b)[MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            if (a[i][j] != b[i][j])
                return true;
    return false;
}

/// <summary>
/// ʵ�������ƶ������������ֺϲ�
/// </summary>
/// <param name="map">���ַ���</param>
/// <param name="j">������</param>
void _MoveUp_(int(*map)[4],int j)
{
    int count = 0;
    int i = 0;//�к�
    for (int k = 0; k < MATRIX_SIZE; k++)
        if (map[k][j] != 0)
            count++;//����ÿ�е�Ԫ�ظ���  

    while (i < count)
    {
        while (map[i][j] == 0)
        {//�����ƶ�1
            for (int k = i; k < MATRIX_SIZE - 1; k++)
                map[k][j] = map[k + 1][j];
            map[MATRIX_SIZE - 1][j] = 0;
        }
        i++;
    }
}

/// <summary>
/// ʵ�������ƶ�������������ڵ����ֺϲ�
/// </summary>
/// <param name="map">���ַ���</param>
void MoveUp(int(*map)[4])
{
    for (int j = 0; j < MATRIX_SIZE; j++)//�����д���
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
/// ʵ�������ƶ������������ֺϲ�
/// </summary>
/// <param name="map">���ַ���</param>
/// <param name="j">������</param>
void _MoveDown_(int(*map)[4], int j)
{
    int count = 0;
    int i = MATRIX_SIZE-1;//�к�
    for (int k = 0; k < MATRIX_SIZE; k++)
        if (map[k][j] != 0)
            count++;//����ÿ�е�Ԫ�ظ���  

    while (i >= MATRIX_SIZE - count)
    {
        while (map[i][j] == 0)
        {//�����ƶ�1
            for (int k = i; k >0; k--)
                map[k][j] = map[k - 1][j];
            map[0][j] = 0;
        }
        i--;
    }
}

/// <summary>
/// ʵ�������ƶ�������������ڵ����ֺϲ�
/// </summary>
/// <param name="map">���ַ���</param>
void MoveDown(int(*map)[4])
{
    for (int j = 0; j < MATRIX_SIZE; j++)//�����д���
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
/// ʵ�������ƶ������������ֺϲ�
/// </summary>
/// <param name="map">���ַ���</param>
/// <param name="i">������</param>
void _MoveRight_(int(*map)[4], int i)
{
    int count = 0;
    int j = MATRIX_SIZE-1;//�к�
    for (int k = 0; k < MATRIX_SIZE; k++)
        if (map[i][k] != 0)
            count++;//����ÿ�е�Ԫ�ظ���  

    while (j >= MATRIX_SIZE- count)
    {
        while (map[i][j] == 0)
        {//�����ƶ�1
            for (int k = j; k >0 ;k--)
                map[i][k] = map[i][k-1];
            map[i][0] = 0;
        }
        j--;
    }
}

/// <summary>
/// ʵ�������ƶ�������������ڵ����ֺϲ�
/// </summary>
/// <param name="map">���ַ���</param>
void MoveRight(int(*map)[4])
{
    for (int i = 0; i < MATRIX_SIZE; i++)//�����д���
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
/// ʵ�������ƶ������������ֺϲ�
/// </summary>
/// <param name="map">���ַ���</param>
/// <param name="i">������</param>
void _MoveLeft_(int(*map)[4], int i)
{
    int count = 0;
    int j = 0;//�к�
    for (int k = 0; k < MATRIX_SIZE; k++)
        if (map[i][k] != 0)
            count++;//����ÿ�е�Ԫ�ظ���  

    while (j < count)
    {
        while (map[i][j] == 0)
        {//�����ƶ�1
            for (int k = j; k<MATRIX_SIZE-1; k++)
                map[i][k] = map[i][k + 1];
            map[i][MATRIX_SIZE-1] = 0;
        }
        j++;
    }
}

/// <summary>
/// ʵ�������ƶ�������������ڵ����ֺϲ�
/// </summary>
/// <param name="map">���ַ���</param>
void MoveLeft(int(*map)[4])
{
    for (int i = 0; i < MATRIX_SIZE; i++)//�����д���
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