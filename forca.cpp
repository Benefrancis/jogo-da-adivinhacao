#include<iostream>
#include<string>
#include <map>
#include <vector>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

map<char, bool> chutou;

vector<char> erros;

void cabecalho();

void chutes_errados();

void imprime_palavra();

void chute();

void placar();

bool enforcou();

bool acertou();

bool existe(char l);


int main() {

    cabecalho();


    while (!enforcou() && !acertou()) {

        imprime_palavra();

        chutes_errados();

        chute();

    }


    placar();

}

void placar() {
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;

    if (!acertou()) {
        cout << "Voce perdeu! Tente novamente!" << endl;
    } else {
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;
    }
}

void chute() {
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

void imprime_palavra() {
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
}

void chutes_errados() {
    cout << endl;


    cout << "Chutes errados: ";
    for (char e: erros) {
        cout << e << " ";
    }
    cout << endl;
}

void cabecalho() {
    cout << "*****************" << endl;
    cout << "* JOGO DA FORCA *" << endl;
    cout << "*****************" << endl;
}

bool existe(char chute) {

    for (char c: PALAVRA_SECRETA) {
        if (chute == c) {
            return true;
        }
    }
    return false;
}

bool acertou() {
    for (char l: PALAVRA_SECRETA) {
        if (!chutou[l]) {
            return false;
        }
    }
    return true;
}


bool enforcou() {
    return erros.size() >= 4;
}
