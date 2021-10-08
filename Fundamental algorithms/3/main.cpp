#include <iostream>
#include "Tree.h"

int main(int argc, char* argv[])
{
	using namespace std;

	if (argc < 2)
		error(1);

	func_tree(argv[1]);
	return 0;
}     