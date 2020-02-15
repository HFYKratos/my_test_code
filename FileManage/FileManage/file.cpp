#pragma once
#include"file.hpp"

void searchDir(std::string path, std::unordered_set<std::string>& filemap)
{
	std::string match = path + "\\" + "*.*";
	_finddata_t filedata;
	auto handle = _findfirst(match.c_str(), &filedata);
	if (handle == -1)
	{
		perror("searching failed!");
		std::cout << match << std::endl;
		return;
	}
	do
	{
		if (filedata.attrib & _A_SUBDIR)
		{
			if (strcmp(filedata.name, ".") != 0 && strcmp(filedata.name, "..") != 0)
			{
				searchDir(path + "\\" + filedata.name, filemap);
			}
		}
		else
		{
			filemap.insert(path + "\\" + filedata.name);
		}
	} while (_findnext(handle, &filedata) == 0);
	_findclose(handle);
}
