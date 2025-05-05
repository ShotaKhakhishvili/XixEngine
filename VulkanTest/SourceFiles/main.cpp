#include "first_app.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
	XE::FirstApp app{};

	try {
		app.run();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}