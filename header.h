#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <cstring>

class String {
private:
    char* string;
    int length;

public:
    explicit String(int length = 0);                                    // Конструктор по умолчанию (explicit)
    String(const String& other);                                        // Конструктор копирования
    explicit String(const char* str);                                   // Конструктор с параметром (explicit)

    friend std::ostream& operator<<(std::ostream& os, const String& s); // Перегрузка вывода
    friend std::istream& operator>>(std::istream& is, String& s);       // Перегрузка ввода

    String add_string(const String& s2) const;                          // Добавление строки
    String operator +(const String& s2) const;                          // String + String
    String operator +(const char* s2) const;                            // String + char*
    friend String operator +(const char* s1, const String& s2);         // char* + String

    String& operator +=(const String& s2);                              // Сложение с присваиванием
    const String& operator =(const String& other);                      // Оператор присваивания

    String operator -(const String& s2);                                // String - String
    String operator -(const char* s2) const;                            // String - char*
    friend String operator -(const char* s1, const String& s2);         // char* - String

    String& operator -=(const String& s2);                              // Вычитание с присваиванием

    bool operator ==(const String& s2) const;                           // Оператор равенства
    bool operator >(const String& s2) const;                            // Оператор больше
    bool operator >=(const String& s2) const;                           // Оператор больше или равно
    bool operator <(const String& s2) const;                            // Оператор меньше
    bool operator <=(const String& s2) const;                           // Оператор меньше или равно

    String& operator ++();                                              // Префиксный инкремент
    String operator ++(int);                                            // Постфиксный инкремент
    String& operator --();                                              // Префиксный декремент
    String operator --(int);                                            // Постфиксный декремент

    char operator [](int index);                                        // Оператор индексации
    String operator ()(int start, int end) const;                       // Вырезка подстроки

    ~String();                                                          // Деструктор
};

#endif