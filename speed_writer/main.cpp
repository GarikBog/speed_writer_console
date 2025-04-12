#include<iostream>
#include<string>

#define MATH_OPERATIONS "+-*/()%="
#define PUNCTUATION " .,:;`'!?"
#define OTHER "@#$^&_{}[]|\<>~"



// 97 - a
// 122 - z

// 65 - A
// 90 - Z

// 48 - 0
// 57 - 9


// ALL 33 - 126

void Peremeshka(std::string& str) {
	for (int i = 0; i < str.size(); ++i) {
		std::swap(str[i], str[rand() % str.size()]);
	}
}

std::string CreateString(uint8_t size,
	bool include_smallLetters = true,
	bool include_bigLetters = false,
	bool include_numbers = false,
	bool include_punctuation = false,
	bool include_mathOperations = false,
	bool include_other = false)

{
	std::string str;


	

	uint8_t  remaind = size;

	if (include_smallLetters) {
		int8_t smallLetters = rand() % remaind;

		for (int i = 0; i < smallLetters; ++i) {
			str += (char)(97 + rand() % 26);
		}

		remaind = remaind - smallLetters;
	}


	if (include_bigLetters) {
		int8_t bigLetters = rand() % remaind;

		for (int i = 0; i < bigLetters; ++i) {
			str += (char)(65 + rand() % 26);
		}

		remaind = remaind - bigLetters;
	}

	if (include_numbers){
		int8_t numbers = rand() % remaind;

		for (int i = 0; i < numbers; ++i) {
			str += (char)(48 + rand() % 26);
		}
	}

	if (include_punctuation) {
		int8_t punctuation = rand() % remaind;

		for (int i = 0; i < punctuation; ++i) {
			str += PUNCTUATION[rand() % 10];
		}
	}


	if (include_mathOperations) {
		int8_t mathOperations = rand() % remaind;

		for (int i = 0; i < mathOperations; ++i) {
			str += MATH_OPERATIONS[rand() % 9];
		}
	}

	if (include_other) {
		int8_t other = remaind;

		for (int i = 0; i < other; ++i) {
			str += OTHER[rand() % 16];
		}
	}


	Peremeshka(str);
	
	return str;
}

int main() {

	bool run = true;
	while (run) {

	}





	return 0;
}
