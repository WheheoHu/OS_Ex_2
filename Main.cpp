#include <iostream>
#include <fstream>
#include <vector>

int main() {
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