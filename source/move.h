#pragma once

#ifndef MATRIX_SIZE
#define MATRIX_SIZE 4
#endif // !MATRIX_SIZE


void CopyMatrix(int(*dest)[MATRIX_SIZE], int(*src)[4]);

bool Isdifferent(int(*a)[MATRIX_SIZE], int(*b)[MATRIX_SIZE]);

void MoveUp(int(*map)[4]);

void MoveDown(int(*map)[4]);

void MoveRight(int(*map)[4]);

void MoveLeft(int(*map)[4]);
