#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const int MAX_CARROS = 2000;
const int MAX_CLIENTES = 2000;

// Estructura para almacenar la información de un carro
struct Carro {
    int id;
    string marca;
    string modelo;
    int ano;
    int vendido_a;
    int comprado_a;
    double precio_venta;
    double precio_compra;
    string cliente;
    bool vendido;
};

// Estructura para almacenar la información de un cliente
struct Cliente {
    int id;
    string nombre;
    string apellido;
    string correo;
    int edad;
};

// Arreglos para almacenar los datos de los carros y clientes
Carro carros[MAX_CARROS];
Cliente clientes[MAX_CLIENTES];
int numCarros = 0;
int numClientes = 0;

// Función para cargar los datos de carros desde un archivo CSV
void cargardatoscarros() {
    ifstream archivo("autos.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de carros." << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Leer la primera línea (encabezados) y descartarla

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string dato;

        getline(ss, dato, ';'); // Leer y asignar la ID
        carros[numCarros].id = stoi(dato);

        getline(ss, carros[numCarros].marca, ';'); // Leer y asignar la marca
        getline(ss, carros[numCarros].modelo, ';'); // Leer y asignar el modelo

        getline(ss, dato, ';'); // Leer y asignar el año
        carros[numCarros].ano = stoi(dato);

        getline(ss, dato, ';'); // Leer y asignar el cliente al que se vendió
        carros[numCarros].vendido_a = stoi(dato);

        getline(ss, dato, ';'); // Leer y asignar el cliente al que se compró
        carros[numCarros].comprado_a = stoi(dato);

        getline(ss, dato, ';'); // Leer y asignar el precio de venta
        carros[numCarros].precio_venta = stod(dato);

        getline(ss, dato); // Leer y asignar el precio de compra
        carros[numCarros].precio_compra = stod(dato);

        numCarros++;

        if (numCarros >= MAX_CARROS) {
            cout << "Se ha alcanzado el límite máximo de carros." << endl;
            break;
        }
    }

    archivo.close();
}

// Función para cargar los datos de clientes desde un archivo CSV
void cargardatosclientes() {
    ifstream archivo("clientes.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de clientes." << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Leer la primera línea (encabezados) y descartarla

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string dato;

        getline(ss, dato, ';'); // Leer y asignar la ID
        clientes[numClientes].id = stoi(dato);

        getline(ss, clientes[numClientes].nombre, ';'); // Leer y asignar el nombre
        getline(ss, clientes[numClientes].apellido, ';'); // Leer y asignar el apellido

        getline(ss, clientes[numClientes].correo, ';'); // Leer y asignar el correo

        getline(ss, dato); // Leer y asignar la edad
        clientes[numClientes].edad = stoi(dato);

        numClientes++;

        if (numClientes >= MAX_CLIENTES) {
            cout << "Se ha alcanzado el límite máximo de clientes." << endl;
            break;
        }
    }

    archivo.close();
}

// Función para vender un carro
void venderCarro(int idCarro, const string& nombreCliente) {
    for (int i = 0; i < numCarros; ++i) {
        if (carros[i].id == idCarro) {
            if (!carros[i].vendido) {
                carros[i].vendido = true;
                carros[i].cliente = nombreCliente;
                cout << "Carro vendido a " << nombreCliente << " por $" << carros[i].precio_venta << endl;
            } else {
                cout << "El carro ya ha sido vendido." << endl;
            }
            return;
        }
    }
    cout << "No se encontró el carro con la ID especificada." << endl;
}

// Función para calcular la pérdida de la empresa
double perdida() {
    double perdida = 0.0;
    for (int i = 0; i < numCarros; ++i) {
        if (!carros[i].vendido) {
            perdida += carros[i].precio_compra;
        }
    }
    return perdida;
}

// Función para mostrar los carros vendidos
void mostrarcarrosvendidos() {
    cout << "Carros vendidos: " << endl;
    bool encontrados = false;
    for (int i = 0; i < numCarros; ++i) {
        if (carros[i].vendido) {
            cout << "ID: " << carros[i].id << ", Marca: " << carros[i].marca << ", Modelo: " << carros[i].modelo
                 << ", Año: " << carros[i].ano << ", Precio de venta: " << carros[i].precio_venta << ", Comprado por: "
                 << carros[i].cliente << endl;
            encontrados = true;
        }
    }
    if (!encontrados) {
        cout << "No hay carros vendidos." << endl;
    }
}
// Función para mostrar los datos de los clientes
void mostrardatosclientes() {
    cout << "Lista de clientes:" << endl;
    for (int i = 0; i < numClientes; ++i) {
        cout << "ID: " << clientes[i].id << ", Nombre: " << clientes[i].nombre << ", Apellido: " << clientes[i].apellido
             << ", Correo: " << clientes[i].correo << ", Edad: " << clientes[i].edad << endl;
    }
}

// Función para guardar los datos de carros en un archivo CSV
void guardarDatosCarros() {
    ofstream archivo("carros.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de carros para guardar." << endl;
        return;
    }
// Función para mostrar los datos de los clientes
void mostrardatosclientes(); {
    cout << "Lista de clientes:" << endl;
    for (int i = 0; i < numClientes; ++i) {
        cout << "ID: " << clientes[i].id << ", Nombre: " << clientes[i].nombre << ", Apellido: " << clientes[i].apellido
             << ", Correo: " << clientes[i].correo << ", Edad: " << clientes[i].edad << endl;
    }
}

    // Escribir encabezados
    archivo << "id;marca;modelo;ano;vendido_a;comprado_a;precio_venta;precio_compra" << endl;

    // Escribir datos de los carros
    for (int i = 0; i < numCarros; ++i) {
        archivo << carros[i].id << ';' << carros[i].marca << ';' << carros[i].modelo << ';' << carros[i].ano << ';'
                << carros[i].vendido_a << ';' << carros[i].comprado_a << ';' << carros[i].precio_venta << ';'
                << carros[i].precio_compra << endl;
    }

    archivo.close();
}

int main() {
    cargardatoscarros(); // Cargar los datos de los carros desde el archivo CSV
    cargardatosclientes(); // Cargar los datos de los clientes desde el archivo CSV

    int opcion;
    do {
        cout << "\nMENU\n";
        cout << "1. Mostrar lista de carros disponibles\n";
        cout << "2. Mostrar lista de carros vendidos\n";
        cout << "3. Mostrar lista de clientes\n";
        cout << "4. Vender carro\n";
        cout << "5. Mostrar perdida de la empresa\n";
        cout << "6. Salir del programa\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Lista de carros:" << endl;
                for (int i = 0; i < numCarros; ++i) {
                    cout << "ID: " << carros[i].id << ", Marca: " << carros[i].marca << ", Modelo: " << carros[i].modelo
                         << ", Año: " << carros[i].ano << ", Vendido a: " << (carros[i].vendido ? carros[i].cliente : "N/D")
                         << ", Comprado a: " << (carros[i].comprado_a ? to_string(carros[i].comprado_a) : "N/D")
                         << ", Precio de venta: " << carros[i].precio_venta << ", Precio de compra: " << carros[i].precio_compra << endl;
                }
                break;
            case 2:
                mostrarcarrosvendidos();
                break;
            case 3:
                mostrardatosclientes();
                break;
            case 4: {
    // Función para vender un carro
    int idCarro;
    cout << "Ingrese el ID del carro que desea vender: ";
    cin >> idCarro;
    cin.ignore(); // Limpiar el buffer del teclado

    string nombreCliente;
    cout << "Ingrese el nombre del cliente al que se vendió el carro: ";
    getline(cin, nombreCliente);

    venderCarro(idCarro, nombreCliente);

    // Guardar los datos actualizados de los carros en el archivo
    ofstream archivo("carros.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de carros para guardar." << endl;
        return 1; // Salir del programa con código de error
    }

    // Escribir encabezados
    archivo << "id;marca;modelo;ano;vendido_a;comprado_a;precio_venta;precio_compra" << endl;

    // Escribir datos de los carros
    for (int i = 0; i < numCarros; ++i) {
        archivo << carros[i].id << ';' << carros[i].marca << ';' << carros[i].modelo << ';' << carros[i].ano << ';'
                << carros[i].vendido_a << ';' << carros[i].comprado_a << ';' << carros[i].precio_venta << ';'
                << carros[i].precio_compra << endl;
    }

    archivo.close();

    break;
}
            case 5:
                cout << "Perdida de la empresa: $" << perdida() << endl;
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
        }
    } while (opcion != 6);

    return 0;
}

