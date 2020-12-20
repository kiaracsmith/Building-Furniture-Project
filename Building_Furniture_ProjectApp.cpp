/***************************************************************
 * Name:      Building_Furniture_ProjectApp.cpp
 * Purpose:   Code for Application Class
 * Author:    JJ Maree ()
 * Created:   2020-12-11
 * Copyright: JJ Maree ()
 * License:
 **************************************************************/

#include "Building_Furniture_ProjectApp.h"


//(*AppHeaders
#include "Building_Furniture_ProjectMain.h"
#include <wx/image.h>

//*)

IMPLEMENT_APP(Building_Furniture_ProjectApp);

bool Building_Furniture_ProjectApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Building_Furniture_ProjectFrame* Frame = new Building_Furniture_ProjectFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
