


int arm_stat;
int arm_driver_control;

void SetArm(int power){
	arm_driver_control = power;
}

bool ready2stack(){
	if(SensorValue[UltraStack]<20){
	return false;
	}
	else if(SensorValue[UltraStack]>20){
		return true;
	}
	else{
		return false;
	}
}
void InitPIDArm(float localKp, float localKi, float localKd, int localOffset){
	pid_arm.Kp = localKp;
	pid_arm.Ki = localKi;
	pid_arm.Kd = localKd;
	pid_arm.pid_running =true;
	pid_arm.pidOffset = localOffset;
}
void PIDArmTarget(int localTarget){
	pid_arm.pid_target = localTarget;
}
void PIDArmOff(){

	pid_arm.pid_running =false;
}


task arm_control(){

pid_arm.PID_DRIVE_MAX = 127;
pid_arm.PID_DRIVE_MIN = -127;
pid_arm.PID_INTEGRAL_LIMIT = 30;
pid_arm.pid_sensor=5;
pid_arm.pid_method=6;

	while(true){



		if (arm_stat==1){


				if((arm_driver_control>0)&&(SensorValue[ArmPot]<2800)){
				Arm(arm_driver_control);
			}
			else if((arm_driver_control<0)&&(SensorValue[ArmPot]>1250)){
				Arm(arm_driver_control);
			}
			else{
				Arm(0);

			}

		}
		else if(arm_stat==2){
			writeDebugStreamLine("arm_stat=2");
		}
		else if(arm_stat==3){


				if( pid_arm.pid_running )
		{
			// Read the sensor value and scale
			pid_arm.pidSensorCurrentValue = get_pid_sensor(pid_arm.pid_sensor) ;

			// calculate error
			pid_arm.pidError = pid_arm.pid_target - pid_arm.pidSensorCurrentValue;

			// integral - if Ki is not 0
			if( pid_arm.Ki != 0 )
			{
				// If we are inside controlable window then integrate the error
				if( abs(pid_arm.pidError) < pid_arm.PID_INTEGRAL_LIMIT ){
					pid_arm.pidIntegral = pid_arm.pidIntegral + pid_arm.pidError;
				}
				else{
					pid_arm.pidIntegral = 0;
				}
			}
			else{
				pid_arm.pidIntegral = 0;
			}

			if (pid_arm.pidError == 0){
				pid_arm.pidIntegral = 0;
			}

			// calculate the derivative
			pid_arm.pidDerivative = pid_arm.pidError - pid_arm.pidLastError;
			pid_arm.pidLastError  = pid_arm.pidError;



			// calculate drive
			pid_arm.pidDrive = pid_arm.pidOffset+(pid_arm.Kp * pid_arm.pidError) + (pid_arm.Ki * pid_arm.pidIntegral) + (pid_arm.Kd * pid_arm.pidDerivative);

			// limit drive
			if( pid_arm.pidDrive > pid_arm.PID_DRIVE_MAX ){
				pid_arm.pidDrive = pid_arm.PID_DRIVE_MAX;}
			if( pid_arm.pidDrive < pid_arm.PID_DRIVE_MIN ){
				pid_arm.pidDrive = pid_arm.PID_DRIVE_MIN;}

			// send to motor
			pid_method_switch(pid_arm.pid_method,pid_arm.pidDrive);
		}

		}
		else if(arm_stat==4){
			writeDebugStreamLine("armstat4");

		}
		else{
			Arm(arm_driver_control);
		}





wait1Msec( 25 );
	}
}
