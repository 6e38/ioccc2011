
# Tweet Remarks
ioccc 2011

NOTE: This no longer works due to changes in API. It did work
at time of submission.

### To Make

    make all

### To Run

    tweet <username>

#### Examples:

    tweet ioccc
    tweet slashdot

## WARNING

Be careful not to disrupt the long string at the end of the
file when reformatting the code.  Some formatting tools alter
the whitespace in the string.  The program will not work if the
whitespace in the string is altered.

## About

This program reads the timeline for the given user then scrolls
the timeline vertically in the terminal.  When it is finished
scrolling all the messages in the timeline it will re-request
the timeline and display it again.  If the program has finished
outputting all of the messages and 60 seconds have not elapsed
it will simply repeat the messages from its previous request
without making a new request.

To terminate the program type `ctrl-c` or send it the `TERM`
signal.  The program has registered signal handlers for both
`SIGINT` and `SIGTERM`.

This program properly allocates and frees memory.  It handles
most error conditions.  When the program detects an error it
exits by returning from all functions.  The program's return
value corresponds to the line in the source file where the
error occurred.

I have compiled this program with -Wall and -ansi on 32 and 64
bit Linux, HPUX and PPC Mac OS X.  It compiles warning free.
Who says you can't write _good_ obfuscated code?

## Source Code

Best viewed with 81 columns and tabs set to display as one
space.  Tabs are not used in formatting the code but there is
a rather lengthy string that contains tabs and fits nicely in
81 columns when the tabs are displayed as a single space.

## Bending the Rules

You might notice that my program file is 4086 bytes.  It seems
awfully close to the limit.  It is.  I don't think 4086 bytes is
bending the rules and it certainly isn't breaking the rules...

At the end of the file you will see a string that contains 1600
characters of whitespace.  If you look closely you'll notice
that the string contains both space and tab characters.  Since
non-whitespace characters (with some exceptions) are limited to
2048, I couldn't burn a bunch of characters to create my
vertical extra-large character map.  Even after excluding all
ASCII characters above 0x5f from the character map I was still
consuming far too many bytes.  Then it occurred to me: why not
create the character map using whitespace?

I don't think a 1600 byte string of whitespace conforms to the
spirit of the rules but the rules certainly don't disallow it.

## Obfuscation

Mostly I copied the style of code I see at work on a daily
basis.  The techniques I've learned at work have adequately
prepared me for this contest.

+ I employed a lot of inconsistency in my obfuscation.  I have
  found that some of the most difficult to understand code is
  simply inconsistent in every way.

+ Function pointers.  Without them we couldn't do wonderful
  things like callbacks and faux polymorphism.  Why in the
  world would anyone use them the way I have here?  Only to
  obfuscate the code a little more.

+ K & R style function declaration.  But only once.  Sure the
  old guys don't think twice about this notation but run it by
  a newb and he'd think you've gone mad.  RIP Dennis Ritchie.

+ Variable shadowing.  Isn't scope fun?

+ Variable re-use.  Nowadays most compilers are going to
  optimize in ways that you'd spend way too much time looking
  for.  There aren't many good reasons to re-use variables.
  You're just asking to shoot yourself in the foot.

+ Non-descriptive variable names.  This isn't amazing but what
  is amazing is how programmers seem to think that 1 character
  names are totally fine when they know full well they'll be
  turning their code over to someone else to maintain.

+ Use of #defines.  Nothing noteworthy about this.  It's just
  frustrating to read and maintain.  I don't personally have
  anything against pre-processor macros, it's just that almost
  every macro I've seen in my life was made for all the wrong
  reasons and served almost no purpose except to obfuscate the
  code that would otherwise be easy to understand.

+ Formatting.  The easiest way to make everyone's life
  miserable.

+ Various other things hardly worth mentioning: anonymous
  struct, escaped characters, split strings, magic numbers,
  gotos and stuff I've probably forgotten.

+ I didn't use trigraphs.  They seem boring.

+ I didn't use -D compiler directives.  I wanted all the pieces
  to be visible in a single file.

