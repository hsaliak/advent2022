#include <bits/stdc++.h>

int priority(char c) {
    if (std::islower(c)) {
	return c - 'a' + 1;
    } else {
    return c - 'A' +27;	
    }
}

void readInput(const std::string& filename, std::vector<std::string>&  lines) {
    std::ifstream input_file;
    input_file.open(filename);
    assert(input_file.is_open());
    while(input_file){
	std::string line;
	std::getline(input_file, line);
	if (!line.empty()) {
	lines.push_back(std::move(line));
	}
    }
}
int findDuplicateItem(std::string& line) {
    int half = line.size() / 2;
    for (auto it = line.begin(); it != line.begin() + half; ++it) {
	// find if the char exists in the second half.
	auto pos = std::find(line.begin() +half, line.end(), *it);
	if (pos != line.end()) {
	    // ok so we found the item,
	    std::cout << *it << "," << priority(*pos) << "\n";
	    return priority(*pos);
	}
    }
    
    return 0;
}

int commonElements(std::string& s1, std::string& s2, std::string& s3) {
// sort the strings
    std::sort(std::begin(s1), std::end(s1));
    std::sort(std::begin(s2), std::end(s2));
    std::sort(std::begin(s3), std::end(s3));
    // compute intersect between s1 and s2;
    std::string intersect;
    std::string final;
    std::set_intersection(s1.begin(), s1.end(), 
			  s2.begin(), s2.end(),
			  std::back_inserter(intersect));

    std::set_intersection(intersect.begin(), intersect.end(),
			  s3.begin(), s3.end(),
			  std::back_inserter(final));

    std::set<char> final_set{final.begin(), final.end()};
    assert(final_set.size() ==1);
    return priority(final[0]);
}

int main(int argc, char *argv[])
{
    std::vector<std::string> lines;
    readInput("day3.txt", lines);
    int totalPriority = 0;
    for (auto& i : lines){
	totalPriority += findDuplicateItem(i);
    }
    std::cout << totalPriority << "\n";
    assert(lines.size() % 3 == 0);
    std::cout << lines.size() << "\n";

    int badgePriority = 0;
    for (auto it = lines.begin(); it != lines.end(); it+=3) {
	badgePriority += commonElements(*it, *(it+1), *(it+2));
    }
    std::cout << badgePriority << "\n";
    

    return 0;
}
