#ifndef ROBO_MODELS_H
#define ROBO_MODELS_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include<iterator>
#include "parts.h"

using namespace std;
class model
{
public:

	string name;
	int modelNumber;
	double price;
	vector<Torso*> Torsosm;
};

class Orders
{
public:

	int order_num;
	string date;
	string customer;
	string salesA;
	model mod;
	string status;
	double shipping, tax, price, total;


};

#endif
