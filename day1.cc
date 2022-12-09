#include <bits/stdc++.h>

using Deer = std::vector<int>;
void readInput(const std::string& filename, std::vector<Deer>& results) {
    std::ifstream input_file;
    input_file.open(filename);
    assert(input_file.is_open());
    auto deer = Deer{}; // create an empty deer
    while(input_file){
	std::string input;
	std::getline(input_file, input);
	if (input.empty()) {
	    // push the current Deer into the results.
	    results.emplace_back(std::move(deer));
	    deer = Deer{};
	    continue;
	} 
	deer.emplace_back(std::stoi(input));
    }
}
int maxCalories(std::vector<Deer>& deers) {
    int max_calories = std::numeric_limits<int>::min();
    for (auto& d : deers) {
	int calories = 0;
	for (auto c : d) {
	    calories += c;
	}
	if (calories > max_calories) {
	    max_calories = calories;
	}
    }
    return max_calories;
}
int topThreeCalories(std::vector<Deer>& deers) {
    // get the calories by all elves, sort the list, compute the last3.
    std::vector<int> calory_count;
    for(auto& d: deers) {
	int calories = 0;
	for(auto c: d) {
	    calories+=c;
	}
	calory_count.push_back(calories);
    }
    std::sort(std::begin(calory_count), std::end(calory_count));
    assert(calory_count.size() >= 3);
    int max = 0;
    for (int i = 3 ; i > 0; i--) {
	max += *(calory_count.end() -i);
    }
    return max;

}

int main(int argc, char *argv[])
{
    std::vector<Deer> v{};
    readInput("day1.txt", v);
    std::cout << maxCalories(v) << "\n";
    std::cout << topThreeCalories(v) << "\n";
    return 0;
}
