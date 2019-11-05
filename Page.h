#pragma once
#include <vector>
#include <fstream>
class Page
{
public:
	
	Page(int, std::vector<int>);
	void FIFO();
	void LRU();
	float get_shortpage_rate();
	~Page();

private:
	std::vector<int> procs;
	std::fstream outfile;
	//页面数
	int num_pages;
	//缺页率
	float faultpage_rate;
	//缺页个数
	float faultpage_count;
};

