const float BarA = 20;
const float BarB = 28;
const float BarC = 20;
const float BarD = 28;

float artPot2Degree(int SensorInput){

	float temp_output;
	float single_degree = 4095/265;
	temp_output = (float)(SensorInput/single_degree)-33.5;
	return(temp_output);
}

float Theta2Height(){

	float temp_output;
	float angle;
	angle = artPot2Degree(SensorValue[ArmPot]);
	temp_output =  BarA+BarC-(cosDegrees(angle)*BarB + cosDegrees(angle)*BarD) ;
	return(temp_output) ;
}

int autostack_stat;

void ArmEndCondition(int side, int number){
	if (side == 0){
		while(SensorValue[ArmPot]> number){
			wait1Msec(1);
		}
	}
	else if  (side == 1){
		while(SensorValue[ArmPot]< number){
			wait1Msec(1);
		}

	}
}
void ArmEndConditionh(int side, int number){
	if (side == 0){
		while(Theta2Height()> number){
			wait1Msec(1);
		}
	}
	else if  (side == 1){
		while(Theta2Height()< number){
			wait1Msec(1);
		}

	}
}
void suckgood(){

		while(vexRT[Btn8D]== 0){
			wait1Msec(1);
		}

}

void autostackup(){
int autostack_holder1;
fbarflagraw=1;
rollerflagraw=1;
arm_stat=4;
while(SensorValue[FbarPot]>1100){
	wait1Msec(1);
}
Arm(-90);

ArmEndCondition(0,1500);

Arm(-50);

ArmEndCondition(0,1440);

Arm(20);

ArmEndCondition(0,1350);
Arm(-10);

suckgood();

Arm(90);

while((ready2stack()==false)){
	wait1Msec(1);
}

	wait1Msec(8);

while((ready2stack()==false)){
	wait1Msec(1);
}

autostack_holder1=Theta2Height();

if(SensorValue[ArmPot]< 1600){
Arm(30);
fbarflagraw=0;
ArmEndConditionh(1,autostack_holder1+4);
Arm(-10);
}
else if(SensorValue[ArmPot]> 2300){
	Arm(40);
	fbarflagraw=0;
ArmEndConditionh(1,autostack_holder1);
Arm(15);
}

else if(SensorValue[ArmPot]> 1600){
	Arm(-20);
	fbarflagraw=0;
ArmEndConditionh(1,autostack_holder1);
Arm(-10);
}


//wait10Msec(15);
//Arm(15);
while(SensorValue[FbarPot]<2100){
	wait1Msec(1);
}
Arm(-50);
wait10Msec(10);

Outtake();
Arm(30);
wait10Msec(15);
Arm(50);

ArmEndConditionh(1,autostack_holder1+12);
Arm(20);

//fbarflagraw=1;
autostack_stat=0;


}

void autostackdown(){
fbarflagraw=1;
rollerflagraw=1;
arm_stat=4;
writeDebugStreamLine("I am here place 6")
Arm(-90);
writeDebugStreamLine("I am here place 7")
ArmEndCondition(0,1650);
writeDebugStreamLine("I am here place 8")
Arm(20);
wait10Msec(5);
Arm(10);

}



task autostack(){
	//autostack_stat=0;



	while(true){

		if(autostack_stat==1){


			writeDebugStreamLine("I am here place 2")
			autostackup();
			autostack_stat=0;

		}
		else if(autostack_stat==2){
			autostackdown();
			autostack_stat=0;
		}
		else{
		writeDebugStreamLine("else")
			Arm(15);
			fbarflagraw=0;

		}

	}


}
