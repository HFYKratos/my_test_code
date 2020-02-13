#pragma once
#include<iostream>

class MD5
{
public:
	//Œª‘ÀÀ„
	MD5();

private:

	static size_t s[64];

	size_t chunk[64];

	size_t _a;
	size_t _b;
	size_t _c;
	size_t _d;
};

