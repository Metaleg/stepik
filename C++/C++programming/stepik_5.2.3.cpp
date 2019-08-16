// Вам дан класс Rational, который описывает рациональное число. В нем определены методы add, sub, mul и div, которые прибавляют к нему число, отнимают 
// число, умножают на число и делят на число соответственно. Кроме того в нем определен метод neg, который меняет знак на противоположный.
// 
// Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать в качестве аргументов и объекты типа Rational и целые 
// числа. Кроме того вам необходимо определить операторы унарного минуса и плюса для класса Rational.
// 
// Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно. Кроме того, нельзя (это совершенно не 
// нужно) использовать динамическую память или подключать какие-либо библиотеки.

static inline long gcd(long a, long b) {//-----------------Evklid`s algorithm; Calculate GCD
    return (b ? gcd(b, a % b) : a);
}

static inline long lcm(int a, int b) {//-----------------Calculate LCM
    return a / gcd(a, b) * b;
}

struct Rational {
    explicit Rational(int numerator = 0, int denominator = 1);
    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);
    void neg();
    void inv();
    double to_double() const;

    Rational operator+() const;
    Rational operator-() const;
    Rational & operator*=(Rational const & other);
    Rational & operator*=(int value);
    Rational & operator/=(Rational const & other);
    Rational & operator/=(int value);
    Rational & operator+=(Rational const& other);
    Rational & operator+=(int value);
    Rational & operator-=(Rational other);
    Rational & operator-=(int value);

private:
    int numerator_;
    int denominator_;
};

Rational Rational::operator+() const {
    return (*this);
}

Rational Rational::operator-() const {
    Rational temp(*this);
    if ((temp.numerator_ > 0 && temp.denominator_ > 0) || (temp.numerator_ < 0 && temp.denominator_ > 0))
        temp.numerator_ *= -1;
    else
        temp.denominator_ *= -1;
    return temp;
}

Rational & Rational::operator-=(Rational other) {
    return *this += (-other);
}

Rational & Rational::operator-=(int value) {
    return *this += (-value);
}

Rational & Rational::operator*=(Rational const& other) {
    this->numerator_ *= other.numerator_;
    this->denominator_ *= other.denominator_;
    return *this;
}

Rational & Rational::operator*=(int value) {
    this->numerator_ *= value;
    return *this;
}

Rational & Rational::operator/=(Rational const& other) {
    this->numerator_ *= other.denominator_;
    this->denominator_ *= other.numerator_;
    return *this;
}

Rational & Rational::operator/=(int value) {
    this->denominator_ *= value;
    return *this;
}

Rational & Rational::operator+=(Rational const & other) {
    int temp = lcm(this->denominator_, other.denominator_);
    this->numerator_ = this->numerator_ *  temp / this->denominator_ + other.numerator_ * temp / other.denominator_;
    this->denominator_ = temp;
    return *this;
}

Rational & Rational::operator+=(int value) {
    this->numerator_ += (this->denominator_ * value);
    return *this;
}
