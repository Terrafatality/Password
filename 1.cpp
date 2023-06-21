#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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
    void passGenerator(int passLenght)
    {
        password = new char[passLenght];

        for (int i = 0; i < numOfNumbers; ++i) {
            password[i] = char(48 + rand() % 10);
        }
        for (int i = numOfNumbers; i < numOfNumbers + numOfBigChars; ++i) {
            password[i] = char(65 + rand() % 26);
        }
        for (int i = numOfNumbers + numOfBigChars; i < passLenght; ++i) {
            password[i] = char(97 + rand() % 26);
        }
        std::random_shuffle(password, password + passLenght);

    }
    void numOfChars(int passLenght)
    {
        int charRandEnd = passLenght - numOfSmallChars;


        numOfSmallChars = rand() % passLenght;


        numOfBigChars = rand() % charRandEnd;

        numOfNumbers = passLenght - numOfSmallChars - numOfBigChars;
    }
    void SetNumOfBigChars(int num)
    {
        this->numOfBigChars = num;
    }
public:
    int numOfSmallChars;
    int numOfBigChars;
    int numOfNumbers;
    char* password;
};

int main(int argc, char* argv[])
{
    string parameter1;// разобраться с параметрами
    const char upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowerChars = "abcdefghijklmnopqrstuvwxyz";
    const char numberChars = "0123456789";
    const char symbols = "!#$%&()*+,-./|\\\"':;<=>?@[]^_`{}~";
    int count;
    PasswordGenerator* password = new PasswordGenerator();
    string sprav[4] = { "-u указывает количество заглавных букв\n","-l указывает количество строчных букв\n", "- n указывает количество цифр\n","-s указывает количество спецсимволов\n" };
    printf("pwgen: \n");
    scanf("s", &parameter1); //создать строку 
    for (count = 0; count < 1; count++) {
        if (parameter1 = upperChars) {
            // создать условия для внесения в строку
            printf("uno");
        }
        else if (parameter1 = lowerChars) {


        }

        else if (parameter1 = numberChars) {


        }
        else if (parameter1 = symbols) {


        }
        else {
            char* result = password->generate(2, 2, 2, 2);
            cout << result << endl;
        }
    }
}
