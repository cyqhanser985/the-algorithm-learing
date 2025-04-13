#include <iostream>
#include <string>
#include <algorithm>

std::string add_power_of_ten_plus_x(int k, long long x) {
    std::string s1 = "1" + std::string(k, '0');
    std::string s2 = std::to_string(x);
    size_t len = std::max(s1.length(), s2.length());
    
    // 用前导零填充，使两字符串长度相等
    if (s1.length() < len) s1 = std::string(len - s1.length(), '0') + s1;
    if (s2.length() < len) s2 = std::string(len - s2.length(), '0') + s2;
    
    std::string result;
    result.reserve(len + 1); // 预分配空间，避免多次重新分配
    int carry = 0;
    
    // 从最低位到最高位逐位相加
    for (int i = len - 1; i >= 0; --i) {
        int digit1 = s1[i] - '0';
        int digit2 = s2[i] - '0';
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.insert(result.begin(), static_cast<char>('0' + sum % 10));
    }
    
    // 处理剩余进位
    if (carry > 0) {
        result.insert(result.begin(), static_cast<char>('0' + carry));
    }
    
    return result;
}

int main() {
    int k;
    long long x;
    std::cin >> k >> x;
    std::cout << add_power_of_ten_plus_x(k, x) << std::endl;
    return 0;
}
