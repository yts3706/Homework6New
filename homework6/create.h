#ifndef CREATE_H
#define CREATE_H

#include "create_parts.h"
#include"robo_models.h"

Fl_Window *createwin;
Fl_Window *createrm;
Fl_Window *rpwin, *ordern, *userwin, *custwin, *sawin;

vector<model*> models;
model* tempmodel;

vector<Orders*> orders;
Orders* temporder;

vector<string> customers;
vector<string> sas;

Fl_Input *rm_name, *rm_model_number, *rm_price, *order_num, *date, *customer, *sa, *status, *cost, *shipping, *tax, *total, *customern,*san;

void ropa_create(Fl_Widget* w, void* p)
{
	createwin->hide();

	rpwin = new Fl_Window{ 600,400,"Create Robot Part" };
	Fl_Button head(200, 25, 200, 30, "Head");
	Fl_Button arm(200, 75, 200, 30, "Arms");
	Fl_Button battery(200, 125, 200, 30, "Battery");
	Fl_Button locomotor(200, 175, 200, 30, "Locomotor");
	Fl_Button torso(200, 225, 200, 30, "Torso");

	head.callback(create_head);
	arm.callback(create_arm);
	battery.callback(create_battery);
	locomotor.callback(create_locomotor);
	torso.callback(create_torso);

	rpwin->end();
	rpwin->show();

	Fl::run();
}
void create_rm(Fl_Widget* w, void* p)
{
	tempmodel->name = rm_name->value();
	tempmodel->price = stod(rm_name->value());
	tempmodel->modelNumber = stoi(rm_model_number->value());

	models.push_back(tempmodel);
	
}

void rm_create(Fl_Widget* w, void* p)
{
	createrm = new Fl_Window(800,900);

	rm_name = new Fl_Input(130, 250, 210, 25, " Model Name");
	rm_name->align(FL_ALIGN_LEFT);

	rm_model_number = new Fl_Input(130, 300, 210, 25, "Model Number");
	rm_model_number->align(FL_ALIGN_LEFT);

	rm_price = new Fl_Input(130, 350, 210, 25, "Model Number");
	rm_price->align(FL_ALIGN_LEFT);

	Fl_Return_Button *rp_confirm;
	rp_confirm = new Fl_Return_Button(150, 610, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)create_rm, 0);

	createrm->show();
	Fl::run();
}

void create_order(Fl_Widget* w, void* p)
{
	ordern->hide();
	temporder->customer = customer->value();
	temporder->date = date->value();
	temporder->order_num = stoi(order_num->value());
	temporder->price = stod(cost->value());
	temporder->salesA = sa->value();
	temporder->shipping = stod(shipping->value());
	temporder->status = status->value();
	temporder->tax = stod(tax->value());
	temporder->total= stod(tax->value()) + stod(shipping->value()) + stod(cost->value());

	orders.push_back(temporder);


	createwin->show();
}


void order(Fl_Widget* w, void* p)
{
	createwin->hide();
	ordern = new Fl_Window(800, 900);

	order_num = new Fl_Input(100, 25, 210, 25, "Order Number");
	order_num->align(FL_ALIGN_LEFT);
	
	date = new Fl_Input(100, 25, 210, 25, "Date (mm/dd/yy)");
	date->align(FL_ALIGN_LEFT);

	customer = new Fl_Input(100, 25, 210, 25, "Customer");
	customer->align(FL_ALIGN_LEFT);

	sa = new Fl_Input(100, 25, 210, 25, "Sales Associate");
	sa->align(FL_ALIGN_LEFT);

	status = new Fl_Input(100, 25, 210, 25, "Status");
	status->align(FL_ALIGN_LEFT);

	cost = new Fl_Input(100, 25, 210, 25, "Price");
	cost->align(FL_ALIGN_LEFT);

	shipping= new Fl_Input(100, 25, 210, 25, "Shipping");
	shipping->align(FL_ALIGN_LEFT);

	tax= new Fl_Input(100, 25, 210, 25, "Tax");
	tax->align(FL_ALIGN_LEFT);

	Fl_Return_Button *order_confirm;
	order_confirm = new Fl_Return_Button(150, 610, 120, 25, "Confirm");
	order_confirm->callback((Fl_Callback *)create_order, 0);

	ordern->show();
	Fl::run();
}

void add_salesA(Fl_Widget* w, void* p)
{
	sawin->hide();
	string newc;
	newc = san->value();
	sas.push_back(newc);
	createwin->show();
}

void create_salesA(Fl_Widget* w, void* p)
{
	userwin->hide();
	sawin = new Fl_Window(600, 700, "Create Customer");

	san = new Fl_Input(100, 25, 210, 25, "Customer");
	san->align(FL_ALIGN_LEFT);

	Fl_Return_Button *sa_confirm;
	sa_confirm = new Fl_Return_Button(150, 610, 120, 25, "Confirm");
	sa_confirm->callback((Fl_Callback *)add_salesA, 0);

	sawin->end();
	sawin -> show();
}



void create_cust(Fl_Widget* w, void* p)
{
	custwin->hide();

	string newc;
	newc = customern->value();
	customers.push_back(newc);
	createwin->show();
}
void create_customer(Fl_Widget* w, void* p)
{
	userwin->hide();
	custwin = new Fl_Window(600, 700, "Create Customer");

	customern = new Fl_Input(100, 25, 210, 25, "Customer");
	customern->align(FL_ALIGN_LEFT);

	Fl_Return_Button *cust_confirm;
	cust_confirm = new Fl_Return_Button(150, 610, 120, 25, "Confirm");
	cust_confirm->callback((Fl_Callback *)create_cust, 0);

	custwin->end();
	custwin->show();
}


void user(Fl_Widget* w, void* p)
{
	createwin->hide();
	userwin = new Fl_Window(600, 400, "Create new User");
	Fl_Button customer(200, 100, 200, 30, "Customer");
	Fl_Button sac(200, 150, 200, 30, "Sales Associate");

	customer.callback(create_customer);
	sac.callback(create_salesA);

	userwin->end();
	userwin->show();
}

void create()
{
	createwin= new Fl_Window{ 600, 400, "Create" };
	Fl_Button parts(200, 50, 200, 30, "Robot Parts");
	Fl_Button models(200, 100, 200, 30, "Robot Models");
	Fl_Button order(200, 150, 200, 30, "Order");
	Fl_Button user(200, 200, 200, 30, "User");

	parts.callback(ropa_create);
	models.callback(rm_create);
	order.callback(order);
	user.callback(user);
	createwin->end();
	createwin->show();
	Fl::run();
}


#endif
