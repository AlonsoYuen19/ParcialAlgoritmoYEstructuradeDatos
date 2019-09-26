#pragma once
#include "CNodo.h"
template<class T>
class CLista
{
private:
	Nodo<T>*inicio;
	int longitud;
public:
	CLista() {
		inicio = nullptr;
		longitud = 0;
	}
	~CLista() {}
	void push_back(T v) {
		Nodo<T>*nodo = new Nodo<T>(v);
		if (longitud == 0) {
			inicio = nodo;
		}
		else if (longitud == 1) {
			inicio->set_siguiente(nodo);
			inicio->set_anterior(nodo);
			nodo->set_anterior(inicio);
			nodo->set_siguiente(inicio);
		}
		else if (longitud > 1) {
			nodo->set_anterior(inicio->get_anterior());
			inicio->get_anterior()->set_siguiente(nodo);
			nodo->set_siguiente(inicio);
			inicio->set_anterior(nodo);
		}
		longitud++;
	}
	void pop_front() {
		if (longitud == 1) {
			delete inicio->get_siguiente();
			inicio = nullptr;
			longitud--;
		}
		else if (longitud > 1) {
			inicio = inicio->get_siguiente();
			inicio->set_anterior(inicio->get_anterior()->get_anterior());
			inicio->get_anterior()->get_siguiente()->set_anterior(nullptr);
			inicio->get_anterior()->get_siguiente()->set_siguiente(nullptr);
			delete inicio->get_anterior()->get_siguiente();
			inicio->get_anterior()->set_siguiente(inicio);
			longitud--;
		}

	}
	int get_longitud() { return longitud; }
	
	Nodo<T>* get_inicio() {
		return inicio;
	}
};
