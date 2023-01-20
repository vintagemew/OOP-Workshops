#define _CRT_SECURE_NO_WARNINGS

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

		char temp[CHAR_MAX];

		istr.getline(temp, CHAR_MAX, ',');
		if (strlen(temp) > 0)
		{
			m_name = new char[strlen(temp) + 1];
			strcpy(m_name, temp);
		}
		
		istr.getline(temp, CHAR_MAX, ',');
		if (strlen(temp) > 0)
		{
			m_fDesc = new char[strlen(temp) + 1];
			strcpy(m_fDesc, temp);
		}
		
		istr >> m_fPrice;
		istr.ignore(1);

		istr.getline(temp, CHAR_MAX, '\n');
		if (strlen(temp) > 0)
		{
			if (temp[0] == 'Y')
				m_dailySpecial = true;
			else if (temp[0] == 'N')
				m_dailySpecial = false;
		}
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
	static int s_counter = 0;

	std::cout << s_counter + 1 << std::endl;

	if (m_name != nullptr)
	{
		std::cout << m_name;
	}
	if (m_fDesc != nullptr)
	{
		std::cout << m_fDesc;
	}
	std::cout << m_fPrice;
	std::cout << m_dailySpecial;


	s_counter++;
}

