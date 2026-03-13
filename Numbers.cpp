/***********************************************************************
// OOP244 Workshop 6 lab
//
// File	Numbers.cpp
// Version 0.1
// Student Name: Zara Mazhar
// Student Number: 106537251
// Student Email: zmazhar1@myseneca.ca
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Numbers.h"

using namespace std;

namespace seneca {
	Numbers::~Numbers() {
		save();
		delete[] m_numbers;
		delete[] m_filename;
	}
	Numbers::Numbers(const Numbers& src) {
		setEmpty();
		m_isOriginal = false;
		if (!src.isEmpty()) {
			m_numCount = src.m_numCount;
			m_numbers = new double[m_numCount];
			for (int i = 0; i < m_numCount; i++){
				m_numbers[i] = src.m_numbers[i];
			}

		}
	}
	Numbers& Numbers::operator=(const Numbers& src) {
		if (this != &src) {
			delete[]m_numbers;
			m_numbers = nullptr;
			m_numCount = 0;
			if (!src.isEmpty()) {
				m_numCount = src.m_numCount;
				m_numbers = new double[m_numCount];
				for (int i = 0; i < m_numCount; i++) {
					m_numbers[i] = src.m_numbers[i];
				}
			}
		}return *this;
	}
	int Numbers::numberCount() const {
		int count = 0;
		char ch;
		ifstream  file(m_filename);
		while (file.get(ch)) {
			if (ch == '\n') {
				count++;
			}
		}
		return count;
	}
	bool Numbers::load() {
		bool ok = false;
		if (m_numCount > 0) {
			ifstream file(m_filename);
			m_numbers = new double[m_numCount];
			int i = 0;
			while (file) {
				file >> m_numbers[i];
				if (file) {
					i++;
				}
			}
			if (i == m_numCount) {
				ok = true;
			}
			else {
				delete[] m_numbers;
				setEmpty();
			}

		}
		return ok;
	}
	void Numbers::save() const {
		if (m_isOriginal && !isEmpty()) {
			ofstream file(m_filename);
			for (int i = 0; i < m_numCount; i++) {
				file << m_numbers[i] << endl;
			}
		}
	}
	Numbers& Numbers::operator+=(double value) {
		if (!isEmpty()) {
			double* temp = new double[m_numCount + 1];
			for (int i = 0; i < m_numCount; i++) {
				temp[i] = m_numbers[i];
			}
			m_numCount++;
			temp[m_numCount - 1] = value;
			delete[] m_numbers;
			m_numbers = temp;
			sort();
		}return *this;
	}
	ostream& Numbers::display(ostream& ostr) const {
		if (isEmpty()) {
			ostr << "Empty list";
		}
		else {
			ostr << fixed << setprecision(2);
			ostr << "=========================" << endl;
			if (m_isOriginal) {
				ostr << m_filename << endl;
			}
			else {
				ostr << "*** COPY ***" << endl;
			}
			for (int i = 0; i < m_numCount; i++) {
				ostr << m_numbers[i];
				if (i != m_numCount - 1) {
					ostr << ", ";
				}
			}
			ostr << endl;
			ostr << "-------------------------" << endl;
			ostr << "Total of " << m_numCount << " number(s)" << endl;
			ostr << "Largest number:  " << max() << endl;
			ostr << "Smallest number: " << min() << endl;
			ostr << "Average:         " << average() << endl;
			ostr << "=========================";
		}return ostr;
	}
	ostream& operator<<(ostream& os, const Numbers& N) {
		return N.display(os);
	}
	istream& operator>>(istream& istr, Numbers& N) {
		double value;
		istr >> value;
		if (istr) {
			N += value;
		}
		return istr;





	}

}