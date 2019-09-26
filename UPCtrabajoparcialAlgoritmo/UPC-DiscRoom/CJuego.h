#pragma once
#pragma once

#include "CJugador.h"
#include "CVecDisco.h"
#include "CMapa.h"
#include "Cola.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
template <class I>
class CJuego
{
private:

	CJugador<I>* objJugador;
	CVecDisco* objVecDisco;

	CMapa<I>*objMapa;
	I Nivel;
	bool slow;
	float Contador;
	CLista<int>* GlitchX=new CLista<int>();
	CLista<int>* GlitchY=new CLista<int>();
public:
	CJuego(I anchoF, I largoF);
	~CJuego();
	void Dibujar(BufferedGraphics^Buffer, Graphics^g, Bitmap^img1, Bitmap^img2, Bitmap^img3);
	void MoverJugador(I AnchoF, I LargoF, BufferedGraphics^Buffer, Bitmap^bmp);
	void MoverDiscos(I AnchoF, I LargoF, I pX, I pY);
	int obtener(char c);
	void Ralentizar();
	void morir();
	void regresar();

	int get_NroVidas();
	void set_NroVidas(I NroVidas);
	float get_Contador();
	void set_Contador(float Contador);
	bool get_slow();
	void set_Nivel(I nivel);
	int get_Nivel();
	void set_direccion(Direcciones direccion);
	void SaveGame(char*fileName, vector<I>& vec);
	void LoadGame(char*fileName, vector<I>& vec);
	int ShowTiempo(const vector<I>& vec);
	int ShowNivel(const vector<I>& vec);
	 
	void saltarNivel();
	void RegistrarGlitch();
	void Glitch();
	void Guardar();
	void Cargar();
};
template <class I>
CJuego<I>::CJuego(I anchoF, I largoF)
{
	this->slow = true;

	Random^ r = gcnew Random(DateTime::Now.Ticks);
	objJugador = new CJugador<I>(100, 100, 35, 45, 8, 8, 0,5, false);
	objMapa = new CMapa<I>(500, 500, anchoF, largoF, 0);
	objVecDisco = new CVecDisco();

	Nivel = 1;

	this->Contador = 15;
	for (I i = 0; i < 2; i++)
	{
		
		I X = r->Next(400, 400);
		I Y = r->Next(200, 300);
		I Ancho = r->Next(25, 25);
		I Largo = r->Next(25, 25);
		I dX = r->Next(3, 8);
		I dY = r->Next(3, 8);
		I Indice = 0;
		I Tipo = r->Next(1, 1);
		objVecDisco->Agregar(X, Y, Ancho, Largo, dX, dY, Indice, Tipo);
	}

	

}
template <class I>
CJuego<I>::~CJuego() {}

template <class I>
void CJuego<I>::Dibujar(BufferedGraphics^Buffer,Graphics^g,Bitmap^img1,Bitmap^img2,Bitmap^img3)
{
	if (Contador != 0) {
	Contador-=0.1;
	}
	
	objMapa->dibujar(g, img2);
	
	if(Contador>0) {
		objVecDisco->Dibujar(g, img3);
	}
	
}
template <class I>
void CJuego<I>::MoverJugador(I AnchoF, I LargoF,BufferedGraphics^Buffer, Bitmap^bmp)
{
	objJugador->mover(AnchoF, LargoF,Buffer,bmp);
}
template <class I>
void CJuego<I>::MoverDiscos(I AnchoF, I LargoF, I pX, I pY)
{
	objVecDisco->Mover(AnchoF, LargoF, pX, pY);
	
	objVecDisco->GenerarColision(objJugador,AnchoF,LargoF);
}
template <class I>
int CJuego<I>::obtener(char c) {
	if (c == 'X') {
		return objJugador->Get_X();
	}
	else if (c == 'Y') {
		return objJugador->Get_Y();
	}
}
template <class I>
void CJuego<I>::Ralentizar() {
	objVecDisco->SlowMo(slow);
	if (slow == true)
		slow = false;
	else
		slow = true;
}
template <class I>
int CJuego<I>::get_Nivel() { return this->Nivel; }
template <class I>
void CJuego<I>::set_Nivel(I nivel) {this->Nivel = nivel;}
template <class I>
int CJuego<I>::get_NroVidas() { return objJugador->Get_NroVidas(); }
template <class I>
void CJuego<I>::set_NroVidas(I NroVidas) { objJugador->Set_NroVidas(NroVidas); }
template <class I>
float CJuego<I>::get_Contador() { return this->Contador; }
template <class I>
void CJuego<I>::set_Contador(float Contador) { this->Contador = Contador; }
template <class I>
bool CJuego<I>::get_slow() {return this->slow;}

template <class I>
void CJuego<I>::morir() {
	objVecDisco->EliminarTodos();
}
template <class I>
void CJuego<I>::regresar() {
	objJugador->Set_X(100);
	objJugador->Set_Y(100);
}

template <class I>
void CJuego<I>::set_direccion(Direcciones direccion) {
	objJugador->set_direccion(direccion);
}

template <class I>
void CJuego<I>::SaveGame(char* fileName, vector<I>& vec) {
	ofstream file; 
	file.open(fileName);

	if (file.good()) {
		
		for (auto i = vec.begin(); i != vec.end(); i++) {
			file << *i << " ";
		}
		file << endl;
		file.close();
	}
}
template <class I>
void CJuego<I>::LoadGame(char*fileName, vector<I>& vec)
{
	ifstream file; 
	file.open(fileName);
	if (file.good()) { 
		vec.clear();
		I value; 
		while (file >> value) { 
			vec.push_back(value);
		}
		file.close();
	}

}
template <class I>
int CJuego<I>::ShowTiempo(const vector<I>& vec) { 
	
	I i;
	I len = vec.size();
	if (len > 0) {
		for (auto i = vec.begin(); i != vec.end(); i++)
			cout << *i;
		cout << vec[len - 1];
	}
	return vec[i];
}
template <class I>
int CJuego<I>::ShowNivel(const vector<I>& vec) {
	I i;
	I len = vec.size();
	if (len > 0) {
		for (auto i = vec.begin(); i != vec.end(); i++)
			cout << *i;
		cout << vec[len - 1];
	}
	return vec[i+1];
}

template <class I>
void CJuego<I>::saltarNivel() {
	Random^ r = gcnew Random(DateTime::Now.Ticks);
	for (I i = 0; i < 2; i++)
	{

		I X = r->Next(400, 400);
		I Y = r->Next(200, 300);
		I Ancho = r->Next(25, 25);
		I Largo = r->Next(25, 25);
		I dX = r->Next(3, 8);
		I dY = r->Next(3, 8);
		I Indice = 0;
		I Tipo = r->Next(1, 2);
		objVecDisco->Agregar(X, Y, Ancho, Largo, dX, dY, Indice, Tipo);
	}

}
template<class I>
void CJuego<I>::RegistrarGlitch() {
	if (GlitchX->get_longitud() < 20) {
		GlitchX->push_back(objJugador->Get_X());
		GlitchY->push_back(objJugador->Get_Y());
	}
	else {
		GlitchX->pop_front();
		GlitchY->pop_front();
		GlitchX->push_back(objJugador->Get_X());
		GlitchY->push_back(objJugador->Get_Y());
	}

}

template<class I>
void CJuego<I>::Glitch() {
	objJugador->Set_X(GlitchX->get_inicio()->get_dato());
	objJugador->Set_Y(GlitchY->get_inicio()->get_dato());
}

template <class I>
void CJuego<I>::Guardar() {
	list<CDisco*>::iterator it;
	ofstream file("guardadito2.txt");
	file << objJugador->Get_NroVidas() << "," << objJugador->Get_X() << "," << objJugador->Get_Y() << "," << Contador << "," << Nivel;
	list<CDisco*> listadisco = objVecDisco->getListaDisco();
	for (it = listadisco.begin(); it != --listadisco.end(); ++it)
	{
		file << "," << listadisco.size() << "," << it.getNode()->data->Get_X() << "," << it.getNode()->data->Get_Y() << "," << it.getNode()->data->Get_Ancho() << "," << it.getNode()->data->Get_Largo() << ","
			<< it.getNode()->data->Get_dX() << "," << it.getNode()->data->Get_dY() << "," << it.getNode()->data->Get_Tipo();
	}
	cout << endl;
	file.close();
}
template <class I>
void CJuego<I>::Cargar() {
	objVecDisco->EliminarTodos();
	string temp, cadena;
	ifstream namay("guardadito2.txt");
	while (getline(namay, cadena))
	{
		stringstream filetemp(cadena);
		getline(filetemp, temp, ',');
		objJugador->Set_NroVidas(stoi(temp));
		getline(filetemp, temp, ',');
		objJugador->Set_X(stoi(temp));
		getline(filetemp, temp, ',');
		objJugador->Set_Y(stoi(temp));
		getline(filetemp, temp, ',');
		Contador = (stof(temp));
		getline(filetemp, temp, ',');
		Nivel = (stoi(temp));
		getline(filetemp, temp, ',');
		for (int i = 0; i < stoi(temp) - 1; i++)
		{
			int X, Y, Ancho, Largo, dX, dY, Tipo;
			getline(filetemp, temp, ',');
			X = (stoi(temp));
			getline(filetemp, temp, ',');
			Y = (stoi(temp));
			getline(filetemp, temp, ',');
			Ancho = (stoi(temp));
			getline(filetemp, temp, ',');
			Largo = (stoi(temp));
			getline(filetemp, temp, ',');
			dX = (stoi(temp));
			getline(filetemp, temp, ',');
			dY = (stoi(temp));
			getline(filetemp, temp);
			Tipo = (stoi(temp));
			CDisco* objDisco;
			if (Tipo == 1)
				objDisco = new CDiscoSpinning(X, Y, Ancho, Largo, dX, dY, 0, 1);
			else if (Tipo == 2)
				objDisco = new CDiscoPersecutor(X, Y, Ancho, Largo, dX, dY, 0, 2);
			objVecDisco->getListaDisco().push_back(objDisco);
		}
		objVecDisco->Namay = 1;
	}
	namay.close();
}
