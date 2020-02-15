#pragma once
#include<unordered_map>
#include"md5.hpp"
#include"file.hpp"

struct FileManage
{
public:
	FileManage() {};
	void Work();
	void show();

	void ScanFiles();
	void getFileMD5();
	void getCopyList();

	void DeletByFilename(const std::string filename);
	void DeletByMD5(const std::string md5);
	void DeletALLcopy();

private:
	std::unordered_set<std::string> _filemap;
	std::unordered_multimap<std::string, std::string> _md5ToFiles;
	std::unordered_map<std::string, std::string> _fileToMD5;

	std::string path;

	MD5 _md5;
};
