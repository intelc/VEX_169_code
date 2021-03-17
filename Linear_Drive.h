const unsigned int TrueSpeed[128] =
{
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0, 21, 21, 21, 22, 22, 22, 23, 24, 24,
 25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
 28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
 33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
 37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
 41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
 46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
 52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
 61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
 71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
 80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
 88, 89, 89, 90, 90,127,127,127
};


int linearflag=0;

void LeftRaw(int power){

	motor[DriveL1] = power;
	motor[DriveL2] = power;

}

void RightRaw(int power){

	motor[DriveR1] = power;
	motor[DriveR2] = power;

}


void LeftDriveL1(int power){
		if(power>0){
			LeftRaw(TrueSpeed[power]);
		}
		else if (power<0){
			LeftRaw(-(TrueSpeed[-power]));

		}
		else{
			LeftRaw(0);
		}
	}

void RightDriveL1(int power){
		if(power>0){
			RightRaw(TrueSpeed[power]);
		}
		else if (power<0){
			RightRaw(-(TrueSpeed[-power]));

		}
		else{
			RightRaw(0);
		}
	}

void LeftDrive(int power){
	if(linearflag==0){
		LeftRaw(power);
	}
	else if (linearflag==1){
		LeftDriveL1(power);
	}
}

void RightDrive(int power){
	if(linearflag==0){
		RightRaw(power);
	}
	else if (linearflag==1){
		RightDriveL1(power);
	}
}





void Drive(int Lpower, int Rpower){
		LeftDrive(Lpower);
		RightDrive(Rpower);
	}
