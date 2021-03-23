# Interview Questions with Emojis
After going through a few coding interviews, I decided to formalise the questions I was given into short, sweet and neat little code snippets. A repo featuring fully deployable solutions to these problems is available on my GitHub, but take heed: it features some very novel obfuscation techniques... 😉  
  
Anyway, onto the main body of things - sit up straight, don't fall asleep, and try to keep up!  
  
## Bit Shifter
  
### _Produce a function that returns the amount of bits in a given 32 bit integer. For example: 5 = 0101, or two bits._
  
Bit shifter is exactly what it sounds like: it uses bit shifting operators to tell you how many bits are in a number. For this exercise, all ints are assumed to be unsigned 32 bit types.  
Say we have an integer, with a maximum capacity for 32 bits. We could loop over them all, and count how many are positive using a bit mask:  

```
  int CountBits (int num)  
  {  
    int bitCount = 0;  
    for (int i = 0; i < 32; ++i  
    {  
    bitCount += (num & 1);  
    num >> 1;  
    }  
    return bitCount;  
  }
```  
  
Sure, it works - but it's not efficient. If the number is 1, with only a single bit, it's going to vanish the first time and we're going to be looking at a chain of nothing for the next 31 iterations. If only there was a way to break out once it turns to zero?  
  
```
    for (int i = 0; i < 32; ++i)  
    {  
      // Count the bits etc  
      if (!(num)) break;  
    }
```  
   
This works because bools are technically ints, but any value above `0` is counted as `true`, so when it reaches `0` it's as good as `false`. Invert that, and you satisfy the if statement - but there is a better way.  
  
```
  int CountBits (int num)  
  {  
    int bitCount = 0;  
    while (num > 0)  
    {  
      bitCount += (num & 1);  
      num >> 1;  
    }  
    return bitCount;  
  }
```  
  
An if-statement and a loop iterator all in one, while preconditions can be placed before or after a loop - the latter requiring the use of a `do { foo } while( bar );` syntax. That way always runs the loop at least once however, whilst here, even if the supplied number is zero, that doesn't matter. Neat eh?  
  
## Leap Year
  
### _Produce a function that returns whether a provided Year is a leap year, based on its four digit representation. For example: 2020 = TRUE, 2021 = FALSE._
  
Leap years are an odd beast, even in the gregorian calendar. Fortunately, there's a way to predict them: if a year is a leap year, it has to divide cleanly by `4`, and if that isn't the case, it has to divide cleanly by `100` - and `400` even after that.
  
We can figure this out and return it as a bool like this:  
  
```
  bool IsLeap (int year)  
  {  
    if (year % 4 == 0)  
    {  
      return true;  
    }  
    else if (year % 100 == 0)  
    {  
      if (year % 400 == 0)  
      {  
        return true;  
      }  
      else  
      {  
        return false;  
      }  
    }  
    else  
    {  
    return false;  
    }  
  }
```  
  
The `%` sign - or modulo operator - divides a number cleanly, and will `return` the remainder if there is any. Here, we can use that to check that our `year` divides cleanly and satisfies either the first precondition or the second pair of conditionals. If it does, it returns `true`, however if it doesn't - it returns `false`!
How clean.. how readable.. how inefficient! These `if` statements are renowned for being exceptionally cycle-hungry, but whilst we could clean this up with `switch`-`case` blocks, there's a much more elegant way.   
  
First, nest your conditions. Hint:
   - `&&` means "logical AND", so if both inputs are true it will return `true` - returning `false` otherwise.   
   - `||` means "logical OR", so if either or both input is `true` it will return `true`. It won't if they're both `false` though, so think of it like the opposite of               
          AND!       
  
```
  if (year % 4 == 0)  
  {  
    return true;  
  }  
  else if (year % 100 == 0 && year % 400 == 0)  
  {  
    return true;  
  }  
```  
  
Nice, but let's do that again..
  
```  
  if ( year % 4 == 0 || ( year % 100 == 0 && year % 400 == 0 ))  
```  

Better, but not perfect. If a year divides cleanly by 400, then surely it divides by `100` also, considering `400` itself does the same - so we can eliminate our truanism (fancy logical maths talk for saying the same thing twice) by deleting it straight up, along with the brackets we needed to declare its precedence:   
  
```  
  if ( year % 4 == 0 || year % 400 == 0 )  
  {  
    return true;  
  }  
```  
  
Nice.  
There's one more thing we can do here though... all `if` statements use a `true` or `false` value to operate - and as a result, you can think of whatever you feed into them as a boolean statement. That's because of the `==`, `&&` and `||` operators we've been using - think of them like shorthand for our `return true` and `false` statements. If we can access the result of this statement and act accordingly using an `if`, and all we want to know is whether the `if` statement returns `true`, then we can skip out the middle man and just `return` what we get from our logic statement.   
  
```
  bool IsLeap (int year)  
  {  
  
    return ( year % 4 == 0 || year % 400 == 0);  
  
  }  
```

Cycometrically perfect.   
All this code should compile into C++ without much problem, so go ahead and try it out! Be sure to credit where credit's due though - the MIT license is pretty harsh on plagiarism, as is whatever school it is that told you to do the homework that brought you here, I have no doubt. Just message me if this helped, or reference it in your appendix, and you'll be fine - so long as you understand it!   
  
  
--Vector problem coming soon--
