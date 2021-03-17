

void autonomousbody(){

	fGyroAngle = 0;
	startTask(MotorSlewRateTask);
	startTask(arm_control);
	startTask(fbar_control);
	startTask(roller_control);
	startTask(mogo_control);
	startTask(drive_control);
	startTask(piddriveend);
	startTask(GyroCalc);
	LCDStartup();
	backToMainMenu();
	currentDigitalSlideNumber = 1;
	currentAnalogSlideNumber = 1;
	resetEncoders();
	//startTask(LCD);
	/*
	switch(selectedAutoNumber){
		case 0;
		    //PlayTone(700, 50);
		a5P3CL();
			break;
		case 1:
			a5P3CR();
			//PlayTone(500, 50);
			break;
		case 2:
		//PlayTone(300, 50);
			a10P3CL();
			break;
		case 3:
			a10P3CR();
			break;
		case 4:
			a20P3CL();
			break;
		case 5:
			a20P3CR();
			break;
		case 6:
			a5P7CL();
			break;
		case 7:
			a5P7CR();
			break;
		case 8:
			a10P6CL();
			break;
		case 9:
			a10P6CR();
			break;
		case 10:
			a20P5CL();
			break;
		case 11:
			a20P5CR();
			break;
		case 12:
			statBlockL();
			break;
		case 13:
			statBlockR();
			break;
		case 14:
			a5P3LDL();
			break;
		case 15:
			a5P3LDR();
			break;
		case 16:
			a20P3SL();
			break;
		case 17:
		a20P3SR();
			break;
	}

*/
a20P5CR();
is_auto_running=2;
}
