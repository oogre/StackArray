
// include stack library header.
#include <StackArray.h>

// declare a string message.
const String msg = "Happy Hacking!";

// create a stack of characters.
StackArray <char> stack;

// startup point entry (runs once).
void
setup () {
  // start serial communication.
  Serial.begin (9600);

delay(2000);

  // set the printer of the stack.
  stack.setPrinter (Serial);

  // print the message before reversing.
  Serial.println ("Normal String: " + msg);

  // store all the message's characters to the stack.
  for (int i = 0; i < msg.length (); i++)
    stack.unshift(msg.charAt (i));

  // print the message after reversing.
  Serial.print ("Reversed String: ");

  // pop all the message's characters from the stack.
  while (!stack.isEmpty ())
    Serial.print( stack.pop() );

  // print end of line character.
  Serial.println ();
}

void loop(){

}
