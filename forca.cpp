#include<iostream>
#include<string>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

bool existe(char chute){

    for(char c: PALAVRA_SECRETA){
        if(chute == c){
            return true;
        }
    }
    return false;
}


int main(){
    cout << PALAVRA_SECRETA << endl;
    bool acertou;
    bool enforcou;
    while(!enforcou || !acertou){
        char chute;
        cout << "Chute uma letra: "<< endl;
        cin >> chute;
        if(existe(chute)){
            cout << "O seu chute esta na palavra" << endl;
        }else{
            cout << "O seu chute nao esta na palavra" << endl;
        }
    }
}