#include "__gui__winmain.h"
#include "__mysql.h"
#include <wx/sizer.h>

__gui__winmain::__gui__winmain():__gui__frame("__PosSys")
{
    wxButton*p_button01=new wxButton(this,ID_BUTTON_DATA,wxT("Données"));     
    wxButton*p_button02=new wxButton(this,wxID_ANY,wxT("Vente"));     

    wxBoxSizer*h_vsizer=new wxBoxSizer(wxVERTICAL);
    h_vsizer->AddSpacer(GetCharHeight());
    h_vsizer->Add(p_button01);
    h_vsizer->AddSpacer(3);
    h_vsizer->Add(p_button02);
    h_vsizer->AddSpacer(GetCharHeight());

    wxBoxSizer*h_hsizer=new wxBoxSizer(wxHORIZONTAL);

    h_hsizer->AddSpacer(GetCharWidth());
    h_hsizer->Add(h_vsizer);
    h_hsizer->AddSpacer(GetCharWidth());

    SetSizerAndFit(h_hsizer);

	Connect(wxEVT_INIT_DIALOG,wxInitDialogEventHandler(__gui__winmain::OnInit));    	
	Connect(wxEVT_CLOSE_WINDOW,wxCommandEventHandler(__gui__winmain::OnQuit));    
    Connect(wxEVT_BUTTON,wxCommandEventHandler(__gui__winmain::OnButtonClick));
}
void __gui__winmain::OnButtonClick(wxCommandEvent&e)
{
    std::cout<<"__gui__winmain.cpp: In ‘__gui__winmain::OnButtonClick(wxCommandEvent&e)’\n";

    switch(e.GetId())
    {
        case ID_BUTTON_DATA:
            break;
        case ID_BUTTON_SALE:
            break;
    }

    e.Skip();
}
void __gui__winmain::OnInit(wxInitDialogEvent&e)
{
	std::cout<<"__gui__winmain.cpp: In ‘__gui__winmain::OnInit(wxInitDialogEvent&e)’\n";

    __mysql*h__mysql=new __mysql();
	//MYSQL*_h_mysql=__mysql::__connect();	
	if(h__mysql)
		h__mysql->__query("show databases");				
		//__mysql::__query(_h_mysql,"show databases");				


//	MYSQL*_h_mysql=__mysql::__connect();	
	//__mysql::__query(_h_mysql,"show databases");	

    Show(true);		
	e.Skip();				
}
void __gui__winmain::OnQuit(wxCommandEvent&e)
{
	std::cout<<"__gui__winmain.cpp: In ‘OnQuit(wxCloseEvent&e)’\n";
    e.Skip();
}
/*void __gui__appwin::OnEraseBackground(wxEraseEvent&event)
{
	wxDC*dc=event.GetDC();
	
	wxRect rc=wxRect(wxPoint(0,0),wxPoint(GetSize().x,GetSize().y));
	dc->SetBrush(wxBrush(wxColour(155,255,255)));
	dc->DrawRectangle(rc);

	wxBitmap bmp;
    bool b00=bmp.LoadFile(wxT("C:\\img\\texturedwhite.bmp"),wxBITMAP_TYPE_BMP);  
	if(b00)


	Draw::BackgroundPi(dc,rc,bmp,wxColour(170,185,245),GetCharHeight()*2,GetCharHeight());

	for(int id=ID_PANEL_DB;id<=ID_PANEL_MISC;id++)
		Draw::Shadow(event.GetDC(),GetWindowChild(id));
}*/
