#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <cstdint>
#include <functional>
#include <stdint-gcc.h>
#include "my_vector.h"


const uint32_t BASE = 32;
const int MAX = 1000000000;

struct big_integer {

    big_integer();
    big_integer(big_integer const &other) = default;
    big_integer(int a);
    explicit big_integer(std::string const &str);
    ~big_integer() = default;

    big_integer &operator=(big_integer const &other) = default;

    big_integer &operator+=(big_integer const &rhs);
    big_integer &operator-=(big_integer const &rhs);
    big_integer &operator*=(big_integer const &rhs);
    big_integer &operator/=(big_integer const &rhs);
    big_integer &operator%=(big_integer const &rhs);

    big_integer &bit_operation(big_integer const &rhs, const std::function<uint32_t(uint32_t, uint32_t)> function);
    big_integer &operator&=(big_integer const &rhs);
    big_integer &operator|=(big_integer const &rhs);
    big_integer &operator^=(big_integer const &rhs);

    big_integer &operator<<=(int rhs);
    big_integer &operator>>=(int rhs);

    big_integer operator+() const;
    big_integer operator-() const;
    big_integer operator~() const;

    big_integer &operator++();
    big_integer operator++(int);
    big_integer &operator--();
    big_integer operator--(int);

    void del_rep_sign();

    friend bool operator==(big_integer const &a, big_integer const &b);
    friend bool operator!=(big_integer const &a, big_integer const &b);
    friend bool operator<(big_integer const &a, big_integer const &b);
    friend bool operator>(big_integer const &a, big_integer const &b);
    friend bool operator<=(big_integer const &a, big_integer const &b);
    friend bool operator>=(big_integer const &a, big_integer const &b);

    friend std::pair<big_integer, uint32_t> div_by_short(big_integer const &a, uint32_t const &b);
    friend std::pair<big_integer, big_integer> div_by_short_b_i(big_integer const &a, big_integer const &b);
    friend std::pair<big_integer, big_integer> div_mod(big_integer const &a, big_integer const &b);

    friend std::string to_string(big_integer const &a);

private:
    my_vector vec;
};

big_integer operator+(big_integer a, big_integer const &b);
big_integer operator-(big_integer a, big_integer const &b);
big_integer operator*(big_integer a, big_integer const &b);
big_integer operator/(big_integer a, big_integer const &b);
big_integer operator%(big_integer a, big_integer const &b);

big_integer operator&(big_integer a, big_integer const &b);
big_integer operator|(big_integer a, big_integer const &b);
big_integer operator^(big_integer a, big_integer const &b);

big_integer operator<<(big_integer a, int b);
big_integer operator>>(big_integer a, int b);

bool operator==(big_integer const &a, big_integer const &b);
bool operator!=(big_integer const &a, big_integer const &b);
bool operator<(big_integer const &a, big_integer const &b);
bool operator>(big_integer const &a, big_integer const &b);
bool operator<=(big_integer const &a, big_integer const &b);
bool operator>=(big_integer const &a, big_integer const &b);

std::string to_string(big_integer const &a);

std::ostream &operator<<(std::ostream &s, big_integer const &a);
std::istream &operator>>(std::istream &s, big_integer &a);

std::pair<big_integer, big_integer> div_by_short_b_i(big_integer const &a, big_integer const &b);
std::pair<big_integer, uint32_t> div_by_short(big_integer const &a, uint32_t const &b);
std::pair<big_integer, big_integer> div_mod(big_integer const &a, big_integer const &b);

#endif