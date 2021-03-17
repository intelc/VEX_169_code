void statBlockL(){
	varSysTime1 = nSysTime;
 	roller_stat=2;
	mogo_stat=3;
	chain_stat=2;
	arm_stat=3;
	drive_stat=2;
	intake();
	writeDebugStreamLine("Autonomous has started");
	Mogoin();


	InitPIDArm(0.35, 0.02, 0.9,20)
	PIDArmTarget(2400);
	InitPIDDrive(0.55, 0.02, 3, 0);
	pidForwardLeft(18,35);
	fbarflagraw=1;
	WFD();
	drive_stat=3;
		AutoDriveLV = 80;
AutoDriveRV = 80;
	wait10msec(40);
	AutoDriveLV = 0;
AutoDriveRV = 0;
	PIDArmTarget(1800);
	wait10msec(10);

AutoDriveLV = 5;
AutoDriveRV = 5;
	outtake();
	wait10msec(10);
	PIDArmTarget(2500);
	wait10msec(50);
	fbarflagraw=0;
	wait10msec(10);
	PIDArmTarget(1500);


	drive_stat=2;

	pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(2.2, 2, 1.9, 0); // with mogo 50
	InitPIDDrive(1.5, 2, 1.9, 0); //with mogo 100
	GyroRight(90,80);
	WFD();
	InitPIDDrive(0.55, 0.02, 3, 0);
	pidBackwardLeft(25,80);
	WFD();

	pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(2.2, 2, 1.9, 0); // with mogo 50
	GyroRight(48,50);
  WFD();

	drive_stat=3;
		AutoDriveLV = -100;
AutoDriveRV = -100;
	wait10msec(250);

	AutoDriveLV = 0;
AutoDriveRV = 0;








	wait10msec(10000);
	//wait10msec(500);
	drive_stat=1;

}
