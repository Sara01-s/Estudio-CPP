#ifndef SUPERVISOR_HPP
#define SUPERVISOR_HPP

#pragma once
#include "Empleado.hpp"

class Supervisor {

public:

    Supervisor(int sueldo) {
        _sueldo = sueldo;
    }

    // Constructor de conversión
    explicit Supervisor (const Empleado empleado) {
        // Getters...
        // _nombre = empleado.GetNombre();
    }

    int GetPromedioSueldoDepartamento(Supervisor* supervisor, Empleado* empleado, Empleado* empleado2);
    // friend int GetPromedioSueldoDepartamento(Supervisor* supervisor, Empleado* empleado, Empleado* empleado2);
    void PrintNombreEmpleado(const Empleado* empleado);
    void SupervisarA(Empleado& empleado);
    std::string GetNombre();

private:

    Empleado* _empleadoSupervisado;
    std::string _apellido;
    std::string _nombre;
    int _sueldo;
};
#endif // SUPERVISOR_HPP