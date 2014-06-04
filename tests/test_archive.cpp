#include <boost/test/unit_test.hpp>
#include "test_globals.hpp"
#include <loaders/LoaderIMG.hpp>

BOOST_AUTO_TEST_SUITE(ArchiveTests)

BOOST_AUTO_TEST_CASE(test_open_archive)
{
	LoaderIMG archive;
	
	BOOST_REQUIRE( archive.load(Global::getGamePath() + "/models/gta3") );
	
	BOOST_CHECK( archive.getAssetCount() > 0 );
	
	auto& f = archive.getAssetInfoByIndex(0);
	
	// A few assumptions..
	
	BOOST_CHECK_EQUAL( f.name, "radar00.txd" );
	BOOST_CHECK_EQUAL( f.offset, 0);
	BOOST_CHECK_EQUAL( f.size, 33);
	
	auto& f2 = archive.getAssetInfo("radar00.txd");
	
	BOOST_CHECK_EQUAL( f2.name, f.name );
	BOOST_CHECK_EQUAL( f2.offset, f.offset );
	BOOST_CHECK_EQUAL( f2.size, f.size );
}

BOOST_AUTO_TEST_SUITE_END()