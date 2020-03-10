#include "MQTTInterface.h"

#include "../GSM/gsm.h"
#include "../Systick/systick.h"



char TimerIsExpired(Timer* timer) {
	long left = timer->end_time - mqttTick;
	return (left < 0);
}


void TimerCountdownMS(Timer* timer, unsigned int timeout) {
	timer->end_time = mqttTick + timeout;
}


void TimerCountdown(Timer* timer, unsigned int timeout) {
	timer->end_time = mqttTick + (timeout * 1000);
}


int TimerLeftMS(Timer* timer) {
	long left = timer->end_time - mqttTick;
	return (left < 0) ? 0 : left;
}


void TimerInit(Timer* timer) {
	timer->end_time = 0;
}


void NewNetwork(Network* n) {
	n->my_socket = 0;
	n->mqttread = sim800_read;
	n->mqttwrite = sim800_write;
	n->disconnect = sim800_disconnect;
}


int sim800_write(Network* n, unsigned char* buffer, int len, int timeout_ms)
{
	/*
	int length;
	char dat[32];
	if(n->my_socket){

		length = snprintf((char *)dat,sizeof(dat),"AT+CIPSEND=%u",len);
		if(send_gsm_cmd(dat,length, ">", 300)) {
		 		debug_out("Sending data initiated \r\n");

		 		gprs_uart2_send((uint8_t *)buffer,len);
		 		if(get_gsm_ATcmd_reply("SEND", timeout_ms)){
		 			debug_out("Data sent \r\n");
		 			return 1;
		 		}
		 		else {
		 			debug_out("Error sending data \r\n");

		 		}

		 	}

	}
	*/
	return 0;
}



