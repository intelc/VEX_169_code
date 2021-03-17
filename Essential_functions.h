
#include "Linear_Drive.h"

int mogo_flag;

void UseMogo(int power){
	motor[Mogo] = power;

}

void Arm(int power){
	motor[ArmL] = power;
	motor[ArmR] = power;
	motor[ArmT] = power;
}

void SetFbar(int power){
	motor[Fbar]=power;

}

void useroller(int power){
	motor[roller] = power;
}

//////
