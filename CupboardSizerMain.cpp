/***************************************************************
 * Name:      CupboardSizerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    JJ Maree ()
 * Created:   2020-12-11
 * Copyright: JJ Maree ()
 * License:
 **************************************************************/

#include "CupboardSizerMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(CupboardSizerFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(CupboardSizerFrame)
const long CupboardSizerFrame::ID_BUTTON1 = wxNewId();
const long CupboardSizerFrame::ID_TEXTCTRL1 = wxNewId();
const long CupboardSizerFrame::ID_TEXTCTRL2 = wxNewId();
const long CupboardSizerFrame::ID_TEXTCTRL3 = wxNewId();
const long CupboardSizerFrame::ID_STATICTEXT1 = wxNewId();
const long CupboardSizerFrame::ID_STATICTEXT2 = wxNewId();
const long CupboardSizerFrame::ID_STATICTEXT3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CupboardSizerFrame,wxFrame)
    //(*EventTable(CupboardSizerFrame)
    //*)
END_EVENT_TABLE()

CupboardSizerFrame::CupboardSizerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(CupboardSizerFrame)
    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(195,229));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRADIENTACTIVECAPTION));
    Button1 = new wxButton(this, ID_BUTTON1, _("Submit"), wxPoint(64,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(64,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(64,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(64,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Length"), wxPoint(16,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Width"), wxPoint(16,88), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Depth"), wxPoint(16,136), wxDefaultSize, 0, _T("ID_STATICTEXT3"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CupboardSizerFrame::OnButton1Click);
    //*)
}

CupboardSizerFrame::~CupboardSizerFrame()
{
    //(*Destroy(CupboardSizerFrame)
    //*)
}

void CupboardSizerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CupboardSizerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void CupboardSizerFrame::OnButton1Click(wxCommandEvent& event)
{
    wxString L = this->WxEdit1->GetValue();
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BOARD
{
public:
    uint16_t L, W, t;
    string material;
    uint16_t amount;
    /*
        Title: Board Constructor
        Input(s):
        y - Board Dimension (1)
        x - Board Dimension (2)
        z - Board Thickness
        color - Material Color
        qty  - Board Quantity

        Output(s):
        None
        */
    BOARD(int y, int x, int z = 16, string color = "White", int qty = 1)
    {
        L = (y < x) ? x : y;
        W = (y > x) ? x : y;
        t = z;
        material = color;
        amount = qty;
    }
};



/*
Title: product
Description: This file contains the calculations for all different developed products.
Updated: 04-12-2020
Author(s):
    - (Mr.)  JJ Maree [BEng]
    - (Mrs.) K Smith  [BSc]
--------------------------------------------------------------------------------------
*/

/*
Title: Floor Unit
Author: JJ Maree
Updated: 04-12-2020
--------------------------------------------------------------------------------------
Input(s):
W - Floor Unit Width
H - Floor Unit Height (Typically 750)
D - Floor Unit Depth (Typically 560)
t - Board Thickness (Typically 16)
color - Board Material (Typically White)

Output(s):
Unknown
*/
void FloorUnit(int W, int H = 750, int D = 560, int t = 16, string color = "White", int drawOpt = 0)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int grvBacking = 6;
    int doorLim = 550;
    int doorQty = 1;
    int grvRunner = 14;

    //Side Analysis
    x = D;
    y = H;
    BOARD SIDE(x, y, t, "White", 2);

    //Base Analysis
    x = W - t * 2;
    y = D;
    BOARD BASE(x, y, t, "White", 1);

    //Support Analysis
    x = W - t * 2;
    y = 100;
    BOARD SUPPORT(x, y, t, "White", 2);

    //Backing Analysis

    x = W - (t - grvBacking) * 2;
    y = H - (t - grvBacking);
    BOARD BACKING(x, y, t, "White", 2);

    //Door Analysis
    x = H - 5;
    if (W > doorLim)
    {
        y = (W - 8) / 2;
        doorQty = 2;
    }
    else
    {
        y = W - 3;
        doorQty = 1;
    }
    BOARD DOOR(x, y, t, "White", doorQty);

    //Shelf Analysis
    x = W - t * 2;
    y = D - (t - grvBacking - 5) * 2;
    BOARD SHELF(x, y, t, "White", 1);

    switch (drawOpt)
    {
    case 0:
        //No Draw
        break;
    case 1:
        //Two Draws     | 2 Equal Size
        break;
    case 2:
        //Three Draws   | 3 Equal Size
        break;
    case 3:
        //Three Draws   | 2 Equal Size
        break;
    case 4:
        //Three Draws   | 0 Equal Size
        break;
    case 5:
        //Four Draws    |  4 Equal Size
        break;
    default:
        break;
    }

    //Printout

    cout << "Board\t\tL\tW\tt\tQTY" << endl;
    cout << "Side:\t\t" << SIDE.L << "\t" << SIDE.W << "\t" << SIDE.t << "\t" << SIDE.amount << endl;
    cout << "Base:\t\t" << BASE.L << "\t" << BASE.W << "\t" << BASE.t << "\t" << BASE.amount << endl;
    cout << "Support:\t" << SUPPORT.L << "\t" << SUPPORT.W << "\t" << SUPPORT.t << "\t" << SUPPORT.amount << endl;
    cout << "Backing:\t" << BACKING.L << "\t" << BACKING.W << "\t" << BACKING.t << "\t" << BACKING.amount << endl;
    cout << "Door:\t\t" << DOOR.L << "\t" << DOOR.W << "\t" << DOOR.t << "\t" << DOOR.amount << endl;
    cout << "Shelf:\t\t" << SHELF.L << "\t" << SHELF.W << "\t" << SHELF.t << "\t" << SHELF.amount << endl;
}





int main()
{
    int H = 750;
    int W = 500;
    int D = 560;
    int t = 16;

    FloorUnit(W, H, D, t, "White", 0);

    return 0;
}

