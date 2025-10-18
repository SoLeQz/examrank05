#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>

class bigint {
private:
	std::string str;

public:
	// Constructeurs
	bigint() : str("0") {}
	bigint(unsigned int n) { std::ostringstream ss; ss << n; str = ss.str(); }
	bigint(const bigint& src) : str(src.str) {}

	// Getter
	std::string getStr() const { return str; }

	// Affectation
	bigint& operator=(const bigint& src) { str = src.str; return *this; }

	// Addition
	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other) { *this = *this + other; return *this; }

	// Incréments
	bigint& operator++() { *this += bigint(1); return *this; }
	bigint operator++(int) { bigint tmp(*this); ++(*this); return tmp; }

	// Décalages gauche/droite avec unsigned int
	bigint operator<<(unsigned int n) const { bigint t(*this); t.str.append(n, '0'); return t; }
	bigint operator>>(unsigned int n) const {
		bigint t(*this);
		if (n >= t.str.size())
			t.str = "0";
		else
			t.str.erase(t.str.size() - n, n);
		return t;
	}
	bigint& operator<<=(unsigned int n) { *this = *this << n; return *this; }
	bigint& operator>>=(unsigned int n) { *this = *this >> n; return *this; }

	// Décalages avec bigint
	bigint operator<<(const bigint& n) const { return *this << std::stoul(n.str); }
	bigint operator>>(const bigint& n) const { return *this >> std::stoul(n.str); }
	bigint& operator<<=(const bigint& n) { *this = *this << n; return *this; }
	bigint& operator>>=(const bigint& n) { *this = *this >> n; return *this; }

	// Comparaisons
	bool operator==(const bigint& o) const { return str == o.str; }
	bool operator!=(const bigint& o) const { return !(*this == o); }
	bool operator<(const bigint& o) const {
		if (str.size() != o.str.size()) return str.size() < o.str.size();
		return str < o.str;
	}
	bool operator>(const bigint& o) const { return o < *this; }
	bool operator<=(const bigint& o) const { return !(*this > o); }
	bool operator>=(const bigint& o) const { return !(*this < o); }

	// Affichage
	friend std::ostream& operator<<(std::ostream& os, const bigint& obj) { return os << obj.str; }
};

#endif
