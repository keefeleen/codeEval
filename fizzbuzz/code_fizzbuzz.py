#!/usr/bin/env python
import sys,copy,string

def getCountList(base,top):
    counter = 1
    countList = []

    while(base*counter <= top):
        countList.append(base*counter)
        counter += 1
    return countList

def main():

    test_cases = open(sys.argv[1], 'r')

    for test in test_cases:
        test = test.strip('\n')
        x = int(test.split()[0])
        y = int(test.split()[1])
        count = int(test.split()[2])
#        print "Processing case: X=%s, Y=%s, count=%s" % (x,y,count)
    
        x_list = getCountList(x,count)
        y_list = getCountList(y,count)
    
        fb = [ val for val in x_list if val in y_list ]
        fizz = [ val for val in x_list if val not in fb ]  
        buzz = [ val for val in y_list if val not in fb ]  

        output = ""

        for cnt in range(count):
            if cnt+1 in fizz:
                output += 'F '
            elif cnt+1 in buzz:
                output += 'B '
            elif cnt+1 in fb:
                output += 'FB '
            else:
                output = output + str(cnt+1) + ' ' 
                
        output = output.strip(' ')

        print output

    test_cases.close()
        
    return True

if __name__ == '__main__':
    main()
