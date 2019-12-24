#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <tchar.h>
#include <algorithm>

#include"Page.h"
constexpr int BUFSIZE = 512;
int main() {
	//LPCTSTR lpszPipename = TEXT("\\\\.\\pipe\\mynamedpipe");
	//char buffer[1024];
	//DWORD dwRead;

	//HANDLE hpipe = INVALID_HANDLE_VALUE;



	//读入进程访问序列
	std::vector<int> procs;
	std::fstream infile("infile.in", std::ios::in);
	while (!infile.eof())
	{
		int num_temp;
		infile >> num_temp;
		procs.push_back(num_temp);

	}
	infile.close();

	//页面管理
	Page page(4,procs);
	page.FIFO();
	page.LRU();

//	system("pause");
}