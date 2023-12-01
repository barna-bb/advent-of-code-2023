#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

int lmao (string s) {
    int n = 0;
    int number = 0;
    switch (s[n])
        {
        case 'o':
            if(s[n+1] == 'n') {
                if(s[n+2] == 'e') {
                    number = 1;
                }
            }
            break;
        case 't':
            switch (s[n+1])
            {
            case 'w':
                if(s[n+2] == 'o') {
                    number = 2;
                }
                break;
            case 'h':
                if(s[n+2] == 'r') {
                    if(s[n+3] == 'e') {
                        if(s[n+4] == 'e') {
                            number = 3;
                        }
                    }
                }
                break;
            
            default:
                break;
            }
            break;
        case 'f':
            switch (s[n+1])
            {
            case 'o':
                if(s[n+2] == 'u') {
                    if(s[n+3] == 'r') {
                        number = 4;
                    }
                }
                break;
            case 'i':
                if(s[n+2] == 'v') {
                    if(s[n+3] == 'e') {
                        number = 5;
                    }
                }
                break;
            
            default:
                break;
            }
            break;
        case 's':
            switch (s[n+1])
            {
            case 'i':
                if(s[n+2] == 'x') {
                    number = 6;
                }
                break;
            case 'e':
                if(s[n+2] == 'v') {
                    if(s[n+3] == 'e') {
                        if(s[n+4] == 'n') {
                            number = 7;
                        }
                    }
                }
                break;
            
            default:
                break;
            }
            break;
        case 'e':
            if(s[n+1] == 'i') {
                if(s[n+2] == 'g') {
                    if(s[n+3] == 'h') {
                        if(s[n+4] == 't') {
                            number = 8;
                        }
                    }
                }
            }
            break;
        case 'n':
            if(s[n+1] == 'i') {
                if(s[n+2] == 'n') {
                    if(s[n+3] == 'e') {
                        number = 9;
                    }
                }
            }
            break;
        
        default:
            break;
    }
    return number;
}


int firstNumber(string s) {
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        if(isdigit(s[i])) {
            n = (int) s[i] - 48;
            break;
        } else {
            if (lmao(s.substr(i, 5)) != 0) {
                n = lmao(s.substr(i, 5));
                break;
            }
        }
    }
    return n;
}

int lastNumber(string s) {
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        if(isdigit(s[i])) {
            n = (int) s[i] - 48;
        } else {
            if (lmao(s.substr(i, 5)) != 0) {
                n = lmao(s.substr(i, 5));
            }
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