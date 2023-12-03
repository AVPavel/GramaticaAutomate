#include "Production.h"

//De definit metodele din production

int Production::getNumberOfRules()
{
	return mRules.size();
}

void Production::AddRule(const Rule& rule)
{
	mRules.push_back(rule);
}
