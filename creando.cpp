#include <iostream>
using namespace std;

class Node
{
private:
   int _value;
public:
    Node();
    Node(int);
    ~Node();

    //getters y setters
    int getValue();
};
//constructor
 Node:: Node(int value)
{
    this->_value=value;
    //this sirve para ver todos los atributos publicos
    //ie Node n = new Node()
    //instance =n
    //delete instante
    //free instance
}
Node ::Node(){
    this->_value=0;
}
 Node:: ~Node()
{
    
}

int Node::getValue()
{
    return this->_value;
}

int main(int argc, char const *argv[])
{
    int arr[100];
    int n=10;
    int *ptrn = &n;

    cout<<"Direccion: "<<ptrn<<endl;
    cout<<"numero: "<<n<<endl;
    cout<<"numero por medio de desreferenciar: "<< ptrn <<endl;
    //endl es un enter como el ln en java

    //cuando se utilizan clases para poder utilizar clases internas un * despues de la clase
    //se coloca despues de new Node() en el parentesis el numero del constructor que deseo utilizar;
    Node* node = new Node(2);
    //cada vez que se coloque un new se coloca un delete
    //para poder liberar la memoria
    cout<<node->getValue();
    delete node;
    return 0;
}