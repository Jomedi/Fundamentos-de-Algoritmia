// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct tObjeto {
    int costeObj, superficieObj;
    double densidadObj;
};

bool operator<(tObjeto a, tObjeto b) {
    return a.densidadObj < b.densidadObj;
}

struct tDatos {
    int numObjetos, presupuesto;
    vector<int> costeObj, superficieObj;
    vector<double> densidadObj;
};

struct tSol {
    int superficieCub = 0;
    int coste = 0;
    int maxSupCub = -1;
    vector<bool> pagado;
};


vector<int> estimacion(const tDatos &datos, const vector<tObjeto> &objetos) {
    vector<int> esti(datos.numObjetos);

    int supMax = -1, densMax = -1;
    for (int i = 0; i < objetos.size(); i++) {
        if (densMax < objetos[i].densidadObj) {
            supMax = objetos[i].superficieObj;
            densMax = objetos[i].densidadObj;
        } 
    }

    for (int i = 0; i < datos.numObjetos; i++) {
        esti[i] = supMax * (datos.numObjetos - i);
    }

    return esti;
}

// función que resuelve el problema
void resolver(tDatos const& datos, int k, tSol& sol, const vector<int>& esti) {
    int supEstimado = sol.superficieCub + esti[k];
    sol.pagado[k] = true;
    sol.superficieCub += datos.superficieObj[k];
    sol.coste += datos.costeObj[k];
    if (sol.coste <= datos.presupuesto) {
        if (k == datos.numObjetos - 1) {
            if (sol.maxSupCub < sol.superficieCub)
                sol.maxSupCub = sol.superficieCub;
        }
        else if (sol.maxSupCub < supEstimado)
            resolver(datos, k + 1, sol, esti);
    }

    supEstimado = sol.superficieCub - esti[k];
    sol.pagado[k] = false;
    sol.superficieCub -= datos.superficieObj[k];
    sol.coste -= datos.costeObj[k];
    // hijo derecho [ no cogemos el objeto ]
    if (k == datos.numObjetos - 1) {
        if (sol.maxSupCub < sol.superficieCub) 
            sol.maxSupCub = sol.superficieCub;  
    }
    else if (sol.maxSupCub < supEstimado)
        resolver(datos, k + 1, sol, esti);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, p;
    cin >> n >> p;

    if (!std::cin)
        return false;

    tDatos datos;
    datos.numObjetos = n;
    datos.presupuesto = p;

    vector<tObjeto> objetos(n);

    int coste, superficie;
    for (int i = 0; i < n; i++) {
        cin >> coste >> superficie;
        tObjeto aux;
        aux.costeObj = coste;
        aux.superficieObj = superficie;
        aux.densidadObj = superficie / coste;
        objetos.push_back(aux);
        //ANTIGUA SOLUCIÓN
        datos.costeObj.push_back(coste);
        datos.superficieObj.push_back(superficie);
        datos.densidadObj.push_back(superficie / coste);
    }

    vector<vector<int>> m(n, vector<int>(n));

    tSol sol;
    vector<bool> pagado(n, false);
    sol.pagado = pagado;

    //vector con la estimacion (n - k + 1) * superficieObj
    auto esti = estimacion(datos, objetos);
    resolver(datos, 0, sol, esti);

    // escribir sol
    cout << sol.maxSupCub << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}