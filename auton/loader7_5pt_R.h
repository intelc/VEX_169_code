void a5P7CR(){
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
	pidBackwardLeft(16,100);
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
	GyroRight(50,60);
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

			//////////1
	loadstack(1520, 1800);

	//////////2
	loadstack(1600, 2300);

	//////////3
	loadstack(1660, 1850);

	//////////4
	loadstack(1760, 1980);

	//////////5
	loadstack(1790, 1980);
	//////////6
	loadstack(1860, 2100);
	//////////7
	fbarflagraw=1;
wait10Msec(15);
	PIDArmTarget(1600);
	INtake();

	while(SensorValue[ArmPot]>1700){
		wait1Msec(1);
		}

	while(SensorValue[RollerButton]==0){
		wait1Msec(1);
		}
		wait1Msec(5);
		drive_stat=2;
	pid_Left_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(5, 2, 1.9, 0); //with mogo 100
	GyroLeft(270,200);
	PIDArmTarget(2050);
	
wait10Msec(30);
	fbarflagraw=0;
	mogoout();
	while(SensorValue[FbarPot]<1850){
		wait1Msec(1);
		}

		PIDArmTarget(1200);
		fbarflagraw=1;
		wait10Msec(10);
		outtake();
		wait10Msec(5);
		PIDArmTarget(2500);
		fbarflagraw=0;




	WFD();
drive_stat=3;


while(SensorValue[MogoPot]>800){
		wait1Msec(1);
		}
		wait10Msec(10);
AutoDriveLV = -90;
	AutoDriveRV = -90;
	wait10Msec(15);
varSysTime2 = nSysTime;

AutoDriveLV = 0;
	AutoDriveRV =0;









	wait10msec(10000);
	//wait10msec(500);
	drive_stat=1;

}