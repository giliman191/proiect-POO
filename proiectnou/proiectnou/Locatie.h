#pragma once
#include<iostream>
#include<cstring>
#include<cstring>
using namespace std;
#pragma warning(disable:4996)
class Locatie
{
	/*
		Clasa Locatie = COMPLET
	* SETTER SI GETTER:
	char* nume_locatie; sett + gett: bifat
	int nr_zone; sett + gett: bifat
	int* nr_locuri; sett + gett : bifat
	int nr_randuri; sett + gett : bifat

	*OPERATOR
	>>, << : bifat
	++, = , [] :bifat

	*CONSTRUCTORI:fara p, cu p, de copiere : BIFAT
	*DESTRUCTOR: BIFAT
	METODE:
	- metoda care calculeaza nr total de locuri dintr-o locatie : bifat
	- metoda care calculeaza cat % din locuri sunt ocupate : bifat
	- metoda care afiseaza cat% din locuri sunt ocupate ( folosind metoda de mai sus) : bifat
	*/
private:
	char* nume_locatie;
	int nr_zone; /// cate zone sunt in total
	int* nr_locuri;// nr_locuri[i]=x, unde x este numarul de locuri de pe randul i
	int nr_randuri;
public:
	Locatie() /// constructor implicit
	{
		this->nume_locatie = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume_locatie, "Necunoscut");
		this->nr_locuri = NULL;
		this->nr_randuri = 0;
		this->nr_zone = 0;
	}
	Locatie(const char* nume_locatie, int nr_zone, int* nr_locuri, int nr_randuri) /// constructor cu parametri
	{
		if (nume_locatie != NULL)
		{
			this->nume_locatie = new char[strlen(nume_locatie) + 1];
			strcpy(this->nume_locatie, nume_locatie);
		}
		else
		{
			this->nume_locatie = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume_locatie, "Necunoscut");
		}
		this->nr_zone = nr_zone;
		this->nr_randuri = nr_randuri;
		if (nr_randuri > 0)
		{
			this->nr_locuri = new int[nr_randuri];
			for (int i = 0; i < nr_randuri; i++)
				this->nr_locuri[i] = nr_locuri[i];
		}
		else this->nr_locuri = NULL;
	}
	Locatie(const Locatie& l) /// constructor copiere
	{
		if (l.nume_locatie != NULL) /// validare
		{
			this->nume_locatie = new char[strlen(l.nume_locatie) + 1];
			strcpy(this->nume_locatie, l.nume_locatie);
		}
		else
		{
			this->nume_locatie = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume_locatie, "Necunoscut");
		}
		this->nr_zone = l.nr_zone;
		this->nr_randuri = l.nr_randuri;
		if (l.nr_randuri > 0)
		{
			this->nr_locuri = new int[l.nr_randuri];
			for (int i = 0; i < l.nr_randuri; i++)
				this->nr_locuri[i] = l.nr_locuri[i];
		}
		else this->nr_locuri = NULL;
	}
	~Locatie() /// destructor
	{
		if (this->nume_locatie != NULL)
		{
			delete[] this->nume_locatie;
			this->nume_locatie = NULL;
		}
		if (this->nr_locuri != NULL)
		{
			delete[] this->nr_locuri;
			this->nr_locuri = NULL;
		}
	}
	void operator=(Locatie& l)
	{
		if (this->nume_locatie != NULL)
		{
			delete[] this->nume_locatie;
			this->nume_locatie = NULL;
		}
		if (this->nr_locuri != NULL)
		{
			delete[] this->nr_locuri;
			this->nr_locuri = NULL;
		}
		if (l.nume_locatie != NULL)
		{
			this->nume_locatie = new char[strlen(l.nume_locatie) + 1];
			strcpy(this->nume_locatie, l.nume_locatie);
		}
		else
		{
			this->nume_locatie = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume_locatie, "Necunoscut");
		}
		this->nr_zone = l.nr_zone;
		this->nr_randuri = l.nr_randuri;
		if (l.nr_randuri > 0)
		{
			this->nr_locuri = new int[l.nr_randuri];
			for (int i = 0; i < l.nr_randuri; i++)
				this->nr_locuri[i] = l.nr_locuri[i];
		}
		else this->nr_locuri = NULL;
	}



	friend ostream& operator<<(ostream& out, Locatie l)
	{
		out << "Nume locatie: " << l.nume_locatie << endl;
		out << "Numar zone: " << l.nr_zone << endl;
		out << "Numar randuri: " << l.nr_randuri << endl;
		out << "Numar locuri: ";
		for (int i = 0; i < l.nr_randuri; i++)
			out << l.nr_locuri[i] << " ";
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Locatie& l)
	{
		char buffer[100];
		cout << "Nume locatie: ";
		in >> ws;/// citeste spatiile before buffer
		cin.getline(buffer,99);
		l.nume_locatie = new char[strlen(buffer) + 1];
		strcpy(l.nume_locatie, buffer);
		cout << "\n";
		cout << "Numar zone: ";
		in >> l.nr_zone;
		cout << "\n";
		cout << "Numar randuri: ";
		in >> l.nr_randuri;
		cout << "\n";
		if (l.nr_locuri != NULL)
		{
			delete[] l.nr_locuri;
			l.nr_locuri = NULL;
		}
		if (l.nr_randuri > 0)
		{
			l.nr_locuri = new int[l.nr_randuri];
			for (int i = 0; i < l.nr_randuri; i++)
			{
				cout << "Numar locuri pe randul " << i + 1 << ": ";
				in >> l.nr_locuri[i];
				cout << "\n";
			}
		}
		else l.nr_locuri = NULL;
		cout << "\n";
		return in;
	}
	/// cei doi operatori
	friend Locatie operator ++(Locatie& t)
	{
		t.nr_zone++;
		return t;
	}
	friend Locatie operator++(Locatie& t, int)
	{
		Locatie copie = t;
		t.nr_zone++;
		return copie;
	}
	int& operator[](int poz)
	{
		if (poz >= 0 && poz < nr_randuri)
			return nr_locuri[poz];
		else throw new exception("Pozitie incorecta");
	}
	int getNr_Zone()
	{
		return nr_zone;
	}
	void SetNr_Zone(int nr_zone)
	{
		this->nr_zone = nr_zone;
	}
	int getNr_Randuri()
	{
		return nr_randuri;
	}
	void SetNr_Randuri(int nr_randuri)
	{
		this->nr_randuri = nr_randuri;
	}
	int* getNr_Locuri()
	{
		if (nr_locuri != nullptr && nr_randuri > 0) // deep copy
		{
			int* copie = new int[nr_randuri];
			for (int i = 0; i < nr_randuri; i++)
				copie[i] = nr_locuri[i];
			return copie;
		}
		else return nullptr;
	}
	void setNr_Locuri(int nr_randuri, int* nr_locuri)
	{
		if (this->nr_locuri != nullptr)
		{
			delete[] this->nr_locuri;
			this->nr_locuri = nullptr;
		}
		if (nr_randuri > 0)
		{
			this->nr_locuri = new int[nr_randuri];
			for (int i = 0; i < nr_randuri; i++)
				this->nr_locuri[i] = nr_locuri[i];
		}
		else this->nr_locuri = nullptr;
	}
	char* getNume_Locatie()
	{
		if (nume_locatie != nullptr) /// deep copy
		{
			char* copie = new char[strlen(nume_locatie) + 1];
			strcpy(copie, nume_locatie);
			return copie;
		}
		else return nullptr;
	}
	void setNume_Locatie(const char* nume_locatie)
	{
		if (this->nume_locatie != nullptr)
		{
			delete[] this->nume_locatie;
			this->nume_locatie = nullptr;
			if (nume_locatie != nullptr)
			{
				this->nume_locatie = new char[strlen(nume_locatie) + 1];
				strcpy(this->nume_locatie, nume_locatie);
			}
			else this->nume_locatie = nullptr;
		}
	}
	int Numar_Locuri_Totale()
	{
		int ct = 0;
		if (nr_locuri != nullptr && nr_randuri > 0)
			for (int i = 0; i < nr_randuri; i++)
				ct += nr_locuri[i];
		return ct;
	}
	double Procent_Locuri_ocupate()
	{
		double ct = 0;
		if (nr_locuri != nullptr && nr_randuri > 0)
			for (int i = 0; i < nr_randuri; i++)
				ct += nr_locuri[i];
		if (ct == 0) return 0;
		return ct / Numar_Locuri_Totale();
	}
	void Afisare_Procent_Locuri_Ocupate()
	{
		cout << "Sunt ocupate " << Procent_Locuri_ocupate() << "% din locuri" << endl;
	}
};