#include <iostream>
#include "Empleado.hpp"
#include "Supervisor.hpp"

int main(int argc, char** argv) {   

    // Objeto con manejo de memoria automático
    Empleado _empleadoDefault;

    _empleadoDefault.PrintNombre();
    _empleadoDefault.PrintSueldo();
    // Objeto sin manejo de memoria automático (no recomendado)

    Empleado* _empleado_ptr = new Empleado();

    _empleado_ptr->PrintNombre();
    _empleado_ptr->PrintSueldo();

    delete(_empleado_ptr);

    Empleado empleado3(400000, "Juan");
    Supervisor supervisor1(500000);

    supervisor1.PrintNombreEmpleado(&empleado3);

    Empleado empleado4 = Empleado(500000, "Maria", "Juanez");
    Empleado copiaEmpleado4 = Empleado(empleado4);
    copiaEmpleado4.PrintTodosLosDatos();

    Empleado empleado5 = Empleado(700000, "Pepe", "Moreno");

    // Llamada implicita al constructor de conversión (sin explicit)
    //Supervisor supervisor2 = empleado5;
    // Llamada explicita al constructor de conversión (mejor práctica)
    Supervisor supervisor2 = Supervisor(empleado5);

    // Asociación de clases
    /*Empleado empleado6;
    empleado6.SetSupervisor(supervisor2);
    supervisor2.SupervisarA(empleado6);

    // Navegabilidad de clases asociadas
    std::cout << "Supervisor de: " << empleado6.GetNombrePorValor() << ": " 
              << empleado6.GetSupervisor()->GetNombre() << std::endl;*/

    
    

    return 0;
}