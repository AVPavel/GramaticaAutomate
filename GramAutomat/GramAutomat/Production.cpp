#include "Production.h"

//De definit metodele din production

size_t Production::getNumberOfRules()
{
	return mRules.size();
}

void Production::AddRule(const Rule& rule)
{
	mRules.push_back(rule);
}
