/*
 * MasayaTestCase.cpp
 *
 *  Created on: 2012/05/21
 *      Author: kevin
 */

#include "MasayaTestCase.h"
#include "MeyersSingletonRegistry.h"
#include "SingletonHolder.h"

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

	class MySingleton : public masaya::SingletonHolder<MySingleton>{
	friend class masaya::SingletonHolder<MySingleton>;
	private:
		~MySingleton(){};
	public:
		bool isTrue(){
			return true;
		}
	};
void
MasayaTestCase::test_singletonholder()
{

	MySingleton& x = MySingleton::get_instance();

	CPPUNIT_ASSERT (x.isTrue());

}


