#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <fstream.h>
#include <stdlib.h>
#include <ctype.h>
//=========================================================================//
      class Hang
	{ private:
	   char Tenhang[30];
	   int slnhap;
	   float Gianhap;
	   int slxuat;
	  public:
	   Hang()
	    {
	      strcpy(Tenhang,"");
	      slnhap=0;
	      Gianhap=0;
	     }
	   Hang(char *Tenhang1,int slnhap1,float Gianhap1)
	    {
	      strcpy(Tenhang,Tenhang1);
	      slnhap=slnhap1;
	      Gianhap=Gianhap1;
	     }
	     char *getTenhang()
	      { return Tenhang;
	       }

	     float getGia()
	       { return Gianhap;
		}
	    int getSL()
	     { return slnhap;
	      }
	  void hien2();
	  void nhap();
	  void hien();
	  void xuathang();
	  void sx();
	  void suahangnhap();
	  void xoahangnhap();
	  void timhangnhap();
	  void timhangnhapxoa();
      };
int n=0;
Hang ds[100];
//==========================================================================
	void Hang::nhap()
{
	while(1)
	{	cout<<"\nNhap ten hang :    ";
		cin.get(ds[n].Tenhang,30);
		if(ds[n].Tenhang[0]==0) break; //truy nhap vao phan tu dai tien cua xau ten hang,gap dk cua if thi lenh break dc goi den.
		cout<<"\nSo luong      :    ";
		cin>>ds[n].slnhap;
		if(ds[n].slnhap==0) break;
		cout<<"\nGia nhap      :     ";
//		if(ds[n].Gianhap==0) break;
		cin>>ds[n].Gianhap;
		strupr(ds[n].Tenhang); //chuyen ve chu hoa
//doan chuong trinh tim nhung mat hang giong nhau va cong chung lai
		for(int i=0;i<n;i++)
		if(strcmp(ds[i].Tenhang,ds[n].Tenhang)==0) //so sanh neu trung nhau thi
		{	ds[i].slnhap=ds[i].slnhap+ds[n].slnhap;  //cong tt sl lai
			ds[n]=ds[n+1];                           //mang ds se giam
			n=n-1 ;      //phep giam di 1 gia tri  n,khi het gia tri n thi lenh break dc goi den
			break;
		}
	     n++;
	}
}
//==========================================================================//
void Hang::hien()
{
      cout<<"\n\n_________Thong______ke______mat_______hang_________\n\n";
      cout<<"\n"<<setw(7)<<"STT"<<setw(10)<<"TENHANG"<<setw(15)<<"SOLUONG"<<setw(15)<<"GIA"<<"\n";
	for(int i=0;i<n;i++)
	{cout<<"\n\n"<<setw(7)<<i+1<<setw(10)<<ds[i].Tenhang<<setw(15)<<ds[i].slnhap<<setw(15)<<ds[i].Gianhap;
	}
}
//==========================================================================//
void ghitephangnhap()
{       FILE *f;
	f=fopen("d:\\HANGNHAP.dat","w+b");
	for(int i=0;i<n;i++)
	fwrite(&ds[i],sizeof(ds[i]),1,f);
	fclose(f);
}
//=========================================================================//
void doctephangnhap()
{     char c;
      int nb;
      FILE *f;
      long cur, end;
     f = fopen("D:\\HANGNHAP.dat","rb");
     //Mo tep nhi phan da ton tai de doc
     if(f==NULL)
	 cout<<"\nKhong the mo tap tin";
     else
     //	DOAN CHUONG TRINH XU LI DU LIEU
	{
//===========================================
//Xac dinh kich thuoc cua tep(don vi tinh duoc la byte)
	 cur = ftell(f);           //xac dinh vi tri con tro f hien tai( hien tai dau tep)
				     //(Tra ve so byte la 0)
	 fseek(f, 0, SEEK_END);  //dua co tro f ve cuoi tep
	 end = ftell(f);	  //xac dinh vi tri con tro f o cuoi tep
					//(Tra ve kich thuoc bao nhieu byte cua 1 file)
//==========================================
	 fseek(f, cur, SEEK_SET); //dua con tro f ve current,bat dau tu : dau file(dua con tro den ban ghi cuoi cung chua pt trong file)
	 nb = end / sizeof(Hang); //tinh so phan tu cua mang Hang = tongsobyte/so byte cua 1pt kieu hang
	 fread(&ds[n], sizeof(Hang), nb, f);
	 /* &ds[n]  :dia chi cua mang
	    nb      :doc tat ca nb(pt) co trong file
	    f       :con tro file
	  */
	 fclose(f);
	 n = nb;  //Tra ve so phan tu
	 }
   }
//==========================================================================//
void Hang:: xuathang()
{    	char Tenhangxuat[30];
	int soluongxuat;
	while(1)
	{	cout<<"\nNhap ten mat hang can xuat:";
		cin.get(Tenhangxuat,30);
		if(Tenhangxuat[0]==0) break;
		cout<<"So luong:";cin>>soluongxuat;
		strupr(Tenhangxuat);
		for(int i=0;i<n;i++)
		if((strcmp(Tenhangxuat,ds[i].Tenhang)==0)&&(soluongxuat<=ds[i].slnhap))
		  {  ds[i].slnhap=ds[i].slnhap-soluongxuat;
		     cout<<"\n Mat hang  "<<strlwr(Tenhangxuat)<<"  da xuat "<<soluongxuat<<"  chiec" <<endl;
		     cout<<"\n  Xuat hang thanh cong ! ";
		    }
		  for(i=0;i<n;i++)
		  { if((strcmp(Tenhangxuat,ds[i].Tenhang)==0)&&(soluongxuat>ds[i].slnhap))
		       { cout<<"\n Khong du so luong mat hang  "<<Tenhangxuat<<" de xuat\n";
			 break;
			}
		   }
		  break;
	  }
 }
//==========================================================================//
void Hang::suahangnhap()
{	char Tenhangnhapsua[30];
	double dg1;
	while(1)
	{	cout<<"\nNhap ten mat hang can sua  : ";
		cin.get(Tenhangnhapsua,30);
		cin.ignore();
		if(Tenhangnhapsua[0]==0) break;
		strupr(Tenhangnhapsua);
		for(int i=0;i<n;i++)
		if (strcmp(ds[i].Tenhang,Tenhangnhapsua)==0)
		   {	cout<<"\nCap nhat thong tin cua mat hang :\n";
			cout<<"\n     1.Ten moi   :  ";
			cin.get(ds[i].Tenhang,30);
			cout<<"\n     2.So luong  :  ";
			cin>>ds[i].slnhap;
			cout<<"\n     3.Don gia   :  ";
			cin>>ds[i].Gianhap;
			strupr(ds[i].Tenhang);
		      }
	       break;
		}
  }
//==========================================================================//
void Hang::xoahangnhap()
{
	char Tenhangnhapxoa[30];
		while(1)
		    { cout<<"\nNhap ten mat hang nhap can xoa  : ";
				cin.get(Tenhangnhapxoa,30);
				strupr(Tenhangnhapxoa);
				if(Tenhangnhapxoa[0]==0) break;
				for(int i=0;i<n;i++)
				{
					if(strcmp(ds[i].Tenhang,Tenhangnhapxoa)==0)
					{
						for(int j=i;j<n;j++)
						ds[j]=ds[j+1];
						n=n-1;
						i=i-1;
					  cout<<"\n   Xoa thanh cong!  ";
					}
				}
			   break ;
		      }

       }
//==========================================================================//
void Hang::timhangnhap()
 {    char Tenhangnhaptim[30];
   Hang d;
   int k;
   while(1)
    {
	 cout<<"\nNhap ten mat hang ban muon  tim  :  ";
	 cin.get(Tenhangnhaptim,30);
	 if(Tenhangnhaptim[0]==0) break;
	 strupr(Tenhangnhaptim);
	 cout<<"\n\n"<<setw(5)<<"STT"<<setw(10)<<"TENHANG"<<setw(15)<<"SOLUONG"<<setw(15)<<"GIANHAP/CHIEC";
	 for(int i=0;i<n;i++)
	 if(strcmp(ds[i].Tenhang,Tenhangnhaptim)==0)
//	 if(strstr(ds[i].Tenhang,Tenhangnhaptim))
	   { cout<<"\n\n"<<setw(5)<<i<<setw(10)<<ds[i].Tenhang<<setw(15)<<ds[i].slnhap<<setw(15)<<ds[i].Gianhap;
	     }
     break;
    }

  }
//==========================================================================//
void Hang::timhangnhapxoa()
{
   char Tenhangnhaptim[30];
   Hang d;
   int k;
   while(1)
       {
	 cout<<"\nNhap ten mat hang ban muon  tim  :  ";
	 cin.get(Tenhangnhaptim,30);
	 if(Tenhangnhaptim[0]==0) break;
	 strupr(Tenhangnhaptim);
	 cout<<"\n\n"<<setw(5)<<"STT"<<setw(10)<<"TENHANG"<<setw(15)<<"SOLUONG"<<setw(15)<<"GIANHAP/CHIEC";
	 for(int i=0;i<n;i++)
	 if(strcmp(ds[i].Tenhang,Tenhangnhaptim)==0)
	   { cout<<"\n\n"<<setw(5)<<i<<setw(10)<<ds[i].Tenhang<<setw(15)<<ds[i].slnhap<<setw(15)<<ds[i].Gianhap;
	     }
	 cout<<"\nBan co muon xoa mat hang nay khong   :   "
	       <<"\n      + Nhan phim 1 de xoa."
	       <<"\n      + Nhan phim 0 de thoat. "<<endl;
	 do
	   {
	       cin>>k;
	       switch(k)
		 {
		    case 1 :
		       for(int i=0;i<n;i++)
				{
					if(strcmp(ds[i].Tenhang,Tenhangnhaptim)==0)
					{
						for(int j=i;j<n;j++)
						ds[j]=ds[j+1];
						n=n-1;
						i=i-1;
					}
				 }
		       break;
		    }
	 }while(k!=0);
	 break;
    }

}
//==========================================================================//
void Hang::sx()
  {   for(int i=0;i<n-1;i++)
      for(int j=i+1;j<n;j++)
	if(ds[i].Gianhap>ds[j].Gianhap)
	   {   Hang tg;
	       tg=ds[i];
	       ds[i]=ds[j];
	       ds[j]=tg;
	      }
     }
//==========================================================================//
//DOAN CHUONG TRINH GHI DOC FILE MAT HANG CAN NHAP THEM VI BAN HET
     void ghitephangnhapdaxuathet()
     {
      FILE *f;
	f=fopen("E:\\HAN.dat","w+b");
	for(int i=0;i<n;i++)
	if(ds[i].getSL()==0)
	{
	fwrite(&ds[i],sizeof(ds[i]),1,f);
	}
	fclose(f);
   }
//==========================================================================//
void doctephangnhapdaxuathet()
	 {
	    FILE *f;
	   int i=0;
	    f=fopen("E:\\HAN.dat","rb");
	    cout<<"\n"<<setw(7)<<"STT"<<setw(10)<<"TENHANG"<<setw(15)<<"SOLUONG"<<setw(15)<<"GIA"<<"\n";
	    do
	    {
	     fread(&ds[i],sizeof(ds[i]),1,f);
	     if(!feof(f))
	     cout<<"\n\n"<<setw(7)<<1+i++<<setw(10)<<ds[i].getTenhang()<<setw(15)<<ds[i].getSL()<<setw(15)<<ds[i].getGia();
	    }while(!feof(f));
	    fclose(f);
	  }
void doctephangnhapmhbanhet()
	 {
	    FILE *f;
	    int i=0;
	    int t=0;
	    f=fopen("D:\\HANGNHAP.dat","rb");
	    cout<<"\n"<<setw(7)<<"STT"<<setw(10)<<"TENHANG"<<setw(15)<<"SOLUONG"<<setw(15)<<"GIA"<<"\n";
	    do
	    {
	     fread(&ds[i],sizeof(ds[i]),1,f);
	     if(!feof(f))
	     cout<<"\n\n"<<setw(7)<<1+i++<<setw(10)<<ds[i].getTenhang()<<setw(15)<<ds[i].getSL()<<setw(15)<<ds[i].getGia();
	     t++;
	    }while(!feof(f));
	    fclose(f);
	    n=t-1;
	   }
//========================
 /* case 1  : call : void doctephangnhapmhbanhet()
	      call : void ghitephangnhapdaxuathet()
    case 2 :  call : void doctephangnhapmhbanhet()
  */
//========================
//==========================================================================//
void main()
      {  clrscr();
	 Hang a;
	 int chucnang;
	 do
	   {cout<<"\n                 ____CHUONG___TRINH___QUAN___LY___BAN___HANG______";
	    cout<<endl<<endl<<endl;
	    cout<<"\n   1.Thong ke mat hang trong kho"<<endl;
	    cout<<"\n   2.Thong ke mat hang da ban het"<<endl;
	    cout<<"\n   3.Thuc hien chuc nang don nhap hang"<<endl;
	    cout<<"\n   4.Nhap mat hang"<<endl;
	    cout<<"\n   5.Xuat mat hang "<<endl;
	    cout<<"\n   6.Sua thong tin mat hang"<<endl;
	    cout<<"\n   7.Xoa mot mat mat hang trong kho"<<endl;
	    cout<<"\n   8.Tim mat hang trong kho"<<endl;
	    cout<<"\n   9.Tim mat hang trong kho de xoa"<<endl;
	    cout<<"\n   10.Sap xep theo gia nhap"<<endl;
	    cout<<"\n   0.Ket thuc qua trinh"<<endl;
	    cout<<"\n    .Lua chon thao tac :    ";
	    cin>>chucnang;
	    cin.ignore();
	    textbackground(1);
	    textcolor(15);
	    switch(chucnang)
		 {
		   case 1:
		     //	  doctephangnhap();
		     //	  a.hien();
			  doctephangnhapmhbanhet();
			  ghitephangnhapdaxuathet();
			  getch();
			  clrscr();
			  break;
		   case 2:
		   //	  doctephangnhapdaxuathet();
		   //      a.hien();
			  doctephangnhapdaxuathet();
			  getch();
			  clrscr();
			  break;
		   case 3:
			  ghitephangnhap();
			  getch();
			  clrscr();
			  break;
		  case 4:
			  a.nhap();
			  a.hien();
			  getch();
			  clrscr();
			  break;
		  case 5:
			  a.xuathang();
			  a.hien();
			  getch();
			  clrscr();
		  case 6:
			  a.suahangnhap();
			  a.hien();
			  getch();
			  clrscr();
			  break;
		  case 7:
			  a.xoahangnhap();
			  a.hien();
			  getch();
			  clrscr();
			  break;
		  case 8 :
			  a.timhangnhap();
			  getch();
			  clrscr();
			  break;
		  case 9:
			  a.timhangnhapxoa();
			  ghitephangnhap();
			  a.hien();
			  getch();
			  clrscr();
			  break;
		  case 10:
			  a.sx();
			  a.hien();
			  getch();
			  clrscr();
			  break;
//		  default: ghitephangnhap();
		    }
	     }while(chucnang!=0);
	 getch();
	}
