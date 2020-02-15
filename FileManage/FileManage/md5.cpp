#pragma once
#include"md5.hpp"

size_t MD5::_s[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
		12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
		15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

MD5::MD5()
{
	for (size_t i = 0; i < 64; i++)
	{
		_k[i] = static_cast<size_t>(abs(sin(i + 1)) * pow(2, 32));
	}
	reset();
}

void MD5::reset()
{
	_a = 0x67452301;
	_b = 0xefcdab89;
	_c = 0x98badcfe;
	_d = 0x10325476;
	_totalB = _lastB = 0;
	memset(_chunk, 0, 64);
}

void MD5::calMD5(size_t* _chunk)
{
	size_t a = _a, b = _b, c = _c, d = _d, g = 0;
	for (size_t i = 0; i < 16; i++)
	{
		g = i;
		size_t F = (b & c) | ((~b) & d);
		size_t tmp = d;
		d = c;
		c = b;
		b = b + shift((a + F + _k[i] + _chunk[g]), _s[i]);
		a = tmp;
	}
	for (size_t i = 16; i < 32; i++)
	{
		g = (5 * i + 1) % 16;
		size_t G = (b & d) | (c & (~d));
		size_t tmp = d;
		d = c;
		c = b;
		b = b + shift((a + G + _k[i] + _chunk[g]), _s[i]);
		a = tmp;
	}
	for (size_t i = 32; i < 48; i++)
	{
		g = (3 * i + 5) % 16;
		size_t H = b ^ c ^ d;
		size_t tmp = d;
		d = c;
		c = b;
		b = b + shift((a + H + _k[i] + _chunk[g]), _s[i]);
		a = tmp;
	}
	for (size_t i = 48; i < 64; i++)
	{
		g = (7 * i) % 16;
		size_t I = c ^ (b | (~d));
		size_t tmp = d;
		d = c;
		c = b;
		b = b + shift((a + I + _k[i] + _chunk[g]), _s[i]);
		a = tmp;
	}
	_a += a;
	_b += b;
	_c += c;
	_d += d;
}

std::string MD5::changeHex(size_t num)
{
	std::string strmap = "0123456789abcdef", res;
	for (size_t i = 0; i < 4; i++)
	{
		size_t curB = num >> (i * 8) & 0xff;
		std::string curRet;
		curRet += strmap[curB / 16];
		curRet += strmap[curB % 16];
		res += curRet;
	}
	return res;
}

void MD5::calFinalMD5()
{
	char* p = _chunk + _lastB;
	*p++ = 0x80;
	int remainB = 64 - _lastB - 1;
	if (remainB < 8)
	{
		memset(p, 0, remainB);
		calMD5((size_t*)_chunk);
		memset(_chunk, 0, 64);
	}
	else
	{
		memset(p, 0, remainB);
	}
	unsigned long long totalBits = _totalB;
	totalBits *= 8;
	((unsigned long long*) _chunk)[7] = totalBits;
	calMD5((size_t*)_chunk);
}

std::string MD5::getFileMD5(const char* path)
{
	std::ifstream fin(path,std::istream::binary);
	if (!fin.is_open())
	{
		std::cout << path;
		perror("此文件打开失败！");
		return "";
	}
	while (!fin.eof())
	{
		fin.read(_chunk, 64);
		if (fin.gcount() != 64)
		{
			break;
		}
		_totalB += 64;
		calMD5((size_t*) _chunk);
	}
	_lastB = fin.gcount();
	_totalB += _lastB;
	calFinalMD5();
	return changeHex(_a).append(changeHex(_b)).append(changeHex(_c)).append(changeHex(_d));
}