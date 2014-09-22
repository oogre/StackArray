<h1>StackArray Library For Arduino</h1>

  Author: Efstathios Chatzikyriakidis
  Contact: contact@efxa.org
  Library was updated for Arduino 1.0

<h2>Current Version</H2>
1.0 2014-09-22 - Vincent Evrard - added unshift(): add item to the array. (javascript like)
<h2>History</h2>
1.0 2010-09-25 - Efstathios Chatzikyriakidis - added resize(): for growing, shrinking the array size.
1.0 2010-09-25 - Efstathios Chatzikyriakidis - added resize(): for growing, shrinking the array size.
1.0 2010-09-23 - Efstathios Chatzikyriakidis - added exit(), blink(): error reporting and handling methods.
1.0 2010-09-20 - Alexander Brevig - added setPrinter(): indirectly reference a Serial object.
1.0 2010-09-15 - Efstathios Chatzikyriakidis - initial release of the library.
<h2>Description</h2>
StackArray is a library implementing a generic, dynamic stack (array version) for the Arduino.

It is created to help adding LIFO (Last In - First Out) Abstract Data Structure to a program for any use.

StackArray library is part of the "Data Structures & Algorithms" libraries.

<h2>Installation</h2>
Download here: <a href="https://github.com/oogre/StackArray/archive/master.zip">StackArray.zip</a>

Put the "StackArray" directory in "libraries" directory.

In the Arduino IDE, create a new sketch and select from the menubar "Sketch->Import Library->StackArray".

Once the library is imported, an "#include <StackArray.h>" line will appear at the top of your Sketch.

<h2>Creation</h2>
Replace "T" with the data type you want to use.

StackArray <T> stack;

Create instance (object) of a StackArray class.

<h2>Methods</h2>
Replace "T" with the data type you want to use.

<h3>void unshift (const T item)</h3>

Add an item with data type "T" to the top of stack.

<h3>void push (const T item)</h3>

Add an item with data type "T" to the bottom of stack.

<h3>T pop ()</h3>

Remove and return an item with data type "T" from the bottom stack.

<h3>T peek ()</h3>

Get an item with data type "T" from the stack.

<h3>bool isEmpty ()</h3>

Check if the stack is empty.

<h3>bool isFull ()</h3>

Check if the stack is full.

<h3>int count ()</h3>

Get the number of items in the stack.

<h3>void setPrinter (Print & printer)</h3>

Sets the printer of the stack.

<h2>Examples</h2>
<h4>Reverse a string by using a generic, dynamic stack data structure.</h4>

```C++
/*
 *  Reverse a string by using a generic, dynamic stack data structure.
 *
 *  Copyright (C) 2010  Efstathios Chatzikyriakidis (contact@efxa.org)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// include stack library header.
#include <StackArray.h>

// declare a string message.
const String msg = "Happy Hacking!";

// create a stack of characters.
StackArray <char> stack;

// startup point entry (runs once).
void setup () {
  // start serial communication.
  Serial.begin (9600);

  // set the printer of the stack.
  stack.setPrinter (Serial);

  // print the message before reversing.
  Serial.println ("Normal String: " + msg);

  // push all the message's characters to the stack.
  for (int i = 0; i < msg.length (); i++)
    stack.push (msg.charAt (i));

  // print the message after reversing.
  Serial.print ("Reversed String: ");

  // pop all the message's characters from the stack.
  while (!stack.isEmpty ())
    Serial.print (stack.pop ());

  // print end of line character.
  Serial.println ();
}

// loop the main sketch.
void loop () {
  // nothing here.
}
```



<h4>Swapping numbers by using a generic, dynamic stack data structure.</h4>

```C++
/*
 *  Swapping numbers by using a generic, dynamic stack data structure.
 *
 *  Copyright (C) 2010  Efstathios Chatzikyriakidis (contact@efxa.org)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// include stack library header.
#include <StackArray.h>

// declare two numbers.
double a = 1.1;
double b = 2.2;

// create a stack of numbers.
StackArray <double> stack;

// startup point entry (runs once).
void
setup () {
  // start serial communication.
  Serial.begin (9600);

  // set the printer of the stack.
  stack.setPrinter (Serial);
}

// loop the main sketch.
void loop () {
  // print the values of the numbers.
  Serial.print ("a: "); Serial.println (a);
  Serial.print ("b: "); Serial.println (b);

  // push the numbers to the stack.
  stack.push (a);
  stack.push (b);

  // pop the numbers from the stack.
  a = stack.pop ();
  b = stack.pop ();

  // delay 1 second.
  delay (1000);
}
```


<h4>Store a string by using a generic, dynamic stack data structure.</h4>

```C++
/*
 *  Store a string by using a generic, dynamic stack data structure.
 *
 *  Copyright (C) 2014  Vincent Evrard (vincent@ogre.be)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// include stack library header.
#include <StackArray.h>

// declare a string message.
const String msg = "Happy Hacking!";

// create a stack of characters.
StackArray <char> stack;

// startup point entry (runs once).
void setup () {
  // start serial communication.
  Serial.begin (9600);

  delay(2000);

  // set the printer of the stack.
  stack.setPrinter (Serial);

  // print the message before reversing.
  Serial.println ("Normal String: " + msg);

  // push all the message's characters to the stack.
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
  // nothing here.
}
```






<h2>FAQ</h2>
How do I use multiple stacks?
StackArray is a class. Therefore to use multiple stacks, you must create an instance for each of them.