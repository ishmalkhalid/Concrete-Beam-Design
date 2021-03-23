/*-------------------------------------------------*/
/* Name: Ishmal Khalid, Net ID: ik1299 */
/* Date: September 13, 2019. */
/* Program: Assignment.cpp */
/* Description: This program designs a rectangular beam. */
/*-------------------------------------------------*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// Declare and initialize the variables 
	double gk, qk, L, h, b, Ws, TCPA, Wd, V, M;
	const double Cuw = 25;
	const double PERMANENT_LOAD_MARGIN = 0.60;
	const double VARIABLE_LOAD_MARGIN = 0.20;
	int choice;
	//Repeat while choice is not equal to -1	
	do {
			//Repeat while L, gk or qk is less than or equal to 0
		do{
				//Print and read beam specifications
				cout << "This software designs a rectangular beam. Enter the beam specifications:" << endl;

				cout << "Length (m): ";
				cin >> L;

				cout << "Permanent load (gk, kN/m): ";
				cin >> gk;

				cout << "Variable load (qk, kN/m): ";
				cin >> qk;

				//Validate specifications are positive

				if (L <= 0 || gk <= 0 || qk <= 0){
					cout << "Invalid selection. Please enter a positive value." << endl;
				}
		} while (L <= 0 || gk <= 0 || qk <= 0 );


				//Calculate dimensions

				h = (L / 14);  // Calculates depth
				b = (0.4*h);  // Calculates width

				//Calculate Total Characteristic Load

				Ws = h*b*Cuw;    // Calculates beam self-weight in kN/m
				TCPA = Ws + gk; // Calculates beam Total Characteristic Permanent Action

				//Calculate Shear Force and Bending Moment

				Wd = (1 + PERMANENT_LOAD_MARGIN)*gk + (1 + VARIABLE_LOAD_MARGIN)*qk; // Calculates Design Action
				V = Wd*L / 2;                        // Calculates Shear Force
				M = Wd*L*L / 8;                     // Calculates Bending Moment

				//Print calculated values
				cout << "Here is a summary of the beam design:" << endl;
				cout << "The minimum values for the size of the beam are:" << endl;
				cout << "Depth: " << ceil(h * 1000) << " mm" << endl;
				cout << "Width: " << ceil(b * 1000) << " mm" << endl;
				cout << "The total characteristic load: " << TCPA << " kN/m" << endl;
				cout << "Shear Force (V): " << V << " kN" << endl;
				cout << "Bending Moment (M): " << M << " kNm" << endl;

			//Print and read choice to repeat program
			cout << "Enter -1 to exit or any other number to repeat." << endl;
			cin >> choice;
			
	} while (choice!=-1 ); 
	return 0;
}