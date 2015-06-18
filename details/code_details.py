#!/usr/bin/env python
import sys,re,string

def main():

    test_cases = open(sys.argv[1], 'r')

    out_put = ""

    for case in test_cases:
        case = case.strip('\n')
        rows = case.split(',')
    
        new_rows = []

        for row in rows:
            row = re.sub("Y.*$",'O',row)
            row = re.sub("^.*X",'O',row)
            new_rows.append(row)
        #print new_rows

        min_dist = 8 

        for row in new_rows:
            dist = row.count('.')
            if (dist <= min_dist):
                min_dist = dist
            else:
                pass
        
        out_put = out_put + str(min_dist) + "\n"

    out_put = out_put.strip('\n')
    print out_put
    test_cases.close()
    return True

if __name__ == '__main__':
    main()
