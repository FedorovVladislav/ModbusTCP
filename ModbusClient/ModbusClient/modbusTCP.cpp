#include <iostream>
#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <windows.h>
#pragma warning (disable: 4996)
#include <string>
#include <vector>
#include "modbusTCP.h"

using namespace std;



bool  modbus::setConnection() {

    WSAData wsData;
    WORD DLLVersion = MAKEWORD(2, 1);


    if (WSAStartup(DLLVersion, &wsData) != 0)
    {
        std::cout << "dont Open";
        return false;
    }

    SOCKADDR_IN addr;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;


    connection = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
        {
            cout << "error Connect";
            return false;
        }
   else
        cout << "good Connect";
            
   return true;
    };



    void    modbus::closeConnection() {

        closesocket(connection);
        WSACleanup();
    };

    bool   modbus::read(const int startAdress, const int lens) {

        char to_send[12]{ 0 };
        to_send[0] = 1;
        to_send[5] = 6;
        to_send[6] = adress;
        to_send[7] = 3;
        to_send[8] = startAdress >> 8;
        to_send[9] = startAdress;
        to_send[10] = lens >> 8;
        to_send[11] = lens;
        char recive[250];


        send(connection, to_send, 12, 0);

        recv(connection, recive, (9 + lens * 2), 0);
        system("cls");

        for (int i = 0; i < lens; i++)
            result.push_back((recive[9 + i * 2] << 8) | recive[10 + i * 2]);


        return true;
    }


    void modbus::printvalue(int lens) {

        for (int i = 0; i < lens; i++)
            cout << "data\n" << result[i] << "\n";
    }




