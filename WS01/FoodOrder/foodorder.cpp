#include "foodorder.h"

double g_taxrate = 0;
double g_dailydiscount = 0;

sdds::FoodOrder::FoodOrder()
{
	m_name = nullptr;
	m_fDesc = nullptr;
	m_fPrice = 0;
	m_dailySpecial = false;
}

sdds::FoodOrder::~FoodOrder()
{
	delete[] m_name;
	delete[] m_fDesc;
}


std::istream& sdds::FoodOrder::read(std::istream& istr)
{
	if (istr)
	{
		delete[] m_name;
		delete[] m_fDesc;

		istr.getline(m_name, std::numeric_limits<std::streamsize>::max() + 1, ',');
		
		istr.getline(m_fDesc, std::numeric_limits<std::streamsize>::max() + 1, ',');
		
		istr >> m_fPrice;
		istr.ignore(1);

		//istr.getline(m_dailySpecial, std::numeric_limits<std::streamsize>::max() + 1, '\n');

		if (istr.peek() == 'Y')
			m_dailySpecial = true;
		else if (istr.peek() == 'N')
			m_dailySpecial = false;

		istr.ignore(std::numeric_limits<std::streamsize>::max() + 1, ',');
	}
	else
	{
		m_name = nullptr;
		m_fDesc = nullptr;
		m_fPrice = 0;
		m_dailySpecial = false;
	}
	// TODO: insert return statement here
	return istr;
}

void sdds::FoodOrder::display()
{
}
