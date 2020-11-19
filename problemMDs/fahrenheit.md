Problem: Fahrenheit
===================

## tl;dr

Implement a program that converts degrees in Celsius to Fahrenheit, per the below.

```
$ ./fahrenheit
C: 0
F: 32.0
```

## Turning Up the Heat

In the past, if you wanted to know what the outdoor temperature was, you had to look around for one of these, which might have been mounted outside at your house.

![Thermometer](https://www.decorist.com/static/finds/product_images/full_size/85423-ivy-outdoor-thermometer.fbc5e565e03f7666fd61969983ed4e2f.png)

Prior to that, if you wanted to know what the temperature was outside, you just stood outside, but we digress. Nowadays, it's a fairly trivial exercise to pull open a weather app on your phone or visit a weather-reporting website to get the current temperature and the five-day forecast. No need to mess around with one of the above circular dials or its tube-of-mercury cousin[[1](https://docs.cs50.net/2019/ap/problems/fahrenheit/fahrenheit.html#_footnotedef_1 "View footnote.")].

Depending on where you live in the world, your country uses one of two major temperature scales. If you live in the United States (and don't spend most of your day working in a science lab), it's likely that you're familiar with the Fahrenheit scale, and so if you hear that it's 30° outside you're probably putting on a heavy coat and warm pants and bracing yourself for the possibility of snow, because that means it's quite cold, given that the freezing point of water is 32°. On the other hand, it's not until the temperature hits 212° that water boils.

In practically every other country of the world (or if you live in the United States and do in fact spend most of your day working in a science lab), you're probably most familiar with the Celsius or centigrade scale. In that case, if you hear that it's 30° outside you're probably going to rummage through your closet for a swimsuit and put on some sunblock, because it's a beautiful beach day. On the Celsius scale, 0° is the freezing point of water, and 100° is the boiling point.

We acknowledge that with most apps that tell you the weather, it's fairly simple to press that switch that switches the temperature display from Fahrenheit to Celsius (or vice versa), but before that process was automated for us, one either had to memorize some of the more common conversion points or had to use a mathematical formula to convert from one scale to another, which is important if you plan on traveling internationally.

For this problem, we're going to focus on converting in just one direction: from Celsius to Fahrenheit. As it happens, the formula for this conversion isn't terribly complex. (Phew!) One simply takes the current temperature in degrees Celsius (°C), multiplies it by 9, divides by 5, and then adds 32. The result is the equivalent temperature in degrees Fahrenheit (°F). Not bad, right? For the more visually inclined, this translates to this formula:

```
F = ((C * 9) / 5) + 32
```

Let's do a quick test to make sure things work as expected. Worldwide, the commonly accepted value for normal human body temperature is 37°C. If we plug "37" into that formula where °C goes and do the math (37 multiplied by 9 is 333, 333 divided by 5 is 66.6, 66.6 + 32 is 98.6) we get 98.6°F which is what folks in the United States know as normal human body temperature. So that checks out. Similarly if we plug in 0°C (the freezing point of water) into that formula does it convert to 32°F, and 100°C (the boiling point of water) is apparently equivalent to 212°F. Seems like things are going well.

## A Cool Look Back

Log into your [CS50 IDE account](https://ide.cs50.io) (remember how?) and, if you have it from Hello, take a look at your `hello.c` file, which should be in your `chapter1/hello/` directory. (If you don't have it, create it now.) The contents should look probably like this:

```
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

To make our program more adaptable, instead of having it always print the same simple message (`hello, world\n`) each time, we can modify this program to prompt a user to provide their name and then print out their name instead:

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Enter your name: ");
    printf("hello, %s\n", name);
}
```

Notice a couple of important differences in this program. It seems that we have decided to include another header file called `cs50.h`. In this file, which you can have a peek at [here](https://raw.githubusercontent.com/cs50/libcs50/develop/src/cs50.h) and which we'll also discuss in more detail later in the course (so don't be alarmed by some unfamiliar syntax), you'll see that that's where we've declared the data type of `string` and declared a function called `get_string`.

A `string` in computer science essentially refers to a collection of characters---​a word, a sentence, or a phrase. Because when we ask the user for their name it probably consists of more than a single letter, which would be just a character (`char`), we need to use `get_string`to collect their input and we need to store it in a variable whose data type is `string`; we've done this, the variable called `name` has the data type of `string`.

What else has changed, though? That last line of code looks a bit strange. There's a `%s` in there, and the variable `name` appears. What's going on?

Essentially, `%s` is what's known as a placeholder for a variable. At the time the program is compiled, we don't know exactly what will be printed out (unlike the original program which will always print out `hello, world\n`), but we do expect that the program will print `hello,` followed by whatever the user typed. `%s` is how we indicate to `printf` that a `string` will be printed there.

What `string` will we print? Well, that'd be `name`! After we specify what we want `printf` to print, leaving as many placeholders as necessary, we specify what variables those placeholders refer to in order from left to right, separated by commas. We only have one placeholder in our modified program, a single `%s`, and so the variable that we're telling `printf` to print in place of that `%s` is whatever the user typed at the prompt. For example:

```
~/chapter1/hello/ $ ./hello
Enter your name: Alice
Hello, Alice!
```

There's not just `get_string` in `cs50.h` though. There are functions to get user input of nearly all types: `get_int`, `get_float`, `get_double`, `get_long`, `get_char`.

## Getting Warmer

Now, create a file called `fahrenheit.c` (remember how?), ensuring that it is inside of a subdirectory called `fahrenheit` inside of your `chapter1` directory, and then double-click on that file in the file tree to the left. You should now have an open window in your text editor with the tab name `fahrenheit.c`, and you're ready to write your first utility program---​a program that can be used by others to do something meaningful for them. (Not to knock the value of saying `hello, world`... but we can do so much more!)

Write a program that converts a temperature in Celsius to Fahrenheit, as per the sample output below, wherein underlined text represents some user's input[[2](https://docs.cs50.net/2019/ap/problems/fahrenheit/fahrenheit.html#_footnotedef_2 "View footnote.")].

```
~/chapter1/fahrenheit/ $ ./fahrenheit
C: 100
F: 212.0
```

To solve this problem, you needn't do anything more complex than use your currently existing knowledge of C, and the information contained in this specification, including the temperature conversion formula. No matter how the user inputs the temperature in Celsius (that is, no matter to how many decimal places they choose), take care to display Fahrenheit to exactly one decimal place. No need to worry about floating-point imprecision or integer overflow, if you recall what those terms mean.[[3](https://docs.cs50.net/2019/ap/problems/fahrenheit/fahrenheit.html#_footnotedef_3 "View footnote.")]

Do recall that if you include `<cs50.h>` atop your `fahrenheit.c` file, you will have access to a function called `get_float`, which will allow the user to input a floating-point value (a number with a decimal point in it, also known as a real number).The parameters of the get functions will display a prompt for users. So if you had a line in a file called `name.c` that looked like this `get_string("name please:")`, it will display the following:

```
~/name/ $ ./name
name please:
```

Incidentally, know that `printf` can be used to specify how many places after the decimal point you wish to display to the user. For example, assuming you've written the following program in a file called `truncate.c`:

```
#include <stdio.h>

int main(void)
{
   float pi = 3.1415926535;
   printf("%.2f\n", pi);
}
```

When executed (by first compiling with `make truncate` and then executing with `./truncate`), this program will output the value of the variable `pi` to exactly 2 decimal places: `3.14`. Can you see why? Perhaps you can adapt that to display the converted temperature to just one decimal place?

## Testing

### Correctness

Before turning in your solution, be sure to test the correctness of your program with `check50`, by executing the below.

```
check50 cs50/problems/2019/ap/fahrenheit
```

### Style

If you pass all the `check50` test cases, and get a green smiley face when you run things through `style50`, as with:

```
style50 fahrenheit.c
```

If not, don't worry: it's just time for a little bit of debugging and/or cleaning up your code.

## Staff Solution

If you'd like to play with the staff's own implementation of `fahrenheit`, you may execute the below.

```
~cs50/2019/ap/chapter1/fahrenheit
```

## How to Submit

### Step 1 of 2

Ensure that `fahrenheit.c` is in `~/chapter1/fahrenheit`, as with:

```
cd ~/chapter1/fahrenheit
ls
```

If `fahrenheit.c` is not in `~/chapter1/fahrenheit`, move it into that directory, as via `mv` (or via CS50 IDE's lefthand file browser).

### Step 2 of 2

-   To submit `fahrenheit`, execute

    ```
    cd ~/chapter1/fahrenheit
    submit50 cs50/problems/2019/ap/fahrenheit
    ```

    inputting your GitHub username and GitHub password as prompted.

You may resubmit any problem as many times as you'd like before the deadline.

Your submission should be graded for correctness within 2 minutes, at which point your score will appear at [submit.cs50.io](https://submit.cs50.io/)!

This was Fahrenheit.

* * * * *

[1](https://docs.cs50.net/2019/ap/problems/fahrenheit/fahrenheit.html#_footnoteref_1). e.g., <https://upload.wikimedia.org/wikipedia/commons/b/ba/Thermometer.jpg>.

[2](https://docs.cs50.net/2019/ap/problems/fahrenheit/fahrenheit.html#_footnoteref_2). Incidentally, while spelling Fahrenheit correctly is a little tricky, do be careful to do so lest you be told that your program doesn't exist!

[3](https://docs.cs50.net/2019/ap/problems/fahrenheit/fahrenheit.html#_footnoteref_3). If you don't, you soon will!
