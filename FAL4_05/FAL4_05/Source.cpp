// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


// función que resuelve el problema
int resolver1(int num1, int num2) {
    int mod1 = num1 % 10;
    int mod2 = num2 % 10;

    int sol = (mod1 + mod2) % 10;

    if (num1 >= 10 || num2 >= 10)
        sol += 10 * resolver1(num1 / 10, num2 / 10);

    return sol;
}

int resolver2(int num1, int num2) {
    int mod1 = num1 % 10;
    int mod2 = num2 % 10;

    int sol = (mod1 + mod2) % 10;

    if (num1 < 10 && num2 < 10)
        return sol;
    
    int resolver = resolver1(num1 / 10, num2 / 10);

    return sol + 10 * resolver;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n1, n2;
    cin >> n1 >> n2;

    // escribir sol
    cout << resolver1(n1, n2) << " " << resolver2(n1, n2) << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}