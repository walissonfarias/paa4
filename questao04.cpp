#include "maiorInteiro.hpp";
#include "buscarMaior.hpp";
#include <iostream>

using namespace std;
//Busca o maior valor 
int buscarMaior(int s[], int n) {
    int m;
    if (n == 1)
        return s[0];
    else {
        m = buscarMaior(s, n - 1);
        if (m > s[n - 1]) {
            return m;
        }
        else {
            return s[n - 1];
        }
    }
}
//Encontra o maior valor inteiro de uma lista com n elementos.
int maiorInteiro(int s[]) {
    int n = sizeof(s) + 1;
    return buscarMaior(s, n);
}

int main() {
    int arr[] = { 3,40,40,2,40};
    int valor = maiorInteiro(arr);
    std::cout << "O maior valor do array e: \n" << valor << std::endl;

    return 0;
}
