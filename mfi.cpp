

#include <ArduinoHttpClient.h>
#include <WiFiNINA.h>

char serverAddress[] = "10.42.42.12";  // server address
int port = 80;

WiFiClient wifiClient;
HttpClient httpClient = HttpClient(wifiClient, serverAddress, port);


void turnOff() {
  httpClient.beginRequest();
  String postData = "username=ubnt&password=ubnt";
  String contentType = "application/x-www-form-urlencoded";

  httpClient.post("/login.cgi");
  httpClient.sendHeader("Content-Type", "application/x-www-form-urlencoded");
  httpClient.sendHeader("Content-Length", postData.length());
  httpClient.sendHeader("Cookie", "AIROS_SESSIONID=01234567890123456789012345678901");
  httpClient.sendHeader("Accept", "*/*");
  httpClient.beginBody();
  httpClient.print(postData);
  httpClient.endRequest();

  // read the status code and body of the response
  int statusCode = httpClient.responseStatusCode();
  String response = httpClient.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  postData = "output=0";

httpClient.beginRequest();
  httpClient.post("/sensors/1");
  httpClient.sendHeader("Content-Type", "application/x-www-form-urlencoded");
  httpClient.sendHeader("Content-Length", postData.length());
  httpClient.sendHeader("Cookie", "AIROS_SESSIONID=01234567890123456789012345678901");
  httpClient.sendHeader("Accept", "*/*");
  httpClient.beginBody();
  httpClient.print(postData);
  httpClient.endRequest();

  // read the status code and body of the response
  statusCode = httpClient.responseStatusCode();
  response = httpClient.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
}
