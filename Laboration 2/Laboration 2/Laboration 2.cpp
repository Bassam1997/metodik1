// Laboration 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//abstract bas klass
class Shape {

    string Nshape; //behåller namn på mina olika shapes
    string colour;
    
public:
    Shape(string _s, string _f) { // konstruktor
        Nshape = _s; // initierar stringen
       colour = _f;

    } 
    void setNshape(string _s) {
            Nshape = _s; //uppdaterar variabel namnet

        }
    string getNshape() const { //används i vår getmethod
        return Nshape; // returnerar stringen 
    }  
    virtual double getArea() const = 0; //virtuell funktion
    string getColour()
    {
        return colour;
    }

};

class Circle : public Shape // ärver från klass shape utan att innehållet ändras. Subklass, kan ej få direkt åtkomst till privat i superklass. 
{
    double radie;

    public:
    Circle(string _s, double _r, string _f) :Shape(_s, _f) //Denna konstruktor skickar argument till Shape klassens konstruktor.
    {
        radie = _r;
    }
    void setRadie(double _r) 
    {
        radie = _r;
    }
    double getRadie() const 
    {
        return radie;
    }
    double getArea() const
    {
        return radie * radie * 3.14159;
    }
};



class Rektangel : public Shape
{
    double langd, bredd;


public:
    Rektangel(string _s, double _l, double _b, string _f) : Shape(_s, _f)
    {
        langd = _l;
        bredd = _b;
    }
    void setLangd(double _l)
    {
        langd = _l;
    }
    void setBredd(double _b)
    {
        bredd = _b;
    }
    double getLangd() const
    {
        return langd;
    }
    double getBredd() const
    {
        return bredd;
    }
    double getArea() const
    {
        return langd * bredd;
    }
};

class Rounded : public Rektangel
{
  Circle c;
public: 
    Rounded(string _s, double _l, double _b, string _f): Rektangel(_s,_l, _b,_f)
    {
        
    }

    double getArea() const
    {
        return getLangd() * getBredd();
    }

};

class paralell : public Rektangel
{
    double djup;

    public:

    paralell(string _s, double _l, double _b, double _d, string _f) : Rektangel(_s, _l, _b, _f)
    {
        djup = _d;
    }
    double getArea() const
    {
        return 2 * (getBredd() * getLangd() + getBredd() * djup + getLangd()* djup);
    }
    
};

int main()
{
    //Shape test("Shape");  // skapar instans av klassen shape     
    
    
    //std::cout << test.getNshape() << endl;
    
    Circle c("Circle", 3.14, " lightblue");
    cout << c.getNshape() <<", Radie: " << c.getRadie()<< ", "<< c.getArea()<< c.getColour() << endl; // eftersom Circle ärver från Shape så slipper vi skapa en ny method.
    
    Rektangel r("Rektangel", 8, 4, "purple");
    cout << r.getNshape() << ", " << r.getLangd() << " , " << r.getBredd()<< ", "<< r.getArea() << endl; 

    paralell p("Paralell", 5, 4, 8, "grey");
    cout << p.getNshape() << ", " << p.getArea() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
