#include "maxMin.hpp"
#include "divisaoConquista.hpp"
#include <iostream>

using namespace std;

//divide array em chamadas recursivas
int divisaoConquista(int s[], int n) {
    int m;
    if (n == 1)
        return s[0];
    else {
        m = divisaoConquista(s, n - 1);
        if (m > s[n - 1]) {
            return m;
        }
        else {
            return s[n - 1];
        }
    }
}

//Encontra o maior valor de uma lista com n elementos.
int MaxMin(int s[]) {
    int n = sizeof(s) + 1;
    return divisaoConquista(s, n);
}


int main() {
    int arr[] = { 3,40,40,2,40 };
    int valor = maxMin(arr);
    std::cout << "O maior valor do array e: \n" << valor << std::endl;

    return 0;
}
