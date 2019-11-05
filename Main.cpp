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

	//hpipe = CreateNamedPipe(
	//	lpszPipename,
	//	PIPE_ACCESS_DUPLEX,
	//	PIPE_TYPE_MESSAGE |
	//	PIPE_READMODE_MESSAGE |
	//	PIPE_WAIT,
	//	PIPE_UNLIMITED_INSTANCES,
	//	BUFSIZE,
	//	BUFSIZE,
	//	0,
	//	NULL
	//);

	//if (hpipe == INVALID_HANDLE_VALUE)
	//{

	//	_tprintf(TEXT("CreateNamedPipe failed, GLE=%d.\n"), GetLastError());
	//	return -1;
	//}

	//DWORD dwWritten;
	//HANDLE hpipe_write;
	//hpipe_write = CreateFile(
	//	lpszPipename,
	//	GENERIC_READ | GENERIC_WRITE,
	//	0,
	//	NULL,
	//	OPEN_EXISTING,
	//	0,
	//	NULL
	//);

	//if (hpipe_write != INVALID_HANDLE_VALUE)
	//{
	//	WriteFile(hpipe_write,
	//		"test message\n",
	//		15,
	//		&dwWritten,
	//		NULL
	//	);
	//	CloseHandle(hpipe_write);
	//}


	//BOOL fConnected = FALSE;
	//if (hpipe != INVALID_HANDLE_VALUE)
	//{
	//	fConnected = ConnectNamedPipe(hpipe, NULL) ?
	//		TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
	//	if (fConnected)
	//	{
	//		while (ReadFile(hpipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
	//		{
	//			/* add terminating zero */
	//			buffer[dwRead] = '\0';

	//			/* do something with data in buffer */
	//			printf("%s", buffer);
	//		}
	//	}
	//	DisconnectNamedPipe(hpipe);
	//}


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