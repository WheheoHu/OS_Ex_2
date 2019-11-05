#include "Page.h"
#include <queue>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

Page::Page(int _num_pages, std::vector<int> _procs)
{
	this->num_pages = _num_pages;
	this->procs = _procs;
	faultpage_count = 0;
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
			faultpage_count++;
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
	faultpage_count = 0;
	outfile.close();

}

void Page::LRU()
{
	std::unordered_set<int> page_set;
	std::unordered_map<int, int> indexes;
	outfile.open("outLRU.out", std::ios::out);
	for (auto i :procs )
	{
		for (auto &it:indexes)
		{
			it.second++;
		}
		if (page_set.size()<num_pages)
		{
			if (page_set.find(i)==page_set.end())
			{
				page_set.insert(i);
				indexes[i] = 0;
				faultpage_count++;
				outfile << i << "	";
				for (auto i:page_set )
				{
					outfile << i << " ";
				}
				outfile << "*\n";
			}
			else
			{
				outfile << i << "	";
				i++;
				indexes[i]++;
				for (auto i : page_set)
				{
					outfile << i << " ";
				}
				outfile << "\n";
			}
			
		}
		else
		{
			if (page_set.find(i) == page_set.end())
			{
				auto it = std::max_element(indexes.begin(), indexes.end(), [](const std::pair<int, int> &p1,
					const std::pair<int, int> &p2) {
					return p1.second < p2.second;
				});
				
				page_set.erase(it->first);
				indexes[it->first] = 0;
				page_set.insert(i);
				indexes[i] = 0;
				faultpage_count++;
				outfile << i << "	";
				for (auto i : page_set)
				{
					outfile << i << " ";
				}
				outfile << "*\n";
			}
			else
			{
				outfile << i << "	";
				i++;
				indexes[i]++;
				for (auto i : page_set)
				{
					outfile << i << " ";
				}
				outfile << "\n";
			}
		}
	}



	outfile << "short page rate: " << this->get_shortpage_rate() * 100 << "%" << std::endl;
	faultpage_count = 0;
	outfile.close();
}

Page::~Page()
{
}

float Page::get_shortpage_rate()
{
	return faultpage_count / procs.size();
}
