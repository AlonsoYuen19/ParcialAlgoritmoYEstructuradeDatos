#pragma once

#define N_FRAMES03 1

using namespace System;
using namespace System::Drawing;

class CDisco
{
protected:
	int X, Y;
	int Ancho, Largo;
	int dX, dY;
	int Indice;
	int Tipo;
public:
	CDisco();
	CDisco(int X, int Y, int Ancho, int Largo, int dX, int dY, int Indice, int Tipo);
	~CDisco();
	virtual void Mover(int AnchoF, int LargoF, int pX, int pY) {};
	virtual void Dibujar(Graphics^ g, Bitmap^img3) {};
	bool HayColision(int pX, int pY);
	bool HayColision(int pX, int pY, int pAncho, int pLargo);
	int Get_X();
	int Get_Y();
	int Get_dX();
	int Get_dY();
	int Get_Tipo();
	int Get_Ancho();
	int Get_Largo();
	void set_dx(int dX);
	void set_dy(int dY);
};

CDisco::CDisco() {}
CDisco::CDisco(int X, int Y, int Ancho, int Largo, int dX, int dY, int Indice, int Tipo)
{
	this->X = X;
	this->Y = Y;
	this->Ancho = Ancho;
	this->Largo = Largo;
	this->dX = dX;
	this->dY = dY;
	this->Indice = 0;
	this->Tipo = Tipo;
}
CDisco::~CDisco() {}
bool CDisco::HayColision(int pX, int pY)
{
	return pX >= X && pX <= X + Ancho &&
		pY >= Y && pY <= Y + Largo;
}
bool CDisco::HayColision(int pX, int pY, int pAncho, int pLargo)
{
	return HayColision(pX, pY) ||
		HayColision(pX + pAncho, pY) ||
		HayColision(pX, pY + pLargo) ||
		HayColision(pX + pAncho, pY + pLargo);
}
int CDisco::Get_X()
{
	return this->X;
}
int CDisco::Get_Y()
{
	return this->Y;
}
int CDisco::Get_Ancho()
{
	return this->Ancho;
}
int CDisco::Get_Largo()
{
	return this->Largo;
}
void CDisco::set_dx(int dX) { this->dX = dX; }
void CDisco::set_dy(int dY) { this->dY = dY; }
int CDisco::Get_Tipo() { return this->Tipo; }
int CDisco::Get_dX() { return this->dX; }
int CDisco::Get_dY() { return this->dY; }
class CDiscoSpinning : public CDisco
{
private:

public:
	CDiscoSpinning();
	CDiscoSpinning(int X, int Y, int Ancho, int Largo, int dX, int dY, int Indice, int Tipo);
	~CDiscoSpinning();
	void Mover(int AnchoF, int LargoF, int pX, int pY);
	void Dibujar(Graphics^ g, Bitmap^img3);
};

CDiscoSpinning::CDiscoSpinning() {}
CDiscoSpinning::CDiscoSpinning(int X, int Y, int Ancho, int Largo, int dX, int dY, int Indice, int Tipo)
	: CDisco(X, Y, Ancho, Largo, dX, dY, Indice, Tipo)
{}
CDiscoSpinning::~CDiscoSpinning() {}
void CDiscoSpinning::Mover(int AnchoF, int LargoF, int pX, int pY)
{
	if (X + dX < (AnchoF / 10) || X + dX + Ancho > AnchoF - (AnchoF / 10))
		dX *= -1;
	if (Y + dY < (LargoF / 10) || Y + dY + Largo > LargoF - (LargoF / 10))
		dY *= -1;

	X += dX;
	Y += dY;
}
void CDiscoSpinning::Dibujar(Graphics^ g, Bitmap^img3)
{
	int AnchoI, LargoI;


	AnchoI = img3->Width / N_FRAMES03;
	LargoI = img3->Height;




	Rectangle Origen = Rectangle(AnchoI * Indice, 0, AnchoI, LargoI);
	Rectangle Destino = Rectangle(X, Y, Ancho, Largo);


	g->DrawImage(img3, Destino, Origen, GraphicsUnit::Pixel);


	if (Indice == N_FRAMES03 - 1)
		Indice = 0;

	else
		Indice++;
	//g->FillEllipse(Brushes::Green, X, Y, Ancho, Largo);
}

class CDiscoPersecutor : public CDisco
{
private:

public:
	CDiscoPersecutor();
	CDiscoPersecutor(int X, int Y, int Ancho, int Largo, int dX, int dY, int Indice, int Tipo);
	~CDiscoPersecutor();
	void Mover(int AnchoF, int LargoF, int pX, int pY);
	void Dibujar(Graphics^ g, Bitmap^img3);
};

CDiscoPersecutor::CDiscoPersecutor() {}
CDiscoPersecutor::CDiscoPersecutor(int X, int Y, int Ancho, int Largo, int dX, int dY, int Indice, int Tipo)
	: CDisco(X, Y, Ancho, Largo, dX, dY, Indice, Tipo)
{}
CDiscoPersecutor::~CDiscoPersecutor() {}
void CDiscoPersecutor::Mover(int AnchoF, int LargoF, int pX, int pY)
{
	if (X + dX < (AnchoF / 10) || X + dX + Ancho > AnchoF - (AnchoF / 10) || (dX > 0 && pX < X) || (dX<0 && pX>X))
		dX *= -1;
	if (Y + dY < (LargoF / 10) || Y + dY + Largo > LargoF - (LargoF / 10) || (dY > 0 && pY < Y) || (dY<0 && pY>Y))
		dY *= -1;

	X += dX;
	Y += dY;
}
void CDiscoPersecutor::Dibujar(Graphics^ g, Bitmap^img3)
{

	int AnchoI, LargoI;


	AnchoI = img3->Width / N_FRAMES03;
	LargoI = img3->Height;




	Rectangle Origen = Rectangle(AnchoI * Indice, 0, AnchoI, LargoI);
	Rectangle Destino = Rectangle(X, Y, Ancho, Largo);


	g->DrawImage(img3, Destino, Origen, GraphicsUnit::Pixel);


	if (Indice == N_FRAMES03 - 1)
		Indice = 0;

	else
		Indice++;

}















