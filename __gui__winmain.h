/*___________________________________________________________________________
 Name:			
 Purpose:		    __PosSys's Main Window
 Implemetation:	
 Author:		    Boidron Thomas
 Modified by:
 Created:			
 Copyleft:		    (c)Boidron Thomas
 Licence:		    GNU
 TODO:			
______________________________________________________________________________*/
#include "__gui__frame.h"

class __gui__winmain:public __gui__frame
{
	public:
		__gui__winmain();
	private:
		virtual void OnInit(wxInitDialogEvent&);		
        virtual void OnButtonClick(wxCommandEvent&);
		virtual void OnQuit(wxCommandEvent&);		
    private:
        enum {ID_BUTTON_DATA=0xff,ID_BUTTON_SALE};

};



