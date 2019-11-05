#include "Page.h"
#include <queue>
#include <iostream>




Page::Page(int _num_pages, std::vector<int> _procs)
{
	this->num_pages = _num_pages;
	this->procs = _procs;
}

void Page::FIFO()
{
	std::deque<int>  page_queue(num_pages);
	
	for (auto i : procs) {

		if (page_queue.empty())
		{
			page_queue.push_back(i);
		}
		auto it = std::find(page_queue.begin(), page_queue.end(), i);
		if (it!=page_queue.end()) {
			break;
		}
		else
		{
			page_queue.push_front(i);
			shortpage_count++;
		}




		

	}
	
	
}

Page::~Page()
{
}

float Page::get_shortpage_rate()
{
	return shortpage_count / procs.size();
}
