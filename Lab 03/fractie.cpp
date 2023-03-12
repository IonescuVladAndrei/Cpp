#include "fractie.hpp"

Fractie::Fractie(int aa,int bb)
{
    a=aa;
    b=bb;
}

Fractie::Fractie(const Fractie &obj)
{
    this->a = obj.a;
    this->b = obj.b;
}

Fractie &Fractie::operator=(const Fractie &obj)
{
    this->a = obj.a;
    this->b = obj.b;
    if (this->b == 0)
        std::cout << "Atentie la numitor: 0!" << std::endl;
    return (*this);
}

Fractie::~Fractie() {}

double Fractie::getValoare()
{
    double rez = 0;
    if (this->b == 0)
        std::cout << "getValoare(): Atentie la numitor: 0!" << std::endl;
    else
        rez = (double)a / b;
    return rez;
}

Fractie Fractie::getInv()
{
    int temp = this->a;
    this->a = this->b;
    this->b = temp;
    return (*this);
}

void Fractie::setdata(int a1, int b1)
{
    this->a=a1;
    this->b=b1;
}

int Fractie::getA()
{
    return this->a;
}

int Fractie::getB()
{
    return this->b;
}

Fractie operator+(const Fractie &obj1, const Fractie &obj2)
{
    Fractie aux(obj1);
    aux.a = obj1.a * obj2.b + obj2.a*obj1.b;
    aux.b = obj1.b*obj2.b;
    return aux;
}

Fractie operator-(const Fractie &obj1, const Fractie &obj2)
{
    Fractie aux(obj1);
    aux.a = obj1.a * obj2.b - obj2.a*obj1.b;
    aux.b = obj1.b*obj2.b;
    return aux;
}

Fractie operator*(const Fractie &obj1, const Fractie &obj2)
{
    Fractie aux(obj1);
    aux.a = obj1.a *obj2.a;
    aux.b = obj1.b*obj2.b;
    return aux;
}

Fractie operator/(const Fractie &obj1, const Fractie &obj2)
{
    Fractie aux(obj1);
    aux.a = obj1.a * obj2.b;
    aux.b = obj1.b*obj2.a;
    return aux;
}

Fractie operator-(const Fractie &obj1)
{
    Fractie aux(obj1);
    aux.a = -aux.a;
    return aux;
}

Fractie &Fractie::operator+=(const Fractie &obj)
{
    this->a = this->a * obj.b + obj.a*this->b;
    this->b = this->b*obj.b;
    return (*this);
}

Fractie &Fractie::operator-=(const Fractie &obj)
{
    this->a = this->a * obj.b - obj.a*this->b;
    this->b = this->b*obj.b;
    return (*this);
}

Fractie &Fractie::operator*=(const Fractie &obj)
{
    this->a = this->a * obj.a;
    this->b = this->b*obj.b;
    return (*this);
}

Fractie &Fractie::operator/=(const Fractie &obj)
{
    this->a = this->a * obj.b;
    this->b = this->b*obj.a;
    return (*this);
}

bool Fractie::operator==(const Fractie &obj)
{
    if((double)this->a/this->b == (double)obj.a/obj.b)
        return 1;
    return 0;
}

bool Fractie::operator!=(const Fractie &obj)
{
    return !((*this)==obj);
}

bool Fractie::operator<(const Fractie &obj)
{
    if(this->a * obj.b < this->b * obj.a)
        return 1;
    return 0;
}

bool Fractie::operator>(const Fractie &obj)
{
    if(this->a * obj.b > this->b * obj.a)
        return 1;
    return 0;
}

bool Fractie::operator<=(const Fractie &obj)
{
    if(this->a * obj.b <= this->b * obj.a)
        return 1;
    return 0;
}

bool Fractie::operator>=(const Fractie &obj)
{
    if(this->a * obj.b >= this->b * obj.a)
        return 1;
    return 0;
}