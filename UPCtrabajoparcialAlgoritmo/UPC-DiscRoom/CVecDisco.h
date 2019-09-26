#pragma once

#include "CDisco.h"
#include "lista.hpp"
#include <vector>
#include "CJugador.h"
using namespace std;

class CVecDisco
{
private:
	list<CDisco*> listaDisco;
public:
	bool Namay = 0;
	CVecDisco();
	~CVecDisco();
	void Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY, int Indice, int Tipo);
	void Mover(int AnchoF, int LargoF, int pX, int pY);
	void Dibujar(Graphics^ g, Bitmap^img3);
	list<CDisco*> getListaDisco();
	void setListaDisco(list<CDisco*> ga);
	void GenerarColision(CJugador<int>* objJugador, int AnchoF, int LargoF);
	void SlowMo(bool r);
	void EliminarTodos();
};

CVecDisco::CVecDisco() {}
CVecDisco::~CVecDisco() {}
void CVecDisco::Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY, int Indice, int Tipo)
{
	CDisco* objDisco;
	if (Tipo == 1)
		objDisco = new CDiscoSpinning(X, Y, Ancho, Largo, dX, dY, Indice, 1);
	else if (Tipo == 2)
		objDisco = new CDiscoPersecutor(X, Y, Ancho, Largo, dX, dY, Indice, 2);
	listaDisco.push_back(objDisco);
}
void CVecDisco::Mover(int AnchoF, int LargoF, int pX, int pY)
{
	list<CDisco*>::iterator it;
	for (auto it = listaDisco.begin(); it != listaDisco.end(); ++it)
		it.getNode()->data->Mover(AnchoF, LargoF, pX, pY);
}

list<CDisco*> CVecDisco::getListaDisco() {
	return listaDisco;
}
void CVecDisco::setListaDisco(list<CDisco*> ga) {
	listaDisco = ga;
}
void CVecDisco::Dibujar(Graphics^ g, Bitmap^img3)
{
	list<CDisco*>::iterator it;
	if (Namay == 1) {
		for (auto it = listaDisco.begin(); it != listaDisco.end(); ++it)
			it.getNode()->data->Dibujar(g, img3);
	}
	for (auto it = listaDisco.begin(); it != listaDisco.end(); ++it)
		it.getNode()->data->Dibujar(g, img3);
}
void getDisco() {

}
void CVecDisco::GenerarColision(CJugador<int>* objJugador, int AnchoF, int LargoF)
{
	list<CDisco*>::iterator it;
	for (auto it = listaDisco.begin(); it != listaDisco.end(); ++it)
		if ((it.getNode()->data->HayColision(objJugador->Get_X(), objJugador->Get_Y(), objJugador->Get_Ancho(), objJugador->Get_Largo())
			||
			objJugador->HayColision(it.getNode()->data->Get_X(), it.getNode()->data->Get_Y(), it.getNode()->data->Get_Ancho(), it.getNode()->data->Get_Largo())))
		{
			objJugador->Set_NroVidas(objJugador->Get_NroVidas() - 1);
			Random^ r = gcnew Random(DateTime::Now.Ticks);
			int X = r->Next(AnchoF / 10, (AnchoF * 9 / 10) - objJugador->Get_Ancho());
			int Y = r->Next(LargoF / 10, (LargoF * 9 / 10) - objJugador->Get_Largo());
			objJugador->Set_X(X);
			objJugador->Set_Y(Y);
		}

}
void CVecDisco::SlowMo(bool r) {
	list<CDisco*>::iterator it;
	if (r == true) {
		for (auto it = listaDisco.begin(); it != listaDisco.end(); ++it)
		{
			it.getNode()->data->set_dx(it.getNode()->data->Get_dX() / 3);
			it.getNode()->data->set_dy(it.getNode()->data->Get_dY() / 3);
		}
	}
	else {
		for (auto it = listaDisco.begin(); it != listaDisco.end(); ++it)
		{
			it.getNode()->data->set_dx(it.getNode()->data->Get_dX() * 3);
			it.getNode()->data->set_dy(it.getNode()->data->Get_dY() * 3);
		}
	}
}
void CVecDisco::EliminarTodos()
{
	list<CDisco*>::iterator it;
	for (auto it = listaDisco.begin(); it != listaDisco.end();)
	{
		it = listaDisco.erase(it);
	}
}