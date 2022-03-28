/*ma so sinh vien: 6251071052
ho va ten: Nguyen Thi Kim Lien 
lop: Cong Nghe Thong Tin k62
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
struct phanso {
	int tuso;
	int mauso; 
};
void nhapphanso (phanso &ps)
{
	fflush (stdin);
	printf("\nNhap tu so: ");
	scanf("%d",&ps.tuso);
	do{
	printf("\nNhap mau so: ");
	scanf("%d", &ps.mauso);
	if(ps.mauso== 0)
	{
		printf("\nVui long nhap lai mau so khac 0");
	}
}while( ps.mauso ==0);
}
void xuatphanso (phanso &ps )
{
	printf("\nPhan so da nhap la: %d/%d",ps.tuso, ps.mauso);
}
void rutgon (phanso &ps )
{
	int max =1;
	for(int i=1; i<=ps.tuso ; i++)
	{
		if(ps.tuso%i==0 && ps.mauso%i ==0)
		{
			if(max < i )
			{
				max = i ; 
			}
		}
	}
      ps.tuso = ps.tuso / max;
      ps.mauso= ps.mauso/ max;
      	printf("\nPhan so da rut gon la: %d/%d",ps.tuso, ps.mauso);
}
void tinhtong (phanso &ps, phanso &ps1)
{
	int Tu, Mau;
	Tu = ps.tuso*ps1.mauso + ps.mauso*ps1.tuso;
	Mau = ps.mauso*ps1.mauso;
	
	printf("\nTong 2 phan so la: %d/%d",Tu, Mau);
}
void tinhHieu (phanso &ps, phanso &ps1)
{
	int Tu, Mau;
	Tu = ps.tuso*ps1.mauso - ps.mauso*ps1.tuso;
	Mau = ps.mauso*ps1.mauso;

	printf("\nHieu 2 phan so la: %d/%d",Tu, Mau);
}

void tinhTich(phanso &ps, phanso &ps1)
{
	int Tu, Mau;
	Tu = ps.tuso * ps1.tuso;
	Mau = ps.mauso * ps1.mauso;

	printf("\nTich 2 phan so la: %d/%d",Tu, Mau);
}

void tinhThuong(phanso &ps, phanso &ps1)
{
	int Tu, Mau;
	Tu = ps.tuso * ps1.mauso;
	Mau = ps.mauso * ps1.tuso;

	printf("\nThuong 2 phan so la: %d/%d",Tu, Mau);
}
void nhapMang (phanso ps[], int n)
{
	for(int i=0; i< n; i++)
	{
			fflush (stdin);
	printf("\nNhap tu so: ");
	scanf("%d",&ps[i].tuso);
	do{
	printf("\nNhap mau so: ");
	scanf("%d", &ps[i].mauso);
	if(ps[i].mauso== 0)
	{
		printf("\nVui long nhap lai mau so khac 0");
	}
}while( ps[i].mauso ==0);
	}
}

	void sapxep(phanso ps[],int n)
	{
	//	phanso a;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)	
		{
		//	printf("\n1 gia tri: %.2f",(float)((float)ps[i].tuso/(float)ps[i].mauso));
		//	printf("\n2 gia tri: %.2f",(float)((float)ps[j].tuso/(float)ps[j].mauso));
			if((float)((float)ps[i].tuso/(float)ps[i].mauso) <(float)((float)ps[j].tuso/(float)ps[j].mauso))
			{
			phanso a =ps[i];
			ps[i]=ps[j];
			ps[j]=a;
			}
		}
		}
		printf("\nSau khi sap xep:");
			for(int i=0;i<n;i++)
			{
					printf("\t %d/%d",ps[i].tuso, ps[i].mauso);
			}
	}
	void timkiem (phanso ps[], int n )
	{
		int a=0;
		for (int i=0; i<n; i++)
		{
			rutgon(ps[i]);
		}
		phanso ps3;
       	nhapphanso(ps3);
       	rutgon(ps3);
		for (int i=0; i<n ; i++)
		{
        	if(ps[i].tuso == ps3.tuso && ps[i].mauso == ps3.mauso)
        	{
        		a+=0;
			}
			else
			{
				a+=1;
			}
		}
		if(a=0)
		{
			printf("\nPhan so da nhap xuat hien");
		}
		else
		{
			printf("\nPhan so da nhap khong xuat hien");
		}
	}
void sapxeptangdan(phanso ps[],int n)
{
   int j;
   phanso key;
   for (int i = 1; i < n; i++) 
   {
       float keyFloat = (float)((float)ps[i].tuso/(float)ps[i].mauso);
       key = ps[i];
       j = i-1;
         printf("\t %0.2f", keyFloat);
       while ( j >= 0 && (float)((float)ps[j].tuso/(float)ps[j].mauso) > keyFloat)
       {
           ps[j+1] = ps[j];
           j = j-1;
       }
       ps[j+1] = key;
   }
  printf("\nSau khi sap xep:");
  
	for(int i=0;i<n;i++)
	{
	printf("\t %d/%d",ps[i].tuso, ps[i].mauso);
	}
}

 
int main (){
	printf("\n1: Xay dung thuat toan");
	printf("\n2: Nhap phan so, kiem tra phan so thoa dieu kien");
	printf("\n3: Xuat phan so da nhap");
	printf("\n4: Rut gon, tinh + - * /");
	printf("\n5: Nhap mang, sap xep giam dan");
	printf("\n6: Tim kiem mot phan so");
	printf("\n7: Sap xep tang dan");
	int p;
	printf("\nNhap so phan tu mang: ");
	    int n;
		scanf("%d",&n);
		phanso mangPs[n];
		nhapMang(mangPs,n);
	do{
		printf("\nXin moi nhap lua chon: ");
		scanf("%d", &p);
		switch (p)
		{
		case 1: 
		printf("\nDa xong ");
		break;
		case 2:
		printf("\nPhan thu 1");
		phanso ps;
		nhapphanso(ps);
		printf("\nPhan thu 2");
		phanso ps2;
		nhapphanso(ps2);
		break; 
		case 3: 
		xuatphanso(ps);
		xuatphanso(ps2);
		break; 
		case 4: 
		rutgon(ps);
		rutgon(ps2);
	tinhtong(ps,ps2);
	tinhHieu(ps,ps2);
	tinhTich(ps,ps2);
	tinhThuong(ps,ps2);
		break;
		case 5: 
		sapxep (mangPs, n);
		break;
		case 6: 
		timkiem (mangPs, n);
		break;
		case 7: 
		sapxeptangdan (mangPs, n);
		break;
	}
	} while (p > 0 || p < 7);

}
