void a20P5CR(){
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
	pidForwardLeft(30,110);
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
	pidBackwardLeft(16.5,100);
	while(SensorValue[mogopot]<1450){
		wait1msec(1);
	}
	PIDArmTarget(1800);
	outtake();
	wait10Msec(20);
fbarflagraw=0;
WFD();
pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(2.2, 2, 1.9, 0); // with mogo 50
	//InitPIDDrive(1.1, 2, 1.9, 0); //without mogo 100
	GyroRight(55,65);
PIDArmTarget(1900);

intake();

PIDArmTarget(1900);




	intake();



	WFD();
	drive_stat=3;
	AutoDriveLV = 80;
AutoDriveRV = 80;
wait10Msec(10);
	AutoDriveLV = 20;
AutoDriveRV = 20;

	loadstack(1540, 2000);

	//////////2
	loadstack(1610, 2050);

	//////////3
	loadstack(1660, 2100);

	//////////4
	loadstack(1720, 2150);

	//////////5
	//loadstack(1790, 1980);
	//////////6

fbarflagraw=1;

wait10Msec(7);


	PIDArmTarget(1600);
	INtake();

	while(SensorValue[ArmPot]>1700){
		wait1Msec(1);
		}
clearTimer(T4)
		while((SensorValue[RollerButton]==0)&&(time10[T4] < 45)){
		wait1Msec(1);
		}
		wait1Msec(5);

PIDArmTarget(1850);

	drive_stat=2;
	pid_Left_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(5, 2, 1.9, 0); // with mogo 50
	GyroLeft(24,32);
	WFD();
	InitPIDDrive(0.55, 0.02, 3.5, 0);
	pidBackwardLeft(42,165);
	fbarflagraw=0;
	while(SensorValue[FbarPot]<1950){
		wait1Msec(1);
		}

		PIDArmTarget(1500);
wait10Msec(10);
	outtake();
	wait10Msec(10);
	PIDArmTarget(1890);
	WFD();

	pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(1.7, 2, 1.9, 0); //with mogo 100
	GyroRight(123,115);
	wait10Msec(50);
	mogoout();
	WFD();


	WFD();


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









	wait10msec(10000);
	//wait10msec(500);
	drive_stat=1;

}
