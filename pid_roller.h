
bool outtaking = false;
int roller_stat;
int roller_driver_control;
int roller_reversed;
int rollerflagraw;

void Setuseroller(int power){
	roller_driver_control = power;
}

void ReverseRoller(){
	clearTimer(T1);
	roller_reversed = 1;
	rollerflag=0;
}
void intake(){
	rollerflagraw=1;
}
void outtake(){
	rollerflagraw=0;
	ReverseRoller();
}

bool conepastsecond(){

	if(time1[T2] < 500){
		return true;
	}
	else{
		return false;
	}

}
task rollerOut(){
		setuseroller(-127);
		sleep(500);
		outtaking = false;
}
void buttonRoller(){
	if(vexRT[Btn6DXmtr2] == 0 && SensorValue[RollerButton] == 1 && outtaking == false && vexRT[Btn5UXmtr2] == 0){
		setuseroller(15);
		indicateCone(0);
		if(flashing == true){
			stopTask(flashConeIndicator);
			flashing = false;

		}

	}

	else if(vexRT[Btn6DXmtr2] == 1 && SensorValue[RollerButton] == 1 && outtaking == false && vexRT[Btn5UXmtr2] == 0){
	
		outtaking = true;
		startTask(rollerOut);
		if(flashing == true){
			stopTask(flashConeIndicator);
			flashing = false;
		}
	}

	else if(outtaking == false && vexRT[Btn5UXmtr2] == 0){
		setuseroller(127);
		indicateCone(1);
		if(flashing == true){
			stopTask(flashConeIndicator);
			flashing = false;
		}
	}

	else if(vexRT[Btn5UXmtr2] == 1){
		setuseroller(0);
		if(flashing != true){
			startTask(flashConeIndicator);
		}
	}
}
task roller_control(){



	while(true){

		if(SensorValue[ROLLERBUTTON]==1){
			clearTimer(T2);
		}

		if (roller_stat==1){

			useroller(roller_driver_control);
		}

		else if(roller_stat==2){

			if(time1[T1] < 1000){
				roller_reversed = 1;
			}
			else{
				roller_reversed = 0;
			}

			if(rollerflagraw==1){
				if((SensorValue[ROLLERBUTTON]!=1)){
					if ((SensorValue[ROLLERBUTTON]!=1)&&(conepastsecond())){
					useRoller(30);
				}
				else{
					useRoller(90);
				}
				}
				else if(SensorValue[ROLLERBUTTON]==1){
					useRoller(15);
				}
			}
			else if(rollerflagraw==0){
				if(roller_reversed == 1){
				useRoller(-90);
				}
				else{
				rollerflag=1;
				}
			}
		}

		else{
			useroller(roller_driver_control);
		}





		wait1Msec( 25 );
	}
}
