#ifndef CREATE_PARTS_H
#define CREATE_PARTS_H

Fl_Input *ropa_name;
Fl_Input *ropa_part_number;
Fl_Input *ropa_type;
Fl_Input *ropa_weight;
Fl_Input *ropa_cost;
Fl_Input *ropa_descriptionription;
Fl_Input *ropa_maxspeed;
Fl_Input *ropa_power_con_loco;
Fl_Input *ropa_energy;
Fl_Input *ropa_max_power;
Fl_Input *ropa_battery_compartments;
Fl_Window *win;

Head* thead;
Locomotor* tloco;
Torso* ttorso;
Arm* tarm;
Battery* tbat;


vector<Locomotor*> locomotors;
vector<Arm*> arms;
vector<Battery*> batterys;
vector<Head*> heads;
vector<Torso*> torsos;


void savehead(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << ropa_name->value() << endl;
	cout << "Part Number " << ropa_part_number->value() << endl;
	cout << "Weight " << ropa_weight->value() << endl;
	cout << "Cost " << ropa_cost->value() << endl;
	cout << "descriptionription " << ropa_descriptionription->value() << endl;


	thead->name = ropa_name->value();
	thead->cost = stod(ropa_cost->value());
	thead->description = ropa_descriptionription->value();
	thead->part_num = stoi(ropa_part_number->value());
	thead->type = "head";
	thead->weight = stod(ropa_weight->value());

	heads.push_back(thead);

}

void savetorso(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << ropa_name->value() << endl;
	cout << "Part Number " << ropa_part_number->value() << endl;
	cout << "Weight " << ropa_weight->value() << endl;
	cout << "Cost " << ropa_cost->value() << endl;
	cout << "descriptionription " << ropa_descriptionription->value() << endl;
	cout << "Battery Compartments " << ropa_battery_compartments->value() << endl;


	ttorso->name = ropa_name->value();
	ttorso->cost = stod(ropa_cost->value());
	ttorso->description = ropa_descriptionription->value();
	ttorso->part_num = stoi(ropa_part_number->value());
	ttorso->type = "torso";
	ttorso->weight = stod(ropa_weight->value());
	ttorso->battery_compartments = stoi(ropa_battery_compartments->value());

	heads.push_back(thead);
}

void savebattery(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << ropa_name->value() << endl;
	cout << "Energy " << ropa_energy->value() << endl;
	cout << "Max Power " << ropa_max_power->value() << endl;
	cout << "Part Number " << ropa_part_number->value() << endl;
	cout << "Weight " << ropa_weight->value() << endl;
	cout << "Cost " << ropa_cost->value() << endl;
	cout << "descriptionription " << ropa_descriptionription->value() << endl;


	tbat->name = ropa_name->value();
	tbat->cost = stod(ropa_cost->value());
	tbat->description = ropa_descriptionription->value();
	tbat->maxPower = stoi(ropa_max_power->value());
	tbat->energy = stoi(ropa_energy->value());
	tbat->part_num = stoi(ropa_part_number->value());
	tbat->type = "battery";
	tbat->weight = stod(ropa_weight->value());

	batterys.push_back(tbat);

	
}

void savearm(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << ropa_name->value()<<endl;
	cout << "Power " << ropa_power_con_loco->value()<<endl;
	cout << "Part Number " << ropa_part_number->value()<<endl;
	cout << "Weight " << ropa_weight->value() << endl;
	cout << "Cost " << ropa_cost->value() << endl;
	cout << "descriptionription " << ropa_descriptionription->value() << endl;

	
	tarm->name = ropa_name->value();
	tarm->cost = stod(ropa_cost->value());
	tarm->description = ropa_descriptionription->value();
	tarm->power_con = stoi(ropa_power_con_loco->value());
	tarm->part_num = stoi(ropa_part_number->value());
	tarm->type = "arm";
	tarm->weight = stod(ropa_weight->value());

	arms.push_back(tarm);

}


void savelocomotor(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << ropa_name->value();
	cout << "Power " << ropa_power_con_loco->value();
	cout << " Speed " << ropa_maxspeed->value();
	cout << "Part Number " << ropa_part_number->value();
	cout << "Weight " << ropa_weight->value();
	cout << "Cost " << ropa_cost->value();
	cout << "descriptionription " << ropa_descriptionription->value();

	
	tloco->name = ropa_name->value();
	tloco->cost = stod(ropa_cost->value());
	tloco->description = ropa_descriptionription->value();
	tloco->max_speed = stoi(ropa_maxspeed -> value());
	tloco->power_conloco = stoi(ropa_power_con_loco->value());
	tloco->part_num = stoi(ropa_part_number->value());
	tloco->type = "locomotor";
	tloco->weight = stod(ropa_weight->value());

	locomotors.push_back(tloco);
	
}


void create_torso(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 480,430, "Torso" };

	ropa_name = new Fl_Input(150, 40, 210, 25, "Name");
	ropa_name->align(FL_ALIGN_LEFT);

	ropa_battery_compartments = new Fl_Input(150, 70, 210, 25, "Number of Batteries(1-3)");
	ropa_battery_compartments->align(FL_ALIGN_LEFT);

	ropa_part_number = new Fl_Input(150, 180, 210, 25, "Part Number");
	ropa_part_number->align(FL_ALIGN_LEFT);

	ropa_weight = new Fl_Input(150, 220, 210, 25, "Weight");
	ropa_weight->align(FL_ALIGN_LEFT);

	ropa_cost = new Fl_Input(150, 260, 210, 25, "Cost");
	ropa_cost->align(FL_ALIGN_LEFT);

	ropa_descriptionription = new Fl_Input(150, 300, 210, 25, "descriptionription");
	ropa_descriptionription->align(FL_ALIGN_LEFT);

	Fl_Button *ropa_confirm;
	ropa_confirm = new Fl_Button(180, 340, 120, 25, "Confirm");
	ropa_confirm->callback((Fl_Callback *)savetorso, 0);

	win->show();
	Fl::run();

}

void create_locomotor(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 600, 400, "Locomotor" };

	ropa_name = new Fl_Input(130, 40, 210, 25, "Name");
	ropa_name->align(FL_ALIGN_LEFT);

	ropa_power_con_loco = new Fl_Input(130, 70, 210, 25, "Power");
	ropa_power_con_loco->align(FL_ALIGN_LEFT);

	ropa_maxspeed = new Fl_Input(130, 100, 210, 25, "Max Speed(Mph)");
	ropa_maxspeed->align(FL_ALIGN_LEFT);

	ropa_part_number = new Fl_Input(130, 140, 210, 25, "Part Number");
	ropa_part_number->align(FL_ALIGN_LEFT);

	ropa_weight = new Fl_Input(130, 180, 210, 25, "Weight");
	ropa_weight->align(FL_ALIGN_LEFT);

	ropa_cost = new Fl_Input(130, 220, 210, 25, "Cost");
	ropa_cost->align(FL_ALIGN_LEFT);

	ropa_descriptionription = new Fl_Input(130, 260, 210, 25, "descriptionription");
	ropa_descriptionription->align(FL_ALIGN_LEFT);

	Fl_Button *ropa_confirm;
	ropa_confirm = new Fl_Button(150, 300, 120, 25, "Confirm");
	ropa_confirm->callback((Fl_Callback *)savelocomotor, 0);

	win->show();
	Fl::run();
}

void create_arm(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 600, 400, "Arm" };

	ropa_name = new Fl_Input(130, 40, 210, 25, "Name");
	ropa_name->align(FL_ALIGN_LEFT);

	ropa_power_con_loco = new Fl_Input(130, 70, 210, 25, "Power Consumption");
	ropa_power_con_loco->align(FL_ALIGN_LEFT);

	ropa_part_number = new Fl_Input(130, 140, 210, 25, "Part Number");
	ropa_part_number->align(FL_ALIGN_LEFT);

	ropa_weight = new Fl_Input(130, 180, 210, 25, "Weight");
	ropa_weight->align(FL_ALIGN_LEFT);

	ropa_cost = new Fl_Input(130, 220, 210, 25, "Cost");
	ropa_cost->align(FL_ALIGN_LEFT);

	ropa_descriptionription = new Fl_Input(130, 260, 210, 25, "descriptionription");
	ropa_descriptionription->align(FL_ALIGN_LEFT);

	Fl_Button *ropa_confirm;
	ropa_confirm = new Fl_Button(150, 300, 120, 25, "Confirm");
	ropa_confirm->callback((Fl_Callback *)savearm, 0);

	win->show();
	Fl::run();

}

void create_battery(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 600, 400, "Battery" };

	ropa_name = new Fl_Input(130, 40, 210, 25, "Name");
	ropa_name->align(FL_ALIGN_LEFT);

	ropa_energy = new Fl_Input(130, 70, 210, 25, "Energy");
	ropa_power_con_loco->align(FL_ALIGN_LEFT);

	ropa_power_con_loco = new Fl_Input(130, 70, 210, 25, "Max Power");
	ropa_max_power->align(FL_ALIGN_LEFT);

	ropa_part_number = new Fl_Input(130, 140, 210, 25, "Part Number");
	ropa_part_number->align(FL_ALIGN_LEFT);

	ropa_weight = new Fl_Input(130, 180, 210, 25, "Weight");
	ropa_weight->align(FL_ALIGN_LEFT);

	ropa_cost = new Fl_Input(130, 220, 210, 25, "Cost");
	ropa_cost->align(FL_ALIGN_LEFT);

	ropa_descriptionription = new Fl_Input(130, 260, 210, 25, "descriptionription");
	ropa_descriptionription->align(FL_ALIGN_LEFT);

	Fl_Button *ropa_confirm;
	ropa_confirm = new Fl_Button(150, 300, 120, 25, "Confirm");
	ropa_confirm->callback((Fl_Callback *)savebattery, 0);

	win->show();
	Fl::run();

}

void create_head(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 600, 400, "Head" };

	ropa_name = new Fl_Input(130, 40, 210, 25, "Name");
	ropa_name->align(FL_ALIGN_LEFT);

	ropa_part_number = new Fl_Input(130, 140, 210, 25, "Part Number");
	ropa_part_number->align(FL_ALIGN_LEFT);

	ropa_weight = new Fl_Input(130, 180, 210, 25, "Weight");
	ropa_weight->align(FL_ALIGN_LEFT);

	ropa_cost = new Fl_Input(130, 220, 210, 25, "Cost");
	ropa_cost->align(FL_ALIGN_LEFT);

	ropa_descriptionription = new Fl_Input(130, 260, 210, 25, "descriptionription");
	ropa_descriptionription->align(FL_ALIGN_LEFT);

	Fl_Button *ropa_confirm;
	ropa_confirm = new Fl_Button(150, 300, 120, 25, "Confirm");
	ropa_confirm->callback((Fl_Callback *)savehead, 0);

	win->show();
	Fl::run();
}

#endif // !CREATE_PARTS_H
