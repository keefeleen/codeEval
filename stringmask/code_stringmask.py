#!/usr/bin/env python
import sys,string

def main():
    test_cases = open(sys.argv[1], 'r')
    
    for _input in test_cases:
        _input = _input.strip('\n')
        text   = _input.split()[0]
        mask   = _input.split()[1]
        #print "Now processing %s with mask %s" % (text,mask)

        counter = 0
        output  = ""

        for flag in mask:
            flag = int(flag)
            if flag:
                output += text[counter].upper()
            else:
                output += text[counter]
            counter += 1
   
        print output        
 
    return True

if __name__ == '__main__':
    main()
