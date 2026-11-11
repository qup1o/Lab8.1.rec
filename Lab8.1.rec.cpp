// Lab 8.1 (recursive)
// Пошук та заміна символів у літерному рядку
// Варіант 28

// Дано літерний рядок, який містить послідовність символів
// s[0], ..., s[n], ...
// 1.   Вияснити, чи є серед цих символів всі букви,
//      що входять в слово "while".
// 2.   Замінити кожну групу букв "while" парою зірочок "**".

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)   // для підключення з unit-тесту (pch.h)
#include <iostream>
#include <cstring>

using namespace std;

bool IsLetterPresent(const char* str, const char letter, int i);
bool IsAllLettersPresent(const char* str, const char* letters, int k);
bool IsWhileAt(const char* str, const int pos);
char* Change(char* dest, const char* str, char* t, int i);

int main()
{
    const char letters[] = "while";   // букви для перевірки

    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (IsAllLettersPresent(str, letters, 0))
        cout << "All letters of \"while\" are present" << endl;
    else
        cout << "Not all letters of \"while\" are present" << endl;

    char* dest1 = new char[strlen(str) + 1];
    dest1[0] = '\0';

    char* dest2;

    dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;

    return 0;
}

// чи є в рядку str символ letter (рекурсивне сканування від позиції i)
bool IsLetterPresent(const char* str, const char letter, int i)
{
    if (str[i] == '\0')
        return false;

    if (str[i] == letter)
        return true;

    return IsLetterPresent(str, letter, i + 1);
}

// чи є в рядку str усі символи з рядка letters
// (рекурсія по k-му символу рядка letters)
bool IsAllLettersPresent(const char* str, const char* letters, int k)
{
    if (letters[k] == '\0')
        return true;

    if (!IsLetterPresent(str, letters[k], 0))
        return false;

    return IsAllLettersPresent(str, letters, k + 1);
}

// чи починається в позиції pos рядка str група букв "while"
bool IsWhileAt(const char* str, const int pos)
{
    return str[pos] == 'w'
        && str[pos + 1] == 'h'
        && str[pos + 2] == 'i'
        && str[pos + 3] == 'l'
        && str[pos + 4] == 'e';
}

// заміна кожної групи букв "while" парою зірочок "**":
// str - вхідний рядок, i - поточна позиція в str,
// t - поточна позиція запису в dest; повертає вказівник на початок dest
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] == '\0')
    {
        *t = '\0';
        return dest;
    }

    if (IsWhileAt(str, i))
    {
        *t++ = '*';
        *t++ = '*';
        return Change(dest, str, t, i + 5);
    }

    *t++ = str[i];
    return Change(dest, str, t, i + 1);
}
