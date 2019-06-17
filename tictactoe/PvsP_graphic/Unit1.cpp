//---------------------------------------------------------------------------
#include <iostream>

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        char p1,p2,p3,p4,p5,p6,p7,p8,p9;
        //p1...p9 pola w grze (ich zawartosc: p1='n')

        char kto;       //czyja tura?

        void check()
        {
                char* w;
                if(p1 != 'n' && p2 != 'n' && p3 != 'n' &&
                   p4 != 'n' && p5 != 'n' && p6 != 'n' &&
                   p7 != 'n' && p8 != 'n' && p9 != 'n')
                   {
                        w = "REMIS!";
                        Application->MessageBox(w, "Koniec gry!", MB_OK);
                   }

                if(     (p1 == p2 && p2 == p3 && p3 != 'n') ||
                        (p4 == p5 && p5 == p6 && p6 != 'n') ||
                        (p7 == p8 && p8 == p9 && p9 != 'n') ||
                        (p1 == p4 && p4 == p7 && p7 != 'n') ||
                        (p2 == p5 && p5 == p8 && p8 != 'n') ||
                        (p3 == p6 && p6 == p9 && p9 != 'n') ||
                        (p1 == p5 && p5 == p9 && p9 != 'n') ||
                        (p3 == p5 && p5 == p7 && p7 != 'n'))
                {

                        if (kto == 'x') w = "Wygrana kó³ka!";
                        else w = "Wygrana krzy¿yka!";

                        Application->MessageBox(w, "Koniec gry!", MB_OK);
                }

        }

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
        pole1->Picture->LoadFromFile("kuba_img//piesel.bmp");
        pole2->Picture->LoadFromFile("kuba_img//piesel.bmp");
        pole3->Picture->LoadFromFile("kuba_img//piesel.bmp");
        pole4->Picture->LoadFromFile("kuba_img//piesel.bmp");     //dzia³a te¿ z 1 o.O
        pole5->Picture->LoadFromFile("kuba_img//piesel.bmp");
        pole6->Picture->LoadFromFile("kuba_img//piesel.bmp");
        pole7->Picture->LoadFromFile("kuba_img//piesel.bmp");
        pole8->Picture->LoadFromFile("kuba_img//piesel.bmp");
        pole9->Picture->LoadFromFile("kuba_img//piesel.bmp");
        tura->Picture->LoadFromFile("kuba_img//o_small.bmp"); //zaczyna kolko (user)

        p1 = 'n';p2 = 'n';p3 = 'n';
        p4 = 'n';p5 = 'n';p6 = 'n';
        p7 = 'n';p8 = 'n';p9 = 'n';

        kto = 'o';

        pole1->Enabled = true;
        pole2->Enabled = true;
        pole3->Enabled = true;
        pole4->Enabled = true;
        pole5->Enabled = true;
        pole6->Enabled = true;
        pole7->Enabled = true;
        pole8->Enabled = true;
        pole9->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole1Click(TObject *Sender)
{
        if(p1=='n')
        {
                if(kto == 'o')
                {
                        pole1->Picture->LoadFromFile("kuba_img//o_big.bmp");
                        p1 = 'o';
                        kto = 'x';
                        tura->Picture->LoadFromFile("kuba_img//x_small.bmp");

                }
                else
                {
                        pole1->Picture->LoadFromFile("kuba_img//x_big.bmp");
                        p1 = 'x';
                        kto = 'o';
                        tura->Picture->LoadFromFile("kuba_img//o_small.bmp");

                }
                pole1->Enabled = false;
                check();

        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole2Click(TObject *Sender)
{
                if(kto == 'o')
                {
                        pole2->Picture->LoadFromFile("kuba_img//o_big.bmp");
                        p2 = 'o';
                        kto = 'x';
                        tura->Picture->LoadFromFile("kuba_img//x_small.bmp");
                }
                else
                {
                        pole2->Picture->LoadFromFile("kuba_img//x_big.bmp");
                        p2 = 'x';
                        kto = 'o';
                        tura->Picture->LoadFromFile("kuba_img//o_small.bmp");
                }
                pole2->Enabled = false;
                check();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole3Click(TObject *Sender)
{
                if(kto == 'o')
                {
                        pole3->Picture->LoadFromFile("kuba_img//o_big.bmp");
                        p3 = 'o';
                        kto = 'x';
                        tura->Picture->LoadFromFile("kuba_img//x_small.bmp");
                }
                else
                {
                        pole3->Picture->LoadFromFile("kuba_img//x_big.bmp");
                        p3 = 'x';
                        kto = 'o';
                        tura->Picture->LoadFromFile("kuba_img//o_small.bmp");
                }
                pole3->Enabled = false;
                check();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole4Click(TObject *Sender)
{
                if(kto == 'o')
                {
                        pole4->Picture->LoadFromFile("kuba_img//o_big.bmp");
                        p4 = 'o';
                        kto = 'x';
                        tura->Picture->LoadFromFile("kuba_img//x_small.bmp");
                }
                else
                {
                        pole4->Picture->LoadFromFile("kuba_img//x_big.bmp");
                        p4 = 'x';
                        kto = 'o';
                        tura->Picture->LoadFromFile("kuba_img//o_small.bmp");
                }
                pole4->Enabled = false;
                check();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole5Click(TObject *Sender)
{
                if(kto == 'o')
                {
                        pole5->Picture->LoadFromFile("kuba_img//o_big.bmp");
                        p5 = 'o';
                        kto = 'x';
                        tura->Picture->LoadFromFile("kuba_img//x_small.bmp");
                }
                else
                {
                        pole5->Picture->LoadFromFile("kuba_img//x_big.bmp");
                        p5 = 'x';
                        kto = 'o';
                        tura->Picture->LoadFromFile("kuba_img//o_small.bmp");
                }
                pole5->Enabled = false;
                check();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole6Click(TObject *Sender)
{
                if(kto == 'o')
                {
                        pole6->Picture->LoadFromFile("kuba_img//o_big.bmp");
                        p6 = 'o';
                        kto = 'x';
                        tura->Picture->LoadFromFile("kuba_img//x_small.bmp");
                }
                else
                {
                        pole6->Picture->LoadFromFile("kuba_img//x_big.bmp");
                        p6 = 'x';
                        kto = 'o';
                        tura->Picture->LoadFromFile("kuba_img//o_small.bmp");
                }
                pole6->Enabled = false;
                check();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole7Click(TObject *Sender)
{
                if(kto == 'o')
                {
                        pole7->Picture->LoadFromFile("kuba_img//o_big.bmp");
                        p7 = 'o';
                        kto = 'x';
                        tura->Picture->LoadFromFile("kuba_img//x_small.bmp");
                }
                else
                {
                        pole7->Picture->LoadFromFile("kuba_img//x_big.bmp");
                        p7 = 'x';
                        kto = 'o';
                        tura->Picture->LoadFromFile("kuba_img//o_small.bmp");
                }
                pole7->Enabled = false;
                check();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole8Click(TObject *Sender)
{
                if(kto == 'o')
                {
                        pole8->Picture->LoadFromFile("kuba_img//o_big.bmp");
                        p8 = 'o';
                        kto = 'x';
                        tura->Picture->LoadFromFile("kuba_img//x_small.bmp");
                }
                else
                {
                        pole8->Picture->LoadFromFile("kuba_img//x_big.bmp");
                        p8 = 'x';
                        kto = 'o';
                        tura->Picture->LoadFromFile("kuba_img//o_small.bmp");
                }
                pole8->Enabled = false;
                check();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pole9Click(TObject *Sender)
{
                if(kto == 'o')
                {
                        pole9->Picture->LoadFromFile("kuba_img//o_big.bmp");
                        p9 = 'o';
                        kto = 'x';
                        tura->Picture->LoadFromFile("kuba_img//x_small.bmp");
                }
                else
                {
                        pole9->Picture->LoadFromFile("kuba_img//x_big.bmp");
                        p9 = 'x';
                        kto = 'o';
                        tura->Picture->LoadFromFile("kuba_img//o_small.bmp");
                }
                pole9->Enabled = false;
                check();
}
//---------------------------------------------------------------------------

