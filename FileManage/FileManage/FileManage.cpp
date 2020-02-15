#pragma once
#include"FileManage.hpp"

void FileManage::show()
{
	std::cout << "********************************************" << std::endl;
	std::cout << "****         请选择需要进行的操作:      ****" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << "****    1.删除所有副本                  ****" << std::endl;
	std::cout << "****    2.输入MD5值删除副本文件         ****" << std::endl;
	std::cout << "****    3.输入文件删除副本文件          ****" << std::endl;
	std::cout << "****    4.展示当前目录的文件            ****" << std::endl;
	std::cout << "****    5.展示当前目录所有有副本        ****" << std::endl;
	std::cout << "****    6.重新选择文件目录              ****" << std::endl;
	std::cout << "****    0.退出                          ****" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << "当前目录为：" << path << "       文件总数为:" << _filemap.size() << std::endl;
}


void FileManage::Work()
{
	ScanFiles();
	getFileMD5();
	getCopyList();
	system("cls");
	int input = 1;
	std::string tmp;
	while (input)
	{
		show();
		std::cin >> input;
		std::cin.ignore();
		switch (input)
		{
		case 0:
			break;
		case 1:
			DeletALLcopy();
			continue;
		case 2:
			std::cout << "请输入指定的MD5码值：";
			std::cin >> tmp;
			std::cin.ignore();
			DeletByMD5(tmp);
			continue;
		case 3:
			std::cout << "请输入指定的文件：";
			getline(std::cin, tmp);
			DeletByFilename(tmp);
			continue;
		case 4:
			system("cls");
			for (const auto& e : _filemap)
			{
				std::cout << e << std::endl;
			}
			std::cout << "一共" << _filemap.size() << "个文件" << std::endl;
			continue;
		case 5:
			if (_fileToMD5.size() == 0)
			{
				std::cout << "当前目录下没有相同的副本文件！" << std::endl;
				continue;
			}
			system("cls");
			for (const auto& e : _fileToMD5)
			{
				std::cout << "文件为：" << std::endl;
				std::cout << e.first << std::endl;
				std::cout << "MD5: " << e.second << std::endl;
			}
			continue;
		case 6:
			ScanFiles();
			getFileMD5();
			getCopyList();
			continue;
		default:
			std::cout << "非法输入！请重新输入->" << std::endl;;
			continue;
		}

	}
}

void FileManage::ScanFiles()
{
	std::cout << "**********************************" << std::endl;
	std::cout << "****请输入需要检索的文件路径->****" << std::endl;
	std::cout << "**********************************" << std::endl;
	_filemap.clear();
	getline(std::cin, path);
	searchDir(path, _filemap);
}

void FileManage::getFileMD5()
{
	_md5ToFiles.clear();
	for (const auto e : _filemap)
	{
		_md5.reset();
		_md5ToFiles.insert(make_pair(_md5.getFileMD5(e.c_str()), e));
	}
}

void FileManage::getCopyList()
{
	_fileToMD5.clear();
	auto it = _md5ToFiles.begin();
	while (it != _md5ToFiles.end())
	{
		size_t count = _md5ToFiles.count((*it).first);
		if (count > 1)
		{
			auto t = _md5ToFiles.equal_range((*it).first);
			auto tit = t.first;
			while (tit != t.second)
			{
				_fileToMD5.insert(make_pair((*tit).second, (*tit).first));
				tit++;
			}
			it = t.second;
		}
		else
		{
			it = _md5ToFiles.erase(it);
		}
	}
}

void FileManage::DeletByFilename(const std::string filename)
{
	if (_filemap.count(filename) == 0)
	{
		std::cout << "未找到指定的文件或文件目录！请重新输入！" << std::endl;
		return;
	}
	const auto md5 = (*_fileToMD5.find(filename)).second;
	auto t = _md5ToFiles.equal_range(md5);
	auto it = t.first;
	_fileToMD5.erase((*it).second);
	while (it != t.second)
	{
		if ((*it).second != filename)
		{
			std::cout << "文件：" << (*it).second << "已经被删除！" << std::endl;
			_filemap.erase((*it).second);
			_fileToMD5.erase((*it).second);
			remove((*it).second.c_str());
		}
		it++;
	}
	_md5ToFiles.erase(md5);
}

void FileManage::DeletByMD5(const std::string md5)
{
	if (_md5ToFiles.count(md5) == 0)
	{
		std::cout << "未找到指定MD5码文件！请重新输入！" << std::endl;
		return;
	}
	auto t = _md5ToFiles.equal_range(md5);
	auto it = t.first;
	std::string filename = (*it).second;
	_fileToMD5.erase((*it).second);
	while (it != t.second)
	{
		if ((*it).second != filename)
		{
			std::cout << "文件：" << (*it).second << "已经被删除！" << std::endl;
			_filemap.erase((*it).second);
			_fileToMD5.erase((*it).second);
			remove((*it).second.c_str());
		}
		it++;
	}
	_md5ToFiles.erase(md5);
}

void FileManage::DeletALLcopy()
{
	while (_md5ToFiles.size() > 0)
	{
		auto it = _md5ToFiles.begin();
		DeletByMD5((*it).first);
	}
}