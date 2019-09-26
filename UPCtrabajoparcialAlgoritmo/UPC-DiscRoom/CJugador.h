#pragma once

using namespace System;
using namespace System::Drawing; 
enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha };
#define N_FRAMES01 1
template <class I>
class CJugador
{
private:
	I X, Y;
	I dX, dY;
	I Ancho, Largo;
	I Indice;
	I NroVidas;
	bool Eliminado;
	Direcciones ultimaTecla;
	I indiceX, indiceY;

	
public:
	CJugador();
	CJugador(I X, I Y, I Ancho, I Largo, I dX, I dY, I Indice,I NroVidas,bool Eliminado);
	~CJugador();
	void Dibujar(BufferedGraphics^buffer,Bitmap^img1, I anchoF, I largoF);
	void mover(I AnchoF, I LargoF, BufferedGraphics^Buffer, Bitmap^bmp);
	bool HayColision(I pX, I pY);
	bool HayColision(I pX, I pY, I pAncho, I pLargo);
	int Get_NroVidas();
	void Set_NroVidas(I NroVidas);
	int Get_X();
	int Get_Y();
	void Set_X(I X);
	void Set_Y(I Y);
	int Get_Ancho();
	int Get_Largo();
	bool get_Eliminado();
	void set_Eliminado(bool Eliminado);
	Direcciones direccion;
	void set_direccion(Direcciones direccion);

};
template <class I>
CJugador<I>::CJugador() {}
template <class I>
CJugador<I>::CJugador(I X, I Y,I Ancho, I Largo,I Indice, I NroVidas, I dX, I dY,bool Elimando)
{
	Random^ r = gcnew Random(DateTime::Now.Ticks);
	
	this->X = X;
	this->Y = Y;
	this->Ancho = 25;
	this->Largo = 39; 
	this->Indice = 0;
	this->NroVidas = NroVidas;
    this->dX = 0;
	this->dY = 0;
	this->Eliminado = false;
	this->ultimaTecla = Direcciones::Abajo;
	this->direccion = Direcciones::Ninguna;
	this->indiceX = 0;
	this->indiceY = 0;
}
template <class I>
CJugador<I>::~CJugador() {}
template <class I>
void CJugador<I>::Dibujar(BufferedGraphics^Buffer, Bitmap^bmp, I AnchoF, I LargoF)
{
	
	Rectangle porcionAUsar = Rectangle(indiceX*Ancho, indiceY*Largo, Ancho, Largo);
	Rectangle aumentoPersonaje = Rectangle(X, Y, Ancho*1.5, Largo*1.5);
	Buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionAUsar, GraphicsUnit::Pixel);
	if (direccion == Derecha && X + dX + (AnchoF / 10) < AnchoF - Ancho) // HACIA LA DERECHA
		X += dX;
	else if (direccion == Izquierda && X - dX - (AnchoF / 10) > 0) // HACIA LA IZQUIERDA
		X += dX;
	else if (direccion == Abajo && Y + dY + (LargoF / 10) < LargoF - Largo) // HACIA ABAJO
		Y += dY;
	else if (direccion == Arriba && Y - dY - (LargoF / 10) > 0) // HACIA ARRIBA
		Y += dY;
}
template <class I>
void CJugador<I>::mover(I AnchoF, I LargoF,BufferedGraphics^Buffer, Bitmap^bmp)
{
	switch (direccion)
	{
	case Direcciones::Arriba:
		indiceX = 2;
		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		dX = 0;
		dY = -10;
		ultimaTecla = Arriba;
		break;
	case Direcciones::Abajo:
		indiceX = 0;
		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		dX = 0;
		dY = 10;
		ultimaTecla = Abajo;
		break;
	case Direcciones::Izquierda:
		indiceX = 1;
		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		dX = -10;
		dY = 0;
		ultimaTecla = Izquierda;
		break;
	case Direcciones::Derecha:
		indiceX = 3;
		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		dX = 10;
		dY = 0;
		ultimaTecla = Derecha;
		break;
	case Direcciones::Ninguna:

		dX = 0;
		dY = 0;
		switch (ultimaTecla) {
		case Direcciones::Abajo:
			indiceX = 0;
			indiceY = 0;
			break;
		case Direcciones::Izquierda:
			indiceX = 1;
			indiceY = 0;
			break;
		case Direcciones::Arriba:
			indiceX = 2;
			indiceY = 0;
			break;
		case Direcciones::Derecha:
			indiceX = 3;
			indiceY = 0;
			break;
		}
		break;
	}
	Dibujar(Buffer, bmp,AnchoF,LargoF);
}

template <class I>
bool CJugador<I>::HayColision(I pX, I pY)
{
	return pX >= X && pX <= X + Ancho &&
		pY >= Y && pY <= Y + Largo;
}
template <class I>
bool CJugador<I>::HayColision(I pX, I pY, I pAncho, I pLargo)
{
	return HayColision(pX, pY) ||
		HayColision(pX + pAncho, pY) ||
		HayColision(pX, pY + pLargo) ||
		HayColision(pX + pAncho, pY + pLargo);
}
template <class I>
int CJugador<I>::Get_NroVidas()
{
	return this->NroVidas;
}
template <class I>
void CJugador<I>::Set_NroVidas(I NroVidas)
{
	Random^ r = gcnew Random(DateTime::Now.Ticks);
	this->NroVidas = NroVidas;
}
template <class I>
int CJugador<I>::Get_X()
{
	return this->X;
}
template <class I>
int CJugador<I>::Get_Y()
{
	return this->Y;
}
template <class I>
int CJugador<I>::Get_Ancho()
{
	return this->Ancho;
}
template <class I>
int CJugador<I>::Get_Largo()
{
	return this->Largo;
}
template <class I>
bool CJugador<I>::get_Eliminado() {
	return this->Eliminado;
}
template <class I>
void CJugador<I>::set_Eliminado(bool Eliminado) {
	this->Eliminado = Eliminado;
}
template <class I>
void CJugador<I>::Set_X(I X){this->X=X;}
template <class I>
void CJugador<I>::Set_Y(I Y){this->Y=Y;}
template <class I>
void CJugador<I>::set_direccion(Direcciones direccion) {
	this->direccion = direccion;
}