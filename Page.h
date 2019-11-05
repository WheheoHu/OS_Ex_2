#pragma once
#include <vector>
class Page
{
public:
	
	Page(int, std::vector<int>);
	void FIFO();

	float get_shortpage_rate();
	~Page();

private:
	std::vector<int> procs;
	int num_pages;
	//ȱҳ��
	float shortpage_rate;
	//ȱҳ����
	float shortpage_count;
};

