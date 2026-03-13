/***********************************************************************
// OOP244 Workshop 6 lab
// 
// File	Numbers.h
// Version 0.1
// Author	Fardad Soleimanloo
// Student Name: Zara Mazhar
// Student Number: 106537251
// Student Email: zmazhar1@myseneca.ca
//The work is mine, only part copied/taken is what the professor has already provided in the files
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
namespace seneca {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
      int numberCount() const;
      bool load();
      void save() const;

   public:
      Numbers();
      Numbers(const char* filename);
      ~Numbers();
      Numbers(const Numbers& src);
      Numbers& operator=(const Numbers& src);
      Numbers& operator+=(double value);
      double average()const;
      double max()const;
      double min()const;
      std::ostream& display(std::ostream& ostr) const;
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr,  Numbers& N);
}
#endif // !SENECA_NUMBERS_H_

