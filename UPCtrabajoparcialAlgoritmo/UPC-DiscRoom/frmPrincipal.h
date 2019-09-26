#pragma once

#include "CJuego.h"

namespace UPCDiscRoom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
		/// <summary>
		/// Summary for frmPrincipal
		/// </summary>
		public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^C = gcnew SoundPlayer("ultraInstinto.wav");
		SoundPlayer^Menu = gcnew SoundPlayer("menu.wav");
		SoundPlayer^SoundTrack = gcnew SoundPlayer("soundtrack.wav");
		SoundPlayer^Teleport = gcnew SoundPlayer("teleport.wav");
		CJuego<int>* objJuego;
		
		Graphics^ g;
		Bitmap^img1;
		Bitmap^img2;
		Bitmap^img3;
		Bitmap^img4;
	
	


	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Label^  LTiempo;
	private: System::Windows::Forms::Label^  LNivel;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::Label^  LSCORE;
	private: System::Windows::Forms::Label^  LTIME;
	private: System::Windows::Forms::Label^  LNIVELITO;









			 BufferedGraphics^ buffer;
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmPrincipal::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->LTiempo = (gcnew System::Windows::Forms::Label());
			this->LNivel = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->LSCORE = (gcnew System::Windows::Forms::Label());
			this->LTIME = (gcnew System::Windows::Forms::Label());
			this->LNIVELITO = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &frmPrincipal::timer1_Tick);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(24, 24);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(283, 361);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->UseWaitCursor = true;
			this->pictureBox2->Visible = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(234, 270);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(73, 96);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(221, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(382, 424);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(-2, -2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(641, 483);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(476, 389);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"JUGAR";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmPrincipal::button1_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(0, 0);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(641, 483);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 5;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Visible = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(0, 0);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(641, 483);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 6;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Visible = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &frmPrincipal::pictureBox6_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(476, 425);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Cerrar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmPrincipal::button2_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(411, 146);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(100, 170);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox7->TabIndex = 8;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Visible = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &frmPrincipal::pictureBox7_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(476, 418);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(98, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"CLASIFICACION";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmPrincipal::button3_Click);
			// 
			// LTiempo
			// 
			this->LTiempo->AutoSize = true;
			this->LTiempo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(206)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->LTiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LTiempo->ForeColor = System::Drawing::Color::Transparent;
			this->LTiempo->Location = System::Drawing::Point(197, 270);
			this->LTiempo->Name = L"LTiempo";
			this->LTiempo->Size = System::Drawing::Size(83, 25);
			this->LTiempo->TabIndex = 12;
			this->LTiempo->Text = L"Tiempo";
			this->LTiempo->Visible = false;
			// 
			// LNivel
			// 
			this->LNivel->AutoSize = true;
			this->LNivel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(206)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->LNivel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LNivel->ForeColor = System::Drawing::Color::Transparent;
			this->LNivel->Location = System::Drawing::Point(443, 270);
			this->LNivel->Name = L"LNivel";
			this->LNivel->Size = System::Drawing::Size(60, 25);
			this->LNivel->TabIndex = 13;
			this->LNivel->Text = L"Nivel";
			this->LNivel->Visible = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(476, 418);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Regresar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &frmPrincipal::button4_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(0, 0);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(641, 483);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 15;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Visible = false;
			// 
			// LSCORE
			// 
			this->LSCORE->AutoSize = true;
			this->LSCORE->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(206)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->LSCORE->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LSCORE->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 36, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->LSCORE->ForeColor = System::Drawing::Color::Transparent;
			this->LSCORE->Location = System::Drawing::Point(182, 86);
			this->LSCORE->Name = L"LSCORE";
			this->LSCORE->Size = System::Drawing::Size(321, 57);
			this->LSCORE->TabIndex = 16;
			this->LSCORE->Text = L"SCOREBOARD";
			this->LSCORE->Visible = false;
			// 
			// LTIME
			// 
			this->LTIME->AutoSize = true;
			this->LTIME->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(206)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->LTIME->Font = (gcnew System::Drawing::Font(L"Open Sans", 14.25F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->LTIME->ForeColor = System::Drawing::Color::Transparent;
			this->LTIME->Location = System::Drawing::Point(187, 194);
			this->LTIME->Name = L"LTIME";
			this->LTIME->Size = System::Drawing::Size(55, 26);
			this->LTIME->TabIndex = 17;
			this->LTIME->Text = L"TIME";
			this->LTIME->Visible = false;
			// 
			// LNIVELITO
			// 
			this->LNIVELITO->AutoSize = true;
			this->LNIVELITO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(206)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->LNIVELITO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->LNIVELITO->ForeColor = System::Drawing::Color::Transparent;
			this->LNIVELITO->Location = System::Drawing::Point(423, 194);
			this->LNIVELITO->Name = L"LNIVELITO";
			this->LNIVELITO->Size = System::Drawing::Size(74, 24);
			this->LNIVELITO->TabIndex = 18;
			this->LNIVELITO->Text = L"LEVEL";
			this->LNIVELITO->Visible = false;
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(641, 483);
			this->Controls->Add(this->LNIVELITO);
			this->Controls->Add(this->LTIME);
			this->Controls->Add(this->LSCORE);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->LNivel);
			this->Controls->Add(this->LTiempo);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->KeyPreview = true;
			this->Name = L"frmPrincipal";
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmPrincipal::frmPrincipal_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &frmPrincipal::frmPrincipal_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
		objJuego = new CJuego<int>(this->ClientRectangle.Width,
			this->ClientRectangle.Height);
		g = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		buffer = context->Allocate(g, this->ClientRectangle);
		img1 = gcnew Bitmap(pictureBox1->Image);
		img1->MakeTransparent(img1->GetPixel(1, 1));
		img2 = gcnew Bitmap(pictureBox2->Image);
		img2->MakeTransparent(img2->GetPixel(1, 1));
		img3 = gcnew Bitmap(pictureBox3->Image);
		img3->MakeTransparent(img3->GetPixel(1, 1));
		img4 = gcnew Bitmap(pictureBox7->Image);
		img4->MakeTransparent(Color::White);
		//Musica en el Menu	
		Menu->PlayLooping();
		}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		int aux;
		vector<int> lista;
		const char* fileName = "guardadito.txt";
		aux = (int)objJuego->get_Contador();
		Text = L"Vidas: " + objJuego->get_NroVidas() + " | Tiempo : "+aux+
			"    | NIVEL " + objJuego->get_Nivel();
		buffer->Graphics->Clear(this->BackColor);
		objJuego->Dibujar(buffer,buffer->Graphics,img1,img2,img3);
		objJuego->MoverJugador(this->ClientRectangle.Width,
			this->ClientRectangle.Height,buffer, img4);
		
		objJuego->MoverDiscos(this->ClientRectangle.Width,
			this->ClientRectangle.Height,
			objJuego->obtener('X'), objJuego->obtener('Y'));
		buffer->Render(g);
		if (objJuego->get_NroVidas() == 0) {
			timer1->Stop();
			pictureBox5->Visible = true;
			lista.push_back(aux);
			lista.push_back(objJuego->get_Nivel());
			objJuego->SaveGame((char*) fileName,lista);
			Menu->PlayLooping();
			button2->Visible = true;
			button2->BringToFront();
		}
		if (objJuego->get_Nivel() == 6) {
				timer1->Stop();
				pictureBox6->Visible = true;
				lista.push_back((15)*5 - aux);
				lista.push_back(objJuego->get_Nivel()-1);
				objJuego->SaveGame((char*)fileName, lista);
				button2->Visible = true;
				button2->BringToFront();
				SoundTrack->Stop();
				Menu->PlayLooping();
			}
		if (objJuego->get_Contador() < 1&& objJuego->get_Nivel() < 5) {


			timer1->Stop();
			g->FillRectangle(Brushes::Black, 1, 1, this->ClientRectangle.Width, this->ClientRectangle.Height);
			g->DrawString("Nivel " + (objJuego->get_Nivel() + 1), gcnew System::Drawing::Font("Arial", 20), Brushes::White, 250, 200);
			objJuego->regresar();
			pictureBox1->Visible = false;
			pictureBox2->Visible = false;
			pictureBox3->Visible = false;
			pictureBox4->Visible = false;
			timer1->Start();

		}
		if (objJuego->get_Contador()< 0) {
			objJuego->saltarNivel();
			objJuego->set_Nivel(objJuego->get_Nivel()+1);
			objJuego->set_NroVidas(8);
			objJuego->set_Contador(15);
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		button1->Visible = false;
		button3->Visible = false;
		pictureBox4->Visible = false;
		Menu->Stop();
		SoundTrack->PlayLooping();
		timer1->Start();

	
	}
	private: System::Void frmPrincipal_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if (e->KeyData == Keys::Right) {
			objJuego->set_direccion(Direcciones::Derecha);
			objJuego->RegistrarGlitch();
			
		}

		else if (e->KeyData == Keys::Left) {
			objJuego->set_direccion(Direcciones::Izquierda);
			objJuego->RegistrarGlitch();
		}
		else if (e->KeyData == Keys::Down) {
			objJuego->set_direccion(Direcciones::Abajo);
			objJuego->RegistrarGlitch();
		}
		else if (e->KeyData == Keys::Up) {
			objJuego->set_direccion(Direcciones::Arriba);
			objJuego->RegistrarGlitch();
		}
		//cancion del ultrainstinto
		else if (e->KeyData == Keys::C) {
			if (objJuego->get_slow() == true) {
				SoundTrack->Stop();
				C->PlayLooping();
			}
			else {
				C->Stop();
				SoundTrack->Play();
			}
			objJuego->Ralentizar();
		}
		//CANCIon de la teletransportacion
		else if (e->KeyData == Keys::R) {
			objJuego->Glitch();
			Teleport->Play();	
		}
		//reanudar cancion del menu Tecla 'E'
		else if (e->KeyData == Keys::E)
		{
			Teleport->Stop();
			SoundTrack->Play();
		}
		else if (e->KeyData == Keys::G) {
			objJuego->Guardar();
		}
		else if (e->KeyData == Keys::T) {
			objJuego->Cargar();
		}
	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//Music2->Stop();
	
	Close();
}
private: System::Void frmPrincipal_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	objJuego->set_direccion(Direcciones::Ninguna);
}

private: System::Void pictureBox7_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox6_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	pictureBox2->Visible = false;
	pictureBox3->Visible = false;
	pictureBox4->Visible = false;
	pictureBox8->Visible = true;
	button3->Visible = false;
	button1->Visible = false;

	LSCORE->Visible = true;
	LTIME->Visible = true;
	LNIVELITO->Visible = true;
	LTiempo->Visible = true;
	LNivel->Visible = true;
	button4->Visible = true;
	

	
    vector<int> lista;
	const char* fileName = "guardadito.txt";
	objJuego->LoadGame((char*)fileName, lista);
	
	LTiempo->Text = " " + objJuego->ShowTiempo(lista);
	LNivel->Text = " " + objJuego->ShowNivel(lista);
}
private: System::Void pictureBox8_Click(System::Object^  sender, System::EventArgs^  e) {
	pictureBox8->Visible = false;
	LSCORE->Visible = true;
	LTIME->Visible = true;
	LNIVELITO->Visible = true;
	LTiempo->Visible = true;
	LNivel->Visible = true;
	button4->Visible = true;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	pictureBox2->Visible = false;
	button4->Visible = false;
	pictureBox8->Visible = false;
	pictureBox3->Visible = false;
	pictureBox4->Visible = true;

	
	button3->Visible = true;
	button1->Visible = true;

	LSCORE->Visible = false;
	LTIME->Visible = false;
	LNIVELITO->Visible = false;
	LTiempo->Visible = false;
	LNivel->Visible = false;


}

};
}
