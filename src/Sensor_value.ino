const int min_soil_res_wet=100;
const int max_soil_res_wet=380;
const int soil_res_dry=380;
int pump_status=0;
int soil_res = 0;
int write_output=0;
const int SensorPin = A0; //soil moisture sensor input pin
const int relayPin = 8; //To RelayPin from arduino
char sensor_out[9];

void setup()
{
  Serial.begin(9600); //to setup baud rate for communication
  pinMode(SensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop()
{
   soil_res = analogRead(SensorPin); //to measure soil resistance
   /*Serial.println(soil_res);*/
  
  if ((soil_res >= min_soil_res_wet) && (soil_res<=max_soil_res_wet)) 
  {
    if(pump_status == 1) 
    {    
      /*write_output = 1;*/
      digitalWrite(relayPin, HIGH);// to turn off
      pump_status=0;
      sprintf(sensor_out,"%d,%d",soil_res,pump_status);  
      Serial.println(sensor_out);
   
    }
   else
    {
      write_output = 0;
      pump_status = 0;
    }
  }
 else 
  {
     if(pump_status == 0) 
      {
        /*write_output = 1;*/
        digitalWrite(relayPin , LOW);// to turn on
        pump_status=1;
        sprintf(sensor_out,"%d,%d",soil_res,pump_status);  
        Serial.println(sensor_out);
      }
     else
        write_output = 0;
  }
     
  delay(1000); 
 }
 
