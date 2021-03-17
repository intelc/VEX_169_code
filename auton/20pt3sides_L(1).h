void a20P3SL(){
	varSysTime1 = nSysTime;
 	roller_stat=2;
	mogo_stat=3;
	chain_stat=2;
	arm_stat=3;
	drive_stat=2;
	intake();
	writeDebugStreamLine("Autonomous has started");
	Mogoin();
	PIDArmTarget(1800);
	InitPIDArm(0.35, 0.02, 0.9,20)
//	wait10Msec(50);


	InitPIDDrive(0.55, 0.02, 3, 0);
	pidForwardLeft(28,100);
	while(SensorValue[ArmPot]<1200){
		wait1Msec(1);
		}
	mogoout();

	wait10msec(100);
	fbarflagraw=1;

	while(SensorValue[MogoPot]>800){
		wait1Msec(1);
		}
	WFD();
	drive_stat=3;
	AutoDriveLV = 60;
AutoDriveRV = 60;


	while(SensorValue[UltraMogo]>15){
		wait1Msec(1);
		}
	AutoDriveLV = 5;
	AutoDriveRV = 5;



	mogoin();
	wait10Msec(10);
	drive_stat=3;
	AutoDriveLV = -50;
	AutoDriveRV = -50;

	while(SensorValue[line1]>2000){
		wait1Msec(1);
		}

	AutoDriveLV = 8;
AutoDriveRV = 8;
wait10Msec(5);
drive_stat=2;
	pidBackwardLeft(30,120);
	while(SensorValue[mogopot]<1450){
		wait1msec(1);
	}
	PIDArmTarget(1800);
	outtake();
	wait10Msec(20);
fbarflagraw=1;
WFD();
pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(2.2, 2, 1.9, 0); // with mogo 50
	//InitPIDDrive(1.1, 2, 1.9, 0); //without mogo 100
	GyroRight(37,60);
PIDArmTarget(1900);

intake();
WFD();
drive_stat=3;
	AutoDriveLV = 60;
AutoDriveRV = 60;


	while(SensorValue[UltraMogo]>16){
		wait1Msec(1);
		}
	AutoDriveLV = -5;
	AutoDriveRV = -5;

///////1

fbarflagraw=1;
wait10Msec(7);

PIDArmTarget(1100);

		while(SensorValue[ArmPot]>1250){
		wait1Msec(1);
		}
		clearTimer(T4)
	while((SensorValue[RollerButton]==0)&&(time10[T4] < 20)){
		wait1Msec(1);
		}
		wait1Msec(5);
	PIDArmTarget(1450);
	drive_stat=2;
	InitPIDDrive(0.55, 0.02, 3, 0);
	pidForwardLeft(13,35);
	while(SensorValue[Armpot]<(1520-180)){
		wait1Msec(1);
	}
	fbarflagraw=0;
	while(SensorValue[FbarPot]<1520){
		wait1Msec(1);
		}
WFD();
pid_Left_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(2.2, 2, 1.9, 0); // with mogo 50
	//InitPIDDrive(1.1, 2, 1.9, 0); //without mogo 100
	GyroLeft(38,60);
		PIDArmTarget(1100);
		wait10Msec(10);
		outtake();
		wait10Msec(4);
		PIDArmTarget(1700);

	wait10Msec(10);
	////////1

	WFD();
		drive_stat=3;
	AutoDriveLV = 60;
AutoDriveRV = 60;


	while(SensorValue[UltraMogo]>15){
		wait1Msec(1);
		}
	AutoDriveLV = -5;
	AutoDriveRV = -5;

	//////2
	intake();
fbarflagraw=1;
wait10Msec(7);

PIDArmTarget(1100);

		while(SensorValue[ArmPot]>1250){
		wait1Msec(1);
		}
		clearTimer(T4)
	while((SensorValue[RollerButton]==0)&&(time10[T4] < 20)){
		wait1Msec(1);
		}
		wait1Msec(5);
	PIDArmTarget(1600);
	drive_stat=3;
	AutoDriveLV = 60;
AutoDriveRV = 60;
	while(SensorValue[Armpot]<(1520-180)){
		wait1Msec(1);
	}
	fbarflagraw=0;
	while(SensorValue[FbarPot]<1520){
		wait1Msec(1);
		}

		PIDArmTarget(1100);
		wait10Msec(10);
		outtake();
		while(SensorValue[UltraMogo]>15){
		wait1Msec(1);
		}
	AutoDriveLV = -5;
	AutoDriveRV = -5;
		wait10Msec(4);
		PIDArmTarget(1820);

	wait10Msec(10);
	////////2




		//////3
	intake();
fbarflagraw=1;
wait10Msec(7);

PIDArmTarget(1100);

		while(SensorValue[ArmPot]>1250){
		wait1Msec(1);
		}
		clearTimer(T4)
	while((SensorValue[RollerButton]==0)&&(time10[T4] < 20)){
		wait1Msec(1);
		}
		wait1Msec(5);
	PIDArmTarget(1660);
	while(SensorValue[Armpot]<(1520-180)){
		wait1Msec(1);
	}
	fbarflagraw=0;
	while(SensorValue[FbarPot]<1520){
		wait1Msec(1);
		}

		PIDArmTarget(1100);
		wait10Msec(10);
		outtake();
		wait10Msec(4);
		PIDArmTarget(1850);

	wait10Msec(10);
	////////3
drive_stat=2;

pid_Left_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(5, 2, 1.9, 0); // with mogo 50
	//InitPIDDrive(1.1, 2, 1.9, 0); //without mogo 100
	GyroLeft(15,30);

	wfd();
InitPIDDrive(0.55, 0.02, 3, 0);
	pidBackwardLeft(34,150);
	WFD();

	pid_Left_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(2.2, 2, 1.9, 0); // with mogo 50
	//InitPIDDrive(1.1, 2, 1.9, 0); //without mogo 100
	GyroLeft(150,170);
	wait10Msec(100);
	mogoout();

		drive_stat=3;
	AutoDriveLV = 90;
	AutoDriveRV = 90;

	while(SensorValue[UltraMogo]>30){
		wait1Msec(1);
	}


	while(SensorValue[MogoPot]>800){
		wait1Msec(1);
		}
		wait10Msec(20);
		AutoDriveLV = -45;
	AutoDriveRV = -45;
	wait10Msec(40);
varSysTime2 = nSysTime;
AutoDriveLV = 0;
	AutoDriveRV =0;


varSysTime2 = nSysTime;


	
}