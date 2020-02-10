#pragma once
#include<iostream>
#include<vector>
#include<time.h>

#define L 9
#define H 9
#define LS (L+2)
#define HS (H+2)
#define NUMS 10

using namespace std;

void game();
void setMine(vector<vector<int>>& Mine);
void start(vector<vector<int>>& Mine, vector<vector<char>>& Show);
void Printf(vector<vector<char>>& Show);
void Printm(vector<vector<int>>& Mine);
int PlayerMove(vector<vector<int>>& Mine, vector<vector<char>>& Show, int& mines);
void Search(vector<vector<int>> Mine, vector<vector<char>>& Show, int x, int y);
int is_win(vector<vector<char>> Show);