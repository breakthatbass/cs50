# Harvard CS50: Introduction to Computer Science

My solutions to the problem sets to the CS50 Harvard Course.
The course lectures and problem sets are available [here](https://cs50.harvard.edu/college/2019/fall/).

## Week 1: C

[```mario.c```](https://github.com/breakthatbass/cs50/blob/master/pset1/mario.c) is a program that creates pyramids out of hashes based on the number the user inputs.

#### Usage:
```
$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```

[```cash.c```](https://github.com/breakthatbass/cs50/blob/master/pset1/cash.c) is a greedy algorithm program that determines the amount of coins needed to create change. 

```
$ ./cash
Change owed: 0.41
4
```
## Week 2: Arrays (C)
[```caesar.c```](https://github.com/breakthatbass/cs50/blob/master/pset2/caesar.c) takes a number as an argument when running the program, prompts for a string, then adds the argument number to each letter in the string (based on its ASCII number) and returns it.

```
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```

[```vigenere.c```](https://github.com/breakthatbass/cs50/blob/master/pset2/vigenere.c)

```
$ ./vigenere ABC
plaintext:  HELLO
ciphertext: HFNLP
```

## Week 3: Algorithms (C)
[```plurality.c```](https://github.com/breakthatbass/cs50/blob/master/pset3/plurality.c)

```
$ ./plurality Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Alice
```

[```runoff.c```](https://github.com/breakthatbass/cs50/blob/master/pset3/runoff.c)

```
./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
```

## Week 4: Memory (C)
[```filter.c```](https://github.com/breakthatbass/cs50/tree/master/pset4/filter) is software for applying filters to images. It provides grayscale, sepia, reverse, and blur filters which are all written in the [```helpers.c```](https://github.com/breakthatbass/cs50/blob/master/pset4/filter/helpers.c).

#### Usage:
```
$ ./filter -g infile.bmp outfile.bmp
```
```
$ ./filter -s infile.bmp outfile.bmp
```
```
$ ./filter -r infile.bmp outfile.bmp
```
```
$ ./filter -b infile.bmp outfile.bmp
```

```recover.c``` - TODO

## Week 5: Data Structures (C)
TODO

## Week 6: Python 🐍
[```mario.py```](https://github.com/breakthatbass/cs50/blob/master/pset6/mario.py), [```cash.py```](https://github.com/breakthatbass/cs50/blob/master/pset6/cash.py), [```caesar.py```](https://github.com/breakthatbass/cs50/blob/master/pset6/caesar.py) are Python versions of weeks one and two C programs.

[```bleep.py```](https://github.com/breakthatbass/cs50/tree/master/pset6/bleep) is a program that takes a sentence (array of strings) as input and checks whether any of the words match any of the words in the banned.txt file and returns the sentence with those words "bleeped" out with "*" characters.

### Usage:

```
python bleep.py
message: what the fiddlesticks
what the ************
```

[Similarities](https://github.com/breakthatbass/cs50/tree/master/pset6/similarities) is a program that takes two files as inputs and determines what characters, words, or lines each file has in common.

### Usage:
```
./compare --lines FILE1 FILE2
```
```
./compare --sentences FILE1 FILE2
```
```
./compare --substrings 1 FILE1 FILE2
```
```
./compare --substrings 2 FILE1 FILE2
```

Or for usage in the web app form using a local Flask server, download the files in the Similarities folder and

```
$ export FLASK_APP=application.py
```
then 
```
flask run
```

## Week 7: Flask & SQL

[```Survey```](https://github.com/breakthatbass/cs50/tree/master/pset7/survey) is a simple Flask app that saves inputs from a survey into a csv file.

### Usage:
Download Survey folder and run on a local Flask server
```
$ export FLASK_APP=application.py
```
```
flask run
```

[```Finance```](https://github.com/breakthatbass/cs50/tree/master/pset7/finance) is a Flask app connected to a SQLite database and stock API that allows a user to create a username and password and buy and sell stocks with fake money.

### Usage:
Download Finance folder and run on a local Flask server
Get an API key from IEX

```
export API_KEY=<insert api key>
```
```
export FLASK_APP=application.py
```
```
flask run
```
### TODO
Host on Horoku
