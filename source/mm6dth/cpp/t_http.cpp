// +---------------------------------------------------------------------------+
// | MM6DTest v0.1 * Tester program for MM6D remote controlled switching device|
// | Copyright (C) 2021 Pozsar Zsolt <pozsar.zsolt@szerafingomba.hu>           |
// | t_http.cpp                                                                |
// | Tester for HTTP                                                           |
// +---------------------------------------------------------------------------+

//   This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License 3.0 version.
//
//   This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.

#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include "messages.h"
#include "utils.h"

using namespace std;

// general variables
char      *outBuffer    = (char*) malloc(255);
char      *ip           = (char*) malloc(15);
char      *uid          = (char*) malloc(255);
bool       lamp         = 0;
bool       ventilator   = 0;
bool       heater       = 0;
bool       autoopmode   = 0;

#define    HTTPGETPROG  "wget -qO "
#define    TEMPFILE     "mm6dtest.tmp"

// write header with menu
void headerwithmenu(int menu)
{
  cls();
#ifdef __DOS__
  printf("�"); for (int i = 0; i < 77; i++) printf("�"); printf("�\n");
  printf("� %s�\n",msg(0));
  printf("� %s�\n",msg(1));
  printf("�"); for (int i = 0; i < 77; i++) printf("�"); printf("�\n");
#else
  printf("+"); for (int i = 0; i < 77; i++) printf("-"); printf("+\n");
  printf("| %s|\n",msg(0));
  printf("| %s|\n",msg(1));
  printf("+"); for (int i = 0; i < 77; i++) printf("-"); printf("+\n");
#endif
  if (menu == 0)
  {
    printf(msg(11));
    for (int i = 5; i < 20; i++) printf("\t%x:\t\t%s\n",i-4,msg(i+7));
    printf(msg(8));
  } else
  {
    if (menu>17)
      printf("\n%s:\n\n",msg(menu)); else
      printf("\n%s:\n\n",msg(menu+11));
  }
}

// open webpage and save content to temporary file
int openwebpage(char *url, bool readfile)
{
  int rc;
  char *commandline = (char*)malloc(255);
  sprintf(commandline,"%s%s http://%s",HTTPGETPROG,TEMPFILE,url);
  rc = system(commandline);
  free(commandline);
  if ((rc == 0) && (readfile))
  {
    FILE *fp = fopen(TEMPFILE,"rb");
    fseek(fp,0,SEEK_END);
    long fsize = ftell(fp);
    rewind(fp);
    char *string = (char*) malloc(fsize + 1);
    fread(string,1,fsize,fp);
    fclose(fp);
    string[fsize] = 0;
    strcpy(outBuffer,string);
    free(string);
  }
  return rc;
}

// get information about device
void f01(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(1);
  sprintf(url,"%s/version",ip);
  rc = openwebpage(url,1);
  free(url);
  if (rc == 0)
  {
    char *input = (char*) malloc(255);
    strcpy(input,outBuffer);
    char *token = strtok(input,"\n");
    int line = 0;
    while (token != NULL)
    {
      if (line == 0) printf("%s%s\n",msg(45),token);
      if (line == 1) printf("%s%s\n",msg(46),token);
      if (line == 2) printf("%s%s\n",msg(47),token);
      token = strtok(NULL,"\n");
      line++;
    }
    free(input);
  } else printf(msg(9));
  pause(27,msg(10));
}

// get status of alarm
void f02(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(2);
  sprintf(url,"%s/get/alarm?uid=%s",ip,uid);
  rc = openwebpage(url,1);
  free(url);
  if (rc == 0)
  {
    char *input = (char*) malloc(255);
    strcpy(input,outBuffer);
    char *token = strtok(input,"\n");
    int line = 0;
    while (token != NULL)
    {
      if (line == 0)
        if (strncmp(token,"1",1) == 0) printf(msg(34)); else printf(msg(44));
      token = strtok(NULL,"\n");
      line++;
    }
    free(input);
  } else printf(msg(9));
  pause(27,msg(10));
}

// get all status
void f03(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(3);
  sprintf(url,"%s/get/all?uid=%s",ip,uid);
  rc = openwebpage(url,1);
  free(url);
  if (rc == 0)
  {
    free(input);
  } else printf(msg(9));
  pause(27,msg(10));
}

// get status of operation mode switch
void f04(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(15);
  sprintf(url,"%s/get/operationmode?uid=%s",ip,uid);
  rc = openwebpage(url,1);
  free(url);
  if (rc == 0)
  {
    free(input);
  } else printf(msg(9));
  pause(27,msg(10));
}

// get status of manual mode switches
void f05(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(16);
  sprintf(url,"%s/get/manualswitch?uid=%s",ip,uid);
  rc = openwebpage(url,1);
  free(url);
  if (rc == 0)
  {
    free(input);
  } else printf(msg(9));
  pause(27,msg(10));
}

// get status of overcurrent protection
void f06(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(17);
  sprintf(url,"%s/get/protection?uid=%s",ip,uid);
  rc = openwebpage(url,1);
  free(url);
  if (rc == 0)
  {
    free(input);
  } else printf(msg(9));
  pause(27,msg(10));
}

// get status of lamp output
void f07(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(18);
  sprintf(url,"%s/get/lamp?uid=%s",ip,uid);
  rc = openwebpage(url,1);
  free(url);
  if (rc == 0)
  {
    char *input = (char*) malloc(255);
    strcpy(input,outBuffer);
    char *token = strtok(input,"\n");
    int line = 0;
    while (token != NULL)
    {
      if (line == 0)
        if (strncmp(token,"1",1) == 0)
          printf("%s%s%s",msg(27),msg(30),msg(31)); else
          printf("%s%s%s",msg(27),msg(30),msg(32));
      token = strtok(NULL,"\n");
      line++;
    }
    free(input);
  } else printf(msg(9));
  pause(27,msg(10));
}

// get status of ventilator output
void f08(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(19);
  sprintf(url,"%s/get/ventilator?uid=%s",ip,uid);
  rc = openwebpage(url,1);
  free(url);
  if (rc == 0)
  {
    char *input = (char*) malloc(255);
    strcpy(input,outBuffer);
    char *token = strtok(input,"\n");
    int line = 0;
    while (token != NULL)
    {
      if (line == 0)
        if (strncmp(token,"1",1) == 0)
          printf("%s%s%s",msg(28),msg(30),msg(31)); else
          printf("%s%s%s",msg(28),msg(30),msg(32));
      token = strtok(NULL,"\n");
      line++;
    }
    free(input);
  } else printf(msg(9));
  pause(27,msg(10));
}

// get status of heater output
void f09(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(20);
  sprintf(url,"%s/get/heater?uid=%s",ip,uid);
  rc = openwebpage(url,1);
  free(url);
  if (rc == 0)
  {
    char *input = (char*) malloc(255);
    strcpy(input,outBuffer);
    char *token = strtok(input,"\n");
    int line = 0;
    while (token != NULL)
    {
      if (line == 0)
        if (strncmp(token,"1",1) == 0)
          printf("%s%s%s",msg(29),msg(30),msg(31)); else
          printf("%s%s%s",msg(29),msg(30),msg(32));
      token = strtok(NULL,"\n");
      line++;
    }
    free(input);
  } else printf(msg(9));
  pause(27,msg(10));
}

// set alarm off
void f10(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(21);
  lamp = ! lamp;
  sprintf(url,"%s/set/alarm/off?uid=%s",ip,uid);
  rc = openwebpage(url,0);
  free(url);
  if (rc != 0) printf(msg(9));
  pause(27,msg(10));
}

// on/off lamp output
void f11(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(23);
  lamp = ! lamp;
  if (lamp)
    printf("%s%s%s",msg(27),msg(30),msg(32)); else
    printf("%s%s%s",msg(27),msg(30),msg(31));
  if (lamp)
    sprintf(url,"%s/set/lamp/off?uid=%s",ip,uid); else
    sprintf(url,"%s/set/lamp/on?uid=%s",ip,uid);
  rc = openwebpage(url,0);
  free(url);
  if (rc != 0) printf(msg(9));
  pause(27,msg(10));
}

// on/off ventilator output
void f12(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(24);
  ventilator = ! ventilator;
  if (ventilator)
    printf("%s%s%s",msg(28),msg(30),msg(32)); else
    printf("%s%s%s",msg(28),msg(30),msg(31));
  if (ventilator)
    sprintf(url,"%s/set/ventilator/off?uid=%s",ip,uid); else
    sprintf(url,"%s/set/ventilator/on?uid=%s",ip,uid);
  rc = openwebpage(url,0);
  free(url);
  if (rc != 0) printf(msg(9));
  pause(27,msg(10));
}

// on/off heater output
void f13(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(25);
  heater = ! heater;
  if (heater)
    printf("%s%s%s",msg(29),msg(30),msg(32)); else
    printf("%s%s%s",msg(29),msg(30),msg(31));
  if (heater)
    sprintf(url,"%s/set/heater/off?uid=%s",ip,uid); else
    sprintf(url,"%s/set/heater/on?uid=%s",ip,uid);
  rc = openwebpage(url,0);
  free(url);
  if (rc != 0) printf(msg(9));
  pause(27,msg(10));
}

// off all outputs
void f14(void)
{
  int rc;
  char *url = (char*) malloc(255);
  headerwithmenu(26);
  printf(msg(33));
  sprintf(url,"%s/set/all/off?uid=%s",ip,uid);
  rc = openwebpage(url,0);
  free(url);
  if (rc != 0) printf(msg(9));
  pause(27,msg(10));
}

// main function
void httptest(char *iip, char *iuid)
{
  strcpy(ip,iip);
  strcpy(uid,iuid);
  // menu
  headerwithmenu(0);
  bool repeat = true;
  char ch;
  while (repeat)
  {
    if (kbhit())
    {
      ch = getch();
      switch (ch)
      {
        case '1': f01(); headerwithmenu(0); break;
        case '2': f02(); headerwithmenu(0); break;
        case '3': f03(); headerwithmenu(0); break;
        case '4': f04(); headerwithmenu(0); break;
        case '5': f05(); headerwithmenu(0); break;
        case '6': f06(); headerwithmenu(0); break;
        case '7': f07(); headerwithmenu(0); break;
        case '8': f08(); headerwithmenu(0); break;
        case '9': f09(); headerwithmenu(0); break;
        case 'a': f10(); headerwithmenu(0); break;
        case 'b': f11(); headerwithmenu(0); break;
        case 'c': f12(); headerwithmenu(0); break;
        case 'd': f13(); headerwithmenu(0); break;
        case 'e': f14(); headerwithmenu(0); break;
      }
      if (ch == 'q') repeat = false;
    }
  }
}