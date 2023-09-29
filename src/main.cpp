#include "lib/eleves.hpp"
#include "lib/groupes.hpp"
#include "lib/generation_groupes.hpp"
#include "lib/generateur_csv.hpp"
#include "lib/import.hpp"
//#include "lib/eleves.hpp"
//#include "lib/groupes.hpp"
//#include "lib/generation_groupes.hpp"
//#include "lib/generateur_csv.hpp"
//#include "lib/import.hpp"
#include "lib/tab_dyn.hpp"
#include <iostream>

int main()
{
	//// Micky
	// 
	//creerCsv();
	

	//// Vincent
	// 
	std::string nom_fichier = "eleve.csv";
	genererEleveViaCsv(nom_fichier);

	//// Ethan
	//
	TabDynString tab(10);
	//std::cout << tab.GetNbElem() << std::endl;
	//std::cout << tab.GetNbElemMax() << std::endl;
	TabDynString tab2;
	//std::cout << tab2.GetNbElem() << std::endl;
	//std::cout << tab2.GetNbElemMax() << std::endl;
	TabDynString tab3(tab2);
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Append("test1");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Append("test2");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Append("test3");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Append("test4");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	std::cout << "..." << std::endl;
	std::cout << "Passage de append a add" << std::endl;
	tab3.Add("test5");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Add("test6");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Add("test7");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Add("test8");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Add("test9");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	std::cout << "..." << std::endl;
	std::cout << "Passage de * (*2) a + (+5)" << std::endl;
	tab3.SetParam(false, 5);
	tab3.Add("test10");
	tab3.Add("test11");
	tab3.Add("test12");
	tab3.Add("test13");
	tab3.Add("test14");
	tab3.Add("test15");
	tab3.Add("test16");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Add("test17");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Add("test18");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	std::cout << "..." << std::endl;
	std::cout << "tab3[0] = " << tab3.Get(0) << std::endl;
	std::cout << "tab3[10] = " << tab3.Get(10) << std::endl;
	std::cout << "tab3[15] = " << tab3.Get(15) << std::endl;
	std::cout << "..." << std::endl;
	std::cout << "Modification de tab3[15]" << std::endl;
	tab3.Set(15, "test19");
	std::cout << "tab3[15] = " << tab3.Get(15) << std::endl;
	std::cout << "..." << std::endl;
	std::cout << "Remise a 0 de tab3" << std::endl;
	tab3.Clear();
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	tab3.Add("test20");
	std::cout << "n = " << tab3.GetNbElem() << ", len = " << tab3.GetNbElemMax() << std::endl;
	TabDynString tab4(1, false, 5);

	std::cout << "Création de tabInt" << std::endl;
	TabDynInt tabInt(10);
	tabInt.Append(1);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(2);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(3);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(4);
	std::cout << "..." << std::endl;
	tabInt.Append(5);
	tabInt.Append(6);
	tabInt.Append(7);
	tabInt.Append(8);
	tabInt.Append(9);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(10);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(11);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	std::cout << "..." << std::endl;
	std::cout << "tabInt[0] = " << tabInt.Get(0) << std::endl;
	std::cout << "tabInt[10] = " << tabInt.Get(10) << std::endl;
	std::cout << "..." << std::endl;
	std::cout << "Modification de tabInt[10]" << std::endl;
	tabInt.Set(10, 12);
	std::cout << "tabInt[10] = " << tabInt.Get(10) << std::endl;
	std::cout << "..." << std::endl;
	std::cout << "Remise a 0 de tabInt" << std::endl;
	tabInt.Clear();
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(13);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	std::cout << "Passage de append a add" << std::endl;
	tabInt.Add(14);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Add(15);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Add(16);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	std::cout << "Passage de * (*2) a + (+5)" << std::endl;
	tabInt.SetParam(false, 5);
	tabInt.Append(17);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(18);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(19);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(20);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(21);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;
	tabInt.Append(22);
	std::cout << "n = " << tabInt.GetNbElem() << ", len = " << tabInt.GetNbElemMax() << std::endl;

	std::cout << "Création de tabString" << std::endl;
	TabDynString tabString(10);
	tabString.Append("1");
	std::cout << "n = " << tabString.GetNbElem() << ", len = " << tabString.GetNbElemMax() << std::endl;
	tabString.Append("2");
	std::cout << "n = " << tabString.GetNbElem() << ", len = " << tabString.GetNbElemMax() << std::endl;
	tabString.Append("3");
	std::cout << "n = " << tabString.GetNbElem() << ", len = " << tabString.GetNbElemMax() << std::endl;
	tabString.Append("1");
	std::cout << "..." << std::endl;
	tabString.Append("2");
	tabString.Append("3");
	tabString.Append("1");
	tabString.Append("2");
	tabString.Append("3");
	std::cout << "n = " << tabString.GetNbElem() << ", len = " << tabString.GetNbElemMax() << std::endl;
	tabString.Append("1");
	std::cout << "n = " << tabString.GetNbElem() << ", len = " << tabString.GetNbElemMax() << std::endl;
	tabString.Append("2");
	std::cout << "n = " << tabString.GetNbElem() << ", len = " << tabString.GetNbElemMax() << std::endl;
	std::cout << "..." << std::endl;
	for (unsigned int i = 0; i < tabString.GetNbElem(); i++)
	{
		std::cout << "tabString[" << i << "] = " << tabString.Get(i) << std::endl;
	}
	std::cout << "n = " << tabString.GetNbElem() << ", len = " << tabString.GetNbElemMax() << std::endl;
	std::cout << "..." << std::endl;
	tabString.Pop();
	//tabString.Pop(3);
	//tabString.Remove("1");
	//tabString.Remove("1", 3);
	//tabString.Remove("1", true);
	//tabString.Remove("1", false);
	for (unsigned int i = 0; i < tabString.GetNbElem(); i++)
	{
		std::cout << "tabString[" << i << "] = " << tabString.Get(i) << std::endl;
	}
	std::cout << "n = " << tabString.GetNbElem() << ", len = " << tabString.GetNbElemMax() << std::endl;


	return 0;*/
}