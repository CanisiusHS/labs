# For Loop

In this lab you will learn:

- Why we have a for loop
- How to use a for loop

## What is a For Loop?

The **for loop** is probably the most frequently used loop of the three types of loops. It is very useful when we want to repeat something a known number of times.

Eventually we'll see how for loops can be useful for:
* Repeating a block of code 10 or 20 or *n* times when you know in advance the value of *n*
* Accessing each individual character in a string
* Looking at each element in an array (more on this to come later!)

Let's start by taking a look at the analogous loop in Scratch.

{% next %}

![scratch_repeat](https://raw.githubusercontent.com/cs50nestm/cs50labs/2019/forloop/repeat.png)

can be recreated in C by:

```c
for (int i = 0; i < 50; i++)
{
    printf("hello, world\n");
}
```

A for loop has three parts (included in parentheses after the word for, and separated by semicolons)

* **Initialization**: `int i = 0` is an initialization of the `int` variable `i`, which means that we created a variable and set its initial value to 0. `i` is a conventional name for a counting variable that keeps track of how many iterations of the loop we’ve already done.

* **Loop Condition**:  Then `i < 50` is the Boolean expression that the for loop checks, to determine if it will continue or not. When this condition is true, the for loop will run the code inside the curly braces. And since we started `i` at 0, stopping before `i` reaches 50 will mean this runs exactly 50 times, as we intended.

* **Increment Statement**:  The third part is the loop modification. This code is executed at the end of every loop. In this case, we increase the value of `i` by 1. As soon as `i` is no longer less than 50, the condition fails and the loop will end. The end result is that `hello world\n` is displayed exactly 50 times.

{% next %}

By taking advantage of loop modification, you can also get a loop to do something slightly different each time the loop repeats, or iterates.

For example, let's look at the following code:

```c
for (int j = 1; j <= 10; j++)
{
    printf("%i\n", j);
}
```

Here we start our counting variable, `j`, at 1 and execute the loop until `j` is no longer less than or equal to 10. Our first execution of the loop prints 1 on its own line. We then increment `j` by 1 and check the condition to see if it's still true. Since `j` is now 2, it's true that `2 <= 10` so the loop repeats printing 2 on it's own line. This continues until we've printed out the count from 1 to 10 inclusive.

{% next %}

## Your Turn

Modify the code on the right to add up the numbers from 1 to 10, using either the supplied for loop or creating your own. Store the total in the variable named `total`.

{% spoiler "Hint" %}

Keep in mind that you can use the value of `i` in your calculation. You can also change the loop so start at one and end when `i <= 10`. This gives you a value which can be added to `total` during each iteration.

{% endspoiler %}

{% next %}

<style type="text/css">
#green {color:green;}
</style>

### Styling with `style50`

Though C doesn't care about how you style your code (in other words code with correct forloop but inconsistent spacing will compile and execute), CS50 does! That's because spacing your code consistently makes it easier to read and as we'll see soon, easier to debug.

You can check that your spacing is correct by executing the following at the `$` prompt:

```
style50 forloop.c
```

If there’s room for improvement in your code’s style, highlighted in red will be any characters you should delete, and highlighted in green will be any characters you should add.

When style50 outputs:

<div id="green">
    <pre><code>Looks good!</code></pre>
</div>

you are now ready to check your code!

### Checking with `check50`

You can check that your work is correct and meets the specifications of the lab by executing the following at the `$` prompt:

```
check50 canisiushs/problems/2020/1_10_forloop
```

If your code passed all of the tests you will see check50 outputs:

<div id="green">
    <pre><code>:) forloop.c exists
:) forloop.c compiles
:) checks the math is right</code></pre>
</div>

you are ready to submit!

### Submitting with `submit50`

Assuming you passed all of the checks and your style is good you can now submit the lab by executing the following at the `$` prompt:

```
submit50 canisiushs/problems/2020/1_10_forloop
```

Congratulations, you've completed the For Loops Lab!

[For more info, download the CS50 Loops Reference Sheet](https://ap.cs50.school/assets/pdfs/unit1/loops.pdf)
