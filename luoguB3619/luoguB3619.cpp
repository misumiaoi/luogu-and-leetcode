/*10 进制转 x 进制*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
	std::string input;
	int base;
	std::cin >> input >> base;
	// 计算输入数的十进制值
	long long decimal_value = 0;
	for (char digit : input) {
		decimal_value = decimal_value * 10 + (digit - '0');
	}
	// 将十进制值转换为指定进制
	std::vector<int> result;
	while (decimal_value > 0) {
		result.push_back(decimal_value % base);
		decimal_value /= base;
	}
	// 输出结果
	if (result.empty()) {
		std::cout << "0";
	} else {
		std::reverse(result.begin(), result.end());
		for (int digit : result) {
			std::cout << digit;
		}
	}

	return 0;
}