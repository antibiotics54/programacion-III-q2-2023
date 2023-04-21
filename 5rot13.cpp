//clase3
//programa para utilizar rot13]
//cambiar las letras
#include <string>
#include <iostream>
using namespace std; 

//valores tabla ascii

#define a 97
#define m 109
#define z 122
#define A 65
#define M 77
#define Z 90
#define ROT_13_CONSTANT 13

//operation = 1 -> add
//operation = 0 -> subtract
//codigo repetitivo
void appendEncryptedChar(char asciiCharacter, bool operation, string &result){
    int encryptedAscii;
    //buscar el numero en la tsbla ascii
    operation ? 
    //se suma 13 por rot13
    encryptedAscii = asciiCharacter + ROT_13_CONSTANT : encryptedAscii = asciiCharacter - ROT_13_CONSTANT;
    char encryptedAsciiChar = char (encryptedAscii);
    result += encryptedAsciiChar;
}

string rot13(string wordToEncrypt){
    string result ="";
    for (int c = 0; c < wordToEncrypt.size(); c++)
    {
        //por la letra recorrida cambiarla a int para encontrar el numero que tiene
        int asciiCharacter = int (wordToEncrypt[c]);
       
        if ((asciiCharacter>=a && asciiCharacter<=m) || (asciiCharacter>=A && asciiCharacter<=M)){
            appendEncryptedChar(asciiCharacter,true, result);
        }else if ((asciiCharacter> m && asciiCharacter <=z) || (asciiCharacter> M && asciiCharacter <=Z)){
            appendEncryptedChar(asciiCharacter,false, result);
       //}else if (asciiCharacter>=A && asciiCharacter<=M){
         //   appendEncryptedChar(asciiCharacter,true, result);
       // }else if {
         //   appendEncryptedChar(asciiCharacter,false, result);
        }else {
            result += wordToEncrypt[c];
        }
    }
    
    return result;
}

//no se puede cambiar lo que se da de parametro
//i.e. respuesta no se puede cambiar

//colocar & antes de la variable para que dependa de otro del stack, mantener referencia del que lo llama
//sin & la respuesta no fuese 15, asi se puede modificar algo ya predeterminado en otro stack
//parametros por referencia
int suma (int l, int b, int &respuesta){
    //codigo dentro de esto se llamas stack
    respuesta = l + b;
    return 0;
}

//cada una de estas cosas se llaman scopes
int main(int argc, char const *argv[])
{
    int l = 10;
    int b = 5;
    int respuesta;

    suma(l, b, respuesta);
    cout<< "respuesta: " <<respuesta<<endl;


    //UBYN
    string hola = "Hola/";
    string encryptedWord = rot13(hola);
    cout <<"Encrypted word: "<< encryptedWord<<endl;
    return 0;
}

