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
