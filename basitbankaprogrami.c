#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h> 


   float bakiyeler[10]={500,600};




void hesaplar(int hesapno[],int hesapSayisi )
{
	
	int j;
	
srand(time(NULL));
	for(j=0;j<hesapSayisi;j++)
	 {
		

	int random = 5000 + rand() % 8000;

	 	hesapno[j]=random;

	 }	
		
}         

void kullaniciadlari(char kullaniciadi[][30],int kullaniciadisayisi,int kullaniciadiuzunlugu)
{
	int j;
    kullaniciadisayisi=2;
	for(j=0;j<kullaniciadisayisi;j++)
	 {
	 
	printf("%d.musteri kullanici ismini gir\n",j+1);
	scanf("%s",&kullaniciadi[j]);	
     }
     
}

void ciktimusterilerin(int hesapno[],char kullaniciadi[][30],int kullaniciadisayisi,int kullaniciadiuzunlugu)
{
	int i,j;
    kullaniciadisayisi=2;
	for(i=0;i<kullaniciadisayisi;i++)
	{
		printf("%d.musterinin kullanici ismi %s ve hesap no'su %d\n\n",i+1,kullaniciadi[i],hesapno[i]);
	}
}


		
void para_cekme(int hesapno[],float bakiyeler[],int hesapSayisi,int islemYapilan_hesapNo)    // bu kismi özgüre sor.Dogru tanimlamis miyim diye mantgini sor
{
	

	printf("para cekme menusune hos geldiniz");
	
	 
	 int i;
	 int kacincihesap=-2;
	 for(i=0;i<hesapSayisi;i++)
	 {
	 	if(islemYapilan_hesapNo==hesapno[i])
	 	{	
	 	printf("tebrikler dogru girdiniz");
	 		kacincihesap=i;
	 	break;
		 }	
	 	
	 }
	
	if(kacincihesap!=1 && kacincihesap!=0) 
	{
 	
      printf("lutfen dogru girdiginizden emin olunuz");
      return;
	
}

	float miktar;
	printf("lutfen cekmek istediginiz miktari giriniz");
	scanf("%f",&miktar);
	
	if(miktar>0)
	{
	bakiyeler[kacincihesap]=bakiyeler[kacincihesap]-miktar;
	printf("para basariyla cekilmistir.Cekilen miktar :%.2f , bakiyenizde kalan miktar : %.2f\n\n",miktar,bakiyeler[kacincihesap]);	
		
	}
	
}

void  para_yatirma(int hesapno[],float bakiyeler[],int hesapSayisi,int islemYapilan_hesapNo)
{

	
	printf("para yatirma menüsüne hos geldiniz");
	
	int i;
	int kacincihesap=-2;
	for(i=0;i<hesapSayisi;i++)
	{
		if(islemYapilan_hesapNo==hesapno[i])
		{
	
		kacincihesap=i;
		break;
		}
		
}
		if(kacincihesap!=1 && kacincihesap!=0)
		{
			printf("gecerli bir hesap nosu giriniz");
			return; // fonksiyondan cikmasi icin
		}
		
		else {
			float miktar;
				printf("kac lira yatirmak istiyorsunuz hesabiniza");
				scanf("%f",&miktar);
				
				if(miktar>0)
				{
					bakiyeler[kacincihesap]=bakiyeler[kacincihesap]+miktar;
					printf("bakiyenize %.2f miktar yatirildi guncel bakiyeniz = %.2f\n\n",miktar,bakiyeler[kacincihesap]);
					
				}
		}

		
	
	
	
}

void para_transferi(int hesapno[],float bakiyeler[],int hesapSayisi,int islemYapilan_hesapNo)
	{
		
   
    printf("para transferi menusune hos geldiniz");
   
    int i;
    int kacincihesap=-2;
    for(i=0;i<hesapSayisi;i++)
    	{

if(islemYapilan_hesapNo==hesapno[i])
		{
	
		kacincihesap=i;
		}
		
	}
	if(kacincihesap!=1 && kacincihesap!=0)
		{
			printf("gecerli bir hesap nosu giriniz");
			return; // fonksiyondan cikmasi icin
		}
	int kacincihesap2=-2;
	int transferhesapno;
	
	printf("para transferi yapmak istediginiz hesap nosunu giriniz");
	scanf("%d",&transferhesapno);
	
	for(i=0;i<hesapSayisi;i++)
    	{

if(transferhesapno==hesapno[i])
		{
	   printf("giris basarili");
		kacincihesap2=i;
		}
		
	}
	if(kacincihesap2!=1 && kacincihesap2!=0)
		{
			printf("gecerli bir hesap nosu giriniz");
			return; // fonksiyondan cikmasi icin
		}
	
	float miktar;
	printf("lutfen transfer etmek istediginiz miktari giriniz");
	scanf("%f",&miktar);
	
		if(miktar>0)
	{
		bakiyeler[kacincihesap]-=miktar;
		bakiyeler[kacincihesap2]+=bakiyeler[kacincihesap2]+miktar;
		printf("bakiyenizden %.2f miktar %d hesap nolu kullaniciya transfer edildi. guncel bakiyeniz = %.2f\n\n",miktar,transferhesapno,bakiyeler[kacincihesap]);
		
	}
	
	
	
	}

void hesap_ekle(int hesapno[],int kullaniciadisayisi,int hesapSayisi)
{
	int girilenhesapno;
	printf("merhaba lutfen önce hesap numaranizi giriniz:");
	scanf("%d",&girilenhesapno);
	
	int i;
	int hangihesap;
	for(i=0;i<kullaniciadisayisi;i++)
	{
		if(girilenhesapno==hesapno[i])
		{
			hangihesap=i;
			printf("doğru girdiniz,yeni hesabiniz olusturulmak uzere isleniyor...\n");
			
			hesapno[hesapSayisi]=hesapno[hangihesap]+1;   // burayi da yaptin ama bir daha bi bak özgüre sor.diziye kaydetme isini
			//mesela ben hesapSayisi yazdim ama bu hangisine kaydoldu sıradaki olan indexe mi yani 0,1 vardi 2.mi oldu.
			
			printf("eklenen hesap no: %d\n\n",hesapno[hesapSayisi]);
			
			
		}
		
		
	}
	hesapSayisi++;
}
int girisonay(int hesapno[],char kullaniciadi[][30],int hesapSayisi,int kullaniciadiuzunlugu)
 {
 	int islemYapilanHesapNumarasi=0;
 	char girdiginkullaniciadi[30]; // cunku karakter dizisi tanimliyomus gibi yapcaksin sayi alir gibi olmaz
 	int girdiginhesapnu;
 	
 	

 	printf("merhaba giris kismina hos geldiniz\n\n");
 	printf("lutfen kullanici adinizi giriniz\n");
 	scanf("%s",&girdiginkullaniciadi);
 	
 	printf("lutfen hesap numaranizi giriniz:\n\n");
 	scanf("%d",&girdiginhesapnu);
 	
 	int i,j;
 	bool dogrumu= false ;
	for(i=0;i<hesapSayisi;i++)
 	{
 	   
 	   	if(strcmp(girdiginkullaniciadi,kullaniciadi[i])==0 && girdiginhesapnu==hesapno[i])
 	   	{
 	   	dogrumu = true;
		islemYapilanHesapNumarasi=hesapno[i];
        break;
		}
 	   	
}
    if(dogrumu==1){
	
	printf("giris basarili\n\nAna menuye yönlendiriliyorsunuz.....");
	
   }
	 else
		{
			printf("lutfen dogru giriniz\n\n");
		   //girisonay( hesapno, kullaniciadi[30], hesapSayisi, kullaniciadiuzunlugu);
		
		}
   return islemYapilanHesapNumarasi;
 }

void menu(int hesapno[],char kullaniciadi[][30],int hesapSayisi,int kullaniciadiuzunlugu,float bakiyeler[],int kullaniciadisayisi)
{
	
  int secenek=0;
    	int altsecenek=0;
    while(secenek!=4)
    {
		int islemYapilan_hesapNo=0;
		 float yeni_bakiyeler[10]={500,600};
 		printf("ana menuye hos geldiniz az sonra seceneklerinizi goreceksiniz:\n\n");
    	printf("giris icin 1 basiniz\n");
    	printf("kullanici eklemek icin 2 basiniz\n");
    	printf("var olan hesaplari goruntulemek icin 3 basiniz\n");
    	printf("cikis icin 4 e basiniz:\n");
    	printf("seceneginizi giriniz lutfen\t\n");
    	scanf("%d",&secenek);
    	
    	if(secenek==1)
    	{
    	
    		while(altsecenek!=4)
    		{
		   islemYapilan_hesapNo = girisonay(hesapno,kullaniciadi,hesapSayisi,kullaniciadiuzunlugu);
    		printf("kullanici menusunune hos geldiniz\n\n");
    		printf("para yatirmak icin 1 basiniz\n");
    		printf("para çekmek icin 2 basiniz\n");
    		printf("para transferi icin 3 basiniz\n");
    		printf("ana menuye donmek icin 4 basiniz\n");
    		scanf("%d",&altsecenek);
    		
    		switch(altsecenek)
    		{
    			case 1: 
				 para_yatirma(hesapno,bakiyeler,hesapSayisi,islemYapilan_hesapNo);
				 break;
    			case 2:
				para_cekme(hesapno,bakiyeler,hesapSayisi,islemYapilan_hesapNo);
				 break;
    			case 3:
				para_transferi(hesapno,bakiyeler,hesapSayisi,islemYapilan_hesapNo);
				break;
				case 4:printf("ana menuye yonlendiriliyorsunuz..\n\n");break;
    			default:printf("lutfen 1-4 arasi giriniz:\n"); 
			}
    	   }
		}
		altsecenek=0;
		
	    if(secenek==2)
	    {
	    	while(altsecenek!=1)
	    	{
	    	girisonay(hesapno,kullaniciadi,hesapSayisi,kullaniciadiuzunlugu);
	    	hesap_ekle(hesapno,kullaniciadisayisi,hesapSayisi);
	    	
	    	printf("ana menuye donmek icin 1 basiniz\n\n");
	    	scanf("%d",&altsecenek);
	    	
	    	switch(altsecenek)
	    	{
	    		case 1:printf("ana menuye yonlendiriliyosunuz\n\n"); break;
	    		default : printf("lutfen üstteki denilen rakamlardan birini seciniz\n\n");
			}
	    		
			}	
		}
		altsecenek=0;
	     if(secenek==3)
	    {
	    	
	    	while(altsecenek!=1)
	    	{
	    		printf("buraya fonksiyon ekleyecegim var olan hesaplari goruntulemek icin\n\n");
	    		
	    		printf("ana menuye donmek icn lutfen 1 basiniz\n\n");
	    		scanf("%d",&altsecenek);
	    		
	    		switch(altsecenek)
	    		{
	    			case 1:printf("ana menuye yonlendirliyosunuz:\n"); break;
	    			default : printf("lutfen ustteki denilen rakamlardan birini seciniz\n"); 
				}
			}

		}
		else
		{
			printf("uygulamadan cikiyorsunuz\n\n");
		}
		
		
	}
}

int main()
{
	int hesapno[10];
	char kullaniciadi[2][30];
	int hesapSayisi=10;	
	int kullaniciadiuzunlugu=30;
   int kullaniciadisayisi =2 ;

	hesaplar(hesapno,hesapSayisi);
	kullaniciadlari(kullaniciadi,kullaniciadisayisi,kullaniciadiuzunlugu);
	ciktimusterilerin(hesapno,kullaniciadi,kullaniciadisayisi,kullaniciadiuzunlugu);
    menu(hesapno,kullaniciadi,hesapSayisi,kullaniciadiuzunlugu,bakiyeler,kullaniciadisayisi);

	
	return 0;
}