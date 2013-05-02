//
//  main.cpp
//  Ejercicio5T8
//
//  Created by Dani on 02/05/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tabla.h"

using namespace std;

Tabla<int, float> generarVectorDisperso(int* v, int tam);
int sumaVectoresDispersos(Tabla<int, float>& vector1, Tabla<int, float>& vector2);
int productoVectoresDispersos(Tabla<int, float>& vector1, Tabla<int, float>& vector2);

int main(int argc, const char * argv[]) {
    
    srand((unsigned)time(0));
    
    int *v = new int[20];
    int *w = new int[10];
    
    for (int i = 0; i < 20; i++) {
        
        if ( i % 3 == 0) {
            v[i] = 0;
        }
        else {
            v[i] = (rand()%20)+1;
        }
    }
    
    for (int j = 0; j < 30; j++) {
        
        if ( j % 4 == 0) {
            w[j] = 0;
        }
        else {
            w[j] = (rand()%20)+1;
        }
    }
    
    for (int h = 0; h < 20; h++) {
        cout << v[h] << ",";
    }
    cout << endl;
    
    for (int k = 0; k < 30; k++) {
        cout << w[k] << ",";
    }
    cout << endl;
    
    Tabla<int, float> a = generarVectorDisperso(v, 20);
    
    Tabla<int, float>::Iterador it = a.principio();
    while (it != a.final()) {
        cout << it.clave() << ": " << it.valor() << endl;
        
        it.avanza();
    }
    
    Tabla<int, float> b = generarVectorDisperso(w, 30);
    
    Tabla<int, float>::Iterador itb = b.principio();
    while (itb != b.final()) {
        cout << itb.clave() << ": " << itb.valor() << endl;
        
        itb.avanza();
    }
    
    int sumaVectores = sumaVectoresDispersos(a, b);

    cout << "Suma de los dos vectores: " << sumaVectores << endl;
    
    int productoVectores = productoVectoresDispersos(a, b);

    cout << "Producto de los dos vectores: " << productoVectores << endl;
    
    return 0;
}

Tabla<int, float> generarVectorDisperso(int* v, int tam) {
    
    Tabla<int, float> vectorDisperso{};
    
    for (int i = 0; i < tam; i++) {
        if (v[i] > 0 && v[i] <= 20) {
            vectorDisperso.inserta(i, v[i]);
        }
    }
    
    return vectorDisperso;
}

int sumaVectoresDispersos(Tabla<int, float>& vector1, Tabla<int, float>& vector2) {
    
    int suma = 0;
    
    Tabla<int, float>::Iterador it1 = vector1.principio();
    Tabla<int, float>::Iterador it2 = vector2.principio();
    
    while (it1 != vector1.final() && it2 != vector2.final()) {
        
        suma += it1.valor();
        suma += it2.valor();
        
        if(it1 != vector1.final()) {
            it1.avanza();
        }
        
        if(it2 != vector2.final()) {
            it2.avanza();
        }
    }
    
    return suma;
}

int productoVectoresDispersos(Tabla<int, float>& vector1, Tabla<int, float>& vector2) {
    
    int producto = 1;
    
    Tabla<int, float>::Iterador it1 = vector1.principio();
    Tabla<int, float>::Iterador it2 = vector2.principio();
    
    while (it1 != vector1.final() && it2 != vector2.final()) {
        
        producto *= it1.valor();
        producto *= it2.valor();
        
        if(it1 != vector1.final()) {
            it1.avanza();
        }
        
        if(it2 != vector2.final()) {
            it2.avanza();
        }
    }
    
    return producto;
}

