# Program involving all the constructs with nesting of loops and conditional constructs, different types of comments, strings

a = 3
for i in range(a):
    b = 6
    for j in range(1,b):
        c = 3 * 2 % 7

        if c==0:
            mod_flag = 1
            if b==6:
                nested_if = True
            
        else:
            mod_flag = 0
        
#test comment    

'''
test
multi line
comment
triple single quotes
''' 
    
if a==3:
    d = 4
    e = "test string 1"
    
    
elif a>=5:
    e = 5
else:
    f = 6
