#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom) {
        if (typeid(num) != typeid(int) || typeid(denom) != typeid(int)) {
            std::cout << "Error: Numerator and denominator must be integers.\n";
            exit(1);
        }
        if (denom == 0) {
            std::cout << "Error: Denominator cannot be zero.\n";
            exit(1);
        }
        numerator = num;
        denominator = denom;
    }

    void reduce() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int findGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return findGCD(b, a % b);
    }

    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_denom = denominator * other.denominator;
        Fraction result(new_num, new_denom);
        result.reduce();
        return result;
    }

    std::string str() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    std::string repr() const {
        return "Fraction(" + std::to_string(numerator) + ", " + std::to_string(denominator) + ")";
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1 + f2;
    std::cout << f1.str() << " + " << f2.str() << " = " << f3.str() << "\n";
    std::cout << "Repr of f3: " << f3.repr() << "\n";
    return 0;
}

