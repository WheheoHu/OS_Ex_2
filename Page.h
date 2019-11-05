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
	//ȱҳ��
	float shortpage_rate;
	//ȱҳ����
	float shortpage_count;
};

