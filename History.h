#ifndef HISTORY_HEADER
#define HISTORY_HEADER

#include "globals.h"
class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int rows, cols;
    char hGrid[MAXROWS][MAXCOLS];
};
#endif // !HISTORY_HEADER
