#include <iostream>

using namespace std;

void pidemat(int f,int c,int **a);                          //declaramos la funcion para pedir los numeros de las matrices
void imprime(int f,int c,int **a);                          //mostramos la matriz al usuario
void multiplica(int m,int n,int s,int **b,int **d,int **e); //declaracion de duncion para realizar la multiplicacion de matrices

void pidemat(int f,int c,int **a){              //f son las filas, c las columnas y a es la matriz
    for(int i=0;i<f;i++){                       //recorremos las filas
        for(int j=0;j<c;j++){                   //recorre las columnas
            cout<<"["<<i<<"]""["<<j<<"]"<<endl; //para que el usuario ingrese cada dato en cada posicion de la matriz
            cin>>a[i][j];                       //se almacena en la posicion indicada
        }
    }
}
void imprime(int f,int c,int **a){  //esta funcion muestra la matriz al usuario, se define #filas, #columnas y la matriz
    for(int i=0;i<f;i++){           //recorre filas
        for(int j=0;j<c;j++){       //recorre columnas
            cout<<*(*(a+i)+j);      //se muestra el VALOR de cada posicion
        }
    cout<<"\n";                     //un salto de linea para que tenga estructura de matriz
    }
 }

void multiplica(int m,int n,int s,int **b,int **d,int **e){ //haremos la opercion de multiplicacion de matrices, matriz b por d y se almacena en la matriz e
    for(int i=0;i<m;i++){                                   //se recorre hasta la ultima fila (m)
        for(int j=0;j<s;j++){                               //se recorre las columnas hasta n
            for(int k=0;k<n;k++){                           //se recorren las filas de la segunda matriz
                e[i][j]=e[i][j]+b[i][k]*d[k][j];            //se almacena en la matriz e
            }
        }
    }
}
int **nuevaMatriz(int p, int q){            //usaremos esta funcion para almacenar los nuevos datos
    int **m, j;
    m= new int *[p];
    for (j=0;j<p;j++){
        m[j]= new int [q];                  //se asigna los valores de cada uno a la nueva matriz
    }
    return m;
}

void pedirdatos(int m, int n, int q, int s){ //se piden los datos generales al usuario
    cout<<"ingrese numero de filas de la matriz A: "<<endl;
    cin>>m;
    cout<<"ingrese numero de columnas de la matriz A: "<<endl;
    cin>>n;
    cout<<"ingrese numero de filas de la matriz B: "<<endl;
    cin>>q;
    cout<<"ingrese numero de columnas de la matriz A: "<<endl;
    cin>>s;
}

int main(){
    int c,f,i,j,x,t,m,n,q,s; //todas las variables que usaremos, fila scolumnas de cada , iteradores
    int *a,**b,**e,*d,**g;   //las matrices que vamos a crear

    pedirdatos(m,n,q,s);        //llamamos a la funcion

    b=new int *[m];             //a b se le asigna el valor de m que son las filas
    e=new int *[q];             //a e se le asigna el valor de q que son las columnas
    g=new int *[m];             //a g se le asigna el valr de m que son las filas
    cout<<"Elementos de la Matriz A: ";
    pidemat(m,n,b);             //se solicita la orimera matriz
    cout<<"Elementos de la Matriz B: ";
    pidemat(q,s,e);             //SE solicita la segunda matriz
    multiplica(m,n,s,b,e,g);        //se hace la multp de matrices
    cout<<"\n";
    imprime(m,s,g);                 //se muestra las matrices
    delete[]b;                      //se elimina las matrices
    delete[]d;
    delete[]e;
    return 0;
}

