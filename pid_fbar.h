

int chain_stat;
int chain_driver_control;
int fbarflagraw;

void Setusechain(int power){
	chain_driver_control = power;
}


task fbar_control(){



	while(true){




		if (chain_stat==1){

			if(fbarflag==0){
				if(SensorValue[FBARPOT]<2300){
				Setusechain(90);
		}
		else{
			Setusechain(10);
		}
		}
		else if(fbarflag==1){
			if(SensorValue[FBARPOT]>1000){
				Setusechain(-90);
		}
		else{
			Setusechain(-10);
		}

		}

			if((SensorValue[FBARPOT]<2500)&&(chain_driver_control>0)){
				SetFbar(chain_driver_control);
			}
			else if((SensorValue[FBARPOT]>900)&&(chain_driver_control<0)){
				SetFbar(chain_driver_control);
				//writeDebugStreamLine("set 127");
			}
			else{
				SetFbar(0);
				//writeDebugStreamLine("set 0");
			}

		}
		else if(chain_stat==2){
			if(fbarflagraw==0){
				if(SensorValue[FBARPOT]<2300){
				Setusechain(90);
		}
		else{
			Setusechain(10);
		}
		}
		else if(fbarflagraw==1){
			if(SensorValue[FBARPOT]>1000){
				Setusechain(-90);
		}
		else{
			Setusechain(-10);
		}

		}
		if((SensorValue[FBARPOT]<2500)&&(chain_driver_control>0)){
				SetFbar(chain_driver_control);
			}
			else if((SensorValue[FBARPOT]>900)&&(chain_driver_control<0)){
				SetFbar(chain_driver_control);
				//writeDebugStreamLine("set 127");
			}
			else{
				SetFbar(0);
				//writeDebugStreamLine("set 0");
			}

		}

		else{
			SetFbar(chain_driver_control);
		}





	wait1Msec( 25 );
	}
}
