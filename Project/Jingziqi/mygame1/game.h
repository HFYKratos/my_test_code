#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

#define H 5
#define L 5

void board(char A[H][L], int h , int l);
void playermove(char A[H][L], int h, int l);
void commove(char A[H][L]);
char WOL(char A[H][L], int h, int l);