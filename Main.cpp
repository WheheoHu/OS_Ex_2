#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <tchar.h>
constexpr int BUFSIZE = 512;
int main() {

	HANDLE hpipe = INVALID_HANDLE_VALUE, hThread = NULL;
	LPCTSTR lpszPipename = TEXT("\\\\.\\pipe\\mynamedpipe");
	hpipe = CreateNamedPipe(
		lpszPipename,
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE |
		PIPE_READMODE_MESSAGE |
		PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES,
		BUFSIZE,
		BUFSIZE,
		0,
		NULL
	);
	if (hpipe == INVALID_HANDLE_VALUE)
	{

		_tprintf(TEXT("CreateNamedPipe failed, GLE=%d.\n"), GetLastError());
		return -1;
	}

	//bool fConnected = ConnectNamedPipe(hpipe, NULL) ?
	//	TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);

	CloseHandle(hpipe);

	std::vector<int> page_num;
	std::fstream infile("infile.in", std::ios::in);
	while (!infile.eof())
	{
		int num_temp;
		infile >> num_temp;
		page_num.push_back(num_temp);

	}
	infile.close();
	system("pause");
}