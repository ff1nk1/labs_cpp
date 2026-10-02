#include "header.h"
#include <iostream>

int main()
{
    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        String s1, s2;
        std::cout << "Введите s1 и s2 через пробел: ";
        std::cin >> s1 >> s2;
        std::cout << "\n=== 1. АРИФМЕТИКА (String и const char*) ===\n";
        std::cout << "s1 + s2: " << (s1 + s2) << " | s1 - s2: " << (s1 - s2) << '\n';
        std::cout << "s1 + \"abc\": " << (s1 + "abc") << " | \"abc\" + s1: " << ("abc" + s1) << '\n';
        std::cout << "s2 - \"abc\": " << (s2 - "abc") << " | \"abc\" - s2: " << ("abc" - s2) << '\n';
        std::cout << "\n=== 2. СРАВНЕНИЯ ===\n";
        std::cout << "s1 == s2: " << (s1 == s2) << " | s1 > s2: "  << (s1 > s2)  << " | s1 < s2: "  << (s1 < s2)  << '\n';
        std::cout << "s1 >= s2: " << (s1 >= s2) << " | s1 <= s2: " << (s1 <= s2) << '\n';

        std::cout << "\n=== 3. ИНДЕКСАЦИЯ, СРЕЗЫ И ИНКРЕМЕНТЫ ===\n";
        std::cout << "s1[0]: " << s1[0] << " | Срез s1(0, 2): " << s1(0, 2) << '\n';

        String temp = s1;
        std::cout << "++temp: " << ++temp << " | temp++: " << temp++ << " (стало: " << temp << ")\n";
        std::cout << "--temp: " << --temp << " | temp--: " << temp-- << " (стало: " << temp << ")\n";

        std::cout << "\n=== 4. СОСТАВНОЕ ПРИСВАИВАНИЕ (+= / -=) ===\n";
        String s_acc = s1;
        s_acc += s2;
        std::cout << "s1 += s2 -> " << s_acc << '\n';
        s_acc -= s2;
        std::cout << "результат -= s2 -> " << s_acc << '\n';

        std::cout << "\nПовторить? (y/n): ";
        std::cin >> again;
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Программа завершена.\n";
    return 0;
}