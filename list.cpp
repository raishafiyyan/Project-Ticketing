#include <iostream>
#include "list.h"

using namespace std;

void createstudio (List &l)
{
    first(l)=nil;
    last(l)=nil;
}

//di function alokasi variabel infotypenya dibuat beda biar gampang bedainnya (studio x) , (jadwal y)
address_studio alokasi_studio (studio x)
{
    address_studio p=new elmstudio;
    info_studio(p)=x;
    next(p)=nil;
    prev(p)=nil;
    firstjadwal(p)=nil;
    return p;
}
address_jadwal alokasi_jadwal (jadwal y)
{
    address_jadwal p=new elmjadwal;
    info_jadwal(p)=y;
    next(p)=nil;
    return p;
}

//Insert First
void insertfirst_studio (List &l, address_studio p)
{
    if (first(l)==nil)
    {
        first(l)=p;
        last(l)=p;
    }
    else
    {
        next(p)=first(l);
        prev(first(l))=p;
        first(l)=p;
    }
}
void insertfirst_jadwal (address_studio &p, address_jadwal &q)
{
    if (firstjadwal(p)==nil)
    {
        firstjadwal(p)=q;
    }
    else
    {
        next(q)=firstjadwal(p);
        prev(firstjadwal(p))=q;
        firstjadwal(p)=q;
    }
}

//Insert Last
void insertlast_studio (List &l, address_studio p)
{
    if(first(l)==nil)
    {
        info_studio(p).id_studio=1;
        first(l)=p;
        last(l)=p;
    }
    else
    {
        info_studio(p).id_studio=info_studio(last(l)).id_studio+1;
        prev(p)=last(l);
        next(last(l))=p;
        last(l)=p;
    }
}
void insertafter_studio (List &l, address_studio p, address_studio prec)
{
    prec=next(first(l));

    if (first(l)==nil)
    {
        insertfirst_studio(l,p);
    }
    else if (last(l) == nil)
    {
        insertlast_studio(l,p);
    }
    else
    {
        next(p)=next(prec);
        prev(p)=prec;
        prev(next(prec))=p;
        next(prec)=p;
    }
}
void insertlast_jadwal (address_studio &p, address_jadwal &q)
{
    if (firstjadwal(p)==nil)
    {
        info_jadwal(q).id_jadwal=1;
        firstjadwal(p)=q;
    }
    else
    {
        address_jadwal x = firstjadwal(p);
        while(next(x)!=nil)
        {
            x=next(x);
        }
        info_jadwal(q).id_jadwal=info_jadwal(x).id_jadwal+1;
        prev(q)=x;
        next(x)=q;
        lastjadwal(p)=q;
    }
}
void insertafter_jadwal (address_studio &p, address_jadwal &q,int x)
{
    address_jadwal prec=firstjadwal(p);
    if(prec==nil)
    {
        insertfirst_jadwal(p,q);
    }
    else
    {
        while (info_jadwal(prec).id_jadwal!=x)
        {
            prec=next(prec);
        }
        if(next(prec)==nil)
        {
            insertlast_jadwal(p,q);
        }
        else
        {
            prev(q)=prec;
            next(q)=next(prec);
            prev(next(prec))=q;
            next(prec)=q;
        }
    }
}

//DELETE LAST
void deletefirst_studio (List &l, address_studio &p)
{
    if (first(l)==nil)
    {
        cout << "data tidak ada";
    }
    else if(first(l)==last(l))
    {
        first(l)=nil;
        last(l)=nil;
    }
    else
    {
        p=first(l);
        first(l)=next(first(l));
        next(p)=nil;
        prev(first(l))=nil;
    }
}
void deletefirst_jadwal (address_studio &p, address_jadwal &q)
{
    if (firstjadwal(p)!=nil)
    {
        q=firstjadwal(p);
        if (next(q)!=nil)
        {
            firstjadwal(p)=next(firstjadwal(p));
            next(q)=nil;
            prev(firstjadwal(p))=nil;
        }
        else
        {
            firstjadwal(p)=nil;
        }
    }
}

void deleteafter_jadwal (address_studio &p, address_jadwal &q,int y)
{
    q=firstjadwal(p);
    if (q!= nil)
    {
        while (info_jadwal(q).id_jadwal!=y)
        {
            q=next(q);
        }
        if(q=firstjadwal(p))
        {
            deletefirst_jadwal(p,q);
        }
        else if(next(q)!=nil)
        {
            address_jadwal prec=prev(q);
            next(prec)=next(q);
            prev(next(q))=prec;
            prev(q)=nil;
            next(q)=nil;
        }
        else
        {
            address_jadwal prec=prev(q);
            next(prec)=nil;
            prev(q)=nil;
        }
    }
    else
    {
        cout << "data jadwal belum ada";
    }
}
void deleteafter_studio (List &l,address_studio &p, address_studio prec)
{
    if(p==first(l))
    {
        deletefirst_studio(l,p);
    }
    else if(p==last(l))
    {
        deletelast_studio(l,p);
    }
    else
    {
        prec=prev(p);
        next(prec)=next(p);
        prev(next(p))=prec;
        prev(p)=nil;
        next(p)=nil;
    }
}

//DELETE LAST
void deletelast_studio (List &l, address_studio &p)
{
    if (first(l)==nil)
    {
        cout << "data tidak ada";
    }
    else if(first(l)==last(l))
    {
        first(l)=nil;
        last(l)=nil;
    }
    else
    {
        p=last(l);
        last(l)=prev(last(l));
        prev(p)=nil;
        next(last(l))=nil;
    }
}
void deletelast_jadwal (address_studio &p, address_jadwal &q)
{
    q=lastjadwal(p);
    if(q!=nil)
    {
        lastjadwal(p)=prev(q);
        prev(q)=nil;
        next(lastjadwal(p))=nil;
    }
    else
    {
        cout << "data tidak ada";
    }
}

address_studio findelm_studio (List l,int x)
{
    address_studio p;
    p=first(l);
    while(info_studio(p).id_studio!=x && p!=nil)
    {
        p=next(p);
    }
    if(p!=nil)
    {
        return p;
    }
    else
    {
        return nil;
    };
}
address_studio findelm_studio_sama (List l,int x)
{
    address_studio p;
    p=first(l);
    while(p!=nil)
    {
        if (info_studio(p).id_studio==x)
        {
            return p;
        }
        else
        {
            p=next(p);
        }
    }

}
address_jadwal findelm_jadwal (address_studio p,int y)
{
    address_jadwal q;
    q=firstjadwal(p);
    while(info_jadwal(q).id_jadwal!=y && q!=nil)
    {
        q=next(q);
    }
    if(q!=nil)
    {
        return q;
    }
    else
    {
        cout << "Data tidak ada";
    }
}
address_jadwal findelm_jadwal_sama (address_studio p,int y)
{
    address_jadwal q;
    q=firstjadwal(p);
    while(q!=nil)
    {
        if(info_jadwal(q).id_jadwal==y)
        {
            return q;
        }
        else
        {
            q=next(q);
        }
    }
}

void printinfo_studio (List l)
{
    address_studio p;
    address_jadwal q;
    p=first(l);
    while (p!=nil)
    {
        cout <<"ID Studio   : "<<info_studio(p).id_studio<<endl
             <<"Nama Studio : "<<info_studio(p).nama<<endl<<endl;
        p=next(p);
    }
}
void printinfo_jadwal (address_studio &p,address_jadwal q)
{
    if (firstjadwal(p)!=nil)
    {
        q=firstjadwal(p);
        while(q!=nil)
        {
            cout << "ID jadwal : "<< info_jadwal(q).id_jadwal<<endl
                 << "Jam Mulai : "<< info_jadwal(q).jam << endl
                 << "Kapasitas : "<< info_jadwal(q).kapasitas << endl << endl;
            q=next(q);
        }
    }
}

void add_studio(studio &x)
{
    cout <<"Nama Studio : ";
    cin >> x.nama;
}
void add_jadwal(jadwal &y,address_studio &p)
{
    cout <<"Jam       : ";
    cin >> y.jam;
    cout <<"Kapasitas : ";
    cin >> y.kapasitas;
}

int kapasitasbanyak (address_studio p)
{
    int temp=0;
    address_jadwal q=firstjadwal(p);
    if(q!=nil)
    {
        while (q!=nil)
        {
            if (info_jadwal(q).kapasitas>temp)
            {
                temp=info_jadwal(q).kapasitas;
            }
            q=next(q);
        }
        return temp;
    }
    else
    {
        cout <<"anda belum menginput jadwal";
    }
};


