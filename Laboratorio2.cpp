#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio, *fin;

class Pila{
    public:
        Pila(){
            inicio = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig= nullptr;
            return n;
        }

        void push(int valor){
            Nodo *n= crearNodo(valor);
            n->sig=inicio;
            inicio=n;
            
        }
        
        void mostrar(){
            Nodo *n = inicio;
            while(n){
                cout<<n->dato<<endl;
                n=n->sig;
            }
        }
        

        Nodo* pop(){
            Nodo* temp = inicio;
            inicio= inicio->sig;
            return temp;
        }

};

class Cola{
    public:
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig= nullptr;
            return n;
        }

        void push(int valor){
            Nodo *n= crearNodo(valor);
            if(!inicio){
                inicio=n;
                fin=n;
            }
            else{
                fin->sig=n;
                fin=n;
            }
        }

        void invertir(){
            Nodo *n = inicio;
            inicio = fin;
            inveritAux(n);
            fin->sig = nullptr;
        }

        void inveritAux(Nodo* n){
            if(n->sig && n->sig!=fin){
                inveritAux(n->sig);
            }
            fin->sig = n;
            fin=n;
        }

        void mostrar(){
            Nodo *n = inicio;
            while(n){
                cout<<n->dato<<endl;
                n=n->sig;
            }
        }

        void pop(){
            Nodo* temp = inicio;
            inicio= inicio->sig;
            free(temp);
        }

        void transform(Pila p){
            Nodo *n = inicio;
            while(n){
                p.push(n->dato);
                n = n->sig;
            }
        }
        int promedio(){
            int acum=0;
            int contador=0;
            Nodo *aux = inicio;
            while(aux){
            acum+=aux->dato;
            aux=aux->sig;
            contador++;
    }
    return acum/contador;
    }
    int Longitud(){
      Nodo *aux= inicio;
    int cont=0;
    while(aux){
        aux= aux->sig;
        cont++;
    }
    return cont;
    }
int getPos(int pos){
      Nodo *aux= inicio;
    int cont=0;
    while(aux){
        if(cont ==pos){
        return aux->dato;
        }
        aux = aux->sig;
        cont++;
    }
    return 0;
    }


    Cola(){
    inicio= NULL;
    }
};

Cola Multiplos(Cola cola1, int prom){
Cola newCola;
int lenght = cola1.Longitud();
for(int i=0; i<lenght; i++){
    int dato= cola1.getPos(i);
    if(dato%prom == 0){
        newCola.push(dato);
    }
}
return newCola;
}

int main(int argc, char** argv) {

    Cola cola1;
    Pila pila1;
    Cola cola2;
	Cola newCola;
    
    cola1.push(40);
    cola1.push(20);
    cola1.push(4);
    cola1.push(7);
    cola1.push(11);
    cola1.push(3);
    cola1.push(23);
    cola1.push(18);
    cola1.push(6);
    cola1.push(2);
    cola1.mostrar();
    cola1.invertir();
    cout<<"Se invirtio la cola"<<endl;
    cola1.mostrar();
    cola1.transform(pila1);
    return 0;
    int promedioCola1= cola1.promedio();

cola2 = Multiplos(cola1, promedioCola1);
    newCola.mostrar();
    cola2.promedio();
}
