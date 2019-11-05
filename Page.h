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
	//ҳ����
	int num_pages;
	//ȱҳ��
	float shortpage_rate;
	//ȱҳ����
	float shortpage_count;
};

