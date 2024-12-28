#include "appli.h"

CAppli appli;

void setup() 
{
	appli.Init();
	
}

void loop() 
{
 	appli.RunProcess(10000);
	appli.RunIhm();
}
