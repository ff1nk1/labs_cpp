#include "header.h"


String::String(int length) : length(length)                 // Конструктор по умолчанию
{
    string = new char[length + 1];
    string[length] = '\0';
}

String::String(const String& other) : String(other.length)  // Конструктор копирования
{   
    std::strcpy(this->string, other.string);
}

String::String(const char* str)                             // Конструктор с параметром
{
    length = std::strlen(str);
    string = new char[length + 1];
    
    std::strcpy(this->string, str);
}

std::ostream& operator<<(std::ostream& os, const String& s) // Перегрузка вывода
{
    if (s.string) 
    {
        os << s.string;
    }
    return os;
}

std::istream& operator>>(std::istream& is, String& s)       // Перегрузка ввода
{
    char temp[4096];
    if (is >> temp) 
    {
        delete[] s.string;
        s.length = std::strlen(temp);
        s.string = new char[s.length + 1];
        std::strcpy(s.string, temp);
    }
    return is;
}

String String::add_string(const String& s2) const              // Добавление строки
{
    String res = String(this->length + s2.length);
    
    std::strcpy(res.string, this->string);
    std::strcat(res.string, s2.string);
    
    return res;
}

String String::operator +(const String& s2) const             // Оператор сложения
{
    return add_string(s2);
}

const String& String::operator =(const String& other)        // Оператор присваивания
{
    if(this == &other)
    {
        return *this;
    }

    length = other.length;
    delete[] string;
    
    string = new char[length + 1];
    
    std::strcpy(this->string, other.string);
    
    return *this; 
}

String String::operator -(const String& s2)                 // Оператор вычитания
{
    size_t min_len = (this->length < s2.length) ? this->length : s2.length;
    char* new_str = new char[this->length + 1];

    for (size_t i = 0; i < min_len; ++i)
    {
        char c1 = this->string[i];
        char c2 = s2.string[i];

        if (c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z') {
            int diff = c1 - c2;
            if (diff < 0) diff += 26;
            new_str[i] = 'a' + diff;
        }
        else if (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z') {
            int diff = c1 - c2;
            if (diff < 0) diff += 26;
            new_str[i] = 'A' + diff;
        }
        else if (c1 >= '0' && c1 <= '9' && c2 >= '0' && c2 <= '9') {
            int diff = c1 - c2;
            if (diff < 0) diff += 10;
            new_str[i] = '0' + diff;
        }
        else {
            new_str[i] = c1;
        }
    }

    for (size_t i = min_len; i < this->length; ++i)
    {
        new_str[i] = this->string[i];
    }

    new_str[this->length] = '\0';

    String res(new_str);
    delete[] new_str;
    return res;
}

String& String::operator -=(const String& s2)               // Вычитание с присваиванием
{
    *this = *this - s2;
    return *this;
}

String& String::operator +=(const String& s2)               // Сложение с присваиванием
{
    *this = *this + s2;
    return *this;
}

bool String::operator ==(const String& s2) const           // Оператор равенства
{
    if (this->length != s2.length) {
        return false;
    }
    return std::strcmp(this->string, s2.string) == 0;
}

bool String::operator >(const String& s2) const            // Оператор больше
{
    return std::strcmp(this->string, s2.string) > 0;
}

bool String::operator <(const String& s2) const            // Оператор меньше
{
    return std::strcmp(this->string, s2.string) < 0;
}

bool String::operator <=(const String& s2) const           // Оператор меньше или равно
{
    return std::strcmp(this->string, s2.string) <= 0;
}

bool String::operator >=(const String& s2) const           // Оператор больше или равно
{
    return std::strcmp(this->string, s2.string) >= 0;
}

String& String::operator++()                                // Префиксный инкремент
{
    for (size_t i = 0; i < this->length; ++i)
    {
        char c = this->string[i];
        if (c >= 'a' && c <= 'z')      this->string[i] = (c == 'z') ? 'a' : c + 1;
        else if (c >= 'A' && c <= 'Z') this->string[i] = (c == 'Z') ? 'A' : c + 1;
        else if (c >= '0' && c <= '9') this->string[i] = (c == '9') ? '0' : c + 1;
    }
    return *this;
}

String String::operator++(int)                             // Постфиксный инкремент
{
    String temp(*this);
    ++(*this);
    return temp;
}

String& String::operator--()                                // Префиксный декремент
{
    for (size_t i = 0; i < this->length; ++i)
    {
        char c = this->string[i];
        if (c >= 'a' && c <= 'z')      this->string[i] = (c == 'a') ? 'z' : c - 1;
        else if (c >= 'A' && c <= 'Z') this->string[i] = (c == 'A') ? 'Z' : c - 1;
        else if (c >= '0' && c <= '9') this->string[i] = (c == '0') ? '9' : c - 1;
    }
    return *this;
}

String String::operator--(int)                             // Постфиксный декремент
{
    String temp(*this);
    --(*this);
    return temp;
}

char String::operator [](int index)                         // Оператор индексации
{
    if(index >= 0 && index < this->length)
        return this->string[index];
    return '\0';
}

String String::operator()(int start, int end) const        // Функция вырезки подстроки
{
    if (start < 0) start = 0;
    if (end >= length) end = length - 1;
    if (start > end) return String("");

    int sub_len = end - start + 1;
    char* new_str = new char[sub_len + 1];

    for (int i = 0; i < sub_len; ++i)
    {
        new_str[i] = this->string[start + i];
    }
    new_str[sub_len] = '\0';

    String res(new_str);
    delete[] new_str;
    return res;
}
    
String String::operator +(const char* s2) const                // String + char*

{
    return add_string(String(s2));                             // Явное создание String
}

String operator +(const char* s1, const String& s2)             // char* + String

{
    return String(s1) + s2;                                     // Явное создание String
}

String String::operator -(const char* s2) const                 // String - char*

{
    String temp(*this);
    return temp - String(s2);                                   // Явное создание String
}

String operator -(const char* s1, const String& s2)             // char* - String

{
    return String(s1) - s2;                                     // Явное создание String
}

String::~String()                                               // Деструктор
{
    delete[] string;
}