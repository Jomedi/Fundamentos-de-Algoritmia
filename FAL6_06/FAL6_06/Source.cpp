// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

struct tDatosConst {
    int supermercados, productos;
    vector<vector<int>> precios;
};

struct tDatos {
    vector<int> prodmismosuper;
    vector<int> coste;
    int suma;
    int precioTotal = 0, minimo = INT_MAX;
};

// función que resuelve el problema
void resolver(tDatosConst const datosConst, tDatos& datos, int col) {
    for (int i = 0; i < datosConst.supermercados; i++) {
        if (datos.prodmismosuper[i] < 3) {

            //marcar producto cogido del super i
            datos.prodmismosuper[i]++;
            //sumar al precio total el precio del producto col del super i
            datos.precioTotal += datosConst.precios[i][col];
            //resta de la suma mínima del producto mínimo col
            datos.suma -= datos.coste[col];

            if (datos.precioTotal + datos.suma < datos.minimo) { // si lo que llevas pagado más el mínimo calculado se pasa del mínimo precioTotal, no lo tienes en cuenta (el primer mínimo es alto porque suma = 0)
                if (col == datosConst.productos - 1)
                    datos.minimo = datos.precioTotal;
                else
                    resolver(datosConst, datos, col + 1);
            }

            datos.prodmismosuper[i]--;
            datos.precioTotal -= datosConst.precios[i][col];
            datos.suma += datos.coste[col];
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    tDatos datos;
    tDatosConst datosConst;

    cin >> datosConst.supermercados >> datosConst.productos;

    vector<vector<int>> precios(datosConst.supermercados, vector<int>(datosConst.productos));
    for (auto& productos : precios) {
        for (auto& precio : productos) {
            cin >> precio;
        }
    }
    datosConst.precios = precios;

    vector<int> prodmismosuper(datosConst.supermercados, 0);
    datos.prodmismosuper = prodmismosuper;

    vector<int> coste(datosConst.productos);
    int suma = 0;
    for (int i = 0; i < datosConst.productos; i++) {

        int mini = datosConst.precios[0][i];

        for (int j = 1; j < datosConst.supermercados; j++)
            mini = min(mini, datosConst.precios[j][i]);

        coste[i] = mini;
        suma += mini;
    }
    datos.suma = suma;
    datos.coste = coste;

    resolver(datosConst, datos, 0);

    // escribir sol
    cout << datos.minimo << "\n";

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