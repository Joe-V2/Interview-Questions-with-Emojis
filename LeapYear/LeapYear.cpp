// LeapYear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "..\emojidefs.h"

🔢 🌍()
{
	👀
	{
	🖨 << "Enter a year:" << 🔚;
	🔢 📆 = 0;
	🖋 >> 📆;
	🖨 << "Year " << 📆 << " is ";
	📧 🧾;
	switch (📆 % 400 == 0 || 📆 % 4 == 0)
	{
	case 👍:
		🧾 = "TOTALLY";
		🛑;
	case 👎:
		🧾 = "NOT";
		🛑;
	}
	🖨 << 🧾 << " a leap year!" << 🔚;
	}

		😵(const std::exception& e)
	{
		🖨 << "ERROR: " << e.what() << 🔚;
		return 1;
	}

	return 0;
}