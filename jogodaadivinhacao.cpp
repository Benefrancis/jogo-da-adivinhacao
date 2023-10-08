#include<iostream>
using namespace std;

int main(){

cout <<"**************************************"<< endl;
cout <<"* Bem-vindos ao jogo da adivinhacao! *"<< endl;
cout <<"**************************************"<< endl;

const int NUMERO_SECRETO = 42;
int chute;
bool acertou= false;
int tentativas = 0;

while(!acertou){

tentativas ++;
cout << "Tentativa "<< tentativas << endl;
cout << "Qual eh o seu chute? ";
 cin >> chute;

 cout << "O valor do seu chute eh: " << chute << endl;

    acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;


    if(acertou){
        cout << "Parabens! Voce acertou o numero secreto!" << endl;
    }else if(maior){
        cout << "Seu chute foi maior do que o numero secreto!" << endl;
    }else{
      cout << "Seu chute foi menor do que o numero secreto!" << endl;
    }

}
cout << "Fim de jogo...";
cout << "Voce acertou o numero secreto na " << tentativas << "a tentativa! " << endl;
}