#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    int vars[3] = {0};

    regex pattern(R"(([a-c])\s*:=\s*([a-c]|\d);)");
    sregex_iterator iter(input.begin(), input.end(), pattern);
    sregex_iterator end;

    for (; iter != end; ++iter) {
        smatch match = *iter;
        char left = match[1].str()[0];
        string right = match[2].str();

        int var_index = left - 'a';
        if (isdigit(right[0])) {
            vars[var_index] = right[0] - '0';
        } else {
            vars[var_index] = vars[right[0] - 'a'];
        }
    }

    cout << vars[0] << " " << vars[1] << " " << vars[2] << endl;
    return 0;
}
