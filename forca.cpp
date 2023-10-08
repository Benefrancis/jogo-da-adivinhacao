#include<iostream>
#include<string>
#include <map>
#include <vector>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

map<char, bool> chutou;

vector<char> erros;

bool existe(char chute) {

    for (char c: PALAVRA_SECRETA) {
        if (chute == c) {
            return true;
        }
    }
    return false;
}


int main() {



    cout << "*****************" << endl;
    cout << "* JOGO DA FORCA *" << endl;
    cout << "*****************" << endl;


    bool acertou;
    bool enforcou;

    while (!enforcou || !acertou) {

        cout << endl;
        cout << endl;
        for (char l: PALAVRA_SECRETA) {
            if (chutou[l]) {
                cout << l << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
        cout << endl;
        cout << "Chutes errados: ";
        for(char e: erros){
            cout << e <<" ";
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
            //Para inserir um elemento em um vector
            // aprendemos a usar o método push_back
            // que insere o elemento desejado no final da lista armazenada.
            erros.push_back(chute);
        }
        cout << endl;
        cout << endl;

    }
}