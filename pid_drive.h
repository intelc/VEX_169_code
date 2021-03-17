


int driveL_driver_control;
int driveR_driver_control;



void SetDriveL(int power){
	DriveL_driver_control = power;
}

void SetDriveR(int power){
	DriveR_driver_control = power;
}

void PIDDriveClear(){
	pid_left_drive.pidError      = 0;
	pid_left_drive.pidLastError  = 0;
	pid_left_drive.pidIntegral   = 0;
	pid_left_drive.pidDerivative = 0;
}

void PIDDriveMaxMin(int maxmin){

	pid_left_drive.PID_DRIVE_MAX = maxmin;
	pid_left_drive.PID_DRIVE_MIN = -maxmin;
	pid_right_drive.PID_DRIVE_MAX = maxmin;
	pid_right_drive.PID_DRIVE_MIN = -maxmin;
}
void PIDDriveStraightMode(){
	pid_left_drive.pid_sensor=1;
	pid_left_drive.pid_method=1;

	pid_right_drive.pid_sensor=2;
	pid_right_drive.pid_method=2;
}
void PIDDriveStraightLeftMode(){
	pid_left_drive.pid_sensor=1;
	pid_left_drive.pid_method=7;


}
void PIDDriveStraightLeftBack(){
	pid_left_drive.pid_sensor=1;
	pid_left_drive.pid_method=7;


}
void PIDDriveTurnMode(){
	pid_left_drive.pid_sensor=4;
	pid_left_drive.pid_method=4;

	pid_right_drive.pid_sensor=4;
	pid_right_drive.pid_method=4;
}
void InitPIDDrive(float localKp, float localKi, float localKd, int localOffset){
	pid_left_drive.Kp = localKp;
	pid_left_drive.Ki = localKi;
	pid_left_drive.Kd = localKd;
	//pid_left_drive.pid_running =true;
	pid_left_drive.pidOffset = localOffset;

	pid_right_drive.Kp = localKp;
	pid_right_drive.Ki = localKi;
	pid_right_drive.Kd = localKd;
	//pid_right_drive.pid_running =true;
	pid_right_drive.pidOffset = localOffset;
}
void PIDDriveLTarget(int localTarget){
	pid_left_drive.pid_target = localTarget;
}
void PIDDriveRTarget(int localTarget){
	pid_right_drive.pid_target = localTarget;
}

task drive_control(){

pid_left_drive.PID_DRIVE_MAX = 127;
pid_left_drive.PID_DRIVE_MIN = -127;
pid_left_drive.PID_INTEGRAL_LIMIT = 100;

pid_right_drive.PID_DRIVE_MAX = 127;
pid_right_drive.PID_DRIVE_MIN = -127;
pid_right_drive.PID_INTEGRAL_LIMIT = 100;

pid_left_drive.pid_sensor=1;
pid_left_drive.pid_method=1;

pid_right_drive.pid_sensor=2;
pid_right_drive.pid_method=2;

pid_left_drive.pid_running = false;
pid_right_drive.pid_running =false;
//writeDebugStreamLine("driverstat %d",drive_stat);
	while(true){

		//writeDebugStreamLine("driveR_driver_control %d",driveR_driver_control);
		//writeDebugStreamLine("driveL_driver_control %d",driveL_driver_control);

		if (drive_stat==1){

		//	writeDebugStreamLine("drive normal running");

			LeftDrive(DriveL_driver_control);
			RightDrive(DriveR_driver_control);
		}

		else if(drive_stat==2){
		//	writeDebugStreamLine("drive pid running");
			if( pid_left_drive.pid_running )
		{
			// Read the sensor value and scale
			pid_left_drive.pidSensorCurrentValue = get_pid_sensor(pid_left_drive.pid_sensor) ;

			// calculate error
			pid_left_drive.pidError = pid_left_drive.pid_target - pid_left_drive.pidSensorCurrentValue;

			// integral - if Ki is not 0
			if( pid_left_drive.Ki != 0 )
			{
				// If we are inside controlable window then integrate the error
				if( abs(pid_left_drive.pidError) < pid_left_drive.PID_INTEGRAL_LIMIT )
					pid_left_drive.pidIntegral = pid_left_drive.pidIntegral + pid_left_drive.pidError;
				else
					pid_left_drive.pidIntegral = 0;
			}
			else
				pid_left_drive.pidIntegral = 0;

			// calculate the derivative
			pid_left_drive.pidDerivative = pid_left_drive.pidError - pid_left_drive.pidLastError;
			pid_left_drive.pidLastError  = pid_left_drive.pidError;

			// calculate drive
			pid_left_drive.pidDrive = pid_left_drive.pidOffset+(pid_left_drive.Kp * pid_left_drive.pidError) + (pid_left_drive.Ki * pid_left_drive.pidIntegral) + (pid_left_drive.Kd * pid_left_drive.pidDerivative);

			// limit drive
			if( pid_left_drive.pidDrive > pid_left_drive.PID_DRIVE_MAX )
				pid_left_drive.pidDrive = pid_left_drive.PID_DRIVE_MAX;
			if( pid_left_drive.pidDrive < pid_left_drive.PID_DRIVE_MIN )
				pid_left_drive.pidDrive = pid_left_drive.PID_DRIVE_MIN;

			// send to motor
			pid_method_switch(pid_left_drive.pid_method,pid_left_drive.pidDrive);
		}
			if( pid_right_drive.pid_running )
		{
			// Read the sensor value and scale
			pid_right_drive.pidSensorCurrentValue = get_pid_sensor(pid_right_drive.pid_sensor) ;

			// calculate error
			pid_right_drive.pidError = pid_right_drive.pid_target - pid_right_drive.pidSensorCurrentValue;

			// integral - if Ki is not 0
			if( pid_right_drive.Ki != 0 )
			{
				// If we are inside controlable window then integrate the error
				if( abs(pid_right_drive.pidError) < pid_right_drive.PID_INTEGRAL_LIMIT )
					pid_right_drive.pidIntegral = pid_right_drive.pidIntegral + pid_right_drive.pidError;
				else
					pid_right_drive.pidIntegral = 0;
			}
			else
				pid_right_drive.pidIntegral = 0;

			// calculate the derivative
			pid_right_drive.pidDerivative = pid_right_drive.pidError - pid_right_drive.pidLastError;
			pid_right_drive.pidLastError  = pid_right_drive.pidError;

			// calculate drive
			pid_right_drive.pidDrive = pid_right_drive.pidOffset+(pid_right_drive.Kp * pid_right_drive.pidError) + (pid_right_drive.Ki * pid_right_drive.pidIntegral) + (pid_right_drive.Kd * pid_right_drive.pidDerivative);

			// limit drive
			if( pid_right_drive.pidDrive > pid_right_drive.PID_DRIVE_MAX )
				pid_right_drive.pidDrive = pid_right_drive.PID_DRIVE_MAX;
			if( pid_right_drive.pidDrive < pid_right_drive.PID_DRIVE_MIN )
				pid_right_drive.pidDrive = pid_right_drive.PID_DRIVE_MIN;

			// send to motor
			pid_method_switch(pid_right_drive.pid_method,pid_right_drive.pidDrive);
		}

		}

		else if(drive_stat==3){
			LeftDrive(AutoDriveLV);
			RightDrive(AutoDriveRV);

		}

		else{
			LeftDrive(DriveL_driver_control);
			RightDrive(DriveR_driver_control);
		}





		wait1Msec( 25 );
	}
}
