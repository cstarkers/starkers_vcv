# Big Marko
## Overview
Big Marko is a VCV Rack sequencer module for generating probabalistic sequences.  The intended application is melody generation, but I want to know what else it's cool for

There are a few Markov-based modules on VCV Rack, but none that just directly let you set the transition matrix. 

## How?

Big Marko has 8 "states" that he can be in (numbered 1-8).  Each state produces a particular output voltage (determined by the inputs on the right).

On a clock pulse, Big Marko will transition states.  The probability of any particular transition (for example, the probability of tranistioning from state 4 to state 7) is determined by the nobs in the main panel.  In this example, it would be the nob marked x:

```
  12345678
  --------
1|oooooooo
2|oooooooo
3|oooooooo
4|ooooooxo
5|oooooooo
6|oooooooo
7|oooooooo
8|oooooooo
```

The LEDs on the right show the current state.

The trigger input advances the state.  Simples.

Reset sends us back to state 1. 

Every nob (probabilities and output levels) has CV inputs, so you can go nuts on the modulation. 

## Some advice
1. Reset sets the state to state 1. 
2. Within every row, make use of the full range of probabilities.  If all the nobs in a row are low, they effectively get normalised up, because the probabilities have to add to 100% across a row.  Similarly if they are all cranked up, they will be normalised down.
3. If you want to have less than 8 states, set the column for the unwanted states to all 0.  That means there is 0 probability of ever arriving in that state, and the corresponding row becomes irrelevant.
4. Probability CVs basically expect bipolar, -5v to 5v.  Setting the nob to zero and providing -5v is the same as turning the nob fully left (ie zero probability). Probabilities are clipped at 0 - i.e if you turn the nob to 9 o'clock and then provide -5v, the probability isn't "negative" somehow, it's still just 0. However, the same is NOT true in the positive direction - turning the nob right and then adding 5v (or, heck, theoretically as many volts as you like) will just continue to add weigting onto that transiation.
5. If using a CV to set the output level of a state, this OVERRIDES the nob, the nob now does nothing, there is no attenuversion or addition or anything.  I'm pretty new to this, I don't actually know if that's how that would be expected to behave or not
6. You might want to Google/ChatGPT "Ergodicity" - there are some traps to think about like getting yourself into a cycle, or having a state you can get into but not out of.  A little hack is to have a reset occasionally (and make sure it's behaving well for long enough to make it back to the reset)

## Coming soon

I intend to make an expander which will be an 8x8 grid of trigger outputs, letting you know which transition was taken. (personally I am generating non-measured melodies and I want to detect something like a V-I transition to be like "oh now would be a cool time to end the phrase")

## You might also like 
MarkovSeq from Sckitam provides a few extra features compared to Big Marko - but it lacks input CV for probabilities
