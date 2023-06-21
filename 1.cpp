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
    setlocale(LC_ALL, "Russian");
    bool str = true;
    string parameter1;// разобраться с параметрами(если будут)
    string upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowerChars = "abcdefghijklmnopqrstuvwxyz";
    string numberChars = "0123456789";
    string symbols = "!#$%&()*+,-./|\\\"':;<=>?@[]^_`{}~";
    int count;
    PasswordGenerator* password = new PasswordGenerator();
    string sprav[4] = { "-u указывает количество заглавных букв\n","-l указывает количество строчных букв\n", "- n указывает количество цифр\n","-s указывает количество спецсимволов\n" };
    do {
        cout << "pwgen: ";
        cin >> parameter1;
        cout << "\n";
        for (count = 0; count < 1; count++) {
            if (parameter1 == "-h" || parameter1 == "-help") {

                for (int i = 0; i < 4; i++) {
                    cout << "" << sprav[i] << endl;
                }

            }
            if (str = false) {
                // создать условия для внесения в строку



                return str;
            }
            else if (parameter1 != "-h" && parameter1 != "-help" && parameter1 != "-u" && parameter1 != "-s" && parameter1 != "-l" && parameter1 != "-n") {
                char* result = password->generate(2, 2, 2, 2);
                cout << result << endl;
                cout << ("Ошибка ввода, используйте справку\n");
                for (int i = 0; i < 4; i++) {
                    cout << "" << sprav[i] << endl;
                }

            }
        }
    } while (parameter1 != "exit");
}
