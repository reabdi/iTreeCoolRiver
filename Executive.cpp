#include <iostream>
#pragma warning(disable:4996)
#include <string>
#include "TemperaturePrime.h"
#include "SolarCalculation.h"			// Added by Reza Abdi (Jan. 17)
#include "StreamTemperature.h"			// Added by Reza Abdi (Jan. 17)
#include "TemperatureInputRepo.h"		// Added by Reza Abdi (Jan. 17)
#include <float.h>
//unsigned int fp_control_state = _controlfp(_EM_INEXACT, _MCW_EM);

#include <math.h>
//#ifdef RUN
int main(int argc, char* argv[])
{
	try
	{
		std::string configFile = "";
		std::ofstream logfile("log.txt");
		logfile << "===============================================================================\n";
		logfile.close();
		if (argc <= 1) {
			std::ofstream logfile("log.txt");
			logfile << "Please specify the path of the configuration file needed to run simulation.\n";
			logfile.close();
			std::cout << "Please specify the path of the configuration file" << std::endl;
			std::getline(std::cin, configFile);
		}
		else
		{
			configFile = argv[1];
		}
		// End of Timestep change code by Pallavi Iyengar

		
		/*Run Temperature Simulation*/
		TemperatureInputs *input= new TemperatureInputs(configFile); 
		Temperature runCoolRiverSimulation(input);
		runCoolRiverSimulation.run();


		std::cout << std::endl << "Hit any key and then press enter to close." << std::endl;
		std::cin.get();
		delete input;
		return 1;
	}
	catch (std::exception &ex)
	{
		std::ofstream logfile("log.txt", ios::app);
		logfile << "Simulation could not be run. " << ex.what();
		logfile.close();
		std::cout << "Simulation could not be run. " <<ex.what()<<std::endl;
		return 0;
	}
	catch (...)
	{
		std::ofstream logfile("log.txt", ios::app);
		logfile << "Simulation could not be run. ";
		logfile.close();
		std::cout << "Simulation could not be run." << std::endl;
		return 0;
	}


}
//#endif