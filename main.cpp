#include <iostream>
#include <stdlib.h>
#include "list.h"

using namespace std;

int main()
{
    List l;
    studio x;
    jadwal y;
    address_studio p;
    address_jadwal q;
    createstudio(l);
    int pilihan;
    int cariID;
    while (pilihan!=10)
    {
        system("CLS");
        cout << "                     SELAMAT DATANG DI 06 CINEPLEX                         "<<"\n"
             << "==========================================================================="<<"\n"
             << "PILIHAN MENU: "<<"\n"
             << "1. Add Studio"<<"\n"
             << "2. Find Studio By ID"<<"\n"
             << "3. Edit Studio"<<"\n"
             << "4. Add Jadwal"<<"\n"
             << "5. Find Jadwal by ID"<<"\n"
             << "6. Delete Jadwal from Studio"<<"\n"
             << "7. View List Jadwal from Studio"<<"\n"
             << "8. Delete Studio and Jadwal"<<"\n"
             << "9. Cari Kapasitas terbanyak"<<"\n"
             << "10. Exit"<<"\n"
             << "pilihan: ";
        cin >> pilihan;

        if (pilihan==1)
        {
            system("CLS");
            add_studio(x);
            address_studio r=findelm_studio_sama(l,x.id_studio);
            if(r==nil)
            {
                p=alokasi_studio(x);
                insertlast_studio(l,p);
                system("CLS");
                cout <<"Data Berhasil di Input" << endl
                     <<"======================"<<endl;
                printinfo_studio(l);
            }
            else
            {
                cout << "Data Sudah Ada";
            };

            getch();
        }
        else if (pilihan==2)
        {
            system("CLS");
            cout << "Masukkan ID Studio yang akan dicari : ";
            cin >> cariID;
            p=findelm_studio_sama(l,cariID);
            if (p != nil)
            {
                cout<<endl<<"Data sebagai berikut : \n" << endl
                    <<"ID Studio : "<<info_studio(p).id_studio<<endl
                    <<"Nama : "<<info_studio(p).nama<<endl<<endl;
            }
            else
            {
                cout << endl;
                cout << "Data tidak ada";
            }
            getch();
            system("CLS");
        }
        else if (pilihan==3)
        {
            system("CLS");
            cout << "Data Studio yang ada" << endl
                 << "====================" << endl<<endl;
            printinfo_studio(l);
            cout << endl;
            cout << "Masukkan ID Studio yang ingin Anda ubah : ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if (p!=nil)
            {
                cout<<"Nama Studio : ";
                cin >> info_studio(p).nama;
                cout << endl;
                cout << "Data berhasil di ubah";
            }
            else
            {
                cout << "Data tidak ditemukan";
            }
            getch();
        }
        else if (pilihan==4)
        {
            system("CLS");
            cout << "Data Studio yang ada" << endl
                 << "====================" << endl<<endl;
            printinfo_studio(l);
            cout << endl;
            cout << "Masukkan ID Studio untuk input Data Jadwal: ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if(p!=nil)
            {
                cout <<endl;
                add_jadwal(y,p);
                address_jadwal x=findelm_jadwal_sama(p,y.id_jadwal);
                if(x==nil)
                {
                    address_jadwal q=alokasi_jadwal(y);
                    insertlast_jadwal(p,q);
                    system("CLS");
                    cout << "Data berhasil di input"<<endl<<endl;
                    printinfo_jadwal(p,q);
                }
                else
                {
                    cout << endl;
                    cout << "Data Jadwal Sudah Ada";
                }
            }
            else
            {
                cout << "Studio tidak ada";
            }
            getch();
        }
        else if (pilihan==5)
        {
            system("CLS");
            cout << "Data Studio yang ada" << endl
                 << "====================" << endl<<endl;
            printinfo_studio(l);
            cout << endl;
            cout << "Masukkan ID Studio untuk mencari Data Jadwal : ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if(p!=nil)
            {
                cout << endl << "Masukkan ID Jadwal yang Anda cari : " ;
                cin >> cariID;
                q = findelm_jadwal_sama(p,cariID);
                if(q!=nil)
                {
                    system("CLS");
                    cout<<"Data Jadwal sebagai berikut :" << endl << endl
                        <<"ID Jadwal : "<<info_jadwal(q).id_jadwal<<endl
                        <<"Jam       : "<<info_jadwal(q).jam<<endl
                        <<"Kapasitas : "<<info_jadwal(q).kapasitas<<endl;
                }
                else
                {
                    system("CLS");
                    cout << endl <<"ID Jadwal tidak ada";
                }
            }
            else
            {
                cout << "Studio tidak ditemukan";
            }
            getch();
        }
        else if (pilihan==6)
        {
            system("CLS");
            printinfo_studio(l);
            cout << endl;
            cout << "Masukkan ID Studio untuk menghapus Data Jadwal: ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if(p!=nil)
            {
                int h;
                system("CLS");
                printinfo_jadwal(p,q);
                cout << "Masukkan ID Jadwal yang ingin dihapus: ";
                cin >> h;
                address_jadwal hapus=findelm_jadwal(p,h);
                if(hapus!=nil)
                {
                    deleteafter_jadwal(p,q,h);
                    cout<<endl;
                    printinfo_jadwal(p,q);
                }
                else
                {
                    cout << "Jadwal tidak ditemukan";
                }
            }
            else
            {
                cout <<"ID Studio belum di input";
            }

            getch();
        }
        else if (pilihan==7)
        {
            system("CLS");
            printinfo_studio(l);
            cout << "Masukkan ID Studio untuk menampilkan Data Jadwal : ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if(p!=nil)
            {
                system("CLS");
                printinfo_jadwal(p,q);
            }
            else
            {
                cout <<"ID Studio belum di input";
            }
            getch();
        }
        else if (pilihan==8)
        {
            system("CLS");
            address_studio prec;
            printinfo_studio(l);
            cout << "Masukkan ID Studio yang ingin anda hapus: ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if (p!=nil)
            {
                deleteafter_studio(l,p,prec);
                system("CLS");
                cout << "Data berhasil dihapus, berikut data sekarang: "<<endl<<endl;
                if(p==nil)
                {
                    cout << "Tidak ada data lagi";
                }
                else
                {
                    printinfo_studio(l);
                }
            }
            else
            {
                cout << "Studio tidak ditemukan";
            }
            getch();
        }
        else if (pilihan==9)
        {
            system("CLS");
            printinfo_studio(l);
            cout << endl << "Masukkan ID Studio untuk mencari kapasitas terbesar dari suatu jadwal : ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if(p!=nil)
            {
                system("CLS");
                printinfo_jadwal(p,q);
                cout << endl;
                int x=kapasitasbanyak(p);
                cout << "Kapasitas terbesar pada studio ini adalah: "<<x;
                getch();
            }
        }
    }
    return 0;
}
