#pragma once
#include <vector>
#include <fstream>
class Page
{
public:
	
	Page(int, std::vector<int>);
	void FIFO();

	float get_shortpage_rate();
	~Page();

private:
	std::vector<int> procs;
	std::fstream outfile;
	
	int num_pages;
	//È±Ò³ÂÊ
	float shortpage_rate;
	//È±Ò³¸öÊı
	float shortpage_count;
};

