char    str[32];
char 	side[9];
float BatteryExp;
float gyroval;
float fGyroAngle;

int AutoSelect;

task GyroCalc(){

	fGyroAngle = 0;
	long liTimer = nPgmTime;
	long printTimer = nPgmTime;

	while (true) {

		float fDeltaTime = (nPgmTime- liTimer)/1000.0
		liTimer = nPgmTime;

		if(nPgmTime - printTimer >= 100){

			printTimer = nPgmTime;
		}

		fGyroAngle -= gyroGetRate(Gyro1)* fDeltaTime;

		delay (1);
	}
}
void displayswitch(){
	switch(AutoSelect)
  {
  	case 0:
    //side="2cone20ptL"
    sprintf(side, "2cone20pL");
    //2cone20ptL();
  	break;
   	case 1:
   // side="2cone5ptL"
    sprintf(side, "2cone5pL");
    //2cone5ptL();
  	break;
  	case 2:
   // side="3cone5ptL"
    sprintf(side, "3cone5pL");
    //3cone5ptL();
  	break;
  	case 3:
    //side="3cone10ptL"
    sprintf(side, "3cone10pL");
    //3cone10ptL();
  	break;
  	case 4:
  //	side="1coneDEFL"
  	sprintf(side, "1coneDEFL");
    //1coneDEFL();
  	break;
  	case 5:
    //side="2cone20ptR"
    sprintf(side, "2cone20pR");
    //2cone20ptR();
  	break;
   	case 6:
   // side="2cone5ptR"
    sprintf(side, "2cone5pR");
    //2cone5ptR();
  	break;
  	case 7:
    // side="3cone5ptR"
    sprintf(side, "3cone5pR");
    //3cone5ptR();
  	break;
  	case 8:
    //side="3cone10ptR"
    sprintf(side, "3cone10pR");
    //3cone10ptR();
  	break;
  	case 9:
  	//side="1coneDEFR"
  	sprintf(side, "1coneDEFR");
    //1coneDEFR();
  	break;
  	default:

  		sprintf(side, "nothing");
		writeDebugStream("auto_switch ERROR");
	}
}
/*
task LCD()
{
	int lastLCDDisplayTime1;


	while(true)
	{
		Autoselect= (int)(SensorValue[in6]/340);
		BatteryExp= SensorValue[in5]/280.00;
		displayswitch()


			if (nSysTime > lastLCDDisplayTime1+100) {
			clearLCDLine(0);                      // Clear line 1 (0) of the LCD
			clearLCDLine(1);                      // Clear line 2 (1) of the LCD
			bLCDBacklight = true;






				sprintf( str, "C.%2.1fE.%2.1f %4.1f", nImmediateBatteryLevel/1000.0, BatteryExp,fGyroAngle );
				displayLCDString(0, 0, str);
				//sprintf( str, "%4.1f",fGyroAngle); ///,
					sprintf( str, "time %d", varSysTime2-varSysTime1 );
				displayLCDString(1, 0,str );








			lastLCDDisplayTime1 = nSysTime;

		}
	}

}
*/

task LCD(){

  while(true){

    LCDMain();
  }
}