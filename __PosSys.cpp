#include "__PosSys.h"
#include "__gui__winmain.h" 

wxIMPLEMENT_APP(__PosSys);

__PosSys::__PosSys()
{
    Connect(wxEVT_ACTIVATE_APP,wxInitDialogEventHandler(__PosSys::OnActivate));    	
}
bool __PosSys::OnInit()
{

//    connect(EVT_QUERY_END_SESSION
	//__event * evt = new __PosSys__event(__PosSys__event::ID_APP_INITALIZE);
	//__process(*evt);	
	

	return true;
}
bool __PosSys::ProcessEvent(wxEvent&e)
{
    switch(e.GetId())
    {
    }
    return EXIT_SUCCESS;
}
bool __PosSys::OnActivate(wxActivateEvent&evt)
{
    __gui__winmain*win_main;
	/*
	The MYSQL part*/
	
	/*__mysql*_p_mysql=new __mysql();					
	__event*_p_event=new __mysql__event(__mysql__event::ID_CONNECT);
	_p_mysql->__process(*_p_event);*/		

    //new CMySqlQuery("show databases");	
			
	/*
	The GUI part*/	
			
	win_main = new __gui__winmain();
	SetTopWindow(win_main);
	//win_main->Show(true);		
	win_main->InitDialog();
	evt.Skip();
    rerturn true;
}	
bool __PosSys::OnClose(wxEvent&evt)
{
    std::cout << "function :: bool __PosSys::__process(__event&e)\n\tMerci d'avoir utilisé __PosSys & bonne journée\n";				
    //win_main->Close();
    return evt.Skip();

}

