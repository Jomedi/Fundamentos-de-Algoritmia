// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int multiplicativo(int num, int &mult) {
    int sol = num % 10, rec;

    if (num >= 10)
        rec = multiplicativo(num / 10, mult);
    else {
        if (num == 1)
            mult++;
        return num;
    }

    if (rec % 10 == sol)
        mult++;

    return sol * rec;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    // escribir sol
    int mul = 0;
    multiplicativo(n, mul);
    cout << mul << '\n';
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