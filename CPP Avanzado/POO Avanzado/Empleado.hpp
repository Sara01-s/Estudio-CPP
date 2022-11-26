#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <iostream>
#include "Supervisor.hpp"

using namespace std;

class Empleado {

private:
    int _sueldo;
    string _nombre;
    string _apellido;
    Supervisor* _supervisor;

public:
    friend class Supervisor;
    // friend int GetPromedioSueldoDepartamento(Supervisor* supervisor, Empleado* empleado, Empleado* empleado2);

    Empleado() {
        _sueldo = 400000;
        _nombre = "Pepito";
    }

    Empleado(int sueldo, string nombre, string apellido) {
        _sueldo = sueldo;
        _nombre = nombre;
        _apellido = apellido;
    }

    // Alternativa
    Empleado(int sueldo, string nombre) : _sueldo(sueldo), _nombre(nombre) {};
    
    // Constructor de copia
    Empleado(const Empleado& empleadoOriginal) {
        _sueldo = empleadoOriginal._sueldo;
        _nombre = empleadoOriginal._nombre;
        _apellido = empleadoOriginal._apellido;
    }

    ~Empleado();
    Supervisor* GetSupervisor();
    void SetSupervisor(Supervisor& supervisor);
    string GetNombrePorValor() const;
    const std::string* GetNombrePorDireccion() const;
    void PrintTodosLosDatos();
    void PrintSueldo();
    void PrintNombre();
    int GetSueldo();
    
};
#endif // EMPLEADO_HPP