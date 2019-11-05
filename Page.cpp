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
	outfile.open("outFIFO.out", std::ios::out);
	std::deque<int>  page_queue;
	page_queue.resize(num_pages);
	for (auto i : procs) {

		bool fshorted = false;

		auto it = std::find(page_queue.begin(), page_queue.end(), i);
		if (it != page_queue.end()) {
			outfile << i << "    ";
			i++;
			for (auto i : page_queue)
			{
				outfile << i << " ";
			}

			outfile << "\n";
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
			//outfile << page_queue.max_size();

		}
		//È±Ò³ÓÃ*±íÊ¾
		outfile << i << "    ";
		for (auto i : page_queue)
		{
			outfile << i << " ";
		}
		outfile << "*\n";
	}


	outfile <<"short page rate: "<< this->get_shortpage_rate()*100 <<"%"<< std::endl;

	outfile.close();

}

Page::~Page()
{
}

float Page::get_shortpage_rate()
{
	return shortpage_count / procs.size();
}
