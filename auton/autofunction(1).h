void loadstack(int height1, int height2){
fbarflagraw=1;
if((height1<1900)){
wait10Msec(7);
}
else{
	wait10Msec(15);
}
	PIDArmTarget(1600);
	INtake();

	while(SensorValue[ArmPot]>1700){
		wait1Msec(1);
		}
clearTimer(T4)
		while((SensorValue[RollerButton]==0)&&(time10[T4] < 45)){
		wait1Msec(1);
		}
		wait1Msec(5);
	PIDArmTarget(height1);
	while(SensorValue[Armpot]<(height1-120)){
		wait1Msec(1);
	}
	fbarflagraw=0;
	while(SensorValue[FbarPot]<1520){
		wait1Msec(1);
		}

		PIDArmTarget(1200);
		wait10Msec(10);
		outtake();
		wait10Msec(5);
		PIDArmTarget(height2);

	wait10Msec(12);

	}
