#pragma once

#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <regex>
#include <ostream>

#include "NameScore.h"


class NameScoreSorter
{
public:
	void pushline(const std::string& line) {
		std::string firstName, lastName;
		std::string score;
		int int_score;

		// parsing & storing into vector
		if (std::tr1::regex_match(line, std::tr1::regex("(\\s*\\w+),(\\s*\\w+),(\\s*\\d+)"))) {
			std::stringstream ss(line);
			std::getline(ss, firstName, ',');
			std::getline(ss, lastName, ',');
			std::getline(ss, score, ',');
			std::istringstream iss(score);
			iss >> int_score;

			// trim
			trim(firstName);
			trim(lastName);
			NameScore record(firstName, lastName, int_score);
			v.push_back(record);
		}
	}

	const std::string getnthline(std::size_t idx) const {
		std::ostringstream os;
		os << v[idx];

		return os.str();
	}

	void sortDescOrderByScoreAndLastName() {
		//sort(v.begin(), v.end(), std::bind(std::logical_and<bool>(),
		//	std::bind(descByScore, std::placeholders::_1, std::placeholders::_2),
		//	std::bind(descByLastName, std::placeholders::_1, std::placeholders::_2)));
		sort(v.begin(), v.end(), descByScoreAndLastNameAndFirstName);
	}



	inline const std::size_t count() const {
		return v.size();
	}

	NameScoreSorter() { }
	~NameScoreSorter() { }

private:
	void ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(),
			std::not1(std::ptr_fun<int, int>(std::isspace))));
	}

	// trim from right
	void rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(),
			std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	}

	void trim(std::string &s) {
		ltrim(s);
		rtrim(s);
	}


	std::vector<NameScore> v;

};

