#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
#define consoleRong 120
#define consoleCao 30
#define roadWidth 30

enum trangthai{UP, DOWN , LEFT, RIGHT};
void cursor(BOOL bVisible ,DWORD dwSize );
void gotoxy(int x, int y);
void TextColor(int x);

void cursor(BOOL bVisible  ,DWORD dwSize )
   {
       HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
       CONSOLE_CURSOR_INFO ConsoleCursorInfor;
       ConsoleCursorInfor.bVisible = bVisible;
       ConsoleCursorInfor.dwSize = dwSize;
       SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfor);
   }
void gotoxy(int x, int y)
   {
   static HANDLE h = NULL;
   if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD c = { x, y };
   SetConsoleCursorPosition(h,c);
  }
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

typedef struct
{
   char kytu;
   int mau;
}MotO;

MotO buffer[consoleCao][roadWidth ];
void VeMotO(int dong,int cot,int kytu,int mau)
{
    buffer[dong][cot].kytu = kytu;
    buffer[dong][cot].mau = mau;
}

 typedef struct{
       int y ;
       int x;

}ToaDo;
typedef struct
{
    char a[10][10];
    char b[100];
}HinhDang;

typedef struct{

         ToaDo toadodan[31];
         int sovien;
         enum trangthai tt;
         HinhDang hd;

}Dan;
typedef struct
{
    ToaDo td;
    int diem;
    int lever;
    HinhDang hd;
    enum trangthai tt;
}MayBay;
typedef struct
{
    ToaDo td;
    HinhDang hd;
    int sotang;
    enum trangthai tt;
}VatCan;
void HienThi(MayBay maybay, Dan dan1,VatCan vc1,
             VatCan vc2,VatCan vc3,VatCan vc4,
             VatCan vc5,VatCan vc6,VatCan thuong,
             VatCan bom,VatCan kieudan1,VatCan kieudan2,
             VatCan kieudan3,Dan dan2, Dan dan3)
{
   int dong,cot,i,j,x,y;
   /// ve duong bien
   for ( i = 0 ;i < consoleCao; i ++)
   {
       VeMotO(i,1,219,6);
       VeMotO(i,roadWidth,219,6);
   }
/// *** hien thi dan kieu 1
   for(i = 0; i < dan1.sovien;i ++)
   {
       VeMotO(dan1.toadodan[i].y,dan1.toadodan[i].x,'o',6);
   }
   // *** hien thi dan kieu 1
   for(i = 0; i < dan2.sovien;i ++)
   {
       VeMotO(dan2.toadodan[i].y,dan2.toadodan[i].x,'o',6);
   }
   // *** hien thi dan kieu 1
   for(i = 0; i < dan3.sovien;i ++)
   {
       VeMotO(dan3.toadodan[i].y,dan3.toadodan[i].x,'o',6);
   }

   /// ****** hien thi may bay *****
   for(dong = -1;dong <= 1;dong ++)
   {
       for(cot = -1; cot <= 1;cot ++)
       {
           x = cot + maybay.td.x;
           y = dong + maybay.td.y;
           VeMotO(y,x,maybay.hd.a[dong + 1][cot +1],11);

       }
   }
   
   /// **** hien thi diem***
   gotoxy(roadWidth + 2,2);
   printf("DIEM: %d",maybay.diem);
   ///**** hien thi cap do
   gotoxy(roadWidth + 2, 1);
   printf("LEVER: %d",maybay.lever);

    /// **** hien thi vat can
          /// *** vc1***
    for(dong = -1;dong <= 1;dong ++)
   {
       for(cot = -1; cot <= 1;cot ++)
       {
           x = cot + vc1.td.x;
           y = dong + vc1.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,vc1.hd.a[dong + 1][cot +1],4);
           }
       }
   }
         /// *** vc2***
    for(dong = -1;dong <= 1;dong ++)
   {
       for(cot = -1; cot <= 1;cot ++)
       {
           x = cot + vc2.td.x;
           y = dong + vc2.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,vc2.hd.a[dong + 1][cot +1],4);
           }


       }
   }
         /// *** vc3***
    for(dong = -1;dong <= 1;dong ++)
   {
       for(cot = -1; cot <= 1;cot ++)
       {
           x = cot + vc3.td.x;
           y = dong + vc3.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,vc3.hd.a[dong + 1][cot +1],4);
           }


       }
   }
         /// *** vc4***
    for(dong = -1;dong <= 1;dong ++)
   {
       for(cot = -1; cot <= 1;cot ++)
       {
           x = cot + vc4.td.x;
           y = dong + vc4.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,vc4.hd.a[dong + 1][cot +1],4);
           }
       }
   }
         /// *** vc5***
    for(dong = -1;dong <= 1;dong ++)
   {
       for(cot = -1; cot <= 1;cot ++)
       {
           x = cot + vc5.td.x;
           y = dong + vc5.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,vc5.hd.a[dong + 1][cot +1],4);
           }
       }
   }
         /// *** vc6***
    for(dong = -1;dong <= 1;dong ++)
   {
       for(cot = -1; cot <= 1;cot ++)
       {
           x = cot + vc6.td.x;
           y = dong + vc6.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,vc6.hd.a[dong + 1][cot +1],4);
           }
       }
   }
      /// *** hien thi thuong***
    for(dong = -1;dong <= 1;dong ++)
   {
       for(cot = -1; cot <= 1;cot ++)
       {
           x = cot + thuong.td.x;
           y = dong + thuong.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,thuong.hd.a[dong + 1][cot +1],6);
           }
       }
   }
      /// *** hien thi bom ***
    for(dong = -1;dong <= 1;dong ++)
   {
       for(cot = -1; cot <= 1;cot ++)
       {
           x = cot + bom.td.x;
           y = dong + bom.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,bom.hd.a[dong + 1][cot +1],11);
           }
       }
   }
       /// *** hien thi kieu dan 1***
    for(dong = 0;dong <= 1;dong ++)
   {
       for(cot = 0; cot <= 1;cot ++)
       {
           x = cot + kieudan1.td.x;
           y = dong + kieudan1.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,kieudan1.hd.a[dong][cot],6);
           }
       }
   }
       /// *** hien thi kieu dan 2***
    for(dong = 0;dong <= 1;dong ++)
   {
       for(cot = 0 ; cot <= 1;cot ++)
       {
           x = cot + kieudan2.td.x;
           y = dong + kieudan2.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,kieudan2.hd.a[dong][cot],13);
           }
       }
   }
       /// *** hien thi kieu dan 3 ***
    for(dong = 0;dong <= 1;dong ++)
   {
       for(cot = 0 ; cot <= 1;cot ++)
       {
           x = cot + kieudan3.td.x;
           y = dong + kieudan3.td.y;
           if ( y >= 0 && y < consoleCao)
           {
              VeMotO(y,x,kieudan3.hd.a[dong][cot],12);
           }
       }
   }

   ///*** dua buffer ra man console
   gotoxy(0,0);
   for(i = 0; i < consoleCao; i++)
   {
       for( j = 0; j < roadWidth + 1; j ++)
       {
           TextColor(buffer[i][j].mau);
           putchar(buffer[i][j].kytu);

           buffer[i][j].kytu = ' ';
       }
      if (i < consoleCao - 1)
        putchar('\n');
   }

}
int main()
{
  /// ********* khoi tao cac gia tri ban dau
  /// dinh nghia cac bien dau vao
  cursor(0,25);
  srand(time(NULL));//khoi tao sinh so ngau nhien
  Dan dan1;
  Dan dan2;
  Dan dan3;
  MayBay maybay;
  VatCan vc1;
  VatCan vc2;
  VatCan vc3;
  VatCan vc4;
  VatCan vc5;
  VatCan vc6;
  VatCan bom;
  VatCan thuong;
  VatCan kieudan1;
  VatCan kieudan2;
  VatCan kieudan3;
  VatCan kieutau1;
  VatCan kieutau2;
  VatCan kieutau3;
  int i,j,k;
  maybay.diem = 0;
  int timedelay;
  timedelay = 20;
  maybay.lever = 0;
  int capdodan;
  capdodan = 5;
  /// ***khoi tao xe***
  maybay.td.x = roadWidth/ 2;
  maybay.td.y = consoleCao - 2;
  maybay.hd.a[0][0] = maybay.hd.a[0][2]
    = maybay.hd.a[2][0] = maybay.hd.a[2][2] = 'o'; /// 4 banh xe:
    maybay.hd.a[0][1] = '^';/// dau xe:
    maybay.hd.a[1][0] = maybay.hd.a[1][2] = '|';
    maybay.hd.a[2][1] = '_';
    maybay.hd.a[1][1] = '+';

  /// khoi tao dan
  /// dan 1
  dan1.sovien = capdodan;
  for (i = 0; i < dan1.sovien; i++ )
  {
     dan1.toadodan[i].x = maybay.td.x;
     dan1.toadodan[i].y = maybay.td.y + i;
  }
  dan1.tt = UP;
  /// dan 2
  dan2.sovien = capdodan;
  for (i = 0; i < dan2.sovien; i++ )
  {
     dan2.toadodan[i].x = maybay.td.x - 1;
     dan2.toadodan[i].y = maybay.td.y + i;
  }
  dan2.tt = UP;
  /// dan 3
  dan3.sovien = capdodan;
  for (i = 0; i < dan3.sovien; i++ )
  {
     dan3.toadodan[i].x = maybay.td.x +1;
     dan3.toadodan[i].y = maybay.td.y + i;
  }
  dan3.tt = UP;

  /// khoi tao vat can
  /// vat can 1
  vc1.td.x = 3 + rand() % ( roadWidth - 5);
  vc1.td.y = -2;
  for( i = 0; i < 3; i ++)
  {
      for ( j = 0; j < 3; j ++)
      {
          vc1.hd.a[i][j] = 219;
      }
  }
  vc1.tt = DOWN;
  /// vat can 2
  vc2.td.x = 3 + rand() % ( roadWidth - 5);
  vc2.td.y = -4;
  for( i = 0; i < 3; i ++)
  {
      for ( j = 0; j < 3; j ++)
      {
          vc2.hd.a[i][j] = 219;
      }
  }
  vc2.tt = DOWN;

/// vat can 3

  vc3.td.x = 3 + rand() % ( roadWidth - 5);
  vc3.td.y = -6;
  for( i = 0; i < 3; i ++)
  {
      for ( j = 0; j < 3; j ++)
      {
          vc3.hd.a[i][j] = 219;
      }
  }
  vc3.tt = DOWN;

/// vat can 4
  vc4.td.x = 3 + rand() % ( roadWidth - 5);
  vc4.td.y = -8;
  for( i = 0; i < 3; i ++)
  {
      for ( j = 0; j < 3; j ++)
      {
          vc4.hd.a[i][j] = 219;
      }
  }
  vc4.tt = DOWN;

/// vat can 5
  vc5.td.x = 3 + rand() % ( roadWidth - 5);
  vc5.td.y = -10;
  for( i = 0; i < 3; i ++)
  {
      for ( j = 0; j < 3; j ++)
      {
          vc5.hd.a[i][j] = 219;
      }
  }
  vc5.tt = DOWN;

/// vat can 6
  vc6.td.x = 3 + rand() % ( roadWidth - 5);
  vc6.td.y = -12;
  for( i = 0; i < 3; i ++)
  {
      for ( j = 0; j < 3; j ++)
      {
          vc6.hd.a[i][j] = 219;
      }
  }
  vc6.tt = DOWN;
  /// khoi tao hop tien
  thuong.td.x = 3 + rand() % ( roadWidth - 5);
  thuong.td.y = -2;
  for( i = 0; i < 3; i ++)
  {
      for ( j = 0; j < 3; j ++)
      {
          thuong.hd.a[i][j] = 36;
      }
  }
  thuong.tt = DOWN;
  /// khoi tao bom
  bom.td.x = 3 + rand() % ( roadWidth - 5);
  bom.td.y = -4;
  for( i = 0; i < 3; i ++)
  {
      for ( j = 0; j < 3; j ++)
      {
          bom.hd.a[i][j] = 42;
      }
  }
  bom.tt = DOWN;
  /// kieu dan 1
  kieudan1.td.x = 3 + rand() % ( roadWidth - 5);
  kieudan1.td.y = -4;
  for( i = 0; i < 2; i ++)
  {
      for ( j = 0; j < 2; j ++)
      {
          kieudan1.hd.a[i][j] = 111;
      }
  }
  kieudan1.tt = DOWN;
  /// kieu dan 2
  kieudan2.td.x = 3 + rand() % ( roadWidth - 5);
  kieudan2.td.y = -6;
  for( i = 0; i < 2; i ++)
  {
      for ( j = 0; j < 2; j ++)
      {
          kieudan2.hd.a[i][j] = 111;
      }
  }
  kieudan2.tt = DOWN;
  /// kieu dan 3
  kieudan3.td.x = 3 + rand() % ( roadWidth - 5);
  kieudan3.td.y = -12;
  for( i = 0; i < 2; i ++)
  {
      for ( j = 0; j < 2; j ++)
      {
          kieudan3.hd.a[i][j] = 111;
      }
  }
  kieudan3.tt = DOWN;

  /// khoi tao buffer
  for ( i  = 0; i < consoleCao; i++ )
    {
        for(j = 0; j < roadWidth;j++)
        {
            buffer[i][j].kytu = ' ';
            buffer[i][j].mau = 7;
        }
    }

  while(1)
  {
      /// *********chuong trinh hien thi**********
      HienThi(maybay,dan1,vc1,vc2,vc3,vc4,
       vc5,vc6,thuong,bom,kieudan1,kieudan2,kieudan3,dan2,dan3);

      /// ******chuong trinh dieu khien******
                /// dan noi dan


                 if ( kbhit())/// neu phat hien co phim nhan
                 {

                 /// dieu khien may bay
                 int  key = 0;
                 key = _getch();
                 if( key == 'a'|| key == 'A'&& maybay.td.x > 3)
                    maybay.tt = LEFT;
                 else if ( key == 'd'|| key == 'D'&& maybay.td.x < roadWidth - 3 )
                    maybay.tt = RIGHT;
                 else if ( key == 'w'|| key == 'W'&& maybay.td.y > consoleCao - 10)
                    maybay.tt = UP;
                 else if ( key == 's'|| key == 'S'&& maybay.td.y < consoleCao - 2)
                    maybay.tt = DOWN;
                 }
                 /// *** may bay di chuyen***
                 if (maybay.tt == DOWN && maybay.td.y < consoleCao -2)
                    maybay.td.y++;
                 else if( maybay.tt == UP && maybay.td.y >= 25)
                    maybay.td.y--;
                 else if( maybay.tt == LEFT && maybay.td.x > 3)
                    maybay.td.x--;
                 else if ( maybay.tt == RIGHT && maybay.td.x < roadWidth - 3)
                    maybay.td.x++;
                 /// *** dan di chuyen***
                 /// dan1
                 if ( dan1.tt == UP)
                 {
                  for(i = 0 ; i < dan1.sovien; i ++)
                    {
                      dan1.toadodan[i].y = dan1.toadodan[i].y - 2;
                    }
                 }
                 ///dan 2
                 if ( dan2.tt == UP)
                 {
                  for(i = 0 ; i < dan2.sovien; i ++)
                    {
                      dan2.toadodan[i].y = dan2.toadodan[i].y - 2;
                    }
                 }
                 /// dan 3
                 if ( dan3.tt == UP)
                 {
                  for(i = 0 ; i < dan3.sovien; i ++)
                    {
                      dan3.toadodan[i].y = dan3.toadodan[i].y - 2;
                    }
                 }
                 /// **** vat can di chuyen
                    if ( vc1.tt = DOWN)
                        vc1.td.y ++;
                    if ( vc2.tt = DOWN)
                        vc2.td.y ++;
                    if ( vc3.tt = DOWN)
                        vc3.td.y ++;
                    if ( vc4.tt = DOWN)
                        vc4.td.y ++;
                    if ( vc5.tt = DOWN)
                        vc5.td.y ++;
                    if ( vc6.tt = DOWN)
                        vc6.td.y ++;

                    if ( thuong.tt == DOWN && maybay.diem >= 20)
                        thuong.td.y++;
                    if ( bom.tt == DOWN && maybay.diem >= 20)
                        bom.td.y++;
                    if ( kieudan1.tt == DOWN && maybay.diem >= 10)
                        kieudan1.td.y++;
                    if ( kieudan2.tt == DOWN && maybay.diem >= 20)
                        kieudan2.td.y++;
                    if ( kieudan3.tt == DOWN &&maybay.diem >= 30)
                        kieudan3.td.y++;

      /// *********reset ve diem goc cho cac doi tuong********
             /// khoi tao ve diem goc cho dan
             /// khoi tao goc dan 1
             for ( i = 0; i < dan1.sovien; i++)
             {
                 if(dan1.toadodan[i].y < 0)
                 {
                    dan1.toadodan[i].x = maybay.td.x;
                    dan1.toadodan[i].y = maybay.td.y - 1 ;
                 }
             }

                 /// khoi tao goc dan 2
            for ( i = 0; i < dan2.sovien; i++)
             {
                 if(dan2.toadodan[i].y < 0)
                 {
                    dan2.toadodan[i].x = maybay.td.x - 1;
                    dan2.toadodan[i].y = maybay.td.y - 1;
                 }
             }
                 /// khoi tao goc dan 3

            for ( i = 0; i < dan3.sovien; i++)
             {
                 if(dan3.toadodan[i].y < 0)
                 {
                    dan3.toadodan[i].x = maybay.td.x + 1;
                    dan3.toadodan[i].y = maybay.td.y - 1;
                 }


             }
             /// khoi tao diem goc cho vc
            if ( vc1.td.y >= consoleCao)
             {
                 vc1.td.x = 3 + rand() % ( roadWidth - 5);
                 vc1.td.y = -2;
             }
            if ( vc2.td.y >= consoleCao)
             {
                 vc2.td.x = 3 + rand() % ( roadWidth - 5);
                 vc2.td.y = -6;
             }
            if ( vc3.td.y >= consoleCao)
             {
                 vc3.td.x = 3 + rand() % ( roadWidth - 5);
                 vc3.td.y = -9;
             }
            if ( vc4.td.y >= consoleCao)
             {
                 vc4.td.x = 3 + rand() % ( roadWidth - 5);
                 vc4.td.y = -12;
             }
            if ( vc5.td.y >= consoleCao)
             {
                 vc5.td.x = 3 + rand() % ( roadWidth - 5);
                 vc5.td.y = -15;
             }
            if ( vc6.td.y >= consoleCao)
             {
                 vc6.td.x = 3 + rand() % ( roadWidth - 5);
                 vc6.td.y = -18;
             }
             if ( kieudan1.td.y >= consoleCao)
             {
                 kieudan1.td.x = roadWidth +6;
                 kieudan1.td.y  = consoleCao +4;
             }
             if ( kieudan2.td.y >= consoleCao)
             {
                 kieudan2.td.x = roadWidth +6;
                 kieudan2.td.y = consoleCao +6;
             }
             if ( kieudan3.td.y >= consoleCao)
             {
                 kieudan3.td.x = roadWidth +6;
                 kieudan3.td.y  = consoleCao +8;
             }

              /// khoi tao lai gia tri phan thuong
        ///tinh theo so diem
            if (maybay.diem % 20 == 0 )
             {
              thuong.td.x = 3 +rand() % (roadWidth - 5);
              thuong.td.y = -6;

             }

         /// khoi tao lai gia tri bom
         ///roi tinh theo so diem
        if ( maybay.diem  % 20 == 0)
           {
               bom.td.x = 3 +rand() % (roadWidth - 5);
               bom.td.y = -8;
           }
           /// khoi tao lai gia tri kieu dan
           if ( maybay.diem  % 10 == 0)
           {
               kieudan1.td.x = 3 +rand() % (roadWidth - 5);
               kieudan1.td.y = -4;

           }
               if ( maybay.diem  %20 == 0)
           {
               kieudan2.td.x = 3 +rand() % (roadWidth - 5);
               kieudan2.td.y = -11;

           }
               if ( maybay.diem  % 30 == 0)
           {
               kieudan3.td.x = 3 +rand() % (roadWidth - 5);
               kieudan3.td.y = -7;

           }
           /// quy doi lever
        if (maybay.diem != 0)
           {
               maybay.lever = maybay.diem / 100;
           }

        if (maybay.lever == 1)
           {
             TextColor(2);
             timedelay = 10;
           }
        if (maybay.lever == 2)
           {
             TextColor(4);
             timedelay = 5;
           }
         if(maybay.lever == 3)
           {
             TextColor(5);
             timedelay = 1;
           }
         if(maybay.lever == 4)
           {
             TextColor(9);
             timedelay = 1/5;
           }
         if(maybay.lever == 5)
           {
             TextColor(1);
             timedelay = 1/10;
           }

      /// *********tinh toan va cham*********


        ///***** khi may bay va cham voi phan thuong
          int DXpt = 0;
          int DYpt = 0;
        DXpt = abs( thuong.td.x - maybay.td.x);/// tinh khoang cach tu tam phan thuong
        DYpt = abs( thuong.td.y - maybay.td.y);/// toi tam xe
        if(DXpt < 3 && DYpt< 3)        /// pham vi an tien
        {
            maybay.diem = maybay.diem + 100;
            thuong.td.x = roadWidth +2;            /// giau di toa do  x y cua phan thuong
            thuong.td.y = consoleCao + 4;

        }
        ///******* khi xe va cham voi bom
        int DXbom = 0;
        int DYbom = 0;
        DXbom = abs( bom.td.x - maybay.td.x);
        DYbom = abs( bom.td.y - maybay.td.y);
        if(DXbom < 3 && DYbom < 3)
        {
            maybay.diem = maybay.diem + 10;
            bom.td.x = roadWidth +5 ;
            bom.td.y = consoleCao + 4;/// dau di toa do cua bom
            vc1.td.x = 3 +rand() % (roadWidth - 5);
            vc1.td.y = -2;
            vc2.td.x = 3 +rand() % (roadWidth - 5);
            vc2.td.y = -6;
            vc3.td.x = 3 +rand() % (roadWidth - 5);
            vc3.td.y = -10;
            vc4.td.x = 3 +rand() % (roadWidth - 5);
            vc4.td.y = -14;
            vc5.td.x = 3 +rand() % (roadWidth - 5);
            vc5.td.y = -16;
            vc6.td.x = 3 +rand() % (roadWidth - 5);
            vc6.td.y = -18;

            }
            /// khi may bay va cham voi kieu dan
            /// *** kieu dan 1
            int DXD = 0;
            int DYD = 0;
            DXD = abs(kieudan1.td.x - maybay.td.x);
            DYD = abs(kieudan1.td.y - maybay.td.y);
            if (DXD < 3 && DYD < 3)
            {
              capdodan = capdodan + 2;
              kieudan1.td.x = roadWidth +3;
              kieudan1.td.y = consoleCao +6;
            }

            DXD = abs(kieudan2.td.x - maybay.td.x);
            DYD = abs(kieudan2.td.y - maybay.td.y);
            if (DXD < 3 && DYD < 3)
            {
              capdodan = capdodan + 2;
              kieudan2.td.x = roadWidth +3;
              kieudan2.td.y = consoleCao +8;
            }
            DXD = abs(kieudan3.td.x - maybay.td.x);
            DYD = abs(kieudan3.td.y - maybay.td.y);
            if (DXD < 3 && DYD < 3)
            {
              capdodan = capdodan + 2;
              kieudan3.td.x = roadWidth +3;
              kieudan3.td.y = consoleCao +10;
            }
          /// *** va cham giua dan va vat can
          /// dan 1:
          ///vc1
             int DXdan;
             int DYdan;

             for ( i = 0; i < dan1.sovien; i ++)
             {

                 DXdan = abs( dan1.toadodan[i].x - vc1.td.x);
                 DYdan =  abs( dan1.toadodan[i].y - vc1.td.y);
                 if ( DXdan < 2 && DYdan < 2)
                   {

                      maybay.diem ++;
                      vc1.td.x = 5 + rand() % ( roadWidth - 5);
                      vc1.td.y = -3;
                      dan1.toadodan[i].x = maybay.td.x;
                      dan1.toadodan[i].y = maybay.td.y - 2;
                     }

             }


             ///vc2
             for ( i = 0; i < dan1.sovien; i ++)
             {
                 DXdan = abs( dan1.toadodan[i].x - vc2.td.x);
                 DYdan = abs( dan1.toadodan[i].y - vc2.td.y);
                 if ( DXdan < 2 && DYdan < 2)
                 {

                      maybay.diem ++;
                      vc2.td.x = 3 + rand() % ( roadWidth - 5);
                      vc2.td.y = -6;
                      dan1.toadodan[i].x = maybay.td.x;
                      dan1.toadodan[i].y = maybay.td.y - 2;
                 }
             }
             ///vc3
             for ( i = 0; i < dan1.sovien; i ++)
             {
                 DXdan = abs( dan1.toadodan[i].x - vc3.td.x);
                 DYdan = abs( dan1.toadodan[i].y - vc3.td.y);
                 if ( DXdan < 2 && DYdan < 2)
                 {

                      maybay.diem ++;
                      vc3.td.x = 3 + rand() % ( roadWidth - 5);
                      vc3.td.y = -9;
                      dan1.toadodan[i].x = maybay.td.x;
                      dan1.toadodan[i].y = maybay.td.y -2 ;
                 }
             }
             ///vc4
             for ( i = 0; i < dan1.sovien; i ++)
             {
                 DXdan = abs( dan1.toadodan[i].x - vc4.td.x);
                 DYdan = abs( dan1.toadodan[i].y - vc4.td.y);
                 if ( DXdan < 2 && DYdan < 2)
                 {

                      maybay.diem ++;
                      vc4.td.x = 3 + rand() % ( roadWidth - 5);
                      vc4.td.y = -12;
                      dan1.toadodan[i].x = maybay.td.x;
                      dan1.toadodan[i].y = maybay.td.y- 2;
                 }
             }
             /// vc5
             for ( i = 0; i < dan1.sovien; i ++)
             {
                 DXdan = abs( dan1.toadodan[i].x - vc5.td.x);
                 DYdan = abs( dan1.toadodan[i].y - vc5.td.y);
                 if ( DXdan < 2 && DYdan < 2)
                 {

                      maybay.diem ++;
                      vc5.td.x = 3 + rand() % ( roadWidth - 5);
                      vc5.td.y = -15;
                      dan1.toadodan[i].x = maybay.td.x;
                      dan1.toadodan[i].y = maybay.td.y - 2;
                 }
             }
             /// vc6
             for ( i = 0; i < dan1.sovien; i ++)
             {
                 DXdan = abs( dan1.toadodan[i].x - vc6.td.x);
                 DYdan = abs( dan1.toadodan[i].y - vc6.td.y);
                 if ( DXdan < 2 && DYdan < 2)
                 {
                      maybay.diem ++;
                      vc6.td.x = 3 + rand() % ( roadWidth - 5);
                      vc6.td.y = -18;
                      dan1.toadodan[i].x = maybay.td.x;
                      dan1.toadodan[i].y = maybay.td.y - 2;
                 }
             }
              /// dan 2:
          ///vc1
             int DXdan1;
             int DYdan1;
             for ( i = 0; i < dan2.sovien; i ++)
             {
                 DXdan1 = abs( dan2.toadodan[i].x - vc1.td.x);
                 DYdan1 =  abs( dan2.toadodan[i].y - vc1.td.y);
                 if ( DXdan1 < 2 && DYdan1 < 2)
                 {

                      maybay.diem ++;
                      vc1.td.x = 5 + rand() % ( roadWidth - 5);
                      vc1.td.y = -3;
                      dan2.toadodan[i].x = maybay.td.x - 1;
                      dan2.toadodan[i].y = maybay.td.y - 2;
                 }
             }
             ///vc2
             for ( i = 0; i < dan2.sovien; i ++)
             {
                 DXdan1 = abs( dan2.toadodan[i].x - vc2.td.x);
                 DYdan1 = abs( dan2.toadodan[i].y - vc2.td.y);
                 if ( DXdan1 < 2 && DYdan1 < 2)
                 {

                      maybay.diem ++;
                      vc2.td.x = 3 + rand() % ( roadWidth - 5);
                      vc2.td.y = -6;
                      dan2.toadodan[i].x = maybay.td.x - 1;
                      dan2.toadodan[i].y = maybay.td.y - 2;
                 }
             }
             ///vc3
             for ( i = 0; i < dan2.sovien; i ++)
             {
                 DXdan1 = abs( dan2.toadodan[i].x - vc3.td.x);
                 DYdan1 = abs( dan2.toadodan[i].y - vc3.td.y);
                 if ( DXdan1 < 2 && DYdan1 < 2)
                 {

                      maybay.diem ++;
                      vc3.td.x = 3 + rand() % ( roadWidth - 5);
                      vc3.td.y = -9;
                      dan2.toadodan[i].x = maybay.td.x - 1;
                      dan2.toadodan[i].y = maybay.td.y -2 ;
                 }
             }
             ///vc4
             for ( i = 0; i < dan2.sovien; i ++)
             {
                 DXdan1 = abs( dan2.toadodan[i].x - vc4.td.x);
                 DYdan1 = abs( dan2.toadodan[i].y - vc4.td.y);
                 if ( DXdan1 < 2 && DYdan1 < 2)
                 {

                      maybay.diem ++;
                      vc4.td.x = 3 + rand() % ( roadWidth - 5);
                      vc4.td.y = -12;
                      dan2.toadodan[i].x = maybay.td.x - 1;
                      dan2.toadodan[i].y = maybay.td.y- 2;
                   }
             }
             /// vc5
             for ( i = 0; i < dan2.sovien; i ++)
             {
                 DXdan1 = abs( dan2.toadodan[i].x - vc5.td.x);
                 DYdan1 = abs( dan2.toadodan[i].y - vc5.td.y);
                 if ( DXdan1 < 2 && DYdan1 < 2)
                 {

                      maybay.diem ++;
                      vc5.td.x = 3 + rand() % ( roadWidth - 5);
                      vc5.td.y = -15;
                      dan2.toadodan[i].x = maybay.td.x - 1;
                      dan2.toadodan[i].y = maybay.td.y - 2;
                 }
             }
             /// vc6
             for ( i = 0; i < dan2.sovien; i ++)
             {
                 DXdan1 = abs( dan2.toadodan[i].x - vc6.td.x);
                 DYdan1 = abs( dan2.toadodan[i].y - vc6.td.y);
                 if ( DXdan1 < 2 && DYdan1 < 2)
                 {

                      maybay.diem ++;
                      vc6.td.x = 3 + rand() % ( roadWidth - 5);
                      vc6.td.y = -18;
                      dan2.toadodan[i].x = maybay.td.x - 1;
                      dan2.toadodan[i].y = maybay.td.y - 2;
                 }
             }
              /// dan 3:
          ///vc1
             int DXdan2;
             int DYdan2;
             for ( i = 0; i < dan3.sovien; i ++)
             {
                 DXdan2 = abs( dan3.toadodan[i].x - vc1.td.x);
                 DYdan2 =  abs( dan3.toadodan[i].y - vc1.td.y);
                 if ( DXdan2 < 2 && DYdan2 < 2)
                 {
                      maybay.diem ++;
                      vc1.td.x = 5 + rand() % ( roadWidth - 5);
                      vc1.td.y = -3;
                      dan3.toadodan[i].x = maybay.td.x - 1;
                      dan3.toadodan[i].y = maybay.td.y - 2;
                 }
             }
             ///vc2
             for ( i = 0; i < dan3.sovien; i ++)
             {
                 DXdan2 = abs( dan3.toadodan[i].x - vc2.td.x);
                 DYdan2 = abs( dan3.toadodan[i].y - vc2.td.y);
                 if ( DXdan2 < 2 && DYdan2 < 2)
                 {
                      maybay.diem ++;
                      vc2.td.x = 3 + rand() % ( roadWidth - 5);
                      vc2.td.y = -6;
                      dan3.toadodan[i].x = maybay.td.x + 1;
                      dan3.toadodan[i].y = maybay.td.y - 2;
                 }
             }
             ///vc3
             for ( i = 0; i < dan3.sovien; i ++)
             {
                 DXdan2 = abs( dan3.toadodan[i].x - vc3.td.x);
                 DYdan2 = abs( dan3.toadodan[i].y - vc3.td.y);
                 if ( DXdan2 < 2 && DYdan2 < 2)
                 {

                      maybay.diem ++;
                      vc3.td.x = 3 + rand() % ( roadWidth - 5);
                      vc3.td.y = -9;
                      dan3.toadodan[i].x = maybay.td.x + 1;
                      dan3.toadodan[i].y = maybay.td.y -2 ;
                 }
             }
             ///vc4
             for ( i = 0; i < dan3.sovien; i ++)
             {
                 DXdan2 = abs( dan3.toadodan[i].x - vc4.td.x);
                 DYdan2 = abs( dan3.toadodan[i].y - vc4.td.y);
                 if ( DXdan2 < 2 && DYdan2 < 2)
                 {

                      maybay.diem ++;
                      vc4.td.x = 3 + rand() % ( roadWidth - 5);
                      vc4.td.y = -12;
                      dan3.toadodan[i].x = maybay.td.x + 1;
                      dan3.toadodan[i].y = maybay.td.y- 2;
                 }
             }
             /// vc5
             for ( i = 0; i < dan3.sovien; i ++)
             {
                 DXdan2 = abs( dan3.toadodan[i].x - vc5.td.x);
                 DYdan2 = abs( dan3.toadodan[i].y - vc5.td.y);
                 if ( DXdan2 < 2 && DYdan2 < 2)
                {

                      maybay.diem ++;
                      vc5.td.x = 3 + rand() % ( roadWidth - 5);
                      vc5.td.y = -15;
                      dan3.toadodan[i].x = maybay.td.x + 1;
                      dan3.toadodan[i].y = maybay.td.y - 2;
                 }
             }
             /// vc6
             for ( i = 0; i < dan3.sovien; i ++)
             {
                 DXdan2 = abs( dan3.toadodan[i].x - vc6.td.x);
                 DYdan2 = abs( dan3.toadodan[i].y - vc6.td.y);
                 if ( DXdan2 < 2 && DYdan2 < 2)
                 {
                      maybay.diem ++;
                      vc6.td.x = 3 + rand() % ( roadWidth - 5);
                      vc6.td.y = -18;
                      dan3.toadodan[i].x = maybay.td.x + 1;
                      dan3.toadodan[i].y = maybay.td.y - 2;
                 }
             }

             /// ***va cham giua xe va vat can***
             ///vc1
             int DXxe = 0;
             int DYxe = 0;
             DXxe = abs( maybay.td.x - vc1.td.x);
             DYxe = abs( maybay.td.y - vc1.td.y);
             if ( DXxe < 3 && DYxe < 3)
             {
               gotoxy ( 10,15);
               printf("GAMEOVER");
               while(_getch() != 13);
               goto gameover;
             }
             /// vc2
             DXxe = abs( maybay.td.x - vc2.td.x);
             DYxe = abs( maybay.td.y - vc2.td.y);
             if ( DXxe < 3 && DYxe < 3)
             {
               gotoxy ( 10,15);
               printf("GAMEOVER");
               while(_getch() != 13);
               goto gameover;
             }
             ///vc3
             DXxe = abs( maybay.td.x - vc3.td.x);
             DYxe = abs( maybay.td.y - vc3.td.y);
             if ( DXxe < 3 && DYxe < 3)
             {
               gotoxy ( 10,15);
               printf("GAMEOVER");
               while(_getch() != 13);
               goto gameover;
             }
             /// vc4
             DXxe = abs( maybay.td.x - vc4.td.x);
             DYxe = abs( maybay.td.y - vc4.td.y);
             if ( DXxe < 3 && DYxe < 3)
             {
               gotoxy ( 10,15);
               printf("GAMEOVER");
               while(_getch() != 13);
               goto gameover;
             }
             /// vc5
             DXxe = abs( maybay.td.x - vc5.td.x);
             DYxe = abs( maybay.td.y - vc5.td.y);
             if ( DXxe < 3 && DYxe < 3)
             {
               gotoxy ( 10,15);
               printf("GAMEOVER");
               while(_getch() != 13);
               goto gameover;
             }
             /// vc6
             DXxe = abs( maybay.td.x - vc6.td.x);
             DYxe = abs( maybay.td.y - vc6.td.y);
             if ( DXxe < 3 && DYxe < 3)
             {
               gotoxy ( 10,15);
               printf("GAMEOVER");
               while(_getch() != 13);
               goto gameover;
             }

       Sleep(timedelay);

  }
    gameover:
    return 0;
}