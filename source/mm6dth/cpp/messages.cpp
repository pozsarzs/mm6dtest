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
    /*  5 */  "\nMenu:\n\n"
  };
  return message[index];
}
