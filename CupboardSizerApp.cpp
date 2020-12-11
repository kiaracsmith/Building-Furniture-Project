/***************************************************************
 * Name:      CupboardSizerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    JJ Maree ()
 * Created:   2020-12-11
 * Copyright: JJ Maree ()
 * License:
 **************************************************************/

#include "CupboardSizerApp.h"

//(*AppHeaders
#include "CupboardSizerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CupboardSizerApp);

bool CupboardSizerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	CupboardSizerFrame* Frame = new CupboardSizerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
