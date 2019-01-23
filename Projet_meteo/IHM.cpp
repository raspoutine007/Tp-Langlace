//--------------------------------------------------------------------------//
//----- D�velopper par Vuillemenot Kevin -----------------------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet m�t�o --------------------------------------//
//----- Classe TForm1 (IHM) ------------------------------------------------//
//----- Comportement des m�thodes de la classe TForm1 (IHM) ----------------//
//--------------------------------------------------------------------------//

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


}

//---------------------------------------------------------------------------
void __fastcall TForm1::BtnServClick(TObject *Sender)
{
	serv= new Serveur(this,EdtIp->Text.c_str(),EdtPort->Text.ToInt());

	if(serv->Lancer())
	{
		Shape1->Brush->Color=clLime;
		MemoConnexions->Lines->Add("Le Serveur est lanc�.") ;
	}

	Timer1->Enabled = true ;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	if(carte->GetEtatConnexion())
	{
		Shape2->Brush->Color = clLime;
		temperature=carte->GetTemperature(2);
		Label5->Caption = temperature;
		serv->GetTemperature(temperature);

		if(serv->GetEtatClient())
		{
			MemoConnexions->Lines->Add(serv->Reception());
		}
	}

	else
	{
		Shape2->Brush->Color = clRed;
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BtnCarteClick(TObject *Sender)
{
	carte=new K8055(0);

	if(carte->GetEtatConnexion())
	{
		Shape2->Brush->Color = clLime;
	}

	else
	{
		Shape2->Brush->Color = clRed;
	}
}

//---------------------------------------------------------------------------

