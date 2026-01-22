#include "bigint.hpp"

static std::string addStrings(const std::string& a, const std::string& b)
{
    std::string res;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
		res.insert(res.begin(), char(sum % 10 + '0'));
		carry = sum / 10;
	}
	return res;
}


bigint bigint::operator+(const bigint& other) const {
	bigint tmp;
	tmp.str = addStrings(str, other.str);
	return tmp;
}
