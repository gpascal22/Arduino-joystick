//Program by PI AND CHIPS BLOG: piandchipsblog.wordpress.com
//Do whatever you want with it, I don't care
int wait = 0; //variable to count the number of random buttons pressed

//variables for the different buttons on the shield
int up_button = 4; 
int down_button = 5;
int right_button = 3;
int select_button = 2;
int x_axis = A0;
int y_axis = A1;

//an array for setting them as inputs easier
int buttons[] = {up_button, down_button, right_button, select_button};
int randomNumber = 2;//code to generate a random number will come later, but for now set it to one
float total_time = 0; //variable to store the total time taken
float avg_time = 0; //variable to store the average time taken
void setup() {
 for (int i; i < 7; i++) //iterates through the buttons in the button array and sets them as inputs, and sets them as high
 {
 pinMode(buttons[i], INPUT);
 digitalWrite(buttons[i], HIGH);
 }
 Serial.begin(9600);//initialize the serial monitor
 Serial.println("Welcome to the Arduino Reaction Game!");
 delay(100);
}

void loop() {
 
 while(wait <= 20){ //while the number of buttons pressed is less than or equal to 20

 switch (randomNumber) {//switch statement means something different will happen depending on the random number chosen
 
//ALL THE OTHER CASE STATEMENTS ARE THE SAME AS ABOVE BUT WITH DIFFERENT BUTTONS
 case 2:
 Serial.println("SELECT BUTTON");
 while(digitalRead(select_button) == 1){
 delay(1);
 total_time++;
 }
 wait++;
 randomNumber = random(2, 5);
 break;
 
 case 3:
 Serial.println("RIGHT BUTTON");
 while(digitalRead(right_button) == 1){
 delay(1);
 total_time++;
 }
 wait++;
 randomNumber = random(2, 5);
 break;
 
 case 4:
 Serial.println("UP BUTTON");
 while(digitalRead(up_button) == 1){
 delay(1);
 total_time++;
 }
 wait++;
 randomNumber = random(2, 5);
 break;

case 5:
 Serial.println("DOWN BUTTON");
 while(digitalRead(down_button) == 1){
 delay(1);
 total_time++;
 }
 wait++;
 randomNumber = random(2, 5);
 break;
}
 }
//when the user has had 20 button presses
avg_time = total_time / 20 /100 ;//work out averag time.
 Serial.println("Your average response time was ");
 Serial.println(avg_time);
 Serial.println("Seconds");
 Serial.print("THANKS FOR PLAYING");
 delay(10000);
}
