#ifndef UNITCLASSES_H_INCLUDED
#define UNITCLASSES_H_INCLUDED
#include <string>
#include <iostream>
#include <string>
#include <fstream>

const char *dir = "./db/test.db";

class BOARD
{
public:
    int L, W, t;
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

void BoardPrint(std::string NAME, BOARD A);
void FloorUnit(int W, int H, int D, int t, std::string color, int n, int drawOpt);
static int createDB(const char *s);
static int createTable(const char *s);
static int insertData(const char *s);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);
static int selectUnits(const char *s);


#endif // UNITCLASSES_H_INCLUDED
