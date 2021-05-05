#include <stdio.h>
#include <stdlib.h>

 enum MATINE{film1=1,film2,film3,film4,film5} ;
struct salon
{
    int izleyicisayisi;
    int koltuk[50];
    enum MATINE film1;
    enum MATINE film2;
    enum MATINE film3;
    enum MATINE film4;
    enum MATINE film5;

} green, red, blue;


FILE *fp;
int i=0,j=0,k=0,menu,result1=1,result2=1,hasilat=0,ogrenci=20,tam=30,salonsecim,filmsecim,biletsecim;
char username[20],password[20],tempusername[20],temppassword[20],uyeler[150][20],salonadi[5];

int main()
{

    koltuklar();
    mainmenu();
}

void koltuklar() {
    for(int i = 1; i <=50; i++){
    green.koltuk[i]= i;
    blue.koltuk[i]= i;
    red.koltuk[i]= i;
    }
}

void mainmenu(){
    printf("Uye olmak icin 1 e basin\n");
    printf("Giris yapmak icin 2 ye basin\n");
    printf("Izleyici istatislikleri icin 3 e basin\n");
    scanf("%d",&menu);
    if (menu==1)
        uyeol();
    else if(menu==2)
        girisyap();
    else if(menu==3)
        {
            istatislikler();
        }
    else
        printf("Hatali tiklama yaptiniz");
}
void uyeol() {
        fp= fopen("sifreler.txt","a+");
        printf("Kullanici Adiniz: ");
        scanf("%s",&username);
        printf("Sifreniz: ");
        scanf("%s",&password);
        fprintf(fp,"%s %s ",&username,&password);
        fclose(fp);
        printf("\n ana menuye yonlendiriliyorsunuz.... \n \n");
        mainmenu();
}
void girisyap(){
    fp=fopen("sifreler.txt","r+");
    while(!feof(fp))
        {
        fscanf(fp,"%s",uyeler[j]);
        j++;
        }
    printf("Kullanici Adiniz: ");
    scanf("%s",&tempusername);
    printf("Sifreniz: ");
    scanf("%s",&temppassword);
    int sayac=0;
    for(i=0;i<150;++i){
        k=i+1;
        result1 = strcmp(tempusername,uyeler[i]);
        result2 = strcmp(temppassword,uyeler[k]);
        if( (result1==0) && (result2==0) ) {
            printf("\n \ngiris basarili\n\n");
            sayac++;
            biletal();
            break;
        }
    }
    if(sayac==0){
        printf("\n \nuye bilgileri bulunamadi \n \n");
        printf("\nana menuye yonlendiriliyorsunuz.... \n \n \n");
        mainmenu();
    }
    fclose(fp);
}

void biletal(){
    printf("lutfen bilet tipini seciniz\n");
    printf("ogrenci: 20tl \t tam: 30tl \nogrenci icin 1 tam icin 2 ye basiniz.\n");
    printf("seciminiz: ");
    scanf("%d",&biletsecim);
    if(biletsecim==1)
        hasilat+=20;
    else if(biletsecim==2)
        hasilat+=30;
    else
        printf("hatali secim yaptiniz");

    fp= fopen("log.txt","a+");
    fprintf(fp,"%d ",hasilat);
    fclose(fp);
    printf("lutfen sinema salonunu seciniz.\n");
    printf("salonlar: \t red icin 1 \t blue icin 2 \t green icin 3\n");
    printf("seciminiz: ");
    scanf("%d",&salonsecim);
    if(salonsecim==1){
        printf("izlemek istediginiz filmi seciniz\n");
        printf("film1 icin 1 e basiniz\n film2 icin 2 e basiniz\n film3 icin 3 e basiniz\n");
        printf("seciminiz: ");
        scanf("%d",&filmsecim);
        if(filmsecim==1) {
            red.film1+=1;
            red.izleyicisayisi+=1;
            koltuksec();
        }
        else if(filmsecim==2) {
            red.film2+=1;
            red.izleyicisayisi+=1;
            koltuksec();
        }
        else if(filmsecim==3) {
            red.film3+=1;
            red.izleyicisayisi+=1;
            koltuksec();
        }
    }
    if(salonsecim==2){
        printf("izlemek istediginiz filmi seciniz\n");
        printf("film1 icin 1 e basiniz\n film2 icin 2 e basiniz\n film3 icin 3 e basiniz\n");
        printf("seciminiz: ");
        scanf("%d",&filmsecim);
        if(filmsecim==1) {
            blue.film1++;
            blue.izleyicisayisi+=1;
            koltuksec();
        }
        else if(filmsecim==2) {
            blue.film2+=1;
            blue.izleyicisayisi+=1;
            koltuksec();
        }
        else if(filmsecim==3) {
            blue.film3+=1;
            blue.izleyicisayisi+=1;
            koltuksec();
        }
    }
    if(salonsecim==3){
        printf("izlemek istediginiz filmi seciniz\n");
        printf("film1 icin 1 e basiniz\n film2 icin 2 e basiniz\n film3 icin 3 e basiniz\n");
        printf("seciminiz: ");
        scanf("%d",&filmsecim);
        if(filmsecim==1) {
            green.film1+=1;
            green.izleyicisayisi+=1;
            koltuksec();
        }
        else if(filmsecim==2) {
            green.film2+=1;
            green.izleyicisayisi+=1;
            koltuksec();
        }
        else if(filmsecim==3) {
            green.film3++;
            green.izleyicisayisi+=1;
            koltuksec();
        }
    }
}

void koltuksec(){
    //pointer kullandim
    int *p;
    p=red.koltuk;
    for(i=0;i<=51;i++)
    {
        if(*(p+i)!=0) {
            *(p+i)=0;
            printf("\n %d numarali koltukta biletiniz alinmistir \n IYI SEYIRLER DILERIZ....",*(p+i));
            break;
        }
    }
    printf("\n ana menuye yonlendiriliyorsunuz.... \n \n");
    mainmenu();
}

void istatislikler(){
    printf("\n \nhasilat: %d \n \n",hasilat);
    printf("red salonu izleyici sayisi %d \n",red.izleyicisayisi);
    printf("red salonu film 1 izleyen sayisi: %d \n",red.film1-50);
    printf("red salonu film 2 sayisi %d \n",red.film2);
    printf("red salonu film 3 izleyen sayisi: %d \n \n \n",red.film3);
    printf("blue salonu izleyici sayisi %d \n",blue.izleyicisayisi);
    printf("blue salonu film 1 izleyen sayisi: %d \n ",blue.film1-50);
    printf("blue salonu film 2 sayisi %d \n",blue.film2);
    printf("blue salonu film 3 izleyen sayisi: %d \n \n \n",blue.film3);
    printf("green salonu izleyici sayisi %d \n",green.izleyicisayisi);
    printf("green salonu film 1 izleyen sayisi: %d \n",green.film1-50);
    printf("green salonu film 2 sayisi %d \n",green.film2);
    printf("green salonu film 3 izleyen sayisi: %d \n",green.film3);
    fp= fopen("log.txt","a+");
    fprintf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d",red.izleyicisayisi,red.film1-50,red.film2,red.film3,blue.izleyicisayisi,blue.film1-50,blue.film2,blue.film3,green.izleyicisayisi,green.film1-50,green.film2,green.film3);
    fclose(fp);
}
