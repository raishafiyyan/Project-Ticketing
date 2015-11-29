#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string>

#define info_studio(p) (p)->info_studio
#define info_jadwal(p) (p)->info_jadwal
#define next(p) (p)->next
#define next_jadwal(p) (p)->next_jadwal
#define prev(p) (p)->prev
#define first(l) ((l).first)
#define last(l) ((l).last)
#define firststudio(p) (p)->firststudio
#define laststudio(p) (p)->laststudio
#define firstjadwal(p) (p)->firstjadwal
#define lastjadwal(p) (p)->lastjadwal
#define nil NULL

using namespace std;

typedef struct elmstudio *address_studio;
typedef struct elmfilm *address_film;
typedef struct elmjadwal *address_jadwal;

//DEKLARASI STUDIO
struct studio
{
    int id_studio;
    string nama;
};

struct elmstudio
{
    studio info_studio;
    address_studio next,prev;
    address_film film;
    address_jadwal firstjadwal,lastjadwal;
};

//DEKLARASI FILM
struct elmfilm
{
    address_jadwal next_jadwal;
    address_film next;
};

struct list_film
{
    address_film firstfilm;
};

//DEKLARASI JADWAL
struct jadwal
{
    int id_jadwal;
    int jam;
    int kapasitas;
    int baris;
    int kolom;
    int tempat_duduk[100][100];
};

struct elmjadwal
{
    jadwal info_jadwal;
    address_jadwal next,prev;
};

//LIST
struct List
{
    address_studio first,last;
};

//DEKLARASI PROCEDURE DAN FUNCTION
void createstudio (List & );

address_studio alokasi_studio (studio );
address_jadwal alokasi_jadwal (jadwal );

void insertfirst_studio (List &, address_studio );
void insertfirst_jadwal (address_studio &, address_jadwal &);

void insertafter_studio (List &, address_studio, address_studio );
void insertafter_jadwal (address_studio &, address_jadwal &,int );

void insertlast_studio (List &, address_studio );
void insertlast_jadwal (address_studio &, address_jadwal &);

void deletefirst_studio (List &, address_studio &);
void deletefirst_jadwal (address_studio &, address_jadwal &);

void deleteafter_studio (List &,address_studio &,address_studio );
void deleteafter_jadwal (address_studio &, address_jadwal &,int );

void deletelast_studio (List &, address_studio &);
void deletelast_jadwal (address_studio &, address_jadwal &);

address_studio findelm_studio (List ,int );
address_jadwal findelm_jadwal (address_studio ,int );

void printinfo_studio (List );
void printinfo_jadwal (address_studio &,address_jadwal );

void add_studio(studio &);
void add_jadwal(jadwal & ,address_studio & );

address_studio findelm_studio_sama (List ,int );
address_jadwal findelm_jadwal_sama (address_studio ,int );

int kapasitasbanyak (address_studio );
#endif // LIST_H_INCLUDED
