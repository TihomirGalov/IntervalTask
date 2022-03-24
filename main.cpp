#include <iostream>

class Interval {
private:
    int a;
    int b;
public:
    Interval();

    Interval(int start, int end);

    void setPoints(int start, int end);

    void setStart(int start);

    void setEnd(int end);

    int getStart() const;

    int getEnd() const;

    size_t getIntervalLength() const;

    bool isInTheInterval(const int &num) const;

    size_t getPrimeNums() const;

    size_t getPalindromes() const;

    size_t getDiffNums() const;

    size_t iterateNumbers(bool (*func)(const size_t)) const;

    bool arePowerOfTwo() const;

    Interval intersect(const Interval &interval) const;

    Interval combine(const Interval &interval) const;

    bool isSuperInterval(const Interval &interval) const;
};

Interval::Interval() : Interval(0, 0) {}

Interval::Interval(int start, int end) {
    setPoints(start, end);
}

void Interval::setPoints(int start, int end) {
    setStart(start);
    setEnd(end);
}

void Interval::setStart(int start) {
    if (start <= b)
        a = start;
    else {
        a = 0;
        b = 0;
    }
}

void Interval::setEnd(int end) {
    if (end >= a)
        b = end;
    else {
        a = 0;
        b = 0;
    }
}

int Interval::getStart() const {
    return a;
}

int Interval::getEnd() const {
    return b;
}

size_t Interval::getIntervalLength() const {
    return abs(b - a);
}

bool Interval::isInTheInterval(const int &num) const {
    return num <= b && num >= a;
}

size_t Interval::iterateNumbers(bool (*func)(size_t)) const {
    size_t counter = 0;
    for (int i = a; i <= b; i++) {
        if (func(abs(i)))
            counter++;
    }
    return counter;
}

bool isPrime(size_t x) {
    if (x == 1 || x == 0)
        return false;
    const size_t half = x / 2;
    for (size_t i = 2; i <= half; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

bool isPalindrome(size_t x) {
    size_t back_side = 0;

    while (back_side < x) {
        back_side = back_side * 10 + x % 10;
        x /= 10;
    }
    return back_side == x && x != 0;
}

bool isRepeated(size_t x) {
    if (x < 10)
        return false;

    bool digits[10]{};

    while (x != 0) {
        if (digits[x % 10])
            return false; //specialen pozdrav za mi60 bilalov
        digits[x % 10] = true;
        x /= 10;
    }
    return true;
}

size_t Interval::getPrimeNums() const {
    return iterateNumbers(isPrime);
}

size_t Interval::getPalindromes() const {
    return iterateNumbers(isPalindrome);

}

size_t Interval::getDiffNums() const {
    return iterateNumbers(isRepeated);

}

bool Interval::arePowerOfTwo() const {
    return (a > 0 && ((a & (a - 1)) == 0)) && (b > 0 && ((b & (b - 1)) == 0));
}

Interval Interval::intersect(const Interval &interval) const {
    int new_start = a;
    int new_end = b;
    if (a < interval.getStart())
        new_start = interval.getStart();
    if (b > interval.getEnd())
        new_end = interval.getEnd();
    return Interval(new_start, new_end);
}

Interval Interval::combine(const Interval &interval) const {
    int new_start = a;
    int new_end = b;
    if (a > interval.getStart())
        new_start = interval.getStart();
    if (b < interval.getEnd())
        new_end = interval.getEnd();
    return Interval(new_start, new_end);
}

bool Interval::isSuperInterval(const Interval &interval) const {
    return this->isInTheInterval(interval.getStart()) && this->isInTheInterval(interval.getEnd());
}

int main() {
    return 0;
}
