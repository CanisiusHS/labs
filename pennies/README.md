# Pennies

Implement a program that calculates the sum of getting a doubled amount of money each day for a month, per the below.

```
$ ./pennies
Days in month: 30
Pennies on first day: 1
$10737418.23
```

#### Step 1
How to begin? Start the file with some "boilerplate" code like the below:

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{

}
```

Save the file as ```pennies.c``` and, just to be safe, try compiling it with

```
make pennies
```

in your terminal window, just to make sure you didn't make any syntactical mistakes, in which case you'll see errors that will need to be fixed! Then dive back into your code.

{% next %}

## Double or Nothing

If ever given the choice between $10,000,000 or a month's worth of pennies, whereby you receive a penny the first day, two pennies the second, four pennies the third, and so forth...​ take the pennies[1].

Anyhow, why the pennies? Exponentiation. Those pennies add up Consider how many pennies you'd receive on the 31st day alone, not to mention on the days leading up to it:

```
1 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2
  × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2
  × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2

  = 1073741824
```

Put more succinctly, that's 1 × 2<sup>30</sup> **(HINT! HINT! HINT!)**. Convert those pennies to dollars (by dividing by 100) and you get, what, over $10,000,000? On just that day? Crazy.

What if you were given more than one penny on that first day? Or the month were February, in which case you'd get shortchanged a few million? (Best to take the pennies in January, March, May, July, August, October, or December[2].) Let's find out.

#### Step 2
Now that you have the structure of your program from **Step 1** ask the user how many days there are in the month.  If the user does not type in 28, 29, 30, or 31 for the number of days in the month, the program should prompt the user to retry.  What kind of loop could we use here? Don't forget to declare your variables!

{% next %}

#### Step 3
Now ask the user how many pennies he or she will receive on the first day of that month. If the user does not input a positive integer for the first day's number of pennies, the program should prompt the user to retry.  Seems like we should take a similar approach to the month part.

{% next %}

#### Step 4
The program should then calculate the amount that the user will have received **in total** by the end of the month (not just on the last day) if that amount is doubled on every day but the first, expressed not as pennies but as dollars and cents.

For instance, your program might behave as follows, whereby underlined text represents some user's input.

```
~/chapter1/pennies/ $ ./pennies
Days in month: 32
Days in month: 31
Pennies on first day: -2
Pennies on first day: 1
$21474836.47
```

Notice how this output suggests that the program should indeed re-prompt the user if he or she fails to cooperate with these rules (as by inputting too many days).

{% next %}

You may also find functions (like pow) in the `math.h` header file that can help when working on this problem. Have a look at the [CS50 Programmer's Manual](https://man.cs50.io/) to see which functions those might be. Be sure, if you use any of those functions, to place this line of code near the top of your `pennies.c` file:

```
#include <math.h>
```

Of course, if you store the user's amount due in an `int` (which is only 32 bits), the total will be bounded by (2<sup>31</sup> - 1) pennies. (Why 2<sup>31</sup> and not 2<sup>32</sup>?  And why 1 less than 2<sup>31</sup>?) Best, then, to store your total in a `long long`, so that the user benefits from 64 bits. (Don't worry if users' totals overflow 64 bits and even go negative; consider it punishment for greed!)

Do take care to format the user's total as dollars and cents (to just 2 decimal places), prefixed with a dollar sign, just as we did in the output above. You do not need to insert commas after every 3 digits to the left of the decimal, as you might normally do.

So that we can automate some tests of your code, we ask that your program's last line of output be the amount owed to a user, followed by `\n`. The rest of your program's personality we leave entirely to you!

## Testing

### Correctness

To test the correctness of your program, you may execute the below at the terminal window.

```
check50 cs50/problems/2019/ap/pennies
```

### Style

```
style50 pennies.c
```

## How to Submit

To submit `pennies`, execute

```
submit50 cs50/problems/2019/ap/pennies
```

inputting your GitHub username and GitHub password as prompted.

You may resubmit any problem as many times as you'd like before the deadline.

Your submission should be graded for correctness within 2 minutes, at which point your score will appear at [submit.cs50.io](https://submit.cs50.io/)!

This was Pennies.

* * * * *

[1] By contrast, if you receive an email from some stranger on the Internet offering you an opportunity to double your money, maybe think twice.

[2] We'll admit it. We had to look at a calendar.
