/*
求两个超级大的数的和
*/

#include <iostream>
#include <string>

int main()
{
	std::string inputa, inputb;
	std::cin >> inputa >> inputb;

	int len_a = inputa.length();
	int len_b = inputb.length();
	int max_len = std::max(len_a, len_b);
	std::string result(max_len + 1, '0'); // 结果字符串，预留一位进位
	bool if_carry = false; // 是否有进位
	for (int i = 0; i < max_len; ++i)
	{
		int digit_a = (len_a - 1 - i >= 0) ? inputa[len_a - 1 - i] - '0' : 0;
		int digit_b = (len_b - 1 - i >= 0) ? inputb[len_b - 1 - i] - '0' : 0;
		int sum = digit_a + digit_b + (if_carry ? 1 : 0);
		if_carry = sum >= 10;
		result[max_len - i] = (sum % 10) + '0'; //s 存储当前位的结果
	}
	if (if_carry)
	{
		result[0] = '1'; // 如果最后有进位，设置最高位
		std::cout << result << std::endl;
	}
	else
	{
		std::cout << result.substr(1) << std::endl; // 输出结果，去掉最高位的 '0'
	}
	return 0;

}