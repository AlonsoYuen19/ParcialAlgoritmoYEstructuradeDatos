#pragma once
using namespace std;
template <class T>
class Nodo
{
private:
	Nodo<T>*siguiente;
	Nodo<T>*anterior;
	T dato;
public:
	Nodo(T valor) {
		dato = valor;
		siguiente = nullptr;
		anterior = nullptr;
	}
	~Nodo() {}
	Nodo<T>* get_siguiente() { return siguiente; }
	Nodo<T>* get_anterior() { return anterior; }
	T get_dato() { return dato; }
	void set_siguiente(Nodo<T>*siguiente) { this->siguiente = siguiente; }
	void set_anterior(Nodo<T>*anterior) { this->anterior = anterior; }
};
