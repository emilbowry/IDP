#ifndef Wifi_h
#define Wifi_h
char ssid[] = "teamfour";
char pass[] = "teamfour";
int keyIndex = 0;
WiFiServer server(80);
WiFiClient client = server.available();
int status = WL_IDLE_STATUS;
#endif