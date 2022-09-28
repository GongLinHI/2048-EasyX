//#include<Windows.h>

#include"Setup.h"
/// <summary>
/// main入口
/// </summary>
/// <returns>0</returns>
int main()
{
	Setup();
	return 0;
}

//int main()
//{
//    int arr[4][4] = { {4,2,2},{0},{4},{2} };
//    int(*p)[4] = arr;
//    print(p);
//    for (int i = 0; i < 3; i++)
//    {
//        PutRandNum(p); print(p);
//    }
//    return 0;
//
//}

//int main()
//{
//    int a;
//    srand((unsigned int)time(0));//修改种子
//    for (size_t i = 0; i < 10; i++)
//
//    {
//        a = rand();
//        printf("%d  ", a);
//
//    }
//}

//int main()
//{
//
//    SYSTEMTIME ti;
//    for (int i = 0; i < 100; i++)
//    {
//        Sleep(2);
//        GetSystemTime(&ti);
//        printf("%ld\n", ti.wMilliseconds);
//    }
//    return 0;
//}


//int main()
//{
//	initgraph(425, 425);
//	YouLose();
//	char ch = getchar();
//	return 0;
//}