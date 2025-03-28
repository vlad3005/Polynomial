#include <iostream>




// Класс для представления многочлена
#include "Polynomial.h"

int main() {
    Polynomial poly1;
    poly1.addTerm(2, 4);
    poly1.addTerm(1, 2);
    poly1.addTerm(2, 0);

    Polynomial poly2;
    poly2.addTerm(1, 2);
    poly2.addTerm(2, 0);

    Polynomial sum = poly1 + poly2;
    Polynomial diff = poly1 - poly2;
    Polynomial prod = poly1 * poly2;
    Polynomial quot = poly1 / poly2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Product: " << prod << std::endl;
    std::cout << "Quotient: " << quot << std::endl;
    return 0;
}

