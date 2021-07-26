#include <vector>
#include <Arduino.h>
#include "Demo.h"

void Demo::run(){
  delay(750);
  sc.criu("...STARTING TEST...", 2);
  delay(250);
  sc.criu("LET'S GO!", 3, RIGHT);
  delay(1000);
  sc.clear();
  sc.ctr(151, 20);
  sc.left("left align", true);
  delay(500);
  sc.right("right align", true);
  delay(500);
  sc.center("=[ centered ]=", true);
  delay(500);
  sc.center("=[ inverted ]=", true);
  sc.invert();
  delay(300);
  sc.clwipe(5);
  delay(300);
  sc.left("ABCDEFGHIJKLMNOPQRSTUVWX");
  sc.crwipe(5);
  delay(300);
  sc.left("LINES CAN JUST FALL DOWN");
  delay(300);
  sc.rod(100);
  delay(500);
  sc.left("LINES CAN ALSO FLOAT UP!");
  delay(300);
  sc.rou(100);
  delay(500);

  sc.left("ABCDEFGHIJKLMNOPQRSTUVWX");
  delay(500);
  sc.rid("Attack from above!", 150);
  delay(500);
  sc.riu("ROLLIN' ON UP FROM BELOW", 50);
  delay(500);
  sc.riu("//////\\\\\\\\\\\\", 100);
  sc.riu("\\/////\\\\\\\\\\\\", 75);
  sc.riu("\\\\////\\\\\\\\\\\\", 50);
  sc.riu("\\\\\\///\\\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\//\\\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\/\\\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\\\\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\/\\\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\//\\\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\////\\\\\\", 25);
  sc.riu("\\\\\\\\\\\\/////\\\\", 50);
  sc.riu("\\\\\\\\\\\\//////\\", 75);
  sc.riu("\\\\\\\\\\\\///////", 100);
  delay(500);
  sc.mwc("a bundle of peeled eggs in burlap weighs twice as much as molten metals or 3 times as much as anxiety", 175);
  delay(250);
  sc.center("[ WIPE IN FROM OUT ]");
  delay(250);
  sc.mwoi(25);
  sc.center("-==[WHEELBARROW ANGST]==-");
  delay(150);
  sc.mwoo(10);
  sc.left("ABCDEFGHIJKLMNOPQRSTUVWX");
  delay(500);
  sc.lwipe("abcdefghijklmnopqrstuvwx", 10);
  delay(250);
  sc.left("-------------------------");
  delay(150);
  sc.lwipe("|__dunwich__|", 10);
  delay(250);
  sc.rwipe("XWVUTSRQPONMLKJIHGFEDCBA", 10);
  delay(250);
  sc.left("XWVUTSRQPONMLKJIHGFEDCBA");
  sc.rwipe("/solidify\\", 10);
  delay(250);
  sc.strobe(75, 20);
  sc.strobe(20, 50);
  sc.strobe(150, 8);
  sc.clear();
  printer.print("ANTHRO", 109, false);
  printer.print("ANTHRO", 3, false);
  sc.invert();
  printer.center("  ANTHRO  ");
  for(uint8_t i = 0 ; i < 25; i++){
    sc.invert();
    delay(150);
  }
  sc.clear();
  sc.left("shift in left");
  std::vector<uint8_t> nums = {0,0,1,3,7,15,31,63,127};
  for(const uint8_t &i : nums){
    sc.sil(i);
    delay(200);
  }
  delay(250);
  sc.clear();
  sc.right("shift in right");
  for(const uint8_t &i : nums){
    sc.sir(i);
    delay(200);
  }

  sc.clear();
  printer.center("** RANDOM DISSOLVE **");
  delay(400);
  sc.rando(5);
  delay(333);

  sc.center("ANYTHING BASICALLY");
  sc.randi("** RANDOM APPEAR **");  //clears sign internally
  delay(250);
  sc.randt("! A MOTH IS BORN ANEW !");
  delay(1000);

  sc.lazr("IT'S A LAZER BEAM BOZO");
  delay(500);
  sc.clear();
  sc.kriu("* CHARS RISE ON UP *");
	delay(333);
  sc.krid("* CHARS FALL FROM SKY *");
	delay(333);
  sc.center("* CHARS FLOAT AWAY *");
	delay(500);
  sc.krou("* CHARS FLOAT AWAY *");
	delay(333);
  sc.krod("* CHARS MELT INTO MUD *");
	delay(333);
	sc.msl("WE CAN SCROLL A MESSAGE THAT IS MUCH MUCH WIDER THAN THE SIGN ITSELF", 15);
	delay(333);
	sc.msr("AND WE CAN DO IT IN THE OTHER DIRECTION EVEVEN THO ITS HARD TO READ", 8);
	delay(333);
  sc.time(10);
	delay(250);
	sc.clear();
	sc.center("_._.all done._._");

}
