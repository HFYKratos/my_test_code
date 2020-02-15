#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>

class MD5
{
public:
	MD5();
	void reset();

	size_t shift(size_t num, size_t s)
	{
		return num << s | (num >> (32 - s));
	}
	std::string changeHex(size_t num);
	void calMD5(size_t* _chunk);
	void calFinalMD5();
	std::string getFileMD5(const char* path);

private:
	static size_t _s[64];

	size_t _totalB;
	size_t _lastB;

	size_t _k[64];
	char _chunk[64];

	size_t _a;
	size_t _b;
	size_t _c;
	size_t _d;
};