#include <bits/stdc++.h>



using pairs = std::pair<std::pair<int,int>, std::pair<int, int>>;
    
void readInput(const std::string& filename, std::vector<pairs>& input) {
    std::ifstream input_file;
    input_file.open(filename);
    assert(input_file.is_open());
    while(input_file) {
	pairs p;
	input_file >> p.first.first;
	if (input_file.eof()) break; // check if we read eof , last line.
	input_file.ignore(1);
	input_file >> p.first.second;
	input_file.ignore(1);
	input_file >> p.second.first;
	input_file.ignore(1);
	input_file >> p.second.second;
	input.push_back(std::move(p));
    }

}

int contains(const pairs& p) {
    std::pair<int,int> minmax{ 
	std::min({p.first.first, p.first.second, p.second.first, p.second.second}),
	std::max({p.first.first, p.first.second, p.second.first, p.second.second})};
    return minmax == p.first || minmax == p.second;
    
}
int overlaps(const pairs& p) {
    // find the pair with the min
    if (p.first.first <= p.second.first) {
	// first pair is first.
	return p.first.second >= p.second.first;
    } else { 
	return p.second.second >= p.first.first;
    }
    
    return 0;
}
int main(int argc, char *argv[])
{
    std::vector<pairs> inputs;
    readInput("day4.txt", inputs);
    int fullyContains = 0;
    int overlap =0;
    for (auto& p : inputs) {
	std::cout << p.first.first << "-" << p.first.second << "," << p.second.first << "-" << p.second.second << "\n";
	fullyContains += contains(p);
	overlap += overlaps(p);
    }

    std::cout << fullyContains << "\n";
    std::cout << overlap << "\n";

    
    return 0;
}
