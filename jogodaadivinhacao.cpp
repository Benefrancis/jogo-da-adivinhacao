#include<iostream>
using namespace std;

int main(){

cout <<"**************************************"<< endl;
cout <<"* Bem-vindos ao jogo da adivinhacao! *"<< endl;
cout <<"**************************************"<< endl;

int numero_secreto = 42;
int chute;

 cout << "Qual eh o seu chute? ";
 cin >> chute;

 cout << "O valor do seu chute eh: " << chute << endl;

    if(chute == numero_secreto){
        cout << "Parabens! Voce acertou o numero secreto!" << endl;
    }else if(chute > numero_secreto){
        cout << "Seu chute foi maior do que o numero secreto!" << endl;
    }else{
      cout << "Seu chute foi menor do que o numero secreto!" << endl;
    }
}