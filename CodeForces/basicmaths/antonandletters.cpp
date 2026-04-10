#include <iostream>
#include <string>
#include <set>

int main() {
    std::string s;
    std::getline(std::cin, s); // Read the full line

    std::set<char> distinct_letters;

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            distinct_letters.insert(c);
        }
    }

    std::cout << distinct_letters.size() << std::endl;

    return 0;
}
