#include<easyx.h>
#include<graphics.h>
#include "img.h"

IMAGE load(int i)
{
	IMAGE img;
	if (i == 0)
		loadimage(&img, _T(".\\resource\\0.jpg"), 100, 100, true);
	else if (i == 2)
		loadimage(&img, _T(".\\resource\\2.jpg"), 100, 100, true);
	else if (i == 4)
		loadimage(&img, _T(".\\resource\\4.jpg"), 100, 100, true);
	else if (i == 8)
		loadimage(&img, _T(".\\resource\\8.jpg"), 100, 100, true);
	else if (i == 16)
		loadimage(&img, _T(".\\resource\\16.jpg"), 100, 100, true);
	else if (i == 32)
		loadimage(&img, _T(".\\resource\\32.jpg"), 100, 100, true);
	else if (i == 64)
		loadimage(&img, _T(".\\resource\\64.jpg"), 100, 100, true);
	else if (i == 128)
		loadimage(&img, _T(".\\resource\\128.jpg"), 100, 100, true);
	else if (i == 256)
		loadimage(&img, _T(".\\resource\\256.jpg"), 100, 100, true);
	else if (i == 512)
		loadimage(&img, _T(".\\resource\\512.jpg"), 100, 100, true);
	else if (i == 1024)
		loadimage(&img, _T(".\\resource\\1024.jpg"), 100, 100, true);
	else if (i == 2048)
		loadimage(&img, _T(".\\resource\\2048.jpg"), 100, 100, true);

	return img;
}


void print(int map[4][4], bool flg)
{
	if (flg)
		initgraph(425, 425);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			IMAGE Image = load(map[i][j]);
			int y = 5 + (105 * i);
			int x = 5 + (105 * j);
			putimage(x, y, &Image);
		}
	//destx=5+(105*j);
	//desty=5+(105*i);
}


void YouWin()
{
	setbkmode(TRANSPARENT);//Í¸Ã÷±³¾°
	RECT r = { 0, 0, 424, 424 };
	drawtext(_T("You Win!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void YouLose()
{
	setbkmode(TRANSPARENT);//Í¸Ã÷±³¾°
	RECT r = { 0, 0, 424, 424 };
	drawtext(_T("You Lose!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}