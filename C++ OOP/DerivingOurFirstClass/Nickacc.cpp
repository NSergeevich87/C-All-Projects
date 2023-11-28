#include "Nickacc.h"

Nickacc::Nickacc() : int_rate{5}
{
}

Nickacc::~Nickacc()
{
}

void Nickacc::deposit(double val)
{
	std::cout << "Nickacc deposit : " << val << "$" << std::endl;
}

void Nickacc::withdraw(double val)
{
	std::cout << "Nickacc withdraw : " << val << "$" << std::endl;
}