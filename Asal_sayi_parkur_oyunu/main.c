#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randuret(int randd[], int ust, int deger1,int arti);
void sirala(int siradizi[],int siraboyut);
void asalkontrol(int asaldizid[],int kontengels);
void dosyayaz(int ilkhp ,int yazhp[],int yazd1[],int yazd2[],int yazddurum[],int yazengels,int yazfinalhp);
void diziolustur();

struct hpler{

int ilkhp;
int finalhp;

};



int main()
{

    diziolustur();

return 0;
}


void diziolustur(){

    int *engeller,*parkurboyu,*engelsayi;
    engeller=malloc(5*sizeof(int));
    parkurboyu=malloc(sizeof(int));
    engelsayi=malloc(sizeof(int));

    randuret(parkurboyu,51,1,50);
    randuret(engelsayi,4,1,2);
    randuret(engeller,parkurboyu[0]-5,engelsayi[0],5);

    printf("---OYUN CALISTIRILDI, OYUN BILGILERINI DOSYADAKI 'LOG.TXT' ICERISINDE GOREBILIRSINIZ !!!");
    printf("\n---GAME STARTED, YOU CAN SEE GAME INFORMATION IN 'LOG.TXT' IN THE FILE !!!");
    sirala(engeller,engelsayi[0]);

    free(engeller);
    free(engelsayi);
    free(parkurboyu);

}


void dosyayaz(int ilkhp ,int yazhp[],int yazd1[],int yazd2[],int yazddurum[],int yazengels,int yazfinalhp){

        int m;
        FILE *dosya;

    dosya=fopen("log.txt","w+");

    fprintf(dosya,"--YARISMA BASLADI--\n");
    fprintf(dosya,"yarismaci HP:%d \n",ilkhp);

        for(m=0;m<yazengels;m++){

                fprintf(dosya,"Yarismaci %d. metreye kadar engelle karsilasmadi. \n",yazd2[m]);

                if(yazddurum[m]==0){
                fprintf(dosya,"%d. metrede engel var.%d ile %d aralarinda asaldir. \n",yazd2[m],yazd1[m],yazd2[m]);
                fprintf(dosya,"yarismaci HP:%d \n",yazhp[m]);
                }
                else if(yazddurum[m]==1){
                fprintf(dosya,"%d. metrede engel var.%d ile %d aralarinda asal degildir. \n",yazd2[m],yazd1[m],yazd2[m]);
                fprintf(dosya,"yarismaci HP:%d \n",yazhp[m]);

                }
                yazfinalhp=yazhp[m];
                if(yazhp[m]<0){
                       break;
                        }

        }

    if(yazfinalhp>0){
            fprintf(dosya,"TEBRIKLER !!! YARISMAYI %d HP ILE BITIRDINIZ\n",yazfinalhp);
    }
    else{
        fprintf(dosya,"UZGUNUM !!! YARISMAYI TAMAMLAYAMADIN\n");
    }

    fclose(dosya);

}


void asalkontrol(int asaldizid[],int kontengels){

    int i,s,kucuk,m,ilkhp,dizi1[5],dizi2[5],dizidurum[5],hpdizi[5];

    struct hpler hpseri1;
    hpseri1.ilkhp=100;
    hpseri1.finalhp=0;


    ilkhp=hpseri1.ilkhp;

for(m=0;m<kontengels;m++){
    s=0;
        if(hpseri1.ilkhp<asaldizid[m])kucuk=hpseri1.ilkhp;
        else kucuk=asaldizid[m];
            for(i=2;i<=kucuk;i++){
                if(hpseri1.ilkhp%i==0 && asaldizid[m]%i==0) {

                s=1;
                dizi1[m]=hpseri1.ilkhp;
                dizi2[m]=asaldizid[m];
                dizidurum[m]=s;

                }
                else{

                dizi1[m]=hpseri1.ilkhp;
                dizi2[m]=asaldizid[m];
                dizidurum[m]=s;

                }

            }

if (s==0){

        hpseri1.ilkhp-=asaldizid[m];
        hpdizi[m]=hpseri1.ilkhp;

        if(hpseri1.ilkhp<0){break;}

}

else if(s==1){

        hpdizi[m]=hpseri1.ilkhp;

    }

}


dosyayaz(ilkhp,hpdizi,dizi1,dizi2,dizidurum,kontengels,hpseri1.finalhp);

    for(i=0;i<kontengels;i++){

            if(hpseri1.ilkhp<0){break;}

    }

}


void sirala(int siradizi[],int siraboyut){

int i,j,*ptrtemp;

for(i=0;i<siraboyut-1;i++){

       for(j=0;j<siraboyut-i-1;j++){

            if(siradizi[j]>siradizi[j+1]){

            *ptrtemp=siradizi[j];
            siradizi[j]=siradizi[j+1];
            siradizi[j+1]=*ptrtemp;

            }

        }

}


asalkontrol(siradizi,siraboyut);

}


void randuret(int randd[], int ust, int deger1,int arti){

srand(time(NULL));

    int i, temp1,k,m;

    for(i=0; i<deger1; i++){

        temp1 = arti+rand()%ust;
        randd[i]=temp1;

            for(m=0;m<i;m++) {

                for(k=m+1;k<=i;k++){

                    if(randd[m]==randd[k]){

                            i--;
                    }

                }
            }

    }


}

