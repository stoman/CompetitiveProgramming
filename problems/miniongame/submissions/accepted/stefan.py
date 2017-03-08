#!/usr/bin/env python2

#Author: Stefan Toman

def minion_game(s):
    #read input
    scores = {"Stuart": 0, "Kevin": 0}
    for (i, c) in enumerate(s):
        if c in "AEIOU":
            scores["Kevin"] += len(s) - i
        else:
            scores["Stuart"] += len(s) - i

    #print winner
    if scores["Kevin"] > scores["Stuart"]:
        print "%s %d" % ("Kevin", scores["Kevin"])
    elif scores["Kevin"] < scores["Stuart"]:
        print "%s %d" % ("Stuart", scores["Stuart"])
    else:
        print "Draw"

#predefined code
if __name__ == '__main__':
    s = raw_input()
    minion_game(s)