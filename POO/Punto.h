// archivo header file (.h extension)
class Punto {

    friend void modificar(Punto &, int, int); // función amiga

    private:
        int _x, _y;

    public:
        Punto(int x, int y) {
            _x = x;
            _y = y;
        }

        Punto() {
            _x = _y = 0;
        }

        // cuando creamos objetos se almacenan en la memoria, cuando el programa
        // finaliza, se puede liberar la memoria usando el destructor!
        ~Punto() { }; // Método destructor

        void setX(int valorX);
        void setY(int valorY);

        int getX();
        int getY();

        void datos();
};