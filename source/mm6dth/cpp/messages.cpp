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
    /*  2 */  "Usage:\n\tmm6dtest IP_address UID\n\n",
    /*  3 */  "Bad IP address!\n",
    /*  4 */  "IP address: ",
    /*  5 */  "\nMenu:\n\n",
    /*  6 */  "\tManual operation mode.\n",
    /*  7 */  "\tAutomatic operation mode.\n",
    /*  8 */  "\tq:\t\tExit to OS\n",
    /*  9 */  "Connection error!\n",
    /* 10 */  "\nPress <ESC> to back to the menu\n\n",
    /* 11 */  "\nTest device via Hypertext Transfer Protocol:\n\n",
    /* 12 */  "Get information about device",
    /* 13 */  "Get status of alarm",
    /* 14 */  "Get all status (except outputs)",
    /* 15 */  "Get status of operation mode switch",
    /* 16 */  "Get status of manual mode switches",
    /* 17 */  "Get status of overcurrent protection",
    /* 18 */  "Get status of lamp output",
    /* 19 */  "Get status of ventilator output",
    /* 20 */  "Get status of heater output",
    /* 21 */  "Set status of alarm to off",
    /* 22 */  "Set status of lamp output",
    /* 23 */  "Set status of ventilator output",
    /* 24 */  "Set status of heater output",
    /* 25 */  "Set off all outputs",
    /* 26 */  "Set status of all outputs and get all status",
    /* 27 */  "\tAlarm event is not detected.\n",
    /* 28 */  "\tLamp",
    /* 29 */  "\tVentilator",
    /* 30 */  "\tHeater",
    /* 31 */  " output is switched ",
    /* 32 */  "on.\n",
    /* 33 */  "off.\n",
    /* 34 */  "\t All outputs are switched off.\n",
    /* 35 */  "\tAlarm event is detected!\n",
    /* 36 */  "\tGrowing hyphae.\n",
    /* 37 */  "\tGrowing mushroom.\n",
    /* 38 */  "\tOvercurrent breaker is opened!\n",
    /* 39 */  "\tOvercurrent breaker is closed.\n",
    /* 40 */  "\tDevice type:\t\t",
    /* 41 */  "\tSoftware version:\t",
    /* 42 */  "\tSerial number:\t\t",
    /* 43 */  "\tAlarm is disabled.\n",
    /* 44 */  "\tDisable alarm (0/1)? ",
    /* 45 */  "\tSwitch on/off heater (0/1)? ",
    /* 46 */  "\tSwitch on/off lamp (0/1)? ",
    /* 47 */  "\tSwitch on/off ventilator (0/1)? "
    };
  return message[index];
}
