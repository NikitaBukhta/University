#include "Fraction.hpp"

#include <iostream>
#include <sstream>
#include <array>

namespace lab_4 {

Fraction::Fraction(int numerator, int decominator):
    m_numerator(numerator), m_denominator(decominator)
{
    // Ми помістили метод reduce() в конструктор, щоб переконатися, що всі дробі, які у нас є, будут зменшені.
    // всі дробі, які будут перезаписані, повинні бути повторно зменшенні
    reduce();
}

Fraction operator* (const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator* (const Fraction &f1, int value)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator* (int value, const Fraction &f1)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

std::istream& operator>> (std::istream & in, Fraction &f1) {
    std::string segment;
    std::string input;
    in >> input;
    std::stringstream ss(input);
    std::array<int*, 2> metadata = {&f1.m_numerator, &f1.m_denominator};
    int counter{0};
    while (std::getline(ss, segment, '/') && counter != metadata.size()) {
        *metadata[counter++] = std::stoi(segment);
    }

    return in;
}

std::ostream& operator<< (std::ostream & out, const Fraction &f1) {
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

int Fraction::nod(int a, int b)
{
    return b == 0 ? a : nod(b, a % b);
}

void Fraction::reduce()
{
    int nod = Fraction::nod(m_numerator, m_denominator);
    m_numerator /= nod;
    m_denominator /= nod;
}

void Fraction::print()
{
    std::cout << m_numerator << "/" << m_denominator << "\n";
}

}   // lab_4;