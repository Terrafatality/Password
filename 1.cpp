#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
static const char AlphaNumeric[] = "0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"!@#$%^&*()_+№;%:?*-=/.,<>{}[]";
int MyLen = sizeof(AlphaNumeric);
char RandomStr() {
    return AlphaNumeric[rand() % MyLen];
}
class PasswordGenerator
{
private:
    const char* upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* lowerChars = "abcdefghijklmnopqrstuvwxyz";
    const char* numberChars = "0123456789";
    const char* symbols = "!#$%&()*+,-./|\\\"':;<=>?@[]^_`{}~";
public:
    char* generate(int upperCharsLength, int lowerCharsLength, int numberCharsLength, int symbol)
    {
        srand(time(NULL)); // Инициализация rand(), иначе будет генерировать одно и то же
        int length = upperCharsLength + lowerCharsLength + numberCharsLength;
        char* password = new char[length];
        password[0] = '\0';
        char* randomUpperChars = this->randomString(this->upperChars, upperCharsLength);
        char* randomLowerChars = this->randomString(this->lowerChars, lowerCharsLength);
        char* randomNumberChars = this->randomString(this->numberChars, numberCharsLength);
        char* randomsymbols = this->randomString(this->symbols, symbol);
        strcat(password, randomUpperChars);
        strcat(password, randomLowerChars);
        strcat(password, randomNumberChars);
        strcat(password, randomsymbols);
        random_shuffle(password, password + strlen(password));
        return password;
    }
private:
    char* randomString(const char* str, int length)
    {
        char* result = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            result[i] = this->randomStringChar(str);
        }
        result[length] = '\0';
        return result;
    }
    char randomStringChar(const char* str)
    {
        int length = strlen(str);
        return str[rand() % length];
    }
    static void showHelp(bool isError) {
        string help = " Usage:/n/t java Pg[{-h, --help, / ? }][length][option value] .../n /t'-h' or '--help' or '/?' shows this help./n /t'length' is the length of the password, if 'length' < 4 it assumes to be 4./n /tAvailable options :/n /t-u determines quantity of uppercase letters in password./n/t- l determines quantity of lowercase letters in password./n/t - n determines quantity of numbers in password. / n/t- s determines quantity of special symbols letters in password./n/tThe default charset in password is lowercase symbols./n/tIf 'length' < u + n + s + l then 'length' assumed to be u + n + s + l./n/tIf Pg invoked without any arguments it assumes 'Pg 8 -u 2 -n 2 -s 2'./n";
        printf(isError ? ("Invalid usage!\n" + help) : help);
    }
public:
    int numOfSmallChars;
    int numOfBigChars;
    int numOfNumbers;
    char* password;
};
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    string parameter1;// разобраться с параметрами(если будут)
    int count;
    int a = 0;
    PasswordGenerator* password = new PasswordGenerator();
    string sprav[4] = { "-u указывает количество заглавных букв\n","-l указывает количество строчных букв\n", "- n указывает количество цифр\n","-s указывает количество спецсимволов\n" };
    do {
        cin >> parameter1;
        cout << "\n";
        string argVal = argv[a];
        for (count = 0; count < 1; count++) {

            if (a == 0) {
                switch (a) {
                case '- h':;
                case '- help':;
                case '/?':
                case '- u': parameter1 = 1;
                case '- n': parameter1 = 2;
                case '- s': parameter1 = 3;
                case '- l': parameter1 = 4;
                    default -> {
                        try {
                            len = Integer.parseInt(argVal);
                        }
                        catch (NumberFormatException e) {
                            showHelp(true);
                        }
                    }
                }
                if (parameter1 == "-h" || parameter1 == "-help") {
                    for (int i = 0; i < 4; i++) {
                        cout << "" << sprav[i] << endl;
                    }
                }
                if (parameter1 == "-u")
                {
                    int N = 8;
                    char str[]{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
                    int strN = 30; // индекс последнего элемента в массиве
                    srand(time(0)); //инициализируем генератор случайных чисел
                    char* pass = new char[N + 1]; //выделяем память для строки пароля
                    for (int i = 0; i < N; i++)
                    {
                        pass[i] = str[rand() % strN]; //вставляем случайный символ
                    }
                    pass[N] = 0; //записываем в конец строки признак конца строки
                    cout << pass; //выводим пароль на экран
                    cout << "\n";
                }
                if (parameter1 == "-s") {
                    int N = 8;
                    char str[]{ "!#$%&()*+,-./|\\\"':;<=>?@[]^_`{}~" };
                    int strN = 35; // индекс последнего элемента в массиве
                    srand(time(0)); //инициализируем генератор случайных чисел
                    char* pass = new char[N + 1]; //выделяем память для строки пароля
                    for (int i = 0; i < N; i++)
                    {
                        pass[i] = str[rand() % strN]; //вставляем случайный символ
                    }
                    pass[N] = 0; //записываем в конец строки признак конца строки
                    cout << pass; //выводим пароль на экран
                    cout << "\n";
                }
                if (parameter1 == "-n")
                {
                    int N = 8;
                    char str[]{ "0123456789" };
                    int strN = 11; // индекс последнего элемента в массиве
                    srand(time(0)); //инициализируем генератор случайных чисел
                    char* pass = new char[N + 1]; //выделяем память для строки пароля
                    for (int i = 0; i < N; i++)
                    {
                        pass[i] = str[rand() % strN]; //вставляем случайный символ
                    }
                    pass[N] = 0; //записываем в конец строки признак конца строки
                    cout << pass; //выводим пароль на экран
                    cout << "\n";
                }
                if (parameter1 == "-l")
                {
                    int N = 8;
                    char str[]{ "abcdefghijklmnopqrstuvwxyz" };
                    int strN = 27; // индекс последнего элемента в массиве
                    srand(time(0)); //инициализируем генератор случайных чисел
                    char* pass = new char[N + 1]; //выделяем память для строки пароля
                    for (int i = 0; i < N; i++)
                    {
                        pass[i] = str[rand() % strN]; //вставляем случайный символ

                    }
                    pass[N] = 0; //записываем в конец строки признак конца строки
                    cout << pass; //выводим пароль на экран
                    cout << "\n";
                }
                if (sscanf(parameter1.c_str(), "%d", &a));
                if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9)
                {

                    srand(time(0));
                    for (int m = 0; m < a; m++) {
                        cout << RandomStr();
                    }
                    cout << "\n";
                }
                if (sscanf(parameter1.c_str(), "%d", &a));
                else if (a != 0 && a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8 && a != 9 && parameter1 != "exit" && parameter1 != "-h" && parameter1 != "-help" && parameter1 != "-u" && parameter1 != "-s" && parameter1 != "-l" && parameter1 != "-n") {
                    char* result = password->generate(2, 2, 2, 2);
                    cout << result << endl;
                    cout << ("Ошибка ввода, используйте справку\n");
                    for (int i = 0; i < 4; i++) {
                        cout << "" << sprav[i] << endl;
                    }
                }
            }
        }
    } while (parameter1 != "exit");
    cout << ("Выход из программы\n");
}
