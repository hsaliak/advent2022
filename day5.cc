#include <bits/stdc++.h>

void readInput(const std::string& filename, std::vector<std::string>& input) {
    std::ifstream input_file;
    input_file.open(filename);
    assert(input_file.is_open());
    while(input_file) {
	std::string line;
	std::getline(input_file, line);
	if (!line.empty())
	    input.push_back(std::move(line));
    }
}

std::pair<int, int> stackCount(const std::vector<std::string>& lines) {
    int depth = 0;
    for (auto& l :lines ) {
	if (!l.empty() || l[0] != '[') {
	    // read from the back of this line.
	    depth++;
	    for (auto it = l.cend(); it >= l.cbegin(); --it) {
		if (std::isdigit(*it)) {
		    return {std::atoi(&*it), depth-1};
		}
	    }
	}
    }
    return {0,0};
}

void populateStacks( std::vector<std::stack<char>>& stacks, 
		    const std::vector<std::string>& lines,
		    int depth) {
    for (int i = depth ; i >= 0; i--) {
	int stackcounter = 0;
	// read the lines
	const std::string& line = lines[i];
	// read it
	for (auto i = 0; i < stacks.size(); ++i) {
	    // look up character for the stack.
	    int char_idx = 1+i*4;
	    if (std::isalpha(line[char_idx]))  {
		stacks[i].push(line[char_idx]);
	    }
	    
	    
	}
    }
}
void printStackTops(std::vector<std::stack<char>>& stacks){
    for (auto& s: stacks) {
	std::cout << s.top() << "\n";
    }
}

void makeMoves( std::vector<std::stack<char>>& stacks, 
		  const std::vector<std::string>& lines,
		  int depth
    ) {
    
    for (int i = depth+1 ; i < lines.size(); i++) {
	auto& line = lines[i];
	int count, from, to;
	count = std::atoi(&line[line.find("move") +4]);
	from = std::atoi(&line[line.find("from")+4]);
	to = std::atoi(&line[line.find("to")+2]);
	// lets make the moves..
	for (int c = 0; c < count; c++){
	    auto item = stacks[from-1].top();
	    stacks[from-1].pop();
	    stacks[to-1].push(item);
	}
    }
}
void makeMoves9001( std::vector<std::stack<char>>& stacks, 
		  const std::vector<std::string>& lines,
		  int depth
    ) {
    
    for (int i = depth+1 ; i < lines.size(); i++) {
	auto& line = lines[i];
	int count, from, to;
	count = std::atoi(&line[line.find("move") +4]);
	from = std::atoi(&line[line.find("from")+4]);
	to = std::atoi(&line[line.find("to")+2]);
	// lets make the moves..
	// push the items into a temporary stack
	std::stack<int> tempstack;
	for (int c = 0; c < count; c++){
	    auto item = stacks[from-1].top();
	    stacks[from-1].pop();
	    tempstack.push(item);
	}
	// pop the items from the temporary stack into the to stack
	while(!tempstack.empty()) {
	    auto item = tempstack.top();
	    stacks[to-1].push(item);
	    tempstack.pop();
	}
    }
}

int main(int argc, char *argv[])
{
    std::vector<std::string> lines;
    readInput("day5.txt", lines);
    std::for_each(std::begin(lines), std::end(lines), [](const auto& l ) {
	std::cout << l << "\n";

    });
    int count, depth;
    std::tie(count, depth)  = stackCount(lines);
    std::cout << stackCount(lines).second << "\n";
    // create the stacks
    std::vector<std::stack<char>> stacks(count);
    populateStacks(stacks, lines,  depth);
    makeMoves9001(stacks, lines, depth);
    printStackTops(stacks);

    return 0;
}
