//
// Created by stas on 5.11.19.
//

#include <iostream>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        numerator = new_numerator;
        denominator = new_denominator;

        Cut();
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    bool operator==(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    Rational operator+(const Rational& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Rational(new_num, new_den);
    }

    Rational operator-(const Rational& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Rational(new_num, new_den);
    }

    Rational operator*(const Rational& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Rational(new_num, new_den);
    }

    Rational operator/(const Rational& other) const {
        int new_num = numerator * other.denominator;
        int new_den = denominator * other.numerator;
        return Rational(new_num, new_den);
    }

    bool operator<(const Rational& other) const {
        return ((*this) - other).numerator < 0;
    }

    bool operator>(const Rational& other) const {
        return ((*this) - other).numerator > 0;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Rational& rational);
    friend std::istream& operator>>(std::istream& stream, Rational& rational);

private:

    void Cut(){
        if(denominator < 0){
            denominator *= -1;
            numerator *= -1;
        }else if(numerator == 0){
            denominator = 1;
        }

        int d = HOD(std::abs(numerator), denominator);
        numerator /= d;
        denominator /= d;
    }

    int HOD(int a, int b){
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }
        return a + b;
    }

    int numerator;
    int denominator;
};

std::ostream& operator<<(std::ostream& stream, const Rational& rational){
    stream << rational.numerator << '/' << rational.denominator;
    return stream;
}

std::istream& operator>>(std::istream& stream, Rational& rational){
    stream >> rational.numerator;
    stream.ignore(1);
    stream >> rational.denominator;
    rational.Cut();
    return stream;
}

int main(){
    std::cout << Rational(1,2) + Rational(1, 3);
    return 0;
}
