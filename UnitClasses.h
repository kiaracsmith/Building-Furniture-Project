#ifndef UNITCLASSES_H_INCLUDED
#define UNITCLASSES_H_INCLUDED
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include "Building_Furniture_ProjectMain.h"

const char *dir = "./db/test.db";

/*
Title: Board Class
Description: Class that defines the boards
*/
class BOARD
{
public:
    float L, W, t;
    std::string material;
    int amount;
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
    BOARD(int y, int x, int z = 16, std::string color = "White", int qty = 1)
    {
        L = (y < x) ? x : y;
        W = (y > x) ? x : y;
        t = z;
        material = color;
        amount = qty;
    }
};

/*
Title: Preview Class
Description: Class that defines the linked list that is shown on the Preview Window.
*/
class PREV
{
public:
    typedef struct node
    {
        std::string a;
        float b;
        float c;
        float d;
        node *next;
    } * nodePtr;
    nodePtr head;
    nodePtr current;
    nodePtr temp;

    List();
    void AddNode(std::string a, float b, float c, float d);
    void DeleteNode(std::string delData);
    void PrintList();
    void DeleteAllNodes();
};

/*
Function Definitions
*/
//Database Function Handlers
void BoardPrint(std::string NAME, BOARD A);
void StoreBoard(std::string DESC, std::string PART, BOARD A);
void StoreUnit(std::string DESC, float L, float H, float D, std::string COLOR, int qty);

//Unit Calculation Function Handlers
std::string FloorUnit(float W, float H, float D, int t, std::string color, int n, int drawOpt);

//Database Initilization Handlers
static int createDB();
static int createTable();

//Database Query Handlers
static int callback(void *NotUsed, int argc, char **argv, char **azColName);
static int cbListUpdate(void *NotUsed, int argc, char **argv, char **azColName);
PREV PreviewWindow;

#endif // UNITCLASSES_H_INCLUDED
