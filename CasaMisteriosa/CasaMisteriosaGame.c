// Casa del terror
// (c) Sara San Martín

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define HUESO 1
#define LLAVE 2
#define ESCAL 3
#define ESCALERA 3
#define PERRO 4
#define SIZE 40

typedef struct Habitacion Habitacion;
typedef struct Objeto Objeto;

// Estructuras
struct Habitacion {
    char descripcion[255];
    int norte, sur, este, oeste;

} habitaciones[9];

struct Objeto {
    int estadoActual;
    char descEstado_1[80];
    char descEstado_2[80];
    int habitacion;
    int yaLoTengo;
} objetos[4];

// Inicializadores
void InitHabitacion(
    Habitacion* habitacion, int norte, int sur, int este, int oeste, const char* desc) {

    strcpy(habitacion->descripcion, desc);
    habitacion->norte = norte;
    habitacion->sur = sur;
    habitacion->este = este;
    habitacion->oeste = oeste;
}

void InitObjeto(
    Objeto* objeto, int estado, int habitacion, int loTengo, const char* desc1, const char* desc2) {

    objeto->estadoActual = estado;
    strcpy(objeto->descEstado_1, desc1);
    strcpy(objeto->descEstado_2, desc2);
    objeto->habitacion = habitacion;
    objeto->yaLoTengo = loTengo;
}



void InitGameData() {
    InitHabitacion(&habitaciones[1], 0, 4, 0, 0, "Estas en una pequenia habitacion pintada de blanco. \nJunto a ti puedes ver una cama y un velador.");
    InitHabitacion(&habitaciones[2], 0, 5, 0, 0, "Estas en una habitacion pintada de verde oscuro. \nJunto a ti puedes ver una cama grande y un velador con fotos de una familia.");
    InitHabitacion(&habitaciones[3], 0, 6, 0, 0, "Estas en el comedor de la casa. hay una mesa redonda.");
    InitHabitacion(&habitaciones[4], 1, 7, 5, 0, "Estas en un pasillo, las paredes son blancas y hay poca luz.");
    InitHabitacion(&habitaciones[5], 2, 8, 6, 4, "Estas en un pasillo, las paredes se ven aun mas oscuras.");
    InitHabitacion(&habitaciones[6], 3, 9, 0, 5, "Estas en un pasillo, ves muchos cuadros y libros.");    
    InitHabitacion(&habitaciones[7], 4, 0, 0, 0, "Estas en el banio, el lavamanos esta desordenado y el inodoro es cafe.");
    InitHabitacion(&habitaciones[8], 5, 0, 0, 0, "Estas en la entrada de la casa, la puerta se encuentra cerrada.");
    InitHabitacion(&habitaciones[9], 6, 0, 0, 0, "Estas en la cocina, hace frio, es grande y hay mucha luz.");

    InitObjeto(&objetos[HUESO], 1, 2, 0, "un hueso en suelo.", "un hueso en el suelo.");
    InitObjeto(&objetos[LLAVE], 1, 3, 0, "un reflejo de luz en lo alto, hay una llave sobre la lampara.", "un reflejo de luz en lo alto, hay una llave sobre la lampara.");
    InitObjeto(&objetos[ESCAL], 1, 9, 0, "una escalera apoyada en la pared.", "una escalera apoyada en la pared.");    InitObjeto(&objetos[PERRO], 1, 9, 0, "un perro desagradable y rabioso cerca de una escalera.", "un perro comiendose un hueso tranquilo.");
}

void TomarObjeto(Objeto* objeto, int posesionObjeto) {
    objeto->habitacion = 0;
    objeto->yaLoTengo = posesionObjeto;
}

void MostrarComandos() {
    printf("\n----- Como jugar / Comandos -----");
    printf("\nMoverse:           ir <direccion>          Ej: ir sur");
    printf("\nTomar objeto:      tomar <objeto>          Ej: tomar llave");
    printf("\nUsar objeto:       usar <objeto>           Ej: usar hueso");
    printf("\nSalir:             cerrar juego");
    printf("\nNum Habitacion:    mostrar habitacion");
    printf("\nZoom:              Ctrl + Rueda mouse");
    printf("\nMostrar ayuda:     mostrar ayuda");
    printf("\nVersion: v1.2.0 -- (c) Sara San Martin 2022");
}


int main(int argc, char** argv) {
    
    InitGameData();

    int habitacionActual = 1; // Comienzas en la habitacion 1
    int numeroDeObjetosEnEscena = 4;

    // Game Loop
    char verbo[30], nombreObjeto[30];
    int i, accion, vueltas;
    int juegoTerminado = 0;
    int indice = 0;
    int escaleraPuesta = 0;
    
    MostrarComandos();
    
    printf("\n\n\n__________________________________________________");
    printf("\n.:Bienvenid@ a la Casa Misteriosa:.");

    while (!juegoTerminado) {

        // Mostramos informacion de la habitacion en la que estamos
        printf("\n__________________________________________________");
        printf("\n\n%s", habitaciones[habitacionActual].descripcion);

        // ¿Hay algún objeto en la habitacion?
        for (i = 1; i <= numeroDeObjetosEnEscena; i++) {

            if (objetos[i].habitacion == habitacionActual) {

                printf("\n<O>!  Puedes ver ");

                if (objetos[i].estadoActual == 1)
                    printf("%s", objetos[i].descEstado_1);
                else
                    printf("%s", objetos[i].descEstado_2);
            }
        }

        // Posibles salidas
        printf("\n\nPuedes continuar por el: ");
        if (habitaciones[habitacionActual].norte != 0)
            printf("\n- norte");
        if (habitaciones[habitacionActual].sur != 0)
            printf("\n- sur");
        if (habitaciones[habitacionActual].este != 0)
            printf("\n- este");
        if (habitaciones[habitacionActual].oeste != 0)
            printf("\n- oeste");
        
        // Leer que quiere el jugador
        printf("\n>> ");
        scanf("%s%s", verbo, nombreObjeto);
        strlwr(verbo); strlwr(nombreObjeto);


        if (!strcmp(verbo, "mostrar") && !strcmp(nombreObjeto, "habitacion")) {
            printf("\n[Debug] Habitacion actual: ");
            printf("%d", habitacionActual);
        }

        // Mostrar comandos
        if (!strcmp(verbo, "mostrar") && !strcmp(nombreObjeto, "ayuda"))
            MostrarComandos();

        // Salir
        if (!strcmp(verbo, "cerrar") && !strcmp(nombreObjeto, "juego"))
            juegoTerminado = 1;

        // Tomar objeto
        if (!strcmp(verbo, "tomar")) {
            
            accion = 0;

            // Hueso
            if (!strcmp(nombreObjeto, "hueso") && objetos[HUESO].habitacion == habitacionActual) {
                
                accion = 1;
                TomarObjeto(&objetos[HUESO], 1);
                printf("\n((Te agachas y recoges el hueso.))");
            }
            
            // Llave
            if (!strcmp(nombreObjeto, "llave") && objetos[LLAVE].habitacion == habitacionActual && objetos[ESCAL].estadoActual == 2) {

                accion = 1;
                if (objetos[ESCALERA].yaLoTengo) {
                    TomarObjeto(&objetos[LLAVE], 1);
                    printf("\n((Das la espalda a la puerta y usas la escalera para subir, logras alcanzar la llave y tomarla.))");
                }
                else {
                    printf("\n((La llaves esta demasiado alta, no puedes alcanzarla.))");
                }
            }

            // Escaleras
            if (!strcmp(nombreObjeto, "escalera") && objetos[ESCALERA].habitacion == habitacionActual) {

                accion = 1;
                if (objetos[PERRO].estadoActual == 2) {
                    TomarObjeto(&objetos[ESCALERA], 1);
                    printf("\n((Te acercas a la escalera, haces fuerza y te la llevas contigo.))");
                }
                else {
                    printf("\n((El perro te ladra hostilmente, no te deja acercarte a la escalera.))");
                }
            }
            
            if (accion == 0)
                printf("\n((No puedes hacer eso.))");
        }

        if (!strcmp(verbo, "usar")) {
            accion = 0;

            // Llave
            if (!strcmp(nombreObjeto, "llave") && objetos[LLAVE].yaLoTengo && habitacionActual == 8) {
                accion = 1;
                printf("\n((Sientes una brisa en tu espalda, giras la llave y abres la puerta, afuera esta de noche, \nhay viento y hace frio. Pero haz logrado escapar, felicidades.))");

                objetos[LLAVE].yaLoTengo = 0;
                printf("\n\nMuchas gracias por jugar!\n- Juego hecho por Sara01.");
                juegoTerminado = 1;
            }

            // Hueso
            if (!strcmp(nombreObjeto, "hueso") 
                && objetos[HUESO].yaLoTengo && habitacionActual == 9) {

                accion = 1;
                objetos[HUESO].yaLoTengo = 0;
                objetos[PERRO].estadoActual = 2;
                printf("\n((El perro se lanza al hueso y se dirige a la esquina a mascarlo.))");
            }

            if (!strcmp(nombreObjeto, "escalera") 
                && objetos[ESCALERA].yaLoTengo && habitacionActual == 3) {

                accion = 1;
                objetos[ESCALERA].estadoActual = 2;
                printf("\n((Pones la escalera en la pared.))");
            }

            if (accion == 0)
                printf("\n((No puedes hacer eso.))");
        }

        if (!strcmp(verbo, "ir")) {
            accion = 0;

            if (!stricmp(nombreObjeto, "norte") && habitaciones[habitacionActual].norte != 0) {
                accion = 1;
                habitacionActual = habitaciones[habitacionActual].norte;
            }

            if (!stricmp(nombreObjeto, "sur") && habitaciones[habitacionActual].sur != 0) {
                accion = 1;
                habitacionActual = habitaciones[habitacionActual].sur;
            }

            if (!stricmp(nombreObjeto, "este") && habitaciones[habitacionActual].este != 0) {
                accion = 1;
                habitacionActual = habitaciones[habitacionActual].este;
            }

            if (!stricmp(nombreObjeto, "oeste") && habitaciones[habitacionActual].oeste != 0) {
                accion = 1;
                habitacionActual = habitaciones[habitacionActual].oeste;
            }

            if (accion == 0)
                printf("\n((No puedes ir hacia alli.))");
        }

    }

    getchar();
}
