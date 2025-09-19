/*A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer value between 0 and 105.

Implement the Spreadsheet class:

Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially set to 0.
void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
void resetCell(String cell) Resets the specified cell to 0.
int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and returns the computed sum.
Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered 0.*/

//Time Complexity -- O(N)

class Spreadsheet {
public:
    vector<vector<int>>vec;
    Spreadsheet(int rows) {
        this->vec = vector<vector<int>>(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        int n = cell.size();
        int row = 0;
        for(int i=1;i<n;i++){
            row=(row*10)+(cell[i]-'0');
        }
        vec[row-1][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        int n = cell.size();
        int row = 0;
        for(int i=1;i<n;i++){
            row=(row*10)+(cell[i]-'0');
        }
        vec[row-1][col] = 0;
    }
    
    int getValue(string formula) {
        int n = formula.size();
        bool encounter_plus = false;
        string X,Y;
        for(int i=1;i<n;i++){
            if(!encounter_plus){
                if(formula[i]=='+'){
                    encounter_plus=true;
                }
                else{
                    X.push_back(formula[i]);
                }
            }
            else{
                Y.push_back(formula[i]);
            }
        }
        int x,y;
        if(X[0]>='A'&&X[0]<='Z'){
            int col = X[0]-'A';
            int row = 0;
            for(int i=1;i<X.size();i++){
                row=(row*10)+(X[i]-'0');
            }
            x=vec[row-1][col];
        }
        else{
            x=stoi(X);
        }
        if(Y[0]>='A'&&Y[0]<='Z'){
            int col = Y[0]-'A';
            int row = 0;
            for(int i=1;i<Y.size();i++){
                row=(row*10)+(Y[i]-'0');
            }
            y=vec[row-1][col];
        }
        else{
            y=stoi(Y);
        }
        return x+y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
