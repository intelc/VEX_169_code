int pidTicksConstant = 10;
int pidAnglesConstant = 6;
int killswitch_value = 0;
int piddrivestat=0;

void WFD(){
	while(piddrivestat!=0){
		wait1Msec(1);
	}
	pid_method_switch(pid_left_drive.pid_method,0)
	}
void killswitch(int time){
	killswitch_value = time;
}

task piddriveend(){
	while(true){
		if(drive_stat==2){
		if(piddrivestat!=0){
			if (time10(T3)>killswitch_value){
					pid_left_drive.pid_running = false;
 					pid_right_drive.pid_running = false;

 			if( piddrivestat==1){

			}
			else if(piddrivestat==2){
				pid_method_switch(pid_left_drive.pid_method,0);
			}
			else if(piddrivestat==3){
				pid_method_switch(pid_left_drive.pid_method,0);
				pid_method_switch(pid_right_drive.pid_method,0);
			}
			else if(piddrivestat==4){
				pid_method_switch(pid_right_drive.pid_method,0);
			}

			piddrivestat=0;
			}


		}
	}
		wait1Msec( 24 );
	}
}

int pidTicks(float distance){     ///// Courtesy of Aditya
	return(int)(360*distance/pidTicksConstant);
}

int pidAngles(float angles){     ///// Courtesy of Aditya
	return(int)(angles*pidAnglesConstant);
}
void EncoderReset(){
	SensorValue[QuadRight]=0;
	SensorValue[QuadLeft]=0;
}
void GyroABS(int angles,int time){
	piddrivestat=4;
//	fGyroAngle=0;
	PIDDriveTurnMode();

 	pid_right_drive.pid_target=(int)(angles);

 	pid_right_drive.pid_running = true;

 	clearTimer(T3);
	Killswitch(time);


}
void GyroRight(int angles,int time){
	piddrivestat=4;
//	fGyroAngle=0;
	PIDDriveTurnMode();

 	pid_right_drive.pid_target=(int)(fGyroAngle)+angles;

 	pid_right_drive.pid_running = true;

 	clearTimer(T3);
	Killswitch(time);


}
void GyroLeft(int angles,int time){
	piddrivestat=3;
	//fGyroAngle=0;
	PIDDriveTurnMode();

 	pid_left_drive.pid_target=(int)(fGyroAngle)-angles;

 	pid_left_drive.pid_running = true;

 	clearTimer(T3);
	Killswitch(time);


}
void LeftTurn45(){
	pid_left_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(2.2, 2, 1.9, 0); // with mogo 50
	//InitPIDDrive(1.1, 2, 1.9, 0); //without mogo 100
	GyroLeft(45,200);
}
void LeftTurn90(){
	pid_left_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(1.5, 2, 1.9, 0); //with mogo 100
	GyroLeft(100,160);
}
void LeftTurn135(){
	pid_left_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(1.5, 0.3, 2.5, 0); // with mogo 135
	GyroLeft(150,150);
}
void LeftTurn180(){
	pid_left_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(1.5, 0.3, 2.9, 0); // with mogo 180
	GyroLeft(200,200);
}

void RightTurn45(){
	pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(2.2, 2, 1.9, 0); // with mogo 50
	//InitPIDDrive(1.1, 2, 1.9, 0); //without mogo 100
	GyroRight(55,70);
}
void RightTurn90(){
	pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(1.7, 2, 1.9, 0); //with mogo 100
	GyroRight(113,90);
}
void RightTurn135(){
	pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(1.5, 0.3, 2.5, 0); // with mogo 135
	GyroRight(150,200);
}
void RightTurn180(){
	pid_Right_drive.PID_INTEGRAL_LIMIT = 5;
	InitPIDDrive(1.5, 0.3, 2.9, 0); // with mogo 180
	GyroRight(200,200);
}

void pidForward(int distance,int time){
 piddrivestat=1;
	PIDDriveStraightMode();

	EncoderReset();

	pid_left_drive.pid_target=pidTicks(distance);
 	pid_right_drive.pid_target=pidTicks(distance);

 	pid_left_drive.pid_running = true;
 	pid_right_drive.pid_running = true;
 	clearTimer(T3);
	Killswitch(time);




}

void pidForwardLeft(int distance,int time){
	piddrivestat=2;
	PIDDriveStraightLeftMode();

	EncoderReset();

	pid_left_drive.pid_target=pidTicks(distance);


 	pid_left_drive.pid_running = true;

	clearTimer(T3);
	Killswitch(time);


}
void pidBackwardLeft(int distance,int time){

	piddrivestat=2;
	PIDDriveStraightLeftBack();

	EncoderReset();

	pid_left_drive.pid_target=pidTicks(-distance);


 	pid_left_drive.pid_running = true;


  clearTimer(T3);
	Killswitch(time);

}


void pidBackward(int distance,int time){
  piddrivestat=1;
	PIDDriveStraightMode();

	EncoderReset();

	pid_left_drive.pid_target=pidTicks(-distance);
 	pid_right_drive.pid_target=pidTicks(-distance);

 	pid_left_drive.pid_running = true;
 	pid_right_drive.pid_running = true;

 	clearTimer(T3);
	Killswitch(time);

}
