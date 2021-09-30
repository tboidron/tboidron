/*___________________________________________________________________________
 Name:			
 Purpose:		    __PosSys's base window.
 					Rajouter les fonctionnalités suivantes à wxFrame:
 						-Raccourci clavier: Ctrl + '+' ==> Augmente la taille de la police.
 						-Raccourci clavier: Ctrl + '-' ==> Diminue la taille de la police.  						
 Implemetation:		Pour que wxFrame puisse recevoir des évènements il faut lui ajouter un wxPanel.
 Author:		    Boidron Thomas
 Modified by:
 Created:			
 Copyleft:		    (c)Boidron Thomas
 Licence:		    GNU
 TODO:			
______________________________________________________________________________*/
#include <wx/wx.h>
#include <string>
#include <wx/event.h>

class __gui__frame:public wxFrame
{
	public:
		__gui__frame(std::string);
	private:
		virtual void OnKeyDown(wxKeyEvent&);
		virtual void OnEraseBackground(wxEraseEvent&);		
};
