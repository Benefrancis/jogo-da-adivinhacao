#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(){

cout <<"**************************************"<< endl;
cout <<"* Bem-vindos ao jogo da adivinhacao! *"<< endl;
cout <<"**************************************"<< endl;

int numero_tentativas;

srand(time(NULL));

const int NUMERO_SECRETO = rand() % 100;

int chute;
bool acertou= false;
int tentativas = 0;
double pontos = 1000.0;

cout << "Escolha o seu nivel de dificuldade: " << endl;
cout << "Facil (F), Medio (M) ou Dificil(D)" << endl;

char dificuldade;

cin >> dificuldade;

if(dificuldade = 'F'){
numero_tentativas = 15;
}else if(dificuldade = 'M'){
numero_tentativas = 10;

}else{
numero_tentativas = 5;
}

for(tentativas = 1; tentativas <= numero_tentativas ; tentativas ++) {

    cout << "Tentativa "<< tentativas << endl;
    cout << "Qual eh o seu chute? ";
    cin >> chute;

    cout << "O valor do seu chute eh: " << chute << endl;

    acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;

    //o divisor deve ser double também
    double pontos_perdidos =  abs(chute - NUMERO_SECRETO) /  2.0;

    pontos -= pontos_perdidos;

    if(acertou){
        cout << "Parabens! Voce acertou o numero secreto!" << endl;
        break; //Interrompendo o laço de repetição
    }else if(maior){
        cout << "Seu chute foi maior do que o numero secreto!" << endl;
    }else{
      cout << "Seu chute foi menor do que o numero secreto!" << endl;
    }

}
cout << "Fim de jogo...";

if(acertou){
cout << "Voce acertou o numero secreto na " << tentativas << "a tentativa! " << endl;
cout.precision(2);
cout << fixed;
cout << "Sua pontuacao foi de: " << pontos << endl;
}else{
cout << "Voce perdeu! Tente novamente!" << endl;
}

}