#include <iostream>
#include <string>

const int ARR_SIZE = 100;

int main()
{
	int answerLength;
	int temp1 = -1;
	int temp2 = -1;
	std::string answer[ARR_SIZE];
	std::string sameLength[2];

	std::cin >> answerLength;

	if (answerLength < 2 || answerLength > 100) {
		std::cout << "impossible";
		return 0;
	}

	for (int i = 0; i < answerLength; i++) {
		std::cin >> answer[i];
	}

	for (int i = 0; i < answerLength; i++) {
		if (i == 0) {
			sameLength[0] = answer[0];
			temp1 = 0;
		}
		else {
			if (sameLength[0].length() == answer[i].length()) {
				sameLength[1] = answer[i];
				temp2 = i;
				break;
			}
			else {
				sameLength[0] = answer[i];
				temp1 = i;
			}
		}
	}
	if (temp1 < 0 || temp2 < 0) {
		std::cout << "impossible";
		return 0;
	}

	for (int j = 0; j < sameLength[0].length(); j++) {
		if (sameLength[0][j] != '1') {
			char c = sameLength[0][j];
			int num = std::atoi(&c);
			num--;
			char const num_char = '0' + num;
			sameLength[1][j] = num_char;
			break;
		}
		else if (sameLength[0][j] == '1') {
			sameLength[1][j] = '1';
		}
	}

	answer[temp1] = sameLength[0];
	answer[temp2] = sameLength[1];

	for (int i = 0; i < answerLength; i++) {
		std::cout << answer[i] + " ";
	}
}
