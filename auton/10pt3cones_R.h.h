void a10P3CR(){
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
	drive_stat=2;


	mogoin();

	while(SensorValue[mogopot]<1300){
		wait1msec(1);
	}
	PIDArmTarget(1800);
	outtake();


PIDArmTarget(1900);

intake();
	drive_stat=3;
	AutoDriveLV = 65;
AutoDriveRV = 65;
PIDArmTarget(1900);

	while(SensorValue[UltraMogo]>18){
		wait1Msec(1);
		}

	AutoDriveLV = -5;
AutoDriveRV = -5;

	drive_stat=2;
	intake();
	PIDArmTarget(1100);

		while(SensorValue[ArmPot]>1250){
		wait1Msec(1);
		}
		clearTimer(T4)
	while((SensorValue[RollerButton]==0)&&(time10[T4] < 20)){
		wait1Msec(1);
		}
		wait1Msec(5);
	PIDArmTarget(1400);
	drive_stat=2;
	pid_Left_drive.PID_INTEGRAL_LIMIT = 10;
	InitPIDDrive(1.3, 2, 1.5, 0); //with mogo 100
	GyroABS(-3,20);
	WFD();

	drive_stat=3;
	AutoDriveLV = 50;
	AutoDriveRV = 50;

		while(SensorValue[ArmPot]<1350){
		wait1Msec(1);
		}
	fbarflagraw=0;

	while(SensorValue[UltraMogo]>18){
		wait1Msec(1);
	}
	AutoDriveLV = -5;
	AutoDriveRV = -5;



	while(SensorValue[FbarPot]<2150){
		wait1Msec(1);
		}
	outtake();
	wait10Msec(30);



	PIDArmTarget(1600);
	fbarflagraw=1;
	wait10Msec(20);
	PIDArmTarget(1100);
	intake();

	while(SensorValue[ArmPot]>1250){
		wait1Msec(1);
		}
	clearTimer(T4)
	while((SensorValue[RollerButton]==0)&&((time10[T4] < 30))){
		wait1Msec(1);
		}
		wait1Msec(5);
	PIDArmTarget(1580);

	AutoDriveLV = -60;
	AutoDriveRV = -60;

	while(SensorValue[ArmPot]<1500){
		wait1Msec(1);
		}
	fbarflagraw=0;
PIDArmTarget(1530);
	while(SensorValue[FbarPot]<2250){
		wait1Msec(1);
		}
	outtake();


	drive_stat=2;
	InitPIDDrive(0.55, 0.02, 3, 0);
	pidBackwardLeft(30,130);
	WFD();
	pid_right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(2.2, 2, 1.9, 0); // with mogo 50
	//InitPIDDrive(1.1, 2, 1.9, 0); //without mogo 100
	GyroRight(55,60);
	WFD();
	
	pidBackwardLeft(20,80);
	WFD();
	outtake();
	PIDArmTarget(1900);
	InitPIDArm(0.3, 0.01, 0.7,20);
	pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(1.7, 2, 1.9, 0); //with mogo 100
	GyroRight(121,115);
	wait10Msec(50);
	mogoout();
	WFD();


	WFD();


	drive_stat=3;
	AutoDriveLV = 40;
	AutoDriveRV = 40;



	while(SensorValue[MogoPot]>800){
		wait1Msec(1);
		}

		AutoDriveLV = -90;
	AutoDriveRV = -90;
	wait10Msec(40);
varSysTime2 = nSysTime;
AutoDriveLV = 0;
	AutoDriveRV =0;
	AutoDriveRV = 0;










}