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


