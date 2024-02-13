#include <stdio.h>
#include <string.h>
int counter = 0;

//Ogrenci veri yapisi
struct Ogrenci {
    int number;
    char name[20];
    char surname[20];
};

//Ogrencieri listelemek icin fonksiyon
void listStudents(struct Ogrenci ogr[], int size) {
    if(size == 0) {
        printf("Hic ogrenci bulunamadi...\n");
        return;
    }

    for(int i = 0; i<size; i++) {
        printf("%d, %s, %s\n",ogr[i].number, ogr[i].name, ogr[i].surname);
    }
}

//Gerkeli veri yapilari
char ogretmenismi[20];
char ogretmensoyismi[20];
int ogretmenyasi;
char okulismi[20];
char dersismi[20];

//Ogrenci eklemek icin fonksiyon
struct Ogrenci addStudent() {
    struct Ogrenci yeniOgr;
    printf("Ogrenci numarasi giriniz:");
    scanf("%d", &yeniOgr.number);
    printf("Isim giriniz:");
    scanf("%s", yeniOgr.name);
    printf("Soyisim giriniz:");
    scanf("%s", yeniOgr.surname);
    
    return yeniOgr;
}

//Okul ismi gostermek icin fonksiyon
void okulIsminiGoster(char* okulismi) {
    printf("%s", okulismi);
}

//Okul ismi degistirmek icin fonksiyon
void okulIsminiGuncelle() {
    printf("Okul ismini giriniz:");
    scanf(" %[^\n]s", okulismi);
}

//Ders ismi gostermek icin fonksiyon
void dersIsminiGoster(char* dersismi) {
    printf("%s\n", dersismi);
}

//Ders ismi degistirmek icin fonksiyon
void dersGuncelle() {
    printf("Ders ismini giriniz:");
    scanf("%s", dersismi);
}

//Ogretmen eklemek icin fonksiyon
void ogretmenEkle(){
    printf("Ogretmen ismi ekleyiniz: ");
    scanf("%s", ogretmenismi);
    printf("Ogretmen soyismi ekleyiniz: ");
    scanf("%s", ogretmensoyismi);
    printf("Ogretmen yasi ekleyiniz: ");
    scanf("%d", &ogretmenyasi);
}

//Ogretmen bilgisini gostermek icin fonksiyon
void ogretmenBilgiGoster() {
    printf("%s, %s, %d", ogretmenismi, ogretmensoyismi, ogretmenyasi);
}

int main() {
    //Ogrenci structi olusturulur
    struct Ogrenci ogr;
    //Ogrenci sayisi belirlenir
    const int ogrenciSayisi = 30;
    //Sinif olusturulur
    struct Ogrenci sinif[ogrenciSayisi];
    int choice = 9;
    int secondchoice = 9;
    

    while(choice != 3) {
        printf("==Hosgeldiniz==\n");
        printf("(1) Ogrencileri listele\n");
        printf("(2) Hakkinda\n");
        printf("(3) Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            listStudents(sinif, counter);
            break;
        //Alt menuye girildigi zaman
        case 2:
            secondchoice = 9;
            //Kullanicidan input alinir
            while (secondchoice != 0){
                printf("(1) Ogrenci Ekle\n");
                printf("(2) Ogrenci Cikar\n");
                printf("(3) Okul ismini goster\n");
                printf("(4) Okul ismini guncelle\n");
                printf("(5) Ogretmen ekle\n");
                printf("(6) Ogretmen bilgisi goster\n");
                printf("(7) Ders ismini goster\n");
                printf("(8) Ders ismini guncelle\n");
                printf("(0) Ust menuye don\n");
                printf("Seciminizi yapin: ");
                scanf("%d", &secondchoice);
                
                switch (secondchoice){
                //Alt menu inputlari islenir
                case 1:
                    sinif[counter] = addStudent();
                    counter++;
                    break;
                case 2:
                //Ogrenci cikartma islemi, listelenemeyerek yapilir daha sonrasinda eklenecek ogrenci ustune eklenir
                    counter--;
                    break;
                case 3: 
                //Okul ismini gosterir
                    okulIsminiGoster(okulismi);
                    break;
                case 4:
                //Okul ismini gunceller
                    okulIsminiGuncelle();
                    break;
                case 5:
                //Ogretmen ekler
                    ogretmenEkle();
                    break;
                case 6:
                //Ogretmen bilgilerini gosterir
                    ogretmenBilgiGoster();
                    break;
                case 7:
                //Ders ismini gosterir
                    dersIsminiGoster(dersismi);
                    break;
                case 8:
                //Ders ismini degistirir
                    dersGuncelle();
                    break;
                }
            }
            break;
        }
    }


    return 0;
}
