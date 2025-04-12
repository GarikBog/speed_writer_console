#include<iostream>
#include<string>
#include<time.h>
#include<windows.h>

#define MATH_OPERATIONS "+-*/()%="
#define PUNCTUATION ".,:;`'!?"
#define OTHER " @#$^&_{}[]|\<>~"



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
	std::string str = "";

	//std::cout << "CREATING STRING " << (int)size << '\n';
	

	uint8_t  remaind = size;

	if (include_smallLetters) {
		int8_t smallLetters = rand() % remaind;

		//std::cout << "Add " << (int)smallLetters << " small letters \n";

		for (int i = 0; i < smallLetters; ++i) {
			str += (char)(97 + rand() % 26);
		}

		remaind = remaind - smallLetters;
	}


	if (include_bigLetters) {
		int8_t bigLetters = rand() % remaind;

		//std::cout << "Add " << (int)bigLetters << " big letters \n";

		for (int i = 0; i < bigLetters; ++i) {
			str += (char)(65 + rand() % 26);
		}

		remaind = remaind - bigLetters;
	}

	if (include_numbers){
		int8_t numbers = rand() % remaind;

		//std::cout << "Add " << (int)numbers << " numbers \n";


		for (int i = 0; i < numbers; ++i) {
			str += (char)(48 + rand() % 10);
		}

		remaind = remaind - numbers;

	}

	if (include_punctuation) {
		int8_t punctuation = rand() % remaind;

		//std::cout << "Add " << (int)punctuation << " punctuation \n";

		for (int i = 0; i < punctuation; ++i) {
			str += PUNCTUATION[rand() % 9];
		}

		remaind = remaind - punctuation;

	}


	if (include_mathOperations) {
		int8_t mathOperations = rand() % remaind;

		//std::cout << "Add " << (int)mathOperations << " mathOperations \n";


		for (int i = 0; i < mathOperations; ++i) {
			str += MATH_OPERATIONS[rand() % 9];
		}
		remaind = remaind - mathOperations;

	}

	if (include_other) {
		int8_t other = remaind;

		//std::cout << "Add " << (int)other << " other \n";


		for (int i = 0; i < other; ++i) {
			str += OTHER[rand() % 16];
		}

		remaind = remaind - other;

	}

	for (int i = 0; i < remaind; ++i) {
		str += ' ';
		
	}

	Peremeshka(str);
	
	return str;
}

int main() {

	bool run = true;
	int level = 0;
	std::string text,player_text;
	while (run && ++level) {
		text = CreateString(level, true, true, true, true, true, true);

		std::cout<< "\n\n\t" << " Write" << "\n";
		std::cout << "\n\t" << text;
		std::cout << "\n\nYour text: ";
		clock_t start_time = clock();
		std::cin >> player_text;
		clock_t end_time = clock();


		if (player_text != text) {
			std::cout << "\n\t YOU LOSE!";
			run = false;
		}else {
			std::cout<<"\n\n\t Right!";
			double delta_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
			std::cout << "\n\t It took you: " << delta_time << " seconds!";
			Sleep(2000);
			std::cout << "\n\n\t Ready for next? (1/0): ";
			bool answer;
			std::cin >> answer;
			if (!answer) {
				run = false;
			}
			else {
				for (int i = 1; i < 4; ++i) {
					Sleep(1000);
					std::cout <<  4-i << ' ';
				}
			}
		}


	}





	return 0;
}
