#ifndef PARTS_H
#define PARTS_H
#include <string>
#include <vector>
#include <fstream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input_Choice.H>
#include <iostream>
#include <string>
#include<iterator>
#include"parts.h"
#include <FL/Fl_Box.H>
#include <conio.h>
#include <stdio.h>
#include <fstream>



using namespace std;


class robot
{
public:
	string name;
	int part_num;
	string type;
	double weight;
	double cost;
	string description;
	//robot();
	//void setter();
	virtual void mysetter(string name, int part_num, string type, double weight, double cost, string description) = 0;
};


class Arm : public robot
{
public:
	//Arm();
	virtual void mysetter(string name, int part_num, string type, double weight, double cost, string description);
	void setArm(int Power_Con);
	int power_con;
};


class Locomotor : public robot
{
public:
	//Locomotor();
	virtual void mysetter(string name, int part_num, string type, double weight, double cost, string description);
	int max_speed;
	int power_conloco;
};

class Torso : public robot
{
public:
	//Torso();
	virtual void mysetter(string name, int part_num, string type, double weight, double cost, string description);
	Head tHead;
	vector<Arm> tArm;
	int battery_compartments;
	Locomotor tLoco;
	vector<Battery> tBattery;
};

class Battery : public robot
{
public:
	virtual void mysetter(string name, int part_num, string type, double weight, double cost, string description);
	//Battery();
	void setBattery(double Energy, double power);
	double energy;
	double maxPower;
};

class Head : public robot
{
public:
	//Head();
	virtual void mysetter(string name, int part_num, string type, double weight, double cost, string description);
};



#endif
