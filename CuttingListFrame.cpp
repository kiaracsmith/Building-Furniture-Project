#include "CuttingListFrame.h"

//(*InternalHeaders(CuttingListFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

#include <string>
#include <iostream>
#include "sqlite/sqlite3.h"
#include "Constants.h"
#include "Building_Furniture_ProjectMain.h"

//(*IdInit(CuttingListFrame)
const long CuttingListFrame::ID_GRID1 = wxNewId();
const long CuttingListFrame::REFRESH_ID1 = wxNewId();
const long CuttingListFrame::CSV1 = wxNewId();
const long CuttingListFrame::PDF1 = wxNewId();
//*)
CT CutListWindow;

BEGIN_EVENT_TABLE(CuttingListFrame, wxFrame)
//(*EventTable(CuttingListFrame)
//*)
END_EVENT_TABLE()

CuttingListFrame::CuttingListFrame(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
{
	//(*Initialize(CuttingListFrame)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(540,673));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	Grid1 = new wxGrid(this, ID_GRID1, wxPoint(0,0), wxSize(540,584), wxBORDER_DOUBLE|wxVSCROLL|wxALWAYS_SHOW_SB, _T("ID_GRID1"));
	Grid1->CreateGrid(2,6);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetRowLabelSize(40);
	Grid1->SetDefaultColSize(80, true);
	Grid1->SetColLabelValue(0, _("Part"));
	Grid1->SetColLabelValue(1, _("Length"));
	Grid1->SetColLabelValue(2, _("Width"));
	Grid1->SetColLabelValue(3, _("Thickness"));
	Grid1->SetColLabelValue(4, _("Color"));
	Grid1->SetColLabelValue(5, _("Quantity"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem3 = new wxMenuItem(Menu1, REFRESH_ID1, _("Refresh"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem3);
	MenuBar1->Append(Menu1, _("Refresh"));
	Menu2 = new wxMenu();
	MenuItem1 = new wxMenuItem(Menu2, CSV1, _("CSV"), wxEmptyString, wxITEM_NORMAL);
	Menu2->Append(MenuItem1);
	MenuItem2 = new wxMenuItem(Menu2, PDF1, _("PDF"), wxEmptyString, wxITEM_NORMAL);
	Menu2->Append(MenuItem2);
	MenuBar1->Append(Menu2, _("Export"));
	SetMenuBar(MenuBar1);
	FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	//*)

	Connect(REFRESH_ID1, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&CuttingListFrame::REFRESHBUTTON);
	Connect(CSV1, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&CuttingListFrame::CSV_Export);
	Connect(PDF1, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&CuttingListFrame::PDF_Export);
	UpdateList();
}

CuttingListFrame::~CuttingListFrame()
{
	//(*Destroy(CuttingListFrame)
	//*)
}

void CuttingListFrame::REFRESHBUTTON(wxCommandEvent &event)
{
	UpdateList();
}
void CuttingListFrame::CSV_Export(wxCommandEvent &event)
{
	UpdateList();
}
void CuttingListFrame::PDF_Export(wxCommandEvent &event)
{
	UpdateList();
}

/*
=================================================================================
                                GUI Functions
=================================================================================
*/
void CuttingListFrame::UpdateList()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	int index = 0;

	// Open Database
	rc = sqlite3_open(DBLoc, &db);
	if (rc)
	{
		std::cout << zErrMsg << std::endl;
		return;
	}
	std::string sql = "SELECT * FROM 'CUTTINGLIST'";

	// Insert Data
	CutListWindow.DeleteAllNodes();
	Grid1->ClearGrid();

	rc = sqlite3_exec(db, sql.c_str(), cbCutListUpdate, 0, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		std::cout << zErrMsg << std::endl;
		sqlite3_free(zErrMsg);
	}
	CutListWindow.current = CutListWindow.head;
	while (CutListWindow.current != NULL)
	{
		if (CutListWindow.current != CutListWindow.head)
		{
			Grid1->AppendRows(index, 1);
			Grid1->SetCellValue(index, 0, CutListWindow.current->a);
			Grid1->SetCellValue(index, 1, roundFunc(CutListWindow.current->b));
			Grid1->SetCellValue(index, 2, roundFunc(CutListWindow.current->c));
			Grid1->SetCellValue(index, 3, roundFunc(CutListWindow.current->d));
			Grid1->SetCellValue(index, 4, CutListWindow.current->e);
			Grid1->SetCellValue(index, 5, roundFunc(CutListWindow.current->f));
			index++;
		}
		CutListWindow.current = CutListWindow.current->next;
	}
}

/*
    Description:    Returns Query of database select
    Input(s):
    Return:         None
*/
static int cbCutListUpdate(void *NotUsed, int argc, char **argv, char **azColName)
{
	CutListWindow.AddNode(argv[3], atof(argv[4]), atof(argv[5]), atof(argv[6]), argv[1], std::stoi(argv[7]));
	return 0;
}
