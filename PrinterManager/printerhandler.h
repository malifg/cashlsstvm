#ifndef PRINTERHANDLER_H
#define PRINTERHANDLER_H

#include <iostream>
#include <HAL/HS_K24/hs_k24.h>

class PrinterHandler
{
public:
    PrinterHandler();
    int printSuccessfulTransaction(std::string terminalNumber, std::string accountNumber, std::string issueTracking, std::string referenceNo, std::string price, std::string credit, std::string serialNumber);
    int printSuccessfulTransactionWithQR(std::string terminalNumber, std::string accountNumber, std::string issueTracking, std::string referenceNo, std::string price, std::string qrString, std::string acceptorName, std::string lineCode, std::string ticket, long secondsValid);
    int printUnsuccessfulTransaction(std::string terminalNumber, std::string accountNumber, std::string issueTracking, std::string referenceNo, std::string price, std::string credit, std::string serialNumber);
    int printPersonalizationSucceed(std::string terminalNumber, std::string referenceNo, std::string credit, std::string serialNumber);
    int printPersonalizationError(std::string terminalNumber, std::string referenceNo, std::string credit, std::string serialNumber);
private:
    HS_K24 printer;
    int setSettings();
    int printLine();
    int printCardHeader();
    int printTerminalNumber(std::string terminalNumber);
    int printAccountNumber(std::string accountNumber);
    int printIssueTracking(std::string issueTracking);
    int printReferenceNo(std::string referenceNo);
    int printPrice(std::string price);
    int printCredit(std::string credit);
    int printSerialNumber(std::string serialNumber);
    int feedAndCut();
    int printDateAndTime();
    int engToPerNumber(char* inputString, int size, char* outputString);
    int dateAndTimeP(char *out);
    long* gregorianToJalali(long gy, long gm, long gd, long out[]);
};

#endif // PRINTERHANDLER_H
