// Еще одна важная группа операторов, которые полезно реализовать для класса рациональных чисел — это операторы сравнения. Реализуйте операторы <, <=, >, 
// >=, ==, != для класса Rational так, чтобы можно было сравнивать объекты класса Rational не только друг с другом, но и с целыми числами.

// При решении задания не используйте метод to_double, он введен в класс, в первую очередь, для удобства тестирования. Вы можете определять любые 
// вспомогательные методы или функции если необходимо.

// Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.

struct Rational {
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);
    Rational operator-() const;
    Rational operator+() const;

    [[nodiscard]] int get_numerator() const;
    [[nodiscard]] int get_denominator() const;

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

int Rational::get_numerator() const {
    return numerator_;
}

int Rational::get_denominator() const {
    return denominator_;
}

bool operator==(const Rational & lhs, const Rational & rhs) {
    return lhs.get_numerator() == rhs.get_numerator() && lhs.get_denominator() == rhs.get_denominator();
}

bool operator!=(const Rational & lhs, const Rational & rhs) {
    return !(rhs == lhs);
}

bool operator<(const Rational & lhs, const Rational & rhs) {
    if (lhs.get_denominator() == rhs.get_denominator())
        return lhs.get_numerator() < rhs.get_numerator();
    else
        return lhs.get_numerator() * rhs.get_denominator() < rhs.get_numerator() * lhs.get_denominator();
}

bool operator>(const Rational & lhs, const Rational & rhs) {
    return rhs < lhs;
}

bool operator<=(const Rational & lhs, const Rational & rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Rational & lhs, const Rational & rhs) {
    return !(lhs < rhs);
}
