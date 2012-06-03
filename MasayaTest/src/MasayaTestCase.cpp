/*
 * MasayaTestCase.cpp
 *
 *  Created on: 2012/05/21
 *      Author: kevin
 */

#include "MasayaTestCase.h"
#include "MeyersSingletonRegistry.h"
#include "SingletonHolder.h"
#include "MySingleton.h"
#include "MyTimer.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>

CPPUNIT_TEST_SUITE_REGISTRATION( MasayaTestCase );

MasayaTestCase::MasayaTestCase() {
	// TODO Auto-generated constructor stub

}

MasayaTestCase::~MasayaTestCase() {
	// TODO Auto-generated destructor stub
}
void
MasayaTestCase::setUp() {
	// TODO Auto-generated destructor stub
}

typedef std::vector<int*> IntV;
IntV v;


void test(int * value){

	IntV::iterator it = std::find(v.begin(),v.end(),value);
	if( it != v.end())
	{
		std::cout << "found!:" << value << std::endl;
		delete *it;
		v.erase(it);
	}

}

class Deleter {
public:
	void operator ()(int * value){

		std::cout << value << std::endl;
		test(value);
	}
};

class AreFive{
public:
		void operator () (int value){
			CPPUNIT_ASSERT( value == 5);
		}
};

void
MasayaTestCase::test_vector()
{

	/*! test cter */
	std::vector<int> iv;
	CPPUNIT_ASSERT( iv.size() == 0);

	std::vector<int> iv_ten(10);
	CPPUNIT_ASSERT( iv_ten.size() == 10);

	std::vector<int> iv_ten_initialized(10,5);
	CPPUNIT_ASSERT( iv_ten_initialized.size()== 10);
	for_each(iv_ten_initialized.begin(),iv_ten_initialized.end(),AreFive());

	std::vector<int> copy(iv_ten_initialized);
	CPPUNIT_ASSERT( copy.size()== 10);
	for_each(copy.begin(),copy.end(),AreFive());





	/*! add item */
	int *test = new int();
	std::cout << "Test:"<< test << std::endl;
	v.push_back(test);

	/*! delete all the item */
	for_each(v.begin(),v.end(),Deleter());
	std::cout << test << std::endl;


	CPPUNIT_ASSERT(true);
}


void
MasayaTestCase::test_test() {



	  CPPUNIT_ASSERT (true);
}
void
MasayaTestCase::test_meyers_singleton_reg() {

	MeyersSingletonRegistry<int>& reg = MeyersSingletonRegistry<int>::getInstance();
	reg.set("one",new int(1));
	int& x = reg.get("one");

	std::cout << x << std::endl;


	CPPUNIT_ASSERT (true);
}


void
MasayaTestCase::test_singletonholder()
{

	masaya::MySingleton& x = masaya::MySingleton::get_instance();

	CPPUNIT_ASSERT (x.isTrue());

}

void
MasayaTestCase::test_mytimer()
{

	masaya::MyTimer& x = masaya::MyTimer::get_instance();
	x.start();
	x.setCurrentTime("first");
	x.setCurrentTime("second");
	std::cout << "first" << x.getTime("first") << std::endl;
	std::cout << "second" << x.getTime("second") << std::endl;
	std::cout << "error" << x.getTime("error") << std::endl;

	CPPUNIT_ASSERT (true);

}


void
MasayaTestCase::test_character()
{

	/*! calc characters */
	char x = '9';
	char y = '0';
	int number = static_cast<int>(x) - static_cast<int>(y);
	std::cout << number << std::endl;
	CPPUNIT_ASSERT( number == 9 );

	/*! change character */
	char white_space = 'a' - 'A';
	CPPUNIT_ASSERT( white_space == ' ' );

	int a = static_cast<int>('A') + static_cast<int>(' ');
	std::cout << static_cast<char>(a) << std::endl;
	int a_dif = static_cast<int>('a');
	CPPUNIT_ASSERT ( static_cast<int>(a_dif) == static_cast<int>(a));

	CPPUNIT_ASSERT( isdigit('0'));
	CPPUNIT_ASSERT( isalpha('a'));
	CPPUNIT_ASSERT( isupper('A'));
	CPPUNIT_ASSERT( islower('b'));

	char xx[2];
	xx[0]= static_cast<char>(toupper('a'));
	xx[1]= '\0';
	char X[2];
	X[0]= 'A';
	X[1]= '\0';

	CPPUNIT_ASSERT( strcmp(xx,X) == 0);
}
