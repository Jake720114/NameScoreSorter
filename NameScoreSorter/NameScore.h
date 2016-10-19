#pragma once

#include <iostream>
#include <string>

class NameScore {
public:
	NameScore(std::string first, std::string last, int score) :
		firstName_(first), lastName_(last), score_(score) { }

	friend static bool descByScore(const NameScore& r1, const NameScore& r2) { return r1.score_ >= r2.score_; }
	friend static bool descByLastName(const NameScore& r1, const NameScore& r2) { return r1.lastName_ >= r2.lastName_; }
	friend std::ostream& operator<<(std::ostream& out, const NameScore& ns) {
		out << ns.firstName_ << ", " << ns.lastName_ << ", " << ns.score_;
		return out;
	}

	~NameScore() { }

private:
	std::string firstName_;
	std::string lastName_;
	int score_;
};
