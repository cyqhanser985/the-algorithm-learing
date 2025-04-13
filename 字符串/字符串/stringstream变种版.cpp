#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    int vars[3] = {0};

    char input_copy[256];
    strcpy(input_copy, input.c_str());

    char *token = strtok(input_copy, ";");
    while (token != nullptr) {
        if (strlen(token) == 0) {
            token = strtok(nullptr, ";");
            continue;
        }

        stringstream ss(token);
        string left, op, right;
        ss >> left >> op >> right;

        if (op != ":=" || left.length() != 1 || left[0] < 'a' || left[0] > 'c') {
            token = strtok(nullptr, ";");
            continue;
        }

        int var_index = left[0] - 'a';
        if (right.length() == 1 && isdigit(right[0])) {
            vars[var_index] = right[0] - '0';
        } else if (right.length() == 1 && right[0] >= 'a' && right[0] <= 'c') {
            vars[var_index] = vars[right[0] - 'a'];
        }

        token = strtok(nullptr, ";");
    }

    cout << vars[0] << " " << vars[1] << " " << vars[2] << endl;
    return 0;
}
