#pragma once

#include <iostream>
#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <windows.h>
#pragma warning (disable: 4996)
#include <string>
#include <vector>

using namespace std;


class modbus {


    char ip[16] = "127.0.0.1";
    int port = 502;
    int adress = 1;
    SOCKET connection;
    vector <int> result;


public:
    bool   setConnection();
       
    void   closeConnection();

    bool   read(const int startAdress, const int lens);

    void   printvalue(int lens);



};



