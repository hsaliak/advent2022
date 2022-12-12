#include <bits/stdc++.h>

std::string readInput(const std::string& filename) {
    std::ifstream input_file;
    input_file.open(filename);
    assert(input_file.is_open());
    std::string line;
    std::getline(input_file, line);
    return line;
}

void maybeAddToCode(std::deque<char>& code, char c) {
    auto pos = std::find(code.begin(), code.end(), c);
if (pos != code.end()) {
    // invalidate the dequeue until the pos.
    for (auto it = code.begin(); it <= pos; ++it) {
	code.pop_front();
    }
}
code.push_back(c); // unconditionally add;
}

std::tuple<std::string, int> controlString(std::string& line) {
    std::deque<char> code;
    int processed = 0;
    for (auto c : line) {
	maybeAddToCode(code, c);
	processed++;
	if (code.size() == 14) { // change to 4 for part 1
	    // return the code.
	    return {std::string{code.begin(), code.end()}, processed};
	}
    }
    return {"", 0};
}

int main(int argc, char *argv[])
{
    std::string line = readInput("day6.txt");
    std::cout << line << "\n";
    std::string code;
    int count;
    std::tie<std::string, int>(code, count) = controlString(line);
    std::cout << code  << "count: " << count << "\n";
 
    return 0;
}
