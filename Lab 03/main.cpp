#include "fractie.cpp"

int main()
{
    /* int a = 563, b = 87;
    double rez = (double)a/b;
    std::cout << "rez = " << rez; */

    Fractie f1(63, 5), f2(68, 7);
    std::cout << "f1: a = " << f1.getA() << " b = " << f1.getB() << std::endl;
    std::cout << "f2: a = " << f2.getA() << " b = " << f2.getB() << std::endl;
    std::cout << "f1 = " << f1.getValoare() << std::endl;
    f1.getInv();
    std::cout << "1/f1: a = " << f1.getA() << " b = " << f1.getB() << std::endl;
    f1.getInv();
    Fractie f3(f1 + f2);
    std::cout << "f1 + f2: a = " << f3.getA() << " b = " << f3.getB() << std::endl;
    Fractie f8(f1 += f2);
    std::cout << "f1 += f2: a = " << f8.getA() << " b = " << f8.getB() << std::endl;
    Fractie f4(f1 - f2);
    std::cout << "f1 - f2: a = " << f4.getA() << " b = " << f4.getB() << std::endl;
    Fractie f9(f1 -= f2);
    std::cout << "f1 -= f2: a = " << f9.getA() << " b = " << f9.getB() << std::endl;
    Fractie f5(f1 * f2);
    std::cout << "f1 * f2: a = " << f5.getA() << " b = " << f5.getB() << std::endl;
    Fractie f10(f1 *= f2);
    std::cout << "f1 *= f2: a = " << f10.getA() << " b = " << f10.getB() << std::endl;
    Fractie f6(f1 / f2);
    std::cout << "f1 / f2: a = " << f6.getA() << " b = " << f6.getB() << std::endl;
    Fractie f11(f1 /= f2);
    std::cout << "f1 /= f2: a = " << f11.getA() << " b = " << f11.getB() << std::endl;
    Fractie f7(-f1);
    std::cout << "-f1: a = " << f7.getA() << " b = " << f7.getB() << std::endl;
    
    if(f1 > f2)
        std::cout << "f1 > f2 ?\tA" << std::endl;
    else 
        std::cout << "f1 > f2 ?\tF" << std::endl;
    if(f1 >= f2)
        std::cout << "f1 >= f2 ?\tA" << std::endl;
    else 
        std::cout << "f1 >= f2 ?\tF" << std::endl;
    if(f1 < f2)
        std::cout << "f1 < f2 ?\tA" << std::endl;
    else 
        std::cout << "f1 < f2 ?\tF" << std::endl;
    if(f1 <= f2)
        std::cout << "f1 <= f2 ?\tA" << std::endl;
    else 
        std::cout << "f1 <= f2 ?\tF" << std::endl;
    if(f1 == f2)
        std::cout << "f1 == f2 ?\tA" << std::endl;
    else 
        std::cout << "f1 == f2 ?\tF" << std::endl;
    if(f1 != f2)
        std::cout << "f1 != f2 ?\tA" << std::endl;
    else 
        std::cout << "f1 != f2 ?\tF" << std::endl; 
}