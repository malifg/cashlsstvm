#include "printerhandler.h"
#include "logo.h"

PrinterHandler::PrinterHandler()
{

}

int PrinterHandler::printSuccessfulTransaction(std::string terminalNumber, std::string accountNumber, std::string issueTracking, std::string referenceNo, std::string price, std::string credit, std::string serialNumber)
{
    //set settings
    setSettings();

    //print bitmap
    printer.printBitmap(sepLogo,103);

    //print Enter
    char strEnter[1] = {0x20};
    printer.printString(strEnter,1);

    //print card header
    printCardHeader();

    //print line
    printLine();

    //print successfull transaction
    char strSuccessfullTransaction[11] = {0xEB, 0xEA, 0xF8, 0xF5, 0x20, 0xA9, 0xF7, 0xEE, 0x90, 0xA4, 0x97};
    printer.printString(strSuccessfullTransaction, 11);

    //print terminal number
    printTerminalNumber(terminalNumber);

    //print account number
    printAccountNumber(accountNumber);

    //print issue Tracking
    printIssueTracking(issueTracking);

    //print reference No
    printReferenceNo(referenceNo);

    //print Date and time
    printDateAndTime();

    //print price
    printPrice(price);

    //print line
    printLine();

    //print credit
    printCredit(credit);

    //print serialNumber
    printSerialNumber(serialNumber);

    //feed and cut paper
    feedAndCut();

    return OK;

}

int PrinterHandler::printSuccessfulTransactionWithQR(std::string terminalNumber, std::string accountNumber, std::string issueTracking, std::string referenceNo, std::string price, std::string qrString, std::string acceptorName, std::string lineCode, std::string ticket, long secondsValid)
{
    //set settings
    setSettings();

    //print bitmap
    printer.printBitmap(sepLogo,103);

    //print Enter
    char strEnter[1] = {0x20};
    printer.printString(strEnter,1);

    //print card header
    printCardHeader();

    //print line
    printLine();

    //print successfull transaction
    char strSuccessfullTransaction[11] = {0xEB, 0xEA, 0xF8, 0xF5, 0x20, 0xA9, 0xF7, 0xEE, 0x90, 0xA4, 0x97};
    printer.printString(strSuccessfullTransaction, 11);

    //print terminal number
    printTerminalNumber(terminalNumber);

    //print account number
    printAccountNumber(accountNumber);

    //print issue Tracking
    printIssueTracking(issueTracking);

    //print reference No
    printReferenceNo(referenceNo);

    //print Date and time
    printDateAndTime();

    //print price
    printPrice(price);

    //print line
    printLine();

    //print QR
    printer.printQR(&*qrString.begin(),qrString.size());

    //print line
    printLine();

    //print acceptor name





    //feed and cut paper
    feedAndCut();

    return OK;
}

int PrinterHandler::printUnsuccessfulTransaction(std::string terminalNumber, std::string accountNumber, std::string issueTracking, std::string referenceNo, std::string price, std::string credit, std::string serialNumber)
{

    //set settings
    setSettings();

    //print bitmap
    printer.printBitmap(sepLogo,103);

    //print Enter
    char strEnter[1] = {0x20};
    printer.printString(strEnter,1);

    //print card header
    printCardHeader();

    //print line
    printLine();

    //print unsuccessfull transaction
    char strUnsuccessfullTransaction[13] = {0xEB, 0xEA, 0xF8, 0xF5, 0x91, 0xF7, 0x20, 0xA9, 0xF7, 0xEE, 0x90, 0xA4, 0x97};
    printer.printString(strUnsuccessfullTransaction, 13);

    //print terminal number
    printTerminalNumber(terminalNumber);

    //print account number
    printAccountNumber(accountNumber);

    //print issue Tracking
    printIssueTracking(issueTracking);

    //print reference No
    printReferenceNo(referenceNo);

    //print Date and time
    printDateAndTime();

    //print price
    printPrice(price);

    //print line
    printLine();

    //print credit
    printCredit(credit);

    //print serialNumber
    printSerialNumber(serialNumber);

    //print Unsuccessful Transaction Black/Whtie Reverse
    printer.setAlignment(ALIGN_CENTER);
    char strUnsuccessfullTransactionCenter[32] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xEB, 0xEA, 0xF8, 0xF5, 0x91, 0xF7, 0x20, 0xA9, 0xF7, 0xEE, 0x90, 0xA4, 0x97, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
    printer.printReverseColorString(strUnsuccessfullTransactionCenter,32);

    //print line
    printLine();

    //print Return Money Policy
    char strReturnMoney1[32] = {0x20, 0x96, 0xA2, 0xF5, 0x20, 0xE9, 0xA4, 0xE0, 0x20, 0xA4, 0x99, 0xEE, 0x90, 0xA2, 0x9F, 0x20, 0xE6, 0xF3, 0x93, 0xF5, 0x20, 0xA4, 0xA8, 0xEE, 0x20, 0x96, 0xA4, 0xF8, 0xAC, 0x20, 0xA4, 0xA2};
    printer.printString(strReturnMoney1, 32);
    char strReturnMoney2[26] = {0x2E, 0xA2, 0xA2, 0xA4, 0xF0, 0xFE, 0xF5, 0xA5, 0x91, 0x93, 0x20, 0x92, 0x91, 0xA8, 0x9F, 0x20, 0xF9, 0x93, 0x20, 0x96, 0xE4, 0x91, 0xA8, 0x20, 0x87, 0x82};
    printer.printString(strReturnMoney2, 26);
    char strReturnMoney3[28] = {0xED, 0xF7, 0x91, 0x93, 0x20, 0xF9, 0x93, 0xE3, 0xAA, 0x20, 0xF9, 0x93, 0x20, 0x96, 0xA4, 0xF8, 0xAC, 0x20, 0xF6, 0xFE, 0x90, 0x20, 0xA4, 0xFE, 0xE8, 0x20, 0xA4, 0xA2};
    printer.printString(strReturnMoney3, 28);
    char strReturnMoney4[14] = {0xA2, 0xFE, 0xFE, 0x91, 0xF5, 0xA4, 0xEA, 0x20, 0xF9, 0xE4, 0x9B, 0x90, 0xA4, 0xF5};
    printer.printString(strReturnMoney4, 14);

    //feed and cut paper
    feedAndCut();

    return OK;

}

int PrinterHandler::printPersonalizationSucceed(std::string terminalNumber, std::string referenceNo, std::string credit, std::string serialNumber)
{
    //set settings
    setSettings();

    //print bitmap
    printer.printBitmap(sepLogo,103);

    //print Enter
    char strEnter[1] = {0x20};
    printer.printString(strEnter,1);

    //print card header
    printCardHeader();

    //print line
    printLine();

    //print Personalization Succeed
    char strPersonalizationSucceed1[26] = {0x96, 0xFE, 0xEC, 0xEA, 0xF8, 0xF5, 0x20, 0x91, 0x93, 0x20, 0xFD, 0xA5, 0x91, 0xA8, 0x20, 0xFC, 0xAC, 0xA1, 0xAA, 0x20, 0x96, 0x91, 0xFE, 0xF3, 0xF5, 0xE4};
    printer.printString(strPersonalizationSucceed1, 26);
    char strPersonalizationSucceed2[10] = {0x2E, 0xA2, 0xAA, 0x20, 0xF4, 0x91, 0x9B, 0xF7, 0x90};
    printer.printString(strPersonalizationSucceed2, 10);

    //print terminal number
    printTerminalNumber(terminalNumber);

    //print reference No
    printReferenceNo(referenceNo);

    //print Date and time
    printDateAndTime();

    //print line
    printLine();

    //print credit
    printCredit(credit);

    //print serialNumber
    printSerialNumber(serialNumber);

    //feed and cut paper
    feedAndCut();

    return OK;
}

int PrinterHandler::printPersonalizationError(std::string terminalNumber, std::string referenceNo, std::string credit, std::string serialNumber)
{

    //set settings
    setSettings();

    //print bitmap
    printer.printBitmap(sepLogo,103);

    //print Enter
    char strEnter[1] = {0x20};
    printer.printString(strEnter,1);

    //print card header
    printCardHeader();

    //print line
    printLine();

    //print Personalization Succeed
    char strPersonalizationError1[13] = {0xF9, 0x93, 0x20, 0xAF, 0xF8, 0x93, 0xA4, 0xF5, 0x20, 0xFD, 0x91, 0xAF, 0xA1};
    printer.printString(strPersonalizationError1, 13);
    char strPersonalizationError2[15] = {0x96, 0xA8, 0x90, 0xF8, 0xA1, 0xA4, 0xA2, 0x20, 0xFD, 0x91, 0xFB, 0xA2, 0xF3, 0xFE, 0xEA};
    printer.printString(strPersonalizationError2, 15);

    //print terminal number
    printTerminalNumber(terminalNumber);

    //print reference No
    printReferenceNo(referenceNo);

    //print Date and time
    printDateAndTime();

    //print line
    printLine();

    //print credit
    printCredit(credit);

    //print serialNumber
    printSerialNumber(serialNumber);

    //feed and cut paper
    feedAndCut();

    return OK;
}

int PrinterHandler::setSettings()
{
    printer.setAlignment(ALIGN_CENTER);
    printer.setPersianCodeTable();
    return OK;
}

int PrinterHandler::printLine()
{
    char strLine[32] = {0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D, 0x20, 0x2D};
    printer.printString(strLine, 32);
    return OK;
}

int PrinterHandler::printTerminalNumber(std::string terminalNumber)
{
    printer.setAlignment(ALIGN_LEFT);
    char terminalNumberPersian[15] = {0x3A, 0x20, 0xF1, 0x91, 0xF7, 0xFE, 0xF5, 0xA4, 0x97, 0x20, 0xF9, 0xA4, 0x91, 0xF5, 0xAA};
    int terminalNumberSize = terminalNumber.size();
    char strPersianTerminalNumber[terminalNumberSize];
    engToPerNumber(&*terminalNumber.begin(), terminalNumberSize, strPersianTerminalNumber);

    char strTerminalNumberFull[32];
    for (int i=0;i<terminalNumberSize;i++)
    {
        strTerminalNumberFull[i] = strPersianTerminalNumber[i];
    }

    for (int i=0;i<32-15-terminalNumberSize;i++)
    {
        strTerminalNumberFull[i+terminalNumberSize] = 0x20;
    }

    for (int i=0;i<15;i++)
    {
        strTerminalNumberFull[i+17] = terminalNumberPersian[i];
    }

    printer.printString(strTerminalNumberFull, 32);

    return OK;
}

int PrinterHandler::printCardHeader()
{
    char strShahinShahrCard[22] = {0xA4, 0xFA, 0xAA, 0x20, 0xF6, 0xFE, 0xFB, 0x91, 0xAA, 0x20, 0xFD, 0xA2, 0xF7, 0xF8, 0xA4, 0xFA, 0xAA, 0x20, 0x96, 0xA4, 0x91, 0xEE};
    printer.printString(strShahinShahrCard, 22);
}

int PrinterHandler::printAccountNumber(std::string accountNumber)
{
    char accountNumberPersian[12] = {0x3A, 0x20, 0x96, 0xA4, 0x91, 0xEE, 0x20, 0xF9, 0xA4, 0x91, 0xF5, 0xAA};
    char strPersianAccountNumber[16];
    engToPerNumber(&*accountNumber.begin(), 16, strPersianAccountNumber);

    char strAccountNumberFull[32];
    for (int i=0;i<6;i++)
    {
        strAccountNumberFull[i] = strPersianAccountNumber[i];
    }

    for (int i=6;i<12;i++)
    {
        strAccountNumberFull[i] = 0x2A;
    }

    for (int i=12;i<16;i++)
    {
        strAccountNumberFull[i] = strPersianAccountNumber[i];
    }

    for (int i=0;i<4;i++)
    {
        strAccountNumberFull[i+16] = 0x20;
    }

    for (int i=0;i<12;i++)
    {
        strAccountNumberFull[i+20] = accountNumberPersian[i];
    }

    printer.printString(strAccountNumberFull, 32);

    return OK;
}

int PrinterHandler::printIssueTracking(std::string issueTracking)
{
    char issueTrackingPersian[14] = {0x3A, 0x20, 0xFD, 0xA4, 0xFE, 0xF0, 0xFE, 0x95, 0x20, 0xF9, 0xA4, 0x91, 0xF5, 0xAA};
    int issueTrackingSize = issueTracking.size();
    char strIssueTrackingNumber[issueTrackingSize];
    engToPerNumber(&*issueTracking.begin(), issueTrackingSize, strIssueTrackingNumber);

    char strIssueTrackingFull[32];
    for (int i=0;i<issueTrackingSize;i++)
    {
        strIssueTrackingFull[i] = strIssueTrackingNumber[i];
    }

    for (int i=0;i<32-14-issueTrackingSize;i++)
    {
        strIssueTrackingFull[i+issueTrackingSize] = 0x20;
    }

    for (int i=0;i<14;i++)
    {
        strIssueTrackingFull[i+18] = issueTrackingPersian[i];
    }
    printer.printString(strIssueTrackingFull, 32);

    return OK;
}

int PrinterHandler::printReferenceNo(std::string referenceNo)
{
    char referenceNoPersian[12] = {0x3A, 0x20, 0xE2, 0x9B, 0xA4, 0xF5, 0x20, 0xF9, 0xA4, 0x91, 0xF5, 0xAA};
    int referenceNoSize = referenceNo.size();
    char strReferenceNoNumber[referenceNoSize];
    engToPerNumber(&*referenceNo.begin(), referenceNoSize, strReferenceNoNumber);

    char strReferenceNoFull[32];
    for (int i=0;i<referenceNoSize;i++)
    {
        strReferenceNoFull[i] = strReferenceNoNumber[i];
    }

    for (int i=0;i<32-12-referenceNoSize;i++)
    {
        strReferenceNoFull[i+referenceNoSize] = 0x20;
    }

    for (int i=0;i<12;i++)
    {
        strReferenceNoFull[i+20] = referenceNoPersian[i];
    }
    printer.printString(strReferenceNoFull, 32);

    return OK;
}

int PrinterHandler::printDateAndTime()
{
    char outDateAndTime[17];
    dateAndTimeP(outDateAndTime);
    char dateAndTime[14] = {0x3A, 0x20, 0xF6, 0x91, 0xF5, 0xA5, 0x20, 0xF8, 0x20, 0xA0, 0xFE, 0xA4, 0x91, 0x97};
    char dateAndTimeSpace[1] = {0x20};

    char strDateAndTimeFull[32];
    for (int i=0;i<17;i++)
    {
        strDateAndTimeFull[i] = outDateAndTime[i];
    }

    for (int i=0;i<1;i++)
    {
        strDateAndTimeFull[i+17] = dateAndTimeSpace[i];
    }

    for (int i=0;i<14;i++)
    {
        strDateAndTimeFull[i+18] = dateAndTime[i];
    }
    printer.printString(strDateAndTimeFull, 32);

    return OK;
}

int PrinterHandler::printPrice(std::string price)
{
    char pricePersian[6] = {0x3A, 0x20, 0xE6, 0xF3, 0x93, 0xF5};
    char rialPersian[5] = {0xF1, 0x91, 0xFE, 0xA4, 0x20};
    int priceSize = price.size();
    char strPrice[priceSize];
    engToPerNumber(&*price.begin(), priceSize, strPrice);
    //char priceSpace[21-price.size()];

    char strPriceFull[32];
    for (int i=0;i<5;i++)
    {
        strPriceFull[i] = rialPersian[i];
    }
    for (int i=0;i < priceSize;i++)
    {
        strPriceFull[i+5] = strPrice[i];
    }
    for (int i=0;i<21-priceSize;i++)
    {
        strPriceFull[i+5+priceSize] = 0x20;
    }
    for (int i=0;i<6;i++)
    {
        strPriceFull[i+26] = pricePersian[i];
    }

    printer.printString(strPriceFull, 32);

    return OK;
}

int PrinterHandler::printCredit(std::string credit)
{
    char rialPersian[5] = {0xF1, 0x91, 0xFE, 0xA4, 0x20};
    char creditPersian[8] = {0x3A, 0x20, 0xFD, 0xA2, 0xF8, 0x9B, 0xF8, 0xF5};
    int creditSize = credit.size();
    char strCredit[creditSize];
    engToPerNumber(&*credit.begin(), creditSize, strCredit);
    char strCreditFull[32];
    for (int i=0;i<5;i++)
    {
        strCreditFull[i] = rialPersian[i];
    }
    for (int i=0;i < creditSize;i++)
    {
        strCreditFull[i+5] = strCredit[i];
    }
    for (int i=0;i<19-creditSize;i++)
    {
        strCreditFull[i+5+creditSize] = 0x20;
    }
    for (int i=0;i<8;i++)
    {
        strCreditFull[i+24] = creditPersian[i];
    }

    printer.printString(strCreditFull, 32);

    return OK;
}

int PrinterHandler::printSerialNumber(std::string serialNumber)
{
    char serialNumberPersian[18] = {0x3A, 0x20, 0x96, 0xA4, 0x91, 0xEE, 0x20, 0xF1, 0x91, 0xFE, 0xA4, 0xA8, 0x20, 0xF9, 0xA4, 0x91, 0xF5, 0xAA};
    int serialNumberSize = serialNumber.size();
    char strSerialNumber[serialNumberSize];
    engToPerNumber(&*serialNumber.begin(), serialNumberSize, strSerialNumber);

    char strSerialNumberFull[32];
    for (int i=0;i<serialNumberSize;i++)
    {
        strSerialNumberFull[i] = strSerialNumber[i];
    }
    for (int i=0;i < 32-18-serialNumberSize;i++)
    {
        strSerialNumberFull[i+serialNumberSize] = 0x20;
    }
    for (unsigned int i=0;i<18;i++)
    {
        strSerialNumberFull[i+14] = serialNumberPersian[i];
    }
    printer.printString(strSerialNumberFull, 32);

    return OK;
}

int PrinterHandler::feedAndCut()
{
    printer.feedPaper(3);
    printer.cutPaper(PAPER_FULL_CUT);
    return OK;
}

int PrinterHandler::dateAndTimeP(char *out)
{
    QTime TimeNow=QTime::currentTime();
    int h1=TimeNow.hour();
    TimeNow=TimeNow.addSecs(12600);
    std::string h=std::to_string((TimeNow.hour()));
    int h2=TimeNow.hour();
    std::string min=std::to_string(TimeNow.minute());
    std::string sec=std::to_string(TimeNow.second());
    if (TimeNow.hour()<10)
    {
        h="0"+h;
    }
    if (TimeNow.minute()<10)
    {
        min="0"+min;
    }
    if (TimeNow.second()<10)
    {
        sec="0"+sec;
    }
    char hourP[2];
    engToPerNumber(&*h.begin(),2,hourP);
    char minP[2];
    engToPerNumber(&*min.begin(),2,minP);
    char secP[2];
    engToPerNumber(&*sec.begin(),2,secP);


    QDate DateNow=QDate::currentDate();
    if (h1>h2)
    {
        DateNow=DateNow.addDays(1);
    }
    long gy=DateNow.year();
    long gm=DateNow.month();
    long gd=DateNow.day();
    long tarikh_g[3];
    gregorianToJalali(gy,gm,gd,tarikh_g);
    std::string jy=std::to_string(tarikh_g[0]-1400);
    std::string jm=std::to_string(tarikh_g[1]);
    std::string jd=std::to_string(tarikh_g[2]);
    if (tarikh_g[0]-1400<10)
    {
        jy="0"+jy;
    }
    if (tarikh_g[1]<10)
    {
        jm="0"+jm;
    }
    if (tarikh_g[2]<10)
    {
        jd="0"+jd;
    }

    char jyP[2];
    engToPerNumber(&*jy.begin(),2,jyP);
    char jmP[2];
    engToPerNumber(&*jm.begin(),2,jmP);
    char jdP[2];
    engToPerNumber(&*jd.begin(),2,jdP);

    char out1[17] = {hourP[0],hourP[1], 0x3A, minP[0], minP[1], 0x3A, secP[0], secP[1], 0x2D, jyP[0],jyP[1], 0x2F, jmP[0], jmP[1], 0x2F, jdP[0], jdP[1]};

    for (int i=0;i<17;i++)
    {
        out[i] = out1[i];
    }
    return OK;
}

int PrinterHandler::engToPerNumber(char *inputString, int size, char *outputString)
{
    for (int i=0;i<size;i++)
    {
        if (inputString[i]<=0x39 && inputString[i]>=0x30)
            outputString[i]=inputString[i]+0x50;
        else
            outputString[i]=inputString[i];
    }
    return OK;
}

long* PrinterHandler::gregorianToJalali(long gy, long gm, long gd, long out[]) {
  long days;
  {
    long gy2 = (gm > 2) ? (gy + 1) : gy;
    long g_d_m[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    days = 355666 + (365 * gy) + ((int)((gy2 + 3) / 4)) - ((int)((gy2 + 99) / 100)) + ((int)((gy2 + 399) / 400)) + gd + g_d_m[gm - 1];
  }
  long jy = -1595 + (33 * ((int)(days / 12053)));
  days %= 12053;
  jy += 4 * ((int)(days / 1461));
  days %= 1461;
  if (days > 365) {
    jy += (int)((days - 1) / 365);
    days = (days - 1) % 365;
  }
  out[0] = jy;
  if (days < 186) {
    out[1]/*jm*/ = 1 + (int)(days / 31);
    out[2]/*jd*/ = 1 + (days % 31);
  } else {
    out[1]/*jm*/ = 7 + (int)((days - 186) / 30);
    out[2]/*jd*/ = 1 + ((days - 186) % 30);
  }
  return out;
}
