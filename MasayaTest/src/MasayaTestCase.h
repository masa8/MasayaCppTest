/*
 * MasayaTestCase.h
 *
 *  Created on: 2012/05/21
 *      Author: kevin
 */

#ifndef MASAYATESTCASE_H_
#define MASAYATESTCASE_H_

#include <cppunit/extensions/HelperMacros.h>
class MasayaTestCase : public CPPUNIT_NS::TestFixture {
public:
	MasayaTestCase();
	virtual ~MasayaTestCase();

	  CPPUNIT_TEST_SUITE( MasayaTestCase );
	  CPPUNIT_TEST( test_test );
	  CPPUNIT_TEST( test_meyers_singleton_reg );
	  CPPUNIT_TEST( test_singletonholder );
	  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();

protected:
  void test_test();
  void test_singletonholder();
  void test_meyers_singleton_reg();

};

#endif /* MASAYATESTCASE_H_ */
