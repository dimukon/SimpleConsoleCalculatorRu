#include <iostream>
#include <string>
#include <limits>
// Проверка переменных
void numberSaveAndCheck(double& a, double& b) {
	while (true) {
		std::cout << std::endl << "Введите первое число: ";
		if (!(std::cin >> a)) {
			std::cerr << std::endl << "Ошибка, вы ввели не число или слишком большое число" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::cout << "Введите второе число: ";
		if (!(std::cin >> b)) {
			std::cerr << std::endl << "Ошибка, вы ввели не число или слишком большое число" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
}
// Математические расчеты
double result(double a, double b, char c) {
	switch (c) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
	return 0;
}
// Сам калькулятор
int main() {
	setlocale(LC_ALL, "RU");
	while (true) {
		short d;
		std::cout << std::endl << "Введите 1 или 2" << std::endl << "1 - Продолжить" << std::endl << "2 - Выйти" << std::endl;
		if (!(std::cin >> d)) {
			std::cerr << std::endl << "Ошибка, вы ввели не число или слишком большое число" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (d == 2) {
			return 0;
		}
		if (d != 1 and d != 2) {
			short e;
			while (true) {
				std::cout << std::endl << "Введите 1 или 2" << std::endl << "1 - Продолжить" << std::endl << "2 - Выйти" << std::endl;
				if (!(std::cin >> e)) {
					std::cerr << std::endl << "Ошибка, вы ввели не число или слишком большое число" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}

				if (e == 1) {
					break;
				}
				if (e == 2) {
					return 0;
				}
			}
		}

		double a, b;
		char c;

		numberSaveAndCheck(a, b);
		std::cout << std::endl << "Список доступных операторов: " << std::endl << "+ - Плюс" << std::endl << "- - Минус" << std::endl << "* - Умножение" << std::endl << "/ - Деление" << std::endl;
		std::string input;
		std::cin >> input;

		while (true) {
			if (input.length() != 1) {
				std::cout << "Ошибка, операция не может содержать больше одного символа!" << std::endl;
				std::cout << std::endl << "Список доступных операторов: " << std::endl << "+ - Плюс" << std::endl << "- - Минус" << std::endl << "* - Умножение" << std::endl << "/ - Деление" << std::endl;
				std::cin >> input;
			}

			if (input != "+" && input != "-" && input != "*" && input != "/") {
				std::cout << "Ошибка, неподдерживаемая операция!" << std::endl;
				std::cout << std::endl << "Список доступных операторов: " << std::endl << "+ - Плюс" << std::endl << "- - Минус" << std::endl << "* - Умножение" << std::endl << "/ - Деление" << std::endl;
				std::cin >> input;
			}

			if (input.length() == 1 && (input == "+" || input == "-" || input == "*" || input == "/")) {
				c = input[0];
				break;
			}
		}
		if (b == 0 && c == '/') {
			while (true) {
				std::cout << std::endl << "Ошибка делить на 0 нельзя" << std::endl;
				std::cout << "Введите второе число: ";
				std::cin >> b;
				if (b != 0) {
					break;
				}
			}
		}

		double r = result(a, b, c);

		std::cout << "Результат: " << r << std::endl;
	}
	return 0;
}