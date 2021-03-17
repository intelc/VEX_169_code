void DriverFunc(){


if(vexRT[Btn7LXmtr2]){
			if (musicflag==0){
				playSoundFile("getit2.wav");
				musicflag=1;
			}
			else if (musicflag==1){
				musicflag=1;
			}
		}
		else if(vexRT[Btn7RXmtr2]){
			if (musicflag==0){
				musicflag=0;
			}
			else if (musicflag==1){
				clearSounds();
				musicflag=0;
			}
		}

if(vexRT[Btn7U]){
	arm_stat=4;
	chain_stat=2;
	roller_stat=2;
	autostack_stat=1;
	if(autostack_running==0){
	autostack_running=1;
	startTask(autostack);
}
}

if(vexRT[Btn7D]){
	arm_stat=4;
	chain_stat=2;
	roller_stat=2;
	autostack_stat=2;
	if(autostack_running==0){
	autostack_running=1;
	startTask(autostack);
}
}
if(vexRT[Btn8U]){

driverflag=2;
	}

if(vexRT[Btn8D]){
stopTask(runauto);
is_auto_running=0;
driverflag=1;
	}



	if(vexRT[Btn7L]){
	stopTask(autostack);
	autostack_running=0;
	arm_stat=1;
	chain_stat=1;
	roller_stat=1;

	}

//writeDebugStreamLine("driverstat %d",drive_stat);
//writeDebugStreamLine("driverflag %d",driverflag);


	if (abs(vexRT[Ch3])>5){

			SetDriveL(vexRT[Ch3]);


		}

		else{

			SetDriveL(0);

		}

		if (abs(vexRT[Ch2])>5){

			SetDriveR(vexRT[Ch2]);


		}

		else{

			SetDriveR(0);
		}



	if (abs(vexRT[Ch3Xmtr2])>15){

			PIDArmOff();
			if (arm_stat!=4){
			arm_stat=1;
			}
			if((vexRT[Ch3Xmtr2]<15)&&(vexRT[Ch3Xmtr2]>10)){
				SetArm(15);

			}
			else{
				SetArm(vexRT[Ch3Xmtr2]);
			}

			PIDArmTarget(SensorValue[ArmPot]);

	}

	else{
		int whatshouldoffsetbe;

		if((SensorValue[ArmPot]<1500)){
				whatshouldoffsetbe =-25;
		}
			else{
			whatshouldoffsetbe = 15;
		}
		if (arm_stat!=4){
			arm_stat=3;
		}
		//	InitPIDArm(0.3, 0.0001, 0.2, whatshouldoffsetbe)
			InitPIDArm(0, 0, 0, whatshouldoffsetbe)

		}

	///////////////////////////////////////////////////////////


//////////////////////////



		if((SIXUPPRESSED1==0)&&(vexRT[Btn6UXmtr2]==1)){
			if(fbarflag==0){
				fbarflag=1;
			}
			else if(fbarflag==1)
				fbarflag=0;
		}

		//////////////////////

		if(vexRT[Btn6UXmtr2]){
			SIXUPPRESSED1=1;
		}
		else if(vexRT[Btn6UXmtr2]==0){
			SIXUPPRESSED1=0;
		}


		if((SIXUPPRESSED2==0)&&(vexRT[Btn6U]==1)){
			if(mogoflag==0){
				mogoflag=1;
			}
			else if(mogoflag==1)
				mogoflag=0;
		}

		//////////////////////

		if(vexRT[Btn6U]){
			SIXUPPRESSED2=1;
		}
		else if(vexRT[Btn6U]==0){
			SIXUPPRESSED2=0;
		}

/*
			if((SIXUPPRESSED3==0)&&(vexRT[Btn6DXmtr2]==1)){
			if(rollerflag==0){
				rollerflag=1;
			}
			else if(rollerflag==1){
				rollerflag=0;
				ReverseRoller();
	}
		}


		if(vexRT[Btn6DXmtr2]){
			SIXUPPRESSED3=1;
		}
		else if(vexRT[Btn6DXmtr2]==0){
			SIXUPPRESSED3=0;
		}

*/
		buttonRoller()






}




void usercontrolbody(){

	/////////////////////////////////////////////
	driverflag=1;
	linearflag=0;
	fbarflag=0;
	rollerflag=1;
	mogoflag=1;
	SIXUPPRESSED1=0;
	arm_stat=1;
	mogo_stat=1;
	chain_stat=1;
	roller_stat=1;
	drive_stat=1;
	autostack_stat=0;
	SIXUPPRESSED3=0;
	autostack_running=0;
	fGyroAngle = 0;
	musicflag=0;
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
	startTask(LCD);

	PIDArmTarget(SensorValue[ArmPot]);


	//startTask(LCD);
	/////////////////////////////////////////////
  while(true){

  		if (driverflag==1){

  			DriverFunc();

  		}
  		else if(driverflag==2){

  			while(vexRT[Btn8D]!=1&&driverflag==2){

  				if(is_auto_running==0){

  					startTask(runauto);
  					is_auto_running=1;

  				}
  				else if(is_auto_running==1){

  					is_auto_running=1;

  				}

  				else if(is_auto_running==2){
  					stopTask(runauto);
  					is_auto_running=0;
  					roller_stat=1;
						mogo_stat=1;
						chain_stat=1;
						arm_stat=1;
						drive_stat=1;
  					driverflag=1;


  				}

  			}
  			is_auto_running=0;
  			driverflag=1;

  		}
  		else if(driverflag==3){

  			while(vexRT[Btn8D]!=1){

  				if(is_prog_running==0){

  					startTask(runprog);
  					is_prog_running=1;

  				}
  				else if(is_prog_running==1){

  					is_prog_running=1;

  				}

  				else if(is_prog_running==2){

  					driverflag=1;
  					is_prog_running=0;
  				}

  			}

  			driverflag=1;
  		}
  		else if(driverflag==4){

  			while(vexRT[Btn8D]!=1){

  				if(is_place_running==0){

  					startTask(runautoplace);
  					is_place_running=1;

  				}
  				else if(is_place_running==1){

  					is_place_running=1;

  				}

  				else if(is_place_running==2){

  					driverflag=1;
  					is_place_running=0;

  				}

  			}

  			driverflag=1;
  		}
  		else if(driverflag==5){

  			while(vexRT[Btn8D]!=1){

  				if(is_load_running==0){

  					startTask(runautoload);
  					is_load_running=1;

  				}
  				else if(is_load_running==1){

  					is_load_running=1;

  				}

  				else if(is_load_running==2){

  					driverflag=1;
  					is_load_running=0;

  				}

  			}

  			driverflag=1;
  		}


	}

}
