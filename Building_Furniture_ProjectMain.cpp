/***************************************************************
 * Name:      Building_Furniture_ProjectMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    JJ Maree ()
 * Created:   2020-12-11
 * Copyright: JJ Maree ()
 * License:
 **************************************************************/

#include "Building_Furniture_ProjectMain.h"
#include <wx/msgdlg.h>
#include <string>
#include <iostream>
#include "UnitClasses.h"
#include "sqlite/sqlite3.h"
using namespace std;

//(*InternalHeaders(Building_Furniture_ProjectFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f,
    long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
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

//(*IdInit(Building_Furniture_ProjectFrame)
const long Building_Furniture_ProjectFrame::ID_STATICBOX3 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_STATICBOX1 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_BUTTON1 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_STATICTEXT1 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_CHOICE1 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_CHOICE2 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_STATICTEXT2 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_STATICBOX2 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_STATICTEXT3 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_STATICTEXT4 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_SPINCTRL1 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_SPINCTRL2 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_SPINCTRL3 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_STATICTEXT5 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_STATICLINE1 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_BUTTON2 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_BUTTON3 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_BUTTON4 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_LISTBOX1 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_BUTTON5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Building_Furniture_ProjectFrame, wxFrame)
//(*EventTable(Building_Furniture_ProjectFrame)
//*)
END_EVENT_TABLE()

/*
=================================================================================
                                Handler Functions
=================================================================================
*/

Building_Furniture_ProjectFrame::Building_Furniture_ProjectFrame(wxWindow *parent, wxWindowID id)
{
    //(*Initialize(Building_Furniture_ProjectFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE | wxRESIZE_BORDER | wxMAXIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(552, 312));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StaticBox3 = new wxStaticBox(this, ID_STATICBOX3, _("Preview"), wxPoint(280, 8), wxSize(256, 264), 0, _T("ID_STATICBOX3"));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Design"), wxPoint(8, 8), wxSize(256, 96), 0, _T("ID_STATICBOX1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Submit"), wxPoint(8, 280), wxSize(256, 23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->Disable();
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Unit"), wxPoint(24, 40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(72, 32), wxSize(170, 23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("Floor Unit"));
    Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(72, 64), wxSize(170, 23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Type"), wxPoint(24, 72), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Dimensions [mm]"), wxPoint(8, 120), wxSize(256, 152), 0, _T("ID_STATICBOX2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Width"), wxPoint(24, 152), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Height"), wxPoint(24, 184), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("500"), wxPoint(72, 144), wxSize(170, 23), 0, 0, 10000, 500, _T("ID_SPINCTRL1"));
    SpinCtrl1->SetValue(_T("500"));
    SpinCtrl2 = new wxSpinCtrl(this, ID_SPINCTRL2, _T("700"), wxPoint(72, 176), wxSize(170, 23), 0, 0, 10000, 700, _T("ID_SPINCTRL2"));
    SpinCtrl2->SetValue(_T("700"));
    SpinCtrl3 = new wxSpinCtrl(this, ID_SPINCTRL3, _T("560"), wxPoint(72, 208), wxSize(170, 23), 0, 0, 10000, 560, _T("ID_SPINCTRL3"));
    SpinCtrl3->SetValue(_T("560"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Depth"), wxPoint(24, 216), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(272, 8), wxSize(-1, 290), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Cutting List"), wxPoint(288, 280), wxSize(248, 23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Save Session"), wxPoint(296, 232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button4 = new wxButton(this, ID_BUTTON4, _("Clear"), wxPoint(400, 232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxPoint(296, 32), wxSize(224, 192), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    Button5 = new wxButton(this, ID_BUTTON5, _("-"), wxPoint(488, 232), wxSize(32, 23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    createDB(dir);
    createTable(dir);
    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnButton1Click);
    Connect(ID_CHOICE1, wxEVT_COMMAND_CHOICE_SELECTED, (wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnChoice1Select);
    Connect(ID_SPINCTRL1, wxEVT_COMMAND_SPINCTRL_UPDATED, (wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnSpinCtrl1Change);
    Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnButton4Click);
    Connect(wxID_ANY, wxEVT_CLOSE_WINDOW, (wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnClose);
    //*)
}

Building_Furniture_ProjectFrame::~Building_Furniture_ProjectFrame()
{
    //(*Destroy(Building_Furniture_ProjectFrame)
    //*)
}

void Building_Furniture_ProjectFrame::OnQuit(wxCommandEvent &event)
{
    Close();
}

void Building_Furniture_ProjectFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Building_Furniture_ProjectFrame::OnClose(wxCloseEvent &event)
{
}

void Building_Furniture_ProjectFrame::OnSpinCtrl1Change(wxSpinEvent &event)
{
}

void Building_Furniture_ProjectFrame::OnButton1Click(wxCommandEvent &event)
{
    //Dimensions
    int H = SpinCtrl1->GetValue();
    int W = SpinCtrl2->GetValue();
    int D = SpinCtrl3->GetValue();
    int t = 16;
    int qty = 1;
    std::string col = "White";

    if (!(H && W && D))
    {
        wxMessageBox("Failure to evaluate dimensions. Try increasing values.", _("Error"));
        return;
    }

    int UnitSelect = Choice1->GetSelection();
    int UnitType = Choice2->GetSelection();

    if ((UnitType > -1) && (UnitType < 6))
    {
        FloorUnit(1000, 750, 560, 16, "White", 1, 0);
        ListBox1->Append("Test");
    }
}

void Building_Furniture_ProjectFrame::OnChoice1Select(wxCommandEvent &event)
{
    int MasterChoice = Choice1->GetSelection();
    Button1->Enable();
    Choice2->Clear();
    switch (MasterChoice)
    {
    case 0: //Floor Unit
    {
        Choice2->SetSelection(Choice2->Append(_("1) No Draws")));
        Choice2->Append("2) Two Draws - 2 Equal Sizes");
        Choice2->Append("3) Three Draws - 3 Equal Sizes");
        Choice2->Append("4) Three Draws - 2 Equal Sizes");
        Choice2->Append("5) Three Draws - 0 Equal Sizes");
        Choice2->Append("6) Four Draws - 4 Equal Sizes");
        break;
    }
    default:
    {
        break;
    }
    }
}

void Building_Furniture_ProjectFrame::OnButton4Click(wxCommandEvent &event)
{
    ListBox1->Clear();
}

/*
=================================================================================
                                Functions
=================================================================================
*/

void FloorUnit(int W, int H, int D, int t, std::string color, int n, int drawOpt)
{
    int x = 0, y = 0, z = 0;
    int grvBacking = 6;
    int doorLim = 550;
    int doorQty = 1;
    int grvRunner = 14;

    //Base Analysis
    x = W - t * 2;
    y = D;
    BOARD BASE(x, y, t, color, n * 1);

    //Side Analysis
    x = D;
    y = H;
    BOARD SIDE(x, y, t, color, n * 2);

    //Support Analysis
    x = W - t * 2;
    y = 100;
    BOARD SUPPORT(x, y, t, color, n * 2);

    //Backing Analysis
    x = W - (t - grvBacking) * 2;
    y = H - (t - grvBacking);
    BOARD BACKING(x, y, t, color, n * 2);

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
    BOARD DOOR(x, y, t, color, doorQty * n);

    //Shelf Analysis
    x = W - t * 2;
    y = D - (t - grvBacking - 5) * 2;
    BOARD SHELF(x, y, t, color, n * 1);
    switch (drawOpt)
    {
    case 0:
        //No Draw
        {
            break;
        }
    case 1:
        //Two Draws     | 2 Equal Size
        {
            break;
        }
    case 2:
        //Three Draws   | 3 Equal Size
        {
            break;
        }
    case 3:
        //Three Draws   | 2 Equal Size
        {
            break;
        }
    case 4:
        //Three Draws   | 0 Equal Size
        {
            break;
        }
    case 5:
        //Four Draws    |  4 Equal Size
        {
            break;
        }
    default:
    {
        break;
    }
    }

    BoardPrint("SIDE", SIDE);
    BoardPrint("BASE", BASE);
    BoardPrint("SIDE", SUPPORT);
    BoardPrint("BACKING", BACKING);
    BoardPrint("DOOR", DOOR);
    BoardPrint("SHELF", SHELF);
}

void BoardPrint(std::string NAME, BOARD A)
{
    std::cout << NAME << "\t" << A.L << "\t" << A.W << "\t" << A.amount << "\n";
}

/*
=================================================================================
                                Database Handles
=================================================================================
*/
static int createDB(const char *s)
{
    sqlite3 *DB;
    int exit = 0;
    exit = sqlite3_open(s, &DB);
    sqlite3_close(DB);
    return 0;
}

static int createTable(const char *s)
{
    sqlite3 *DB;
    std::string sql = "CREATE TABLE IF NOT EXIST UNITS(ID integer PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL);";
    try
    {
        int exit = 0;
        char *messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK)
        {
            cerr << "Error Creating Table" << endl;
            sqlite3_close(DB);
        }
    }
    catch (const exception &e)
    {
        cerr << e.what();
    }
    sql = "CREATE TABLE IF NOT EXIST BOARDS(ID INTEGER PRIMARY KEY AUTOINCREMENT, DESC TEXT NOT NULL, LENGTH REAL NOT NULL, WIDTH REAL NOT NULL, THICKNESS REAL NOT NULL, COLOR TEXT NOT NULL, QUANTITY INT NOT NULL);";
    try
    {
        int exit = 0;
        char *messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK)
        {
            cerr << "Error Creating Table" << endl;
            sqlite3_close(DB);
        }
    }
    catch (const exception &e)
    {
        cerr << e.what();
    }
    return 0;
}

static int insertData(const char *s)
{
    sqlite3 *DB;
    int exit = 0;
    exit = sqlite3_open(s, &DB);
    sqlite3_close(DB);
    return 0;
}

static int selectUnits(const char *s)
{
    sqlite3 *DB;
    int exit = sqlite3_open(s, &DB);
    std::string sql = "SELECT * FROM UNITS;";

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
    return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        cout << azColName[i] << "\t" << argv[i] << endl;
    }
    cout << endl;
    return 0;
}

/*
=================================================================================
                                Other
=================================================================================
*/
