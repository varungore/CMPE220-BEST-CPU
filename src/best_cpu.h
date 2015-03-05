void displayCPUState();
void startExecution();
void loadProgram();
void getValue(int);
int ADD(int, int);
int MUL(int, int);
int SUB(int, int);
int DIV(int, int);
int MOD(int, int);
std::map<std::string, int> instrMap;

std::map<std::string, int> refLocationMap;

string input;
int mem[1024] = { 0 };//0-19 reserved for registers disscuss*
int *PC;
string codeSegment[1024] = { "" };
int flag = 0;
