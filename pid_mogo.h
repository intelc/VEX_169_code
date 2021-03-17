

int mogo_stat;
int mogo_driver_control;
int mogoflag;

void Setmogo(int power){
	mogo_driver_control = power;
}
void mogoout(){
	mogoflag=1;
}
void mogoin(){
	mogoflag=0;
}


task mogo_control(){

pid_mogo.PID_DRIVE_MAX = 127;
pid_mogo.PID_DRIVE_MIN = -127;
pid_mogo.PID_INTEGRAL_LIMIT = 100;
pid_mogo.pid_sensor=3;
pid_mogo.pid_method=3;

	while(true){



		if (mogo_stat==1){

			if((SensorValue[MOGOPOT] <2800)&&(mogo_driver_control<0)){

				UseMogo(mogo_driver_control);
			}
			else if ((SensorValue[MOGOPOT]  >815)&&(mogo_driver_control>0)){

				UseMogo(mogo_driver_control);
			}
			else{

				UseMogo(0); //set mogo pid to down
			}

///////////////////////////
		if(mogoflag==0){
		if(SensorValue[MOGOPOT]  >815){
				Setmogo(127);
		}
		else{
			Setmogo(10);

		}
	}
		else if(mogoflag==1){
if(SensorValue[MOGOPOT] <2800){
				Setmogo(-127);
		}
		else{
			Setmogo(0);
		}
}
		}
		else if(mogo_stat==2){
			if( pid_mogo.pid_running )
		{
			// Read the sensor value and scale
			pid_mogo.pidSensorCurrentValue = get_pid_sensor(pid_mogo.pid_sensor) ;

			// calculate error
			pid_mogo.pidError = pid_mogo.pid_target - pid_mogo.pidSensorCurrentValue;

			// integral - if Ki is not 0
			if( pid_mogo.Ki != 0 )
			{
				// If we are inside controlable window then integrate the error
				if( abs(pid_mogo.pidError) < pid_mogo.PID_INTEGRAL_LIMIT ){
					pid_mogo.pidIntegral = pid_mogo.pidIntegral + pid_mogo.pidError;
				}
				else{
					pid_mogo.pidIntegral = 0;
				}
			}
			else{
				pid_mogo.pidIntegral = 0;
			}
			if (pid_mogo.pidError == 0){
				pid_mogo.pidIntegral = 0;
			}


			// calculate the derivative
			pid_mogo.pidDerivative = pid_mogo.pidError - pid_mogo.pidLastError;
			pid_mogo.pidLastError  = pid_mogo.pidError;

			// calculate drive
			pid_mogo.pidDrive = pid_mogo.pidOffset+(pid_mogo.Kp * pid_mogo.pidError) + (pid_mogo.Ki * pid_mogo.pidIntegral) + (pid_mogo.Kd * pid_mogo.pidDerivative);

			// limit drive
			if( pid_mogo.pidDrive > pid_mogo.PID_DRIVE_MAX ){
				pid_mogo.pidDrive = pid_mogo.PID_DRIVE_MAX;}
			if( pid_mogo.pidDrive < pid_mogo.PID_DRIVE_MIN ){
				pid_mogo.pidDrive = pid_mogo.PID_DRIVE_MIN;}

			// send to motor
			pid_method_switch(pid_mogo.pid_method,pid_mogo.pidDrive);
		}

		}
		else if(mogo_stat==3){
			if((SensorValue[MOGOPOT] <2800)&&(mogoflag==0)){

				UseMogo(-127);
			}
			else if ((SensorValue[MOGOPOT] >750)&&(mogoflag==1)){

				UseMogo(127);
			}
			else{

				UseMogo(0); //set mogo pid to down

			}

		}

		else{
			Usemogo(mogo_driver_control);
		}





		wait1Msec( 25 );
	}
}
