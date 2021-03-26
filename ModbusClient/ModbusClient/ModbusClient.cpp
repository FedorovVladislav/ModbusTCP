#include "modbusTCP.h"


int main()
{
    
    int startAdress = 0;
    int lens = 5;
    modbus modbus1;


    if (modbus1.setConnection())
    {
        modbus1.read(startAdress, lens);
        modbus1.printvalue(lens);
    }


    modbus1.closeConnection();
    
    
    return 0;

    
}

