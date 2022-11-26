#include "Supervisor.hpp"
#include "Empleado.hpp"

std::string Empleado::GetNombrePorValor() const {
    return _nombre;
}

const std::string* Empleado::GetNombrePorDireccion() const {
    return &_nombre;
}

void Empleado::PrintNombre() {
    std::cout << "Nombre empleado: " << _nombre << '\n';
}

void Empleado::PrintSueldo() {
    std::cout << "Sueldo empleado: " << _sueldo << '\n';
}

int Empleado::GetSueldo() {
    return _sueldo;
}

void Empleado::SetSupervisor(Supervisor& supervisor) {
    _supervisor = &supervisor;
}

Empleado::~Empleado() {
    delete(_supervisor);
}

Supervisor* Empleado::GetSupervisor() {
    return _supervisor;
}

void Empleado::PrintTodosLosDatos() {
    std::cout << "Todos los datos del empleado: " << '\n';
    std::cout << "Nombre: " << _nombre << '\n';
    std::cout << "Apellido: " << _apellido << '\n';
    std::cout << "Sueldo: " << _sueldo << '\n';
}