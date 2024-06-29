#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

int main() {
   setlocale(LC_ALL, "RUSSIAN");
   ifstream inputFile("input2.txt");
   ofstream outputFile("output2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "ошибка открытия файла" <<endl;
        return 1;
    }

    regex passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d_]{8,}$");
       /* ^ -начало строки
         (? = .*[a - z]) - хотя бы одна строчная буква
         (? = .*[A - Z]) - хотя бы одна заглавная буква
         (? = .*\\d) - хотя бы одна цифра
         [a - zA - Z\\d_]{8, } - только буквы(как строчные, так и заглавные), цифры и символ подчеркивания, длиной не менее 8 символов
         $ - конец строки */
    //?=.*[a-z]

    string line; 
    while (getline(inputFile, line)) {
        if (regex_match(line, passwordRegex)) {
            outputFile << line << " - пароль надёжный" << endl;
        }
        else {
            outputFile << line << " - пароль не надёжный." << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
