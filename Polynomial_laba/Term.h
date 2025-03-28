#include <iostream>
class Term {
public:
    int coefficient; 
    int exponent;    


    Term() : coefficient(0), exponent(0) {};
    Term(int coef, int exp) : coefficient(coef), exponent(exp) {}

    Term operator+(const Term& other) const {
        if (exponent != other.exponent) throw std::invalid_argument("Exponents must be the same for addition");
        return Term(coefficient + other.coefficient, exponent);
    }

    Term operator-(const Term& other) const {
        if (exponent != other.exponent) throw std::invalid_argument("Exponents must be the same for subtraction");
        return Term(coefficient - other.coefficient, exponent);
    }

    Term operator*(const Term& other) const {
        return Term(coefficient * other.coefficient, exponent + other.exponent);
    }

    Term operator/(const Term& other) const {
        if (other.coefficient == 0) throw std::invalid_argument("Division by zero");
        if (exponent < other.exponent) throw std::invalid_argument("Exponent of dividend must be greater or equal to divisor");
        return Term(coefficient / other.coefficient, exponent - other.exponent);
    }

    friend std::istream& operator>>(std::istream& istr, Term& term) {
    	int coefficient, exponent;
        std::cout << "Введите коеф:" << std::endl;
        istr >> coefficient;
        std::cout << "Введите степень:" << std::endl;
        istr >> exponent;
    	term = Term(coefficient, exponent);
    	return istr;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Term& term) {
    	if (term.coefficient == 0) {
    		return os << "0";
    	}
        else {
    		os << term.coefficient << " * " << "x^" << term.exponent;
    	}
    }
};