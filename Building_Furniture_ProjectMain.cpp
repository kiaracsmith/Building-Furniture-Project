/***************************************************************
 * Name:      Building_Furniture_ProjectMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    JJ Maree ()
 * Created:   2020-12-11
 * Copyright: JJ Maree ()
 * License:
 **************************************************************/

#include <wx/msgdlg.h>
#include <string>
#include <iostream>
#include "sqlite/sqlite3.h"
#include "Building_Furniture_ProjectMain.h"
#include "CuttingListFrame.h"
#include "Constants.h"

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
const long Building_Furniture_ProjectFrame::ID_BUTTON4 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_BUTTON5 = wxNewId();
const long Building_Furniture_ProjectFrame::ID_LISTVIEW1 = wxNewId();
//*)
PREV PreviewWindow;

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
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(767,312));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StaticBox3 = new wxStaticBox(this, ID_STATICBOX3, _("Preview"), wxPoint(280,8), wxSize(480,264), 0, _T("ID_STATICBOX3"));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Design"), wxPoint(8,8), wxSize(256,96), 0, _T("ID_STATICBOX1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Submit"), wxPoint(8,280), wxSize(256,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->Disable();
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Unit"), wxPoint(24,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(72,32), wxSize(170,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("Floor Unit"));
    Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(72,64), wxSize(170,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Type"), wxPoint(24,72), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Dimensions [mm]"), wxPoint(8,120), wxSize(256,152), 0, _T("ID_STATICBOX2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Width"), wxPoint(24,152), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Height"), wxPoint(24,184), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("500"), wxPoint(72,144), wxSize(170,23), 0, 0, 10000, 500, _T("ID_SPINCTRL1"));
    SpinCtrl1->SetValue(_T("500"));
    SpinCtrl2 = new wxSpinCtrl(this, ID_SPINCTRL2, _T("700"), wxPoint(72,176), wxSize(170,23), 0, 0, 10000, 700, _T("ID_SPINCTRL2"));
    SpinCtrl2->SetValue(_T("700"));
    SpinCtrl3 = new wxSpinCtrl(this, ID_SPINCTRL3, _T("560"), wxPoint(72,208), wxSize(170,23), 0, 0, 10000, 560, _T("ID_SPINCTRL3"));
    SpinCtrl3->SetValue(_T("560"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Depth"), wxPoint(24,216), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(272,8), wxSize(-1,290), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Show Cutting List"), wxPoint(280,280), wxSize(248,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button4 = new wxButton(this, ID_BUTTON4, _("Clear"), wxPoint(624,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button5 = new wxButton(this, ID_BUTTON5, _("Remove"), wxPoint(544,280), wxSize(64,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    ListView1 = new wxListView(this, ID_LISTVIEW1, wxPoint(296,32), wxSize(450,224), wxLC_REPORT|wxLC_ALIGN_LEFT|wxVSCROLL|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_LISTVIEW1"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnButton1Click);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnChoice1Select);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnSpinCtrl1Change);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnButton2Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnButton5Click);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Building_Furniture_ProjectFrame::OnClose);
    //*)


    ListView1->InsertColumn(0, _("Description"), 0, 280);
    ListView1->InsertColumn(1, _("Width"), 0, 50);
    ListView1->InsertColumn(2, _("Depth"), 0, 50);
    ListView1->InsertColumn(3, _("Height"), 0, 50);

    //Function Initiation
    createDB();
    createTable();
    PreviewWindow.AddNode("First", 0, 0, 0);
    ListUpdate();
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

/*
    Description: Add to List Button
    */
void Building_Furniture_ProjectFrame::OnButton1Click(wxCommandEvent &event)
{

    // Valiables
    // - Dimensions
    int H = SpinCtrl1->GetValue();
    int W = SpinCtrl2->GetValue();
    int D = SpinCtrl3->GetValue();
    int t = 16;

    std::string color = "White";

    // - Command Definition
    std::string ID = "";

    int UnitSelect = (int)Choice1->GetSelection();
    int UnitType = (int)Choice2->GetSelection();

    if (!(H && W && D))
    {
        wxMessageBox("Failure to evaluate dimensions. Try increasing values.", _("Error"));
        return;
    }

    switch (UnitSelect)
    {
    case 0:
    {
        //Floor Unit
        ID = FloorUnit(W, H, D, t, color, 1, UnitType);
        break;
    }
    default:
        break;
    }
    ListUpdate();
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

/*
    Description: Remove All Button
    */
void Building_Furniture_ProjectFrame::OnButton4Click(wxCommandEvent &event)
{
    // Variable Initilization
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    const char *data = "Callback function called";

    // Open Database
    rc = sqlite3_open(DBLoc, &db);
    if (rc)
    {
        std::cout << zErrMsg << std::endl;
        return;
    }
    sql = "DELETE from 'UNITS'; ";
    rc = sqlite3_exec(db, sql.c_str(), callback, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cout << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    sql = "DELETE from 'CUTTINGLIST'; ";
    rc = sqlite3_exec(db, sql.c_str(), callback, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cout << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    ListUpdate();
}

void Building_Furniture_ProjectFrame::OnListBox1Select(wxCommandEvent &event)
{
}

void Building_Furniture_ProjectFrame::OnButton5Click(wxCommandEvent &event)
{
    int Choice = ListView1->GetFocusedItem();
    ListView1->DeleteItem(Choice);
}
/*
=================================================================================
                                Unit Functions
=================================================================================
*/

std::string FloorUnit(float W, float H, float D, int t, std::string color, int n, int drawOpt)
{
    int x = 0, y = 0;
    int grvBacking = 6;
    int doorLim = 550;
    int doorQty = 1;

    std::string NAME = "Floor Unit - ";
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
            NAME.append("No Draws");
            break;
        }
    case 1:
        //Two Draws     | 2 Equal Size
        {
            NAME.append("Two Draws (2 Equal Sizes)");
            break;
        }
    case 2:
        //Three Draws   | 3 Equal Size
        {
            NAME.append("Three Draws (3 Equal Sizes)");
            break;
        }
    case 3:
        //Three Draws   | 2 Equal Size
        {
            NAME.append("Three Draws (2 Equal Sizes)");
            break;
        }
    case 4:
        //Three Draws   | 0 Equal Size
        {
            NAME.append("Three Draws (0 Equal Sizes)");
            break;
        }
    case 5:
        //Four Draws    |  4 Equal Size
        {
            NAME.append("Four Draws (4 Equal Sizes)");
            break;
        }
    default:
    {
        break;
    }
    }

    StoreUnit(NAME, W, H, D, color, n);
    StoreBoard(NAME, "SIDE", SIDE);
    StoreBoard(NAME, "BASE", BASE);
    StoreBoard(NAME, "SIDE", SUPPORT);
    StoreBoard(NAME, "BACKING", BACKING);
    StoreBoard(NAME, "DOOR", DOOR);
    StoreBoard(NAME, "SHELF", SHELF);
    return NAME;
}

/*
=================================================================================
                                Database Handles
=================================================================================
*/

/*
Description:    Creates Database
Input(s):       Database file directory
Return:         0
*/
static int createDB()
{
    sqlite3 *db;
    sqlite3_open(DBLoc, &db);
    sqlite3_close(db);
    return 0;
}

/*
Description:    Creates Tables
Input(s):       Database file directory
Return:         0
*/
static int createTable()
{
    // Variable Initilization
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;

    // Open Database
    rc = sqlite3_open(DBLoc, &db);
    if (rc)
    {
        std::cout << zErrMsg << std::endl;
        return (0);
    }

    // Create Units Table
    sql = "CREATE TABLE UNITS("
          "ID INTEGER PRIMARY KEY     NOT NULL,"
          "DESC           TEXT    NOT NULL,"
          "LENGTH         REAL     NOT NULL,"
          "HEIGHT         REAL     NOT NULL,"
          "DEPTH          REAL     NOT NULL,"
          "COLOR          TEXT     NOT NULL,"
          "QUANTITY       INTEGER  NOT NULL );";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cout << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    // Create Cutting List Table
    sql = "CREATE TABLE CUTTINGLIST("
          "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
          "COLOR                             TEXT    NOT NULL,"
          "DESC                             TEXT    NOT NULL,"
          "PART                             TEXT    NOT NULL,"
          "LENGTH                           REAL     NOT NULL,"
          "WIDTH                            REAL     NOT NULL,"
          "THICKNESS                        REAL     NOT NULL,"
          "QUANTITY                         INTEGER  NOT NULL );";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cout << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    // Close Database
    sqlite3_close(db);
    return 0;
}

/*
    Description:    Adds board dimensions to cutting list database
    Input(s):       Unit Description, Overall Length, Overall Width, Overall Depth, Color, Quantity
    Return:         None
*/
void StoreBoard(std::string DESC, std::string PART, BOARD A)
{
    sqlite3 *db;
    int rc;
    char *zErrMsg = 0;

    // Open Database
    rc = sqlite3_open(DBLoc, &db);
    if (rc)
    {
        std::cout << zErrMsg << std::endl;
        return;
    }
    std::string sql = "INSERT INTO CUTTINGLIST (DESC, PART, LENGTH, WIDTH, THICKNESS, QUANTITY, COLOR) VALUES ('";
    sql.append(DESC);
    sql.append("','");
    sql.append(PART);
    sql.append("',");
    sql.append(std::to_string(A.L));
    sql.append(",");
    sql.append(std::to_string(A.W));
    sql.append(",");
    sql.append(std::to_string(A.t));
    sql.append(",");
    sql.append(std::to_string(A.amount));
    sql.append(",'");
    sql.append(A.material);
    sql.append("');");

    // Insert Data
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        std::cout << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return;
}

/*
    Description:    Adds unit to unit list database
    Input(s):       Unit Description, Overall Length, Overall Width, Overall Depth, Color, Quantity
    Return:         None
*/
void StoreUnit(std::string DESC, float L, float H, float D, std::string COLOR, int qty)
{
    sqlite3 *db;
    int rc;
    char *zErrMsg = 0;

    // Open Database
    rc = sqlite3_open(DBLoc, &db);
    if (rc)
    {
        std::cout << zErrMsg << std::endl;
        return;
    }

    // Formulate SQL Query
    std::string sql = "INSERT INTO UNITS (DESC, LENGTH, HEIGHT, DEPTH, QUANTITY, COLOR) VALUES ('";
    sql.append(DESC);
    sql.append("',");
    sql.append(std::to_string(L));
    sql.append(",");
    sql.append(std::to_string(H));
    sql.append(",");
    sql.append(std::to_string(D));
    sql.append(",");
    sql.append(std::to_string(qty));
    sql.append(",'");
    sql.append(COLOR);
    sql.append("');");

    //Insert Data
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cout << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return;
}

/*
    Description:    Returns Query of database select
    Input(s):
    Return:         None
*/
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    std::cout << argv[1] << std::endl; //DESC
    std::cout << argv[2] << std::endl; //LENGTH
    std::cout << argv[3] << std::endl; //HEIGHT
    std::cout << argv[4] << std::endl; //DEPTH

    return 0;
}

/*
=================================================================================
                                GUI Functions
=================================================================================
*/
void Building_Furniture_ProjectFrame::ListUpdate()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    long index = 0;

    // Open Database
    rc = sqlite3_open(DBLoc, &db);
    if (rc)
    {
        std::cout << zErrMsg << std::endl;
        return;
    }
    std::string sql = "SELECT * FROM 'UNITS'";

    // Insert Data
    PreviewWindow.DeleteAllNodes();
    ListView1->DeleteAllItems();

    rc = sqlite3_exec(db, sql.c_str(), cbListUpdate, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        std::cout << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    PreviewWindow.current = PreviewWindow.head;
    while (PreviewWindow.current != NULL)
    {
        if (PreviewWindow.current != PreviewWindow.head)
        {
            index = ListView1->InsertItem(0, PreviewWindow.current->a);
            ListView1->SetItem(index, 1, roundFunc(PreviewWindow.current->b));
            ListView1->SetItem(index, 2, roundFunc(PreviewWindow.current->c));
            ListView1->SetItem(index, 3, roundFunc(PreviewWindow.current->d));
        }
        PreviewWindow.current = PreviewWindow.current->next;
    }
    sqlite3_close(db);
    return;
}

/*
    Description:    Returns Query of database select
    Input(s):
    Return:         None
*/
static int cbListUpdate(void *NotUsed, int argc, char **argv, char **azColName)
{
    PreviewWindow.AddNode(argv[1], atof(argv[2]), atof(argv[3]), atof(argv[4]));
    return 0;
}

std::string roundFunc(float a)
{
    float b = (float)((int)(a * 100 + .05)) / 100;
    char buf[10];
    std::string value = "";

    sprintf(buf, "%f", b);

    for (int i = 0, j = 0, k = 0; j < 2; i++)
    {
        if (buf[i] == '.')
        {
            k = 1;
        }
        if (k == 1)
        {
            j++;
        }
        value += buf[i];
    }
    return value;
}

void Building_Furniture_ProjectFrame::OnButton2Click(wxCommandEvent &event)
{
    CuttingListFrame *CutListFrame = new CuttingListFrame(0);
    CutListFrame->Show();
}
