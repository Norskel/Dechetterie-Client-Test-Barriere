#pragma once
#include "Client.h"
#include "Protocole\StructTypeMessage.h"
#include "Protocole\Protocole.h"



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(Client^ cl)
		{
			InitializeComponent();
			_cl = cl;
			
			//listTMsg = ltm;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		Client^ _cl;
		Protocole^ p = Protocole::getProtocole();
		TypeMessage^ _TM = gcnew TypeMessage();
		Boolean acces = false;
		


		//List<TypeMessage^>^ listTMsg;
	private: System::Windows::Forms::Timer^  timerUpdate;
	private: System::Windows::Forms::GroupBox^  gbBarriere;


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::CheckBox^  cbBarriere;

	protected:
		Boolean stateCl = false;
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:


	protected:

	private: System::Windows::Forms::GroupBox^  gBConnection;
	private: System::Windows::Forms::Label^  l2;
	private: System::Windows::Forms::Label^  l1;
	private: System::Windows::Forms::TextBox^  tbIP;
	private: System::Windows::Forms::Label^  state;
	private: System::Windows::Forms::NumericUpDown^  nUDPort;
	private: System::Windows::Forms::Button^  btConnect;
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
			this->gBConnection = (gcnew System::Windows::Forms::GroupBox());
			this->l2 = (gcnew System::Windows::Forms::Label());
			this->l1 = (gcnew System::Windows::Forms::Label());
			this->tbIP = (gcnew System::Windows::Forms::TextBox());
			this->state = (gcnew System::Windows::Forms::Label());
			this->nUDPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->btConnect = (gcnew System::Windows::Forms::Button());
			this->timerUpdate = (gcnew System::Windows::Forms::Timer(this->components));
			this->gbBarriere = (gcnew System::Windows::Forms::GroupBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->cbBarriere = (gcnew System::Windows::Forms::CheckBox());
			this->gBConnection->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDPort))->BeginInit();
			this->gbBarriere->SuspendLayout();
			this->SuspendLayout();
			// 
			// gBConnection
			// 
			this->gBConnection->Controls->Add(this->l2);
			this->gBConnection->Controls->Add(this->l1);
			this->gBConnection->Controls->Add(this->tbIP);
			this->gBConnection->Controls->Add(this->state);
			this->gBConnection->Controls->Add(this->nUDPort);
			this->gBConnection->Controls->Add(this->btConnect);
			this->gBConnection->Location = System::Drawing::Point(12, 12);
			this->gBConnection->Name = L"gBConnection";
			this->gBConnection->Size = System::Drawing::Size(386, 100);
			this->gBConnection->TabIndex = 2;
			this->gBConnection->TabStop = false;
			this->gBConnection->Text = L"Connection";
			// 
			// l2
			// 
			this->l2->AutoSize = true;
			this->l2->Location = System::Drawing::Point(193, 20);
			this->l2->Name = L"l2";
			this->l2->Size = System::Drawing::Size(26, 13);
			this->l2->TabIndex = 5;
			this->l2->Text = L"Port";
			// 
			// l1
			// 
			this->l1->AutoSize = true;
			this->l1->Location = System::Drawing::Point(72, 20);
			this->l1->Name = L"l1";
			this->l1->Size = System::Drawing::Size(17, 13);
			this->l1->TabIndex = 4;
			this->l1->Text = L"IP";
			// 
			// tbIP
			// 
			this->tbIP->Location = System::Drawing::Point(72, 38);
			this->tbIP->Name = L"tbIP";
			this->tbIP->Size = System::Drawing::Size(100, 20);
			this->tbIP->TabIndex = 3;
			// 
			// state
			// 
			this->state->AutoSize = true;
			this->state->BackColor = System::Drawing::Color::Red;
			this->state->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->state->ForeColor = System::Drawing::Color::White;
			this->state->Location = System::Drawing::Point(15, 38);
			this->state->Name = L"state";
			this->state->Size = System::Drawing::Size(41, 20);
			this->state->TabIndex = 2;
			this->state->Text = L"OFF";
			this->state->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// nUDPort
			// 
			this->nUDPort->Location = System::Drawing::Point(193, 38);
			this->nUDPort->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65525, 0, 0, 0 });
			this->nUDPort->Name = L"nUDPort";
			this->nUDPort->Size = System::Drawing::Size(65, 20);
			this->nUDPort->TabIndex = 1;
			// 
			// btConnect
			// 
			this->btConnect->Location = System::Drawing::Point(279, 38);
			this->btConnect->Name = L"btConnect";
			this->btConnect->Size = System::Drawing::Size(75, 20);
			this->btConnect->TabIndex = 0;
			this->btConnect->Text = L"Connect";
			this->btConnect->UseVisualStyleBackColor = true;
			this->btConnect->Click += gcnew System::EventHandler(this, &MyForm::btConnect_Click);
			// 
			// timerUpdate
			// 
			this->timerUpdate->Enabled = true;
			this->timerUpdate->Tick += gcnew System::EventHandler(this, &MyForm::timerUpdate_Tick);
			// 
			// gbBarriere
			// 
			this->gbBarriere->Controls->Add(this->cbBarriere);
			this->gbBarriere->Location = System::Drawing::Point(12, 118);
			this->gbBarriere->Name = L"gbBarriere";
			this->gbBarriere->Size = System::Drawing::Size(386, 100);
			this->gbBarriere->TabIndex = 4;
			this->gbBarriere->TabStop = false;
			this->gbBarriere->Text = L"Barrière";
			// 
			// cbBarriere
			// 
			this->cbBarriere->AutoSize = true;
			this->cbBarriere->Location = System::Drawing::Point(53, 42);
			this->cbBarriere->Name = L"cbBarriere";
			this->cbBarriere->Size = System::Drawing::Size(45, 17);
			this->cbBarriere->TabIndex = 0;
			this->cbBarriere->Text = L"Etat";
			this->cbBarriere->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(412, 228);
			this->Controls->Add(this->gbBarriere);
			this->Controls->Add(this->gBConnection);
			this->Name = L"MyForm";
			this->Text = L"Client Balance";
			this->gBConnection->ResumeLayout(false);
			this->gBConnection->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDPort))->EndInit();
			this->gbBarriere->ResumeLayout(false);
			this->gbBarriere->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btConnect_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			stateCl = _cl->Connect(IPAddress::Parse(tbIP->Text), (int)nUDPort->Value);
		}
		catch (...)
		{
			stateCl = _cl->Connect(IPAddress::Parse(tbIP->Text), (int)nUDPort->Value);
		}

	}
	private: System::Void timerUpdate_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (stateCl)
		{
			state->Text = "ON";
			state->BackColor = Color::Lime;
			gBConnection->Enabled = false;

			try
			{
				Socket^ cl = _cl->getSocket();
				ProtocolMsg^ pm = gcnew ProtocolMsg();

				array<Byte>^ buffer = gcnew array<Byte>(512);
				cl->Receive(buffer);
				pm = p->translateReceive(buffer);
				

				if (pm->type == p->GetTypeProtocoleByID("brOuvre"))
				{
					cbBarriere->Checked = true;
				}
				else
				{
					if (pm->type == p->GetTypeProtocoleByID("brFerme"))
					{
						cbBarriere->Checked = false;
					}
					else
					{
						if (pm->type == p->GetTypeProtocoleByID("brDEtat"))
						{
							cl->Send(p->RetourGetEtatBarriere(cbBarriere->Checked));
						}
					}
				}


			}
			catch (...)
			{

			}

		}
		else
		{
			state->Text = "OFF";
			state->BackColor = Color::Red;
			gBConnection->Enabled = true;
		}


	}

	

};







