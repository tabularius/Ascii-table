
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>


void header();
void horizontal_line(int length);
void ascii_table();
void pause_scroll();

const char VLine = 179;
const char HLine = 196;
const int NoOfLines = 23;

int main()
{
	ascii_table();
	return 0;
}

void pause_scroll()
{
	std::cout << std::endl;
	std::cout << "Press any key to continue...";
	getchar();
	std::cout << std::endl;
}

void horizontal_line(int length)
{
	for (int i = 1; i < length; i++) std::cout << HLine;
	std::cout << std::endl;
}

void header()
{
	horizontal_line(NoOfLines);
	std::cout << VLine << " CHR " << VLine << " DEC" << VLine << " HEX" << VLine << " OCT" << VLine << std::endl;
	horizontal_line(NoOfLines);
}

void ascii_table()
{
	int AsciiNumberLength;
	std::string AsciiNumber;
	std::ostringstream convert;
	
	int numItems = 0;
	std::string SpecialChar[32];
	
	SpecialChar[numItems++] = "NUL";
	SpecialChar[numItems++] = "SOH";
	SpecialChar[numItems++] = "STX";
	SpecialChar[numItems++] = "ETX";
	SpecialChar[numItems++] = "EOT";
	SpecialChar[numItems++] = "ENQ";
	SpecialChar[numItems++] = "ACK";
	SpecialChar[numItems++] = "BEL";
	SpecialChar[numItems++] = " BS";
	SpecialChar[numItems++] = " HT";
	SpecialChar[numItems++] = " LF";
	SpecialChar[numItems++] = " VT";
	SpecialChar[numItems++] = " FF";
	SpecialChar[numItems++] = " CR";
	SpecialChar[numItems++] = " SO";
	SpecialChar[numItems++] = " SI";
	SpecialChar[numItems++] = "DLE";
	SpecialChar[numItems++] = "DC1";
	SpecialChar[numItems++] = "DC2";
	SpecialChar[numItems++] = "DC3";
	SpecialChar[numItems++] = "DC4";
	SpecialChar[numItems++] = "NAK";
	SpecialChar[numItems++] = "SYN";
	SpecialChar[numItems++] = "ETB";
	SpecialChar[numItems++] = "CAN";
	SpecialChar[numItems++] = " EM";
	SpecialChar[numItems++] = "SUB";
	SpecialChar[numItems++] = "ESC";
	SpecialChar[numItems++] = " FS";
	SpecialChar[numItems++] = " GS";
	SpecialChar[numItems++] = " RS";
	SpecialChar[numItems++] = " US";

	header();


	for (int counter = 0; counter < 256; counter++)
	{
		if (counter < 32)
		{
			std::cout << VLine << " " << SpecialChar[counter] << " " << VLine;
			convert.str("");
			convert << std::dec << counter;
			AsciiNumber = convert.str();
			AsciiNumberLength = AsciiNumber.size();
			while (AsciiNumberLength < 4)
			{
				AsciiNumber.insert(0," ");
				AsciiNumberLength++;
			}
			std::cout << AsciiNumber << VLine << " ";
			
			convert.str("");
			convert << std::hex << counter;
			AsciiNumber = convert.str();
			AsciiNumberLength = AsciiNumber.size();
			while (AsciiNumberLength < 3)
			{
				AsciiNumber.insert(0, " ");
				AsciiNumberLength++;
			}
			std::cout << AsciiNumber << VLine << " ";

			convert.str("");
			convert << std::oct << counter;
			AsciiNumber = convert.str();
			AsciiNumberLength = AsciiNumber.size();
			while (AsciiNumberLength < 3)
			{
				AsciiNumber.insert(0, " ");
				AsciiNumberLength++;
			}
			std::cout << AsciiNumber << VLine;

			std::cout << std::endl;
			horizontal_line(NoOfLines);
			if (((counter+1) % 10) == 0)
			{
				pause_scroll();
				header();
			}
		}
		
		else
		{
			std::cout << VLine << "  " << char(counter) << "  " << VLine;
			
			convert.str("");
			convert << std::dec << counter;
			AsciiNumber = convert.str();
			AsciiNumberLength = AsciiNumber.size();
			while (AsciiNumberLength < 4)
			{
				AsciiNumber.insert(0, " ");
				AsciiNumberLength++;
			}
			std::cout << AsciiNumber << VLine;

			convert.str("");
			convert << std::hex << counter;
			AsciiNumber = convert.str();
			AsciiNumberLength = AsciiNumber.size();
			while (AsciiNumberLength < 4)
			{
				AsciiNumber.insert(0, " ");
				AsciiNumberLength++;
			}
			std::cout << AsciiNumber << VLine;

			convert.str("");
			convert << std::oct << counter;
			AsciiNumber = convert.str();
			AsciiNumberLength = AsciiNumber.size();
			while (AsciiNumberLength < 4)
			{
				AsciiNumber.insert(0, " ");
				AsciiNumberLength++;
			}
			std::cout << AsciiNumber << VLine;

			std::cout << std::endl;
			horizontal_line(NoOfLines);
			if (((counter + 1) % 10) == 0)
			{
				pause_scroll();
				header();
			}
		}
	}
}
