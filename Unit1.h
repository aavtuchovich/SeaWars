//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TDrawGrid *DrawGrid1;
	TDrawGrid *DrawGrid2;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button1;
	TTimer *Timer1;
	TMainMenu *MainMenu1;
	TMenuItem *Buhf1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TLabel *Label3;
	TLabel *Label4;
	TMenuItem *N4;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DrawGrid2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
