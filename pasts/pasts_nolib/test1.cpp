#include<iostream>
#include<windows.h>
using namespace std;

string* arr;
int arrSize = 0;

int getWord(string line){
    int count = 0;
    bool inWord = false;

    for (char ch : line) {
        if (ch != ' ') {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    return count;
}

void CreateArray(string line){
    arrSize = getWord(line);
    arr = new string[arrSize];

    string word = "";
    int index = 0;

    for (char ch : line) {
        if (ch != ' ') {
            word += ch;
        } else {
            if (!word.empty()) {
                arr[index++] = word;
                word = "";
            }
        }
    }

    if (!word.empty()) {
        arr[index++] = word;
    }
}

int main(){
    SetConsoleOutputCP(65001);

    string s = "MANIS11 JANIS!@#$%^&*()";

    CreateArray(s);

    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << endl;
    }

    delete[] arr;
}
