
#include "gsm.h"
#if (_GSM_CALL == 1 || _GSM_MSG == 1 || _GSM_GPRS == 1)
//###############################################################################################################
void gsm_callback_simcardReady(void)
{
  gsm_printf("CALLBACK SIMCARD READY\r\n");
}
//###############################################################################################################
void gsm_callback_simcardPinRequest(void)
{
  gsm_printf("CALLBACK SIMCARD PIN\r\n");
}
//###############################################################################################################
void gsm_callback_simcardPukRequest(void)
{
  gsm_printf("CALLBACK SIMCARD PUK\r\n");
}
//###############################################################################################################
void gsm_callback_simcardNotInserted(void)
{
  gsm_printf("CALLBACK SIMCARD NOT DETECT\r\n");
}
//###############################################################################################################
void gsm_callback_networkRegister(void)
{
  gsm_printf("CALLBACK NETWORK REGISTER\r\n");
}
//###############################################################################################################
void gsm_callback_networkUnregister(void)
{
  gsm_printf("CALLBACK NETWORK UNREGISTER\r\n");
}
//###############################################################################################################
#if (_GSM_CALL == 1)
void gsm_callback_newCall(const char *number)
{
  
  if (strstr((char*) number, "+79657775424")!=NULL) 
    {
      gsm_call_answer();
      gsm_call_end();
      gsm_msg_send("+79657775424","Call OK");  
    }
}
//###############################################################################################################
void gsm_callback_endCall(void)
{
  gsm_printf("CALLBACK END CALL\r\n");
}
//###############################################################################################################
void gsm_callback_dtmf(char *string, uint8_t len)
{
  gsm_printf("CALLBACK DTMF %s, LEN:%d\r\n", string, len);
}
#endif
//###############################################################################################################
#if (_GSM_MSG == 1)
void gsm_callback_newMsg(char *number, gsm_time_t time, char *msg)
{
  gsm_printf("CALLBACK NEW MESSAGE FROM %s, LEN:%d\r\n", number, strlen(msg));
  gsm_printf("%s\r\n", msg);
  if (strstr((char*) number, "+79657775424")!=NULL)
    {
      gsm_msg_send(number,"Test OK");
    }  
  gsm_msg_deleteAll();
}
#endif
//###############################################################################################################
#if (_GSM_GPRS == 1)
void gsm_callback_gprsConnected(void)
{
  gsm_printf("CALLBACK GPRS CONNECTED, IP: %s\r\n", gsm.gprs.ip);
}
//###############################################################################################################
void gsm_callback_gprsDisconnected(void)
{
  gsm_printf("CALLBACK GPRS DISCONNECTED\r\n");
}
//###############################################################################################################
void gsm_callback_mqttMessage(char *topic, char *message)
{
  gsm_printf("CALLBACK GPRS MQTT TOPIC: %s   ----   MESSAGE: %s\r\n", topic, message);
}
//###############################################################################################################
void gsm_callback_mqttDisconnect(void)
{
  gsm_printf("CALLBACK GPRS MQTT DISCONNECT\r\n");
}
//###############################################################################################################
#endif
#endif
