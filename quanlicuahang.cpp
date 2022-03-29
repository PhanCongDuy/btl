#include<stdio.h>

struct phanso {
	int tuso;
	int mauso;
};

void NhapPhanSo (struct phanso &a){
	printf ("\nNhap tu so: ");
	scanf ("%d",&a.tuso);
	do{
	printf ("Nhap mau so: ");
	scanf ("%d",&a.mauso);
	if(a.mauso==0){
		printf ("***Nhap lai mau so khac 0***");
	}
	}while(a.mauso==0);
}

void XuatPhanSo (struct phanso a){
	printf ("Phan so da nhap la : %d/%d ",a.tuso,a.mauso);
}

int UCLN (int a,int b){
	if(a<0){
		a=a*(-1);
	}
	if(b<0){
		b=b*(-1);
	}
	while(a!=b){
		if (a>b){
			a=a-b;
		}else{
			b=b-a;
		}
	}
	return a;
}
void RutGonPhanSo (struct phanso a){
	if(a.tuso!=0){
		int t=UCLN(a.tuso,a.mauso);
	   printf ("\nRut gon phan so : %d/%d",a.tuso=a.tuso/t,a.mauso=a.mauso/t);
	}else{
	   printf ("Rut gon phan so : 0");
	}
}

struct phanso TinhTong (phanso a,phanso b){
	phanso tong;
	tong.mauso=a.mauso*b.mauso;
	tong.tuso=a.tuso*b.mauso+a.mauso*b.tuso;
	return tong;
}

struct phanso TinhHieu (phanso a,phanso b){
	phanso hieu;
	hieu.mauso=a.mauso*b.mauso;
	hieu.tuso=a.tuso*b.mauso-a.mauso*b.tuso;
	return hieu;
}

struct phanso TinhTich (phanso a,phanso b){
	phanso tich;
	tich.mauso=a.mauso*b.mauso;
	tich.tuso=a.tuso*b.tuso;
	return tich;
}

struct phanso TinhThuong (phanso a,phanso b){
	phanso thuong;
	thuong.mauso=a.mauso*b.tuso;
	thuong.tuso=b.mauso*a.tuso;
	return thuong;
}

void NhapDSPhanSo (struct phanso x[],int n){
	for (int i=0;i<n;i++){
		printf ("Nhap vao phan so thu %d ",i+1);
		NhapPhanSo(x[i]);
	}
}

void XuatDSPhanSo (struct phanso x[],int n){
	printf("\n*****************************\n");
	for(int i=0; i<n; i++){
		printf("\nPhan so da nhap thu %d\n",i+1);
		XuatPhanSo(x[i]);
	}
}

void SapXepPhanSo (struct phanso x[],int n){
	int i,j;
	struct phanso KEY;
	for(i=1;i<n;i++){
		KEY.tuso=x[i].tuso;
		KEY.mauso=x[i].mauso;
		j=i-1;
	   while(j>=0 && (((float)x[j].tuso/x[j].mauso) > ((float)KEY.tuso/KEY.mauso))){
	   	x[j+1].tuso  =x[j].tuso;
	   	x[j+1].mauso =x[j].mauso;
	   	j=j-1;
	   }
	   x[j+1].tuso  =KEY.tuso;
	   x[j+1].mauso =KEY.mauso;
	}
	
}
void XuatDay(struct phanso x[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf ("  %d/%d  ",x[i].tuso,x[i].mauso);
    
}


void TimKiemPhanSo (struct phanso x[],int n,phanso y){
	int kt;
	NhapPhanSo(y);
	for (int i=0;i<n;i++){
		if(x[i].tuso==y.tuso && x[i].mauso==y.mauso){
			kt=1;
			break;
		}else{
			kt=0;
		}
	}
	if (kt==1){
		printf ("\nCo phan so muon tim kiem");
	}else{
		printf ("\nKhong co phan so muon tim kiem");
	}
}

int main (){
	struct phanso a;
	struct phanso b;
	int n;
	struct phanso x[100];
	struct phanso y;
/*	printf("Nhap phan so thu nhat  ");
	NhapPhanSo(a);
	XuatPhanSo(a);
	RutGonPhanSo(a);
	printf ("\nNhap phan so thu hai  ");
	NhapPhanSo(b);
	XuatPhanSo(b);
	RutGonPhanSo(b);
	struct phanso tong=TinhTong(a,b);
	printf ("\nTong hai phan so la : %d/%d ",tong.tuso,tong.mauso);
	RutGonPhanSo(tong);
	struct phanso hieu=TinhHieu(a,b);
	printf ("\nHieu hai phan so la : %d/%d ",hieu.tuso,hieu.mauso);
	RutGonPhanSo(hieu);
	struct phanso tich=TinhTich(a,b);
	printf ("\nTich hai phan so la : %d/%d ",tich.tuso,tich.mauso);
	RutGonPhanSo(tich);
	struct phanso thuong=TinhThuong(a,b);
	printf ("\nThuong hai phan so la : %d/%d ",thuong.tuso,thuong.mauso);
	RutGonPhanSo(thuong);
	*/
	do{
		printf ("\nNhap so phan so la : ");
		scanf ("%d",&n);
	}while(n<=0);
	NhapDSPhanSo(x,n);
	XuatDSPhanSo(x,n);
	SapXepPhanSo(x,n);
	printf("\n*****************************\n");
	printf ("\nSap Xep day phan so la :   ");
	XuatDay(x,n);
	TimKiemPhanSo(x,n,y);
}
