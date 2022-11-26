#include <iostream>
#include "Empleado.hpp"
#include "Supervisor.hpp"

void Supervisor::PrintNombreEmpleado(const Empleado* empleado) {
    std::cout << "Nombre empleado: " << empleado->_nombre << '\n';
}

int Supervisor::GetPromedioSueldoDepartamento(Supervisor* supervisor, Empleado* empleado, Empleado* empleado2) {
    return (supervisor->_sueldo + empleado->_sueldo + empleado2->_sueldo) / 3;
}

void Supervisor::SupervisarA(Empleado& empleado) {
    _empleadoSupervisado = &empleado;
}

std::string Supervisor::GetNombre() {
    return _nombre;
}

// Destructor personalizado
Supervisor::~Supervisor() {
    // poner delete en atributos inicializados con new
    delete(_empleadoSupervisado);
}