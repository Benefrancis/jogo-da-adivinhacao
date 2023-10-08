#include<iostream>
#include<string>
#include <map>
#include <vector>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

string palavra_secreta = "MELANCIA";

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


string sorteia();


/**
  * Lê o arquivo de palavras que serão as palavras utilizadas no jogo
  * @return
  *
  * retorna as palavras
  */
vector<string> ler_arquivo() {

    ifstream arquivo;

    arquivo.open("palavras.txt");

    vector<string> palavras;

    if(arquivo.is_open()) {

        int qtd_palavras;

        arquivo >> qtd_palavras;



        for (int i = 0; i < qtd_palavras; i++) {
            string palavra;
            arquivo >> palavra;

            palavras.push_back(palavra);

            // cout << "Na linha " << i << " : " << palavra << endl;
        }

        arquivo.close();
    } else{
        cout << "Não foi possível acesar o banco de palavras " << endl;
        exit(0);
    }


    return palavras;

}


/**
 * Metodo inicial
 * @return
 */
int main() {

    cabecalho();

    sorteia();

    while (!enforcou() && !acertou()) {
        imprime_palavra();
        chutes_errados();
        chute();
    }
    placar();
}

 string sorteia() {

    vector<string> palavras = ler_arquivo();

    srand(time(NULL));

    int indice = rand() % palavras.size();

    palavra_secreta = palavras[indice];
}


/**
 * Imprime o placar ao final do jogo
 */
void placar() {
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (!acertou()) {
        cout << "Voce perdeu! Tente novamente!" << endl;
    } else {
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;
    }
}

/**
 * função para disponibilizar uma oportunidade de chute para o jogador
 */
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

/**
 * Imprime a palavra sendo formada
 */
void imprime_palavra() {
    cout << endl;
    cout << endl;
    for (char l: palavra_secreta) {
        if (chutou[l]) {
            cout << l << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

/**
 * Imprime os chutes errados
 */
void chutes_errados() {
    cout << endl;
    cout << "Chutes errados: ";
    for (char e: erros) {
        cout << e << " ";
    }
    cout << endl;
}


/**
 * Imprime o caveçalho do programa
 */
void cabecalho() {
    cout << "*****************" << endl;
    cout << "* JOGO DA FORCA *" << endl;
    cout << "*****************" << endl;
}

/**
 * Existe o caracter na palavra secreta
 * @param chute
 * @return
 */
bool existe(char chute) {

    for (char c: palavra_secreta) {
        if (chute == c) {
            return true;
        }
    }
    return false;
}

/**
 * Retorna se o jogador ja acertou a palavra secreta
 * @return
 */
bool acertou() {
    for (char l: palavra_secreta) {
        if (!chutou[l]) {
            return false;
        }
    }
    return true;
}

/**
 * Existem apenas quatro tentativas
 * @return
 */
bool enforcou() {
    return erros.size() > 4;
}
