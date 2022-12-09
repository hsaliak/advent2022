#include <bits/stdc++.h>

std::set<char> chars{'A','B','C','X','Y','Z'};

enum Pick  {
    rock = 1,
    paper = 2,
    scissors = 3,
};
 
Pick charToPick(char c) {
    assert(chars.find(c) != chars.end());
    switch (c) {
    case 'A':
    case 'X':
	return Pick::rock;
    case 'B':
    case 'Y':
	return Pick::paper;
    case 'C':
    case 'Z':
	return Pick::scissors;
    default:
	assert(true == false);
    }
}

int scorePartTwo(char in, char out) {
    Pick inp = charToPick(in);
    switch (inp) {
    case Pick::rock: 
	switch (out) {
	case 'X':  // lose
	    return Pick::scissors + 0;
	case 'Y' : // draw
	    return Pick::rock + 3;
	case 'Z': // win
	    return Pick::paper + 6;
	}
    case Pick::paper: 
	switch (out) {
	case 'X':  // lose
	    return Pick::rock + 0;
	case 'Y' : // draw
	    return Pick::paper + 3;
	case 'Z': // win
	    return Pick::scissors + 6;
	}

    case Pick::scissors: 
	switch (out) {
	case 'X':  // lose
	    return Pick::paper + 0;
	case 'Y' : // draw
	    return Pick::scissors + 3;
	case 'Z': // win
	    return Pick::rock + 6;
	}
    }
    return 0;
}
int scoreGame(char in, char out) {
    Pick inp = charToPick(in);
    Pick outp = charToPick(out);
    std::cout << "IN:" << inp << " OUT:" << outp<< " \n";

    switch (inp) {
    case Pick::rock:
	switch (outp) {
	case  Pick::rock:
	    return Pick::rock + 3;
	case Pick::paper:
	    return Pick::paper + 6;
	case Pick::scissors:
	    return Pick::scissors + 0;
	}

    case Pick::paper:
	switch (outp) {
	case  Pick::rock:
	    return Pick::rock + 0;
	case Pick::paper:
	    return Pick::paper + 3;
	case Pick::scissors:
	    return Pick::scissors + 6;
	}
    case Pick::scissors:
	switch (outp) {
	case  Pick::rock:
	    return Pick::rock + 6;
	case Pick::paper:
	    return Pick::paper + 0;
	case Pick::scissors:
	    return Pick::scissors + 3;
	}
    }
    return 0;
}

void readInput(const std::string& filename, std::vector<char>& ins, std::vector<char>& outs) {
    std::ifstream input_file;
    input_file.open(filename);
    assert(input_file.is_open());
    while(input_file) {
	char inc, outc;
	input_file >> inc;
	// check if we read to the end of the file
	if (input_file.eof()) break;
	input_file >> outc;
	std::cout << "read: " << inc << " " << outc << "\n";
	ins.push_back(inc);
	outs.push_back(outc);
    }
}
int main(int argc, char *argv[])
{
    std::vector<char> ins;
    std::vector<char> outs;
    readInput("day2.txt", ins, outs);
    assert(ins.size() == outs.size());
    int total = 0;
    for (int i = 0 ; i < ins.size(); i++) {
	int 
	game_score = scorePartTwo(ins[i], outs[i]);
	total += game_score;
	std::cout << game_score << "\n";
    }
    std::cout << total << "\n";
    return 0;
}
