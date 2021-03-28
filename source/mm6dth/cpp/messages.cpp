// +---------------------------------------------------------------------------+
// | MM6DTest v0.1 * Tester program for MM6D remote controlled switching device|
// | Copyright (C) 2021 Pozsar Zsolt <pozsar.zsolt@szerafingomba.hu>           |
// | messages.cpp                                                              |
// | Messages                                                                  |
// +---------------------------------------------------------------------------+

//   This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License 3.0 version.
//
//   This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.

// get message
char const *msg(int const index)
{
  static char const * const message[] =
  {
    /*  0 */  "MM6DTest v0.1 * Tester program for MM6D remote controlled switching device  ",
    /*  1 */  "Copyright (C) 2021 Pozsar Zsolt <pozsar.zsolt@szerafingomba.hu>             ",
    /*  2 */  "Usage:\n\tmm6dtest.exe IP_address UID\n\n",
    /*  3 */  "Bad IP address!\n",
    /*  4 */  "IP address: ",
    /*  5 */  "\nMenu:\n\n",
    /*  6 */  "",
    /*  7 */  "",
    /*  8 */  "\tq:\t\tExit to OS\n",
    /*  9 */  "Connection error!\n",
    /* 10 */  "\nPress <ESC> to back to the menu\n\n",
    /* 11 */  "\nTest device via Hypertext Transfer Protocol:\n\n",
    /* 12 */  "Get information about device",
    /* 13 */  "Get operation mode",
    /* 14 */  "Get all status (except outputs)",
    /* 15 */  "Get status of operation mode switch",
    /* 16 */  "Get status of manual mode switches",
    /* 17 */  "Get status of overcurrent protection",
    /* 18 */  "Get status of lamp output",
    /* 19 */  "Get status of ventilator output",
    /* 20 */  "Get status of heater output",
    /* 21 */  "Set status of alarm to off",
    /* 22 */  "",
    /* 23 */  "Set status of lamp output",
    /* 24 */  "Set status of ventilator output",
    /* 25 */  "Set status of heater output",
    /* 26 */  "Set off all outputs",
    /* 27 */  "\tLamp",
    /* 28 */  "\tVentilator",
    /* 29 */  "\tHeater",
    /* 30 */  " output is switched ",
    /* 31 */  "on.\n",
    /* 32 */  "off.\n",
    /* 33 */  "\t All outputs are switched off.\n",
    /* 34 */  "\tAlarm event is detected!\n",
    /* 35 */  "",
    /* 36 */  "",
    /* 37 */  "",
    /* 38 */  "",
    /* 39 */  "",
    /* 40 */  "",
    /* 41 */  "",
    /* 42 */  "",
    /* 43 */  "",
    /* 44 */  "\tAlarm event is not detected!\n",
    /* 45 */  "\tDevice type:\t\t",
    /* 46 */  "\tSoftware version:\t",
    /* 47 */  "\tSerial number:\t\t",
    /* 48 */  "",
    /* 49 */  "",
    /* 50 */  ""
    };
  return message[index];
}
