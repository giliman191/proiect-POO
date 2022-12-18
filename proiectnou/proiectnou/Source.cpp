#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"
int main()
{
	Bilet b1;
	Bilet b2(1, 10, 1, 120, "VIP");
	Bilet b3(b2);
	cout << b1;
	cout << b2;
	cout << b3;
	b1 = b2;
	cout << "biletul b1: " << b1;
	cout << "biletul b2: " << b2;
	cout << "Id bilet b1: " << b1.getIdBilet() << endl;
	cout << "Id bilet b2: " << b2.getIdBilet() << endl;
	cout << "Id bilet b3: " << b3.getIdBilet() << endl;
	cout << "Categorie bilet b1: " << b1.getCategorie() << endl;
	cout << "Categorie bilet b2: " << b2.getCategorie() << endl;
	cout << "Categorie bilet b3: " << b3.getCategorie() << endl;
	cout << b1.getNrLoc() << endl;
	cout << b2.getNrLoc() << endl;
	cout << b3.getNrLoc() << endl;
	cout << b1.getNrRand() << endl;
	cout << b2.getNrRand() << endl;
	cout << b3.getNrRand() << endl;
	cout << b1.getNrZona() << endl;
	cout << b2.getNrZona() << endl;
	cout << b3.getNrZona() << endl;
	cout << b1.getPret() << endl;
	cout << b2.getPret() << endl;
	cout << b3.getPret() << endl;
	b1.setCategorie("Normal");
	b1.setNrLoc(5);
	b1.setNrRand(2);
	b1.setNrZona(1);
	b1.setPret(100);
	cout << b1;
	if (b1 == b2)
		cout << "Biletul 1 este egal cu biletul 2" << endl;
	else
		cout << "Biletul 1 nu este egal cu biletul 2" << endl;
	if (b1 == b3)
		cout << "Biletul 1 este egal cu biletul 3" << endl;
	else
		cout << "Biletul 1 nu este egal cu biletul 3" << endl;
	if (b2 == b3)
		cout << "Biletul 2 este egal cu biletul 3" << endl;
	else
		cout << "Biletul 2 nu este egal cu biletul 3" << endl;
	if (b1 != b2)
		cout << "Biletul 1 este diferit de biletul 2" << endl;
	else
		cout << "Biletul 1 nu este diferit de biletul 2" << endl;
	Eveniment e1;
	Eveniment e2("Teatrul", 10, 2, 2022, 20, 30);
	Eveniment e3(e2);
	cout << e1;
	cout << e2;
	cout << e3;
	e1 = e2;
	cout << e1;
	cout << e2;
	e1.setAn(2019);
	e1.setLuna(12);
	e1.setZi(25);
	e1.setOra(20);
	e1.setMinut(30);
	cout << e1 << endl;
	cout << e1.getAn() << endl;
	cout << e1.getLuna() << endl;
	cout << e1.getZi() << endl;
	cout << e1.getOra() << endl;
	cout << e1.getMinut() << endl;
	e1--;
	e2 += 10;
	cout << e1;
	cout << e2;
	Locatie l1;
	int v[]{ 10,20,50 };
	Locatie l2("Teatrul",3,v,3);
	cout << l1;
	cout << l2;
	Locatie l3 = l2;
	int x[] = {15,20,30,34};
	l1.setNr_Locuri(4, x);
	cout << endl;
	cout << 1111111;
	cout << endl;
	cout << "NUMAR ZONE    " << endl;
	l1.SetNr_Zone(4);
	cout << l1.getNr_Zone()<<endl;
	cout << "Procent: " << endl;
	cout << l1.Procent_Locuri_ocupate()<<endl; /// se afiseaza zero deoarece nu am inceput sa marchez locurile ocupate
	cout << l1.getNume_Locatie() << endl;
	l2++;
	cout << l2.getNr_Zone() << endl;
	cout << l2[1]<<endl;
	l3.setNume_Locatie("Fotbal");
	cout << l3.getNume_Locatie() << endl;
	Locatie l4;
	cin >> l4;
	cout << l4;
	return 0;
}