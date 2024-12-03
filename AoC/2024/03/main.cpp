#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::regex pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
    std::smatch matches;
    std::vector<std::string> results;

    auto begin = text.cbegin();
    auto end = text.cend();

    while (std::regex_search(begin, end, matches, pattern)) {
      results.push_back(matches[0]);
      begin = matches.suffix().first;
    }

    int result = 0;
    bool enabled = true;
    for (const auto& match : results) {
      size_t comma_pos = match.find(',');
      if (match == "don't()") { 
        enabled = false;
      } else if (match == "do()") {
        enabled = true;
      } else if (enabled) {
        int first = stoi(match.substr(4,comma_pos));
        int second = stoi(match.substr(comma_pos + 1));
        result += first * second;
      }
    }

    cout << result << endl;

    return 0;
}
