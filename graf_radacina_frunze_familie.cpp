/*
    Se da un fisier text ce contine pe prima linie un numar natural n si pe urmatoarea linie vectorul de tati.
    construiti matricea de adiacenta.
    determinati radacina arborelului
    determinati frunzele
    determinati descendentii nodului.
    determinati descendentii nodului.
    verificati daca doua noduri sunt frati
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream in("GRAF.TXT");
int n, t[100], a[100][100],  xnod, noda,nodb;
void citire()
{
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>t[i];
        a[t[i]][i]=a[i][t[i]]=1;
    }
}
void radacina()
{
    cout<<"Radacina:";
    for(int i=1;i<=n;i++)
        if(t[i]==0)
            cout<<i;
}
void frunze()
{
    int verific;
    for(int i=1;i<=n;i++)
    {
        verific=1;
        for(int j=1;j<=n;j++)
            if(t[j]==i)
            {
                verific=0;
                break;
            }
        if(verific==1)
            cout<<i<<" ";

    }
}
void matrice()
{
    for(int i=1;i<=n;i++)
        {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
            cout<<"\n";
        }
}
void stramosi(int nod)
{
     int i;
    for(i=1;i<=n;i++)
        if(t[t[nod]]==i)
            {
                cout<<i<<" ";
                stramosi(i);
            }
}
void descendent(int nod)
{
    int i;
    for(i=1;i<=n;i++)
        if(t[i]==nod)
            {
                cout<<i<<" ";
                descendent(i);
            }
}
void ascendent(int nod)
{
    int i;
    for(i=1;i<=n;i++)
        if(t[nod]==i)
            {
                cout<<i<<" ";
                ascendent(i);
            }
}
void nepoti(int nod)
{
     int i;
    for(i=1;i<=n;i++)
        if(t[t[i]]==nod)
            {
                cout<<i<<" ";
                descendent(i);
            }
}
void frati(int a, int b)
{
    if(t[a]==t[b])
        cout<<"Sunt frati";
    else
        cout<<"NU sunt frati";
}
int main()
{
    citire();
    matrice();
    radacina();
    cout<<"\n";
    frunze();
    cout<<"\n";
    cout<<"Introduceti nodul:";
    cin>>xnod;
    cout<<"\nAscendenti:";
    ascendent(xnod);
    cout<<"\nDescendenti:";
    descendent(xnod);
    cout<<"\nStramosi:";
    stramosi(xnod);
    cout<<"\nNepoti:";
    nepoti(xnod);
    cout<<"\n";
    cout<<"Introduceti nodurile (presupusii frati):";
    cin>>noda;
    cin>>nodb;
    frati(noda,nodb);

    return 0;
}
