#include"MineSweep.hpp"

void game()
{
	vector<vector<int>> Mine;
	vector<vector<char>> Show;
	Mine.resize(HS);
	Show.resize(H);
	for (size_t i = 0; i < HS; i++)//初始化棋盘
	{
		Mine[i].resize(LS, 0);
	}
	for (size_t i = 0; i < H; i++)
	{
		Show[i].resize(L, '*');
	}
	setMine(Mine);
	start(Mine, Show);
}

void setMine(vector<vector<int>>& Mine)
{
	int x = 0, y = 0;
	srand((unsigned)time(NULL));
	int mines = NUMS;
	while (mines)
	{
		x = rand() % L + 1;
		y = rand() % H + 1;
		if (Mine[x][y] == 0)
		{
			Mine[x][y] = 1;
			mines--;
		}
	}
}
void Printm(vector<vector<int>>& Mine)
{
	int i = 0;
	cout << i++ << " ";
	for (int j = 1; j <= L; j++)
	{
		cout << j << " ";
	}
	cout << endl;
	for (size_t a = 1; a < Mine.size() - 1; a++)
	{
		cout << i++ << " ";
		for (size_t b = 1; b < Mine[a].size() - 1; b++)
		{
			cout << Mine[a][b] << " ";
		}
		cout << endl;
	}
}

void Printf(vector<vector<char>>& Show)
{
	int i = 0;
	cout << i++ << " ";
	for (int j = 1; j <= L; j++)
	{
		cout << j << " ";
	}
	cout << endl;
	for (const auto& e : Show)
	{
		cout << i++ << " ";
		for (const auto& i : e)
		{
			
			cout << i << " ";
		}
		cout << endl;
	}
}

void Search(vector<vector<int>> Mine, vector<vector<char>>& Show, int x, int y)
{
	int num = Mine[x - 1][y - 1] + Mine[x][y - 1] + Mine[x - 1][y] + Mine[x][y + 1] + 
		Mine[x + 1][y - 1] + Mine[x - 1][y + 1] + Mine[x + 1][y + 1] + Mine[x + 1][y];
	if (num == 0)
	{
		Show[x - 1][y - 1] = ' ';
		if (x - 1 > 0 && y - 1 > 0 && Show[x - 2][y - 2] == '*')
			Search(Mine, Show, x - 1, y - 1);
		if (y - 1 > 0 && Show[x - 1][y - 2] == '*')
			Search(Mine, Show, x, y - 1);
		if (x - 1 > 0 && Show[x - 2][y - 1] == '*')
			Search(Mine, Show, x - 1, y);
		if (x + 1 <= L && y + 1 <= H && Show[x][y] == '*')
			Search(Mine, Show, x + 1, y + 1);
		if (x + 1 <= L && Show[x][y - 1] == '*')
			Search(Mine, Show, x + 1, y);
		if (y + 1 <= H && Show[x - 1][y] == '*')
			Search(Mine, Show, x, y + 1);
		if (x - 1 > 0 && y + 1 <= H && Show[x - 2][y] == '*')
			Search(Mine, Show, x - 1, y + 1);
		if (x + 1 <= L && y - 1 > 0 && Show[x][y - 2] == '*')
			Search(Mine, Show, x + 1, y - 1);
	}
	else
	{
		Show[x - 1][y - 1] = '0' + num;
	}
}

int PlayerMove(vector<vector<int>>& Mine, vector<vector<char>>& Show, int& mines)
{
	int x = 0, y = 0;
	cin >> y >> x;
	while (x <= 0 || x > L || y <= 0 || y > H)
	{
		cout << "非法输入！请重新输入：";
		cin >> x >> y;
	}
	while (Show[x - 1][y - 1] != '*')
	{
		cout << "此坐标已经扫描了！请重新选择：" << endl;
		cin >> x >> y;
	}
	if (Mine[x][y] == 1)
	{
		if (mines == 1)
		{
			int tx = x, ty = y;
			while (Mine[x][y] == 1)
			{
				x = rand() % L + 1;
				y = rand() % H + 1;
			}
			Mine[x][y] = 1;
			Mine[tx][ty] = 0;
			x = tx, y = ty;
		}
		else
		{
			return -1;
		}
	}
	mines = 0;
	Search(Mine, Show, x, y);
	return 1;
}

int is_win(vector<vector<char>> Show)
{
	int count = 0;
	for (const auto& e : Show)
	{
		for (const auto& i : e)
		{
			if (i == '*')
			{
				count++;
			}
		}
	}
	if (count == NUMS)
	{
		return 0;
	}
	return 1;
}

void start(vector<vector<int>>& Mine, vector<vector<char>>& Show)
{
	int mines = 1, res = 1;
	while (res)
	{
		system("cls");
		Printf(Show);
		Printm(Mine);
		res = PlayerMove(Mine, Show, mines);
		res = is_win(Show);
	}
	if (res == -1)
	{
		cout << "游戏结束！你被炸死了！" << endl;
	}
	if (res == 0)
	{
		cout << "游戏结束！扫雷成功！" << endl;
	}
}