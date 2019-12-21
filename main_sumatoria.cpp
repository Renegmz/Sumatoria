/* 
 * File:   main.cpp
 * Author: renegomez
 *
 * Created on 15 de diciembre de 2019, 06:31 PM
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename T>
T sumatoria_asc(T suma_act, T suma_ant, int &k)
{
    bool seguir(true);
    while(seguir)
    {
        suma_ant = suma_act;
        suma_act += 1 / pow(k,4);
        if(suma_act == suma_ant)
            seguir = false;
        else
            k++;
    }
    return suma_act;
}

template <typename T>
T sumatoria_desc(T suma_act, T suma_ant, int k)
{
    bool seguir(true);
    while(seguir && k)
    {
        suma_ant = suma_act;
        suma_act += 1 / pow(k,4);
        if(suma_act == suma_ant)
            seguir = false;
        else
            k--;
    }
    return suma_act;
}

int main()
{
    int k(1);
    float suma_act1(0), suma_ant1(0);
    double suma_act2(0), suma_ant2(0);

    cout << fixed << setprecision(25) << endl;
   
    cout << "----------Sumatoria Ascendente----------" << endl;
    suma_act1 = sumatoria_asc(suma_act1,suma_ant1,k);
    cout << "Simple precisión" << endl;
    cout << "El mayor valor de la sumatoria: " << suma_act1 << " El máximo número de terminos sumados: " << k << endl;
    
    k=1;
    suma_act2 = sumatoria_asc(suma_act2,suma_ant2,k);
    cout << "Doble precisión" << endl;
    cout << "El mayor valor de la sumatoria: " << suma_act2 << " El máximo número de terminos sumados: " << k << endl;
    
    cout << "----------Sumatoria Descendente----------" << endl;
    suma_act1 = suma_ant1 = 0;
    suma_act1 = sumatoria_desc(suma_act1,suma_ant1,64);
    cout << "Simple precisión" << endl;
    cout << "El mayor valor de la sumatoria: " << suma_act1 << " El máximo número de terminos sumados: " << "64" << endl;
    
    suma_act2 = suma_ant2 = 0;
    suma_act2 = sumatoria_desc(suma_act2,suma_ant2,9741);
    cout << "Doble precisión" << endl;
    cout << "El mayor valor de la sumatoria: " << suma_act2 << " El máximo número de terminos sumados: " << "9741" << endl;
    return 0;
}



