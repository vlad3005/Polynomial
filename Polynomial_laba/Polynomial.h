#include "LinkedList.h"

class Polynomial {
private:
    LinkedList terms;

public:
    Polynomial() {}

    Polynomial(const Term& term) {
        terms.addTerm(term.coefficient, term.exponent);
    }

    //void addTerm(int coefficient, int exponent) {
    //    if (coefficient == 0) return;
    //    Term term = Term(coefficient, exponent);
    //    Node* newNode = new Node(coefficient, exponent);
    //    if (!terms.head || terms.head->term.exponent < exponent) {
    //        terms.pushFront(term);
    //    }

    //    Node* current = head;
    //    Node* prev = nullptr;
    //    while (current && current->term.exponent > exponent) {
    //        prev = current;
    //        current = current->next;
    //    }

    //    if (current && current->term.exponent == exponent) {
    //        current->term.coefficient += coefficient;
    //        if (current->term.coefficient == 0) {
    //            if (prev) prev->next = current->next;
    //            else head = current->next;
    //            delete current;
    //        }
    //        delete newNode;
    //    }
    //    else {
    //        newNode->next = current;
    //        if (prev) prev->next = newNode;
    //    }
    //}

    Polynomial& operator=(const Polynomial& other) {
        if (this == &other) return *this;
        terms.clear();
        Node* current = other.terms.head;
        while (current) {
            terms.addTerm(current->term.coefficient, current->term.exponent);
            current = current->next;
        }
        return *this;
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result;
        Node* current = terms.head;
        while (current) {
            result.terms.addTerm(current->term.coefficient, current->term.exponent);
            current = current->next;
        }
        current = other.terms.head;
        while (current) {
            result.terms.addTerm(current->term.coefficient, current->term.exponent);
            current = current->next;
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result;
        Node* current = terms.head;
        while (current) {
            result.terms.addTerm(current->term.coefficient, current->term.exponent);
            current = current->next;
        }
        current = other.terms.head;
        while (current) {
            result.terms.addTerm(-current->term.coefficient, current->term.exponent);
            current = current->next;
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (Node* term1 = terms.head; term1; term1 = term1->next) {
            for (Node* term2 = other.terms.head; term2; term2 = term2->next) {
                result.terms.addTerm(term1->term.coefficient * term2->term.coefficient, term1->term.exponent + term2->term.exponent);
            }
        }
        return result;
    }

    Polynomial operator/(const Polynomial& other) const {
        Polynomial quotient, remainder(*this);
        while (remainder.terms.head && remainder.terms.head->term.exponent >= other.terms.head->term.exponent) {
            int coef = remainder.terms.head->term.coefficient / other.terms.head->term.coefficient;
            int exp = remainder.terms.head->term.exponent - other.terms.head->term.exponent;
            Polynomial term;
            term.terms.addTerm(coef, exp);
            quotient = quotient + term;
            remainder = remainder - (term * other);
        }
        
        return quotient;
    }

    void addTerm(int coefficient, int exponent) {
        terms.addTerm(coefficient, exponent);
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
        Node* current = poly.terms.head;
        bool first = true;
        while (current) {
            if (!first && current->term.coefficient > 0) {
                os << " + ";
            }
            else if (current->term.coefficient < 0) {
				os << " - ";
            }
            os <<  abs(current->term.coefficient) << "x^" << current->term.exponent;
            current = current->next;
            first = false;
        }
        return os;
    }
};