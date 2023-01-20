#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

#include <iostream>
#include <stdexcept>
#include <limits>
#include <climits>
#include <cstring>
//#include <string>

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds 
{
	class FoodOrder
	{
	private:
		char* m_name;
		char* m_fDesc;

		double m_fPrice;

		bool m_dailySpecial;
	public:
		FoodOrder();
		~FoodOrder();

		std::istream& read(std::istream& istr);
		void display();
	};
}

#endif // !SDDS_FOODORDER_H


