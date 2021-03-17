
int is_prog_running = 0;
int is_place_running = 0;
int is_load_running = 0;


task runauto(){
	autonomousbody();
	writeDebugStreamLine("Autonomous task");
	is_auto_running = 2;
}

task runprog(){
	progskillsbody();
	is_prog_running = 2;
}

task runautoplace(){
	autoplacebody();
	is_place_running = 2;
}

task runautoload(){
	autoloadbody();
	is_load_running = 2;
}
