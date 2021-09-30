#include "__gui__frame.h"

__gui__frame::__gui__frame(std::string sz_title)
:
wxFrame((wxFrame *)NULL,wxID_ANY,sz_title.c_str(),wxDefaultPosition,wxSize(900,700),wxDEFAULT_FRAME_STYLE)
{
    //SetFont(wxFont(16,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL));    
	//Connect(wxEVT_ERASE_BACKGROUND,wxEraseEventHandler(__gui__frame::OnEraseBackground));	
    wxPanel* _p_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
    _p_panel->Bind(wxEVT_CHAR_HOOK, &__gui__frame::OnKeyDown, this);	
}
void __gui__frame::OnKeyDown(wxKeyEvent&e)
{
	//std::cout << "function :: __gui__frame::OnKeyDown(...)\n";    		    	
    switch(e.GetKeyCode())
    {
    	case '+':
    	case 'a':    	
		case WXK_NUMPAD_ENTER:
		case WXK_NUMPAD_ADD:		
    	{
			std::cout << "function :: __gui__frame::OnKeyDown(...)\n";    		    	
    		if(e.ControlDown())
    		{
				std::cout << "function :: __gui__frame::OnKeyDown(...)\n";    		
    		}
    	}
    	break;
    	case '-':
		case WXK_NUMPAD_SUBTRACT:		    	
    	{    	
    		if(e.ControlDown())
    		{
				std::cout << "function :: __gui__frame::OnKeyDown(...)\n";    		
    		}    	
    	}
    	break;
    }
    e.Skip();	    
}
void __gui__frame::OnEraseBackground(wxEraseEvent&evt)
{

}
