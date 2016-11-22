#include <Fl/Fl.H>                     
#include <Fl/Fl_Window.H>      
#include <FL/Fl_Button.H>   
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
#include <stdio.h> 
#include "parts.h"
#include "create.h"
Fl_Window *win;

void create(Fl_Widget*w, void* p)
{

	win->hide();
	create();
}
void view(Fl_Widget*w, void* p)
{
//In progress
}

int main()
{
	win = new Fl_Window{ 600, 400, "Robbie robott Shop" };
	Fl_Button createn(200, 50, 200, 30, "Create");
	Fl_Button viewn(200, 100, 200, 30, "View");

	createn.callback(create);
	viewn.callback(view);
	win->end();
	win->show();

	return(Fl::run());
}
