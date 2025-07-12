#include <iostream>
#include <string>
#include <limits>
// �������� ����������
void numberSaveAndCheck(double& a, double& b) {
	while (true) {
		std::cout << std::endl << "������� ������ �����: ";
		if (!(std::cin >> a)) {
			std::cerr << std::endl << "������, �� ����� �� ����� ��� ������� ������� �����" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::cout << "������� ������ �����: ";
		if (!(std::cin >> b)) {
			std::cerr << std::endl << "������, �� ����� �� ����� ��� ������� ������� �����" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
}
// �������������� �������
double result(double a, double b, char c) {
	switch (c) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
	return 0;
}
// ��� �����������
int main() {
	setlocale(LC_ALL, "RU");
	while (true) {
		short d;
		std::cout << std::endl << "������� 1 ��� 2" << std::endl << "1 - ����������" << std::endl << "2 - �����" << std::endl;
		if (!(std::cin >> d)) {
			std::cerr << std::endl << "������, �� ����� �� ����� ��� ������� ������� �����" << std::endl;
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
				std::cout << std::endl << "������� 1 ��� 2" << std::endl << "1 - ����������" << std::endl << "2 - �����" << std::endl;
				if (!(std::cin >> e)) {
					std::cerr << std::endl << "������, �� ����� �� ����� ��� ������� ������� �����" << std::endl;
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
		std::cout << std::endl << "������ ��������� ����������: " << std::endl << "+ - ����" << std::endl << "- - �����" << std::endl << "* - ���������" << std::endl << "/ - �������" << std::endl;
		std::string input;
		std::cin >> input;

		while (true) {
			if (input.length() != 1) {
				std::cout << "������, �������� �� ����� ��������� ������ ������ �������!" << std::endl;
				std::cout << std::endl << "������ ��������� ����������: " << std::endl << "+ - ����" << std::endl << "- - �����" << std::endl << "* - ���������" << std::endl << "/ - �������" << std::endl;
				std::cin >> input;
			}

			if (input != "+" && input != "-" && input != "*" && input != "/") {
				std::cout << "������, ���������������� ��������!" << std::endl;
				std::cout << std::endl << "������ ��������� ����������: " << std::endl << "+ - ����" << std::endl << "- - �����" << std::endl << "* - ���������" << std::endl << "/ - �������" << std::endl;
				std::cin >> input;
			}

			if (input.length() == 1 && (input == "+" || input == "-" || input == "*" || input == "/")) {
				c = input[0];
				break;
			}
		}
		if (b == 0 && c == '/') {
			while (true) {
				std::cout << std::endl << "������ ������ �� 0 ������" << std::endl;
				std::cout << "������� ������ �����: ";
				std::cin >> b;
				if (b != 0) {
					break;
				}
			}
		}

		double r = result(a, b, c);

		std::cout << "���������: " << r << std::endl;
	}
	return 0;
}