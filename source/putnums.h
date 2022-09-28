#pragma once

#ifndef MATRIX_SIZE
#define MATRIX_SIZE 4
#endif // !MATRIX_SIZE

bool IsHaveSpace(int(*map)[4]);

void PutRandNum(int(*map)[4]);

int IsGameOver(int(*map)[4]);
