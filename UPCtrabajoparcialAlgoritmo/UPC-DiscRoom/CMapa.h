#pragma once
using namespace System;
using namespace System::Drawing;
#define N_FRAMES02 1
template <class T>
class CMapa
{
private:
	T X, Y;
	T ANCHO, LARGO;
	T INDICE;
public:
	CMapa();
	~CMapa();
	CMapa(T X, T Y, T ANCHO, T LARGO, T INDICE);
	void dibujar(Graphics^g, Bitmap^img2);

};
template <class T>
CMapa<T>::CMapa() {}
template <class T>
CMapa<T>::~CMapa() {}
template <class T>
CMapa<T>::CMapa(T X, T Y, T ANCHO, T LARGO, T INDICE) 
{
	this->X = 1;
	this->Y = 1;
	this->ANCHO = ANCHO;
	this->LARGO = LARGO;
	this->INDICE = 0;

}
template <class T>
void CMapa<T>::dibujar(Graphics^g, Bitmap^img2)
{
	int AnchoI, LargoI;


	AnchoI = img2->Width / N_FRAMES02;
	LargoI = img2->Height;

	Rectangle Origen = Rectangle(AnchoI * INDICE, 0, AnchoI, LargoI);
	Rectangle Destino = Rectangle(X, Y, ANCHO, LARGO);

	g->DrawImage(img2, Destino, Origen, GraphicsUnit::Pixel);

	if (INDICE == N_FRAMES02 - 1)
		INDICE = 0;
	else
		INDICE++;
}


