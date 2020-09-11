#include <boost/version.hpp>
#include <boost/config.hpp>
#include <boost/timer.hpp>
#include <iostream>
using namespace boost;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	std::cout << BOOST_VERSION << std::endl;
	std::cout << BOOST_LIB_VERSION << std::endl;
	std::cout << BOOST_PLATFORM << std::endl;
	std::cout << BOOST_COMPILER << std::endl;
	std::cout << BOOST_STDLIB << std::endl;

	timer t;
	std::cout << "Max timespan:" << t.elapsed_max() / 3600 << "h" << endl;
	cout << "min timespan:" << t.elapsed_min() << "s" << endl;
	cout << "now timespan:" << t.elapsed()  << "s" << endl;
	return 0;
}

