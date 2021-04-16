import copy
import math

#global variable
flag_const = 0


#function to check whether the given string is a number
def arg_is_dig(str_arg):
        
    for i in str_arg:
        temp = ord(i)

        if (temp<48 or temp>57) and i!='.':
            return 0

    return 1


#function to retreive the value of a variable from the quadruple data structure
def quad_ds_retrieve(quad_ds, curr_line, var):

    global flag_const

    for i in range(curr_line-1,-1,-1):
        line = quad_ds[i]
        
        if line['op'] == '=' and line['res'] == var:
            if arg_is_dig(line['arg1']):
                flag_const = 1
                return line['arg1']

            else:
                flag_const = 0
                return -1

    flag_const = 0
    return -1


#function to check if a number is a power of 2 or not
def is_power_of_2(n):

    return n and (not(n&(n-1)))



#function to perform constant folding optimisation
def constant_folding_opt(quad_ds):

    for i in range(len(quad_ds)):

        line = quad_ds[i]

        #binary operators
        if len(line)==4:

            #binary plus : '+'
            if line['op'] == '+':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) + float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) + int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f and line['arg1'] == '0':
                    temp_eval = line['arg2']
                    quad_ds[i]['op'] = '='
                    quad_ds[i]['arg1'] = temp_eval
                    del quad_ds[i]['arg2']

                elif arg2_f and line['arg2'] == '0':
                    quad_ds[i]['op'] = '='
                    del quad_ds[i]['arg2']


            #binary minus : '-'
            elif line['op'] == '-':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) - float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) - int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f and line['arg1'] == '0':
                    temp_eval = "-" + line['arg2']
                    quad_ds[i]['op'] = '='
                    quad_ds[i]['arg1'] = temp_eval
                    del quad_ds[i]['arg2']

                elif arg2_f and line['arg2'] == '0':
                    quad_ds[i]['op'] = '='
                    del quad_ds[i]['arg2']


            #binary star : '*'
            elif line['op'] == '*':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) * float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) * int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f:

                    if line['arg1'] == '0':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']

                    elif line['arg1'] == '1':
                        temp_eval = line['arg2']
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']

                elif arg2_f:

                    if line['arg2'] == '0':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']

                    elif line['arg2'] == '1':
                        quad_ds[i]['op'] = '='
                        del quad_ds[i]['arg2']

            
            #binary divide : '/'
            elif line['op'] == '/':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) / float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) / int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f:

                    if line['arg1'] == '0':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']


                elif arg2_f:

                    if line['arg2'] == '0':
                        print("Division By Zero Error\n")
                        exit()

                    elif line['arg2'] == '1':
                        quad_ds[i]['op'] = '='
                        del quad_ds[i]['arg2']


            #binary modulus : '%'
            elif line['op'] == '%':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) % float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) % int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f:

                    if line['arg1'] == '0':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']


                elif arg2_f:

                    if line['arg2'] == '0':
                        print("Division By Zero Error\n")
                        exit()

                    elif line['arg2'] == '1':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']


            #binary LT : '<'
            elif line['op'] == '<':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) < float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) < int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary GT : '>'
            elif line['op'] == '>':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) > float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) > int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary LTE : '<='
            elif line['op'] == '<=':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) <= float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) <= int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary GTE : '>='
            elif line['op'] == '>=':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) >= float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) >= int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary EQ : '=='
            elif line['op'] == '==':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) == float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) == int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

            #binary NEQ : '!='
            elif line['op'] == '!=':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) != float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) != int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']
                


#function to perform constant propagation optimisation
def constant_propagation(quad_ds):

    global flag_const

    for i in range(len(quad_ds)):

        line = quad_ds[i]

        #binary operators
        if len(line)==4:

            #binary plus : '+'
            if line['op'] == '+':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) + float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) + int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f and line['arg1'] == '0':
                    temp_eval = line['arg2']
                    quad_ds[i]['op'] = '='
                    quad_ds[i]['arg1'] = temp_eval
                    del quad_ds[i]['arg2']

                elif arg2_f and line['arg2'] == '0':
                    quad_ds[i]['op'] = '='
                    del quad_ds[i]['arg2']


            #binary minus : '-'
            elif line['op'] == '-':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) - float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) - int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f and line['arg1'] == '0':
                    temp_eval = "-" + line['arg2']
                    quad_ds[i]['op'] = '='
                    quad_ds[i]['arg1'] = temp_eval
                    del quad_ds[i]['arg2']

                elif arg2_f and line['arg2'] == '0':
                    quad_ds[i]['op'] = '='
                    del quad_ds[i]['arg2']


            #binary star : '*'
            elif line['op'] == '*':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) * float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) * int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f:

                    if line['arg1'] == '0':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']

                    elif line['arg1'] == '1':
                        temp_eval = line['arg2']
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']

                elif arg2_f:

                    if line['arg2'] == '0':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']

                    elif line['arg2'] == '1':
                        quad_ds[i]['op'] = '='
                        del quad_ds[i]['arg2']


            #binary divide : '/'
            elif line['op'] == '/':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) / float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) / int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f:

                    if line['arg1'] == '0':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']


                elif arg2_f:

                    if line['arg2'] == '0':
                        print("Division By Zero Error\n")
                        exit()

                    elif line['arg2'] == '1':
                        quad_ds[i]['op'] = '='
                        del quad_ds[i]['arg2']


            #binary modulus : '%'
            elif line['op'] == '%':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) % float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) % int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                elif arg1_f:

                    if line['arg1'] == '0':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']


                elif arg2_f:

                    if line['arg2'] == '0':
                        print("Division By Zero Error\n")
                        exit()

                    elif line['arg2'] == '1':
                        temp_eval = "0"
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = temp_eval
                        del quad_ds[i]['arg2']



            #binary LT : '<'
            elif line['op'] == '<':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) < float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) < int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary GT : '>'
            elif line['op'] == '>':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) > float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) > int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary LTE : '<='
            elif line['op'] == '<=':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) <= float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) <= int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary GTE : '>='
            elif line['op'] == '>=':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) >= float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) >= int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary LTE : '<='
            elif line['op'] == '<=':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) <= float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) <= int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary EQ : '=='
            elif line['op'] == '==':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) == float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) == int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']


            #binary NEQ : '!='
            elif line['op'] == '!=':
                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #arg1 is a digit, arg2 is a variable
                if arg1_f and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res

                #arg1 is a variable, arg2 is a digit
                elif not(arg1_f) and arg2_f:
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                #arg1 and arg2 are variables
                elif not(arg1_f) and not(arg2_f):
                    flag_const = 0
                    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                    if flag_const:
                        line['arg1'] = res

                    flag_const = 0
                    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
                    if flag_const:
                        line['arg2'] = res2


                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])


                #both the arguments are constants
                if arg1_f and arg2_f:

                    #one or both the arguments are floating point numbers
                    if '.' in line['arg1'] or '.' in line['arg2']:
                        temp_eval = float(line['arg1']) != float(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']

                    #the arguments are integers
                    else:
                        temp_eval = int(line['arg1']) != int(line['arg2'])
                        quad_ds[i]['op'] = '='
                        quad_ds[i]['arg1'] = str(temp_eval)
                        del quad_ds[i]['arg2']



#function to perform common subexpression elimination
def common_subexpression_elim(quad_ds):

    quad_ds_c = copy.deepcopy(quad_ds)
    l_q_ds = len(quad_ds_c)

    bin_operators = ["+","-","*","/","%","<",">","<=",">=","==","!="]

    removed_ind = []

    for i in range(l_q_ds):

        if i not in removed_ind:

            line = quad_ds_c[i]

            #binary operators
            if len(line)==4:

                
                if line['op'] in bin_operators:

                    arg1 = line['arg1']
                    arg2 = line['arg2']

                    j = i + 1
                    ind_j = 0
                    flag_2 = 0

                    temp_rem_ind = []
                    
                    while j<l_q_ds and flag_2==0:

                        flag = 0
                        loop_i = j

                        while j<l_q_ds and flag == 0:
                            
                            line2 = quad_ds_c[j]

                            #finding a second instance of the same expression
                            if len(line2) == 4 and line2['op'] == line['op'] and line2['arg1'] == arg1 and line2['arg2'] == arg2:
                                ind_j = j
                                flag = 1

                            j += 1

                        if flag:

                            flag_2 = 0
                            while loop_i < ind_j and flag_2 == 0:
                                line3 = quad_ds_c[loop_i]

                                if len(line3) == 3 and line3['op'] == '=' and (line3['res'] == arg1 or line3['res'] == arg2):
                                    flag_2 = 1
                                    

                                loop_i += 1

                            #arguments in the expression are not being modified
                            if flag_2 == 0:
                                
                                next_line = quad_ds_c[ind_j + 1]
                                if ind_j + 1 < len(quad_ds) and next_line['op'] == '=' and next_line['arg1'] == quad_ds_c[ind_j]['res']:
                                    quad_ds[ind_j + 1]['arg1'] = line['res']

                                temp_rem_ind.append(ind_j)
                                removed_ind.append(ind_j)


                    temp_rem_ind = sorted(temp_rem_ind,reverse=True)
                    for trav_ind in temp_rem_ind:
                        quad_ds.pop(trav_ind)



#function to perform strength reduction optimisation
def strength_reduction(quad_ds):

    for i in range(len(quad_ds)):

        line = quad_ds[i]

        #binary operators
        if len(line) == 4:

            #variable * (2^i) => variable << i
            if line['op'] == '*':

                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #if arg1 is a variable and arg2 is a number
                if not(arg1_f) and arg2_f:

                    if '.' not in line['arg2']:
                        num = int(line['arg2'])
                        res = is_power_of_2(num)
                        
                        if res:
                            shift_value = int(math.log2(num))

                            quad_ds[i]['op'] = '<<'
                            quad_ds[i]['arg2'] = shift_value


                #if arg1 is a number and arg2 is a variable
                if arg1_f and not(arg2_f):

                    if '.' not in line['arg1']:
                        num = int(line['arg1'])
                        res = is_power_of_2(num)
                                                
                        if res:
                            shift_value = int(math.log2(num))

                            quad_ds[i]['op'] = '<<'
                            quad_ds[i]['arg1'] = quad_ds[i]['arg2']
                            quad_ds[i]['arg2'] = shift_value


            #variable / (2^i) => variable >> i
            elif line['op'] == '/':

                arg1_f = arg_is_dig(line['arg1'])
                arg2_f = arg_is_dig(line['arg2'])

                #if arg1 is a variable and arg2 is a number
                if not(arg1_f) and arg2_f:

                    if '.' not in line['arg2']:
                        num = int(line['arg2'])
                        res = is_power_of_2(num)
                                        
                        if res:
                            shift_value = int(math.log2(num))

                            quad_ds[i]['op'] = '>>'
                            quad_ds[i]['arg2'] = shift_value


                #if arg1 is a number and arg2 is a variable
                if arg1_f and not(arg2_f):

                    if '.' not in line['arg1']:
                        num = int(line['arg1'])
                        res = is_power_of_2(num)
                                                                
                        if res:
                            shift_value = int(math.log2(num))

                            quad_ds[i]['op'] = '>>'
                            quad_ds[i]['arg1'] = quad_ds[i]['arg2']
                            quad_ds[i]['arg2'] = shift_value



#function to print the quadruple data structure in table format
def print_quad(quad_ds):

    print()
    print()
    print('%-12s' % "Operator",'%-12s' % "Arg1",'%-12s' % "Arg2",'%-12s' % "Result")
    print()

    for i in range(len(quad_ds)):

        line = quad_ds[i]

        if len(line) == 4:
            print('%-12s' % line['op'],'%-12s' % line['arg1'],'%-12s' % line['arg2'],'%-12s' % line['res'])

        elif len(line) == 3:
            print('%-12s' % line['op'],'%-12s' % line['arg1'],'%-12s' % "",'%-12s' % line['res'])

        elif len(line) == 2:
            print('%-12s' % line['op'],'%-12s' % "",'%-12s' % "",'%-12s' % line['res'])


    print()
    print()



#function to print the intermediate code from the quadruple data structure
def print_icg(quad_ds):

    print()
    print()

    for i in range(len(quad_ds)):
        line = quad_ds[i]

        if len(line) == 4:
            print(line['res'],"=",line['arg1'],line['op'],line['arg2'])

        elif len(line) == 3:
            
            if line['op'] == '=':
                print(line['res'],"=",line['arg1'])

            elif line['op'] == 'if':
                print(line['op'],line['arg1'],"goto",line['res'])

        elif len(line) == 2:

            if line['op'] == "goto":
                print(line['op'],line['res'])

    
    print()
    print()




if __name__ == "__main__":

    file_quad = open("quad_intermediate_code.txt","r")
    file_ip = file_quad.readlines()
    file_quad.close()

    #list of dictionaries where each element of the list corresponds 
    # to one record in the quadruple data structure
    #each dictionary has the fields 'op', 'arg1', 'arg2', 'res'
    quad_ds = [] 

    for i in range(len(file_ip)):
        file_ip[i] = file_ip[i].strip()
        line = file_ip[i].split()
        temp = {}

        no_f = len(line)

        #all four fields of the quadruple ds are filled
        if no_f == 4:
            temp['op'] = line[0]
            temp['arg1'] = line[1]
            temp['arg2'] = line[2]
            temp['res'] = line[3]


        #only 3 fields are filled - op, arg1, res
        elif no_f == 3:
            temp['op'] = line[0]
            temp['arg1'] = line[1]
            temp['res'] = line[2]

        #only 2 fields are filled - op, res
        elif no_f == 2:
            temp['op'] = line[0]
            temp['res'] = line[1]

        quad_ds.append(temp)



    print("Intermediate Code before Optimization")
    print_icg(quad_ds)
    print("Intermediate Code in Quadruple Format before Optimization")
    print_quad(quad_ds)
    


    #constant folding
    constant_folding_opt(quad_ds)
    print("Intermediate Code generated after Constant Folding Optimization")
    print_icg(quad_ds)
    print("Intermediate Code in Quadruple format after Constant Folding Optimization")
    print_quad(quad_ds)
    


    #constant propagation
    # constant_propagation(quad_ds)
    # print("Intermediate Code generated after Constant Propagation Optimization")
    # print_icg(quad_ds)
    # print("Intermediate Code in Quadruple format after Constant Propagation Optimization")
    # print_quad(quad_ds)



    #common subexpression elimination
    # common_subexpression_elim(quad_ds)
    # print("Intermediate Code generated after Common Subexpression Elimination Optimization")
    # print_icg(quad_ds)
    # print("Intermediate Code in Quadruple format after Common Subexpression Elimination Optimization")
    # print_quad(quad_ds)


    #strength reduction
    strength_reduction(quad_ds)
    print("Intermediate Code generated after Strength Reduction Optimization")
    print_icg(quad_ds)
    print("Intermediate Code in Quadruple format after Strength Reduction Optimization")
    print_quad(quad_ds)

