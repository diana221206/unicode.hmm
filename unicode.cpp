#include <iostream>
#include <tchar.h>
#include <cstring>

bool isPalindrome(const TCHAR* str) {
    int len = _tcslen(str);
    for (int i = 0; i < len / 2; ++i)
        if (str[i] != str[len - 1 - i]) return false;
    return true;
}

int countWords(const TCHAR* str) {
    int count = 0;
    bool inWord = false;
    for (int i = 0; i < _tcslen(str); ++i) {
        if (_istspace(str[i])) inWord = false;
        else if (!inWord) { count++; inWord = true; }
    }
    return count;
}

void replaceString(TCHAR* text, const TCHAR* search, const TCHAR* replace) {
    TCHAR* pos = _tcsstr(text, search);
    if (!pos) return;
    TCHAR newText[256]; 
    _tcsncpy(newText, text, pos - text);
    newText[pos - text] = '0';
    _stprintf(newText + (pos - text), _T("%s%s"), replace, pos + _tcslen(search));
    _tcscpy(text, newText);
}

int main() {
    TCHAR input[256], search[256], replace[256];

    std::wcout << _T("Введите строку: ");
    std::wcin.getline(input, 256);

    std::wcout << (isPalindrome(input) ? _T("Строка является палиндромом.\n") : _T("Строка не является палиндромом.\n"));
    std::wcout << _T("Количество слов в строке: ") << countWords(input) << _T("\n");

    std::wcout << _T("Введите строку для поиска: ");
    std::wcin.getline(search, 256);

    std::wcout << _T("Введите строку для замены: ");
    std::wcin.getline(replace, 256);

    replaceString(input, search, replace);
    std::wcout << _T("Измененный текст: ") << input << _T("\n");

    return 0;
}
