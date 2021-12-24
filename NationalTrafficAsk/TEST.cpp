#include "Structure.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	BaseData* b = new BaseData(1, "Zibo", "Taian", new TIME("2020-11-11 11:11:11"), new TIME("2020-11-12 11:11:11"), "G543", "High Speed Train", 888.9);
	cout << b->begin_city;
}