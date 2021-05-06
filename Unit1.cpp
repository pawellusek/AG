//---------------------------------------------------------------------------

#include <vcl.h>
#include <time.h>


#pragma hdrstop

#include "Unit1.h"
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




void __fastcall TForm1::FormCreate(TObject *Sender)
{
Image1->Canvas->Pixels[0][0] = clWhite;
Image4->Canvas->Pixels[0][0] = clWhite;
ile_miast=0;
max_miast=1000;
for(int i=0; i<max_miast;++i){
        wsp[i][0]=-1;
        wsp[i][1]=-1;
        }
for(int i=0;i<max_miast;++i){
        for(int j=0;j<max_miast;++j){
                odl[i][j]=0;
                }
                }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if(ile_miast<max_miast){
++ile_miast;
        Image1->Canvas->Pixels[X][Y]=clBlack;
        Image1->Canvas->Pixels[X][Y+1]=clBlack;
        Image1->Canvas->Pixels[X+1][Y]=clBlack;
        Image1->Canvas->Pixels[X+1][Y+1]=clBlack;
        Image1->Canvas->Pixels[X+2][Y+2]=clBlack;
        Image1->Canvas->Pixels[X][Y+2]=clBlack;
        Image1->Canvas->Pixels[X+2][Y]=clBlack;
        Image1->Canvas->Pixels[X+1][Y+2]=clBlack;
        Image1->Canvas->Pixels[X+2][Y+1]=clBlack;
        Image1->Canvas->TextOut(X,Y-15,ile_miast-1);
        Image4->Canvas->Pixels[X][Y]=clBlack;
        Image4->Canvas->Pixels[X][Y+1]=clBlack;
        Image4->Canvas->Pixels[X+1][Y]=clBlack;
        Image4->Canvas->Pixels[X+1][Y+1]=clBlack;
        Image4->Canvas->Pixels[X+2][Y+2]=clBlack;
        Image4->Canvas->Pixels[X][Y+2]=clBlack;
        Image4->Canvas->Pixels[X+2][Y]=clBlack;
        Image4->Canvas->Pixels[X+1][Y+2]=clBlack;
        Image4->Canvas->Pixels[X+2][Y+1]=clBlack;
        Image1->Canvas->Font->Color=clBlack;
        Image4->Canvas->TextOut(X,Y-15,ile_miast-1);
        wsp[ile_miast-1][0]=X;
        wsp[ile_miast-1][1]=Y;


        }
else Application->MessageBox("Maksymalna ilosc miast!!!", "Uwaga", MB_OK);

}
//---------------------------------------------------------------------------

int TForm1::odleglosc(int jeden, int dwa)
{
 int odl=sqrt((wsp[jeden][0]-wsp[dwa][0])*(wsp[jeden][0]-wsp[dwa][0])+
                                (wsp[jeden][1]-wsp[dwa][1])*(wsp[jeden][1]-wsp[dwa][1]));
                                return odl;
 }



int TForm1::randval(int low, int high)
{
int val;

val=((int)(rand()%1000)/1000.0)*(high-low)+low;
return(val);
}




void __fastcall TForm1::Button1Click(TObject *Sender)
{
populacja=StrToInt(Edit1->Text);
tab = new int*[ile_miast+1];
for (int j = 0; j < ile_miast+1; j++)
tab[j] = new int[populacja];
tabn = new int*[ile_miast+1];
for (int j = 0; j < ile_miast+1; j++)
tabn[j] = new int[populacja];
time_t t;
srand((unsigned) time(&t));


///////////////////////////////////////////
dlugosc=ile_miast;         //deklaracje dopasowañ i innych
////////////////////////////////////////////////////////////////
bool dalej=false;         //  tablica do sprawdzania poprawnosci populacji pocz¹tkowej
check=new int[ile_miast];  ///..... cd
////////////rodzice i dzieci wybrani do krzy¿owania///////////
parent1=new int[ile_miast+1];
parent2=new int[ile_miast+1];
child1=new int[ile_miast+1];
child2=new int[ile_miast+1];




///////////////////tworzenie populacji pocz¹tkowej////////////////////////////
for(int i=0; i<populacja;i++){

        for(int g=0;g<ile_miast;g++)
        check[g]=0;
        for( int j=0; j<ile_miast;j++){
                do{
                        gen=rand() % ile_miast;
                        if(check[gen]==0){
                                check[gen]=1;
                                tab[j][i]=gen;
                               // StringGrid1->Cells[j][i]=tab[j][i];
                                dalej=true;
                                }
                        else{dalej=false;}
                   }
         while(dalej==false);
        }

}
//Label1->Caption=k;
//for(int g=0;g<ile_miast;g++){
//        StringGrid3->Cells[g][0]=check[g];
//        }

////////////////////////////////////////////////////////////////

/*for(int i=0; i<max_miast;++i){  //wypisanie miast do Memo
       if(wsp[i][0]!=-1)
       Memo1->Lines->Add("wsp miasta "+ IntToStr(i) +
       " to "+ wsp[i][0]+", "+wsp[i][1]);
       else{}
       }   */

///////////////////////////////////rysowanie wszystkich tras///////////////////
/*
Image1->Canvas->Pen->Color=clRed;
for(int i=0;i<ile_miast-1;++i){
         for(int j=0;j<ile_miast;++j){
         Image1->Canvas->MoveTo(wsp[i][0],wsp[i][1]);
         Image1->Canvas->LineTo(wsp[j][0],wsp[j][1]);
         Memo1->Lines->Add("Ustawiam w "+IntToStr(wsp[i][0])+", "+wsp[i][1]);
         Memo1->Lines->Add("Rysujê do "+IntToStr(wsp[j][0])+", "+wsp[j][1]);

         }
         }
  */
//////////////////////////////uzupelnienie tablicy odleglosci//////////////////

//StringGrid2->RowCount=ile_miast;
//StringGrid2->ColCount=ile_miast;
 for(int i=0;i<ile_miast;++i){
        for(int j=0;j<ile_miast;++j){
                odl[i][j]=sqrt((wsp[i][0]-wsp[j][0])*(wsp[i][0]-wsp[j][0])+
                                (wsp[i][1]-wsp[j][1])*(wsp[i][1]-wsp[j][1]));
               // StringGrid2->Cells[i][j]=odl[i][j];
                                }
                                }
//StringGrid1->RowCount=populacja;
//StringGrid1->ColCount=ile_miast+1;
 //////////////////////obliczanie lacznej dlugosci trasy////////////////////
int odleglosc=0;
best_ever=new int[ile_miast+1];

for(int i=0;i<populacja;i++){

        for(int j=0;j<ile_miast-1;j++){
                odleglosc+=odl[tab[j][i]][tab[j+1][i]];
                }
        odleglosc+=odl[tab[ile_miast-1][i]][tab[0][i]];
   tab[dlugosc][i]=odleglosc;
     odleglosc=0;
    // StringGrid1->Cells[ile_miast][i]=tab[dlugosc][i];
    }
    pok=1;

      double avg;

    int sum=0;
    best=tab[ile_miast][0];
    index_best=0;
    for(int y=1;y<populacja;y++){
              if(tab[ile_miast][y]<best){
                best=tab[ile_miast][y];
                index_best=y;
                }
                else{}
              }

     for(int y=0;y<populacja;y++){
               sum+=tab[ile_miast][y];
               }
     avg=sum/populacja;
      sum=0;
      for(int e=0;e<ile_miast+1;e++){
        best_ever[e]=tab[e][index_best];
        }
     Memo1->Lines->Add("Pokolenie: "+IntToStr(pok)+ " || Best: "+IntToStr(best)+ " || Avg: "+FloatToStr(avg));
     Memo2->Lines->Add("Pokolenie: "+ IntToStr(pok)+ " || Best: "+IntToStr(best_ever[ile_miast]));
      // Memo3->Lines->Add(IntToStr(pok));
      Memo4->Lines->Add(IntToStr(best_ever[ile_miast]));
     //////selekcja turniejowa, wybor rodzicow i zapamietanie//////////////////////////////
rozm_turnieju=StrToInt(Edit2->Text);
int rodz1,rodz2;
int temp1,temp2;
cross=StrToFloat(Edit3->Text);
mutate=StrToFloat(Edit4->Text);
invert=StrToFloat(Edit6->Text);
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////glowna petla ag///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
pokolenia=StrToInt(Edit5->Text);
ProgressBar2->Max=populacja/2;
ProgressBar1->Max=pokolenia;
for(pok=2;pok<pokolenia+1;pok++){

ProgressBar1->Position=pok;
for(int i=0;i<populacja/2;i++){
        ProgressBar2->Position=i;
            //petla do selekcji, krzyzowania i mutacji////////
        //Memo1->Lines->Add("Wybor rodzicow nr. " +IntToStr(i));
         rodz1=rand()%populacja;
         rodz2=rand()%populacja;
       // Memo1->Lines->Add("Wartosc temp "+ IntToStr(tab[ile_miast][rodz1]));
        for(int j=0;j<rozm_turnieju-1;j++){
                temp2=rand()%populacja;
                temp1=rand()%populacja;
              // Memo1->Lines->Add("Wartosc nastepna "+ IntToStr(tab[ile_miast][temp]));
                if(tab[ile_miast][temp1]<tab[ile_miast][rodz1])
                        {
                        /// Memo1->Lines->Add("drugi jest lepszy wiec zamiana");
                         rodz1=temp1;
                         }
                         else{}
                if(tab[ile_miast][temp2]<tab[ile_miast][rodz2])
                        {
                        /// Memo1->Lines->Add("drugi jest lepszy wiec zamiana");
                         rodz2=temp2;
                         }
                         else{}


        }

        // Memo1->Lines->Add("rodz1 jest wiec rowny"+ IntToStr(rodz1)+" " +IntToStr(tab[ile_miast][rodz1]));
        // Memo1->Lines->Add("rodz2 jest wiec rowny"+ IntToStr(rodz2)+" " +IntToStr(tab[ile_miast][rodz2]));

       ////////////// zapamietanie dwoch rodzicow do zmiennych tablicowych ////////////////////////////////////

        for(int w=0;w<ile_miast+1;w++)
        {
        parent1[w]=tab[w][rodz1];
        parent2[w]=tab[w][rodz2];
        }
        double x;
        x=rand()%1000/1000.0;
        if(x<cross){       // czy ma zajsc krzyzowanie?
        int left,right;

        if(RadioButton1->Checked==Enabled){ // krzyzowanie  PMX/////////////////////////
                                           //losowanie punktow przeciecia
                left=randval(1,ile_miast-2);
                right=randval(left+1,ile_miast-1);
               // left=randval(0,ile_miast-2);
               // right=randval(left+1,ile_miast-1);

      //   Memo1->Lines->Add(IntToStr(left)+" " +IntToStr(right));

         int **pomoc;           ///////tworzenie pomocniczej tablicy odwzorowan
         pomoc = new int*[ile_miast];
         for (int j = 0; j < ile_miast; j++)
         pomoc[j] = new int[2];
         for (int j = 0; j < ile_miast; j++){
         pomoc[j][0]=-1;
         pomoc[j][1]=-1;
         }
         int *ch1_test =new int[ile_miast];
         int *ch2_test =new int[ile_miast];
         for(int l=0;l<ile_miast;l++)
         ch1_test[l]=-1;
         for(int l=0;l<ile_miast;l++)
         ch2_test[l]=-1;
         for(int k=left;k<right+1;k++){
                child1[k]=parent2[k];
                child2[k]=parent1[k];
                ch1_test[child1[k]]=1;
                ch2_test[child2[k]]=1;
                pomoc[k][0]=parent1[k];
                pomoc[k][1]=parent2[k];
                }

               ///uzupelnianie potomka1 od poczatku do left
              for(int v=0;v<left;v++){
           if(ch1_test[parent1[v]]==-1){
                child1[v]=parent1[v];
                }
            else   {
                 int zamiana;
                 int g=0;
                 int szukaj=parent1[v];
                 do{
                 if(pomoc[g][1]==szukaj){
                        zamiana=pomoc[g][0];
                        szukaj=zamiana;
                        g=0;
                        }
                        else{}
                 g++;
                    }
                 while(g<ile_miast);
                 child1[v]=zamiana;
            }
            }
              ////uzupelnianie potomka1 od right do konca
              for(int v=right+1;v<ile_miast;v++){
           if(ch1_test[parent1[v]]==-1)
                child1[v]=parent1[v];
            else   {
                 int zamiana=0;
                 int g=0;
                 int szukaj=parent1[v];
                 do{
                 if(pomoc[g][1]==szukaj){
                        zamiana=pomoc[g][0];
                        szukaj=zamiana;
                        g=0;
                        }
                        else{}
                 g++;
                    }
                 while(g<ile_miast);
                 child1[v]=zamiana;

            }
            }

            ///uzupelnianie potomka2 od poczatku do left
              for(int v=0;v<left;v++){
           if(ch2_test[parent2[v]]==-1) {
                child2[v]=parent2[v];
                }
            else   {
                 int zamiana;
                 int g=0;
                 int szukaj=parent2[v];
                 do{
                 if(pomoc[g][0]==szukaj){
                        zamiana=pomoc[g][1];
                        szukaj=zamiana;
                        g=0;
                        }
                        else{}
                 g++;
                    }
                 while(g<ile_miast);
                 child2[v]=int(zamiana);
            }
            }
              ////uzupelnianie potomka2 od right do konca
              for(int v=right+1;v<ile_miast;v++){
           if(ch2_test[parent2[v]]==-1)
                child2[v]=parent2[v];
            else   {
                 int zamiana;
                 int g=0;
                 int szukaj=parent2[v];
                 do{
                 if(pomoc[g][0]==szukaj){
                        zamiana=pomoc[g][1];
                        szukaj=zamiana;
                        g=0;
                        }
                        else{}
                 g++;
                    }
                 while(g<ile_miast);
                 child2[v]=int(zamiana);
            }
            }


         for (int x = 0; x < ile_miast;  x++)
       delete[] pomoc[x];                 // STEP 1: DELETE THE COLUMNS

        delete[] pomoc;

       delete []ch1_test;
       delete []ch2_test;

        }/////////koniec krzyzowania PMX

        else if(RadioButton2->Checked==Enabled){ // krzyzowanie OX

                left=randval(1,ile_miast-2);
                right=randval(left+1,ile_miast-1);
                int *first =new int[ile_miast-(right-left+1)];
                int *second =new int[ile_miast-(right-left+1)];
                int *ch1_test =new int[ile_miast];
                int *ch2_test =new int[ile_miast];
                for(int l=0;l<ile_miast;l++){
                ch1_test[l]=-1;
                ch2_test[l]=-1;
                }
                for(int p=0;p<20;p++){    //czyszczenie stringgrida

                        StringGrid3->Cells[p][0]="";


                        }



                for(int k=left;k<right+1;k++){
                child1[k]=parent2[k];
                child2[k]=parent1[k];
                ch1_test[child1[k]]=1;
                ch2_test[child2[k]]=1;
                }

    ////////////////// uzupelnianie pomocniczej tablicy dla child1
                 int pozycja1=0;
                 for(int v=right+1;v<ile_miast;v++){
                        if(ch1_test[parent1[v]]==-1){
                        first[pozycja1]=parent1[v];
                        pozycja1++;
                  //      Memo1->Lines->Add(IntToStr(pozycja1));
                        }
                 else{}
                 }
                 for(int v=0;v<right+1;v++){
                        if(ch1_test[parent1[v]]==-1){
                        first[pozycja1]=parent1[v];
                        pozycja1++;
                      //  Memo1->Lines->Add(IntToStr(pozycja1));
                        }
                else{}
                }
           //    Memo1->Lines->Add(IntToStr(left)+ " " + IntToStr(right));
          //  Memo1->Lines->Add("     " +IntToStr(ile_miast-(right-left+1))) ;


            int position=0;
            for(int h=right+1;h<ile_miast;h++,position++)
                child1[h]=first[position];

             for( int h=0;h<left;h++,position++)
                child1[h]=first[position];
               ///koniec tworzenia pierwszego potomka

               ////uzupelnianie reszty drugiego potomka

                int pozycja2=0;
                 for(int v=right+1;v<ile_miast;v++){
                        if(ch2_test[parent2[v]]==-1){
                        second[pozycja2]=parent2[v];
                        pozycja2++;
                  //      Memo1->Lines->Add(IntToStr(pozycja1));
                        }
                 else{}
                 }
                 for(int v=0;v<right+1;v++){
                        if(ch2_test[parent2[v]]==-1){
                        second[pozycja2]=parent2[v];
                        pozycja2++;
                      //  Memo1->Lines->Add(IntToStr(pozycja1));
                        }
                else{}
                }
            //   Memo1->Lines->Add(IntToStr(left)+ " " + IntToStr(right));
          //  Memo1->Lines->Add("     " +IntToStr(ile_miast-(right-left+1))) ;


            int positionn=0;
            for(int h=right+1;h<ile_miast;h++,positionn++)
                child2[h]=second[positionn];

             for( int h=0;h<left;h++,positionn++)
                child2[h]=second[positionn];
               ///koniec tworzenia pierwszego potomka



            delete []first;
            delete []second;
            delete []ch1_test;
            delete []ch2_test;


               /////// koniecv tworzenia drugiego potomka
          /* for(int vv=0;vv<ile_miast;vv++){
            StringGrid3->Cells[vv][2]=parent1[vv];
            StringGrid3->Cells[vv][3]=parent2[vv];
            StringGrid3->Cells[vv][4]=child1[vv];
            StringGrid3->Cells[vv][5]=child2[vv];
            }
            for(int vv=0;vv<ile_miast-(right-left+1);vv++){
                StringGrid3->Cells[vv][6]=first[vv];
                StringGrid3->Cells[vv][7]=second[vv];
                }
                */
           ////////////////////////////////////////////

        } //////////////koniec krzyzowania OX////////////////










        } ////koniec warunku jak krzyzowanie ma zajsc

        else{       // co zrobic jak krzyzowanie nie ma zajsc

        for(int c=0;c<ile_miast;c++){
        child1[c]=parent1[c];
        child2[c]=parent2[c];
        }


        }  //koniec else jak krzyzowanie nie ma zajsc

        ////wpisanie potomkow do nowej tablicy

        if(i==0){
        for(int y=0;y<ile_miast;y++){
        tabn[y][0]=child1[y];
        tabn[y][1]=child2[y];
        }
        }
        else{
                for(int y=0;y<ile_miast;y++){
                tabn[y][2*i]=child1[y];
                tabn[y][2*i+1]=child2[y];
        }
        }

}  ////koniec glownej petli for odpowiadajacej za  krzyzowanie//////

  // for(int row=0;row<ile_miast;row++){
      //  for(int col=0;col<populacja;col++){
               // StringGrid3->Cells[row][col]=tabn[row][col];
               // tab[row][col]=tabn[row][col];
             //   }
             //   }


        /////////sprawdzanie gdzie sa powtorzone symbole////////////
    /*     int f=0,alar=0,jest=0,brak=0,pozycja=0,stop=0;
          int uwaga=0;int zamien=0;
        for(f=0;f<populacja;f++){
                for(alar=0;alar<ile_miast;alar++){
                        for(int z=0;z<ile_miast && stop==0;z++){
                                if(tabn[z][f]==alar)
                                        uwaga++;
                                if(uwaga==2){
                                        //Memo1->Lines->Add("Alarm" + IntToStr(f)+ " dwa razy " + IntToStr(alar));
                                        jest=alar;
                                        pozycja=z;
                                         stop=1;
                                        zamien=1;
                                }
                        }
                        stop=0;
                        if(uwaga==0){
                                //  Memo1->Lines->Add("Brak "+ IntToStr(alar)+ " w " +IntToStr(f));
                                brak=alar;
                        }
                        uwaga=0;
                }
                 //tabn[pozycja][f]=alar;

                if (zamien==1){
              //  Memo1->Lines->Add("Pozycja "+IntToStr(pozycja)+ "populacja "+IntToStr(f) + " bylo " +IntToStr(jest)+ " bedzie " +IntToStr(brak));
                tabn[pozycja][f]=brak;
                }
                zamien=0;
        }
      */


          //zamiana z tabn na tab
          for(int row=0;row<ile_miast;row++){
        for(int col=0;col<populacja;col++){
              // StringGrid3->Cells[row+ile_miast+1][col]=tabn[row][col];
                tab[row][col]=tabn[row][col];
                }
        }


         ///mutacja
     int swap1,swap2,one,two;
     for(int i=0;i<populacja;i++){    //   petla odpowiadajaca za mutacje
     double x=rand()%1000/1000.0;
     if(x<mutate)
     {
        one=rand()%ile_miast;
         two=rand()%ile_miast;
         swap1=tab[one][i];
         swap2=tab[two][i];
         tab[one][i]=swap2;
         tab[two][i]=swap1;
         }
         }

         ///opertor inwersji
         int jeden,dwa;
         for(int i=0;i<populacja;i++){

         double x=rand()%1000/1000.0;
                if(x<invert)
                {
                for(int n=0;n<ile_miast;n++)
                //StringGrid3->Cells[n][3]=tab[n][i];
                jeden=randval(1,ile_miast-2);
                dwa=randval(jeden+1,ile_miast-1);
                int *temp=new int[ile_miast];
                for(int n=0;n<ile_miast;n++)
                        temp[n]=-1;
                for(int n=jeden;n<dwa+1;n++){
                         temp[n]=tab[n][i];
                         }
                for(int n=jeden,v=0;n<dwa+1;n++,v++){
                        tab[n][i]=temp[dwa-v];
                      }

        /*   for(int n=0;n<ile_miast;n++)
                StringGrid3->Cells[n][5]=tab[n][i];
           for(int n=0;n<ile_miast;n++)
                StringGrid3->Cells[n][4]=temp[n];
          */

          delete []temp;
         }
         }
 ///wyliczanie dlugosci tras dla nowego pokolenia

   for(int m=0;m<populacja;m++){

        for(int j=0;j<ile_miast-1;j++){
                odleglosc+=odl[tabn[j][m]][tabn[j+1][m]];
                }
        odleglosc+=odl[tabn[ile_miast-1][m]][tabn[0][m]];
   tab[dlugosc][m]=odleglosc;
     odleglosc=0;
    }

    //wyznaczanie avg i best

     best=tab[ile_miast][0];
    for(int y=1;y<populacja;y++){
              if(tab[ile_miast][y]<best){
                best=tab[ile_miast][y];
                index_best=y;
                }
                }
              if(best_ever[ile_miast]>best){

                        for(int bb=0;bb<ile_miast+1;bb++)
                                best_ever[bb]=tab[bb][index_best];
                  Memo2->Lines->Add("Pokolenie: "+ IntToStr(pok)+ " || Best: "+IntToStr(best_ever[ile_miast]));

              }

     for(int y=0;y<populacja;y++){
               sum+=tab[ile_miast][y];
               }
     avg=sum/populacja;
      sum=0;
      Memo1->Lines->Add("Pokolenie: "+IntToStr(pok)+ " || Best: "+IntToStr(best)+" ("+IntToStr(best_ever[ile_miast])+") "         + " || Avg: "+FloatToStr(avg));
       //  Memo3->Lines->Add(IntToStr(pok));
      Memo4->Lines->Add(IntToStr(best_ever[ile_miast]));

}  //////////////////koniec petli glownej ag


  //// ponowne rysowanie punktow i oznaczen

   for(int q=0;q<Image1->Height;q++){
        for(int w=0;w<Image1->Width;w++){
                Image1->Canvas->Pixels[w][q]=Image4->Canvas->Pixels[w][q];
        }
   }

  ///wypisanie best_ever oraz rysowanie trasy
  //Image1->Canvas->Pen->Color=clRed;  //uaktywnic na kompilacje
 Image1->Canvas->MoveTo(wsp[best_ever[ile_miast-1]][0],wsp[best_ever[ile_miast-1]][1]);
 for(int k=0;k<ile_miast;k++){
 StringGrid3->Cells[k][0]=best_ever[k];
 Image1->Canvas->Pen->Style=psSolid;
 Image1->Canvas->Pen->Width=3;
 Image1->Canvas->LineTo(wsp[best_ever[k]][0],wsp[best_ever[k]][1]);

 }


 ////rysowanie informacji
 Image1->Canvas->Font->Color=clGreen;
 Image1->Canvas->Font->Size=8;
 Image1->Canvas->Font->Style=TFontStyles()<< fsBold;
 AnsiString popul="Pop:"+Edit1->Text;
 Image1->Canvas->TextOutA(5,Image1->Height-30,popul);
 AnsiString pokole="Pok:"+Edit5->Text;
 Image1->Canvas->TextOutA(5,Image1->Height-15,pokole);
 AnsiString cro;
 if(RadioButton1->Checked==true)
 cro="Krzy¿:PMX";
 else
 cro="Krzy¿:OX";
 Image1->Canvas->TextOutA(160,Image1->Height-30,cro);
 AnsiString turn="Roz_tur:"+ Edit2->Text;
  AnsiString prozmia="Miasta:"+IntToStr(ile_miast);
 Image1->Canvas->TextOutA(80,Image1->Height-30,prozmia);

 Image1->Canvas->TextOutA(80,Image1->Height-15,turn);
 AnsiString p_krzyz="Prawd_krzy¿:"+Edit3->Text;
 Image1->Canvas->TextOutA(160,Image1->Height-15,p_krzyz);
 AnsiString p_mut="Prawd_mut:"+Edit4->Text;
 AnsiString p_inv="Prawd_inv:"+Edit6->Text;
 Image1->Canvas->TextOutA(270,Image1->Height-30,p_mut);
 Image1->Canvas->TextOutA(270,Image1->Height-15,p_inv);
 AnsiString naj="Best:"+IntToStr(best_ever[ile_miast]);
 Image1->Canvas->TextOutA(380,Image1->Height-15,naj);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
Edit5->Text="100";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
Edit5->Text="1000";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
Edit5->Text="10000";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton7Click(TObject *Sender)
{
Edit5->Text="100000";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton8Click(TObject *Sender)
{
Edit5->Text="1000000";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
double pop=StrToFloat(Edit3->Text);
if(pop>=1){}
else{

pop=pop+0.05;
Edit3->Text=FloatToStr(pop);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
double pop=StrToFloat(Edit3->Text);
if(pop<=0){}
else{


pop=pop-0.05;
Edit3->Text=FloatToStr(pop);
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button4Click(TObject *Sender)
{
	SaveDialog1->Filter = "BMP - Mapa Bitowa Windows |*.BMP";
	if(SaveDialog1 -> Execute())
    {
    	Image1 -> Picture -> SaveToFile(SaveDialog1 -> FileName + ".bmp");
        Image1 -> Width = Image1 -> Picture -> Width;
		Image1 -> Height = Image1 -> Picture -> Height;
    }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button5Click(TObject *Sender)
{
int rodz1,rodz2;
int temp1,temp2;
//int rodz1,rodz2;
//int temp1,temp2;
  int ile_jeszcze=StrToInt(Edit5->Text);
 double avg;
int dotychczas=pok;
    int sum=0;
 ProgressBar1->Max=pok+ile_jeszcze;
///poczatek
         for(pok=dotychczas;pok<dotychczas+ile_jeszcze;pok++){

ProgressBar1->Position=pok;
for(int i=0;i<populacja/2;i++){
      //  ProgressBar2->Position=i;
            //petla do selekcji, krzyzowania i mutacji////////
        //Memo1->Lines->Add("Wybor rodzicow nr. " +IntToStr(i));
         rodz1=rand()%populacja;
         rodz2=rand()%populacja;
       // Memo1->Lines->Add("Wartosc temp "+ IntToStr(tab[ile_miast][rodz1]));
        for(int j=0;j<rozm_turnieju-1;j++){
                temp2=rand()%populacja;
                temp1=rand()%populacja;
              // Memo1->Lines->Add("Wartosc nastepna "+ IntToStr(tab[ile_miast][temp]));
                if(tab[ile_miast][temp1]<tab[ile_miast][rodz1])
                        {
                        /// Memo1->Lines->Add("drugi jest lepszy wiec zamiana");
                         rodz1=temp1;
                         }
                         else{}
                if(tab[ile_miast][temp2]<tab[ile_miast][rodz2])
                        {
                        /// Memo1->Lines->Add("drugi jest lepszy wiec zamiana");
                         rodz2=temp2;
                         }
                         else{}


        }

        // Memo1->Lines->Add("rodz1 jest wiec rowny"+ IntToStr(rodz1)+" " +IntToStr(tab[ile_miast][rodz1]));
        // Memo1->Lines->Add("rodz2 jest wiec rowny"+ IntToStr(rodz2)+" " +IntToStr(tab[ile_miast][rodz2]));

       ////////////// zapamietanie dwoch rodzicow do zmiennych tablicowych ////////////////////////////////////

        for(int w=0;w<ile_miast+1;w++)
        {
        parent1[w]=tab[w][rodz1];
        parent2[w]=tab[w][rodz2];
        }
        double x;
        x=rand()%1000/1000.0;
        if(x<cross){       // czy ma zajsc krzyzowanie?
        int left,right;

        if(RadioButton1->Checked==Enabled){ // krzyzowanie  PMX/////////////////////////
                                           //losowanie punktow przeciecia
                left=randval(1,ile_miast-2);
                right=randval(left+1,ile_miast-1);
               // left=randval(0,ile_miast-2);
               // right=randval(left+1,ile_miast-1);

      //   Memo1->Lines->Add(IntToStr(left)+" " +IntToStr(right));

         int **pomoc;           ///////tworzenie pomocniczej tablicy odwzorowan
         pomoc = new int*[ile_miast];
         for (int j = 0; j < ile_miast; j++)
         pomoc[j] = new int[2];
         for (int j = 0; j < ile_miast; j++){
         pomoc[j][0]=-1;
         pomoc[j][1]=-1;
         }
         int *ch1_test =new int[ile_miast];
         int *ch2_test =new int[ile_miast];
         for(int l=0;l<ile_miast;l++)
         ch1_test[l]=-1;
         for(int l=0;l<ile_miast;l++)
         ch2_test[l]=-1;
         for(int k=left;k<right+1;k++){
                child1[k]=parent2[k];
                child2[k]=parent1[k];
                ch1_test[child1[k]]=1;
                ch2_test[child2[k]]=1;
                pomoc[k][0]=parent1[k];
                pomoc[k][1]=parent2[k];
                }

               ///uzupelnianie potomka1 od poczatku do left
              for(int v=0;v<left;v++){
           if(ch1_test[parent1[v]]==-1){
                child1[v]=parent1[v];
                }
            else   {
                 int zamiana;
                 int g=0;
                 int szukaj=parent1[v];
                 do{
                 if(pomoc[g][1]==szukaj){
                        zamiana=pomoc[g][0];
                        szukaj=zamiana;
                        g=0;
                        }
                        else{}
                 g++;
                    }
                 while(g<ile_miast);
                 child1[v]=zamiana;
            }
            }
              ////uzupelnianie potomka1 od right do konca
              for(int v=right+1;v<ile_miast;v++){
           if(ch1_test[parent1[v]]==-1)
                child1[v]=parent1[v];
            else   {
                 int zamiana=0;
                 int g=0;
                 int szukaj=parent1[v];
                 do{
                 if(pomoc[g][1]==szukaj){
                        zamiana=pomoc[g][0];
                        szukaj=zamiana;
                        g=0;
                        }
                        else{}
                 g++;
                    }
                 while(g<ile_miast);
                 child1[v]=zamiana;

            }
            }

            ///uzupelnianie potomka2 od poczatku do left
              for(int v=0;v<left;v++){
           if(ch2_test[parent2[v]]==-1) {
                child2[v]=parent2[v];
                }
            else   {
                 int zamiana;
                 int g=0;
                 int szukaj=parent2[v];
                 do{
                 if(pomoc[g][0]==szukaj){
                        zamiana=pomoc[g][1];
                        szukaj=zamiana;
                        g=0;
                        }
                        else{}
                 g++;
                    }
                 while(g<ile_miast);
                 child2[v]=int(zamiana);
            }
            }
              ////uzupelnianie potomka2 od right do konca
              for(int v=right+1;v<ile_miast;v++){
           if(ch2_test[parent2[v]]==-1)
                child2[v]=parent2[v];
            else   {
                 int zamiana;
                 int g=0;
                 int szukaj=parent2[v];
                 do{
                 if(pomoc[g][0]==szukaj){
                        zamiana=pomoc[g][1];
                        szukaj=zamiana;
                        g=0;
                        }
                        else{}
                 g++;
                    }
                 while(g<ile_miast);
                 child2[v]=int(zamiana);
            }
            }


         for (int x = 0; x < ile_miast;  x++)
       delete[] pomoc[x];                 // STEP 1: DELETE THE COLUMNS

        delete[] pomoc;

        delete []ch1_test;
        delete []ch2_test;

        }/////////koniec krzyzowania PMX

        else if(RadioButton2->Checked==Enabled){ // krzyzowanie OX

                left=randval(1,ile_miast-2);
                right=randval(left+1,ile_miast-1);
                int *first =new int[ile_miast-(right-left+1)];
                int *second =new int[ile_miast-(right-left+1)];
                int *ch1_test =new int[ile_miast];
                int *ch2_test =new int[ile_miast];
                for(int l=0;l<ile_miast;l++){
                ch1_test[l]=-1;
                ch2_test[l]=-1;
                }
                for(int p=0;p<20;p++){    //czyszczenie stringgrida
                  for(int s=0;s<20;s++){
                        StringGrid3->Cells[p][s]="";
                        }

                        }



                for(int k=left;k<right+1;k++){
                child1[k]=parent2[k];
                child2[k]=parent1[k];
                ch1_test[child1[k]]=1;
                ch2_test[child2[k]]=1;
                }

    ////////////////// uzupelnianie pomocniczej tablicy dla child1
                 int pozycja1=0;
                 for(int v=right+1;v<ile_miast;v++){
                        if(ch1_test[parent1[v]]==-1){
                        first[pozycja1]=parent1[v];
                        pozycja1++;
                  //      Memo1->Lines->Add(IntToStr(pozycja1));
                        }
                 else{}
                 }
                 for(int v=0;v<right+1;v++){
                        if(ch1_test[parent1[v]]==-1){
                        first[pozycja1]=parent1[v];
                        pozycja1++;
                      //  Memo1->Lines->Add(IntToStr(pozycja1));
                        }
                else{}
                }
           //    Memo1->Lines->Add(IntToStr(left)+ " " + IntToStr(right));
          //  Memo1->Lines->Add("     " +IntToStr(ile_miast-(right-left+1))) ;


            int position=0;
            for(int h=right+1;h<ile_miast;h++,position++)
                child1[h]=first[position];

             for( int h=0;h<left;h++,position++)
                child1[h]=first[position];
               ///koniec tworzenia pierwszego potomka

               ////uzupelnianie reszty drugiego potomka

                int pozycja2=0;
                 for(int v=right+1;v<ile_miast;v++){
                        if(ch2_test[parent2[v]]==-1){
                        second[pozycja2]=parent2[v];
                        pozycja2++;
                  //      Memo1->Lines->Add(IntToStr(pozycja1));
                        }
                 else{}
                 }
                 for(int v=0;v<right+1;v++){
                        if(ch2_test[parent2[v]]==-1){
                        second[pozycja2]=parent2[v];
                        pozycja2++;
                      //  Memo1->Lines->Add(IntToStr(pozycja1));
                        }
                else{}
                }
            //   Memo1->Lines->Add(IntToStr(left)+ " " + IntToStr(right));
          //  Memo1->Lines->Add("     " +IntToStr(ile_miast-(right-left+1))) ;


            int positionn=0;
            for(int h=right+1;h<ile_miast;h++,positionn++)
                child2[h]=second[positionn];

             for( int h=0;h<left;h++,positionn++)
                child2[h]=second[positionn];
               ///koniec tworzenia pierwszego potomka



            delete []first;
            delete []second;
            delete []ch1_test;
            delete []ch2_test;


               /////// koniecv tworzenia drugiego potomka
          /* for(int vv=0;vv<ile_miast;vv++){
            StringGrid3->Cells[vv][2]=parent1[vv];
            StringGrid3->Cells[vv][3]=parent2[vv];
            StringGrid3->Cells[vv][4]=child1[vv];
            StringGrid3->Cells[vv][5]=child2[vv];
            }
            for(int vv=0;vv<ile_miast-(right-left+1);vv++){
                StringGrid3->Cells[vv][6]=first[vv];
                StringGrid3->Cells[vv][7]=second[vv];
                }
                */
           ////////////////////////////////////////////

        } //////////////koniec krzyzowania OX////////////////










        } ////koniec warunku jak krzyzowanie ma zajsc

        else{       // co zrobic jak krzyzowanie nie ma zajsc

        for(int c=0;c<ile_miast;c++){
        child1[c]=parent1[c];
        child2[c]=parent2[c];
        }


        }  //koniec else jak krzyzowanie nie ma zajsc

        ////wpisanie potomkow do nowej tablicy

        if(i==0){
        for(int y=0;y<ile_miast;y++){
        tabn[y][0]=child1[y];
        tabn[y][1]=child2[y];
        }
        }
        else{
                for(int y=0;y<ile_miast;y++){
                tabn[y][2*i]=child1[y];
                tabn[y][2*i+1]=child2[y];
        }
        }

}  ////koniec glownej petli for odpowiadajacej za  krzyzowanie//////

  // for(int row=0;row<ile_miast;row++){
      //  for(int col=0;col<populacja;col++){
               // StringGrid3->Cells[row][col]=tabn[row][col];
               // tab[row][col]=tabn[row][col];
             //   }
             //   }


        /////////sprawdzanie gdzie sa powtorzone symbole////////////
    /*     int f=0,alar=0,jest=0,brak=0,pozycja=0,stop=0;
          int uwaga=0;int zamien=0;
        for(f=0;f<populacja;f++){
                for(alar=0;alar<ile_miast;alar++){
                        for(int z=0;z<ile_miast && stop==0;z++){
                                if(tabn[z][f]==alar)
                                        uwaga++;
                                if(uwaga==2){
                                        //Memo1->Lines->Add("Alarm" + IntToStr(f)+ " dwa razy " + IntToStr(alar));
                                        jest=alar;
                                        pozycja=z;
                                         stop=1;
                                        zamien=1;
                                }
                        }
                        stop=0;
                        if(uwaga==0){
                                //  Memo1->Lines->Add("Brak "+ IntToStr(alar)+ " w " +IntToStr(f));
                                brak=alar;
                        }
                        uwaga=0;
                }
                 //tabn[pozycja][f]=alar;

                if (zamien==1){
              //  Memo1->Lines->Add("Pozycja "+IntToStr(pozycja)+ "populacja "+IntToStr(f) + " bylo " +IntToStr(jest)+ " bedzie " +IntToStr(brak));
                tabn[pozycja][f]=brak;
                }
                zamien=0;
        }
      */


          //zamiana z tabn na tab
          for(int row=0;row<ile_miast;row++){
        for(int col=0;col<populacja;col++){
              // StringGrid3->Cells[row+ile_miast+1][col]=tabn[row][col];
                tab[row][col]=tabn[row][col];
                }
        }


         ///mutacja
     int swap1,swap2,one,two;
     for(int i=0;i<populacja;i++){    //   petla odpowiadajaca za mutacje
     int swap1,swap2;
     double x=rand()%1000/1000.0;
     if(x<mutate)
     {
        one=rand()%ile_miast;
         two=rand()%ile_miast;
         swap1=tab[one][i];
         swap2=tab[two][i];
         tab[one][i]=swap2;
         tab[two][i]=swap1;
         }
         }

         ///opertor inwersji
         int jeden,dwa;
         for(int i=0;i<populacja;i++){

         double x=rand()%1000/1000.0;
                if(x<invert)
                {
                for(int n=0;n<ile_miast;n++)
                //StringGrid3->Cells[n][3]=tab[n][i];
                jeden=randval(1,ile_miast-2);
                dwa=randval(jeden+1,ile_miast-1);
                int *temp=new int[ile_miast];
                for(int n=0;n<ile_miast;n++)
                        temp[n]=-1;
                for(int n=jeden;n<dwa+1;n++){
                         temp[n]=tab[n][i];
                         }
                for(int n=jeden,v=0;n<dwa+1;n++,v++){
                        tab[n][i]=temp[dwa-v];
                      }

        /*   for(int n=0;n<ile_miast;n++)
                StringGrid3->Cells[n][5]=tab[n][i];
           for(int n=0;n<ile_miast;n++)
                StringGrid3->Cells[n][4]=temp[n];
          */

          delete []temp;
         }
         }
 ///wyliczanie dlugosci tras dla nowego pokolenia
   int odleglosc=0;
   for(int m=0;m<populacja;m++){

        for(int j=0;j<ile_miast-1;j++){
                odleglosc+=odl[tabn[j][m]][tabn[j+1][m]];
                }
        odleglosc+=odl[tabn[ile_miast-1][m]][tabn[0][m]];
   tab[dlugosc][m]=odleglosc;
     odleglosc=0;
    }

    //wyznaczanie avg i best

     best=tab[ile_miast][0];
    for(int y=1;y<populacja;y++){
              if(tab[ile_miast][y]<best){
                best=tab[ile_miast][y];
                index_best=y;
                }
                }
              if(best_ever[ile_miast]>best){

                        for(int bb=0;bb<ile_miast+ 1;bb++)
                                best_ever[bb]=tab[bb][index_best];
                  Memo2->Lines->Add("Pokolenie: "+ IntToStr(pok)+ " || Best: "+IntToStr(best_ever[ile_miast]));

              }

     for(int y=0;y<populacja;y++){
               sum+=tab[ile_miast][y];
               }
     avg=sum/populacja;                   
      sum=0;
      Memo1->Lines->Add("Pokolenie: "+IntToStr(pok)+ " || Best: "+IntToStr(best)+" ("+IntToStr(best_ever[ile_miast])+") "         + " || Avg: "+FloatToStr(avg));
      //       Memo3->Lines->Add(IntToStr(pok));
      Memo4->Lines->Add(IntToStr(best_ever[ile_miast]));

}




 //// ponowne rysowanie punktow i oznaczen

   for(int q=0;q<Image1->Height;q++){
        for(int w=0;w<Image1->Width;w++){
                Image1->Canvas->Pixels[w][q]=Image4->Canvas->Pixels[w][q];
        }
   }

  ///wypisanie best_ever oraz rysowanie trasy
  //Image1->Canvas->Pen->Color=clRed;  //uaktywnic na kompilacje
 Image1->Canvas->MoveTo(wsp[best_ever[ile_miast-1]][0],wsp[best_ever[ile_miast-1]][1]);
 for(int k=0;k<ile_miast;k++){
 StringGrid3->Cells[k][0]=best_ever[k];
 Image1->Canvas->Pen->Style=psSolid;
 Image1->Canvas->Pen->Width=1;
 Image1->Canvas->LineTo(wsp[best_ever[k]][0],wsp[best_ever[k]][1]);

 }


 ////rysowanie informacji
 Image1->Canvas->Font->Color=clGreen;
 Image1->Canvas->Font->Size=8;
 Image1->Canvas->Font->Style=TFontStyles()<< fsBold;
 AnsiString popul="Pop:"+Edit1->Text;
 Image1->Canvas->TextOutA(5,Image1->Height-30,popul);
 AnsiString pokole="Pok:"+IntToStr(pok-1);
 Image1->Canvas->TextOutA(5,Image1->Height-15,pokole);
 AnsiString cro;
 if(RadioButton1->Checked==true)
 cro="Krzy¿:PMX";
 else
 cro="Krzy¿:OX";
 Image1->Canvas->TextOutA(160,Image1->Height-30,cro);
 AnsiString turn="Roz_tur:"+ Edit2->Text;
 Image1->Canvas->TextOutA(80,Image1->Height-15,turn);
 AnsiString p_krzyz="Prawd_krzy¿:"+Edit3->Text;
 Image1->Canvas->TextOutA(160,Image1->Height-15,p_krzyz);
 AnsiString p_mut="Prawd_mut:"+Edit4->Text;
 AnsiString p_inv="Prawd_inv:"+Edit6->Text;
 Image1->Canvas->TextOutA(270,Image1->Height-30,p_mut);
 Image1->Canvas->TextOutA(270,Image1->Height-15,p_inv);
  AnsiString naj="Best:"+IntToStr(best_ever[ile_miast]);
 Image1->Canvas->TextOutA(380,Image1->Height-15,naj);
  AnsiString prozmia="Miasta:"+IntToStr(ile_miast);
 Image1->Canvas->TextOutA(80,Image1->Height-30,prozmia);
///koniec
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
int wsp_x,wsp_y;
time_t t;
srand((unsigned) time(&t));
int count=StrToInt(Edit7->Text);
for(int i=0;i<count;i++){
        wsp_x=randval((rand()%50)+10,Image1->Width-15);
        wsp_y=randval((rand()%50)+20,Image1->Height-30);

        Image1->Canvas->Pixels[wsp_x][wsp_y]=clBlack;
        Image1->Canvas->Pixels[wsp_x][wsp_y+1]=clBlack;
        Image1->Canvas->Pixels[wsp_x+1][wsp_y]=clBlack;
        Image1->Canvas->Pixels[wsp_x+1][wsp_y+1]=clBlack;
        Image1->Canvas->Pixels[wsp_x+2][wsp_y+2]=clBlack;
        Image1->Canvas->Pixels[wsp_x][wsp_y+2]=clBlack;
        Image1->Canvas->Pixels[wsp_x+2][wsp_y]=clBlack;
        Image1->Canvas->Pixels[wsp_x+1][wsp_y+2]=clBlack;
        Image1->Canvas->Pixels[wsp_x+2][wsp_y+1]=clBlack;
        if(count<80){
        Image4->Canvas->TextOut(wsp_x,wsp_y-15,i);
        Image1->Canvas->TextOut(wsp_x,wsp_y-15,i);
        }
        Image4->Canvas->Pixels[wsp_x][wsp_y]=clBlack;
        Image4->Canvas->Pixels[wsp_x][wsp_y+1]=clBlack;
        Image4->Canvas->Pixels[wsp_x+1][wsp_y]=clBlack;
        Image4->Canvas->Pixels[wsp_x+1][wsp_y+1]=clBlack;
        Image4->Canvas->Pixels[wsp_x+2][wsp_y+2]=clBlack;
        Image4->Canvas->Pixels[wsp_x][wsp_y+2]=clBlack;
        Image4->Canvas->Pixels[wsp_x+2][wsp_y]=clBlack;
        Image4->Canvas->Pixels[wsp_x+1][wsp_y+2]=clBlack;
        Image4->Canvas->Pixels[wsp_x+2][wsp_y+1]=clBlack;
        Image1->Canvas->Font->Color=clBlack;
        wsp[i][0]=wsp_x;
        wsp[i][1]=wsp_y;
        ++ile_miast;
        }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
int wynik[2000];
int temp[2000];
wynik[0]=0;
int best_wynik=0;
int koniec=ile_miast-1;
for(int l=1; l<=ile_miast;l++){
        temp[l-1]=l;
        }

        for(int i=0;i<ile_miast-1;i++){

      int best=temp[0];
        int best_index=0;
        int best_odl=odleglosc(wynik[i],temp[0]);
        for( int j=1; j<koniec;++j){
          if((odleglosc(wynik[i],temp[j])<best_odl)){
                best=temp[j];
                best_index=j;
              best_odl=odleglosc(wynik[i],temp[j]);
                }
           else {}

         }
         wynik[i+1]=best;
            temp[best_index]=temp[koniec-1];
           koniec--;

     }

    Image1->Canvas->Pen->Color=clRed;
Image1->Canvas->MoveTo(wsp[0][0],wsp[0][1]);
for(int k=0;k<ile_miast;k++){
Image1->Canvas->Pen->Style=psSolid;
 Image1->Canvas->Pen->Width=1;
 Image1->Canvas->LineTo(wsp[wynik[k]][0],wsp[wynik[k]][1]);
 }
 Image1->Canvas->LineTo(wsp[wynik[0]][0],wsp[wynik[0]][1]);
  int odleglos=0;
 for(int j=0;j<ile_miast-1;j++){
                odleglos+=odleglosc(wynik[j],wynik[j+1]);
                }
        odleglos+=odleglosc(wynik[ile_miast-1],wynik[0]);


 AnsiString naj="ANS:"+IntToStr(odleglos);
 Image1->Canvas->TextOutA(380,Image1->Height-30,naj);
}
//---------------------------------------------------------------------------

