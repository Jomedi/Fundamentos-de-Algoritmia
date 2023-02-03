// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tMarcas {
    vector<bool> marcasCol, marcasFil, marcasDi, marcasDd;
};

void nReinas(int k, int n, int &maneras, tMarcas &marcas) {
    for (int i = 0; i < n; i++) {
        if (!marcas.marcasDd[i + k] && !marcas.marcasDi[k - i + n - 1] && !marcas.marcasCol[k] && !marcas.marcasFil[i]) {
            marcas.marcasDd[i + k] = true;
            marcas.marcasDi[k - i + n - 1] = true;
            marcas.marcasCol[k] = true;
            marcas.marcasFil[i] = true;
            if (k == n - 1)
                maneras++;
            else   
                nReinas(k + 1, n, maneras, marcas);   
            marcas.marcasDd[i + k] = false;
            marcas.marcasDi[k - i + n - 1] = false;
            marcas.marcasCol[k] = false;
            marcas.marcasFil[i] = false;   
        }
    }
}

int nReinas(int n) {
    int maneras = 0;
    tMarcas marcas;
    marcas.marcasCol.resize(n);
    marcas.marcasDd.resize(n+n-1);
    marcas.marcasDi.resize(n+n-1);
    marcas.marcasFil.resize(n);
    nReinas(0, n, maneras, marcas);
    return maneras;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;

    // escribir sol
    int maneras = nReinas(N);
    cout << maneras << "\n";

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