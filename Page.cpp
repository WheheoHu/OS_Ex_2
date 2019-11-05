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
	std::deque<int>  page_queue;
	page_queue.resize(num_pages);
	for (auto i : procs) {

		bool fshorted = false;

		auto it = std::find(page_queue.begin(), page_queue.end(), i);
		if (it != page_queue.end()) {
			std::cout << i << "    ";
			i++;
			for (auto i : page_queue)
			{
				std::cout << i << " ";
			}

			std::cout << "\n";
			continue;


		}
		else
		{
			page_queue.push_front(i);
			shortpage_count++;
			fshorted = true;
			if (page_queue.size() >= num_pages)
			{
				page_queue.pop_back();
				page_queue.resize(num_pages);
			}
			//std::cout << page_queue.max_size();

		}
		//È±Ò³ÓÃ*±íÊ¾
		std::cout << i << "    ";
		for (auto i : page_queue)
		{
			std::cout << i << " ";
		}
		std::cout << "*\n";
	}


	std::cout <<"short page rate: "<< this->get_shortpage_rate() << std::endl;


}

Page::~Page()
{
}

float Page::get_shortpage_rate()
{
	return shortpage_count / procs.size();
}
