#include <iostream>
using namespace std;
char* mystrcat(char* str1, const char* str2) {
    char* ptr = str1;
    while (*ptr != '\0') {
        ptr++;
    }
    while (*str2 != '\0') {
        *ptr = *str2;
        ptr++;
        str2++;
    }
    *ptr = '\0';
    return str1;
}

char* mystrchr(char* str, char s) {
    while (*str != '\0') {
        if (*str == s) {
            return str;
        }
        str++;
    }
    return nullptr;
}

const char* mystrstr(const char* str1, const char* str2) {
    if (*str2 == '\0') {
        return str1;
    }
    while (*str1 != '\0') {
        const char* ptr1 = str1;
        const char* ptr2 = str2;
        while (*ptr1 == *ptr2 && *ptr2 != '\0') {
            ptr1++;
            ptr2++;
        }
        if (*ptr2 == '\0') {
            return str1;
        }
        str1++;
    }
    return nullptr;
}

int main() {
    char buffer1[50] = "Hello, ";
    const char* str_to_add = "world!";
    char* result_cat = mystrcat(buffer1, str_to_add);
    cout << "Result of mystrcat: " << result_cat << endl;

    char str_to_search_char[] = "programming";
    char char_to_find = 'g';
    char* result_chr = mystrchr(str_to_search_char, char_to_find);
    if (result_chr != nullptr) {
        cout << "Character '" << char_to_find << "' found in: " << str_to_search_char << ", starting from position: " << result_chr - str_to_search_char << endl;
    }
    else {
        cout << "Character '" << char_to_find << "' not found in: " << str_to_search_char << endl;
    }

    char char_to_find_not_present = 'z';
    result_chr = mystrchr(str_to_search_char, char_to_find_not_present);
    if (result_chr != nullptr) {
        cout << "Character '" << char_to_find_not_present << "' found in: " << str_to_search_char << endl;
    }
    else {
        cout << "Character '" << char_to_find_not_present << "' not found in: " << str_to_search_char << endl;
    }

    char str_to_search_str[] = "This is a simple string";
    const char* str_to_find_sub = "simple";
    const char* str_to_find_sub_not_present = "complex";

    const char* result_str = mystrstr(str_to_search_str, str_to_find_sub);
    if (result_str != nullptr) {
        cout << "Substring '" << str_to_find_sub << "' found in: " << str_to_search_str << ", starting from position: " << result_str - str_to_search_str << endl;
    }
    else {
        cout << "Substring '" << str_to_find_sub << "' not found in: " << str_to_search_str << endl;
    }

    result_str = mystrstr(str_to_search_str, str_to_find_sub_not_present);
    if (result_str != nullptr) {
        cout << "Substring '" << str_to_find_sub_not_present << "' found in: " << str_to_search_str << endl;
    }
    else {
        cout << "Substring '" << str_to_find_sub_not_present << "' not found in: " << str_to_search_str << endl;
    }

    return 0;
}
