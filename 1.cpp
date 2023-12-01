#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <algorithm>

using namespace std;

int firstNumber(string s) {
    int n = 0;
    for (char& c : s) {
        if (isdigit(c)) {
            n = (int) c - 48;
            break;
        }
    }
    return n;
}

int lastNumber(string s) {
    reverse(s.begin(), s.end());
    int n = 0;
    for (char& c : s) {
        if (isdigit(c)) {
            n = (int) c - 48;
            break;
        }
    }
    return n;
}

int lineNumber(string s) {
    return 10 * firstNumber(s) + lastNumber(s);
}

int main() {
    string line = "";
    int sum = 0;
    ifstream file ("1");
    if (file.is_open()) {
        while (getline(file, line)) {
            sum += lineNumber(line);
        }
    file.close();
    }
    cout << sum << "\n";
    return 0;
}