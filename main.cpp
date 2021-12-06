#pragma clang diagnostic push
#pragma ide diagnostic ignored "VirtualCallInCtorOrDtor"

#include <iostream>
#include <bits/stdc++.h>
#include <functional>

using namespace std;


bool string_is_alphas(string s) {
    for (string::iterator it = s.begin(); it != s.end(); it++) {
        if (isalpha(*it) == 0 && *it != '_')
            return false;
    }
    return true;
}

void valid_string(const string& s) {
    try {
        if (s.empty())
            throw 1;
        if (!string_is_alphas(s))
            throw 2;
    }
    catch (int e) {
        if (e == 1) {
            cout << "Eroare: stringul introdus e gol";
        }
        if (e == 2) {
            cout << "Eroare: stringul introdus nu contine doar litere";
        }
        exit(EXIT_FAILURE);
    }
}

class Destinatie {
protected:
    int pret_per_zi;
    string nume_destinatie;
public:
    Destinatie();

    Destinatie(string new_nume_destinatie);

    Destinatie(const Destinatie& d);

    Destinatie& operator=(const Destinatie& d);

    virtual ~Destinatie();

    virtual void citire(istream& input);

    virtual void afisare(ostream& output);

    friend istream& operator>>(istream& input, Destinatie& r);

    friend ostream& operator<<(ostream& output, Destinatie& r);


    int get_pret_per_zi() const;
};

Destinatie::Destinatie() {
    pret_per_zi = -1;
    nume_destinatie = string();
}

Destinatie::Destinatie(string new_nume_destinatie) : nume_destinatie(new_nume_destinatie) {
    pret_per_zi = -1;
}


Destinatie::Destinatie(const Destinatie& d) {
    this->pret_per_zi = d.pret_per_zi;
    nume_destinatie.clear();
    this->nume_destinatie = d.nume_destinatie;

}

Destinatie& Destinatie::operator=(const Destinatie& d) {
    if (this != &d) {
        this->pret_per_zi = d.pret_per_zi;
        nume_destinatie.clear();
        this->nume_destinatie = d.nume_destinatie;
        return *this;
    }
}

Destinatie::~Destinatie() {
    pret_per_zi = -1;
    nume_destinatie.clear();
}

void Destinatie::citire(istream& input) {
    cout << "Spuneti care este numele destinatiei: ";
    string s;
    cin >> s;
    valid_string(s);
    nume_destinatie = s;
    s.erase();
    cout << endl;
}

void Destinatie::afisare(ostream& output) {
    cout << "Numele destinatiei este: ";
    output << nume_destinatie;
    cout << endl;

    cout << "Pretul per zi al sejurului este de: ";
    output << pret_per_zi;
    cout << endl;
}

istream& operator>>(istream& input, Destinatie& r) {
    r.citire(input);
    return input;
}

ostream& operator<<(ostream& output, Destinatie& r) {
    r.afisare(output);
    return output;
}


int Destinatie::get_pret_per_zi() const {
    return pret_per_zi;
}

////////////////////////////////////////////


class Excursie_la_Munte : public Destinatie {
private:
    string nume_monitor_ski;
    const static int pret_strandard_zi = 387;
    const static int pret_echipament_ski_zi = 59;
public:
    Excursie_la_Munte();

    Excursie_la_Munte(string new_nume_monitor_ski);

    Excursie_la_Munte(string new_nume_monitor_ski, string new_nume_destinatie);

    Excursie_la_Munte(const Excursie_la_Munte& em);

    Excursie_la_Munte& operator=(const Excursie_la_Munte& em);

    ~Excursie_la_Munte();

    void citire(istream& input);

    void afisare(ostream& output);

    friend istream& operator>>(istream& input, Excursie_la_Munte& r);

    friend ostream& operator<<(ostream& output, Excursie_la_Munte& r);

};

Excursie_la_Munte::Excursie_la_Munte() : Destinatie() {
    nume_monitor_ski = "";
    pret_per_zi = pret_echipament_ski_zi + pret_strandard_zi;
}

Excursie_la_Munte::Excursie_la_Munte(string new_nume_monitor_ski) : nume_monitor_ski(new_nume_monitor_ski),
                                                                    Destinatie() {
    pret_per_zi = pret_echipament_ski_zi + pret_strandard_zi;
}

Excursie_la_Munte::Excursie_la_Munte(string new_nume_monitor_ski, string new_nume_destinatie) : Destinatie(
        new_nume_destinatie) {
    this->nume_monitor_ski = new_nume_monitor_ski;
    pret_per_zi = pret_echipament_ski_zi + pret_strandard_zi;
}


Excursie_la_Munte::Excursie_la_Munte(const Excursie_la_Munte& em) : Destinatie(em) {

    nume_monitor_ski.clear();
    this->nume_monitor_ski = em.nume_monitor_ski;

}

Excursie_la_Munte& Excursie_la_Munte::operator=(const Excursie_la_Munte& em) {
    if (this != &em) {
        this->pret_per_zi = em.pret_per_zi;
        nume_destinatie.clear();
        this->nume_destinatie = em.nume_destinatie;
        nume_monitor_ski.clear();
        this->nume_monitor_ski = em.nume_monitor_ski;
        return *this;
    }
}

Excursie_la_Munte::~Excursie_la_Munte() {
    nume_monitor_ski.clear();
}

void Excursie_la_Munte::citire(istream& input) {
    Destinatie::citire(input);
    cout << "Numele monitorului de ski este: ";
    string s;
    cin >> s;
    valid_string(s);
    nume_monitor_ski = s;
    s.erase();
    cout << endl;

}

void Excursie_la_Munte::afisare(ostream& output) {
    Destinatie::afisare(output);
    cout << "Numele monitorului de ski este: ";
    output << nume_monitor_ski;
    cout << endl;
}

istream& operator>>(istream& input, Excursie_la_Munte& r) {
    r.citire(input);
    return input;
}

ostream& operator<<(ostream& output, Excursie_la_Munte& r) {
    r.afisare(output);
    return output;
}


////////////////////////////////////
class Excursie_la_Mare : public Destinatie {
private:
    const static int pret_strandard_zi = 297;
    const static int pret_taxa_sezlong = 25;
public:
    Excursie_la_Mare();

    Excursie_la_Mare(string new_nume_monitor_ski);

    Excursie_la_Mare(const Excursie_la_Mare& em);

    Excursie_la_Mare& operator=(const Excursie_la_Mare& em);

    ~Excursie_la_Mare();

    void citire(istream& input);

    void afisare(ostream& output);

    friend istream& operator>>(istream& input, Excursie_la_Mare& r);

    friend ostream& operator<<(ostream& output, Excursie_la_Mare& r);

};

Excursie_la_Mare::Excursie_la_Mare() : Destinatie() {
    pret_per_zi = pret_taxa_sezlong + pret_strandard_zi;
}

Excursie_la_Mare::Excursie_la_Mare(string new_nume_destinatie) : Destinatie(
        new_nume_destinatie) {
    pret_per_zi = pret_taxa_sezlong + pret_strandard_zi;
}


Excursie_la_Mare::Excursie_la_Mare(const Excursie_la_Mare& em) : Destinatie(em) {
    this->pret_per_zi = em.pret_per_zi;
    nume_destinatie.clear();
    this->nume_destinatie = em.nume_destinatie;
}

Excursie_la_Mare& Excursie_la_Mare::operator=(const Excursie_la_Mare& em) {
    if (this != &em) {
        this->pret_per_zi = em.pret_per_zi;
        nume_destinatie.clear();
        this->nume_destinatie = em.nume_destinatie;
        return *this;
    }
}

Excursie_la_Mare::~Excursie_la_Mare() {
}

void Excursie_la_Mare::citire(istream& input) {
    Destinatie::citire(input);
}

void Excursie_la_Mare::afisare(ostream& output) {
    Destinatie::afisare(output);
}

istream& operator>>(istream& input, Excursie_la_Mare& r) {
    r.citire(input);
    return input;
}

ostream& operator<<(ostream& output, Excursie_la_Mare& r) {
    r.afisare(output);
    return output;
}


////////////////////////////////////

class City_break : public Destinatie {
private:
    static map<string, int> muzee;
    int nr_muzee;
    vector<string> muzee_de_vizitat;
    int pret_bilete;
public:
    City_break();

    City_break(string new_nume_destinatie, int new_numar_muzee);

    City_break(const City_break& c);

    City_break& operator=(const City_break& c);

    ~City_break();

    void citire(istream& input);

    void afisare(ostream& output);

    friend istream& operator>>(istream& input, City_break& c);

    friend ostream& operator<<(ostream& output, City_break& c);

    void set_muzee_de_vizitat();

    static void set_muzee();

    static void print_muzee();

    int get_pret_bilete() const;
};

map<string, int> City_break::muzee = map<string, int>();                //init map muzee


City_break::City_break() : Destinatie() {
    pret_per_zi = 300;
}

City_break::City_break(string new_nume_destinatie, int new_numar_muzee) : Destinatie(new_nume_destinatie) {
    nr_muzee = new_numar_muzee;
    pret_bilete = -1;
    pret_per_zi = 300;
    try {
        if (muzee.size() < 2)
            throw 1;                                //daca muzeele inca nu fusesera initializate, le init aici
    }
    catch (int e) {
        if (e == 1) {
            set_muzee();
        }
    }
    City_break::print_muzee();
    set_muzee_de_vizitat();
}

City_break::City_break(const City_break& c) : Destinatie(c) {
    nr_muzee = c.nr_muzee;
    pret_bilete = c.pret_bilete;
}

City_break& City_break::operator=(const City_break& c) {
    if (this != &c) {
        this->pret_per_zi = c.pret_per_zi;
        nume_destinatie.clear();
        this->nume_destinatie = c.nume_destinatie;
        this->nr_muzee = c.nr_muzee;
        pret_bilete = c.pret_bilete;
        return *this;
    }
}

City_break::~City_break() {
}

void City_break::citire(istream& input) {
    Destinatie::citire(input);
    cout << "Spuneti numarul de muzee la care vreti sa mergeti: ";
    try {
        cin >> nr_muzee;
        if (nr_muzee < 0)
            throw "Numarul muzeelor viztate trebuie sa fie >0";
    }
    catch (const exception& e) {
        cout << "Eroare! " << e.what();
        exit(EXIT_FAILURE);
    }
    cout << endl;
    try {
        if (muzee.size() < 2)
            throw 1;                                //daca muzeele inca nu fusesera initializate, le init aici
    }
    catch (int e) {
        if (e == 1) {
            set_muzee();
        }
    }
    City_break::print_muzee();
    set_muzee_de_vizitat();
}

void City_break::afisare(ostream& output) {
    Destinatie::afisare(output);
    cout << "Numarul de muzee la care mergeti este de: ";
    cout << nr_muzee;
    cout << endl;
    cout << "Muzeele pe care le veti vizita sunt:\n ";
    for (auto j = muzee_de_vizitat.begin(); j != muzee_de_vizitat.end(); j++) {
        cout << *j << endl;
    }
    cout << "Pretul total al biletelor este de: ";
    cout << pret_bilete;
    cout << endl;
}

istream& operator>>(istream& input, City_break& c) {
    c.citire(input);
    return input;
}

ostream& operator<<(ostream& output, City_break& c) {
    c.afisare(output);
    return output;
}

void City_break::set_muzee() {
    muzee.insert(pair<string, int>("Louvre", 200));
    muzee.insert(pair<string, int>("British_Museum", 189));
    muzee.insert(pair<string, int>("Metropolitan_Museum_of_Art", 176));
    muzee.insert(pair<string, int>("National_Gallery", 247));
    muzee.insert(pair<string, int>("Tate_Modern", 321));
    muzee.insert(pair<string, int>("National_Gallery_of_Art", 134));
    muzee.insert(pair<string, int>("Centre_Georges_Pompidou", 452));
    muzee.insert(pair<string, int>("Musée_d'Orsay", 221));
    muzee.insert(pair<string, int>("Museo_del_Prado", 145));
    muzee.insert(pair<string, int>("Muzeul_Ermitaj", 235));
    muzee.insert(pair<string, int>("Victoria_and_Albert_Museum", 172));
    muzee.insert(pair<string, int>("Art_Institute_of_Chicago", 185));
}


void City_break::set_muzee_de_vizitat() {
    cout << nr_muzee;
    muzee_de_vizitat.reserve(nr_muzee + 1);
    cout << "You can write the number of the museum or write the exact name of the museum" << endl;
    int pret_muzee = 0;
    string muzeu;
    cout << "Primul muzeu pe care vreti sa-l vizitati este: ";
    try {
        cin >> muzeu;
        throw string_is_alphas(muzeu);
    }
    catch (bool e) {
        if (e) {
            muzee_de_vizitat.push_back(muzeu);                  //s-a scris numele
            pret_muzee += muzee.find(muzeu)->second;            //adauga pretul biletului la muzeu
        }
        if (!e) {                         //s-a scris pozitia in map
            int num;                ///stringul e ca si int
            stringstream ss;
            ss << muzeu;
            ss >> num;
            int k = 1;
            auto j = muzee.begin();
            for (j = muzee.begin(); k < num; j++) {
                k++;
            }
            muzee_de_vizitat.push_back(j->first);
            pret_muzee += j->second;
        }
    }

    muzeu.clear();

    for (int i = 1; i < nr_muzee; i++) {
        cout << "Urmatorul muzeu la care vreti sa mergeti este: ";
        try {
            cin >> muzeu;
            throw string_is_alphas(muzeu);
        }
        catch (bool e) {
            if (e) {
                muzee_de_vizitat.push_back(muzeu);                  //s-a scris numele
                pret_muzee += muzee.find(muzeu)->second;            //adauga pretul biletului la muzeu
            }
            if (!e) {                         //s-a scris pozitia in map
                int num;                ///stringul e ca si int
                stringstream ss;
                ss << muzeu;
                ss >> num;
                int k = 1;
                auto j = muzee.begin();
                for (j = muzee.begin(); k < num; j++) {
                    k++;
                }
                muzee_de_vizitat.push_back(j->first);
                pret_muzee += j->second;
            }
        }
        muzeu.clear();
    }
    pret_bilete = pret_muzee;
}

void City_break::print_muzee() {
    int i = 1;
    for (map<string, int>::iterator it = muzee.begin(); it != muzee.end(); it++) {
        cout << i << ") " << it->first << " " << it->second << endl;
        i++;
    }
}

int City_break::get_pret_bilete() const {
    return pret_bilete;
}

class Factory {
public:
    virtual Destinatie* create_destinatie() { return nullptr; };
    //virtual void create_rezervare();
};


class Create_destinatie : public Factory {
    Destinatie* create_destinatie();
};
////////////////////////////////////

class Rezervare {
private:
    int nr_zile;
    int pret_final;
    Destinatie* destinatie;
public:
    Rezervare();

    Rezervare(int new_nr_zile);

    Rezervare(int new_nr_zile, Destinatie* new_destinatie);

    Rezervare(const Rezervare& r);

    Rezervare& operator=(const Rezervare& r);

    virtual ~Rezervare();

    virtual void citire(istream& input);

    virtual void afisare(ostream& output);

    friend istream& operator>>(istream& input, Rezervare& r);

    friend ostream& operator<<(ostream& output, Rezervare& r);

    void set_destinatie();

    void calculare_pret_final();

    const int get_pret_final();


};


Rezervare::Rezervare() {
    nr_zile = -1;
    destinatie = nullptr;
    pret_final = -1;
}

Rezervare::Rezervare(int new_nr_zile) : nr_zile(-1) {
    nr_zile = new_nr_zile;
    set_destinatie();
    calculare_pret_final();
}

Rezervare::Rezervare(int new_nr_zile, Destinatie* new_destinatie) : nr_zile(-1), destinatie(nullptr) {
    nr_zile = new_nr_zile;
    destinatie = new_destinatie;
    calculare_pret_final();
}

Rezervare::Rezervare(const Rezervare& r) {
    this->nr_zile = r.nr_zile;
    this->pret_final = r.pret_final;
    this->destinatie = r.destinatie;

}

Rezervare& Rezervare::operator=(const Rezervare& r) {
    if (this != &r) {
        this->nr_zile = r.nr_zile;
        this->pret_final = r.pret_final;
        this->destinatie = r.destinatie;
        return *this;
    }
}

Rezervare::~Rezervare() {
    nr_zile = -1;
    pret_final = -1;
}

void Rezervare::citire(istream& input) {
    cout << "Introduceti numarul de zile al sejurului: ";
    try {
        cin >> nr_zile;
        if (nr_zile < 0)
            throw "Numarul zilelor viztate trebuie sa fie >0";
    }
    catch (const exception& e) {
        cout << "Eroare! " << e.what();
        exit(EXIT_FAILURE);
    }
    set_destinatie();
    calculare_pret_final();
    cout << endl;
}

void Rezervare::afisare(ostream& output) {
    cout << "Numarul de zile al sejurului dumneavoastra este: ";
    cout << nr_zile;
    cout << endl;
    cout << "Informatii despre destinatie:\n----\n ";
    cout << *destinatie;
    cout << "----\n";
    cout << "Pretul final al sejurului dumneavoastra este: ";
    cout << pret_final;
    cout << endl;

}

istream& operator>>(istream& input, Rezervare& r) {
    r.citire(input);
}

ostream& operator<<(ostream& output, Rezervare& r) {
    r.afisare(output);
}


void Rezervare::set_destinatie() {
    Factory* factory = new Create_destinatie();
    destinatie = factory->create_destinatie();
    cin >> *destinatie;
}

void Rezervare::calculare_pret_final() {
    pret_final = destinatie->get_pret_per_zi() * nr_zile;
    if (dynamic_cast<City_break*>(destinatie)) {
        auto* c = dynamic_cast<City_break*>(destinatie);                   //downcast
        pret_final += c->get_pret_bilete();
    }
}

const int Rezervare::get_pret_final() {
    return pret_final;
}
////////////////////////////////////////////////////

template<typename T>
class BookingVacante {
private:
    static int nr;
    static unordered_map<int, T> vector;
    Rezervare rezervare;
public:
    BookingVacante() {
    };

    BookingVacante(const BookingVacante& r) {
        rezervare = r.rezervare;
    };

    BookingVacante& operator=(const BookingVacante& r) {
        if (this != &r) {
            rezervare = r.rezervare;
            return *this;
        }
    };

    ~BookingVacante() {
    };

    void citire(istream& input) {
        cin >> rezervare;
    };

    void afisare(ostream& output) {
        cout << rezervare;
    };

    friend istream& operator>>(istream& input, BookingVacante& r) {
        r.citire(input);
    };

    friend ostream& operator<<(ostream& output, BookingVacante& r) {
        r.afisare(output);
    };

    BookingVacante<T>& operator+=(const BookingVacante& r) {
        vector.insert({ r.nr, r.rezervare });
        nr++;
        return *this;
    };

    void print_vector() {
        for (auto i = vector.begin(); i != vector.end(); i++) {
            cout << i->first << ")\n" << i->second << endl;
        }
    };

    bool delete_element_in_vector(int nr_rez) {
        for (auto i = vector.begin(); i != vector.end(); i++) {
            if (i->first == nr_rez) {
                vector.erase(i);
                return true;
            }
        }
        return false;
    }

};

//initializam atributele statice in afara clasei. In versiuni mai noi de c++ se putea face si in clasa prin "inline"
template<typename T>
unordered_map<int, T>  BookingVacante<T>::vector = unordered_map<int, T>();
template<typename T>
int BookingVacante<T>::nr = 0;


template<>
class BookingVacante<Excursie_la_Mare> {
    static int nr1;
    static unordered_map<int, Rezervare> vector1;
    Rezervare rezervare;
public:
    BookingVacante() {};

    BookingVacante(const BookingVacante& r) {
        rezervare = r.rezervare;
    };

    BookingVacante& operator=(const BookingVacante& r) {
        if (this != &r) {
            rezervare = r.rezervare;
            return *this;
        }
    };

    ~BookingVacante() {
    };

    void citire(istream& input) {
        int nr_zile = 0;
        Destinatie* d = new Excursie_la_Mare;
        cout << "Numarul de zile al sejurului este de: ";
        try {
            cin >> nr_zile;
            if (nr_zile < 0)
                throw "Numarul zilelor viztate trebuie sa fie >0";
        }
        catch (const exception& e) {
            cout << "Eroare! " << e.what();
            exit(EXIT_FAILURE);
        }
        cin >> *d;
        rezervare = Rezervare(nr_zile, d);
    };

    void afisare(ostream& output) {
        cout << rezervare;
    };

    friend istream& operator>>(istream& input, BookingVacante& r) {
        r.citire(input);
    };

    friend ostream& operator<<(ostream& output, BookingVacante& r) {
        r.afisare(output);
    };

    BookingVacante<Excursie_la_Mare>& operator+=(const BookingVacante& r) {
        vector1.insert({ r.nr1, r.rezervare });
        nr1++;
        return *this;
    };

    static void print_vector() {
        for (auto i = vector1.begin(); i != vector1.end(); i++) {
            cout << i->first << ")\n" << i->second << endl;
        }
    };

    int pret_totat_excursii_mare() {
        int pret = 0;
        for (auto i = vector1.begin(); i != vector1.end(); i++) {
            pret += i->second.get_pret_final();
        }
        return pret;
    }

    bool delete_element_in_vector(int nr_rez) {
        for (auto i = vector1.begin(); i != vector1.end(); i++) {
            if (i->first == nr_rez) {
                vector1.erase(i);
                return true;
            }
        }
        return false;
    }
};

unordered_map<int, Rezervare>  BookingVacante<Excursie_la_Mare>::vector1 = unordered_map<int, Rezervare>();
int BookingVacante<Excursie_la_Mare>::nr1 = 0;


Destinatie* Create_destinatie::create_destinatie() {
    int tip_destinatie;
    cout << "1 = Excursie la Munte\n 2 = Excursie la Mare\n 3 = City Break\n";
    cin >> tip_destinatie;
    try {
        if (tip_destinatie != 1 && tip_destinatie != 2 && tip_destinatie != 3)
            throw 1;
    }
    catch (int i) {
        if (i == 1) {
            cout << "Tipul destinatiei trebuie sa fie un intreg intre 1 si 3\n";
            exit(EXIT_FAILURE);
        }
    }
    if (tip_destinatie == 1) {
        return new Excursie_la_Munte;                             //upcast
    }
    if (tip_destinatie == 2) {
        return new Excursie_la_Mare;
    }
    if (tip_destinatie == 3) {
        return new City_break;
    }
}

class VMMenu {                                                        ///clasa singleton
private:
    BookingVacante<Rezervare>* vectorR = new BookingVacante<Rezervare>();
    BookingVacante<Excursie_la_Mare>* vectorM = new BookingVacante<Excursie_la_Mare>();
    static VMMenu* instance;
    vector<pair<string, function<void()>>> functii;                     ///vector de functii lambda

    VMMenu();

    VMMenu(const VMMenu&) = delete;

    VMMenu& operator=(const VMMenu&) = delete;

public:
    static VMMenu* get_instance();

    static void delete_instance();

    void program();


};


VMMenu::VMMenu() {
    functii.push_back(make_pair("Adauga rezervare\n", [&]() {
        BookingVacante<Rezervare> r1;
        cin >> r1;
        *vectorR += r1;
        cout << " --- Rezervarea a fost adaugata ---\n";
    }));
    functii.push_back(make_pair("Printeaza toate rezervarile\n", [&]() {
        vectorR->print_vector();
        cout << "\n";
    }));
    functii.push_back(make_pair("Sterge rezervare\n", [&]() {
        int nr_rez;
        cout << "Spuneti care este numarul rezervarii pe care doriti sa o stergeti din vector: ";
        cin >> nr_rez;
        try {
            bool e1 = vectorR->delete_element_in_vector(nr_rez);
            if (e1 == false)
                throw 1;
        }
        catch (int e) {
            if (e == 1) {
                cout << "Acest element nu exista in vector\n";
            }
        }

    }));
    functii.push_back(make_pair("Adauga rezervare specializata la mare \n", [&]() {
        BookingVacante<Excursie_la_Mare> r1;
        cin >> r1;
        *vectorM += r1;
        cout << " --- Rezervarea specializata a fost adaugata ---\n";
    }));
    functii.push_back(make_pair("Printeaza toate rezervarile specializate la mare \n", [&]() {
        vectorM->print_vector();
        cout << "\n";
    }));
    functii.push_back(make_pair("Calculeaza pretul total al excursiilor la mare specializate\n", [&]() {
        cout << vectorM->pret_totat_excursii_mare() << " de lei\n";
    }));
    functii.push_back(make_pair("Sterge rezervare specializata la mare \n", [&]() {
        int nr_rez;
        cout << "Spuneti care este numarul rezervarii pe care doriti sa o stergeti din vector: ";
        cin >> nr_rez;
        try {
            bool e1 = vectorM->delete_element_in_vector(nr_rez);
            if (e1 == false)
                throw 1;
        }
        catch (int e) {
            if (e == 1) {
                cout << "Acest element nu exista in vector\n";
            }
        }
    }));
}


VMMenu* VMMenu::get_instance() {
    if (instance == nullptr)
        instance = new VMMenu();
    return instance;
}

VMMenu* VMMenu::instance = nullptr;

void VMMenu::delete_instance() {
    delete instance;
    instance = nullptr;
}

void VMMenu::program() {


    bool is_running = true;
    while (is_running == true) {
        try {
            int fct;
            for (int i = 0; i < functii.size(); i++)
                cout << i << ") " << functii[i].first << endl;
            cout << functii.size() << ") Close" << endl;

            cout << "Alege operatiunea pe care vrei sa o faca programul: " << endl;
            cin >> fct;
            if (fct < 0 || fct > functii.size())
                throw runtime_error("Operatiunea ceruta nu este valida");

            if (fct == functii.size()) {
                is_running = false;
                continue;
            }
            functii[fct].second();
        }
        catch (const exception& e) {
            cout << "Eroare: " << e.what() << endl;
        }
    }
}


int main() {
    VMMenu::get_instance()->program();
    VMMenu::delete_instance();

    return 0;
}