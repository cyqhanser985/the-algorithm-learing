#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string input;
    getline(cin, input); // 读取整行输入
    int vars[3] = {0};   // vars[0] = a, vars[1] = b, vars[2] = c，初始值为 0

    stringstream ss(input);
    string statement;
    while (getline(ss, statement, ';')) {
        if (statement.empty()) continue; // 跳过空语句

        size_t pos = statement.find(":=");
        if (pos == string::npos) continue; // 无效语句

        // 提取左边变量和右边值，并去除空格
        string left = statement.substr(0, pos);
        string right = statement.substr(pos + 2);
        left = left.substr(left.find_first_not_of(" \t"), left.find_last_not_of(" \t") + 1 - left.find_first_not_of(" \t"));
        right = right.substr(right.find_first_not_of(" \t"), right.find_last_not_of(" \t") + 1 - right.find_first_not_of(" \t"));

        // 检查左边是否为有效变量
        if (left.length() != 1 || left[0] < 'a' || left[0] > 'c') continue;
        int var_index = left[0] - 'a';

        // 判断右边是数字还是变量
        if (right.length() == 1 && isdigit(right[0])) {
            vars[var_index] = right[0] - '0';
        } else if (right.length() == 1 && right[0] >= 'a' && right[0] <= 'c') {
            vars[var_index] = vars[right[0] - 'a'];
        }
    }

    cout << vars[0] << " " << vars[1] << " " << vars[2] << endl;
    return 0;
}
