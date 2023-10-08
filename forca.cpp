#include<iostream>
#include<string>
#include <map>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

map<char, bool> chutou;


bool existe(char chute) {

    for (char c: PALAVRA_SECRETA) {
        if (chute == c) {
            return true;
        }
    }
    return false;
}


int main() {
   // cout << PALAVRA_SECRETA << endl;
    bool acertou;
    bool enforcou;

    while (!enforcou || !acertou) {

        for (char l: PALAVRA_SECRETA) {
            if (chutou[l]) {
                cout << l << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
        char chute;
        cout << "Chute uma letra: " << endl;
        cin >> chute;

        chutou[chute] = true;

        if (existe(chute)) {
            cout << "O seu chute esta na palavra" << endl;
        } else {
            cout << "O seu chute nao esta na palavra" << endl;
        }
    }
}