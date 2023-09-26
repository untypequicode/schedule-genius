#include "tableau_dynamique.hpp"

TabDyn::TabDyn()
	: m_nb_elem(0),
	m_nb_elem_max(0),
	m_tab_string(nullptr),
	m_tab_char(nullptr),
	m_tab_int(nullptr),
	m_tab_double(nullptr),
	m_tab_float(nullptr)
{

}

TabDyn::TabDyn(const TabDyn& tab_dyn)
	: m_nb_elem(tab_dyn.GetNbElem()),
	m_nb_elem_max(tab_dyn.GetNbElemMax()),
	m_tab_string(tab_dyn.GetTabString()),
	m_tab_char(tab_dyn.GetTabChar()),
	m_tab_int(tab_dyn.GetTabInt()),
	m_tab_double(tab_dyn.GetTabDouble()),
	m_tab_float(tab_dyn.GetTabFloat())
{

}

TabDyn::TabDyn(unsigned int nb_elem_max)
	: m_nb_elem(0),
	m_nb_elem_max(nb_elem_max),
	m_tab_string(nullptr),
	m_tab_char(nullptr),
	m_tab_int(nullptr),
	m_tab_double(nullptr),
	m_tab_float(nullptr)
{

}

TabDyn::TabDyn(unsigned int nb_elem_max, std::string* tab_string)
	: m_nb_elem(0),
	m_nb_elem_max(nb_elem_max),
	m_tab_string(tab_string),
	m_tab_char(nullptr),
	m_tab_int(nullptr),
	m_tab_double(nullptr),
	m_tab_float(nullptr)
{

}

TabDyn::TabDyn(unsigned int nb_elem_max, char* tab_char)
	: m_nb_elem(0),
	m_nb_elem_max(nb_elem_max),
	m_tab_string(nullptr),
	m_tab_char(tab_char),
	m_tab_int(nullptr),
	m_tab_double(nullptr),
	m_tab_float(nullptr)
{

}

TabDyn::TabDyn(unsigned int nb_elem_max, int* tab_int)
	: m_nb_elem(0),
	m_nb_elem_max(nb_elem_max),
	m_tab_string(nullptr),
	m_tab_char(nullptr),
	m_tab_int(tab_int),
	m_tab_double(nullptr),
	m_tab_float(nullptr)
{

}

TabDyn::TabDyn(unsigned int nb_elem_max, double* tab_double)
	: m_nb_elem(0),
	m_nb_elem_max(nb_elem_max),
	m_tab_string(nullptr),
	m_tab_char(nullptr),
	m_tab_int(nullptr),
	m_tab_double(tab_double),
	m_tab_float(nullptr)
{

}

TabDyn::TabDyn(unsigned int nb_elem_max, float* tab_float)
	: m_nb_elem(0),
	m_nb_elem_max(nb_elem_max),
	m_tab_string(nullptr),
	m_tab_char(nullptr),
	m_tab_int(nullptr),
	m_tab_double(nullptr),
	m_tab_float(tab_float)
{

}

TabDyn::~TabDyn()
{
	delete[] m_tab_string;
	delete[] m_tab_char;
	delete[] m_tab_int;
	delete[] m_tab_double;
	delete[] m_tab_float;
}

void TabDyn::AddElem(std::string elem)
{
	if (m_nb_elem_max == 0 or m_tab_string == nullptr)
	{
		m_tab_string = new std::string[2];
		m_nb_elem_max = 2;
		m_tab_string[0] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem < m_nb_elem_max) {
		m_tab_string[m_nb_elem] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem == m_nb_elem_max) {

		std::string* temp = new std::string[m_nb_elem_max * 2];
		for (unsigned int i = 0; i < m_nb_elem; i++) {
			temp[i] = m_tab_string[i];
		}
		temp[m_nb_elem] = elem;
		m_nb_elem++;
		m_nb_elem_max *= 2;
		delete[] m_tab_string;
		m_tab_string = temp;
	}
}

void TabDyn::AddElem(char elem)
{
	if (m_nb_elem_max == 0 or m_tab_char == nullptr)
	{
		m_tab_char = new char[2];
		m_nb_elem_max = 2;
		m_tab_char[0] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem < m_nb_elem_max) {
		m_tab_char[m_nb_elem] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem == m_nb_elem_max) {

		char* temp = new char[m_nb_elem_max * 2];
		for (unsigned int i = 0; i < m_nb_elem; i++) {
			temp[i] = m_tab_char[i];
		}
		temp[m_nb_elem] = elem;
		m_nb_elem++;
		m_nb_elem_max *= 2;
		delete[] m_tab_char;
		m_tab_char = temp;
	}
}

void TabDyn::AddElem(int elem)
{
	if (m_nb_elem_max == 0 or m_tab_int == nullptr)
	{
		m_tab_int = new int[2];
		m_nb_elem_max = 2;
		m_tab_int[0] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem < m_nb_elem_max) {
		m_tab_int[m_nb_elem] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem == m_nb_elem_max) {

		int* temp = new int[m_nb_elem_max * 2];
		for (unsigned int i = 0; i < m_nb_elem; i++) {
			temp[i] = m_tab_int[i];
		}
		temp[m_nb_elem] = elem;
		m_nb_elem++;
		m_nb_elem_max *= 2;
		delete[] m_tab_int;
		m_tab_int = temp;
	}
}

void TabDyn::AddElem(double elem)
{
	if (m_nb_elem_max == 0 or m_tab_double == nullptr)
	{
		m_tab_double = new double[2];
		m_nb_elem_max = 2;
		m_tab_double[0] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem < m_nb_elem_max) {
		m_tab_double[m_nb_elem] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem == m_nb_elem_max) {

		double* temp = new double[m_nb_elem_max * 2];
		for (unsigned int i = 0; i < m_nb_elem; i++) {
			temp[i] = m_tab_double[i];
		}
		temp[m_nb_elem] = elem;
		m_nb_elem++;
		m_nb_elem_max *= 2;
		delete[] m_tab_double;
		m_tab_double = temp;
	}
}

void TabDyn::AddElem(float elem)
{
	if (m_nb_elem_max == 0 or m_tab_float == nullptr)
	{
		m_tab_float = new float[2];
		m_nb_elem_max = 2;
		m_tab_float[0] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem < m_nb_elem_max) {
		m_tab_float[m_nb_elem] = elem;
		m_nb_elem++;
	}
	else if (m_nb_elem == m_nb_elem_max) {

		float* temp = new float[m_nb_elem_max * 2];
		for (unsigned int i = 0; i < m_nb_elem; i++) {
			temp[i] = m_tab_float[i];
		}
		temp[m_nb_elem] = elem;
		m_nb_elem++;
		m_nb_elem_max *= 2;
		delete[] m_tab_float;
		m_tab_float = temp;
	}
}

std::string TabDyn::GetElemString(unsigned int index) const
{
	if (0 <= index < m_nb_elem) {
		return m_tab_string[index];
	}
	return "";
}

char TabDyn::GetElemChar(unsigned int index) const
{
	if (0 <= index < m_nb_elem) {
		return m_tab_char[index];
	}
	return '\0';
}

int TabDyn::GetElemInt(unsigned int index) const
{
	if (0 <= index < m_nb_elem) {
		return m_tab_int[index];
	}
	return 0;
}

double TabDyn::GetElemDouble(unsigned int index) const
{
	if (0 <= index < m_nb_elem) {
		return m_tab_double[index];
	}
	return 0.0;
}

float TabDyn::GetElemFloat(unsigned int index) const
{
	if (0 <= index < m_nb_elem) {
		return m_tab_float[index];
	}
	return 0.0f;
}

std::string* TabDyn::GetTabString() const
{
	return m_tab_string;
}

char* TabDyn::GetTabChar() const
{
	return m_tab_char;
}

int* TabDyn::GetTabInt() const
{
	return m_tab_int;
}

double* TabDyn::GetTabDouble() const
{
	return m_tab_double;
}

float* TabDyn::GetTabFloat() const
{
	return m_tab_float;
}

void TabDyn::SetElemString(unsigned int index, std::string elem)
{
	if (0 <= index < m_nb_elem) {
		m_tab_string[index] = elem;
	}
}

void TabDyn::SetElemChar(unsigned int index, char elem)
{
	if (0 <= index < m_nb_elem) {
		m_tab_char[index] = elem;
	}
}

void TabDyn::SetElemInt(unsigned int index, int elem)
{
	if (0 <= index < m_nb_elem) {
		m_tab_int[index] = elem;
	}
}

void TabDyn::SetElemDouble(unsigned int index, double elem)
{
	if (0 <= index < m_nb_elem) {
		m_tab_double[index] = elem;
	}
}

void TabDyn::SetElemFloat(unsigned int index, float elem)
{
	if (0 <= index < m_nb_elem) {
		m_tab_float[index] = elem;
	}
}

unsigned int TabDyn::GetNbElem() const
{
	return m_nb_elem;
}

unsigned int TabDyn::GetNbElemMax() const
{
	return m_nb_elem_max;
}