typedef struct{
	float  Kp;
	float  Ki;
	float  Kd;
	bool pid_running;
	int  pid_target;
	int  pid_method;
	int  pid_sensor;
	int  pidSensorCurrentValue;
	int  pidError;
	int  pidLastError;
	int  pidIntegral;
	int  pidDerivative;
	int  pidDrive;
	int  pidOffset;
	int PID_DRIVE_MAX;
	int PID_DRIVE_MIN;
	int PID_INTEGRAL_LIMIT;
} pid_constants;

pid_constants pid_arm;
pid_constants pid_left_drive;
pid_constants pid_right_drive;
pid_constants pid_MOGO;

void pid_method_switch(int method, int power){

	switch(method){
	case 1:
		LeftDriveL1(power);
		break;

	case 2:
		RightDriveL1(power);
		break;

	case 3:
		useMogo(power);
		break;
	case 4:
		LeftDrive(power);
		RightDrive(-power);
		break;
	case 5:
		LeftDrive(-power);
		RightDrive(power);
		break;

	case 6:
		Arm(power);
		break;

	case 7:


  motorReq[DriveL1] = power;
	motorReq[DriveL2] = power;
	motorReq[DriveR1] = power;
	motorReq[DriveR2] = power;

	break;

	case 8:
	motorReq[DriveL1] = -power;
	motorReq[DriveL2] = -power;
	motorReq[DriveR1] = -power;
	motorReq[DriveR2] = -power;
		break;


	default:
		writeDebugStream("pid_method_switch ERROR");
	}

}
int get_pid_sensor(int sensor){

	switch(sensor){
	case 1:
		return(SensorValue[QuadLeft]);
		break;

	case 2:
		return(SensorValue[QuadRight]);
		break;

	case 3:
		return(SensorValue[MOGOPOT]);
		break;

	case 4:
		return(fGyroAngle);
		break;

	case 5:
		return(SensorValue[ArmPOT]);
		break;



	default:
		return(0);
		writeDebugStream("get_pid_sensor ERROR");
	}
}

#include "pid_arm.h"
#include "pid_roller.h"
#include "pid_fbar.h"
#include "pid_mogo.h"
#include "pid_drive.h"






#include "pid_control.h"
