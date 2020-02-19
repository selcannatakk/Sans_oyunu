1
1#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <locale.h>
int istatistik[50][6];
int counter=0;
int mod=0;
int modval;
int b=0;
int sonuclar[6][2];
int sayac=0;
int main()
{
    // program çalıştıgında açılan ana menünün kodları
    setlocale(LC_ALL,"Turkish");
    system("color A");
    printf("\n");
    printf("\t\t\tANA MENU\n");
    printf("\n");
    printf("\t\t1. Sans Oyunlari\n");
    printf("\t\t2. Cekilis Istatikleri\n");
    printf("\t\t3. Cikis\n\n");

    printf("Seciminizi Giriniz:");
    int secim;
    scanf("%d",&secim);

    // if elseyi kullanılarak kullanıcıdan seçim yapmasını istiyoruz.
    if(secim == 1)
    {
        system("cls");
        sans_oyunlari();
    }
    else if(secim == 2)
    {
        system("cls");
        cekilis_istatistikleri();
    }
    else if(secim == 3)
    {
        cikis();
    }
    else
    {
        printf("Hatali Secim Yaptiniz...\n");
        Sleep(1000);
        system("CLS");
        main();
    }
    return secim;
}

// sans oyunları alt menü kodları
int sans_oyunlari()
{
    printf("\n");
    printf("\t\t\tSANS OYUNLARI ALT MENÜSÜ\n");
    printf("\n");
    printf("\t\t1. Sayisal Loto Oynama\n");
    printf("\t\t2. Sans Topu Oynama\n");
    printf("\t\t3. On Numara Oynama\n");
    printf("\t\t4. Super Loto Oynama\n");
    printf("\t\t5. Ana Menu\n");
    printf("Oynamak istediginiz oyunu seciniz..");
    int so_secim;
    scanf("%d",&so_secim);

    // switch case kullanılarak alt menümüzün seçeneklerini kullanıcıya sunduk.

    do
	{
		switch (so_secim)
		{
		case 1:
			Sayisal_Loto();
			break;
		case 2:
			Sans_Topu();
			break;
		case 3:
			On_Numara();
			break;
		case 4:
			Super_Loto();
			break;
		case 5:
			system("cls");
			main();
			break;

// default kullanılarak istenilen seceneklerden birini kullanıcı secmeze böyle bir hata ile karsılasıcaktır.

		default:
			system("cls");
			printf("\n\n\t\tYanlis secim yaptiniz...");
			Sleep(1000);
			sans_oyunlari();
			break;
		}
	} while (so_secim <= 5 && so_secim >= 1);

	return so_secim;

}
    // sans oyunlarının ilk oyunu olan sayısal loto kodları

    int Sayisal_Loto()
	{
	    system("cls");
	    printf("\t\t\tSAYISAL LOTO OYUNUNA HOSGELDINIZ\n\n\n");
        int k_sayilar[6],r_sayilar[6];
        int dogru_t=0;
        int gecici;
        printf("Lütfen [1-49] arasi 6 farkli sayi giriniz::\n");   //kullanıcan altı sayı istiyoruz.
        for(int i=0;i<6;i++)
        {
            scanf("%d",&k_sayilar[i]);
            kontrol:if(k_sayilar[i]<=0)
            {
                printf("0 disinda bir sayi giriniz!\n");    // kullanıcı 0 girerse eger böyle bir hata ile karsılasıcaktır.
                scanf("%d",&k_sayilar[i]);
                goto kontrol;
            }
        }
            for(int i=0; i<6;i++)
            {
                for(int j=i+1; j<6; j++)
                {
                    if(k_sayilar[i] > k_sayilar[j])    // kullanıcının gırdıgı sayılar kucukten büğüye sıralanır.
                    {
                        gecici = k_sayilar[i];
                        k_sayilar[i] = k_sayilar[j];
                        k_sayilar[j] = gecici;
                    }
                }
            }
        printf("\nKullanicinin girdigi sayilar     ::\t");  // kullanıdan girilen sayılar ekrana yazdırılır
        for(int i=0; i<6; i++)
            printf("%d\t", k_sayilar[i]);
        srand(time(NULL));                               // sistem 6 adet random sayı uretmektedir.
        for(int i=0;i<6;i++)
        {
            tekrar:
            r_sayilar[i]=1+rand()%49;
            for(int j=0;j<i;j++)
            {
                if(r_sayilar[i]==r_sayilar[j])
                    goto tekrar;

            }
        }
        for(int i=0; i<6;i++)                               //altı adet üretilen random sayırları kucukten buyuge sıralanır.
            {
                for(int j=i+1; j<6; j++)
                {
                    if(r_sayilar[i] > r_sayilar[j])
                    {
                        gecici = r_sayilar[i];
                        r_sayilar[i] = r_sayilar[j];
                        r_sayilar[j] = gecici;
                    }
                }
                istatistik[b][i]=r_sayilar[i];       // sayısal lotonun istatisliği için cıkab sayıları diziye aktarıyoruz.
            }
            b++;
        printf("\n\nSistemin ürettigi sayilar        ::\t");  // sistemin ürettiği altı adet sayı ekrana yazılmaktadır.
        for(int i=0; i<6; i++)
            printf("%d\t", r_sayilar[i]);

            for(int i=0;i<6;i++)                      // sistemin ve kullanıcıdan alınan sayılar karsılastırırlır.
            {
                for(int j=0;j<6;j++)
                {
                    if(k_sayilar[i]==r_sayilar[j])
                    {
                        dogru_t+=1;                  // her dogru tahmınde dogru sayısını bır attırıyoruz.
                    }
                }
            }
            printf("\n\nDogru Tahmin Sayisi:%d",dogru_t);      // dogru tahmin sayisine göre puanlama yapılır.
            if(dogru_t==3)
                printf("\todulunuz: 32");
            else if(dogru_t==4)
                printf("\todulunuz: 64");
            else if(dogru_t==5)
                printf("\todulunuz: 128");
            else if(dogru_t==6)
                printf("\todulunuz: 256");
            else
                printf("\n\nOdul icin yeterli dogru tahminde bulunamadiniz...!\n");
            printf("\n\nOynamaya devam etmek istiyormusunuz?(e/E/h/H)");
            char devam;
            hata:scanf("%s",&devam);
            if(devam=='e' || devam=='E')
            {
                system("cls");
                Sayisal_Loto();
            }
            else if(devam=='h' || devam=='H')
            {
                system("cls");
                sans_oyunlari();
            }
             else
            {
                printf("\n\nYanlis bir secim girdiniz:!!!");
                goto hata;
            }
	}
    int Sans_Topu()
    {
        system("cls");
	    printf("\t\t\tSANS TOPU OYUNUNA HOSGELDINIZ\n\n\n");
        int k_sayilar[5],r_sayilar[5];
        int k_sayilar1,r_sayilar1;
        int dogru_t=0;
        int gecici;
        printf("Lütfen [1-34] arasi 5 farkli sayi giriniz::\n");
        for(int i=0;i<5;i++)
        {
            scanf("%d",&k_sayilar[i]);
            kontrol:if(k_sayilar[i]<=0)
            {
                printf("0 disinda bir sayi giriniz!\n");
                scanf("%d",&k_sayilar[i]);
                goto kontrol;
            }
        }
            printf("\nve [1-14] arasi 1 sayi giriniz::\n");
            scanf("%d",&k_sayilar1);
            kontrol2:if(k_sayilar1<=0)
            {
                printf("0 disinda bir sayi giriniz!\n");
                scanf("%d",&k_sayilar1);
                goto kontrol2;
            }

            for(int i=0; i<5;i++)
            {
                for(int j=i+1; j<5; j++)
                {
                    if(k_sayilar[i] > k_sayilar[j])
                    {
                        gecici = k_sayilar[i];
                        k_sayilar[i] = k_sayilar[j];
                        k_sayilar[j] = gecici;
                    }
                }
            }
        printf("\nKullanicinin girdigi sayilar   ::\t");
        for(int i=0; i<5; i++)
            printf("%d\t", k_sayilar[i]);
            printf("%d",k_sayilar1);
        srand(time(NULL));
        for(int i=0;i<5;i++)
        {
            tekrar:
            r_sayilar[i]=1+rand()%49;
            for(int j=0;j<i;j++)
            {
                if(r_sayilar[i]==r_sayilar[j])
                    goto tekrar;
            }
        }
        r_sayilar1=1+rand()%14;
        for(int i=0; i<5;i++)
            {
                for(int j=i+1; j<5; j++)
                {
                    if(r_sayilar[i] > r_sayilar[j])
                    {
                        gecici = r_sayilar[i];
                        r_sayilar[i] = r_sayilar[j];
                        r_sayilar[j] = gecici;
                    }
                }
            }
        printf("\n\nSistemin ürettigi sayilar      ::\t");
        for(int i=0; i<5; i++)
            printf("%d\t", r_sayilar[i]);
            printf("%d",r_sayilar1);

            for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(k_sayilar[i] == r_sayilar[j])
                    {
                        dogru_t+=1;
                    }
                }
            }
            if(k_sayilar1==r_sayilar1)
            {
                dogru_t+=1;
                printf("\n\nDogru tahmin sayisi:%d+1",dogru_t);
                if(dogru_t==2)
                    printf("\todulunuz: 2");
                else if(dogru_t==3)
                    printf("\todulunuz: 4");
                else if(dogru_t==4)
                    printf("\todulunuz: 16");
                else if(dogru_t==5)
                    printf("\todulunuz: 64");
                else if(dogru_t==6)
                    printf("\todulunuz: 256");
                else
                    printf("\n\nOdul icin yeterli dogru tahminde bulunamadiniz...!");
            }
            else
                printf("\n\nDogru Tahmin Sayisi:%d",dogru_t);
            if(dogru_t==3)
                printf("\todulunuz: 8");
            else if(dogru_t==4)
                printf("\todulunuz: 32");
            else if(dogru_t==5)
                printf("\todulunuz: 128");
            else
                printf("\n\nOdul icin yeterli dogru tahminde bulunamadiniz...!");
            printf("\n\nOynamaya devam etmek istiyormusunuz?(e/E/h/H)");
            char devam;
            hata:scanf("%s",&devam);
            if(devam=='e' || devam=='E')
            {
                system("cls");
                Sans_Topu();
            }
            else if(devam=='h' || devam=='H')
            {
                system("cls");
                sans_oyunlari();
            }
             else
            {
                printf("\n\nYanlis bir secim girdiniz:!!!");
                goto hata;
            }
    }
    int On_Numara()
    {
       system("cls");
	    printf("\t\t\tON NUMARA OYUNUNA HOSGELDINIZ\n\n\n");
        int k_sayilar[10],r_sayilar[22];
        int dogru_t=0;
        int gecici;
        printf("Lütfen [1-80] arasi 10 farkli sayi giriniz::\n");
        for(int i=0;i<10;i++)
        {
            scanf("%d",&k_sayilar[i]);
            kontrol:if(k_sayilar[i]<=0 || k_sayilar[i]>80)
            {
                printf("0 disinda veya 1-80 arasi bir sayi giriniz!\n");
                scanf("%d",&k_sayilar[i]);
                goto kontrol;
            }
        }
            for(int i=0; i<10;i++)
            {
                for(int j=i+1; j<10; j++)
                {
                    if(k_sayilar[i] > k_sayilar[j])
                    {
                        gecici = k_sayilar[i];
                        k_sayilar[i] = k_sayilar[j];
                        k_sayilar[j] = gecici;
                    }
                }
            }
        printf("\nKullanicinin girdigi sayilar     ::");
        for(int i=0; i<10; i++)
            printf("%d  ", k_sayilar[i]);
        srand(time(NULL));
        for(int i=0;i<22;i++)
        {
            tekrar:
            r_sayilar[i]=1+rand()%80;
            for(int j=0;j<i;j++)
            {
                if(r_sayilar[i]==r_sayilar[j])
                    goto tekrar;

            }
        }
        for(int i=0; i<22;i++)
            {
                for(int j=i+1; j<22; j++)
                {
                    if(r_sayilar[i] > r_sayilar[j])
                    {
                        gecici = r_sayilar[i];
                        r_sayilar[i] = r_sayilar[j];
                        r_sayilar[j] = gecici;
                    }
                }
            }

        printf("\n\nSistemin ürettigi sayilar        ::");
        for(int i=0; i<22; i++)
            printf("%d  ", r_sayilar[i]);

            for(int i=0;i<6;i++)
            {
                for(int j=0;j<22;j++)
                {
                    if(k_sayilar[i]==r_sayilar[j])
                    {
                        dogru_t+=1;
                    }
                }
            }
            printf("\n\nDogru Tahmin Sayisi:%d",dogru_t);
            if(dogru_t==0)
                printf("\todulunuz: 8");
            else if(dogru_t==6)
                printf("\todulunuz: 16");
            else if(dogru_t==7)
                printf("\todulunuz: 32");
            else if(dogru_t==8)
                printf("\todulunuz: 64");
            else if(dogru_t==9)
                printf("\todulunuz: 128");
            else if(dogru_t==10)
                printf("\todulunuz: 256");
            else
                printf("\n\nOdul icin yeterli dogru tahminde bulunamadiniz...!\n");
            printf("\n\nOynamaya devam etmek istiyormusunuz?(e/E/h/H)");
            char devam;
            hata:scanf("%s",&devam);
            if(devam=='e' || devam=='E')
            {
                system("cls");
                Sayisal_Loto();
            }
            else if(devam=='h' || devam=='H')
            {
                system("cls");
                sans_oyunlari();
            }
             else
            {
                printf("\n\nYanlis bir secim girdiniz:!!!");
                goto hata;
            }
    }
    int Super_Loto()
    {
      system("cls");
	    printf("\t\t\tSÜPER LOTO OYUNUNA HOSGELDINIZ\n\n\n");
        int k_sayilar[6],r_sayilar[6];
        int dogru_t=0;
        int gecici;
        printf("Lütfen [1-54] arasi 6 farkli sayi giriniz::\n");
        for(int i=0;i<6;i++)
        {
            scanf("%d",&k_sayilar[i]);
            kontrol:if(k_sayilar[i]<=0 || k_sayilar[i]>54)
            {
                printf("0 disinda veya 1-54 dan arasi bir sayi giriniz!\n");
                scanf("%d",&k_sayilar[i]);
                goto kontrol;
            }
        }
            for(int i=0; i<6;i++)
            {
                for(int j=i+1; j<6; j++)
                {
                    if(k_sayilar[i] > k_sayilar[j])
                    {
                        gecici = k_sayilar[i];
                        k_sayilar[i] = k_sayilar[j];
                        k_sayilar[j] = gecici;
                    }
                }
            }
        printf("\nKullanicinin girdigi sayilar     ::\t");
        for(int i=0; i<6; i++)
            printf("%d\t", k_sayilar[i]);
        srand(time(NULL));
        for(int i=0;i<6;i++)
        {
            tekrar:
            r_sayilar[i]=1+rand()%54;
            for(int j=0;j<i;j++)
            {
                if(r_sayilar[i]==r_sayilar[j])
                    goto tekrar;

            }
        }
        for(int i=0; i<6;i++)
            {
                for(int j=i+1; j<6; j++)
                {
                    if(r_sayilar[i] > r_sayilar[j])
                    {
                        gecici = r_sayilar[i];
                        r_sayilar[i] = r_sayilar[j];
                        r_sayilar[j] = gecici;
                    }
                }
            }

        printf("\n\nSistemin ürettigi sayilar        ::\t");
        for(int i=0; i<6; i++)
            printf("%d\t", r_sayilar[i]);

            for(int i=0;i<6;i++)
            {
                for(int j=0;j<6;j++)
                {
                    if(k_sayilar[i]==r_sayilar[j])
                    {
                        dogru_t+=1;
                    }
                }
            }
            printf("\n\nDogru Tahmin Sayisi:%d",dogru_t);
            if(dogru_t==3)
                printf("\todulunuz: 32");
            else if(dogru_t==4)
                printf("\todulunuz: 64");
            else if(dogru_t==5)
                printf("\todulunuz: 128");
            else if(dogru_t==6)
                printf("\todulunuz: 256");
            else
                printf("\n\nOdul icin yeterli dogru tahminde bulunamadiniz...!\n");
            printf("\n\nOynamaya devam etmek istiyormusunuz?(e/E/h/H)");
            char devam;
            hata:scanf("%s",&devam);
            if(devam=='e' || devam=='E')
            {
                system("cls");
                Sayisal_Loto();
            }
            else if(devam=='h' || devam=='H')
            {
                system("cls");
                sans_oyunlari();
            }
             else
            {
                printf("\n\nYanlis bir secim girdiniz:!!!");
                goto hata;
            }

    }
int cekilis_istatistikleri()
{

    int sifir;
    hesapla2:
    modval=51;
    mod=0;
    int zerocount=0;
    hesapla:
    for(int i=0;i<b;i++)
    {
        for(int j=0;j<6;j++)
        {
            counter=0;
            for(int k=0;k<b;++k)
            {
                for(int m=0;m<6;m++)
                {
                    if(istatistik[k][m]==istatistik[i][j] && istatistik[k][m]!=0)
                    {
                        counter++;
                    }
                }
            }
            if (counter>mod)
            {
                mod=counter;
                modval=istatistik[i][j];
            }
        }
    }

    for(int c=0;c<b;c++)
    {
        for(int v=0;v<6;v++)
        {
            if(istatistik[c][v]==modval && istatistik[c][v]!=0 && mod>1)
            {
                sonuclar[sayac][1]=istatistik[c][v];
                sonuclar[sayac][2]=mod;
                istatistik[c][v]=0;
                zerocount++;
                goto hesapla;
            }
        }
    }
    if(zerocount==mod)
    {
        sayac++;
        //printf("deneme\n");
        goto hesapla2;
    }
    for(int i=0;i<sayac;i++)
    {
        printf("sayi:%d\tadedi:%d\n",sonuclar[i][1],sonuclar[i][2]);
    }
    printf("\n");
    scanf("%d",sifir);

}
int cikis()
{
    char secim1;
    system("cls");
    printf("\n\n Cikmak Istediginizden Emin Misiniz..?(e/E/h/H) : ");
    scanf("%s",&secim1);
    if(secim1 == 'e' || secim1 == 'E')
    {
            system("cls");
			printf("Cikis Yapiliyor...");
			Sleep(2000);
			exit(1);
    }
    else if(secim1 == 'h' || secim1 == 'H')
    {
        system("cls");
        printf("Ana Menuye Yonlendiriliyorsunuz...\n");
        system("cls");
        main();
    }
    else
    {
        system("cls");
        printf("Yanlis bir secim girdiniz");
        Sleep(1000);
        cikis();
    }
    return secim1;
}
