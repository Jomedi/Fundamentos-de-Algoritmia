// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos {
    int torres, reinas, total;
    vector<int> casillaI, casillaK;
};

struct tMarcas {
    vector<bool> marcasCol, marcasFil, marcasDi, marcasDd;
    int numTorres, numReinas;
};

void imprimirTablero(const vector<vector<string>> & tablero) {
    for (int i = 0; i < tablero.size(); i++) {
        for (int j = 0; j < tablero[i].size(); j++) {
            cout << tablero[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < tablero.size(); i++) {
        cout << "//";
    }
    cout << "\n";
}

bool casillaValida(int i, int k, const tDatos datos) {
    for (int j = 0; j < datos.casillaI.size(); j++) {
        if (datos.casillaI[j] == i && datos.casillaK[j] == k)
            return false;
    }
    return true;
}

void nReinas(int k, const tDatos datos, int& maneras, tMarcas& marcas) {
    for (int i = 0; i < datos.total; i++) {
        if (casillaValida(i, k, datos)) {
            if (!marcas.marcasDd[i + k] && !marcas.marcasDi[k - i + datos.total - 1] && !marcas.marcasCol[k] && !marcas.marcasFil[i] && marcas.numReinas > 0) {
                marcas.marcasDd[i + k] = true;
                marcas.marcasDi[k - i + datos.total - 1] = true;
                marcas.marcasCol[k] = true;
                marcas.marcasFil[i] = true;
                marcas.numReinas--;
                if (k == datos.total - 1 && marcas.numReinas == 0 && marcas.numTorres == 0) {
                    maneras++;
                }
                    
                else
                    nReinas(k + 1, datos, maneras, marcas);
                marcas.numReinas++;
                marcas.marcasDd[i + k] = false;
                marcas.marcasDi[k - i + datos.total - 1] = false;
                marcas.marcasCol[k] = false;
                marcas.marcasFil[i] = false;
            }
            else if (!marcas.marcasDd[i + k] && !marcas.marcasDi[k - i + datos.total - 1] && !marcas.marcasCol[k] && !marcas.marcasFil[i] && marcas.numTorres > 0) {
                marcas.marcasCol[k] = true;
                marcas.marcasFil[i] = true;
                marcas.numTorres--;
                if (k == datos.total - 1 && marcas.numReinas == 0 && marcas.numTorres == 0) {
                    maneras++;
                } 
                else
                    nReinas(k + 1, datos, maneras, marcas);
                marcas.numTorres++;
                marcas.marcasCol[k] = false;
                marcas.marcasFil[i] = false;
            } 
        }
        
    }
}

int nReinas(const tDatos datos) {
    int maneras = 0;
    //vector<vector<string>> tablero(datos.total, vector<string>(datos.total, "-"));
    tMarcas marcas;
    marcas.marcasCol.resize(datos.total);
    marcas.marcasDd.resize(2*(datos.total) - 1);
    marcas.marcasDi.resize(2 * (datos.total) - 1);
    marcas.marcasFil.resize(datos.total);
    marcas.numReinas = datos.reinas;
    marcas.numTorres = datos.torres;
    nReinas(0, datos, maneras, marcas);
    return maneras;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int T, R;
    cin >> T >> R;

    if (!cin)
        return false;

    tDatos datos;
    datos.torres = T;
    datos.reinas = R;
    datos.total = T + R;

    int casillas, f, c;
    cin >> casillas;
    for (int i = 0; i < casillas; i++) {
        cin >> f >> c;
        datos.casillaI.push_back(f);
        datos.casillaK.push_back(c);
    }

    // escribir sol
    int maneras = nReinas(datos);
    cout << maneras << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}