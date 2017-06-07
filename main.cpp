#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

struct karta{
    int kolor; //1-pik, 2-kier, 3-karo, 4-trefl // NIE MA ZNACZENIA
    int kod; //2-2, 3-3, 4-4, 5-5, 6-6, 7-7, 8-8, 9-9, 10-10, 11-J, 12-Q, 13-K, 14-A
    int wartosc;
    bool uzyta; //nieużyta-0, użyta-1
};

void wypelnienie_talii(struct karta* stos,int l_talii);
void wyswietl_karte(struct karta* karta);
int szukaj_i_usun(struct karta* stos,int l_talii,int kod);
int sprawdz_randomowy_wynik_rozdania(struct karta* stos,int l_talii,int suma_kart_krupiera,int asy_krupiera);

int main(){
    int l_talii;
    char symbol; //a-As, k-Krol, q-Dama, j-Walet, t-10, 9,8,7,6,5,4,3,2
    char symbol_karty_krupiera;
    int suma_kart_krupiera;
    int asy_krupiera=0;
    struct karta* stos;
    int siedemnsatki=0;
    int osiemnastki=0;
    int dziewietnastki=0;
    int dwudziestki=0;
    int dwudziestkijedynki=0;
    int fury=0;
    int blackjacki=0;
    int wynik=0;
    double j=0;

    srand(time(NULL));

    cout<<"Wprowadz ilosc talii: ";
    cin>>l_talii;
    stos = new struct karta[52*l_talii];

    wypelnienie_talii(stos,l_talii);
    /*
    for(int i=0;i<52*l_talii;i++) wyswietl_karte(&stos[i]);
    */
    while(1){

        cout<<"\nWprowadz, karty, ktorych juz nie ma w stosie krupiera (tylko symbole).\na-as, k-krol, d-dama, w-walet, t-dziesiatka, 9-9, 8-8, ... \ne - KONIEC WPROWADZANIA \n";
        cout<<"Podaj symbole (w ciagu), ciag zakoncz 'e': ";
        while(symbol!='e'){
            cin>>symbol;
            if(symbol=='a'){
                szukaj_i_usun(stos,l_talii,14);
            }
            if(symbol=='k'){
                szukaj_i_usun(stos,l_talii,13);
            }
            if(symbol=='d'){
                szukaj_i_usun(stos,l_talii,12);
            }
            if(symbol=='w'){
                szukaj_i_usun(stos,l_talii,11);
            }
            if(symbol=='t'){
                szukaj_i_usun(stos,l_talii,10);
            }
            if(symbol=='9'){
                szukaj_i_usun(stos,l_talii,9);
            }
            if(symbol=='8'){
                szukaj_i_usun(stos,l_talii,8);
            }
            if(symbol=='7'){
                szukaj_i_usun(stos,l_talii,7);
            }
            if(symbol=='6'){
                szukaj_i_usun(stos,l_talii,6);
            }
            if(symbol=='5'){
                szukaj_i_usun(stos,l_talii,5);
            }
            if(symbol=='4'){
                szukaj_i_usun(stos,l_talii,4);
            }
            if(symbol=='3'){
                szukaj_i_usun(stos,l_talii,3);
            }
            if(symbol=='2'){
                szukaj_i_usun(stos,l_talii,2);
            }
        }
        /*
        for(int i=0;i<52*l_talii;i++){
            if(stos[i].uzyta==0){
                wyswietl_karte(&stos[i]);
            }
        }
        */

        cout<<"\nPodaj jaka karte posiada krupier (tylko symbol).\nPodaj symbol: ";
        cin>>symbol_karty_krupiera;
        if(symbol_karty_krupiera=='a'){
            asy_krupiera++;
            suma_kart_krupiera=11;
            if(szukaj_i_usun(stos,l_talii,14)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='k'){
            suma_kart_krupiera=10;
            if(szukaj_i_usun(stos,l_talii,13)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='d'){
            suma_kart_krupiera=10;
            if(szukaj_i_usun(stos,l_talii,12)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='w'){
            suma_kart_krupiera=10;
            if(szukaj_i_usun(stos,l_talii,11)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='t'){
            suma_kart_krupiera=10;
            if(szukaj_i_usun(stos,l_talii,10)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='9'){
            suma_kart_krupiera=9;
            if(szukaj_i_usun(stos,l_talii,9)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='8'){
            suma_kart_krupiera=8;
            if(szukaj_i_usun(stos,l_talii,8)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='7'){
            suma_kart_krupiera=7;
            if(szukaj_i_usun(stos,l_talii,7)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='6'){
            suma_kart_krupiera=6;
            if(szukaj_i_usun(stos,l_talii,6)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='5'){
            suma_kart_krupiera=5;
            if(szukaj_i_usun(stos,l_talii,5)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='4'){
            suma_kart_krupiera=4;
            if(szukaj_i_usun(stos,l_talii,4)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='3'){
            suma_kart_krupiera=3;
            if(szukaj_i_usun(stos,l_talii,3)==1){
                system("clear");
                continue;
            }
        }
        if(symbol_karty_krupiera=='2'){
            suma_kart_krupiera=2;
            if(szukaj_i_usun(stos,l_talii,2)==1){
                system("clear");
                continue;
            }
        }

            while(1){
                wynik=sprawdz_randomowy_wynik_rozdania(stos,l_talii,suma_kart_krupiera,asy_krupiera);
                if(wynik==-1){
                    blackjacki++;
                }
                if(wynik==17){
                    siedemnsatki++;
                }
                if(wynik==18){
                    osiemnastki++;
                }
                if(wynik==19){
                    dziewietnastki++;
                }
                if(wynik==20){
                    dwudziestki++;
                }
                if(wynik==21){
                    dwudziestkijedynki++;
                }
                if(wynik>21){
                    fury++;
                }
                j=j+1;
                if(j==2000000){
                    cout<<endl;
                    cout<<"===== \n\n";
                    cout<<"     ";
                    cout<<"17: "<<siedemnsatki*100/j <<" %\n";
                    cout<<"     ";
                    cout<<"18: "<<osiemnastki*100/j <<" %\n";
                    cout<<"     ";
                    cout<<"19: "<<dziewietnastki*100/j <<" %\n";
                    cout<<"     ";
                    cout<<"20: "<<dwudziestki*100/j <<" %\n";
                    cout<<"     ";
                    cout<<"21: "<<dwudziestkijedynki*100/j <<" %\n";
                    cout<<"     ";
                    cout<<"21 (BJ): "<<blackjacki*100/j <<" %\n";
                    cout<<"     ";
                    cout<<"Fura: "<<fury*100/j <<" %\n";
                    cout<<"\n=====";
                    cout<<endl;
                    break;
                }
            }
            while(getchar()!='\n');
            cout<<"BAW SIE DALEJ (ENTER)";
            getchar();
            system("clear");
        }

}

int sprawdz_randomowy_wynik_rozdania(struct karta* stos,int l_talii,int suma_kart_krupiera,int asy_krupiera){
    int losowa;
    int i;
    struct karta* stos_pomocniczy;
    stos_pomocniczy = new struct karta[52*l_talii];
    for(i=0;i<52*l_talii;i++){
        stos_pomocniczy[i].kod=stos[i].kod;
        stos_pomocniczy[i].wartosc=stos[i].wartosc;
        stos_pomocniczy[i].kolor=stos[i].kolor;
        stos_pomocniczy[i].uzyta=stos[i].uzyta;
    }
    i=1;
    //cout<<"\n=====\n";
    while(suma_kart_krupiera<=16){
        i++;
        losowa=rand()%(52*l_talii);
        while(stos_pomocniczy[losowa].uzyta!=0){
            losowa=rand()%(52*l_talii);
        }
        stos_pomocniczy[losowa].uzyta=1;
        //wyswietl_karte(&stos_pomocniczy[losowa]);
        if(stos_pomocniczy[losowa].kod==14){
            asy_krupiera++;
        }
        suma_kart_krupiera+=stos_pomocniczy[losowa].wartosc;
        if(i==2 && suma_kart_krupiera==21){
            delete stos_pomocniczy;
            //getchar();
            //cout<<"KONIEC (BJ)\n\n";
            return -1;
        }
        while(suma_kart_krupiera>21){
            if(asy_krupiera!=0){
                asy_krupiera--;
                suma_kart_krupiera-=10;
            }else{
                break;
            }
        }
        //cout<<suma_kart_krupiera;
        //cout<<"\n=====\n";
    }
    delete stos_pomocniczy;
    //getchar();
    //cout<<"KONIEC\n\n";
    return suma_kart_krupiera;

}

int szukaj_i_usun(struct karta* stos,int l_talii,int kod){
    for(int i=0;i<52*l_talii;i++){
        if(stos[i].kod==kod && stos[i].uzyta!=1){
            stos[i].uzyta=1;
            break;
        }
        if(i==52*l_talii-1){
            cout<<"Nie ma juz takiej karty!";
            return 1;
        }
    }
    return 0;
}

void wyswietl_karte(struct karta* karta){
    if(karta->kod==2){
        cout<<"2 ";
    }
    if(karta->kod==3){
        cout<<"3 ";
    }
    if(karta->kod==4){
        cout<<"4 ";
    }
    if(karta->kod==5){
        cout<<"5 ";
    }
    if(karta->kod==6){
        cout<<"6 ";
    }
    if(karta->kod==7){
        cout<<"7 ";
    }
    if(karta->kod==8){
        cout<<"8 ";
    }
    if(karta->kod==9){
        cout<<"9 ";
    }
    if(karta->kod==10){
        cout<<"10 ";
    }
    if(karta->kod==11){
        cout<<"J ";
    }
    if(karta->kod==12){
        cout<<"Q ";
    }
    if(karta->kod==13){
        cout<<"K ";
    }
    if(karta->kod==14){
        cout<<"A ";
    }
    if(karta->kolor==1){
        cout<<"Pik\n";
    }
    if(karta->kolor==2){
        cout<<"Kier\n";
    }
    if(karta->kolor==3){
        cout<<"Karo\n";
    }
    if(karta->kolor==4){
        cout<<"Trefl\n";
    }
}

void wypelnienie_talii(struct karta* stos, int l_talii){
    int i=0,j=0;
    for(j=0;j<l_talii;j++){
        for(i=0;i<13;i++){
            i=i+j*52;
            stos[i].kolor=1;
            stos[i+13].kolor=2;
            stos[i+26].kolor=3;
            stos[i+39].kolor=4;
            i=i-j*52;
        }
        for(i=0;i<52;i=i+13){
            i=i+j*52;
            stos[i].kod=14;
            stos[i+1].kod=13;
            stos[i+2].kod=12;
            stos[i+3].kod=11;
            stos[i+4].kod=10;
            stos[i+5].kod=9;
            stos[i+6].kod=8;
            stos[i+7].kod=7;
            stos[i+8].kod=6;
            stos[i+9].kod=5;
            stos[i+10].kod=4;
            stos[i+11].kod=3;
            stos[i+12].kod=2;
            i=i-j*52;
        }
        for(i=0;i<52;i=i+13){
            i=i+j*52;
            stos[i].wartosc=11;
            stos[i+1].wartosc=10;
            stos[i+2].wartosc=10;
            stos[i+3].wartosc=10;
            stos[i+4].wartosc=10;
            stos[i+5].wartosc=9;
            stos[i+6].wartosc=8;
            stos[i+7].wartosc=7;
            stos[i+8].wartosc=6;
            stos[i+9].wartosc=5;
            stos[i+10].wartosc=4;
            stos[i+11].wartosc=3;
            stos[i+12].wartosc=2;
            i=i-j*52;
        }
        for(i=-1;i<52;i++){
            i=i+j*52;
            stos[i].uzyta=0;
            i=i-j*52;
        }
    }

}
